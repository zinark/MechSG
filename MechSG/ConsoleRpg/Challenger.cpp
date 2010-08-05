#include "Challenger.h"

bool Challenger::IsDie()
{
    return _Statistics.HitPoint() <= 0;
}

void Challenger::TakeDamage( int damageQuantity )
{
    _Statistics.SetHitPoint(_Statistics.HitPoint() - damageQuantity);
}
