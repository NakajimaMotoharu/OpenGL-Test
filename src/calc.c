#include"sub.h"

double rand1(int n){
	if (rand() % n == 0){
		return (double)rand() / (double)RAND_MAX;
	} else {
		return (double)rand() / (double)RAND_MAX * -1;
	}
}

void fpscountfunc(int value){
	fpscurrent = fpscount;
	fpscount = 0;
	updcurrent = updcount;
	updcount = 0;
	updpms = (double)updcurrent / 1000.0;
	glutTimerFunc(1000, fpscountfunc, 0);
}

void my_lookin(void){
	double addx = 0.0, addy = 0.0, addz = 0.0, supxy = 0.0;

	addx = -1.0 * sin(my_rad * acos(-1.0));
	addy = sin(my_und * acos(-1.0));
	supxy = cos(my_und * acos(-1.0));
	addz = -1.0 * cos(my_rad * acos(-1.0));

	watch.x = you.x + (addx * supxy);
	watch.y = you.y + addy;
	watch.z = you.z + (addz * supxy);
}

void my_mapreset(void){
	int i = 0, j = 0, k = 0;
	
	for (i = 0; i < MY_MAP_MAXVAL; i = i + 1){
		for (j = 0; j < MY_MAP_MAXVAL; j = j + 1){
			my_mapdata[i][0][j].exist = 1;
			my_mapdata[i][0][j].r = 0.0;
			my_mapdata[i][0][j].g = 1.0;
			my_mapdata[i][0][j].b = 0.0;
		}
	}
	
	for (i = 0; i < MY_MAP_MAXVAL; i = i + 1){
		for (j = 1; j < MY_MAP_MAXHIGH; j = j + 1){
			for (k = 0; k < MY_MAP_MAXVAL; k = k + 1){
				if ((random() % 30) == 0){
					my_mapdata[i][j][k].exist = 1;
					my_mapdata[i][j][k].r = rand1(1);
					my_mapdata[i][j][k].g = rand1(1);
					my_mapdata[i][j][k].b = rand1(1);
				} else {
					my_mapdata[i][j][k].exist = 0;
				}
			}
		}
	}
}

void my_info(char buf[MY_BUF]){
	snprintf(buf, MY_BUF, "% 4dfps, (x, y, z) = (%.1f, %.1f, %.1f), % 5dupdate", fpscurrent, you.x, you.y, you.z, updcurrent);
}

void my_upp_calc(void){
	double down_val = 0.0006, drop = 1.5;
	if (updpms != 0.0){
		down_val = down_val / sqrt(updpms);
	}
	
	if (you.y != drop){
		if (my_upp != 0.0){
			you.y = you.y + my_upp;
			my_upp = my_upp - down_val;
		} else {
			you.y = you.y + my_upp;
			my_upp = my_upp - down_val;
		}
	} else {
		if (my_upp != 0.0){
			you.y = you.y + my_upp;
			my_upp = my_upp - down_val;
		}
	}
	if (you.y < drop){
		you.y = drop;
		my_upp = 0.0;
	}
}

void my_act(void){
	double addrad = 0.0, pipe = 0.02 * ((double)speed_mag / 100.0);
	if (updpms != 0.0){
		pipe = pipe / updpms;
	}
	
	if (dashfrag == 1){
		pipe = pipe * 2.0;
	}
	
	if (menufrag == 0){
		if (pushw == 1){
			addrad = 0.0;
			you.x = you.x - ((sin(addrad + (my_rad * acos(-1.0)))) * pipe);
			you.z = you.z - ((cos(addrad + (my_rad * acos(-1.0)))) * pipe);
		}
		if (pushs == 1){
			addrad = 1.0 * acos(-1.0);
			you.x = you.x - ((sin(addrad + (my_rad * acos(-1.0)))) * pipe);
			you.z = you.z - ((cos(addrad + (my_rad * acos(-1.0)))) * pipe);
		}
		if (pusha == 1){
			addrad = 0.5 * acos(-1.0);
			you.x = you.x - ((sin(addrad + (my_rad * acos(-1.0)))) * pipe);
			you.z = you.z - ((cos(addrad + (my_rad * acos(-1.0)))) * pipe);
		}
		if (pushd == 1){
			addrad = 1.5 * acos(-1.0);
			you.x = you.x - ((sin(addrad + (my_rad * acos(-1.0)))) * pipe);
			you.z = you.z - ((cos(addrad + (my_rad * acos(-1.0)))) * pipe);
		}
	}
}

void my_move_update(int value){
	my_upp_calc();
	my_act();
	my_lookin();
	updcount = updcount + 1;
	
	glutTimerFunc(MY_UPDATE, my_move_update, 0);
}

int my_map_access(int x, int y, int z, MY_BLOCK *data){
	x = x + (MY_MAP_MAXVAL / 2);
	y = y + 1;
	z = z + (MY_MAP_MAXVAL / 2);
	
	if ((x >= 0) && (x < MY_MAP_MAXVAL)){
		if ((y >= 0) && (y < MY_MAP_MAXHIGH)){
			if ((z >= 0) && (z < MY_MAP_MAXVAL)){
				if (my_mapdata[x][y][z].exist == 1){
					data->exist = 1;
					data->r = my_mapdata[x][y][z].r;
					data->g = my_mapdata[x][y][z].g;
					data->b = my_mapdata[x][y][z].b;
					return 1;
				} else {
					data->exist = 0;
					return 0;
				}
			}
		}
	}
	
	return 0;
}
