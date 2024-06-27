

function runsocket(){
    let url = `wss://${window.location.host}/ws/socket-pong-tournament-local/`;
    
    const chatSocket = new WebSocket(url);
    

    let running = true;

    let data = null
    let latestData = null;
    let interval = setInterval(() => {
        console.log(latestData);
        console.log(data);
        latestData = null;
    }, 1000); 

    chatSocket.onmessage = function(e){
        data = JSON.parse(e.data)
        if (data.type == 'connection_established')
            console.log(data);
        else if (data.type == 'update received')
        {
            if (data.data.game_data)
            {
                latestData = data.data.game_data
                paddle_speed = data.data.game_data.paddle_speed
                paddle_width = parseInt(data.data.game_data.paddle_width)
                paddle_height = parseInt(data.data.game_data.paddle_height)
                p1_x_pos = parseFloat(data.data.game_data.p1_x_pos)
                p1_y_pos = parseFloat(data.data.game_data.p1_y_pos)
                p2_x_pos = parseFloat(data.data.game_data.p2_x_pos)
                p2_y_pos = parseFloat(data.data.game_data.p2_y_pos)
                p1_score = parseInt(data.data.game_data.p1_score)
                p2_score = parseInt(data.data.game_data.p2_score)  
                ball_x_pos = parseFloat(data.data.game_data.ball_x_pos)
                ball_y_pos = parseFloat(data.data.game_data.ball_y_pos)
                ball_width = parseFloat(data.data.game_data.ball_width)
                ball_x_velocity = parseFloat(data.data.game_data.ball_x_velocity)
                ball_y_velocity = parseFloat(data.data.game_data.ball_y_velocity)
                ball_x_normalspeed = parseFloat(data.data.game_data.ball_x_normalspeed)
                player1 = data.data.game_data.player1
                player2 = data.data.game_data.player2
            }
            if (data.data.tournament && data.data.tournament.is_finished == true)
                running = false
        }   
    }
    
    WHITE = (255, 255, 255)
    BLACK = (0, 0, 0)
    
    WIDTH = 600
    HEIGHT = 600
    
    let delay = 30
    
    let paddle_speed = 5
    
    let paddle_width = 10
    let paddle_height = 100
    
    let p1_x_pos = 10
    let p1_y_pos = HEIGHT / 2 - paddle_height / 2
    
    
    let p2_x_pos = WIDTH - paddle_width - 10
    let p2_y_pos = HEIGHT / 2 - paddle_height / 2
    
    let p1_score = 0
    let p2_score = 0
    
    let p1_up = false
    let p1_down = false
    let p2_up = false
    let p2_down = false
    
    let ball_x_pos = WIDTH / 2
    let ball_y_pos = HEIGHT / 2
    let ball_width = 8
    let ball_x_velocity = -1
    let ball_y_velocity = 0
    let ball_x_normalspeed = 1
    let player1 = ""
    let player2 = ""
    
    const canvas = document.getElementById('CanvasTourLocal');
    
    const ctx = canvas.getContext('2d');
    
    var canvasModal = document.getElementById('localTournament');
    let update = null
	canvasModal.addEventListener('hidden.bs.modal', function () {
        console.log("aurevoir")
		chatSocket.close()
        clearInterval(interval)
        clearInterval(update)
        running = null
	});

    document.addEventListener('keydown', function(event) {
        const key = event.key;
    
        switch(key) {
            case 'z':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_up_pressed'}));
                break;
            case 'w':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_up_pressed'}));
                break;
            case 's':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_down_pressed'}));
                break;
            case 'ArrowUp':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'p2key_up_pressed'}));
                break;
            case 'ArrowDown':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'p2key_down_pressed'}));
                break;
            case 'ArrowRight':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_right_pressed'}));
                break;
            case 'ArrowLeft':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_left_pressed'}));
                break;
            case 'Enter':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_enter_pressed'}));
                    break;
        }
    });
    
    document.addEventListener('keyup', function(event) {
        const key = event.key;
        console.log(key)
        switch(key) {
            case 'z':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_up_released'}));
                break;
            case 'w':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_up_released'}));
                break;
            case 's':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_down_released'}));
                break;
            case 'ArrowUp':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'p2key_up_released'}));
                break;
            case 'ArrowDown':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'p2key_down_released'}));
                break;
            case 'ArrowRight':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_right_released'}));
                break;
            case 'ArrowLeft':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_left_released'}));
                break;
            case 'Enter':
                if (chatSocket.readyState === WebSocket.OPEN)
                    chatSocket.send(JSON.stringify({'message': 'key_enter_released'}));
                break;
        }
        if (chatSocket.readyState === WebSocket.OPEN)
            chatSocket.send(JSON.stringify({'message': 'key_pressed', 'key': key}));
    });
    
    function draw_objects(){
        if (data && data.data && data.data.tournament.status === "SelectSize") // debut du tournois demarage
        {
            ctx.fillStyle = 'black'
            ctx.fillRect(0, 0, canvas.width, canvas.height);
            ctx.fillStyle = 'white';
            ctx.textAlign = "center"
            ctx.font = "25px Orbitron"
            message = "select tournament size: "
            ctx.fillText(message, WIDTH/2, HEIGHT/2)
            message = "< " + data.data.tournament.maxplayer + " >"
            ctx.fillText(message, WIDTH/2, HEIGHT/2 + 40)
        }
        else if (data && data.data && data.data.tournament.status === "SelectPlayerNames") // debut du tournois demarage
        {
            ctx.fillStyle = 'black'
            ctx.fillRect(0, 0, canvas.width, canvas.height);
            ctx.fillStyle = 'white';
            ctx.textAlign = "center"
            ctx.font = "25px Orbitron"
            message = "select player name: "
            ctx.fillText(message, WIDTH/2, HEIGHT/2)
            message = data.data.tournament.playername + "_"
            ctx.fillText(message, WIDTH/2, HEIGHT/2 + 40)
        }
        else if (data && data.data && data.data.tournament.status === "New_match") // debut du tournois demarage
        {
            ctx.fillStyle = 'black'
            ctx.fillRect(0, 0, canvas.width, canvas.height);
            ctx.fillStyle = 'white';
            ctx.textAlign = "center"
            // console.log(data)
            ctx.textBaseline = "middle"
            ctx.font = "25px Orbitron"
            message = "Next match starts in: "
            ctx.fillText(message, WIDTH/2, HEIGHT/2 - 60)
            ctx.font = "60px Orbitron"
            message =  data.data.tournament.timer 
            ctx.fillText(message, WIDTH/2, HEIGHT/2)
            message = data.data.tournament.games[0].player1
            ctx.font = "35px Orbitron"
            ctx.fillText(message, WIDTH/4 + 10, HEIGHT/2 + 60)
            ctx.font = "25px Orbitron"
            ctx.fillStyle = 'red';
            ctx.fillText("vs", WIDTH/2, HEIGHT/2 + 60)
            ctx.fillStyle = 'white';
            ctx.font = "35px Orbitron"
            message = data.data.tournament.games[0].player2
            ctx.fillText(message, ((WIDTH/4) * 3) -10, HEIGHT/2 + 60)
        }
        
        else    //pendant le match
        {
            ctx.fillStyle = 'black';
            ctx.fillRect(0, 0, canvas.width, canvas.height);
            ctx.fillStyle = 'white';
            ctx.fillRect(p1_x_pos,  p1_y_pos, paddle_width, paddle_height);
            ctx.fillRect(p2_x_pos,  p2_y_pos, paddle_width, paddle_height);
            ctx.beginPath();
            ctx.arc(ball_x_pos, ball_y_pos, ball_width, 0, Math.PI * 2);
            ctx.fill();
            ctx.closePath();
            ctx.font = "25px Orbitron"
            ctx.textAlign = 'center'
            ctx.fillText(p1_score, WIDTH / 4, HEIGHT / 6, 45)
            ctx.fillText(p2_score, WIDTH * 3 / 4, HEIGHT / 6, 45)
            ctx.fillText(player2, WIDTH * 3 / 4, HEIGHT / 10)
            ctx.fillText(player1, WIDTH / 4, HEIGHT / 10)
        }
    }
    
    function get_update(){

        if (chatSocket.readyState === WebSocket.OPEN){
            chatSocket.send(JSON.stringify({'message': 'update'}));
        }
    }
    
    update = setInterval(() => {
        get_update()
    }, 10);

    function draw(){
        if (running){
            draw_objects()
            requestAnimationFrame(draw);
        }
        else if (running == false) //fin du tournois
        {
            console.log(latestData)
            ctx.fillStyle = 'black'
            ctx.fillRect(0, 0, canvas.width, canvas.height);
            ctx.fillStyle = 'white';
            ctx.textAlign = "center"
            ctx.textBaseline = "middle"
            ctx.font = "25px Orbitron"
            ctx.fillText("Tournament finished", WIDTH/2, HEIGHT/2 -40)
            let win_message
            ctx.font = "35px Orbitron"
            ctx.fillStyle = 'red';
            win_message = data.data.tournament.winner
            ctx.fillText(win_message, WIDTH/2, HEIGHT/2)
            ctx.fillStyle = 'white'
            ctx.textBaseline = 'center'
            ctx.font = "25px Orbitron"
            ctx.fillText("won the tournament!", WIDTH/2, HEIGHT/2 +40)
            clearInterval(update)
            clearInterval(interval)
            chatSocket.close()
        }
        else
            return
    }
    
    draw();
    }
    runsocket()
