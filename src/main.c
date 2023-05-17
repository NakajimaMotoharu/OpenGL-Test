#include"sub.h"

MY_POSITION you, watch;
MY_BLOCK my_mapdata[MY_MAP_MAXVAL][MY_MAP_MAXHIGH][MY_MAP_MAXVAL];
double my_upp = 0.0, my_rad = 0.0, my_und = 0.0, updpms = 0.000;
int fpscount = 0, fpscurrent = 0, psmtfrag = 0, psmt_wp = 0, vecx = 0, vecz = 0;
int pushw = 0, pusha = 0, pushs = 0, pushd = 0, menufrag = 0;
char console_buf[MY_CONSOLE_LINES][MY_CONSOLE_CHAR];
int console_point = 0, console_char = 1, fov = 60, updcount = 0, updcurrent = 0;
int dashfrag = 0, my_map_area = 10, speed_mag = 100, jump_mag = 100, sens_mag = 100;

int main(int argc, char **argv){
	int i = 0;
	
	you.x = 0.0;
	you.y = 1.5;
	you.z = 15.0;
	watch.x = 0.0;
	watch.y = 1.5;
	watch.z = 14.0;
	for (i = 0; i < MY_CONSOLE_LINES; i = i + 1){
		console_buf[i][0] = '>';
		console_buf[i][1] = '\0';
	}
	
	srand(time(NULL));
	
	my_mapreset();
	
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(MY_W, MY_H);
	glutInitWindowPosition(0, 0);
	
	glutCreateWindow("GLUT test");
	glutInitDisplayMode(GLUT_RGBA);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	glutDisplayFunc(show);
	glutKeyboardFunc(key);
	glutKeyboardUpFunc(keyup);
	glutSpecialFunc(spkey);
	glutMouseFunc(my_click);
	glutPassiveMotionFunc(my_psmt);
	
	glutTimerFunc(1000, fpscountfunc, 0);
	glutTimerFunc(1, maindisp, 0);
	glutTimerFunc(MY_UPDATE, my_move_update, 0);
	
	glutMainLoop();
	
	return 0;
}
