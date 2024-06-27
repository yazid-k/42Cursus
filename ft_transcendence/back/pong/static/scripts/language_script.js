// script pour les traductions

var translations = {
    "english": {
        "welcome": "Welcome",
        "edit": "Edit profile",
        "update": "Update profile",
        "username": "Username",
        "picture": "Profile picture",
        "save": "Save",
        "close": "Close",
        "language": "Language",
        "author": "Authors",
        "game": "Game",
        "play": "Play a:",
        "match": "Match",
        "tournament": "Tournament",
        "won": "Win(s)",
        "lost": "Defeat(s)",
        "tourn": "Tournament(s) won",
        "1v1": "Play a 1v1 match:",
        "online": "Online",
        "users": "Users",
        "profile": "profile",
        "pending": "pending",
        "add": "add friend",
        "playpong": "Pong",
        "account": "No account yet?",
        "signin": "Sign in",
        "here": "Sign up here",
        "or": "or",
        "42login": "Log in with",
        "signup": "Sign up",
        "email": "Email adress",
        "password": "Password",
        "submit": "Submit",
        "logout": "Log out",
        "localmatch": "Local match",
        "opponent": "Choose an alias for your opponent",
        "start": "Start",
        "onlinematch": "Online match",
        "localtourn": "Local tournament",
        "onlinetourn": "Online tournament",
    },
    "français": {
        "welcome": "Bienvenue",
        "edit": "Modifier profil",
        "update": "Mise à jour du profil",
        "username": "Nom d'utilisateur",
        "picture": "Photo de profil",
        "save": "Enregistrer",
        "close": "Fermer",
        "language": "Langue",
        "author": "Auteurs",
        "game": "Jeu",
        "play": "Démarrer un :",
        "match": "Match",
        "tournament": "Tournoi",
        "won": "Victoire(s)",
        "lost": "Défaite(s)",
        "tourn": "Tournoi(s) gagné(s)",
        "1v1": "Jouer un match 1v1 :",
        "online": "En ligne",
        "users": "Utilisateurs",
        "profile": "profil",
        "pending": "attente",
        "add": "ajouter",
        "playpong": "Pong",
        "account": "Pas de compte?",
        "signin": "Se connecter",
        "here": "Inscris-toi ici.",
        "or": "ou",
        "42login": "Se connecter avec",
        "signup": "S'enregistrer",
        "email": "Adresse email",
        "password": "Mot de passe",
        "submit": "Confirmer",
        "logout": "Se déconnecter",
        "localmatch": "Partie en local",
        "opponent": "Choisis un alias pour ton adversaire",
        "start": "Démarrer",
        "onlinematch": "Partie en ligne",
        "localtourn": "Tournoi en local",
        "onlinetourn": "Tournoi en ligne",
    },
    "español": {
        "welcome": "Bienvenido",
        "edit": "Editar perfil",
        "update": "Actualización del perfil",
        "username": "Nombre de usuario",
        "picture": "Foto de perfil",
        "save": "Guardar",
        "close": "Cerrar",
        "language": "Idioma",
        "author": "Autores",
        "game": "Juego",
        "play": "Iniciar un :",
        "match": "Partido",
        "tournament": "Torneo",
        "won": "Triumfo(s)",
        "lost": "Derrota(s)",
        "tourn": "Torneo(s) ganado(s)",
        "1v1": "Jugar un partido 1v1 :",
        "online": "En línea",
        "users": "Usuarios",
        "profile": "perfil",
        "pending": "pendiente",
        "add": "añadir",
        "playpong": "Pong",
        "account": "No cuenta?",
        "signin": "Iniciar sesión",
        "here": "Registrate acqui.",
        "or": "o",
        "42login": "Iniciar sesión con",
        "signup": "Registrarse",
        "email": "Correo electrónico",
        "password": "Contraseña",
        "submit": "Confirmar",
        "logout": "Cerrar sesión",
        "localmatch": "Partido en local",
        "opponent": "Elige un alias para tu oponente",
        "start": "Iniciar",
        "onlinematch": "Partido en línea",
        "localtourn": "Torneo en local",
        "onlinetourn": "Torneo en línea",
    }
};


