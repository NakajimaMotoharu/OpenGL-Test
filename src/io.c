#include"sub.h"

void maindisp(int value){
	glutPostRedisplay();
	glutTimerFunc(1, maindisp, 0);
}

void key(unsigned char keys, int x, int y){
	if (menufrag == 0){
		if (keys == ' '){
			if (you.y == 1.5){
				my_upp = 0.1 * ((double)jump_mag / 100.0);
			}
		} else if (keys == 'w'){
			pushw = 1;
		} else if (keys == 'a'){
			pusha = 1;
		} else if (keys == 's'){
			pushs = 1;
		} else if (keys == 'd'){
			pushd = 1;
		} else if (keys == 'q'){
			exit(0);
		} else if (keys == '	'){
			if (menufrag == 0){
				menufrag = 1;
				if (psmtfrag == 1){
					psmtfrag = 0;
					glutSetCursor(GLUT_CURSOR_INHERIT);
				}
			}
		} else if (keys == 'e'){
			my_mapreset();
		}
	} else {
		console_main(keys);
	}
}

void keyup(unsigned char keys, int x, int y){
	if (keys == 'w'){
		pushw = 0;
	} else if (keys == 'a'){
		pusha = 0;
	} else if (keys == 's'){
		pushs = 0;
	} else if (keys == 'd'){
		pushd = 0;
	}
}

void spkey(int keys, int x, int y){
	if (keys == GLUT_KEY_UP){
		my_und = my_und + 0.01;
		if (my_und >= 0.5){
			my_und = my_und - 0.01;
		}
	} else if (keys == GLUT_KEY_DOWN){
		my_und = my_und - 0.01;
		if (my_und <= -0.5){
			my_und = my_und + 0.01;
		}
	} else if (keys == GLUT_KEY_LEFT){
		my_rad = my_rad + 0.01;
	} else if (keys == GLUT_KEY_RIGHT){
		my_rad = my_rad - 0.01;
	}
}

void my_click(int button, int state, int x, int y){
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)){
		if (menufrag == 1){
			if ((x >= 1322) && (y <= 13)){
				exit(1);
			}
		} else {
			if ((x >= 1322) && (y <= 13)){
				exit(1);
			} else if (psmtfrag == 0){
				psmtfrag = 1;
				glutWarpPointer(MY_W / 2, MY_H / 2);
				glutSetCursor(GLUT_CURSOR_NONE);
			} else {
				psmtfrag = 0;
				glutSetCursor(GLUT_CURSOR_INHERIT);
			}
		}
	} else if (button == GLUT_RIGHT_BUTTON){
		if (state == GLUT_DOWN){
			if (dashfrag == 0){
				dashfrag = 1;
			}
		} else if (state == GLUT_UP){
			if (dashfrag == 1){
				dashfrag = 0;
			}
		}
	}
}

void my_psmt(int x, int y){
	int diffx = 0, diffy = 0;
	double sens = 0.001 * ((double)sens_mag / 100.0);

	if (psmtfrag == 1){
		if (psmt_wp == 0){
			diffx = (MY_W / 2) - x;
			diffy = (MY_H / 2) - y;
			my_rad = my_rad + (sens * diffx);
			my_und = my_und + (sens * diffy);
			if (my_und < -0.499999){
				my_und = -0.499999;
			} else if (my_und > 0.499999){
				my_und = 0.499999;
			}
			psmt_wp = 1;
			glutWarpPointer(MY_W / 2, MY_H / 2);
		} else {
			psmt_wp = 0;
		}
	}
}
