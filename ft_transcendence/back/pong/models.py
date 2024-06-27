from django.db import models
from django.utils import timezone
from django.contrib.auth.models import AbstractUser
from django.db.models.signals import post_save
from django.dispatch import receiver
from asgiref.sync import async_to_sync

class UserProfile(AbstractUser):
    update_from = models.CharField(max_length=100, default='created', blank=True, null=True)
    email = models.EmailField(unique=True)
    tourn_won = models.IntegerField(default=0)
    matches_won = models.IntegerField(default=0)
    matches_lost = models.IntegerField(default=0)
    avatar = models.ImageField(upload_to='avatars/', default='avatars/default2.png')
    status = models.CharField(max_length=10, default='is_offline')
    language = models.CharField(max_length=9, default='english')
    def __str__(self):
        return self.username

class Match(models.Model):
    player1 = models.CharField(max_length=30, blank=True)
    player2 = models.CharField(max_length=30, blank=True)
    player1_score = models.IntegerField(default=0)
    player2_score = models.IntegerField(default=0)
    timestamp = models.DateTimeField(auto_now_add=True)

    @classmethod
    def create_match_from_game(cls, game_instance):
        player1_user = None
        player1_profiles = UserProfile.objects.filter(username=game_instance.player1)
        if player1_profiles.exists():
            player1_user = player1_profiles.first()

        player2_user = None
        player2_profiles = UserProfile.objects.filter(username=game_instance.player2)
        if player2_profiles.exists():
            player2_user = player2_profiles.first()

        if game_instance.p1_score > game_instance.p2_score:
                if player1_user is not None:
                    player1_user.matches_won += 1
                    player1_user.update_from = 'p1 match won save'
                    delattr(player1_user, 'tourn_won')
                    player1_user.save()
                if player2_user is not None:
                    player2_user.matches_lost += 1
                    player2_user.update_from = 'p2 match lost save'
                    delattr(player2_user, 'tourn_won')
                    player2_user.save()
        elif game_instance.p1_score < game_instance.p2_score:
                if player1_user is not None:
                    player1_user.matches_lost += 1
                    player1_user.update_from = 'p1 match lost save'
                    delattr(player1_user, 'tourn_won')
                    player1_user.save()
                if player2_user is not None:
                    player2_user.matches_won += 1
                    player2_user.update_from = 'p2 match won save'
                    delattr(player2_user, 'tourn_won')
                    player2_user.save()

        match = Match.objects.create(
            player1=game_instance.player1,
            player2=game_instance.player2,
            player1_score=game_instance.p1_score,
            player2_score=game_instance.p2_score,
            )
        return match

    def __str__(self):
        return self.player1 + ' vs ' + self.player2

@receiver(post_save, sender=Match)
def update_stats(sender, instance, created, **kwargs):
    if created:
        for user in [instance.player1, instance.player2]:
            from .consumers import StatsConsumer
            try:
                userProfile = UserProfile.objects.get(username=user)
            except UserProfile.DoesNotExist:
                print(f"UserProfile with username {user} does not exist.")
                continue
            consumer = StatsConsumer.instances.get(userProfile.id)
            if consumer:
                from .views import match_stats
                stats = match_stats(userProfile)
                async_to_sync(consumer.send_stats_to_all)(stats)

class Friend(models.Model):
    STATUS_CHOICES = (
        ('pending', 'Pending'),
        ('accepted', 'Accepted'),
        ('rejected', 'Rejected'),
    )
    sender = models.ForeignKey(UserProfile, on_delete=models.CASCADE, related_name='sender')
    receiver = models.ForeignKey(UserProfile, on_delete=models.CASCADE, related_name='receiver')
    status = models.CharField(max_length=10, choices=STATUS_CHOICES, default='pending')

    def __str__(self):
        return self.sender.username + ' -> ' + self.receiver.username + ' (' + self.status + ')'
