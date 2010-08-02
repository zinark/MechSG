#include "Statistics.h"
#include <stdexcept>
using namespace std;
using namespace CRPG;

Statistics::Statistics(void)
{
    _HitPoint =0;
    _Armor = 0;
    _Accuracy = 0;
    _MaxHitPoint = 0;
}


Statistics::~Statistics(void)
{
}

Statistics& Statistics::SetHitPoint( int value )
{
    _HitPoint = value;
    return *this;
}

Statistics& Statistics::SetAccuracy( int value )
{
    if (value > 20) throw invalid_argument ("Value should not be greater than 20");
    _Accuracy = value;
    return *this;
}

Statistics& Statistics::SetArmor( int value )
{
    _Armor = value;
    return *this;
}

Statistics& Statistics::SetMaxHitPoint( int value )
{
    _MaxHitPoint = value;
    return *this;
}

Statistics& Statistics::SetLevel( int value )
{
    _Level = value;
    return *this;
}
