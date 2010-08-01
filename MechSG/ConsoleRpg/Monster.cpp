#include "Monster.h"
using namespace CRPG;

CRPG::Monster::Monster( const string& name, int xpReward )
{
    _Name = name;
    _XpReward = xpReward;
}

CRPG::Monster::Monster()
{
    Monster ("", 0);
}

CRPG::Monster::~Monster( void )
{

}


Monster& CRPG::Monster::Statisticed( const CRPG::Statistics& statistics )
{
    _Statistics = statistics;
    return *this;
}

Monster& CRPG::Monster::Weaponed( const Weapon& weapon )
{
    _Weapon = weapon;
    return *this;
}

