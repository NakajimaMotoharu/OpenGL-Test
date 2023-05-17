#include"sub.h"

void show(){
	int i = 0, j = 0, k = 0;
	double l = 0.0, m = 0.0, n = 0.0;
	char buf[MY_BUF], echo_exit[] = "exit";
	MY_BLOCK tmp;
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	if (menufrag == 0){
		glColor3d(1.0, 0.0, 0.0);
		
		glViewport(0, 0, MY_W, MY_H);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(you.x, you.y, you.z, watch.x, watch.y, watch.z, 0.0, 1.0, 0.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective((double)fov, (double)MY_W / (double)MY_H, 1.0, 100.0);
		
		glBegin(GL_QUADS);
			for (i = (int)you.x - my_map_area; i < (int)you.x + my_map_area; i = i + 1){
				for (j = -1; j < MY_MAP_MAXHIGH - 1; j = j + 1){
					for (k = (int)you.z - my_map_area; k < (int)you.z + my_map_area; k = k + 1){
						if (my_map_access(i, j, k, &tmp) == 1){
							glColor3d(tmp.r, tmp.g, tmp.b);
							l = (double)i;
							m = (double)j;
							n = (double)k;
							glVertex3f(l - 0.5, m + 0.0, n - 0.5);
							glVertex3f(l - 0.5, m + 1.0, n - 0.5);
							glVertex3f(l + 0.5, m + 1.0, n - 0.5);
							glVertex3f(l + 0.5, m + 0.0, n - 0.5);
							glVertex3f(l - 0.5, m + 0.0, n - 0.5);
							glVertex3f(l - 0.5, m + 0.0, n + 0.5);
							glVertex3f(l + 0.5, m + 0.0, n + 0.5);
							glVertex3f(l + 0.5, m + 0.0, n - 0.5);
							glVertex3f(l - 0.5, m + 0.0, n - 0.5);
							glVertex3f(l - 0.5, m + 0.0, n + 0.5);
							glVertex3f(l - 0.5, m + 1.0, n + 0.5);
							glVertex3f(l - 0.5, m + 1.0, n - 0.5);
							glVertex3f(l + 0.5, m + 1.0, n + 0.5);
							glVertex3f(l + 0.5, m + 0.0, n + 0.5);
							glVertex3f(l - 0.5, m + 0.0, n + 0.5);
							glVertex3f(l - 0.5, m + 1.0, n + 0.5);
							glVertex3f(l + 0.5, m + 1.0, n + 0.5);
							glVertex3f(l + 0.5, m + 1.0, n - 0.5);
							glVertex3f(l - 0.5, m + 1.0, n - 0.5);
							glVertex3f(l - 0.5, m + 1.0, n + 0.5);
							glVertex3f(l + 0.5, m + 1.0, n + 0.5);
							glVertex3f(l + 0.5, m + 1.0, n - 0.5);
							glVertex3f(l + 0.5, m + 0.0, n - 0.5);
							glVertex3f(l + 0.5, m + 0.0, n + 0.5);
						}
					}
				}
			}
		glEnd();
		
		glBegin(GL_LINES);
			glColor3d(0.0, 0.0, 0.0);
			
			for (i = (int)you.x - my_map_area; i < (int)you.x + my_map_area; i = i + 1){
				for (j = -1; j < MY_MAP_MAXHIGH - 1; j = j + 1){
					for (k = (int)you.z - my_map_area; k < (int)you.z + my_map_area; k = k + 1){
						if (my_map_access(i, j, k, &tmp) == 1){
							l = (double)i;
							m = (double)j;
							n = (double)k;
							glVertex3f(l - 0.5, m + 0.0, n - 0.5);
							glVertex3f(l + 0.5, m + 0.0, n - 0.5);
							glVertex3f(l + 0.5, m + 0.0, n - 0.5);
							glVertex3f(l + 0.5, m + 0.0, n + 0.5);
							glVertex3f(l + 0.5, m + 0.0, n + 0.5);
							glVertex3f(l - 0.5, m + 0.0, n + 0.5);
							glVertex3f(l - 0.5, m + 0.0, n + 0.5);
							glVertex3f(l - 0.5, m + 0.0, n - 0.5);
							glVertex3f(l - 0.5, m + 1.0, n - 0.5);
							glVertex3f(l + 0.5, m + 1.0, n - 0.5);
							glVertex3f(l + 0.5, m + 1.0, n - 0.5);
							glVertex3f(l + 0.5, m + 1.0, n + 0.5);
							glVertex3f(l + 0.5, m + 1.0, n + 0.5);
							glVertex3f(l - 0.5, m + 1.0, n + 0.5);
							glVertex3f(l - 0.5, m + 1.0, n + 0.5);
							glVertex3f(l - 0.5, m + 1.0, n - 0.5);
							glVertex3f(l - 0.5, m + 0.0, n - 0.5);
							glVertex3f(l - 0.5, m + 1.0, n - 0.5);
							glVertex3f(l + 0.5, m + 0.0, n - 0.5);
							glVertex3f(l + 0.5, m + 1.0, n - 0.5);
							glVertex3f(l + 0.5, m + 0.0, n + 0.5);
							glVertex3f(l + 0.5, m + 1.0, n + 0.5);
							glVertex3f(l - 0.5, m + 0.0, n + 0.5);
							glVertex3f(l - 0.5, m + 1.0, n + 0.5);
						}
					}
				}
			}
		glEnd();
	}
	
	my_info(buf);
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, MY_W, MY_H, 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	
	// info
	glRasterPos2f(0, 11);
	for (i = 0; i < strlen(buf); i = i + 1){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, buf[i]);
	}
	
	// exit
	glRasterPos2f(MY_W - 41, 11);
	for (i = 0; i < strlen(echo_exit); i = i + 1){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, echo_exit[i]);
	}
	glBegin(GL_LINES);
		glColor3d(0.0, 0.0, 0.0);
		glVertex2f(MY_W - 44, 13);
		glVertex2f(MY_W - 44, 0);
		glVertex2f(MY_W - 44, 13);
		glVertex2f(MY_W, 13);
	glEnd();
		
	// closshear
	if (menufrag == 0){
		glColor3d(1.0, 1.0, 1.0);
		glBegin(GL_QUAD_STRIP);
			glVertex2f((MY_W / 2) - 6, (MY_H / 2) - 1);
			glVertex2f((MY_W / 2) - 6, (MY_H / 2) + 1);
			glVertex2f((MY_W / 2) - 2, (MY_H / 2) - 1);
			glVertex2f((MY_W / 2) - 2, (MY_H / 2) + 1);
		glEnd();
		glBegin(GL_QUAD_STRIP);
			glVertex2f((MY_W / 2) + 2, (MY_H / 2) - 1);
			glVertex2f((MY_W / 2) + 2, (MY_H / 2) + 1);
			glVertex2f((MY_W / 2) + 6, (MY_H / 2) - 1);
			glVertex2f((MY_W / 2) + 6, (MY_H / 2) + 1);
		glEnd();
		glBegin(GL_QUAD_STRIP);
			glVertex2f((MY_W / 2) - 1, (MY_H / 2) - 6);
			glVertex2f((MY_W / 2) + 1, (MY_H / 2) - 6);
			glVertex2f((MY_W / 2) - 1, (MY_H / 2) - 2);
			glVertex2f((MY_W / 2) + 1, (MY_H / 2) - 2);
		glEnd();
		glBegin(GL_QUAD_STRIP);
			glVertex2f((MY_W / 2) - 1, (MY_H / 2) + 2);
			glVertex2f((MY_W / 2) + 1, (MY_H / 2) + 2);
			glVertex2f((MY_W / 2) - 1, (MY_H / 2) + 6);
			glVertex2f((MY_W / 2) + 1, (MY_H / 2) + 6);
		glEnd();
		glColor3d(0.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
			glVertex2f((MY_W / 2) - 6, (MY_H / 2) - 1);
			glVertex2f((MY_W / 2) + 7, (MY_H / 2) - 1);
			glVertex2f((MY_W / 2) + 7, (MY_H / 2) + 2);
			glVertex2f((MY_W / 2) - 6, (MY_H / 2) + 2);
		glEnd();
		glBegin(GL_LINE_LOOP);
			glVertex2f((MY_W / 2) - 1, (MY_H / 2) - 6);
			glVertex2f((MY_W / 2) - 1, (MY_H / 2) + 7);
			glVertex2f((MY_W / 2) + 2, (MY_H / 2) + 7);
			glVertex2f((MY_W / 2) + 2, (MY_H / 2) - 6);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f((MY_W / 2) - 7, (MY_H / 2) - 1);
			glVertex2f((MY_W / 2) - 2, (MY_H / 2) - 6);
		glEnd();
	}
	
	if (menufrag == 1){
		glColor3d(0.0, 0.0, 0.0);
		
		glRasterPos2f(0, 24);
		snprintf(buf, MY_BUF, "Console screen mode.");
		for (i = 0; i < strlen(buf); i = i + 1){
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, buf[i]);
		}
		for (j = 0; j <= console_point; j = j + 1){
			glRasterPos2f(0, (j + 1) * 12 + 24);
			snprintf(buf, MY_BUF, "%s", console_buf[j]);
			for (i = 0; i < strlen(buf); i = i + 1){
				glutBitmapCharacter(GLUT_BITMAP_9_BY_15, buf[i]);
			}
		}
	}
	
	fpscount = fpscount + 1;
	glFlush();
}
