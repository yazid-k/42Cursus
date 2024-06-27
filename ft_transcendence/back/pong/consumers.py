import json
from channels.generic.websocket import AsyncWebsocketConsumer
from channels.db import database_sync_to_async
import channels.layers
from asgiref.sync import sync_to_async
from django.core.cache import cache
from django.contrib.auth import get_user_model
from django.db.models import Q
import threading
import time
from .models import Match, Friend, UserProfile


# ************************* WS POUR LA LANGUE ******************************
class LanguageConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        self.user = self.scope['user']
        if self.user.is_authenticated:
            self.user_profile = await sync_to_async(UserProfile.objects.get)(username=self.user.username)
            await self.accept()


    @database_sync_to_async
    def update_language_in_db(self, language):
        self.scope['user'].language = language
        self.scope['user'].update_from = 'langage save'
        self.scope['user'].save()
        print("Language updated in db: ", language)

    async def set_language(self, language):
        if language in ['english', 'français', 'español']: 
            await self.update_language_in_db(language)

    async def send_language(self):
        language = self.user_profile.language
        await self.send(text_data=json.dumps({'action': 'get_language', 'language': language}))

    async def receive(self, text_data):
        data = json.loads(text_data)
        print("message received in consumer: ", data)
        action = data['action']
        if action == 'get_language':
            await self.send_language()
        if action == 'set_language':
            language = data['language']
            await self.set_language(language)

# ************************* WS POUR LES STATS DES JOUEURS ****************************

class StatsConsumer(AsyncWebsocketConsumer):
    instances = {}

    async def connect(self):
        self.user = self.scope["user"]
        self.instances[self.user.id] = self
        await self.accept()

    async def disconnect(self, close_code):
        if self.user and self.user.id:
            del self.instances[self.user.id]

    async def receive(self, text_data):
        pass

    async def send_stats(self, stats):
        print("Sending stats")
        await self.send(text_data=json.dumps(stats))

    @classmethod
    async def send_stats_to_all(cls, stats):
        for consumer in cls.instances.values():
            await consumer.send_stats(stats)

games_online = [] # Création de listes vides
games_local = []
games_tournament_local = []
games_tournament_online = []


# ************************* CLASSE GAME DE BASE ****************************

