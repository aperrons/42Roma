from .models import User

class Friend:
    def __init__(self, name, status):
        self.name = name
        self.status = status
    
    def to_dict(self):
        return {
            'username': self.username,
            'status': self.status
        }

    def __str__(self):
        return f"{self.name} {self.status}"

def get_user_data(user):
    userOut = {
        'username': user.username,
        'gamesPlayed': user.gamesPlayed,
        'wins': user.wins,
        'losses': user.losses,
        'pair': user.pair
    }
    return userOut

def create_user_from_data(data):
    return User.objects.create_user(
        first_name=data['firstName'],
        last_name=data['lastName'],
        birth_date=data['birthDate'],
        email=data['email'],
        username=data['username'],
        password=data['password']
    )

def filter_users(friends):
    friends_data = []

    for friend in friends:
        friend_data = {
            'username': friend.username,
            'status': getattr(friend, 'status', 'True')  # Utilizza un valore di default se 'status' non è disponibile
        }
        friends_data.append(friend_data)
    return friends_data

def get_friends_data(user):
    friends = []

    if (hasattr(user, 'friends')):
        friends = user.friends.all()
    
    filtered_friends = filter_users(friends)
    return filtered_friends