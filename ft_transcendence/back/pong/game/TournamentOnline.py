from ..consumers import BasePongConsumer, games_tournament_online, Game, Player
from ..models import UserProfile
import json
import time
import threading

class PongOnlineTournament(BasePongConsumer):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.tournament = None

    async def setup_game(self):
        user = self.scope['user'].username
        found_tournament = False
        for tournament in games_tournament_online:
            if not tournament.is_finished and await tournament.has_player(user):
                self.tournament = tournament
                await self.tournament.add_player(user)
                found_tournament = True
                break
        if not found_tournament:
            for tournament in games_tournament_online:
                if not tournament.is_finished and tournament.status == "Waiting" and len(tournament.players) < 8:
                    self.tournament = tournament
                    await self.tournament.add_player(user)
                    found_tournament = True
                    break
        if not found_tournament:
            self.tournament = TournamentOnline()
            games_tournament_online.append(self.tournament)
            await self.tournament.add_player(user)
            await self.tournament.start()

        print(f"User {user} joined tournament {self.tournament.id}")
        print(f"Current players: {[player.name for player in self.tournament.players]}")

    async def disconnect(self, code):
        self.tournament = None

    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        message = text_data_json['message']
        username = self.scope['user'].username
        game_data:Game = self.tournament.getupdate(username)
        if (game_data is not None):
            self.game = game_data
        if message == 'update':
            if (game_data is not None):
                game_data = await game_data.to_dict()
            player:Player = await self.tournament.get_player(username)
            if (player != None):
                player = player.player_status
            tournament_data = {
                'tournament': await self.tournament.to_dict(),
                'game_data': game_data,
                'player_status':player
            }
            await self.send(text_data=json.dumps({
                'type': 'update received',
                'data': tournament_data
            }))
        elif 'pressed' in message or 'released' in message:
            await self.tournament.handle_key_event(message, username)


