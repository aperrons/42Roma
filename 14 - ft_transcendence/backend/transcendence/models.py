from django.contrib.auth.models import AbstractUser
from django.db import models

class User(AbstractUser):
    
    birth_date = models.DateField(null=True, blank=True)
    registered_via_oauth = models.BooleanField(default=False)
    gamesPlayed = models.IntegerField(default=0)
    wins = models.IntegerField(default=0)
    losses = models.IntegerField(default=0)
    pair = models.IntegerField(default=0)
    status = models.BooleanField(default=False)
    friends = models.ManyToManyField('self', blank=True, symmetrical=True)
    #profile_image = models.ImageField(upload_to='profiles/', null=True, blank=True)

    def save(self, *args, **kwargs):
        if not self.registered_via_oauth and not self.birth_date:
            raise ValueError("La data di nascita è necessaria per gli utenti non registrati via OAuth")
        super().save(*args, **kwargs)

    def __str__(self):
        return f"{self.first_name} {self.last_name} ({self.email})"
