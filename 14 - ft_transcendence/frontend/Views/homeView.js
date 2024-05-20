import { header, footer } from "../elements.js";
import { getCsrfToken } from "../utils.js";

export function loadHomePage(container) {

    let csrfToken;

    window.onload = function() {
        if (!getCsrfToken()) {
            fetch('/api/csrf/', { credentials: 'include' })  // Assicurati che le credenziali includano i cookie
            .then(response => response.json())
            .then(data => {
                csrfToken = data.csrfToken;  // Salva il token CSRF
            });
        }
    }
    console.log("Home");
    document.getElementById('header').innerHTML = header;
    document.getElementById('content').innerHTML = '<h1>Home Page</h1>';
    document.getElementById('footer').innerHTML = footer;

}
    
