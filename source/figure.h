#pragma once
#include "utils/vector.h"

//figures-----------------------------------------------------------------------------------------
#undef SF
#define SF 16

// ---------------------------------------------------------------------------
const struct vector_t quadrat[] = 
{
		{10, 0},
		{0, 10},
		{-10, 0},
		{0, -10},
};

const struct packet_t vectors_xx[] =
{
	{MOVE, {  20,  -20}},
	{DRAW, { -40,    0}},
	{DRAW, {   0,   40}},
	{DRAW, {  40,    0}},
	{DRAW, {   0,  -40}},
	{MOVE, { -10,   10}},
	{DRAW, { -20,   20}},
	{MOVE, {   0,  -20}},
	{DRAW, {  20,   20}},
	{STOP, {   0,    0}}
};

const struct packet_t beer_l[] =
{
	{MOVE, {  0 * SF,  	0 * SF}},  //1
	{DRAW, {  0 * SF,  	2 * SF}},	//2
	{DRAW, {  6 * SF,  	0 * SF}},	//3
	{MOVE, { -2 * SF,  	0 * SF}},	//4
	{DRAW, {  0 * SF,  	1 * SF}},	//5
	{DRAW, { -2 * SF,  	0 * SF}},	//6
	{DRAW, {  0 * SF,  -1 * SF}},	//7
	{MOVE, {  0 * SF,  -1 * SF}},	//8
	{DRAW, {  2 * SF,   0 * SF}},	//9
	{MOVE, {  0 * SF,  -1 * SF}},	//10
	{DRAW, { -2 * SF,  	0 * SF}},	//11
	{MOVE, {  0 * SF,  -1 * SF}},	//12
	{DRAW, {  2 * SF,  	0 * SF}},	//13
	{MOVE, {  2 * SF,  -1 * SF}},	//14
	{DRAW, { -6 * SF,  	0 * SF}},	//15
	{DRAW, {  0 * SF,  	2 * SF}},	//16
	
		
	{STOP, {   0,    0}}
};

const struct packet_t beer_r[] =
{
	{MOVE, {  0 * SF,  	0 * SF}},  	//1
	{DRAW, {  0 * SF,  -2 * SF}},	//2
	{DRAW, {  6 * SF,  	0 * SF}},	//3
	{MOVE, { -2 * SF,  	0 * SF}},	//4
	{DRAW, {  0 * SF,  -1 * SF}},	//5
	{DRAW, { -2 * SF,  	0 * SF}},	//6
	{DRAW, {  0 * SF,   1 * SF}},	//7
	{MOVE, {  0 * SF,   1 * SF}},	//8
	{DRAW, {  2 * SF,   0 * SF}},	//9
	{MOVE, {  0 * SF,   1 * SF}},	//10
	{DRAW, { -2 * SF,  	0 * SF}},	//11
	{MOVE, {  0 * SF,   1 * SF}},	//12
	{DRAW, {  2 * SF,  	0 * SF}},	//13
	{MOVE, {  2 * SF,   1 * SF}},	//14
	{DRAW, { -6 * SF,  	0 * SF}},	//15
	{DRAW, {  0 * SF,  -2 * SF}},	//16
		
	{STOP, {   0,    0}}
};

const struct packet_t drunkard_r[] =
{
	{MOVE, {  0 * SF,  	0 * SF}},  //1
	{DRAW, {  0 * SF,  	2 * SF}},	//2
	{DRAW, {  1 * SF,  	0 * SF}},	//3
	{DRAW, {  0 * SF,  -1 * SF}},	//4
	{DRAW, {  3 * SF,  	0 * SF}},	//5
	{DRAW, {  0 * SF,  	1 * SF}},	//6
	{DRAW, {  1 * SF,  	1 * SF}},	//7
	{DRAW, {  1 * SF,  	0 * SF}},	//8
	{DRAW, {  1 * SF,  -1 * SF}},	//9
	{DRAW, {  0 * SF,  -1 * SF}},	//10
	{DRAW, {  1 * SF,  	0 * SF}},	//10
	{DRAW, {  1 * SF,   1 * SF}},	//11
	{DRAW, {  1 * SF,   0 * SF}},	//12
	{DRAW, {  1 * SF,  -1 * SF}},	//13
	{DRAW, {  0 * SF,  -1 * SF}},	//14
	{DRAW, { -1 * SF,  -1 * SF}},	//15
	{DRAW, { -1 * SF,  	0 * SF}},	//16
	{DRAW, { -1 * SF,  	1 * SF}},	//17
	{DRAW, { -8 * SF,  	0 * SF}},	//18
	
		
	{STOP, {   0,    0}}
};

const struct packet_t drunkard_l[] =
{
	{MOVE, {  0 * SF,  	0 * SF}},  //1
	{DRAW, {  0 * SF,  	-2 * SF}},	//2
	{DRAW, {  1 * SF,  	0 * SF}},	//3
	{DRAW, {  0 * SF,  	1 * SF}},	//4
	{DRAW, {  3 * SF,  	0 * SF}},	//5
	{DRAW, {  0 * SF,  	-1 * SF}},	//6
	{DRAW, {  1 * SF,  	-1 * SF}},	//7
	{DRAW, {  1 * SF,  	0 * SF}},	//8
	{DRAW, {  1 * SF,  	1 * SF}},	//9
	{DRAW, {  0 * SF,  	1 * SF}},	//10
	{DRAW, {  1 * SF,  	0 * SF}},	//10
	{DRAW, {  1 * SF,   -1 * SF}},	//11
	{DRAW, {  1 * SF,   0 * SF}},	//12
	{DRAW, {  1 * SF,  	1 * SF}},	//13
	{DRAW, {  0 * SF,  	1 * SF}},	//14
	{DRAW, { -1 * SF,  	1 * SF}},	//15
	{DRAW, { -1 * SF,  	0 * SF}},	//16
	{DRAW, { -1 * SF,  	-1 * SF}},	//17
	{DRAW, { -8 * SF,  	0 * SF}},	//18
	
		
	{STOP, {   0,    0}}
};

