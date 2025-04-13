#include <vectrex.h>
#include "utils/vector.h"
#include "print/print.h"
#include "utils/controller.h"
#include "utils/utils.h"
#include "game.h"
#include "player.h"
#include "level.h"

#include "tunes.h"

#define toggle_value 50

char score[6];

struct game_t current_game =
{
	.lives = 0,
	.level = 0,
	.difficulty = 0,
	.score = { 0, 0},
	.high_score = {0,0,99,99},
	.state = STOPPED,
};

void game_init(void)
{
	// activate first joystick, switch off second joystick
	enable_controller_1_x();
	enable_controller_1_y();
	disable_controller_2_x();
	disable_controller_2_y();
	
	// set player data
	current_game.lives = 3; 
	current_game.level = 1;
	current_game.difficulty = 0;
	current_game.score[0] = 0;   //minutes
	current_game.score[1] = 0;	//seconds
	current_game.state = RUNNING;	

}

unsigned int check_new_high_score()
{	
	if(current_game.high_score[0] <= current_game.difficulty)
	{

		if(current_game.high_score[1] <= current_game.level)
		{
			
			if(current_game.high_score[2] >= current_game.score[0])
			{
				
				if(current_game.high_score[3] >= current_game.score[1])
				{
					return 1;
				}
			}
		}
	}
	
	return 0;
}

void save_high_score()
{
	current_game.high_score[0] = current_game.difficulty;
	current_game.high_score[1] = current_game.level;
	current_game.high_score[2] = current_game.score[0];
	current_game.high_score[3] = current_game.score[1];
}

void format_time(unsigned int m, unsigned int s)
{
	unsigned int minutes = m;
	unsigned int seconds = s;
	unsigned cnt = 5;
	
	score[cnt] = '\x80';
	cnt = cnt-1;
	
	unsigned int temp_seconds = seconds;

	do
	{

		score[cnt] = '0' + ((char) (seconds %10));
		seconds = seconds / 10;
		cnt = cnt -1;
		
	}while(seconds != 0);
	
	if(temp_seconds <= 9)
	{
		score[cnt] = '0';
		cnt--;
	}
	
	score[cnt] = ':';
	cnt --;
	
	
	unsigned int temp_minutes = minutes;
	
	do
	{
		score[cnt] = '0' + ((char) (minutes %10));
		minutes = minutes / 10;
		cnt = cnt - 1;
		
	}while(minutes != 0);

	if(temp_minutes <= 9)
	{
		score[cnt] = '0';
	}

}

//screen for game lost
void game_lost()
{
	current_game.state = STOPPED;
	
	unsigned int new_high = 0;
	new_high = check_new_high_score();
	
	if(new_high)
	{
		save_high_score();
	}
	
	format_time(current_game.score[0], current_game.score[1]);
	
	unsigned int button = 0;
	unsigned int toggle = toggle_value;
	do
	{
		Wait_Recal();
		print_string(110, -60, "YOU LOST !\x80");
		if(new_high == 1)
		{
			print_string(90, -80, "NEW RECORD !\x80");
		}
		else
		{
			print_string(90, -60, "HIGH SCORE:\x80");
		}
		
		print_string(64, -120, "DRUNKENNESS:\x80");
		print_unsigned_int(64,30, current_game.high_score[0]);
		
		print_string(32, -120, "LEVEL:\x80");
		print_unsigned_int(32,30, current_game.high_score[1]);
						
		print_string(0, -120, "TIME:\x80");
		Print_Str_d(0, 30, &score[0]);
		
		if(toggle <= (toggle_value/2))
		{
			print_string(-120, -100, "TRY AGAIN PRESS 1\x80");
			if(toggle == 0)
			{
				toggle = toggle_value;				
			}
		}
		toggle --;
		
		check_buttons();
		if(button_1_1_pressed())
		{
			button = 1;
		} 
	
		
	}while(button == 0);

}

