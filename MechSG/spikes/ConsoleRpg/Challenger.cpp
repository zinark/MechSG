#include "Challenger.h"
#include "Dice.h"
using namespace CRPG;

bool Challenger::IsDie()
{
    return _Statistics.HitPoint() <= 0;
}

void Challenger::TakeDamage( int damageQuantity )
{
    _Statistics.SetHitPoint(_Statistics.HitPoint() - damageQuantity);
}

void Challenger::Attack( IChallenger& monster )
{
    Dice hitDice (Range(1,20));
    Dice damageDice (_Weapon.DamageRange());
    _LastHitRoll = hitDice.Roll();
    if (_Statistics.Accuracy() > _LastHitRoll)
    {
        _LastDamageRoll = damageDice.Roll();
        int damage = _LastDamageRoll - monster.GetStatistics().Armor();
        if (damage < 0) damage = 0;
        monster.TakeDamage(damage);
    }
}
