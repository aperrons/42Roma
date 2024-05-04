import { userpage } from './userpage.js';
import { getCsrfToken } from '/utils.js'
/*
const userData = {
    username: "Fanologo",
    gamesPlayed: 0,
    wins: 0,
    losses: 0,
    pair: 0
};

userpage(userData);*/

/*const routes = {
    '/' : home
};

const rootDiv = document.getElementById('root');
rootDiv.innerHTML = routes[window.location.pathname];
*/
window.AppData = {
    user: null
}

let csrfToken;

window.onload = function() {
    if (!getCsrfToken()) {
        fetch('/api/csrf/', { credentials: 'include' })  // Assicurati che le credenziali includano i cookie
        .then(response => response.json())
        .then(data => {
            csrfToken = data.csrfToken;  // Salva il token CSRF
        });
    }
};

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


