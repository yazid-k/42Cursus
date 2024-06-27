// Script principal de gestion des demandes d'amis
function runsocketFriends() {

	let url = `wss://${window.location.host}/ws/friends_requests/`
	var socketFriends = new WebSocket(url);

	function handleClick(event) {
		var element = event.target;
		while (element && !element.matches('.button_friends')) {
			element = element.parentElement;
		}
		if (element) {
			var data= {
				sender_id: element.getAttribute('data-sender'),
				receiver_id: element.getAttribute('data-receiver'),
				type: element.getAttribute('data-type')
			}
			socketFriends.send(JSON.stringify({
				'data': data,
			}));
		}
	}

	socketFriends.onopen = function(e) {
	console.log("Friend_Request socket is open");
	};

	socketFriends.onmessage = function(e) {
	var data = JSON.parse(e.data);

	console.log("data reçue par le JS pour la friend update:", data);

	if (data.type === 'accepted') {
		var divRecUser = document.getElementById('userDiv-' + data.receiver_id);
		if (divRecUser) {
			divRecUser.remove();
			var friendsList = document.getElementById('friendsList');
			if (friendsList) {
				console.log('rentre dasn friendsli receiver');
				var newFriendElement = document.createElement('li');
				let statusIndicatorClasses = "rounded-circle me-2";
				if (data.rec_status === 'is_online') {
    				statusIndicatorClasses += " border border-2 border-success";
				} else if (data.rec_status === 'is_playing') {
    				statusIndicatorClasses += " border border-2 border-danger";
				}
				newFriendElement.innerHTML = `
				<div class="d-flex justify-content-between align-items-center col-10 bg-white bg-opacity-25 mb-2 rounded shadow-sm mx-auto p-3">
					<div class="d-flex align-items-center">
						<img id="status-indicator-${ data.receiver_id }" class="${ statusIndicatorClasses }" src="${ data.rec_avatar }" alt="Friend avatar" style="width: 35px; height: 35px;">
						<div style="max-width: 7ch; overflow: hidden; text-overflow: ellipsis; white-space: nowrap;">
							${ data.rec_username }
						</div>
					</div>
					<button class="btn buttonfriends btn-sm btn-dark shadow-sm" data-translate="profile" style="--bs-btn-font-size: .75rem;"
						id="profile-${ data.receiver_id }"
						type="button" data-bs-toggle="popover"
						title="${ data.sender_username } profile"
						data-bs-custom-class="custom-popover"
						data-bs-html="true"
						data-bs-content="
						<i class='bi bi-trophy-fill'></i> Won (${data.rec_stats.tourn}) tournament(s)
						<br><i class='bi bi-joystick'></i> Played (${data.rec_stats.total}) matches:
						<br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>won (${data.rec_stats.won})
						<br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>lost (${data.rec_stats.lost})
						<br><i class='bi bi-calendar-check-fill'></i> Joined on ${data.rec_stats.joined}
						">
						profile
					</button>
				</div>
				`;
				friendsList.appendChild(newFriendElement);
			}
		}
		var divSendUser = document.getElementById('userDiv-' + data.sender_id);
		if (divSendUser) {
			divSendUser.remove();
			var friendsList = document.getElementById('friendsList');
			if (friendsList) {
				console.log('rentre dasn friendslis sender');
				var newFriendElement = document.createElement('li');
				let statusIndicatorClasses = "rounded-circle me-2";
				if (data.rec_status === 'is_online') {
    				statusIndicatorClasses += " border border-2 border-success";
				} else if (data.rec_status === 'is_playing') {
    				statusIndicatorClasses += " border border-2 border-danger";
				}
				newFriendElement.innerHTML = `
				<div class="d-flex justify-content-between align-items-center col-10 bg-white bg-opacity-25 mb-2 rounded shadow-sm mx-auto p-3">
					<div class="d-flex align-items-center">
						<img id="status-indicator-${ data.sender_id }" class="${ statusIndicatorClasses }" src="${ data.send_avatar }" alt="Friend avatar" style="width: 35px; height: 35px;">
						<div style="max-width: 7ch; overflow: hidden; text-overflow: ellipsis; white-space: nowrap;">
							${ data.send_username }
						</div>
					</div>
					<button class="btn buttonfriends btn-sm btn-dark shadow-sm" data-translate="profile" style="--bs-btn-font-size: .75rem;"
						id="profile-${ data.sender_id }"
						type="button" data-bs-toggle="popover"
						title="${ data.send_username } profile"
						data-bs-custom-class="custom-popover"
						data-bs-html="true"
						data-bs-content="
						<i class='bi bi-trophy-fill'></i> Won (${data.send_stats.tourn}) tournament(s)
						<br><i class='bi bi-joystick'></i> Played (${data.send_stats.total}) matches:
						<br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>won (${data.send_stats.won})
						<br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>lost (${data.send_stats.lost})
						<br><i class='bi bi-calendar-check-fill'></i> Joined on ${data.send_stats.joined}
						">
						profile
					</button>
				</div>
				`;
				friendsList.appendChild(newFriendElement);
			}
		}
		var popoverTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="popover"]'))
		var popoverList = popoverTriggerList.map(function (popoverTriggerEl) {
			return new bootstrap.Popover(popoverTriggerEl)
		})
	}
	else if (data.type === 'rejected') {
		
		var divParent = document.getElementById('userDiv-' + data.receiver_id);
		if (divParent) {
			var divButton = document.getElementById("f_request_validation-" + data.receiver_id);
			divButton.remove();
			var newDivButton = document.createElement('div');
			newDivButton.innerHTML = `
			<div id="f_request_add-${ data.receiver_id }">
                <button data-type="send_f_request" data-sender="${ data.sender_id }" data-receiver="${ data.receiver_id }" class="btn buttonfriends button_friends btn-sm btn-primary shadow-sm"
                style="--bs-btn-font-size: .75rem;" data-translate="add">add friend
                </button>
            </div>
			`;
			divParent.appendChild(newDivButton);
		}

		var divParent = document.getElementById('userDiv-' + data.sender_id);
		if (divParent) {
			var divButton = document.getElementById("f_request_pending-" + data.sender_id);
			divButton.remove();
			var newDivButton = document.createElement('div');
			newDivButton.innerHTML = `
			<div id="f_request_add-${ data.sender_id }">
                <button data-type="send_f_request" data-sender="${ data.receiver_id }" data-receiver="${ data.sender_id }" class="btn buttonfriends button_friends btn-sm btn-primary shadow-sm"
                style="--bs-btn-font-size: .75rem;" data-translate="add">add friend
                </button>
            </div>
			`;
			divParent.appendChild(newDivButton);
		}
		
	}

	else if (data.type == 'send_f_request') {

		var divParent = document.getElementById('userDiv-' + data.sender_id);
		if (divParent) {
			var divButton = document.getElementById("f_request_add-" + data.sender_id);
			divButton.remove();
			var newDivButton = document.createElement('div');
			newDivButton.innerHTML = `
			<div id="f_request_validation-${ data.sender_id }" class="d-flex flex-row align-items-center">
				<div class="button_friends me-1" data-type="accepted" data-sender="${ data.receiver_id }" data-receiver="${ data.sender_id }" >
					<button class="btn buttonvalid px-2 btn-sm btn-primary shadow-sm"
					style="--bs-btn-font-size: .75rem;"><i class="bi bi-check-square"></i></button>
				</div>
				<div class="button_friends" data-type="rejected" data-sender="${ data.receiver_id }" data-receiver="${ data.sender_id }" >
					<button class="px-2 buttonvalid btn btn-sm btn-danger shadow-sm"
					style="--bs-btn-font-size: .75rem;"><i class="bi bi-x-square"></i></button>
				</div>
			</div>
			`;
			divParent.appendChild(newDivButton);

		}

		var divParent = document.getElementById('userDiv-' + data.receiver_id);
		if (divParent) {
			var divButton = document.getElementById("f_request_add-" + data.receiver_id);
			divButton.remove();
			var newDivButton = document.createElement('div');
			newDivButton.innerHTML = `
			<button id="f_request_pending-${ data.receiver_id }" class="btn buttonfriends btn-sm btn-primary shadow-sm" disabled
            style="--bs-btn-font-size: .75rem;" data-translate="pending">pending
			</button>
			`;
			divParent.appendChild(newDivButton);
		}
	}

		var activeLanguage = document.querySelector('.chooseLanguage.active');
		applyTranslation(activeLanguage.textContent.trim().toLowerCase());

	};

	socketFriends.onclose = function(e) {
		console.log("Friend_Request socket is close", e.code, e.reason);
	};
	document.body.addEventListener('click', handleClick);
}

runsocketFriends();