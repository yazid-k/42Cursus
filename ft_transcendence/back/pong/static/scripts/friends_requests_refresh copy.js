// fonction pour recuperer les cookies avec le csrf_token
function getCookie(name) {

	let cookieValue = null;
	if (document.cookie && document.cookie !== '') {
		const cookies = document.cookie.split(';');
		for (let i = 0; i < cookies.length; i++) {
			const cookie = cookies[i].trim();
			if (cookie.substring(0, name.length + 1) === (name + '=')) {
				cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
				break;
			}
		}
	}
	return cookieValue;
}
const csrf_token = getCookie('csrftoken');

// Script principal de gestion des demandes d'amis
function runsocketFriends() {

	let url = `wss://${window.location.host}/ws/friends_requests/`
	var socket = new WebSocket(url);

	socket.onopen = function(e) {
	console.log("Friend_Request socket is open");
	};

	socket.onmessage = function(e) {
	var data = JSON.parse(e.data);
	console.log("data reçu par le JS pour la friend update:", data);
	if (data.type === 'friends_requests_update') {

		var userElement = document.getElementById('userRemove-' + data.friend_id);
		userElement.parentNode.removeChild(userElement);
		var friendElement = document.createElement('li');
		friendElement.innerHTML = `
			<div class="d-flex justify-content-between align-items-center col-10 bg-white bg-opacity-25 mb-2 rounded shadow-sm mx-auto p-3">
				<div class="d-flex align-items-center">
					<img id="status-indicator-${data.friend_id}" class="rounded-circle me-2 
					{% if ${data.friend_status} == 'is_online' %}border border-2 border-success
                    {% elif ${data.friend_status} == 'is_playing' %}border border-2 border-danger
                    {% elif ${data.friend_status} == 'is_offline' %}
					{% endif %}" src="${data.friend_avatar}" alt="Friend avatar" style="width: 35px; height: 35px;">
					<div style="max-width: 7ch; overflow: hidden; text-overflow: ellipsis; white-space: nowrap;">
						${data.friend_username} ${data.friend_id}
					</div>
				</div>
				<button class="btn buttonfriends btn-sm btn-dark shadow-sm" data-translate="profile" style="--bs-btn-font-size: .75rem;"
					id="profile-${data.friend_id}"
					type="button" data-bs-toggle="popover"
					title="${data.friend_username} profile"
					data-bs-custom-class="custom-popover"
					data-bs-html="true"
					data-bs-content="
					<i class='bi bi-trophy-fill'></i> Won (${data.friend_stats.tourn}) tournament(s)
					<br><i class='bi bi-joystick'></i> Played (${data.friend_stats.total}) matches:
					<br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>won (${data.friend_stats.won})
					<br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>lost (${data.friend_stats.lost})
					<br><i class='bi bi-calendar-check-fill'></i> Joined on ${data.friend_joined}
					">
					profile
				</button>
			</div>
			`;
		document.getElementById('friendsList').appendChild(friendElement);
		applyTranslation

		// Initialisez les popovers
		var popoverTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="popover"]'))
		var popoverList = popoverTriggerList.map(function (popoverTriggerEl) {
			return new bootstrap.Popover(popoverTriggerEl)
})
	}
	else if (data.type == 'new_friend_request') {

		// Suppression de l'ancien élément de demande d'ami s'il existe
		var addFriendButton = document.getElementById('addFriendButton-' + data.friend_id);
		if (addFriendButton) {
			addFriendButton.remove();
		}
		// Suppression de l'ancien élément de demande d'ami s'il existe
		var oldRequestElement = document.getElementById('userRemove-' + data.friend_id);
		if (oldRequestElement) {
			oldRequestElement.remove();
		}
		// Creation du nouvel élément de demande d'ami avec accept ou reject
		var newRequestElement = document.createElement('li');
		newRequestElement.innerHTML = `
		<div id="userRemove-${data.friend_id}" class="d-flex justify-content-between align-items-center col-10 bg-white bg-opacity-25 p-3 mb-2 rounded shadow-sm mx-auto">
			<div class="d-flex align-items-center">
                <img class="rounded-circle me-2" src="${data.friend_avatar}" alt="" style="width: 35px; height: 35px;">
                <div style="max-width: 7ch; overflow: hidden; text-overflow: ellipsis; white-space: nowrap;">
                ${data.friend_username}
                </div>
			</div>
			<form action="handle_invite" method="POST">
				<input type="hidden" name="csrfmiddlewaretoken" value="${csrf_token}">
                <input type="hidden" name="invite" value="${data.friend_username}">
                <button type="submit" name="friend_status" value="accepted" class="btn buttonvalid px-2 btn-sm btn-primary shadow-sm"
                style="--bs-btn-font-size: .75rem;"><i class="bi bi-check-square"></i></button>
                <button type="submit" name="friend_status" value="rejected" class="px-2 buttonvalid btn btn-sm btn-danger shadow-sm"
                style="--bs-btn-font-size: .75rem;"><i class="bi bi-x-square"></i></button>
			</form>
		</div>
		`;
		document.getElementById('usersList').appendChild(newRequestElement);
	}
	};

	socket.onclose = function(e) {
	console.log("Connection WS REFRESH FRIENDS closed");
	};
}

document.addEventListener('DOMContentLoaded', (event) => {
	runsocketFriends();
});