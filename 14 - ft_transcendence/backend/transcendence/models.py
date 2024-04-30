from django.contrib.auth.models import AbstractUser
from django.db import models

class User(AbstractUser):
    
    birth_date = models.DateField()
    gamesPlayed = models.IntegerField(default=0)
    wins = models.IntegerField(default=0)
    losses = models.IntegerField(default=0)
    pair = models.IntegerField(default=0)
    status = models.BooleanField(default=False)
    friends = models.ManyToManyField('self', blank=True, symmetrical=True)

    def __str__(self):
        return f"{self.first_name} {self.last_name} ({self.email})"
