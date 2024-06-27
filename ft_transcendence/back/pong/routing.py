from django.urls import re_path
from . import consumers
from .game.TournamentLocal import PongLocalTournament
from .game.TournamentOnline import PongOnlineTournament
from .game.PongLocal import PongLocal
from .game.PongOnline import PongOnline


websocket_urlpatterns = [

    re_path(r'ws/socket-pong-local/', PongLocal.as_asgi()),
    re_path(r'ws/socket-pong-online/', PongOnline.as_asgi()),
    re_path(r'ws/socket-pong-tournament-online/', PongOnlineTournament.as_asgi()),
    re_path(r'ws/socket-pong-tournament-local/', PongLocalTournament.as_asgi()),
    re_path(r'ws/stats/', consumers.StatsConsumer.as_asgi()),
	re_path(r'ws/status/', consumers.FriendStatusConsumer.as_asgi()),
    re_path(r'ws/language/', consumers.LanguageConsumer.as_asgi()),
	re_path(r'ws/friends_requests/', consumers.FriendsRequestsConsumer.as_asgi()),
	re_path(r'ws/userslist_update/', consumers.UsersListUpdateConsumer.as_asgi())
]
