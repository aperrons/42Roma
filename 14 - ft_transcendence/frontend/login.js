import { userpage } from './userpage.js';
import { getCsrfToken } from '/utils.js'

document.getElementById('loginInButton').addEventListener('click', login);

function login(event) {
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

    fetch('/api/login/', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json',
        'X-CSRFToken': csrfToken
    },
        body: JSON.stringify(userData),
        credentials: 'include'
    })
    .then(response => {
        if (response.ok) {
            return response.json();
        } else if (response.status === 400 || response.status === 401) {
            return response.json().then(data => {
                return Promise.reject(data.error);
            });
        } else {
            return Promise.reject('An unexpected error occurred');
        }
    })
    .then(data => {
        console.log('Login successful:', data);
        userpage(data.user);
    })
    .catch(error => {
        console.log('Handled error:', error);
    });
}



