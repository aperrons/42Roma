function userpage(user) {
    const loginaddFriendForm = document.getElementById('loginForm');
    const registrationForm = document.getElementById('registerForm');

    // Nascondi i form di login e registrazione all'avvio
    if (loginForm && registrationForm) {
        loginForm.style.display = 'none';
        registrationForm.style.display = 'none';
    }

    const container = document.getElementById('userDetails');
    container.innerHTML = '';
    container.style.display = 'flex';
    container.style.flexDirection = 'column';
    container.style.alignItems = 'center';  
    container.style.justifyContent = 'center';

    const addFriendForm = document.createElement('form');
    addFriendForm.setAttribute('id', 'addFriendForm');

    const input = document.createElement('input');
    input.setAttribute('type', 'text');
    input.setAttribute('placeholder', 'Inserisci username');
    input.setAttribute('id', 'friendUsername');
    addFriendForm.appendChild(input);

    const submitButton = document.createElement('button');
    submitButton.textContent = 'Aggiungi Amico';
    submitButton.setAttribute('type', 'submit');
    addFriendForm.appendChild(submitButton);

    //addFriendForm.style.display = 'none';
    container.appendChild(addFriendForm);

    const menu = document.createElement('div');
    menu.className = 'menu';
    container.appendChild(menu);

    const toggle = document.createElement('div');
    toggle.className = 'toggle';
    const toggleIcon = document.createElement('ion-icon');
    toggleIcon.setAttribute('name', 'add-outline');
    toggle.appendChild(toggleIcon);
    menu.appendChild(toggle);

    const menuItems = [
        { icon: 'home-outline', color: '#ff2972', view: 'Home Page' },
        { icon: 'person-add-outline', color: '#fee800', view: 'AddFriend Page' },
        { icon: 'chatbox-outline', color: '#fe00f1', view: 'Chat Page' },
        { icon: 'settings-outline', color: '#04fc43', view: 'Settings Page' }
    ];

    menuItems.forEach((item, index) => {
        const li = document.createElement('li');
        li.style.setProperty('--i', index);
        li.style.setProperty('--clr', item.color);
        const link = document.createElement('a');
        link.href = "#";
        link.onclick = () => changeContent(item.view);  // Utilizza un handler di click per cambiare il contenuto
        const icon = document.createElement('ion-icon');
        icon.setAttribute('name', item.icon);
        link.appendChild(icon);
        li.appendChild(link);
        menu.appendChild(li);
    });

    toggle.onclick = () => {
        menu.classList.toggle('active');
        const settingsCard = document.getElementById('settingsCard');
        if (settingsCard && settingsCard.style.display !== 'none') {
            settingsCard.style.display = 'none';
        }
    }
    const card = createCard(user);
    container.appendChild(card);

    const logout = createLogout();
    container.appendChild(logout);
}

