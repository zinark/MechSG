#include "Statistics.h"
#include <stdexcept>
using namespace std;
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
    if (value > 20) throw invalid_argument ("Value should not be greater than 20");
    _Accuracy = value;
    return *this;
}

CRPG::Statistics& CRPG::Statistics::Armor( int value )
{
    _Armor = value;
    return *this;
}