function applyTranslation(language) {

    if (!language) {
        var activeLanguage = document.querySelector('.chooseLanguage.active');
        var language = this.textContent.trim().toLowerCase();
    }

    var elements = document.querySelectorAll('[data-translate]');
    elements.forEach(function(element) {
        var translation = translations[language][element.getAttribute('data-translate')];
        if (translation) {
            if (element.textContent)
                element.textContent = translation;
            else if (element.placeholder) {
                element.placeholder = translation;
            }
            else if (element.title) {
                element.title = translation;
            }
        }
        console.log("traduction applied");
    });
    var activeLanguage = document.querySelector('.chooseLanguage.active');
    if (activeLanguage) {
        activeLanguage.classList.remove('active');
    }
    var newLanguage = document.getElementById(language);
    if (newLanguage) {
        newLanguage.classList.add('active');
    }
}
function runSocketLanguage() {
    let url = `wss://${window.location.host}/ws/language/`
    const languageSock = new WebSocket(url);
    

    var buttons = document.querySelectorAll('.chooseLanguage');
    buttons.forEach(function(button) {
    button.addEventListener('click', function() {
        var language = this.textContent.trim().toLowerCase();
        applyTranslation(language);
        var message = {
            action: 'set_language',
            language: language
        };
        languageSock.send(JSON.stringify(message));
        });
    });

    languageSock.onopen = function() {
        var message = {
            action: 'get_language'
        };
        languageSock.send(JSON.stringify(message));
    };

    languageSock.onmessage = function(event) {
        var message = JSON.parse(event.data);
        if (message.action === 'get_language') {
            var language = message.language;
            applyTranslation(language);
        }
    };

}
runSocketLanguage();

// function getPopoverContentContent(language, data) {
//     console.log("rentre dans la fonction avec : ", language);

//     let newContent
//     if (language === 'english') {
//         console.log("rentrer ici anglais : ");
//         newContent = `
//         <button class="btn buttonfriends btn-sm btn-dark shadow-sm" style="--bs-btn-font-size: .75rem;"
//             id="profile-${data.friend_id}"
//             type="button" data-bs-toggle="popover"
//             title="${data.friend_username} profile"
//             data-bs-custom-class="custom-popover"
//             data-bs-html="true"
//             data-bs-content="
//             <i class='bi bi-trophy-fill'></i> Won (${data.friend_stats.tourn}) tournament(s)
//             <br><i class='bi bi-joystick'></i> Played (${data.friend_stats.total}) matches:
//             <br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>won (${data.friend_stats.won})
//             <br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>lost (${data.friend_stats.lost})
//             <br><i class='bi bi-calendar-check-fill'></i> Joined on ${data.friend_joined}
//             ">
//             profile
// 		</button>
        
//         `;
//     }
//     else if (language === 'français') {
//         console.log("rentrer ici francais : ");
//         newContent = `
//         <button class="btn buttonfriends btn-sm btn-dark shadow-sm" style="--bs-btn-font-size: .75rem;"
//             id="profile-${data.friend_id}"
//             type="button" data-bs-toggle="popover"
//             title="Profil de ${data.friend_username}"
//             data-bs-custom-class="custom-popover"
//             data-bs-html="true"
//             data-bs-content="
//             <i class='bi bi-trophy-fill'></i> (${data.friend_stats.tourn}) Tournament(s) gagné(s)
//             <br><i class='bi bi-joystick'></i> (${data.friend_stats.total}) Match(s) joué(s):
//             <br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>victoires (${data.friend_stats.won})
//             <br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>défaites (${data.friend_stats.lost})
//             <br><i class='bi bi-calendar-check-fill'></i> Inscrit depuis ${data.friend_joined}
//             profil
//         </button>
//         `;
//         console.log("contenu apres : ", newContent);
//     }
//     else if (language === 'español') {
//         console.log("rentrer ici espagnol : ");
//         newContent = `
//         <button class="btn buttonfriends btn-sm btn-dark shadow-sm" style="--bs-btn-font-size: .75rem;"
//             id="profile-${data.friend_id}"
//             type="button" data-bs-toggle="popover"
//             title="Perfil de ${data.friend_username}"
//             data-bs-custom-class="custom-popover"
//             data-bs-html="true"
//             data-bs-content="
//             <i class='bi bi-trophy-fill'></i> (${data.friend_stats.tourn}) Torneo(s) ganado(s)
//             <br><i class='bi bi-joystick'></i> (${data.friend_stats.total}) Partido(s) jugado(s):
//             <br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>triumfo(s) (${data.friend_stats.won})
//             <br>&nbsp;&nbsp;&nbsp;&nbsp;<i class='bi bi-caret-right-fill'></i>derrota(s) (${data.friend_stats.lost})
//             <br><i class='bi bi-calendar-check-fill'></i> Regigistrado desde ${data.friend_joined}
//             perfil
//         </button>
//         `;
//         console.log("contenu apres : ", newContent);
//     }
//     return newContent;
// }


// function translatePopover(data) {

//     var activeLanguage = document.querySelector('.chooseLanguage.active');

//     console.log("traduction de la popover en", activeLanguage.textContent.trim().toLowerCase());
//     var translatedContent = getPopoverContent(activeLanguage.textContent.trim().toLowerCase(), data);

//     console.log("contenu traduit : ", translatedContent);

//     return translatedContent
// }