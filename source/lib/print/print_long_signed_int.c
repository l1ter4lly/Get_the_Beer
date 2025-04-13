// ***************************************************************************
// print
// ***************************************************************************

#include <vectrex.h>
#include "utils/utils.h"
#include "print.h"

// ---------------------------------------------------------------------------
// print decimal unsigned long int value at absolute coordinates (y, x)

void print_long_signed_int(int y, int x, signed long int z)
{
	volatile char message[7];
	message[0] = (z < 0) ? (char) 0x2d : (char) 0x2b;
	message[6] = '\x80';
	unsigned int i = 5;
	long unsigned int u = (z < 0) ? (65535u - (((long unsigned int) z) - 1u)) : (long unsigned int) z;
	do
	{
		message[i--] = (char) ('0' + (u % 10));
		u = u / 10;
	}
	while (i > 0);	
	position_beam_s(y, x, 0x7F);
	Print_Str((void*) &message[0]);
}

// ***************************************************************************
// end of file
// ***************************************************************************