class TournamentOnline():
    def __init__(self):
        self.games = []
        self.players = []
        self.is_started = False
        self.status = "Waiting"
        self.is_finished = False
        self.is_running = True
        self.timer = 10
        self.winner = None
        self.qualif = None
        self.id = len(games_tournament_online)

    async def to_dict(self):
        return {
        'games': [await game.to_dict() for game in self.games] if self.games else [],
        'players': [await player.to_dict() for player in self.players],
        'status': self.status,
        'is_finished': self.is_finished,
        'is_running': self.is_running,
        'timer': self.timer,
        'winner': self.winner,
        'qualif': self.qualif
    }

    def add_player_to_game(self, player):
        game:Game
        for game in self.games:
            if (game.player1 == "" or game.player2 == ""):
                player.game = game
                if (player.game.player1 == ""):
                    player.game.player1 = player.name
                elif (player.game.player2 == ""):
                    player.game.player2 = player.name
                # connecter ici avec la BD pour apairer les joueurs 2 par 2
                break
        if player.game == None:
            player.game = Game(5, "online")
            player.game.player1 = player.name
            self.games.append(player.game)

    def wait(self):
        if self.timer >= 0 and len(self.players) > 1:
            time.sleep(1)
            self.timer -= 1
        elif self.timer < 0:
            self.status = "Starting"
            if (len(self.players) > 4):
                self.qualif = 3
            elif len(self.players) > 2:
                self.qualif = 2
            else:
                self.qualif = 1

    def starting(self):
        for player in self.players:
            if player.player_status == "Waiting":
                self.add_player_to_game(player)
        for player in self.players:
            if player.game and not player.game.is_running and player.game.player1 and player.game.player2:
                player.game.start()
                player.player_status = "Playing"
                print(f"Game started for {player.name} with players {player.game.player1} and {player.game.player2}")
            if player.game and player.game.is_running:
                player.player_status = "Playing"
        self.status = "Started"

    def started(self):
        for player in self.players:
            if player.player_status in ["Disqualified", "Qualified"]:       #parcoure les joueurs, ignore si qualifie/discalifie
                continue
            if player.player_status == "Waiting" and player.game and (player.game.player1 == "" or player.game.player2 == ""): # qualifie le joueur s'il est seul
                player.player_status = "Qualified"
            if player.game and player.game.has_finished and player.game.player1 == player.name:     # Si la partie est finie, regarde le score et determine un gagnant
                if player.game.p1_score <= player.game.p2_score:
                    player.player_status = "Disqualified"
                else:
                    player.player_status = "Qualified"
            elif player.game and player.game.has_finished and player.game.player2 == player.name:   # pareil pour player 2
                if player.game.p2_score <= player.game.p1_score:
                    player.player_status = "Disqualified"
                    player.game = None
                else:
                    player.player_status = "Qualified"
                    player.game = None
        if all(player.player_status in ["Qualified", "Disqualified"] for player in self.players):    #parcours les joueurs, s'ils sont tous qualif/disqualif, rentre dans les conditions
            if (self.qualif == 1):       #finale jouee, donne un gagnant pour le tournois
                self.status = "Ending"
                for player in self.players:
                    player.game = None
                    if (player.player_status == "Qualified"):
                        self.winner = player.name
                        from django.db import transaction
                        with transaction.atomic():
                            winnerProfiles = UserProfile.objects.select_for_update().filter(username=self.winner)
                            if winnerProfiles.exists():
                                winnerProfile = winnerProfiles.first()
                                winnerProfile.tourn_won += 1
                                winnerProfile.update_from = "tourn update"
                                winnerProfile.save()
                                print("stats saved")
            else:                       #relance une session de parties
                self.games = []
                for player in self.players:
                    player.game = None
                    if (player.player_status == "Qualified"):
                        player.player_status = "Waiting"
                self.status = "Starting"
                self.qualif -= 1
                self.timer = 10
                while (self.timer >= 0):
                    time.sleep(1)
                    self.timer -= 1

    def run(self):
        while self.is_running:
            if self.status == "Waiting":
                self.wait()
            if self.status == "Starting":
                self.starting()
                # for player in self.players:
                #     if player.player_status == "Waiting":
                #         self.add_player_to_game(player, round, current_tourn)
                # for player in self.players:
                #     if not player.game.is_running and player.game.player1 and player.game.player2:
                #         player.game.start()
                #         player.player_status = "Playing"
                #         print(f"Game started for {player.name} with players {player.game.player1} and {player.game.player2}")
                #     if player.game.is_running:
                #         player.player_status = "Playing"
                # self.status = "Started"
            if self.status == "Started":
                self.started()
            if self.status == "Ending":
                self.is_finished = True
                self.is_running = False
                self.status == "Finished"
            time.sleep(0.005)
                # for player in self.players:
                #     if player.player_status == "Waiting" and (player.game.player1 is None or player.game.player2 is None):
                #         player.player_status = "Winner"
                #     if player.game.has_finished and player.game.player1 == player.name:
                #         if player.game.p1_score <= player.game.p2_score:
                #             player.player_status = "Disqualified"
                #         else:
                #             player.player_status = "Winner"
                #     elif player.game.has_finished and player.game.player2 == player.name:
                #         if player.game.p2_score <= player.game.p1_score:
                #             player.player_status = "Disqualified"
                #         else:
                #             player.player_status = "Winner"
                #             self.winner = player.name
                # round+=1
                # if self.winner:
                #     self.is_running = False
                #     self.is_finished = True
                #     self.status = "Finished"
                #     winner_user=User.objects.get(username=self.winner)
                #     winner_userProfile=UserProfile.objects.get(user=winner_user)
                #     winner_userProfile.tourn_won += 1
                #     winner_userProfile.save()

         
    async def add_player(self, username):
        if self.status == "Waiting":
            for player in self.players:
                if player.name == username:
                    print(f"Player {username} is already in the tournament.")
                    return
            new_player = Player(username)
            self.players.append(new_player)
            print(f"Added player {username} to the tournament.")

    async def start(self):
        if (self.is_started is not True):
            self.is_started = True
            thread = threading.Thread(target=self.run)
            thread.start()


    async def has_player(self, username):
        for player in self.players:
            if player.name == username:
                return True
        return False
    
    async def get_player(self, username):
        for player in self.players:
            if player.name == username:
                return player
        return None

    def getupdate(self, username):
        player:Player
        for player in self.players:
            if (player.name == username):
                return player.game

    async def handle_key_event(self, message, username):
        player:Player
        for player in self.players:
            if (player.name == username):
                break
        if (player == None or player.game == None):
            return
        if message == 'key_up_pressed':
            await player.game.key_up_pressed(username)
        elif message == 'key_up_released':
            await player.game.key_up_released(username)
        elif message == 'key_down_pressed':
            await player.game.key_down_pressed(username)
        elif message == 'key_down_released':
            await player.game.key_down_released(username)
        elif message == 'p2key_up_pressed' and player.game.game_type == "local":
            player.game.p2_up = True
        elif message == 'p2key_up_released' and player.game.game_type == "local":
            player.game.p2_up = False
        elif message == 'p2key_down_pressed' and player.game.game_type == "local":
            player.game.p2_down = True
        elif message == 'p2key_down_released' and player.game.game_type == "local":
            player.game.p2_down = False
            