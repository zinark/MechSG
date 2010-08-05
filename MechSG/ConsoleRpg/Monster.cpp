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


Monster& Monster::WithStat( const CRPG::Statistics& statistics )
{
    _Statistics = statistics;
    return *this;
}

Monster& Monster::Weaponed( const Weapon& weapon )
{
    _Weapon = weapon;
    return *this;
}

void Monster::TakeDamage( int damagePoint )
{
    _Statistics.SetHitPoint(_Statistics.HitPoint() - damagePoint);
}

void Monster::Attack( Player& player )
{
    Dice hitDice (Range(1,20));
    Dice damageDice (_Weapon.DamageRange());
    int hitRoll = hitDice.Roll();
    if (_Statistics.Accuracy() > hitRoll)
    {
        int damageRoll = damageDice.Roll();
        int damage = damageRoll - player.GetStatistics().Armor();
        if (damage < 0) damage = 0;
        player.TakeDamage(damage);
    }
}

bool Monster::Attack( Player& player, int& hitRoll, int& damageRoll )
{
    Dice hitDice (Range(1,20));
    Dice damageDice (_Weapon.DamageRange());
    hitRoll = hitDice.Roll();
    if (_Statistics.Accuracy() > hitRoll)
    {
        damageRoll = damageDice.Roll();
        int damage = damageRoll - player.GetStatistics().Armor();
        if (damage < 0) damage = 0;
        player.TakeDamage(damage);
        return true;
    }
    return false;
}

