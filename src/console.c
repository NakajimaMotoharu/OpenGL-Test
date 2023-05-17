#include"sub.h"

void console_main(unsigned char keys){
	int i = 0;
	
	if (keys == 13){
			if ((strcmp(console_buf[console_point], ">exit")) == 0){
				menufrag = 0;
			} else if ((strcmp(console_buf[console_point], ">")) != 0) {
				console_internal_action(console_buf[console_point]);
			}
			console_char = 1;
			if (console_point != MY_CONSOLE_LINES - 1){
				console_char = 1;
				console_point = console_point + 1;
			} else {
				for (i = 0; i < MY_CONSOLE_LINES - 1; i = i + 1){
					strcpy(console_buf[i], console_buf[i + 1]);
				}
				console_buf[console_point][0] = '>';
				console_buf[console_point][console_char] = '\0';
			}
		} else if (keys == '	'){
				menufrag = 0;
		} else if (keys == 8){
			if (console_char > 1){
				console_char = console_char - 1;
				console_buf[console_point][console_char] = '\0';
			}
		} else {
			console_buf[console_point][console_char] = keys;
			console_char = console_char + 1;
			console_buf[console_point][console_char] = '\0';
			//printf("%d\n", (int)keys);
		}
}

void console_intext(char *text){
	int i = 0;
	
	if (console_point != MY_CONSOLE_LINES - 1){
		console_point = console_point + 1;
		strcpy(console_buf[console_point], text);
	} else {
		for (i = 0; i < MY_CONSOLE_LINES - 1; i = i + 1){
			strcpy(console_buf[i], console_buf[i + 1]);
		}
		strcpy(console_buf[console_point], text);
	}
}

void console_internal_action(char *func){
	int i = 0, j = 0, func_code = 0;
	char buf[MY_BUF];
	
	for (i = 0; (func[i] != '\0') && (func[i] != ' '); i = i + 1){
		buf[i] = func[i];
	}
	buf[i] = '\0';
	func_code = console_search_func(buf);
	if ((func[i] == '\0') && (func_code != 0) && (func_code != 2)){
		func_code = 0;
		console_intext("No arguments.");
	}
	i = i + 1;
	
	if (func_code != 0){
		for (j = 0; func[i] != '\0'; i = i + 1, j = j + 1){
			if ((func[i] <= '9') && (func[i] >= '0')){
				buf[j] = func[i];
			} else {
				console_intext("The argument must be an integer.");
				func_code = 0;
				break;
			}
		}
		buf[j] = '\0';
		if (func_code == 1){
			fov = atoi(buf);
			//printf("%s, %d\n", buf, fov);
		} else if (func_code == 2){
			console_intext("(1) help : Displays all commands.");
			console_intext("(2) fov  : Set FOV(1-179).");
			console_intext("(3) exit : Exit console mode.");
			console_intext("(4) area : Specifies the drawing distance.");
			console_intext("(5) jump : Specifies the jump magnification.");
			console_intext("(6) speed: Specifies the movement speed multiplier.");
			console_intext("(7) sens : Specifies the mouse sensitivity magnification.");
		} else if (func_code == 3){
			my_map_area = atoi(buf);
		} else if (func_code == 4){
			jump_mag = atoi(buf);
		} else if (func_code == 5){
			speed_mag = atoi(buf);
		} else if (func_code == 6){
			sens_mag = atoi(buf);
		}
	} else {
		console_intext("Command not found.");
	}
}

int console_search_func(char *func){
	if (strcmp(func, ">fov") == 0){
		return 1;
	} else if (strcmp(func, ">help") == 0){
		return 2;
	} else if (strcmp(func, ">area") == 0){
		return 3;
	} else if (strcmp(func, ">jump") == 0){
		return 4;
	} else if (strcmp(func, ">speed") == 0){
		return 5;
	} else if (strcmp(func, ">sens") == 0){
		return 6;
	} else {
		return 0;
	}
}
