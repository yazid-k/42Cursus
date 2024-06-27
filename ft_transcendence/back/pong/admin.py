from django.contrib import admin
from .models import UserProfile, Match, Friend
# Register your models here.

admin.site.register(UserProfile)
admin.site.register(Match)
admin.site.register(Friend)
# admin.site.register(Tournoi)
