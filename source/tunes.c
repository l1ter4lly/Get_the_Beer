// ***************************************************************************
// tunes
// ***************************************************************************

#include <vectrex.h>
#include "tunes.h"

// ---------------------------------------------------------------------------


const struct sound_adsr_table_t my_curve =
{
	.amplitude = { 0xED, 0xED, 0xA9, 0xA9, 0x99, 0x88, 0x77, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00, 0x00}	// 32 nibbles amplitude offsets
};

const struct sound_adsr_table_t my_curve_jumping =
{
	.amplitude = { 0x11, 0x33, 0x55, 0x77, 0x99, 0xA9, 0xED, 0xED, 0xA9, 0x77, 0x33, 0x11, 0x00, 0x00, 0x00, 0x00}	// 32 nibbles amplitude offsets
};

const struct sound_adsr_table_t my_curve_landing =
{
	.amplitude = { 0xFF, 0xFF, 0xED, 0xED, 0xA9, 0x99, 0x99, 0x77, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}	// 32 nibbles amplitude offsets
};

const struct sound_twang_table_t my_vibrato =
{
	.frequency = {-2, -1, 1, 2, 3, 3, 0, 0} // base frequency offsets
};

const struct sound_twang_table_t my_vibrato_landing =
{
	.frequency = {1, 1, 2, 3, 2, 1, 0, 0} // base frequency offsets
};


const struct sound_music_t landing = 
{
	.adsr_table = &my_curve_landing,   	//(struct sound_adsr_table_t*) &Vec_ADSR_FADE4,
	.twang_table = &my_vibrato_landing, //(struct sound_twang_table_t*) &Vec_TWANG_VIBEHL,
	{
		0, 12,
		0, 128		//0b10011000, 0b00000000, 0b10000000
	}
};

const struct sound_music_t bing = 
{
	.adsr_table = &my_curve,   	//(struct sound_adsr_table_t*) &Vec_ADSR_FADE4,
	.twang_table = &my_vibrato, //(struct sound_twang_table_t*) &Vec_TWANG_VIBEHL,
	{
		0, 12,
		0, 128
	}
};
const struct sound_music_t jumping = 
{
	.adsr_table = &my_curve_jumping,   	//(struct sound_adsr_table_t*) &Vec_ADSR_FADE4,
	.twang_table = &my_vibrato, //(struct sound_twang_table_t*) &Vec_TWANG_VIBEHL,
	{
		0b10001001, 
	}
};

const struct sound_explosion_t test =
{
	.enable = 0b00001001,				// noise (bits 5-3) and tone channel (bits 2-0) enable (0b00nnnccc), 
	.noise = SOUND_EXPL_RISE,			// noise source sweep, =0 up, >0 down, <0 inhibit  
	.volume = SOUND_VOL_RISE,			// volume sweep, =0 up, >0 down, <0 inhibit
	.duration = 128U,					// explosion duration, 0x01 longest to 0x80 shortest 
};


// -------------------------------------------------------------------------

// ***************************************************************************
// end of file
// ***************************************************************************
