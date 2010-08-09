#include "Weapon.h"

CRPG::Weapon::Weapon (void)
{
    _Name = "";
    _Range = Range(1,1);
}

CRPG::Weapon::Weapon( string name, Range& range )
{
    _Name = name;
    _Range = range;
}
CRPG::Weapon::~Weapon(void)
{
}
