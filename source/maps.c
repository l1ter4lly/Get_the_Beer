#include "maps.h"
#include "utils/collision.h"
#include "utils/utils.h"
#include "player.h"
#include "figure.h"
#include "game.h"
#include "tunes.h"

void map_draw(struct map_t* m)
{
	for( int i = 0; i < m->number_static; i++)
	{
		platform_draw(&m->platform_list_static[i]);
	}
	
	for( int k = 0; k < m->number_dynamic; k++)
	{
		platform_draw(&m->platform_list_dynamic[k]);
	}
	
	Reset0Ref();				
	dp_VIA_t1_cnt_lo = 0x7f;	
	Moveto_d(m->target_y, m->target_x);		

	scale_beam(13);
	if(current_game.difficulty == 1)
	{
		Draw_VLp(&drunkard_r);
	}
	else
	{
		Draw_VLp(&beer_l);
	}
		
}

int map_check_target(struct map_t* m)
{
	if(check_collision(player.y, player.x, m->target_y, m->target_x, 5, 6))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int map_check(struct map_t* m)
{
	int platform_touched = 0;
	
	for( int i = 0; i < m->number_static; i++)
	{		
		if( platform_check(&m->platform_list_static[i]) )
		{
			if(player.momentum == FALLING)
			{
				play_music(&landing);
				player.momentum = STANDING;
				player.speed_y = 0;
				platform_touched = 1;
				//speed_cnt_y = speed_cnt_std;
				
				if(player.draw_state == JUMP_LEFT)
				{
					player.draw_state = STAND_LEFT;
				}
				else if(player.draw_state == JUMP_RIGHT)
				{
					player.draw_state = STAND_RIGHT;
				}
					
				break;			
			}
			else
			{
				platform_touched = 1;
			}
			return -1;
		}
		
	}
	if(platform_touched == 0)
	{
		for(int k = 0; k < m->number_dynamic; k++)
		{
			if( platform_check(&m->platform_list_dynamic[k]))
			{
				if(player.momentum == FALLING)
				{
					play_music(&landing);
					player.momentum = STANDING;
					player.speed_y = 0;
					platform_touched = 1;
					//speed_cnt_y = speed_cnt_std;
					
					if(player.draw_state == JUMP_LEFT)
					{
						player.draw_state = STAND_LEFT;
					}
					else if(player.draw_state == JUMP_RIGHT)
					{
						player.draw_state = STAND_RIGHT;
					}
						
					break;			
				}
				else
				{
					//player.y += (int)&m->platform_list_dynamic[k].speed_y;
					platform_touched = 1;
					return k;
					break;
				}
			}
		}
	}
	
	if(platform_touched == 0)
	{
		if(player.momentum != FALLING)
		{
			player.momentum = FALLING;
			if(player.draw_state == STAND_LEFT)
			{
				player.draw_state = JUMP_LEFT;
			}
			else
			{
				player.draw_state = JUMP_RIGHT;
			}
		}	
	}	
	return -1;
	
}

void map_update(struct map_t* m)
{
	
	for( int k = 0; k <= m->number_dynamic; k++)
	{
		platform_update(&m->platform_list_dynamic[k]);
	}

}

struct map_t map_empty =
{
	.number_static = 0,
	.number_dynamic = 0,
	
	.platform_list_static =
	{

	},
	
	.platform_list_dynamic =
	{
		
	}
};


struct map_t map_1 =
{
	.number_static = 10,
	.number_dynamic = 2,
		
	.target_y = 115,
	.target_x =106,
	
	.platform_list_static =
	{
			{.state = STATIC, .size = LARGE, .y = 	-100, 	.x =  -50, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = LARGE, .y = 	 -80, 	.x =   60, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = LARGE, .y = 	 -60, 	.x =   10, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = MIDDLE, .y = 	 -40, 	.x =    0, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = MIDDLE, .y = 	 -25, 	.x =   15, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = LARGE, .y = 	  40, 	.x =  -20, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = LARGE, .y = 	  60, 	.x =  -40, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = LARGE, .y = 	  80, 	.x =   20, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = LARGE, .y = 	 100, 	.x =   70, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = LARGE, .y = 	 111, 	.x =  100, .speed_y = 0, .speed_x = 0},
			
	},
	
	.platform_list_dynamic =
	{
			{.state = MOBILE, .size = LARGE, .y = 	-80, 	.x = -50, .speed_y = 0, .speed_x = 1, .max_travel_dist = 60, .travelled_dist = 0},
			{.state = MOBILE, .size = LARGE, .y = 	-40, 	.x = 50, .speed_y = 1, .speed_x = 0, .max_travel_dist = 90, .travelled_dist = 0},
	}
	

};

struct map_t map_2 =
{
	.number_static = 9,
	.number_dynamic = 2,
		
	.target_y =  115,
	.target_x = -106,
	
	.platform_list_static =
	{
			{.state = STATIC, .size = LARGE, .y = 	-100, 	.x =  -85, .speed_y = 0, .speed_x = 0}, //1
			{.state = STATIC, .size = LARGE, .y = 	 -85, 	.x =  -25, .speed_y = 0, .speed_x = 0},	//2
			{.state = STATIC, .size = LARGE, .y = 	 -75, 	.x =   35, .speed_y = 0, .speed_x = 0},	//3
			{.state = STATIC, .size = LARGE, .y = 	   5, 	.x =   40, .speed_y = 0, .speed_x = 0},	//4
			{.state = STATIC, .size = LARGE, .y = 	 -25, 	.x =  -45, .speed_y = 0, .speed_x = 0},	//5
			{.state = STATIC, .size = MIDDLE, .y = 	  40, 	.x =  -65, .speed_y = 0, .speed_x = 0},	//6
			{.state = STATIC, .size = LARGE, .y = 	  60, 	.x =  -45, .speed_y = 0, .speed_x = 0},	//7
			{.state = STATIC, .size = LARGE, .y = 	  80, 	.x =  -65, .speed_y = 0, .speed_x = 0},	//8
			{.state = STATIC, .size = LARGE, .y = 	 110, 	.x = -100, .speed_y = 0, .speed_x = 0},	//9
			
	},
	
	.platform_list_dynamic =
	{
			{.state = MOBILE, .size = LARGE, .y = 	-60, 	.x = 60, .speed_y = 1, .speed_x = 0, .max_travel_dist = 60, .travelled_dist = 0},
			{.state = MOBILE, .size = LARGE, .y = 	 20, 	.x = 15, .speed_y = 0, .speed_x = -1, .max_travel_dist = 90, .travelled_dist = 0},
	}
	

};
struct map_t map_3 =
{
	.number_static = 8,
	.number_dynamic = 3,
		
	.target_y =  115,
	.target_x =  106,
	
	.platform_list_static =
	{
			{.state = STATIC, .size = LARGE, .y = 	-100, 	.x =    5, .speed_y = 0, .speed_x = 0}, //1
			{.state = STATIC, .size = LARGE, .y = 	 -80, 	.x =  -35, .speed_y = 0, .speed_x = 0},	//2
			{.state = STATIC, .size = LARGE, .y = 	 -60, 	.x =   -5, .speed_y = 0, .speed_x = 0},	//3
			{.state = STATIC, .size = LARGE, .y = 	  25, 	.x =    0, .speed_y = 0, .speed_x = 0},	//4
			{.state = STATIC, .size = MIDDLE, .y = 	  45, 	.x =   40, .speed_y = 0, .speed_x = 0},	//5
			{.state = STATIC, .size = MIDDLE, .y = 	  60, 	.x =  -35, .speed_y = 0, .speed_x = 0},	//6
			{.state = STATIC, .size = LARGE, .y = 	  80, 	.x = -100, .speed_y = 0, .speed_x = 0},	//7
			{.state = STATIC, .size = LARGE, .y = 	 100, 	.x =  100, .speed_y = 0, .speed_x = 0},	//8
			
	},
	
	.platform_list_dynamic =
	{
			{.state = MOBILE, .size = LARGE, .y =   -40, 	.x = -60, .speed_y = 0, .speed_x =  1, .max_travel_dist =  60, .travelled_dist = 0},
			{.state = MOBILE, .size = LARGE, .y = 	-20, 	.x =  45, .speed_y = 0, .speed_x = -1, .max_travel_dist =  90, .travelled_dist = 0},
			{.state = MOBILE, .size = LARGE, .y =     0, 	.x = -30, .speed_y = 0, .speed_x =  1, .max_travel_dist =  100, .travelled_dist = 0},

	}
	
};
struct map_t map_4 =
{
	.number_static = 8,
	.number_dynamic = 3,
		
	.target_y =  115,
	.target_x =    0,
	
	.platform_list_static =
	{
			{.state = STATIC, .size = LARGE, .y = 	-100, 	.x =  -95, .speed_y = 0, .speed_x = 0}, //1
			{.state = STATIC, .size = LARGE, .y = 	 -80, 	.x =   85, .speed_y = 0, .speed_x = 0},	//2
			{.state = STATIC, .size = LARGE, .y = 	 -60, 	.x =  -85, .speed_y = 0, .speed_x = 0},	//3
			{.state = STATIC, .size = LARGE, .y = 	  25, 	.x =    0, .speed_y = 0, .speed_x = 0},	//4
			{.state = STATIC, .size = MIDDLE, .y = 	  45, 	.x =   50, .speed_y = 0, .speed_x = 0},	//5
			{.state = STATIC, .size = MIDDLE, .y = 	  60, 	.x =  -45, .speed_y = 0, .speed_x = 0},	//6
			{.state = STATIC, .size = MIDDLE, .y = 	  80, 	.x =  -60, .speed_y = 0, .speed_x = 0},	//7
			{.state = STATIC, .size = LARGE, .y = 	 100, 	.x =    0, .speed_y = 0, .speed_x = 0},	//8
			
	},
	
	.platform_list_dynamic =
	{
			{.state = MOBILE, .size = LARGE, .y =   -40, 	.x = -60, .speed_y = 0, .speed_x =  1, .max_travel_dist =  60, .travelled_dist = 0},
			{.state = MOBILE, .size = LARGE, .y = 	-20, 	.x =  45, .speed_y = 0, .speed_x = -1, .max_travel_dist =  90, .travelled_dist = 0},
			{.state = MOBILE, .size = LARGE, .y =     0, 	.x = -30, .speed_y = 0, .speed_x =  1, .max_travel_dist =  100, .travelled_dist = 0},

	}
};

struct map_t map_5 =
{
	.number_static = 5,
	.number_dynamic = 3,
	
	.target_y =  115,
	.target_x =  -50,	
	
	.platform_list_static =
	{
			{.state = STATIC, .size = MIDDLE, .y = 	-40, 	.x =   0, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = MIDDLE, .y = 	 20, 	.x = -15, .speed_y = 0, .speed_x = 0},		
			{.state = STATIC, .size = MIDDLE, .y = 	 70, 	.x =  45, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = LARGE, .y = 	110, 	.x = -50, .speed_y = 0, .speed_x = 0},
			{.state = STATIC, .size = MIDDLE, .y = 	 90, 	.x =   0, .speed_y = 0, .speed_x = 0},
			
	},
	
	.platform_list_dynamic =
	{
			{.state = MOBILE, .size = LARGE, .y =   -110, 	.x = -50, .speed_y = 1, .speed_x =  1, .max_travel_dist =   50, .travelled_dist = 0},
			{.state = MOBILE, .size = LARGE, .y = 	 -40, 	.x =  60, .speed_y = 1, .speed_x = -1, .max_travel_dist =   60, .travelled_dist = 0},
			{.state = MOBILE, .size = MIDDLE, .y = 	  45, 	.x = -80, .speed_y = 0, .speed_x =  1, .max_travel_dist =   50, .travelled_dist = 0},
	}
};

//struct platform_t list[] =
//{
	//{.state = STATIC, .size = LARGE, .y = 	-30, 	.x = -50, .speed_y = 0, .speed_x = 0},
	//{.state = STATIC, .size = MIDDLE, .y = 	30, 	.x = -50, .speed_y = 0, .speed_x = 0},
	//{.state = STATIC, .size = MIDDLE, .y = 	100, 	.x = -50, .speed_y = 0, .speed_x = 0},
	//{.state = MOBILE, .size = LARGE, .y = 	-70, 	.x = -50, .speed_y = 0, .speed_x = 0},
//};