class Game():
    def __init__(self, maxscore, game_type):
        self.is_started = False
        self.game_type = game_type
        self.delay = 30
        self.WHITE = (255, 255, 255)
        self.BLACK = (0, 0, 0)
        self.player1 = ""
        self.player2 = ""
        self.WIDTH = 600
        self.HEIGHT = 600
        self.paddle_speed = 5
        self.paddle_width = 10
        self.paddle_height = 100
        self.p1_x_pos = 10
        self.p1_y_pos = self.HEIGHT / 2 - self.paddle_height / 2
        self.p2_x_pos = self.WIDTH - self.paddle_width - 10
        self.p2_y_pos = self.HEIGHT / 2 - self.paddle_height / 2
        self.p1_score = 0
        self.p2_score = 0
        self.maxscore = maxscore
        self.p1_up = False
        self.p1_down = False
        self.p2_up = False
        self.p2_down = False
        self.ball_x_pos = self.WIDTH / 2
        self.ball_y_pos = self.HEIGHT / 2
        self.ball_width = 8
        self.ball_x_velocity = 10
        self.ball_y_velocity = 0
        self.ball_x_normalspeed = 10
        self.has_finished = False
        self.is_running = False

    async def to_dict(self):
        return {
            'game_type': self.game_type,
            'delay': self.delay,
            'player1': self.player1,
            'player2': self.player2,
            'WIDTH': self.WIDTH,
            'HEIGHT': self.HEIGHT,
            'paddle_speed': self.paddle_speed,
            'paddle_width': self.paddle_width,
            'paddle_height': self.paddle_height,
            'p1_x_pos': self.p1_x_pos,
            'p1_y_pos': self.p1_y_pos,
            'p2_x_pos': self.p2_x_pos,
            'p2_y_pos': self.p2_y_pos,
            'p1_score': self.p1_score,
            'p2_score': self.p2_score,
            'maxscore': self.maxscore,
            'p1_up': self.p1_up,
            'p1_down': self.p1_down,
            'p2_up': self.p2_up,
            'p2_down': self.p2_down,
            'ball_x_pos': self.ball_x_pos,
            'ball_y_pos': self.ball_y_pos,
            'ball_width': self.ball_width,
            'ball_x_velocity': self.ball_x_velocity,
            'ball_y_velocity': self.ball_y_velocity,
            'ball_x_normalspeed': self.ball_x_normalspeed,
            'has_finished': self.has_finished,
            'is_running': self.is_running
        }

    def apply_player_movement(self):
        if self.p1_up:
            self.p1_y_pos = max(self.p1_y_pos - self.paddle_speed, 0)
        elif self.p1_down:
            self.p1_y_pos = min(self.p1_y_pos + self.paddle_speed, self.HEIGHT - self.paddle_height)
        if self.p2_up:
            self.p2_y_pos = max(self.p2_y_pos - self.paddle_speed, 0)
        elif self.p2_down:
            self.p2_y_pos = min(self.p2_y_pos + self.paddle_speed, self.HEIGHT - self.paddle_height)

    def apply_ball_movement(self):
        if (self.ball_x_pos + self.ball_x_velocity < self.p1_x_pos + self.paddle_width
            and (self.p1_y_pos < self.ball_y_pos + self.ball_y_velocity + self.ball_width < self.p1_y_pos + self.paddle_height + 10)):
            self.ball_x_velocity = -(self.ball_x_velocity - 0.1)
            self.ball_y_velocity = (self.p1_y_pos + self.paddle_height / 2 - self.ball_y_pos) / 16
            self.ball_y_velocity = -self.ball_y_velocity

        elif self.ball_x_pos + self.ball_x_velocity < 0:
            self.p2_score += 1
            self.reset_ball_position()
        if (self.ball_x_pos + self.ball_x_velocity > self.p2_x_pos - self.paddle_width
            and (self.p2_y_pos < self.ball_y_pos + self.ball_y_velocity + self.ball_width < self.p2_y_pos + self.paddle_height + 10)):
            self.ball_x_velocity = -(self.ball_x_velocity + 0.1)
            self.ball_y_velocity = (self.p2_y_pos + self.paddle_height / 2 - self.ball_y_pos) / 16
            self.ball_y_velocity = -self.ball_y_velocity
        elif self.ball_x_pos + self.ball_x_velocity > self.WIDTH:
            self.p1_score += 1
            self.reset_ball_position()
        if self.ball_y_pos + self.ball_y_velocity > self.HEIGHT or self.ball_y_pos + self.ball_y_velocity < 0:
            self.ball_y_velocity = -self.ball_y_velocity

        self.ball_x_pos += self.ball_x_velocity
        self.ball_y_pos += self.ball_y_velocity

        if self.p1_score >= self.maxscore or self.p2_score >= self.maxscore:
            self.endgame()

    def reset_ball_position(self):
        self.ball_x_pos = self.WIDTH / 2
        self.ball_y_pos = self.HEIGHT / 2
        self.ball_x_velocity = self.ball_x_normalspeed
        self.ball_y_velocity = 0
        self.p1_y_pos = self.HEIGHT / 2 - self.paddle_height / 2
        self.p2_y_pos = self.HEIGHT / 2 - self.paddle_height / 2

    def run(self):
        self.is_running = True
        while self.is_running:
            self.apply_player_movement()
            self.apply_ball_movement()
            time.sleep(0.025)

    def start(self):
        if (self.is_started is not True):
            self.is_started = True
            thread = threading.Thread(target=self.run)
            thread.start()

    def endgame(self):
        self.is_running = False
        self.has_finished = True
        if (self.game_type == "online"):
            new_match = Match.create_match_from_game(self)
            if hasattr(new_match, 'tourn_won'):
                delattr(new_match, 'tourn_won')
            new_match.save()

    async def key_up_pressed(self, username):
        if (username == self.player1):
            self.p1_up = True
        elif (username == self.player2):
            self.p2_up = True


    async def key_up_released(self, username):
        if (username == self.player1):
            self.p1_up = False
        elif (username == self.player2):
            self.p2_up = False

    async def key_down_pressed(self, username):
        if (username == self.player1):
            self.p1_down = True
        elif (username == self.player2):
            self.p2_down = True


    async def key_down_released(self, username):
        if (username == self.player1):
            self.p1_down = False
        elif (username == self.player2):
            self.p2_down = False


# ************************* CLASSE PLAYER DE BASE ****************************

class Player:
    def __init__(self, name):
        self.name = name
        self.player_status = 'Waiting'
        self.game:Game = None

    async def to_dict(self):
        return {
            'name': self.name,
            'player_status': self.player_status,
            'game': await self.game.to_dict() if self.game else None
        }





