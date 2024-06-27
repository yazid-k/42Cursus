from django.conf import settings
from django.conf.urls.static import static
from django.urls import path, re_path
from . import views
from . import consumers
from .game.TournamentLocal import PongLocalTournament
from .game.TournamentOnline import PongOnlineTournament
from .game.PongLocal import PongLocal
from .game.PongOnline import PongOnline


urlpatterns = [
	path('', views.home, name='home'),
	path('update_profile', views.update_profile, name='test'),
	path('oauth/', views.auth, name='auth'),
	path('logout/', views.logout_view, name='logout'),
	path('accounts/login/', views.sign_in, name='sign_in'),
	path('register', views.register, name='register'),
	path('sign_in', views.sign_in, name='sign_in'),
    path('api/', views.api, name='api'),
	re_path(r'ws/socket-pong-local/', PongLocal.as_asgi()),
	re_path(r'ws/socket-pong-online/', PongOnline.as_asgi()),
	re_path(r'ws/socket-pong-tournament-online/', PongOnlineTournament.as_asgi()),
	re_path(r'ws/socket-pong-tournament-local/', PongLocalTournament.as_asgi()),
	re_path(r'ws/status/', consumers.FriendStatusConsumer.as_asgi()),
	re_path(r'ws/friends_requests/', consumers.FriendsRequestsConsumer.as_asgi()),
	re_path(r'ws/userslist_update/', consumers.UsersListUpdateConsumer.as_asgi()),
	re_path(r'ws/stats/', consumers.StatsConsumer.as_asgi()),
    re_path(r'ws/language/', consumers.LanguageConsumer.as_asgi())
] + static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
