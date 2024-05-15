import { userpage } from './userpage.js';
import { getCsrfToken } from './utils.js'

document.getElementById('loginInButton').addEventListener('click', login);

async function login(event) {
    event.preventDefault();

    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;

    if (!username.trim() || !password.trim()) {
        alert('Both username and password are required');
        return;
    }

    const userData = { username, password };
    const csrfToken = getCsrfToken();

    console.log(userData);

    try {
        const response = await fetch('/api/login/', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'X-CSRFToken': csrfToken
            },
            body: JSON.stringify(userData),
            credentials: 'include'  // Include i cookie nella richiesta per gestire la sessione CSRF
        });

        if (!response.ok) {
            const errorData = await response.json();
            throw new Error(errorData.error || 'Failed to login');
        }

        const data = await response.json();
        console.log('Login successful:', data);
        window.AppData.user = data;
        userpage(data.user);  // Chiama una funzione che gestisce la navigazione dell'utente loggato
    } catch (error) {
        console.error('Login failed:', error);  // Mostra un messaggio di errore più appropriato
        alert('Login failed: ' + error.message);  // Avvisa l'utente del fallimento del login
    }
}



