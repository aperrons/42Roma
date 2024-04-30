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

    toggle.onclick = () => menu.classList.toggle('active');

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
    profilePic.src = 'data:image/jpeg;base64,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';
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

    console.log('friends:', user.friends);
    console.log('length:', user.friends.length);

    friendsCount.textContent = `${user.friends.length}`;
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

    container.innerHTML = ''; // Cambia il contenuto dinamicamente

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
            // Esegui il file JavaScript per la Settings Page
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
