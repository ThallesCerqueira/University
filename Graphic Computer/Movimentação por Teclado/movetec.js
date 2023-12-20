var cnv = document.querySelector("canvas");
cnv.width = window.innerWidth;
cnv.height = window.innerHeight;

var ctx = cnv.getContext("2d");
var UP = 38, DOWN = 40, LEFT = 37, RIGHT = 39;
var movUp = false, movDown = false, movLeft = false, movRight = false;

var p1 = {
x:10,
y:10
}

window.addEventListener("keydown", keydownHandler);
window.addEventListener("keyup", keyupHandler);

function keydownHandler(e) {
	var key = e.keyCode;
	
	switch(key) {
	
	case LEFT:
		movLeft = true
		break;
	case UP:
		movUp = true
		break;
	case RIGHT:
		movRight = true
		break;
	case DOWN:
		movDown = true
		break;
	}

}

function keyupHandler(e) {
	
	var key = e.keyCode;
	
	switch(key) {
	
	case LEFT:
		movLeft = false
		break;
	case UP:
		movUp = false
		break;
	case RIGHT:
		movRight = false
		break;
	case DOWN:
		movDown = false
		break;
	}
	
}

function desenhar() {

	ctx.clearRect(0, 0, cnv.width, cnv.height);
	ctx.fillRect(p1.x, p1.y, 20, 20);

}

function animacao() {
	window.requestAnimationFrame(animacao);
	desenhar();
	mover();
}

function mover() {
		if(movLeft) {
			p1.x -= 5
		}
		if(movRight) {
			p1.x += 5
		}
		if(movUp) {
			p1.y -= 5
		}
		if(movDown) {
			p1.y += 5
		}
	
}	

animacao();
