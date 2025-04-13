// ***************************************************************************
// print
// ***************************************************************************

#include <vectrex.h>
#include "utils/utils.h"
#include "print.h"

// ---------------------------------------------------------------------------
// print decimal unsigned long int value at absolute coordinates (y, x)

void print_long_unsigned_int(int y, int x, unsigned long int z)
{
	volatile char message[6];
	message[5] = '\x80';
	unsigned int i = 4;
	do
	{
		message[i--] = (char) ('0' + (z % 10));
		z = z / 10;
	}
	while (i != 255);	
	position_beam_s(y, x, 0x7F);
	Print_Str((void*) &message[0]);
}

// ***************************************************************************
// end of file
// ***************************************************************************
