#include "Dice.h"
#include <ctime>
#include <cstdlib>

CRPG::Dice::Dice( Range& range )
{
    _Range = range;
    srand(time(0));
}

CRPG::Dice::Dice( void )
{
    Dice (Range(1,6));
}


CRPG::Dice::~Dice(void)
{
}

int CRPG::Dice::Roll()
{
    return _Range.LowRange() + rand() % (_Range.HighRange() + 1 - _Range.LowRange());
}

CRPG::Dice& CRPG::Dice::Ranged( CRPG::Range& range )
{
    _Range =range;
    return *this;
}
