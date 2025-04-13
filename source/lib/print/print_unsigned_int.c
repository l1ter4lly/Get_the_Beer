// ***************************************************************************
// print
// ***************************************************************************

#include <vectrex.h>
#include "utils/utils.h"
#include "print.h"

// ---------------------------------------------------------------------------
// print decimal unsigned int value at absolute coordinates (y, x)

void print_unsigned_int(int y, int x, unsigned int z)
{
	volatile char message[4];
	message[3] = '\x80';
	unsigned int i = 2;
	do
	{
		message[i--] = (char) ('0' + z % 10);
		z = z / 10;
	}
	while (i != 255);	
	position_beam_s(y, x, 0x7F);
	Print_Str((void*) &message[0]);
}

// ***************************************************************************
// end of file
// ***************************************************************************