# ************************* LOGIQUE DU PONG DE BASE ****************************

class BasePongConsumer(AsyncWebsocketConsumer):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.game:Game = None

    async def connect(self):
        print("scope: ", self.scope)
        await self.accept()
        await self.setup_game()
        if self.game and self.game.player1 != "" and self.game.player2 != "":
            self.game.start()
            print("appelle send status")
            await self.send_status_update('is_playing')
        await self.send_connection_message()

    async def setup_game(self):
        pass

    async def disconnect(self, close_code):
        await self.send_status_update('is_online')
        print("passe par le disconnect")

    async def send_status_update(self, status):
        await self.channel_layer.group_send(
            "online_users",
            {
                'type': 'status_update',
                'user_id': self.scope['user'].id,
                'status': status
            }
        )
        print("send isplaying ou offline update from:", self.scope['user'].username)

    async def send_connection_message(self):
        user = self.scope['user']
        await self.send(text_data=json.dumps({
            'type': 'connection_established',
            'message': 'you are connected ' + user.username,
        }))

    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        message = text_data_json['message']
        username = self.scope['user'].username

        if message == 'update':
            await self.send_update()
        elif 'pressed' in message or 'released' in message:
            await self.handle_key_event(message, username)

    async def handle_key_event(self, message, username):
        if message == 'key_up_pressed':
            await self.game.key_up_pressed(username)
        elif message == 'key_up_released':
            await self.game.key_up_released(username)
        elif message == 'key_down_pressed':
            await self.game.key_down_pressed(username)
        elif message == 'key_down_released':
            await self.game.key_down_released(username)
        elif message == 'p2key_up_pressed' and self.game.game_type == "local":
            self.game.p2_up = True
        elif message == 'p2key_up_released' and self.game.game_type == "local":
            self.game.p2_up = False
        elif message == 'p2key_down_pressed' and self.game.game_type == "local":
            self.game.p2_down = True
        elif message == 'p2key_down_released' and self.game.game_type == "local":
            self.game.p2_down = False
        await self.send_debug_message(message)

    async def send_debug_message(self, message):
        await self.send(text_data=json.dumps({
            'type': 'debug',
            'message': message
        }))

    async def send_update(self):
        await self.send(text_data=json.dumps({
            'type': 'update received',
            'data': self.game.__dict__
        }))

# A MODIFIER POUR AJOUTER LA 3e OPTION (faire ca ici ?)
class FriendStatusConsumer(AsyncWebsocketConsumer):

    async def connect(self):
        self.user = self.scope['user']
        if self.user.is_authenticated:
            self.user_profile = await sync_to_async(UserProfile.objects.get)(username=self.user.username)
            self.user_profile.status = 'is_online'
            await sync_to_async(self.user_profile.save)()
            await self.channel_layer.group_add(
                "online_users",
                self.channel_name
            )
            await self.channel_layer.group_send(
                "online_users",
                {
                    'type': 'status_update',
                    'user_id': self.user.id,
                    'status': 'is_online'
                }
            )
            await self.accept()
        else:
            await self.close()
        print("user is:", self.user_profile)
        print("status is:", self.user_profile.status)

    async def disconnect(self, close_code):
        self.user_profile = await sync_to_async(UserProfile.objects.get)(username=self.user.username)
        self.user_profile.status = 'is_offline'
        print("user is:", self.user_profile)
        print("status is:", self.user_profile.status)
        await sync_to_async(self.user_profile.save)()
        await self.channel_layer.group_discard(
            "online_users",
            self.channel_name
        )
        await self.channel_layer.group_send(
            "online_users",
            {
                'type': 'status_update',
                'user_id': self.user.id,
                'status': 'is_offline'
            }
        )

    async def receive(self, text_data):
        print("receive dans le status consumer")
        text_data_json = json.loads(text_data)
        message = text_data_json['message']
        await self.send(text_data=json.dumps({
            'message': message
        }))

    async def status_update(self, event):
        await self.send(text_data=json.dumps({
            'type': 'status_update',
            'user_id': event['user_id'],
            'status': event['status']
        }))
        print("status update event is:", event)


# ************************* CONSUMER ASYNC FRIENDS REQUESTS ****************************

