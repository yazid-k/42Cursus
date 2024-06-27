var initialContent = document.getElementById('playDiv').innerHTML;
function attachEvent() {
    
    document.getElementById('playSingle').addEventListener('click', function() {
        
        var activeLanguage = document.querySelector('.chooseLanguage.active');
        
        if (activeLanguage.textContent.trim().toLowerCase() === 'english') {
            document.getElementById('playDiv').innerHTML = `
            <div class="mb-2 text-center">
                <p class="mb-2"><span id="backArrow" style="cursor: pointer;">
                    <i class="bi bi-arrow-left text-light me-1"></i>
                </span>Play 1v1 match:</p>
                <button class="btn btn-dark btn-sm shadow-sm text-light col-6 mb-2" data-bs-toggle="modal" data-bs-target="#localMatchModal">Local
                </button>
                <button class="btn btn-primary btn-sm shadow-sm text-light col-6" data-bs-toggle="modal" data-bs-target="#onlineMatchModal">Online
                </button>
            </div>
            `;
        }
        else if (activeLanguage.textContent.trim().toLowerCase() === 'français') {
            document.getElementById('playDiv').innerHTML = `
            <div class="mb-2 text-center">
                <p class="mb-2"><span id="backArrow" style="cursor: pointer;">
                    <i class="bi bi-arrow-left text-light me-1"></i>
                </span>Lancer un match 1v1 :</p>
                <button class="btn btn-dark btn-sm shadow-sm text-light col-6 mb-2" data-bs-toggle="modal" data-bs-target="#localMatchModal">Local
                </button>
                <button class="btn btn-primary btn-sm shadow-sm text-light col-6" data-bs-toggle="modal" data-bs-target="#onlineMatchModal">En ligne
                </button>
            </div>
            `;
        }
        else if (activeLanguage.textContent.trim().toLowerCase() === 'español') {
            document.getElementById('playDiv').innerHTML = `
            <div class="mb-2 text-center">
                <p class="mb-2"><span id="backArrow" style="cursor: pointer;">
                    <i class="bi bi-arrow-left text-light me-1"></i>
                </span>Iniciar un partido 1v1 :</p>
                <button class="btn btn-dark btn-sm shadow-sm text-light col-6 mb-2" data-bs-toggle="modal" data-bs-target="#localMatchModal">Local
                </button>
                <button class="btn btn-primary btn-sm shadow-sm text-light col-6" data-bs-toggle="modal" data-bs-target="#onlineMatchModal">En línea
                </button>
            </div>
            `;
        }
        document.getElementById('backArrow').addEventListener('click', function() {
            document.getElementById('playDiv').innerHTML = initialContent;
            applyTranslation(activeLanguage.textContent.trim().toLowerCase());
            attachEvent();	
        });
    });
    document.getElementById('playTournament').addEventListener('click', function() {

        var activeLanguage = document.querySelector('.chooseLanguage.active');

        if (activeLanguage.textContent.trim().toLowerCase() === 'english') {
            document.getElementById('playDiv').innerHTML = `
            <div class="mb-2 text-center">
                <p class="mb-2"><span id="backArrow" style="cursor: pointer;">
                    <i class="bi bi-arrow-left text-light me-1"></i>
                </span>Play a tournament:</p>
                <button class="btn btn-dark btn-sm shadow-sm text-light col-6 mb-2" data-bs-toggle="modal" data-bs-target="#localTournament">Local
                </button>
                <button class="btn btn-primary btn-sm shadow-sm text-light col-6" data-bs-toggle="modal" data-bs-target="#onlineTournament">Online
                </button>
            </div>
            `;
        }
        else if (activeLanguage.textContent.trim().toLowerCase() === 'français') {
            document.getElementById('playDiv').innerHTML = `
            <div class="mb-2 text-center">
                <p class="mb-2"><span id="backArrow" style="cursor: pointer;">
                    <i class="bi bi-arrow-left text-light me-1"></i>
                </span>Lancer un tournoi :</p>
                <button class="btn btn-dark btn-sm shadow-sm text-light col-6 mb-2" data-bs-toggle="modal" data-bs-target="#localTournament">Local
                </button>
                <button class="btn btn-primary btn-sm shadow-sm text-light col-6" data-bs-toggle="modal" data-bs-target="#onlineTournament">En ligne
                </button>
            </div>
            `;
        }
        else if (activeLanguage.textContent.trim().toLowerCase() === 'español') {
            document.getElementById('playDiv').innerHTML = `
            <div class="mb-2 text-center">
                <p class="mb-2"><span id="backArrow" style="cursor: pointer;">
                    <i class="bi bi-arrow-left text-light me-1"></i>
                </span>Iniciar un torneo :</p>
                <button class="btn btn-dark btn-sm shadow-sm text-light col-6 mb-2" data-bs-toggle="modal" data-bs-target="#localTournament">Local
                </button>
                <button class="btn btn-primary btn-sm shadow-sm text-light col-6" data-bs-toggle="modal" data-bs-target="#onlineTournament">En línea
                </button>
            </div>
            `;
        }
        document.getElementById('backArrow').addEventListener('click', function() {
            document.getElementById('playDiv').innerHTML = initialContent;
            applyTranslation(activeLanguage.textContent.trim().toLowerCase());
            attachEvent();
        });
    });
}

attachEvent();