#pragma once

// ---------------------------------------------------------------------------
enum game_state
{
	RUNNING,
	STOPPED,
};

struct game_t
{
	unsigned int lives;
	unsigned int level;
	unsigned int difficulty;
	unsigned int score[2];
	unsigned int high_score[4];
	enum game_state state;
};

// ---------------------------------------------------------------------------

extern struct game_t current_game;

// ---------------------------------------------------------------------------

int game();

void game_init();
void game_play();

void game_start_screen();

void game_lost();
void game_won();

void save_high_score();
unsigned int check_new_high_score();


