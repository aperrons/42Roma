//import { isValidEmail, isValidName, isAdult, isValidPassword } from './utils.js';
//import { userpage } from './userpage.js';
import { getCsrfToken } from './utils.js';
/*
document.getElementById('first-name').addEventListener('focusout', validateName);
document.getElementById('last-name').addEventListener('focusout', validateName);
document.getElementById('birth-date').addEventListener('focusout', validateAge);
document.getElementById('email').addEventListener('focusout', validateEmail);
document.getElementById('new-username').addEventListener('focusout', validateName);
document.getElementById('new-password').addEventListener('input', validatePassword);
document.getElementById('form').addEventListener('submit', register);

function displayError(message) {
    const errorDiv = document.getElementById('errorMessages');
    errorDiv.innerText = message;
    errorDiv.style.display = 'block';
}

function clearError() {
    const errorDiv = document.getElementById('errorMessages');
    errorDiv.innerText = '';
    errorDiv.style.display = 'none';
}

function validateName(event) {
    const input = event.target;
    if (!isValidName(input.value)) {
        input.classList.add('invalid');
        displayError('Nome e cognome possono contenere solo lettere e numeri.');
    } else {
        input.classList.remove('invalid');
        clearError();
    }
    checkFormValidity();
}

function validateAge() {
    const input = document.getElementById('birthDate');
    if (!isAdult(input.value)) {
        input.classList.add('invalid');
        displayError('Devi avere almeno 18 anni per registrarti.');
    } else {
        input.classList.remove('invalid');
        clearError();
    }
    checkFormValidity();
}

function validateEmail() {
    const input = document.getElementById('email');
    if (!isValidEmail(input.value)) {
        input.classList.add('invalid');
        displayError('Inserisci un indirizzo email valido.');
    } else {
        input.classList.remove('invalid');
        clearError();
    }
    checkFormValidity();
}

function validatePassword() {
    const input = document.getElementById('newPassword');
    if (!isValidPassword(input.value)) {
        input.classList.add('invalid');
        displayError('La password deve contenere almeno 6 caratteri, di cui almeno una maiuscola e un numero.');
    } else {
        input.classList.remove('invalid');
        clearError();
    }
    checkFormValidity();
}

function checkFormValidity() {
    const inputs = document.querySelectorAll('#first-name, #last-name, #birth-date, #email, #new-username, #new-password');
    const allValid = Array.from(inputs).every(input => {
        return input.value.trim() !== "" && !input.classList.contains('invalid');
    });

    const registerSubmitButton = document.getElementById('registerSubmitButton');
    registerSubmitButton.disabled = !allValid;

    console.log('Register button enabled:', !registerSubmitButton.disabled);
}*/


export async function register(event) {
    event.preventDefault();
    if (document.getElementById('register-submit-button').disabled) {
        alert('Correggi gli errori nel form prima di registrarti.');
        return;
    }
    console.log("SIAMOOOOOO QUIIIIIIIIIIIIII")
/*
    const userData = {
        firstName: document.getElementById('first-name').value,
        lastName: document.getElementById('last-name').value,
        birthDate: document.getElementById('birth-nate').value,
        email: document.getElementById('email').value,
        username: document.getElementById('new-username').value,
        password: document.getElementById('new-password').value,
    };*/

    const csrfToken = getCsrfToken();

    try {
        const response = await fetch('/api/register/', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'X-CSRFToken': csrfToken
            },
            body: JSON.stringify(userData),
            credentials: 'include'
        });
    
        if (!response.ok) {
            const errorData = await response.json();
            throw new Error(errorData.error || 'Failed to register');
        }

        const data = await response.json();

        window.AppData.user = data;
        console.log(window.AppData.user);
        //userpage(data.user);  // Chiama una funzione che gestisce la navigazione dell'utente loggato
    } catch (error) {
        alert('Registration failed: ' + error.message);  // Avvisa l'utente del fallimento del login
    }
}

