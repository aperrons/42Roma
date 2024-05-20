import { loadHomePage } from './Views/homeView.js';
import { loadLoginPage } from './Views/loginView.js';
import { loadRegistrationPage } from './Views/registrationView.js';
import { loadUserPage } from './Views/userpageView.js';
import { register} from './login.js'

window.AppData = {
    user: null
}

const routes = {
    '/ft_transcendence/': () => loadHomePage(),
    '/ft_transcendence/login': () => loadLoginPage(),
    '/ft_transcendence/registration': () => loadRegistrationPage(),
    '/ft_transcendence/userpage': () => loadUserPage()
};

function handleRouteChange() {
    const path = window.location.pathname
    const routeAction = routes[path];
    if (routeAction) {
        routeAction()
    } else {
        document.getElementById('content').innerHTML = '<h1>404 - Page Not Found</h1>';
    }
}

function navigateTo(path) {
    history.pushState({}, '', path);
    handleRouteChange();
}

window.onpopstate = handleRouteChange;

document.addEventListener('DOMContentLoaded', () => {
    handleRouteChange();  // Carica la rotta iniziale al caricamento della pagina

    const registrationButton = document.getElementById('register-button');
    if (registrationButton) {
        registrationButton.addEventListener('click', () => {
            navigateTo('/ft_transcendence/registration');
        });
    }

    document.addEventListener('click', (event) => {
        if (event.target && event.target.id === 'register-submit-button') {
            event.preventDefault();
            handleRegistration();
        }
    });

    async function handleRegistration() {
        const userData = {
            firstName: document.getElementById('first-name').value,
            lastName: document.getElementById('last-name').value,
            birthDate: document.getElementById('birth-date').value,
            email: document.getElementById('email').value,
            username: document.getElementById('new-username').value,
            password: document.getElementById('new-password').value
        };
    
        try {
            await register(userData);
            navigateTo('/ft_transcendence/userpage'); // Naviga alla pagina dell'utente
        } catch (error) {
            console.error('Registration failed:', error);
            document.getElementById('content').innerHTML = '<h1>Registration failed. Please try again.</h1>';
        }
    }


    /*
    const registrationSubmitButton = document.getElementById('register-submit-button');
    if (registrationSubmitButton) {
        registrationSubmitButton.addEventListener('click', async () => {
            //se è andato tutto bene
            navigateTo('/ft_transcendence/userpage');
        });
    }*/
});


/*
document.getElementById('welcomeButton').addEventListener('click', function() {
    document.getElementById('buttonContainer').style.display = 'block'; // Mostra i bottoni di login e registrazione
    this.style.display = 'none'; // Nasconde il bottone di benvenuto
});

document.getElementById('loginButton').addEventListener('click', function() {
    document.getElementById('loginForm').style.display = 'block';
    document.getElementById('registerForm').style.display = 'none';
    document.getElementById('buttonContainer').style.display = 'none'; // Opzionale: nascondi i bottoni di navigazione
});

document.getElementById('registerButton').addEventListener('click', function() {
    document.getElementById('registerForm').style.display = 'block';
    document.getElementById('loginForm').style.display = 'none';
    document.getElementById('buttonContainer').style.display = 'none'; // Opzionale: nascondi i bottoni di navigazione
});
*/

