#include "utils/collision.h"
#include "utils/utils.h"
#include "figure.h"
#include "platform.h"
#include "player.h"
#include "game.h"



void platform_update(struct platform_t* p)
{
	if(p->state == MOBILE)
	{
		if(p->travelled_dist >= p->max_travel_dist)
		{
			p->speed_x *= -1;
			p->speed_y *= -1; 
			p->travelled_dist = 0;
		} 
		
		//if(current_game.difficulty == 2)
		//{
			//p->x = p->x + (p->speed_x * 2);
			//p->y = p->y + (p->speed_y * 2);
			//p->travelled_dist += 2;
		//}
		//else
		//{
			p->x = p->x + p->speed_x ;
			p->y = p->y + p->speed_y ;
			p->travelled_dist++;
		//}

		
		if(p->y > 118)
		{
			p->y = 118;
			p->speed_y *= -1;
			p->travelled_dist = 0;
		}
	
	}
}

void platform_draw(struct platform_t* p)
{
	Reset0Ref();				
	dp_VIA_t1_cnt_lo = 0x7f;	
	Moveto_d(p->y, p->x);		

	scale_beam(13);
	switch(p->size)
	{
		case LARGE:
			Draw_VLp(&plattform_large);
			break;
			
		case MIDDLE:
			Draw_VLp(&plattform_middle);
			break;
			
		default:
			break;
	}
	dp_VIA_t1_cnt_lo = 0x7f;

}

int platform_check(struct platform_t* p)
{
	if(p->size == LARGE)
	{
		if(check_collision(player.y, player.x, p->y, p->x, 2, 12))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(p->size == MIDDLE)
	{
		if(check_collision(player.y, player.x, p->y, p->x, 1, 4))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}


}
