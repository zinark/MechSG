#include <gtest/gtest.h>
#include "Weapon.h"
using namespace CRPG;

TEST (Weapon, WeaponHasADamageRange)
{
    Weapon weapon ("Dagger", Range(1,4));
    EXPECT_EQ (4, weapon.DamageRange().HighRange());
    EXPECT_EQ (1, weapon.DamageRange().LowRange());
}

TEST (Weapon, WeaponHasAName)
{
    Weapon weapon ("Sword", Range(2,6));
    EXPECT_EQ ("Sword", weapon.Name ());
}