class FriendsRequestsConsumer(AsyncWebsocketConsumer):
    instances = {}

    async def connect(self):
        self.user = self.scope["user"]
        if self.user.is_authenticated:
            self.instances[self.user.id] = self
            await self.accept()
        else:
            print(f"User {self.user.username} is not authenticated")

    async def disconnect(self, close_code):
        if self.user and self.user.id in self.instances:
            del self.instances[self.user.id]
        await super().disconnect(close_code)

    async def receive(self, text_data):
        data = json.loads(text_data)
        inner_data= data['data']
        type = inner_data['type']
        if type == 'send_f_request':
            await self.send_f_updates(inner_data)
        elif type == 'accepted' or type == 'rejected':
            await self.handle_f_updates(inner_data)

    async def send_f_updates(self, data):
        receiver_id = data['receiver_id']
        receiver = await sync_to_async(UserProfile.objects.get)(id=receiver_id)
        sender_id = data['sender_id']
        sender = await sync_to_async(UserProfile.objects.get)(id=sender_id)
        from .views import friends_list
        friends_l = await sync_to_async(friends_list)(sender)
        for friend in friends_l['friends']:
            if friend.username == receiver:
                return
        invite_exists = await sync_to_async(Friend.objects.filter(sender=sender, receiver=receiver, status='pending').first)()
        if invite_exists:
            print("Invite already exists")
            return
        invite_exists = await sync_to_async(Friend.objects.filter(sender=receiver, receiver=sender, status='pending').first)()
        if invite_exists:
            print("Invite already exists")
            return
        await sync_to_async(Friend.objects.create)(sender=sender, receiver=receiver, status='pending')
        
        for user in [receiver, sender]:
            consumer = FriendsRequestsConsumer.instances.get(user.id)
            if consumer:
                await consumer.send(text_data=json.dumps(data))


    async def handle_f_updates(self, data):
        status = data['type']
        receiver_id = data['receiver_id']
        receiver = await sync_to_async(UserProfile.objects.get)(id=receiver_id)
        sender_id = data['sender_id']
        sender = await sync_to_async(UserProfile.objects.get)(id=sender_id)
        inv = await sync_to_async(Friend.objects.filter(sender=receiver, receiver=sender, status='pending').first)()      
        if inv:
            inv.status = status
            await sync_to_async(inv.save)()
        if status == 'accepted':
            data['rec_avatar'] = receiver.avatar.url
            data['rec_status'] = receiver.status
            data['rec_username'] = receiver.username
            data['send_avatar'] = sender.avatar.url
            data['send_status'] = sender.status
            data['send_username'] = sender.username
            from .views import match_stats
            data['send_stats'] = await sync_to_async(match_stats)(sender)
            data['rec_stats'] = await sync_to_async(match_stats)(receiver)
            print("data sender is:", data)
            print("data receiver is:", data)
        for user in [receiver, sender]:
            consumer = FriendsRequestsConsumer.instances.get(user.id)
            if consumer:
                await consumer.send(text_data=json.dumps(data))



# ************************* CONSUMER ASYNC USERLIST UPDATE ****************************

class UsersListUpdateConsumer(AsyncWebsocketConsumer):

    instances = {}      

    async def connect(self):
        self.user = self.scope["user"]
        if self.user.is_authenticated:
            self.instances[self.user.id] = self
            await self.accept()
            new_user = await sync_to_async(UserProfile.objects.get)(username=self.user.username)
            data = {}
            data['username'] = new_user.username
            data['avatar'] = new_user.avatar.url
            data['new_user_id'] = new_user.id
            await self.update_list(data)

        else:
            print(f"User {self.user.username} is not authenticated")

    async def disconnect(self, close_code):
        if self.user and self.user.id in self.instances:
            del self.instances[self.user.id]
        await super().disconnect(close_code)

    async def receive(self, text_data):
        pass

    async def update_list(self, data):

        new_user_id = data['new_user_id']
        new_user = await sync_to_async(UserProfile.objects.get)(id=new_user_id)
        for user_id, consumer in UsersListUpdateConsumer.instances.items():
            if user_id != new_user_id:
                current_user = await sync_to_async(UserProfile.objects.get)(id=user_id)
                friends1 = await sync_to_async(Friend.objects.filter)(sender=new_user, receiver=current_user, status='accepted')
                friends2 = await sync_to_async(Friend.objects.filter)(sender=current_user, receiver=new_user, status='accepted')
                friends = friends1.union(friends2)
                if not await sync_to_async(friends.exists)():
                    data['sender_id'] = user_id
                    print("sending data to:", current_user.username)
                    print("data is:", data)
                    await consumer.send(text_data=json.dumps(data))
                    print("consumer id:", consumer)
