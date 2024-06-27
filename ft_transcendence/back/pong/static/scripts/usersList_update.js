function runsocketUsersUpdate() {

    let url = `wss://${window.location.host}/ws/userslist_update/`
    const usersUpdateSock = new WebSocket(url);

    usersUpdateSock.onopen = function (event) {
        console.log('UsersListUpdate socket is open');
    };

    usersUpdateSock.onmessage = function (event) {

        let data = JSON.parse(event.data)
        console.log('On recoit le message dans userslist : ', data)
        let usersList = document.getElementById('usersList');
        if (usersList) {
            console.log('On entre dans le userslist ', data)
            let existingUser = document.getElementById(`userDiv-${data.new_user_id}`);
            if (!existingUser) {
                console.log('On cree le nouvea user')
                let newUser = document.createElement('div');
                newUser.innerHTML = `
                <div id="userDiv-${data.new_user_id}" class="d-flex justify-content-between align-items-center col-10 bg-white bg-opacity-25 p-3 mb-2 rounded shadow-sm mx-auto">
                    <div class="d-flex align-items-center">
                        <img class="rounded-circle me-2" src="${data.avatar}" alt="" style="width: 35px; height: 35px;">
                        <div style="max-width: 7ch; overflow: hidden; text-overflow: ellipsis; white-space: nowrap;">
                        ${data.username}
                        </div>
                    </div>
                    <div id="f_request_add-${data.new_user_id}">
                        <button data-type="send_f_request" data-sender="${data.sender_id}" data-receiver="${data.receiver_id}" class="btn buttonfriends button_friends btn-sm btn-primary shadow-sm"
                        style="--bs-btn-font-size: .75rem;" data-translate="add">add friend
                        </button>
                    </div>
                </div>
                `;
                console.log('On a créé le nouvel user')
                usersList.appendChild(newUser);

            }
        }

        var activeLanguage = document.querySelector('.chooseLanguage.active');
		applyTranslation(activeLanguage.textContent.trim().toLowerCase());
        
    }

    usersUpdateSock.onclose = function (event) {
        console.log('UsersUpdate socket is closed');
    };
}

document.addEventListener('DOMContentLoaded', (event) => {
    runsocketUsersUpdate();
});