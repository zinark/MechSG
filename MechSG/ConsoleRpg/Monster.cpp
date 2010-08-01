#include "Monster.h"
#include "Dice.h"
#include <iostream>
using namespace std;
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


Monster& CRPG::Monster::WithStat( const CRPG::Statistics& statistics )
{
    _Statistics = statistics;
    return *this;
}

Monster& CRPG::Monster::Weaponed( const Weapon& weapon )
{
    _Weapon = weapon;
    return *this;
}

void CRPG::Monster::TakeDamage( int damagePoint )
{
    _Statistics.HitPoint(_Statistics.HitPoint() - damagePoint);
}

void CRPG::Monster::Attack( Player& player )
{
    Dice hitDice (Range(1,20));
    Dice damageDice (_Weapon.DamageRange());
    int hitRoll = hitDice.Roll();
    if (_Statistics.Accuracy() > hitRoll)
    {
        int damageRoll = damageDice.Roll();
    }
}

