from ..consumers import BasePongConsumer, games_online, Game

class PongOnline(BasePongConsumer):
    async def setup_game(self):
        user = self.scope['user']
        for game in games_online:
            if not game.has_finished and (game.player1 == user.username or game.player2 == user.username):
                self.game = game
                break
            if not self.game and not game.has_finished and (not game.player1 or not game.player2):
                self.game = game
                if not self.game.player1 and game.player2 != user.username:
                    self.game.player1 = user.username
                elif not self.game.player2 and game.player1 != user.username:
                    self.game.player2 = user.username
                break
        if not self.game:
            self.game = Game(5, "online")
            self.game.player1 = user.username
            games_online.append(self.game)
