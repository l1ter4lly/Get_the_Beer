#include "player.h"
#include "utils/vector.h"
#include "utils/controller.h"
#include "utils/utils.h"
#include "figure.h"
#include "game.h"
#include "print/print.h"
#include "level.h"
#include "tunes.h"

#define speed_cnt_std 10
//---------------------------------------------------------------------------
unsigned int speed_cnt_y = speed_cnt_std;

struct player_t player =
{
	.draw_state = STAND_RIGHT,
	.live = ALIVE,
	.momentum = STANDING,
	.falling_dist =0,
	
	{{ .y = -126, .x = -100}},
	{{ .speed_y = 0, .speed_x = 0}},
};


//----------------------------------------------------------------------------
void player_draw(void)
{
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(player.y, player.x);

	scale_beam(13);
	
	if(current_game.difficulty ==1)//switch player with beer 
	{
		if(player.momentum == STANDING)
		{
			if(player.draw_state == STAND_LEFT)
			{
				player.draw_state = BEER_LEFT;
			}
			else if(player.draw_state == STAND_RIGHT)
			{
				player.draw_state = BEER_RIGHT;
			}
		}
		else if((player.momentum == RISING) | (player.momentum == FALLING))
		{
			if(player.draw_state == JUMP_LEFT)
			{
				player.draw_state = BEER_LEFT;
			}
			else if(player.draw_state == JUMP_RIGHT)
			{
				player.draw_state = BEER_RIGHT;
			}
		}
	}
	else if(current_game.difficulty == 3 && player.speed_x != 0)//invert player drawing
	{
		if(player.momentum == STANDING)
		{
			if(player.draw_state == STAND_LEFT)
			{
				player.draw_state = STAND_RIGHT;
			}
			else if(player.draw_state == STAND_RIGHT)
			{
				player.draw_state = STAND_LEFT;
			}
		}
		else if((player.momentum == RISING) | (player.momentum == FALLING))
		{
			if(player.draw_state == JUMP_LEFT)
			{
				player.draw_state = JUMP_RIGHT;
			}
			else if(player.draw_state == JUMP_RIGHT)
			{
				player.draw_state = JUMP_LEFT;
			}
		}
	}
	
	switch(player.draw_state)
	{
		case STAND_LEFT:
			Draw_VLp((void*)&drunkard_l[0]);
			break;
			
		case STAND_RIGHT:
			Draw_VLp((void*)&drunkard_r[0]);
			break;
			
		case JUMP_LEFT:
			Draw_VLp((void*)&drunkard_jump_l[0]);
			break;
			
		case JUMP_RIGHT:
			Draw_VLp((void*)&drunkard_jump_r[0]);
			break;
			
		case BEER_LEFT:
			Draw_VLp((void*)&beer_l[0]);
			break;				
			
		case BEER_RIGHT:
			Draw_VLp((void*)&beer_r[0]);
			break;
			
		default:
			Draw_VLp((void*)&plattform_middle[0]);
			break;
	}
	
	
}

void player_get_controlls(void)
{
	Joy_Digital();
	if (joystick_1_down())
	{
		
	}
	else if (joystick_1_up())
	{
		
	}

	if (joystick_1_left())
	{
		if(player.speed_x > -3)
		{
			player.speed_x -= 1;			
		}
		
		if((player.momentum == RISING) | (player.momentum == FALLING))
		{
			player.draw_state = JUMP_LEFT;
		}
		else
		{
			player.draw_state = STAND_LEFT;
		}
		
	}
	else if (joystick_1_right())
	{
		if(player.speed_x < 3)
		{
			player.speed_x += 1;			
		}
		//player.speed_x = 1;
		
		if((player.momentum == RISING) | (player.momentum == FALLING))
		{
			player.draw_state = JUMP_RIGHT;
		}
		else
		{
			player.draw_state = STAND_RIGHT;
		}
	}
	else
	{
		player.speed_x = 0;
	}
		
	//Buttons-------------------------------------------------------
	check_buttons();
	if(button_1_1_pressed())
	{
		
	}
	if(button_1_2_pressed())
	{
		
	}
	if(button_1_3_pressed())
	{

		
	}
	if(button_1_4_pressed())
	{
		//switch state and set initial jump-speed
		
		
		if(player.momentum == STANDING)
		{
			player.momentum = RISING;
			play_music(&jumping);
			
			
			if(player.draw_state == STAND_LEFT )
			{
				player.draw_state = JUMP_LEFT;
			}
			else
			{
				player.draw_state = JUMP_RIGHT;
			}
			player.speed_y = 2;
			
		}
	}
}

void player_create(void)
{
	if(current_game.difficulty != 2)
	{
		player.x = -100;
		player.y = -126;
	}
	
	player.speed_yx = 0;
	
	player.draw_state = STAND_RIGHT;
	player.live = ALIVE;
	player.momentum = STANDING;
	player.falling_dist = 0;
}

void player_move(int y, int x)
{	
	//is player jumping or mid-air --> controll jump/y speed
	if((player.momentum == RISING) | (player.momentum == FALLING))
	{
		speed_cnt_y --;
	
		if(speed_cnt_y == 0)
		{
			if(player.speed_y > -3)
			{
				player.speed_y --;
				
				if(player.speed_y < 0)
				{
					player.momentum = FALLING;
				}
			}
			speed_cnt_y = speed_cnt_std;
		}
			
	}
	else
	{
		speed_cnt_y = speed_cnt_std;
	}
	
	//player is falling, add distance to over all falling distance
	if(player.speed_y < 0)
	{
		player.falling_dist = player.falling_dist + (unsigned int)(player.speed_y * -1);
	}
	
	//calculate new y position, for check if player reaches over the top
	unsigned int new_y = 0;
	if((player.y > 116) & (player.momentum != STANDING))
	{
		new_y = (unsigned int)(player.y + player.speed_y);
		
	}
	
	//var for inverting without inverting original speed
	int player_add_x = player.speed_x;
	
	//if difficulty = 3, invert x values
	if(current_game.difficulty == 3)
	{
		player_add_x *= -1;
	}
	
	//check if player reaches top
	if(new_y > 118)
	{
		player.y = 118;
		player.momentum = FALLING;
		player.x += (player_add_x + x);
	}
	else
	{
		player.x += (player_add_x + x);
		player.y += player.speed_y + y;
	}
	

}

void player_check_death()
{
	unsigned int death_threshold = 85;
	//if player was falling and is now standing again check the falling distance 
	if((player.falling_dist != 0) & (player.momentum == STANDING))
	{
		if(player.falling_dist > death_threshold)
		{
			player.live = DEAD;
		}
		else
		{
			player.falling_dist = 0;
		}
	}
}

void player_update(void)
{
	player_get_controlls();
	player_check_death();
	player_draw();
}


unsigned int player_check_BottomUp(void)
{
	//if(player.x > 118)
	//{
		//player.x = 118;
	//}
	if(player.y <= -126) //player on or below ground
	{
		if(player.momentum == FALLING)
		{
			play_music(&landing);
		}
		
		player.y = -126;
		player.speed_y = 0;
		speed_cnt_y = speed_cnt_std;
		
		player.momentum = STANDING;
		
		if(player.draw_state == JUMP_LEFT)
		{
			player.draw_state = STAND_LEFT;
		}
		else if(player.draw_state == JUMP_RIGHT)
		{
			player.draw_state = STAND_RIGHT;
		}
		return 1;
	}
	return 0;
}


