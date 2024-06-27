function runsocket(){
let url = `wss://${window.location.host}/ws/socket-pong-online/`

const chatSocket = new WebSocket(url);

let running = true

let data = null
let latestData = null;
let interval = setInterval(() => {
    console.log(latestData);
    console.log(data);
    latestData = null;
}, 1000);


chatSocket.onmessage = function(e){
    let data = JSON.parse(e.data)
    if (data.type == 'connection_established')
        console.log(data);
    else if (data.type == 'update received')
    {
        latestData = data.data
        paddle_speed = data.data.paddle_speed
        paddle_width = parseInt(data.data.paddle_width)
        paddle_height = parseInt(data.data.paddle_height)
        p1_x_pos = parseFloat(data.data.p1_x_pos)
        p1_y_pos = parseFloat(data.data.p1_y_pos)
        p2_x_pos = parseFloat(data.data.p2_x_pos)
        p2_y_pos = parseFloat(data.data.p2_y_pos)
        p1_score = parseInt(data.data.p1_score)
        p2_score = parseInt(data.data.p2_score)  
        ball_x_pos = parseFloat(data.data.ball_x_pos)
        ball_y_pos = parseFloat(data.data.ball_y_pos)
        ball_width = parseFloat(data.data.ball_width)
        ball_x_velocity = parseFloat(data.data.ball_x_velocity)
        ball_y_velocity = parseFloat(data.data.ball_y_velocity)
        ball_x_normalspeed = parseFloat(data.data.ball_x_normalspeed)
        player1 = data.data.player1
        player2 = data.data.player2
        if (data.data.has_finished === true)
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

const canvas = document.getElementById('CanvasOnline');

const ctx = canvas.getContext('2d');

var canvasModal = document.getElementById('onlineMatchModal');
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
    }
});

document.addEventListener('keyup', function(event) {
    const key = event.key;

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
    }
});

function draw_objects(){
    ctx.fillStyle = 'black';
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    ctx.fillStyle = 'white';
    ctx.fillRect(p1_x_pos,  p1_y_pos, paddle_width, paddle_height);
    ctx.fillRect(p2_x_pos,  p2_y_pos, paddle_width, paddle_height);
    ctx.beginPath();
    ctx.arc(ball_x_pos, ball_y_pos, ball_width, 0, Math.PI * 2);
    ctx.fill();
    ctx.closePath();
    ctx.font = "45px sans-serif"
    ctx.font = "25px Orbitron"
    ctx.textAlign = 'center'
    ctx.fillText(p1_score, WIDTH / 4, HEIGHT / 6, 45)
    ctx.fillText(p2_score, WIDTH * 3 / 4, HEIGHT / 6, 45)
    ctx.fillText(player2, WIDTH * 3 / 4, HEIGHT / 10)
    ctx.fillText(player1, WIDTH / 4, HEIGHT / 10)

}

function get_update(){
    if (chatSocket.readyState === WebSocket.OPEN){
        chatSocket.send(JSON.stringify({'message': 'update'}));
    }
}

function draw(){
    if (running){
        draw_objects()
        get_update()
        requestAnimationFrame(draw);
    }
    else
    {
        console.log(latestData)
        ctx.fillStyle = 'black'
        ctx.fillRect(0, 0, canvas.width, canvas.height);
        ctx.fillStyle = 'red';
        ctx.textAlign = 'center'
        ctx.textBaseline = "middle"
        ctx.font = "40px Orbitron"
        ctx.fillText("Game Over", WIDTH/2, HEIGHT/2 - 20)
        let win_message
        if (p1_score > p2_score){
            win_message = player1 + " won the match"
        }
        else
            win_message = player2 + " won the match"
        ctx.fillStyle = 'white'
        ctx.textBaseline = 'center'
        ctx.fillText(win_message, WIDTH/2, HEIGHT/2 + 20)
        clearInterval(interval)
        chatSocket.close()
    }
}

draw();
}
runsocket()
