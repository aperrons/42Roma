import { getCsrfToken } from '/utils.js'

export function executeLogout() {
    const csrfToken = getCsrfToken();

    // Logging for debugging purposes; consider removing in production
    console.log('CSRF Token:', csrfToken);

    if (!csrfToken) {
        console.error('CSRF token not found. Please make sure you are logged in.');
        return;
    }

    fetch('/api/logout/', {
        method: 'POST',
        headers: {
            'X-CSRFToken': csrfToken
        },
        credentials: 'include' // Ensure cookies are included with the request
    })
    .then(response => {
        if (response.ok) {
            console.log("Logout successful");
            window.location.href = '/login';
        } else {
            console.error("Logout failed", response.status);
        }
    })
    .catch(error => console.error('Error during logout:', error));
}
