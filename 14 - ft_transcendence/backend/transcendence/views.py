from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from django.views.decorators.http import require_http_methods
from .models import User
from django.contrib.auth import authenticate, login
from django.contrib.auth import logout
import json
from django.http import JsonResponse
from django.middleware.csrf import get_token
import logging
from django.views.decorators.csrf import csrf_protect
from .utils import Friend, get_user_data, create_user_from_data, get_friends_data

logger = logging.getLogger(__name__)

@require_http_methods(["POST"])
@csrf_protect
def register_view(request):
    try:
        data = json.loads(request.body.decode('utf-8'))
        user = create_user_from_data(data)

        user.status = True
        user.save()
        login(request, user)

        userOut = get_user_data(user)
        userOut['friends'] = get_friends_data(user)

        return JsonResponse({"user": userOut}, status=201)
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
            login(request, user)
            user.status = True
            user.save()

            userOut = get_user_data(user)
            userOut['friends'] = get_friends_data(user)

            return JsonResponse({"user": userOut}, status=200)
        else:
            # Le credenziali non sono corrette
            return JsonResponse({'error': 'Credenziali non valide'}, status=400)
    except Exception as e:
        print("Error during login:", str(e))
        return JsonResponse({'error': str(e)}, status=500)
    
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

def csrf(request):
    return JsonResponse({'csrfToken': get_token(request)})

