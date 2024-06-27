// Script pour gerer l'update du profil

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

// Update profile script
document.getElementById('updateProfileForm').addEventListener('submit', function(event) {
    event.preventDefault();

    var formData = new FormData(this);

    fetch('/update_profile', {
        method: 'POST',
        body: formData,
        headers: {
            'X-CSRFToken': getCookie('csrftoken')
        }
    })
    .then(response => {
        return response.json();
    })
    .then(data => {
        try {
            $('#profileModal').modal('hide');
            if (data.status === 'success') {
                if (formData.get('username')) {
                    document.getElementById('usernameDisplay').textContent = formData.get('username') + '!';
                }
            }
            if (data.avatar_url) {
                document.getElementById('avatarDisplay').src = `${data.avatar_url}?t=${Date.now()}`;
            }
        } catch (error) {
            console.error('Error while trying to hide modal:', error);
        }
    })
    .catch(error => {
        console.error('Error:', error);
    });
});