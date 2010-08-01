#include "Statistics.h"


CRPG::Statistics::Statistics(void)
{
}


CRPG::Statistics::~Statistics(void)
{
}

CRPG::Statistics& CRPG::Statistics::HitPoint( int value )
{
    _HitPoint = value;
    return *this;
}

CRPG::Statistics& CRPG::Statistics::Accuracy( int value )
{
    _Accuracy = value;
    return *this;
}

CRPG::Statistics& CRPG::Statistics::Armor( int value )
{
    _Armor = value;
    return *this;
}
