#include "Monster.h"
#include "Dice.h"
#include <iostream>
using namespace std;
using namespace CRPG;

Monster::Monster( const string& name, int xpReward )
{
    _Name = name;
    _XpReward = xpReward;
}

Monster::Monster()
{
    _Name = "";
    _XpReward = 0;
}

Monster::~Monster( void )
{

}