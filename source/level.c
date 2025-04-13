#include <vectrex.h>
#include "utils/utils.h"
#include "print/print.h"
#include "level.h"
#include "player.h"
#include "game.h"
#include "figure.h"
#include "tunes.h"

struct level_t current_level =
{
	.state = LOST,
};

void level_init()
{
	current_level.state = PLAY;
	
	if(current_game.difficulty == 2)
	{
		switch(current_game.level)
		{
			case 1:
				current_level.current_map = map_1;
				break;
				
			case 2:
				current_level.current_map = map_2;
				break;
				
			case 3:
				current_level.current_map = map_3;
				break;
				
			case 4:
				current_level.current_map = map_4;
				break;
				
			case 5:
				current_level.current_map = map_5;
				break;
				
			default:
				break;	
		}
		
		int temp_x = current_level.current_map.target_x;
		int temp_y = current_level.current_map.target_y;
		current_level.current_map.target_x = player.x;
		current_level.current_map.target_y = player.y;
		player.x = temp_x;
		player.y = temp_y;
		
	}
	else
	{
		switch(current_game.level)
		{
			case 1:
				current_level.current_map = map_1;
				break;
				
			case 2:
				current_level.current_map = map_2;
				break;
				
			case 3:
				current_level.current_map = map_3;
				break;
				
			case 4:
				current_level.current_map = map_4;
				break;
				
			case 5:
				current_level.current_map = map_5;
				break;
				
			default:
				
				break;			
		}
	}
	
}

void save_time_to_game(unsigned int m, unsigned int s)
{
	current_game.score[0] += m;
	
	unsigned int current_seconds = current_game.score[1];
	if((s + current_seconds) >= 60)
	{
		current_game.score[0] += 1;
		current_game.score[1] = (s + current_seconds) - 60;
	}
	else
	{
		current_game.score[1] += s;
	}
}

void level_play()
{
	level_init();
	player_create();
	
	unsigned int frames = 0;
	unsigned int seconds = 0;
	unsigned int minutes = 0;
	
	while(current_level.state == PLAY)
	{
		
		//Wait_Recal();	
		sync();
		
		frames ++;
		
		if(frames == 50)
		{
			frames = 0;
			
			if(seconds == 59)
			{
				minutes++;
				seconds = 0;
			}
			else
			{
				seconds++;
			}
		}
		
		if(current_game.difficulty == 1)
		{
			if(seconds <= 9)
			{
				switch(seconds)
				{
					case 0:
						Intensity_3F();
						break;
					case 1:
						Intensity_3F();
						break;
					case 2:
						Intensity_3F();
						break;
					case 3:
						Intensity_5F();
						break;
					case 4:
						Intensity_5F();
						break;
					case 5:
						Intensity_5F();
						break;
					case 6:
						Intensity_5F();
						break;
					case 7:
						Intensity_7F();
						break;
					case 8:
						Intensity_7F();
						break;
					case 9:
						Intensity_7F();
						break;
					default:
						Intensity_5F();
						break;
				}
				
			}
			else
			{
				switch(seconds/10)
				{
					case 0:
						Intensity_3F();
						break;
					case 1:
						Intensity_3F();
						break;
					case 2:
						Intensity_3F();
						break;
					case 3:
						Intensity_5F();
						break;
					case 4:
						Intensity_5F();
						break;
					case 5:
						Intensity_5F();
						break;
					case 6:
						Intensity_5F();
						break;
					case 7:
						Intensity_7F();
						break;
					case 8:
						Intensity_7F();
						break;
					case 9:
						Intensity_7F();
						break;
					default:
						Intensity_5F();
						break;
				}
			}
		}
		else
		{
			Intensity_5F();
		}
		
		player_update();
		map_update(&current_level.current_map);
		map_draw(&current_level.current_map);
			
		int dynamic_number = -1;
		
		//if not on ground, check plattforms	
		if(player.momentum != RISING)
		{
			if(player_check_BottomUp() == 0)
			{
			
				if((player.momentum == FALLING) | (player.momentum == STANDING))
				{
					dynamic_number = map_check(&current_level.current_map);
				}

			}
		}
		
		if(dynamic_number == -1)
		{
			player_move(0,0);		
		}
		else
		{
			player_move(current_level.current_map.platform_list_dynamic[dynamic_number].speed_y,
						current_level.current_map.platform_list_dynamic[dynamic_number].speed_x);
		}
		
		if(map_check_target(&current_level.current_map))
		{
			if(current_game.difficulty == 2)
			{
				player.x = -100;
				player.y = -126;
			}
			Clear_Sound();
			stop_music();
			current_level.state = WON;
			save_time_to_game(minutes, seconds);
		}

		
		if(player.live == DEAD)
		{
			if(current_game.difficulty == 2)
			{
				player.x = -100;
				player.y = -126;
			}
			Clear_Sound();
			stop_music();
			current_level.state = LOST;
			save_time_to_game(minutes, seconds);
		}
		
		
	}
	

	
}
