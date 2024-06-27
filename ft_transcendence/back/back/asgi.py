"""
ASGI config for back project.

It exposes the ASGI callable as a module-level variable named ``application``.

For more information on this file, see
https://docs.djangoproject.com/en/5.0/howto/deployment/asgi/
"""

import os
from django.urls import re_path
from pong import consumers
from django.core.asgi import get_asgi_application
from channels.routing import ProtocolTypeRouter, URLRouter
from channels.auth import AuthMiddlewareStack
import pong.routing
from pong.game.TournamentLocal import PongLocalTournament
from pong.game.TournamentOnline import PongOnlineTournament
from pong.game.PongOnline import PongOnline
from pong.game.PongLocal import PongLocal

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'back.settings')

application = ProtocolTypeRouter({
    'http':get_asgi_application(),
    'websocket':AuthMiddlewareStack(
        URLRouter(
            # pong.routing.websocket_urlpatterns
            [
            re_path(r'ws/socket-pong-local/', PongLocal.as_asgi()),
            re_path(r'ws/socket-pong-online/', PongOnline.as_asgi()),
            re_path(r'ws/socket-pong-tournament-online/', PongOnlineTournament.as_asgi()),
            re_path(r'ws/socket-pong-tournament-local/', PongLocalTournament.as_asgi()),
            re_path(r'ws/stats/$', consumers.StatsConsumer.as_asgi()),
			re_path(r'ws/status/', consumers.FriendStatusConsumer.as_asgi()),
            re_path(r'ws/language/', consumers.LanguageConsumer.as_asgi()),
			re_path(r'ws/friends_requests/', consumers.FriendsRequestsConsumer.as_asgi()),
			re_path(r'ws/userslist_update/', consumers.UsersListUpdateConsumer.as_asgi())
            ]
        )
    )
})
