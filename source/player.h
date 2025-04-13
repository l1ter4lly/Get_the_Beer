#pragma once
#include "platform.h"
#include "level.h"



enum player_drawing_state
{
	STAND_LEFT,
	STAND_RIGHT,
	JUMP_LEFT,
	JUMP_RIGHT,
	BEER_LEFT,
	BEER_RIGHT,
};

enum player_momentum
{
	STANDING,
	RISING,
	FALLING,
};

enum player_live
{
	ALIVE,
	DEAD,
};


struct player_t
{
	enum player_drawing_state draw_state;
	enum player_live live;	
	enum player_momentum momentum;
	unsigned int falling_dist;
	union
	{
		struct
		{
			int y;
			int x;
		};
		long int yx;
	};
	
	union
	{
		struct
		{
			int speed_y;
			int speed_x;
		};
		long int speed_yx;
	};
		
};

extern struct player_t player;


void player_create(void);
void player_move(int y, int x);
void player_update(void);
void player_check_platforms(struct level_t* lvl);
unsigned int player_check_BottomUp(void);

