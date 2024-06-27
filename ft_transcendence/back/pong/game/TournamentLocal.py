from ..consumers import Game, games_tournament_local, Player, BasePongConsumer
import time
import threading
import json

class TournamentLocal():
    def __init__(self, owner):
        self.game:Game = None
        self.players = []
        self.maxplayer = 0
        self.playername = ""
        self.status = "SelectSize"
        self.is_finished = False
        self.is_running = True
        self.timer = 10
        self.winner = None
        self.id = len(games_tournament_local)
        self.owner = owner
        self.is_started = False

    def prepare_next_match(self):
        if (self.game == None):
            self.game = Game(5, "Local")
        player:Player
        for player in self.players:
            if (self.status == "New_match" and player.player_status == "Waiting"):
                if (self.game.player1 == ""):
                    self.game.player1 = player.name
                    player.game = self.game
                elif (self.game.player2 == ""):
                    self.game.player2 = player.name
                    player.game = self.game
                    while (self.timer > 0):
                        time.sleep(1)
                        self.timer -= 1
                    player.game.start()
                    self.status = "Playing"
                    self.timer = 10
                    break
        if (self.game.is_started == False):
            for player in self.players:
                if (player.name == self.game.player1):
                    player.player_status = "Qualified"
                    self.game = None
                    player.game = None
                    self.status = "End_round"

    def handle_match(self):
        if (not self.game.has_finished):
            return
        player:Player
        for player in self.players:
            if (player.name == self.game.player1):
                if (self.game.p1_score > self.game.p2_score):
                    player.player_status = "Qualified"
                else:
                    player.player_status = "Disqualified"
            elif (player.name == self.game.player2):
                if (self.game.p2_score > self.game.p1_score):
                    player.player_status = "Qualified"
                else:
                    player.player_status = "Disqualified"
        self.game = None
        if not all(player.player_status in ["Qualified", "Disqualified"] for player in self.players):
            self.status = "New_match"
            self.prepare_next_match()
        else:
            self.status = "End_round"

    def next_round(self):
        player:Player
        for player in self.players:
            if (player.player_status == "Qualified"):
                player.player_status = "Waiting"
        count = 0
        for player in self.players:
            if (player.player_status == "Waiting"):
                count += 1
                if (count >= 2):
                    self.status = "New_match"
                    return
        if (count <= 1):
            self.status = "Ended"
            for player in self.players:
                if (player.player_status == "Waiting"):
                    break
            self.winner = player.name
            self.is_finished = True
            self.is_running = False

    def run(self):
        while self.is_running:
            if (self.status == "Adding"):
                pass
            elif (self.status == "New_match"):
                self.prepare_next_match()
            elif (self.status == "Playing"):
                self.handle_match()
            elif (self.status == "End_round"):
                self.next_round()
            time.sleep(0.001)

    async def addPlayers(self, playername):
        player:Player = Player(playername)
        self.players.append(player)

    async def start(self):
        if (self.is_started is not True):
            self.is_started = True
            thread = threading.Thread(target=self.run)
            thread.start()

    async def is_owner(self, user):
        if (user == self.owner):
            return (True)
        else:
            return (False)
    async def to_dict(self):
        return {
        'games': [await self.game.to_dict() if self.game else None],
        'players': [await player.to_dict() for player in self.players],
        'status': self.status,
        'is_finished': self.is_finished,
        'is_running': self.is_running,
        'timer': self.timer,
        'winner': self.winner,
        'maxplayer': self.maxplayer,
        'playername': self.playername
    }

    async def handle_key_event(self, message, username):
        if message == 'key_right_pressed' and self.status == 'SelectSize':
            if (self.maxplayer < 8):
                self.maxplayer += 1
        elif message == 'key_left_pressed' and self.status == 'SelectSize':
            if (self.maxplayer > 0):
                self.maxplayer -= 1
        elif message == 'key_enter_pressed':
            if (self.status == "SelectSize"):
                self.status = "SelectPlayerNames"
        if (self.game == None):
            return
        if message == 'key_up_pressed':
            await self.game.key_up_pressed(self.game.player1)
        elif message == 'key_up_released':
            await self.game.key_up_released(self.game.player1)
        elif message == 'key_down_pressed':
            await self.game.key_down_pressed(self.game.player1)
        elif message == 'key_down_released':
            await self.game.key_down_released(self.game.player1)
        elif message == 'p2key_up_pressed' and self.game.game_type == "Local":
            self.game.p2_up = True
        elif message == 'p2key_up_released' and self.game.game_type == "Local":
            self.game.p2_up = False
        elif message == 'p2key_down_pressed' and self.game.game_type == "Local":
            self.game.p2_down = True
        elif message == 'p2key_down_released' and self.game.game_type == "Local":
            self.game.p2_down = False


# ********************** SURCHARGE CLASSE POUR TOURNOI LOCAL *************************

class PongLocalTournament(BasePongConsumer):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.tournament = None

    async def setup_game(self):
        user = self.scope['user'].username
        found_tournament = False
        for tournament in games_tournament_local:
            if not tournament.is_finished and await tournament.is_owner(user):
                self.tournament = tournament
                found_tournament = True
                break
        if not found_tournament:
            self.tournament = TournamentLocal(user)
            games_tournament_local.append(self.tournament)
            await self.tournament.start()

    async def handle_key_pressed(self, key):
        if(self.tournament.status == "SelectPlayerNames"):
            if (len(key) == 1 and key[0].isascii() and len(self.tournament.playername) < 15):
                self.tournament.playername += key
            elif (key == "Backspace"):
                self.tournament.playername = self.tournament.playername[:-1]
            elif (key == "Enter"):
                if (self.tournament.playername != ""):
                    player:Player
                    for player in self.tournament.players:
                        if (player.name == self.tournament.playername):
                            return
                    new_player = Player(self.tournament.playername)
                    self.tournament.players.append(new_player)
                    if (len(self.tournament.players) == self.tournament.maxplayer):
                        self.tournament.status = "New_match"
                    self.tournament.playername = ""

    async def disconnect(self, close_code):
        self.tournament = None

    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        message = text_data_json['message']
        username = self.scope['user'].username
        game_data:Game = self.tournament.game
        if (game_data is not None):
            self.game = game_data
        if message == 'start':
            self.tournament.status = "New_match"
        if message == 'addPlayer':
            if message.startswith('addPlayer'):
                await self.tournament.addPlayers(text_data_json['playername'])
        if message == 'update':
            if (game_data is not None):
                game_data = await game_data.to_dict()
            tournament_data = {
                'tournament': await self.tournament.to_dict(),
                # 'players': [await player.to_dict() for player in self.tournament.players],
                # 'games': [await game.to_dict() for game in self.tournament.games],
                'game_data': game_data
            }
            await self.send(text_data=json.dumps({
                'type': 'update received',
                'data': tournament_data
            }))
        elif message == 'key_pressed' or message == 'key_released':
            await self.handle_key_pressed(text_data_json['key'])
        elif 'pressed' in message or 'released' in message:
            await self.tournament.handle_key_event(message, username)