void game_won()
{
	current_game.state = STOPPED;
	
	unsigned int new_high = 0;
	new_high = check_new_high_score();
	
	if(new_high)
	{
		save_high_score();
	}
	
	format_time(current_game.score[0], current_game.score[1]);
	
	unsigned int button = 0;
	unsigned int toggle = toggle_value;
	do
	{
		Wait_Recal();
		print_string(110, -60, "YOU WON !\x80");
		if(new_high == 1)
		{
			print_string(90, -80, "NEW RECORD !\x80");
		}
		else
		{
			print_string(90, -60, "HIGH SCORE:\x80");
		}
		
		print_string(64, -120, "DRUNKENNESS:\x80");
		print_unsigned_int(64,30, current_game.high_score[0]);
		
		print_string(32, -120, "LEVEL:\x80");
		print_unsigned_int(32,30, current_game.high_score[1]);
						
		print_string(0, -120, "TIME:\x80");
		Print_Str_d(0, 30, &score[0]);
		
		if(toggle <= (toggle_value/2))
		{
			print_string(-120, -100, "TRY AGAIN PRESS 1\x80");
			if(toggle == 0)
			{
				toggle = toggle_value;				
			}
		}
		toggle --;
		
		check_buttons();
		if(button_1_1_pressed())
		{
			button = 1;
		} 
	
		
	}while(button == 0);
	
}

//screen for start
void game_start_screen()
{
	format_time(current_game.high_score[2], current_game.high_score[3]);
	
	unsigned int button = 0;
	unsigned int toggle = toggle_value;
	do
	{
		Wait_Recal();

		print_string(90, -60, "HIGH SCORE:\x80");
		
		print_string(64, -120, "DRUNKENNESS:\x80");
		print_unsigned_int(64,30, current_game.high_score[0]);
		
		print_string(32, -120, "LEVEL:\x80");
		print_unsigned_int(32,30, current_game.high_score[1]);
						
		print_string(0, -120, "TIME:\x80");
		Print_Str_d(0, 30, &score[0]);
		
		if(toggle <= (toggle_value/2))
		{
			print_string(-120, -80, "START PRESS 1\x80");
			if(toggle == 0)
			{
				toggle = toggle_value;				
			}
		}
		toggle --;
		
		check_buttons();
		if(button_1_1_pressed())
		{
			button = 1;
			stop_explosion();
		} 
	
		
	}while(button == 0);
	

}

void level_start_screen()
{
	
	unsigned int delay = 100;
	format_time(current_game.score[0], current_game.score[1]);
	
	
	
	while(delay != 0)
	{
		Wait_Recal();
		
		if(current_game.lives < 3)
		{
			print_string(100, -80, "LIVE LOST!\x80");
			print_unsigned_int(64,30, current_game.difficulty);
		}
		else
		{
			print_string(100, -80, "GET READY!\x80");
			print_unsigned_int(64,30, current_game.difficulty);
		}

		print_string(64, -120, "DRUNKENNESS:\x80");
		print_unsigned_int(64,30, current_game.difficulty);
		
		print_string(32, -120, "LEVEL:\x80");
		print_unsigned_int(32,30, current_game.level);

		print_string(0, -120, "LIVES:\x80");
		print_unsigned_int(0,30, current_game.lives);
		
		print_string(-32, -120, "TIME:\x80");
		Print_Str_d(-32, 30, &score[0]);

		delay--;
	}
}

//game loop, starts level, checks level 
void game_play(void)
{
		game_start_screen();
		game_init();
		while(current_game.state == RUNNING)
		{
			level_start_screen();
			level_play();
					
			if(current_level.state == WON)
			{
				if(current_game.level == 5)
				{				
					if(current_game.difficulty == 3)
					{
						game_won();		//game won, safe time
					}
					else
					{
						current_game.difficulty ++;
						current_game.level = 1;
					}									
				}
				else
				{
					current_game.level ++;
				}
				
				
			}
			else if(current_level.state == LOST)
			{
				current_game.lives --;
				if(current_game.lives == 0)
				{
					game_lost();
				}
			}
		}
			

}

int game(void)
{

	if (1)
	{
		
		game_play();
		return 0;		// go to option screen, repeat cycle
	}
	else
	{
		return -1; 		// jump to title screen
	}
}
