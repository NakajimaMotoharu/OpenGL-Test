#ifndef __SUB_H__
#define __SUB_H__

#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

#define MY_W 1366
#define MY_H 768
#define MY_MAP_MAXVAL 1024
#define MY_MAP_MAXHIGH 5
#define MY_BUF 256
#define MY_CONSOLE_LINES 60
#define MY_CONSOLE_CHAR 256
#define MY_UPDATE 1

typedef struct{
	double x, y, z;
}MY_POSITION;

typedef struct{
	int exist;
	double r, g, b;
}MY_BLOCK;

//show.c
void show(void);

//io.c
void maindisp(int value);
void key(unsigned char keys, int x, int y);
void keyup(unsigned char keys, int x, int y);
void spkey(int keys, int x, int y);
void my_click(int button, int state, int x, int y);
void my_psmt(int x, int y);

//calc.c
double rand1(int n);
void fpscountfunc(int value);
void my_lookin(void);
void my_mapreset(void);
void my_info(char buf[MY_BUF]);
void my_upp_calc(void);
void my_act(void);
void my_move_update(int value);
int my_map_access(int x, int y, int z, MY_BLOCK *data);

//console.c
void console_main(unsigned char keys);
void console_intext(char *text);
void console_internal_action(char *func);
int console_search_func(char *func);

extern MY_POSITION you, watch;
extern MY_BLOCK my_mapdata[MY_MAP_MAXVAL][MY_MAP_MAXHIGH][MY_MAP_MAXVAL];
extern double my_upp, my_rad, my_und, updpms;
extern int fpscount, fpscurrent, psmtfrag, psmt_wp, vecx, vecz;
extern int pushw, pusha, pushs, pushd, menufrag;
extern char console_buf[MY_CONSOLE_LINES][MY_CONSOLE_CHAR];
extern int console_point, console_char, fov, updcount, updcurrent;
extern int dashfrag, my_map_area, speed_mag, jump_mag, sens_mag;

#endif /* __SUB_H__ */
