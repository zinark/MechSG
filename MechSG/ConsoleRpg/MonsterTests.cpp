#include <gtest/gtest.h>
#include "Weapon.h"
#include "Statistics.h"
#include "Monster.h"

using namespace CRPG;

TEST (Monster, ConstructionOfAMonster)
{
    int xpReward = 100;
    
    Statistics stat = Statistics ()
        .HitPoint (10)
        .Accuracy (5)
        .Armor (10);

    Weapon weapon ("Sword", Range(1,6));
    
    Monster monster = Monster ("Orc", xpReward)
        .Statisticed (stat)
        .Weaponed (weapon);

    EXPECT_EQ (100, monster.XpReward ());
    EXPECT_EQ ("Orc", monster.Name ());
    EXPECT_EQ ("Sword", monster.EquippedWeapon().Name());
    EXPECT_EQ (10, monster.Statistics().HitPoint());
}