#pragma once
#include "platform.h"
//


struct map_t
{
	int number_static;
	int number_dynamic;
		
	int target_y;
	int target_x;
	
	struct platform_t platform_list_static[10];
	struct platform_t platform_list_dynamic[3];

};

void map_draw(struct map_t* m);

int map_check(struct map_t* m);

int map_check_target(struct map_t* m);

void map_update(struct map_t* m);

extern struct map_t map_1;
extern struct map_t map_2;
extern struct map_t map_3;
extern struct map_t map_4;
extern struct map_t map_5;

extern struct map_t map_empty;


