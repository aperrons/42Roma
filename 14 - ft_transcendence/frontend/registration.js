import { isValidEmail, isValidName, isAdult, isValidPassword } from './utils.js';
import { userpage } from './userpage.js';
import { getCsrfToken } from './utils.js';

document.getElementById('firstName').addEventListener('focusout', validateName);
document.getElementById('lastName').addEventListener('focusout', validateName);
document.getElementById('birthDate').addEventListener('focusout', validateAge);
document.getElementById('email').addEventListener('focusout', validateEmail);
document.getElementById('newUsername').addEventListener('focusout', validateName);
document.getElementById('newPassword').addEventListener('input', validatePassword);
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
    const inputs = document.querySelectorAll('#firstName, #lastName, #birthDate, #email, #newUsername, #newPassword');
    const allValid = Array.from(inputs).every(input => {
        return input.value.trim() !== "" && !input.classList.contains('invalid');
    });

    const registerSubmitButton = document.getElementById('registerSubmitButton');
    registerSubmitButton.disabled = !allValid;

    console.log('Register button enabled:', !registerSubmitButton.disabled);
}


function register(event) {
    event.preventDefault();
    if (document.getElementById('registerSubmitButton').disabled) {
        
        alert('Correggi gli errori nel form prima di registrarti.');
        return;
    }

    const userData = {
        firstName: document.getElementById('firstName').value,
        lastName: document.getElementById('lastName').value,
        birthDate: document.getElementById('birthDate').value,
        email: document.getElementById('email').value,
        username: document.getElementById('newUsername').value,
        password: document.getElementById('newPassword').value,
    };

    const csrfToken = getCsrfToken();

    fetch('/api/register/', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'X-CSRFToken': csrfToken
        },
        body: JSON.stringify(userData),
        credentials: 'include'
    })
    .then(response => response.json())
    .then(data => {
        if (data.user) {
            console.log('Success:', data);
            userpage(data.user);
        } else {
            console.error('Error:', data.error);
        }
    })
    .catch((error) => {
        console.error('Network error', error);
    });
}
