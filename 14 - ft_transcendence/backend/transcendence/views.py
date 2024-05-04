from django.http import JsonResponse
from django.utils.decorators import method_decorator
from rest_framework.decorators import api_view, permission_classes, authentication_classes
from rest_framework.permissions import IsAuthenticated
from rest_framework_simplejwt.authentication import JWTAuthentication
from django.views.decorators.http import require_http_methods
from .models import User
from django.contrib.auth import authenticate, login as django_login
from django.contrib.auth import logout
import json
from django.http import JsonResponse
from django.middleware.csrf import get_token
import logging
from django.views.decorators.csrf import csrf_protect
from .utils import Friend, get_user_data, create_user_from_data, get_friends_data, create_user_from_42data
from rest_framework_simplejwt.tokens import RefreshToken
from rest_framework.response import Response
import os, random
from django.conf import settings
from django.core.files import File
from urllib.parse import urlencode
import secrets
from django.shortcuts import redirect
import requests
import traceback
from django.http import JsonResponse
from requests.exceptions import RequestException

logger = logging.getLogger(__name__)

@require_http_methods(["POST"])
@csrf_protect
def register_view(request):
    try:
        data = json.loads(request.body.decode('utf-8'))
        user = create_user_from_data(data)
        '''
        profiles_dir = os.path.join(settings.BASE_DIR, 'app/profiles')
        profiles_list = os.listdir(profiles_dir)
        random_image_name = random.choice(profiles_list)
        random_image_path = os.path.join(profiles_dir, random_image_name)

        with open(random_image_path, 'rb') as img:
            user.profile_image.save(random_image_name, File(img), save=True)
        '''
        user.status = True
        user.save()
        django_login(request, user)

        refresh = RefreshToken.for_user(user)

        userOut = get_user_data(user)
        userOut['friends'] = get_friends_data(user)
        #userOut['profile_image'] = user.profile_image.url

        return JsonResponse({
            'user': userOut,
            'refresh': str(refresh),
            'access': str(refresh.access_token),
        }, status=201)
    except Exception as e:
        print("ERROr:", str(e))
        return JsonResponse({"error": str(e)}, status=400)
    
@require_http_methods(["POST"])
@csrf_protect
def login_view(request):
    try:
        data = json.loads(request.body.decode('utf-8'))
        username = data.get('username')
        password = data.get('password')

        user = authenticate(username=username, password=password)
        if user:
            django_login(request, user)  # Log in l'utente nel framework di sessione Django

            # Generazione dei token JWT
            refresh = RefreshToken.for_user(user)
            
            # Aggiorna lo stato dell'utente se necessario
            user.status = True
            user.save()
  
            # Ottieni i dati aggiuntivi dell'utente
            userOut = get_user_data(user)
            userOut['friends'] = get_friends_data(user)

            # Invia i token JWT e i dati dell'utente al client
            return JsonResponse({
                'user': userOut,
                'refresh': str(refresh),
                'access': str(refresh.access_token),
            }, status=200)
        else:
            # Gestione delle credenziali non valide
            return JsonResponse({'error': 'Credenziali non valide'}, status=400)
    except Exception as e:
        # Logging l'errore per ulteriori analisi e invio di una risposta generica di errore
        print("Error during login:", str(e))
        return JsonResponse({'error': 'Errore del server'}, status=500)  # Evita di inviare dettagli dell'errore al client
    
@require_http_methods(["POST"])
@csrf_protect
def logout_view(request):

    user = request.user

    if user.is_authenticated:
        user.status = False
        user.save()
        logout(request)
        
        return JsonResponse({'success': 'Logout successful'}, status=200)
    else:
        return JsonResponse({'error': 'Not authenticated'}, status=400)

#@method_decorator(csrf_protect, name='dispatch')
@api_view(['POST'])
@authentication_classes([JWTAuthentication])
@permission_classes([IsAuthenticated])
def change_username_view(request):
    try:
        data = json.loads(request.body.decode('utf-8'))
        new_username = data.get('username')

        if not new_username:
            return JsonResponse({'error': 'Username is required'}, status=400)

        # Controlla la disponibilità del nuovo username
        if User.objects.filter(username=new_username).exists():
            return JsonResponse({'error': 'This username is already taken'}, status=409)

        # Aggiorna il nome utente
        user = request.user
        user.username = new_username
        user.save()

        # Ritorna il nuovo username per conferma
        return JsonResponse({'new_username': user.username}, status=200)

    except Exception as e:
        # Logging l'errore per ulteriori analisi
        print("Error during username change:", str(e))
        return JsonResponse({'error': 'Server error'}, status=500)

@csrf_protect
def login42_start(request):

    state_token = secrets.token_urlsafe()
    request.session['oauth_state'] = state_token

    params = urlencode({
        'client_id': settings.CLIENT_ID,
        'redirect_uri': settings.REDIRECT_URI,
        'response_type': 'code',
        'scope': 'public',
        'state': state_token
    })

    auth_url = f"https://api.intra.42.fr/oauth/authorize?{params}"

    return JsonResponse({'url': auth_url})

@require_http_methods(["GET"])
@csrf_protect
def login42_oauth(request):
    state_token = request.GET.get('state')
    saved_state = request.session.pop('oauth_state', None)

    if not saved_state or saved_state != state_token:
        return JsonResponse({'error': 'State mismatch'}, status=400)

    code = request.GET.get('code')
    print("CODE")
    print(code)
    try:
        token_response = requests.post('https://api.intra.42.fr/oauth/token', data={
            'grant_type': 'authorization_code',
            'code': code,
            'redirect_uri': settings.REDIRECT_URI,
            'client_id': settings.CLIENT_ID,
            'client_secret': settings.CLIENT_SECRET,
        })

        if not token_response.ok:
            return JsonResponse({'error': 'Failed to fetch token', 'details': token_response.text}, status=token_response.status_code)

        token_json = token_response.json()
        access_token = token_json.get('access_token')
        if not access_token:
            return JsonResponse({'error': 'No access token provided'}, status=400)

        user_info_response = requests.get('https://api.intra.42.fr/v2/me', headers={'Authorization': f'Bearer {access_token}'})
        if not user_info_response.ok:
            return JsonResponse({'error': 'Failed to fetch user info', 'details': user_info_response.text}, status=user_info_response.status_code)

        user_info = user_info_response.json()
        user = create_user_from_42data(user_info)
        django_login(request, user)

        refresh = RefreshToken.for_user(user)
        userOut = get_user_data(user)
        userOut['friends'] = get_friends_data(user)

        return JsonResponse({
            'user': userOut,
            'refresh': str(refresh),
            'access': str(refresh.access_token),
        }, status=200)
    except RequestException as e:
        return JsonResponse({'error': 'Network error', 'info': str(e)}, status=500)
    except Exception as e:
        traceback_details = traceback.format_exc()
        return JsonResponse({'error': 'Errore del server', 'info': str(e), 'trace': traceback_details}, status=500)



def csrf(request):
    return JsonResponse({'csrfToken': get_token(request)})

