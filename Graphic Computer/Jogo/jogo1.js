var canvas = document.querySelector("canvas");
canvas.width = 500;
canvas.height = 500;
var ctx = canvas.getContext("2d");

canvas.style.position = "absolute";
canvas.style.top = "50%";
canvas.style.left = "50%";
canvas.style.transform = "translate(-50%, -50%)";

var qtdCapturados = 0;

var fundo = new Image();
fundo.src = "fundo.jpg";

var fundoEspaco = new Image();
fundoEspaco.src = "espaco.jpg";

var player = new Image();
player.src = "player.png";

var procurado = new Image();
procurado.src = "procurado.png";

var playerVirado = new Image();
playerVirado.src = "playerVirado.png";

var procuradoVirado = new Image();
procuradoVirado.src = "procuradoVirado.png";

var procuradoMorto = new Image();
procuradoMorto.src = "procuradoMorto.png";

var sprites = [];

var mundo = {
	img: fundo,
	x: 0,
	y: 0,
	width: 1000,
	height: 700
};
sprites.push(mundo);

var persona  = {
	img: player,
	x: 0,
	y: 0,
	width: 64,
	height: 61
};
sprites.push(persona);

var procurado = {
	img: procurado,
	x: 0,
	y: 0,
	width: 64,
	height: 61
};
sprites.push(procurado);

var cam = {
	x: 0,
	y: 0,
	width: canvas.width,
	height: canvas.height,
	limiteL: function () {
					return this.x + (this.width * 0.25);
	},
	limiteR: function () {
					return this.x + (this.width * 0.75);	
	},
	limiteU: function () {
					return this.y + (this.height * 0.25);
	},
	limiteD: function () {
					return this.y + (this.height * 0.75);		
	}
}

var mvLeft = mvRight = mvUp = mvDown = false;

window.addEventListener( "keydown", function (e) {
			var key = e.keyCode;
			
			switch(key) {
				case 37:
					mvLeft = true;
					break;
				case 39:
					mvRight = true;
					break;
				case 38:
					mvUp = true;
					break;
				case 40:
					mvDown = true;
					break;
								
			}	

}, false);

window.addEventListener( "keyup", function (e) {
			var key = e.keyCode;
			
			switch(key) {
				case 37:
					mvLeft = false;
					break;
				case 39:
					mvRight = false;
					break;
				case 38:
					mvUp = false;
					break;
				case 40:
					mvDown = false;
					break;
								
			}	

}, false);

function atualiza() {

if(mvLeft && !mvRight) {
persona.img = playerVirado;
persona.width = 64,
persona.height = 61;
persona.x -= 2;
}

if(mvRight && !mvLeft) {
persona.img = player;
persona.width = 64,
persona.height = 61;
persona.x += 2;
}

if(mvUp && !mvDown) {
persona.img = player;
persona.width = 64,
persona.height = 61;
persona.y -= 2;
}

if(mvDown && !mvUp) {
persona.img = player;
persona.width = 64,
persona.height = 61;
persona.y += 2;
}

if(persona.x < 0) {
	persona.x = 0;
}

if(persona.x + persona.width > mundo.width) {
	persona.x = mundo.width - persona.width;
}

if(persona.y < 0) {
	persona.y = 0;
}

if(persona.y + persona.height > mundo.height) {
	persona.y = mundo.height - persona.height;
}

if(cam.x < 0) {
	persona.x = 0;
}

if(cam.x + cam.width > mundo.width) {
	cam.x = mundo.width - cam.width;
}

if(cam.y < 0) {
	cam.y = 0;
}

if(cam.y + cam.height > mundo.height) {
	cam.y = mundo.height - cam.height;
}

if (persona.x < cam.limiteL()) {
	cam.x = persona.x - (cam.width * 0.25);
}

if (persona.x + persona.width > cam.limiteR()) {
	cam.x = persona.x + persona.width - (cam.width * 0.75);
} 

if(persona.y < cam.limiteU()) {
	cam.y = persona.y - (cam.height * 0.25);
}

if(persona.y + persona.height > cam.limiteD()) {
	cam.y = persona.y + persona.height - (cam.height * 0.75);
}

if(persona.x < procurado.x + 64 &&
	persona.x +  84 > procurado.x &&
	persona.y < procurado.y + 61 && 
	persona.y + 84 > procurado.y) {

		++qtdCapturados;
		reset();
	
}
	
}

function reset() {
	cam.x = (mundo.width - cam.width) / 2;
	cam.y = (mundo.height - cam.height) / 2;
	
	persona.x = (canvas.width - persona.width) / 2;
persona.y = (canvas.height - persona.height) / 2;

	persona.img = player;

	procurado.x = Math.random() * (mundo.width - procurado.width);
	procurado.y = Math.random() * (mundo.height - procurado.height);

	
}

function loop() {
	window.requestAnimationFrame(loop, canvas);
	atualiza();
	render();

}

function render() {
	ctx.save();
	ctx.translate(-cam.x, -cam.y);
	
  	
  for (var i in sprites) {
    var spr = sprites[i];
    ctx.drawImage(spr.img, spr.x, spr.y, spr.width, spr.height);
  }

	ctx.restore();
	ctx.font = "bold 25px Arial";
	ctx.fillStyle = "#0000ff";
	ctx.fillText("SCORE: " + qtdCapturados, 10, 30);

}

loop();