var canvas = document.querySelector("canvas");

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

var c = canvas.getContext('2d');
var x = 100;
var y = 100;
var dx = 5;
var dy = 5;

// Desenhar retângulos
c.strokeStyle = "green";
c.lineWidth = 8;
c.strokeRect(100, 100, 100, 50)

// Desenhar retângulo cheio
c.fillStyle = "green";
c.fillRect(200, 200, 150, 100);

// Desenhar retas
c.beginPath();
c.strokeStyle = "#AAFF00"
c.lineWidth = 4;
c.moveTo(300, 300);
c.lineTo(400, 400);
c.lineTo(300, 600);
c.lineTo(300, 300);
c.stroke();

// Desenhar arcos e círculos
c.beginPath()
c.arc(400, 700, 100, 0, 360*Math.PI/180, true);
c.fill()

c.beginPath()
c.arc(700, 700, 100, 0, 90*Math.PI/180, true);
c.fillStyle = "black"
c.fill()

c.beginPath()
c.arc(700, 700, 100, 0, 90*Math.PI/180, false);
c.fillStyle = "red"
c.fill()

// Animando

function animacao() {
	requestAnimationFrame(animacao);
	c.clearRect(0, 0, innerWidth, innerHeight);
	c.beginPath();
	c.arc(x, y, 50, 0, 360*Math.PI / 180, false);
	c.strokeStyle = "black";
	c.stroke();
	
	if(x > innerWidth - 50 || x < 25 ) {
		dx = -dx;	
		
	}	
	if(y > innerHeight - 50|| y < - 25) {
		dy = -dy;	
	}

	x += dx;
	y += dy;
	
}

animacao()