#include "Range.h"


CRPG::Range::Range( int low, int high )
{
    _LowRange = low;
    _HighRange = high;
}

CRPG::Range::Range( void )
{
    Range (1,6);
}


CRPG::Range::~Range(void)
{
}
