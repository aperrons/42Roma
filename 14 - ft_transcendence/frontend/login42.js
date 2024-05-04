import { userpage } from './userpage.js';
import { getCsrfToken } from '/utils.js'

document.getElementById('loginIn42Button').addEventListener('click', login42);

async function login42(event) {
    
    event.preventDefault();

    const csrfToken = getCsrfToken();

    try {
        const response = await fetch('/api/42oauth_start/', {
            method: 'GET',
            headers: {
                'X-CSRFToken': csrfToken
            },
            credentials: 'include'
        });

        if (!response.ok) {
            throw new Error('Failed to initiate login with 42');
        }

        const data = await response.json();
        console.log(data);
        if (data.url) {
            window.location.href = data.url;
            console.log("HHHHHHEEEEEEEEEEEEEEEEEEEEEEEEEEEEE22222222");
        }

        console.log("HHHHHHEEEEEEEEEEEEEEEEEEEEEEEEEEEEE");
       
       // console.log(window.location.href);
        //window.AppData.user = data;
         
    } catch (error) {
        console.error('Login failed:', error); 
        alert('Login failed: ' + error.message);  
    }
}