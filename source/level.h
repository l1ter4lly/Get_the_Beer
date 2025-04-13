#pragma once
#include "utils/vector.h"
#include "maps.h"


enum level_state_t
{
	PLAY,
	LOST,
	WON,
};

struct level_t
{
	enum level_state_t state;
	struct map_t current_map;	

};

extern struct level_t current_level;

void level_init();

void level_set_map(struct level_t* current_lvl);

void level_play();

void level_draw_end();
