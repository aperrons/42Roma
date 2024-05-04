import { getCsrfToken } from '/utils.js'
import { refreshAccessToken } from './utils.js';
import { userpage } from './userpage.js';

export function loadSettingsPage(container) {
    console.log("Settings Page");

    const existingCard = document.getElementById('settingsCard');
    if (existingCard) {
        // Se la card esiste e è visibile, la nascondiamo
        if (existingCard.style.display !== 'none') {
            existingCard.style.display = 'none';
        } else {
            // Se la card esiste ma è nascosta, la rimuoviamo e ne creiamo una nuova
            container.removeChild(existingCard);
            const newCard = createCard(window.AppData.user.user);
            container.appendChild(newCard);
            newCard.style.display = 'flex';  // Assicurati che la nuova card sia visibile
        }
    } else {
        // Se non esiste alcuna card, ne creiamo una nuova
        const newCard = createCard(window.AppData.user.user);
        container.appendChild(newCard);
        newCard.style.display = 'flex';  // Assicurati che la nuova card sia visibile
    }
}

function createCard(user) {
    const card = document.createElement('div');
    card.className = 'settingsCard';
    card.id = 'settingsCard';

    const content = document.createElement('div');
    content.className = 'settingsContent';

    const details = document.createElement('div');
    details.className = 'settingsDetails';

    const actionButton = document.createElement('div');
    actionButton.className = 'actionSettingsButton';

    // Crea il bottone per cambiare il nickname
    const changeUsernameButton = document.createElement('button');
    changeUsernameButton.textContent = 'Change Nickname!';
    changeUsernameButton.className = 'full-width-button';

    // Crea il campo di input e il bottone di conferma, inizialmente nascosti
    const usernameInput = document.createElement('input');
    usernameInput.id = 'inputNN';
    usernameInput.type = 'text';
    usernameInput.placeholder = 'New Nickname';
    usernameInput.style.display = 'none'; // Nascondi inizialmente

    const confirmButton = document.createElement('button');
    confirmButton.textContent = 'Confirm';
    confirmButton.className = 'full-width-button';
    confirmButton.id = "confirmButton";
    confirmButton.style.display = 'none'; // Nascondi inizialmente

    const errorMessage = document.createElement('div');
    errorMessage.id = ('errMess');
    errorMessage.textContent = 'Name not available';
    errorMessage.style.color = 'red';
    errorMessage.style.display = 'none'; // Nascondi inizialmente

    // Gestisce il click del bottone di cambio nickname
    changeUsernameButton.onclick = function() {
        usernameInput.style.display = 'block';
        confirmButton.style.display = 'block';
        errorMessage.style.display = 'none'; // Nascondi il messaggio di errore quando si tenta di nuovo

        card.style.height = "auto";
    };

    // Gestisce il click del bottone di conferma
    confirmButton.onclick = async function() {
        const newUsername = usernameInput.value.trim();
        if (!newUsername) {
            errorMessage.textContent = 'Username cannot be empty';
            errorMessage.style.display = 'block';
            return;
        }
    
        const csrfToken = getCsrfToken();
        const jwtToken = window.AppData.user.access;
    
        try {
            const response = await fetch('/api/login/changeusername', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${jwtToken}`,
                    'X-CSRFToken': csrfToken
                },
                body: JSON.stringify({ username: newUsername }),
                credentials: 'include'
            });
    
            if (response.ok) {
                const data = await response.json();
                window.AppData.user.user.username = data.new_username;
                // Nascondi e rimuovi la settingsCard
                //removeAndResetSettingsCard();
                const card = document.getElementById('settingsCard');
                if (card) {
                    card.parentNode.removeChild(card);
                }
                userpage(window.AppData.user.user);
            } else if (response.status === 409) {
                const errorData = await response.json();
                usernameInput.placeholder = 'This username is already taken';
                usernameInput.value = '';
                errorMessage.textContent = errorData.error || "Username is already taken";
                errorMessage.style.display = 'block';
            } else if (response.status === 401) {
                // Prova a rinnovare il token
                const newAccessToken = await refreshAccessToken(window.AppData.user.refresh);
                if (newAccessToken) {
                    window.AppData.user.access = newAccessToken;
                    return confirmButton.onclick();  // Riprova la richiesta originale
                } else {
                    alert('Session expired. Please log in again.');
                }
            } else {
                const errorData = await response.json();
                console.error('Failed to change username:', errorData);
                throw new Error(errorData.error);
            }
        } catch (error) {
            console.error('Error during the fetch operation:', error);
            throw error;
        }
    };

    actionButton.appendChild(changeUsernameButton);
    actionButton.appendChild(usernameInput);
    actionButton.appendChild(confirmButton);
    actionButton.appendChild(errorMessage);

    const changeProfileImageButton = document.createElement('button');
    changeProfileImageButton.textContent = 'Change Profile Image';
    changeProfileImageButton.className = 'full-width-button';
    //changeProfileImageButton.onclick = () => changeContent('Organize Tournament');

    actionButton.appendChild(changeProfileImageButton);
    details.appendChild(actionButton); 
    content.appendChild(details);
    card.appendChild(content);

    return card;
}

function removeAndResetSettingsCard() {
    const card = document.getElementById('settingsCard');
    if (card) {
        card.parentNode.removeChild(card);
    }
    const container = document.getElementById('main-content');
    const newCard = createCard(window.AppData.user.user);
    container.appendChild(newCard);
    newCard.style.display = 'flex';
}