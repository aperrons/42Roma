import { header, footer, register_form } from "../elements.js";
import { isValidEmail, isValidName, isAdult, isValidPassword } from '../utils.js';

export function loadRegistrationPage(container) {

    console.log("RegistrAtion");
    document.getElementById('header').innerHTML = header;
    document.getElementById('content').innerHTML = register_form;
    document.getElementById('footer').innerHTML = footer;

    document.getElementById('first-name').addEventListener('focusout', validateName);
    document.getElementById('last-name').addEventListener('focusout', validateName);
    document.getElementById('birth-date').addEventListener('focusout', validateAge);
    document.getElementById('email').addEventListener('focusout', validateEmail);
    document.getElementById('new-username').addEventListener('focusout', validateName);
    document.getElementById('new-password').addEventListener('input', validatePassword);
    //document.getElementById('form').addEventListener('submit', register);

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
        const input = document.getElementById('birth-date');
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
        const input = document.getElementById('new-password');
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

        const registerSubmitButton = document.getElementById('register-submit-button');
        registerSubmitButton.disabled = !allValid;

        console.log('Register button enabled:', !registerSubmitButton.disabled);
    }
}