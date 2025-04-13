// ***************************************************************************
// print
// ***************************************************************************

#include <vectrex.h>
#include "utils/utils.h"
#include "print.h"

// ---------------------------------------------------------------------------
// print decimal int value at absolute coordinates (y, x)

void print_signed_int(int y, int x, int z)
{
	volatile char message[5];
	message[0] = (z < 0) ? (char) 0x2d : (char) 0x2b;
	message[4] = '\x80';
	unsigned int i = 3;
	unsigned int u = (z < 0) ? (255u - (((unsigned int) z) - 1u)) : (unsigned int) z;
	do
	{
		message[i--] = (char) ('0' + u % 10);
		u = u / 10;
	}
	while (i > 0);	
	position_beam_s(y, x, 0x7F);
	Print_Str((void*) &message[0]);
}

// ***************************************************************************
// end of file
// ***************************************************************************
