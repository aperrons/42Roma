import { loadHomePage } from './homeView.js';
import { loadLoginPage } from './loginView.js';
import { loadRegistrationPage } from './registrationView.js';

window.AppData = {
    user: null
}

const routes = {
    '/ft_transcendence/': () => loadHomePage(),
    '/ft_transcendence/login': () => loadLoginPage(),
    '/ft_transcendence/registration': () => loadRegistrationPage()
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

