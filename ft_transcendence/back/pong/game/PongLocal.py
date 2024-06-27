from ..consumers import BasePongConsumer, games_local, Game
import json

class PongLocal(BasePongConsumer):
    async def setup_game(self):
        user = self.scope['user']
        user1 = user.username
        user2 = user.username + "_2"

        for game in games_local:
            if not game.has_finished and game.player1 == user1 and game.player2 == user2:
                self.game = game
                break
        if not self.game:
            self.game = Game(5, "local")
            self.game.player1 = user1
            self.game.player2 = user2
            games_local.append(self.game)
        else:
            self.game.is_running = True

    async def disconnect(self, close_code):
        print("local disconnect")
        user = self.scope['user']
        user1 = user.username
        user2 = user.username + "_2"

        for game in games_local:
            if not game.has_finished and game.player1 == user1 and game.player2 == user2:
                self.game = game
                break
        if (self.game):
            self.game.is_running = False
            self.game.has_finished = True

    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        message = text_data_json['message']
        if message == 'opponent_name':
            self.game.player2 = text_data_json['value']
        else:
            await super().receive(text_data)