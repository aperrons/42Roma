export function isValidEmail(email) {
    const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return re.test(email.toLowerCase());
}

export function isValidName(name) {
    const re = /^[a-zA-Z0-9]+$/;
    return re.test(name);
}

export function isAdult(birthDate) {
    const currentDate = new Date();
    const eighteenthBirthday = new Date(birthDate);
    eighteenthBirthday.setFullYear(eighteenthBirthday.getFullYear() + 18);

    return currentDate >= eighteenthBirthday;
}

export function isValidPassword(password) {
    const re = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[a-zA-Z\d]{6,}$/;
    return re.test(password);
}

export function getCsrfToken() {

    return document.cookie.split('; ')
        .find(row => row.startsWith('csrftoken='))
        ?.split('=')[1]; 
}

export async function refreshAccessToken(refreshToken) {
    try {
        const response = await fetch('/api/token/refreshtoken', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ refresh: 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ0b2tlbl90eXBlIjoicmVmcmVzaCIsImV4cCI6MTcxNDgwOTU3MCwiaWF0IjoxNzE0NzIzMTcwLCJqdGkiOiJhOWY3ZWFiMDRlMGI0NWNiODM1NmMzZWJmNDBjMWVhMyIsInVzZXJfaWQiOjF9.mzGI6pQbjSudgbbUDw1oxGwlnHYQLRX8jpAKyD3be6U' })
        });

        const data = await response.json();
        if (response.ok) {
            console.log('Token refreshed successfully');
            window.AppData.user.refresh = data.refresh;
            return data.access;  // Ritorna il nuovo access token
        } else {
            console.error('Failed to refresh token:', data);
            throw new Error(data.detail || 'Unknown error');
        }
    } catch (error) {
        console.error('Error refreshing access token:', error);
    }
}