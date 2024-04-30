export function loadAddFriendPage(container) {
    
    const friendForm =  document.getElementById('addFriendForm');
    //const form = document.getElementById('');



    friendForm.addEventListener('submit', function(event) {
        event.preventDefault();
        console.log('Form clickke');

        friendForm.style.display = 'none';
    });
}