const struct packet_t drunkard_jump_r[] =
{
	{MOVE, {  0 * SF,  	0 * SF}},  //1
	{DRAW, {  1 * SF,  	0 * SF}},	//2
	{DRAW, {  0 * SF,  	1 * SF}},	//3
	{DRAW, {  2 * SF,  	0 * SF}},	//4
	{DRAW, {  0 * SF,  	4 * SF}},	//5
	{DRAW, {  2 * SF,  	0 * SF}},	//6
	{DRAW, {  0 * SF,  -1 * SF}},	//7
	{DRAW, { -1 * SF,  	0 * SF}},	//8
	{DRAW, {  0 * SF,  -2 * SF}},	//9
	{DRAW, {  1 * SF,  	1 * SF}},	//10
	{DRAW, {  1 * SF,  	0 * SF}},	//11
	{DRAW, {  1 * SF,  -1 * SF}},	//12
	{DRAW, {  0 * SF,  -1 * SF}},	//13
	{DRAW, {  1 * SF,  	0 * SF}},	//14
	{DRAW, {  1 * SF,   1 * SF}},	//15
	{DRAW, {  1 * SF,   0 * SF}},	//16
	{DRAW, {  1 * SF,  -1 * SF}},	//17
	{DRAW, {  0 * SF,  -1 * SF}},	//18
	{DRAW, { -1 * SF,  -1 * SF}},	//19
	{DRAW, { -1 * SF,  	0 * SF}},	//20
	{DRAW, { -1 * SF,  	1 * SF}},	//21
	{DRAW, { -6 * SF,  	0 * SF}},	//22
	{DRAW, {  0 * SF,  -1 * SF}},	//23
	{DRAW, { -2 * SF,  	0 * SF}},	//24
	{DRAW, {  0 * SF,  	1 * SF}},	//25
	
		
	{STOP, {   0,    0}}
};

const struct packet_t drunkard_jump_l[] =
{
	{MOVE, {  0 * SF,  	0 * SF}},  	//1
	{DRAW, {  1 * SF,  	0 * SF}},	//2
	{DRAW, {  0 * SF,  	-1 * SF}},	//3
	{DRAW, {  2 * SF,  	0 * SF}},	//4
	{DRAW, {  0 * SF,  	-4 * SF}},	//5
	{DRAW, {  2 * SF,  	0 * SF}},	//6
	{DRAW, {  0 * SF,  	1 * SF}},	//7
	{DRAW, { -1 * SF,  	0 * SF}},	//8
	{DRAW, {  0 * SF,  	2 * SF}},	//9
	{DRAW, {  1 * SF,  	-1 * SF}},	//10
	{DRAW, {  1 * SF,  	0 * SF}},	//11
	{DRAW, {  1 * SF,  	1 * SF}},	//12
	{DRAW, {  0 * SF,  	1 * SF}},	//13
	{DRAW, {  1 * SF,  	0 * SF}},	//14
	{DRAW, {  1 * SF,   -1 * SF}},	//15
	{DRAW, {  1 * SF,   0 * SF}},	//16
	{DRAW, {  1 * SF,  	1 * SF}},	//17
	{DRAW, {  0 * SF,  	1 * SF}},	//18
	{DRAW, { -1 * SF,  	1 * SF}},	//19
	{DRAW, { -1 * SF,  	0 * SF}},	//20
	{DRAW, { -1 * SF,  	-1 * SF}},	//21
	{DRAW, { -6 * SF,  	0 * SF}},	//22
	{DRAW, {  0 * SF,  	1 * SF}},	//23
	{DRAW, { -2 * SF,  	0 * SF}},	//24
	{DRAW, {  0 * SF,  	-1 * SF}},	//25
	
		
	{STOP, {   0,    0}}
};

const struct packet_t plattform_middle[] =
{
	{MOVE, {  0 * SF,  	0 * SF}},  	//1
	{DRAW, {  0 * SF,  	2 * SF}},	//2
	{DRAW, {  1 * SF,  	0 * SF}},	//3
	{DRAW, {  0 * SF,  -2 * SF}},	//4
	{DRAW, {  0 * SF,  -2 * SF}},	//5
	{DRAW, { -1 * SF,  	0 * SF}},	//6
	{DRAW, {  0 * SF,  	2 * SF}},	//7
	
	{STOP, {   0,    0}}
};


const struct packet_t plattform_large[] =
{
	{MOVE, {  0 * SF,  	0 * SF}},  //1
	{DRAW, {  0 * SF,  	7 * SF}},	//2
	{DRAW, {  1 * SF,  	0 * SF}},	//3
	{DRAW, {  0 * SF,  -7 * SF}},	//4
	{DRAW, {  0 * SF,  -7 * SF}},	//5
	{DRAW, { -1 * SF,  	0 * SF}},	//6
	{DRAW, {  0 * SF,  	7 * SF}},	//7
	
	{STOP, {   0,    0}}
};
	

//end figures