function createCard(user) {
    const card = document.createElement('div');
    card.className = 'card';
    const imgBox = document.createElement('div');
    imgBox.className = 'imgBox';
    const profilePic = document.createElement('img');
    profilePic.src = "main.webp"
    profilePic.alt = 'Profile Picture';
    imgBox.appendChild(profilePic);

    const content = document.createElement('div');
    content.className = 'content';

    const friendsIconContainer = document.createElement('div');
    friendsIconContainer.className = 'friends-icon-container';
    friendsIconContainer.style.cssText = 'position: absolute; top: 15px; right: 15px; display: flex; align-items: center;';
    
    const iconLink = document.createElement('a');
    iconLink.href = "#";

    const friendsIcon = document.createElement('ion-icon');
    friendsIcon.setAttribute('name', 'people');
    friendsIcon.style.cssText = 'margin-right: 2px; font-size: 23px;'; // Spazio tra icona e numero

    const friendsCount = document.createElement('span');

    friendsCount.textContent = '0'; //`${user.friends.length}`;
    friendsCount.className = 'friends-count';
    friendsCount.style.fontSize = '15px';

    friendsIconContainer.appendChild(friendsIcon);
    friendsIconContainer.appendChild(friendsCount);
    card.appendChild(friendsIconContainer);

    friendsIconContainer.onclick = () => {
        console.log("cliccato");
    }

    const details = document.createElement('div');
    details.className = 'details';
    
    const name = document.createElement('h2');
    name.className = 'usern';
    name.textContent = user.username;
    name.style.fontSize = '27px';
    details.appendChild(name);

    // Creazione e posizionamento dei pulsanti actionButton tra il nome e le statistiche
    const actionButton = document.createElement('div');
    actionButton.className = 'actionButton';
    const playBongButton = document.createElement('button');
    playBongButton.textContent = 'Play Bong!';
    playBongButton.onclick = () => changeContent('Play Bong');
    const organizeTournamentButton = document.createElement('button');
    organizeTournamentButton.textContent = 'Organize Tournament';
    organizeTournamentButton.onclick = () => changeContent('Organize Tournament');
    actionButton.appendChild(playBongButton);
    actionButton.appendChild(organizeTournamentButton);
    details.appendChild(actionButton); // Inserisci qui prima delle statistiche

    // Sezione delle statistiche
    const stats = document.createElement('div');
    stats.className = 'stats';
    const gamesPlayed = document.createElement('p');
    gamesPlayed.textContent = `Partite giocate: ${user.gamesPlayed}`;
    const wins = document.createElement('p');
    wins.textContent = `Partite vinte: ${user.wins}`;
    const losses = document.createElement('p');
    losses.textContent = `Partite perse: ${user.losses}`;
    const pair = document.createElement('p');
    pair.textContent = `Pareggi: ${user.pair}`;
    stats.append(gamesPlayed, wins, losses, pair);

    details.appendChild(stats);
    content.appendChild(details);
    card.appendChild(imgBox);
    card.appendChild(content);

    return card;
}

function createLogout() {
    const logout = document.createElement('div');
    logout.className = 'logout';
    const outlink = document.createElement('a');
    outlink.href = "#";
    outlink.onclick = () => changeContent('Logout');  // Esempio di funzione di logout
    const outIcon = document.createElement('ion-icon');
    outIcon.setAttribute('name', 'exit-outline');
    outlink.appendChild(outIcon);
    logout.appendChild(outlink);

    return logout;
}

export function changeContent(view) {
    const container = document.getElementById('main-content');
    const userDetails = document.getElementById('userDetails');

    //userDetails.style.display = 'none';

    //container.innerHTML = ''; // Cambia il contenuto dinamicamente

    switch(view) {
        case 'Home Page':
            // Esegui il file JavaScript per la Home Page
            import('./home.js').then(module => {
                module.loadHomePage(container);
            });
            break;
        case 'AddFriend Page':
            // Esegui il file JavaScript per la Registration Page
            import('./addfriend.js').then(module => {
                module.loadAddFriendPage(container);
            });
            break;
        case 'Chat Page':
            // Esegui il file JavaScript per la Chat Page
            import('./chat.js').then(module => {
                module.loadChatPage(container);
            });
            break;
        case 'Settings Page':
            import('./settings.js').then(module => {
                module.loadSettingsPage(container);
            });
            break;
        case 'Play Bong':
            // Esegui il file JavaScript per la pagina di contatto
            import('./playbong.js').then(module => {
                module.loadPlayBongPage(container);
            });
            break;
        case 'Organize Tournament':
            // Esegui il file JavaScript per la pagina "Seguici"
            import('./organizetournament.js').then(module => {
                module.loadOrganizeTournamentPage(container);
            });
            break;
        case 'Logout':
            // Esegui il file JavaScript per eseguire il logout
            import('./logout.js').then(module => {
                module.executeLogout();
            });
            break;
        default:
            // Visualizza un messaggio di default o una pagina di errore
            container.innerHTML = `<h1>Questa vista (${view}) non è disponibile.</h1>`;
    }
}
/*
function createFriendsListCard(friends) {
    const card = document.createElement('div');
    card.className = 'friends-list-card';
    card.style.cssText = 'position: absolute; display: none; width: 200px; background-color: white; box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2); padding: 10px; z-index: 100;';

    friends.forEach(friend => {
        const friendItem = document.createElement('div');
        friendItem.textContent = friend.name; // Assumendo che ogni amico abbia una proprietà 'name'
        card.appendChild(friendItem);
    });

    return card;
}*/

export { userpage };
