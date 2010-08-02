#include <iostream>
#include <gtest/gtest.h>
#include "Weapon.h"
#include "Statistics.h"
#include "Monster.h"
#include "Player.h"

using namespace CRPG;
using namespace std;

TEST (Monster, ConstructionOfAMonster)
{
    int xpReward = 100;
    Monster monster = Monster ("Orc", xpReward)
        .WithStat (Statistics().SetHitPoint (10).SetAccuracy (5).SetArmor (10))
        .Weaponed (Weapon ("Sword", Range(1,6)));

    EXPECT_EQ (100, monster.XpReward ());
    EXPECT_EQ ("Orc", monster.Name ());
    EXPECT_EQ ("Sword", monster.EquippedWeapon().Name());
    EXPECT_EQ (10, monster.Statistics().HitPoint());
}

TEST (Monster, ReferenceAddressesShouldBeTheSameOnFluenting)
{
    Monster monster ("X", 1);

    EXPECT_EQ (&monster, &(monster.WithStat (Statistics ())));
    EXPECT_EQ (&monster, &(monster.Weaponed (Weapon())));
}

TEST (Monster, CanTakeDamage)
{
    Monster m = Monster ("foo", 100).WithStat (Statistics().SetHitPoint(50));
    m.TakeDamage (50);

    EXPECT_EQ (0, m.Statistics ().HitPoint ());
}

TEST (Monster, CanDie)
{
    Monster m = Monster ("m", 100).WithStat(Statistics().SetHitPoint(5));
    EXPECT_EQ (false, m.IsDie ());
    m.TakeDamage(5);
    EXPECT_EQ (true, m.IsDie());
}

TEST (Monster, Attack_HitAndDamageRolls)
{
    Monster m = Monster ("m", 50)
        .Weaponed(Weapon("Sword", Range(1,6)))
        .WithStat(Statistics()
            .SetHitPoint(5)
            .SetAccuracy(12)
            .SetArmor(5));
    
    Player p1 = Player ("P1")
        .WithStat(Statistics()
            .SetHitPoint(10)
            .SetArmor(5)
            .SetAccuracy(10));
    
    int hitRoll = 0;
    int damageRoll = 0;
    bool result = m.Attack (p1, hitRoll, damageRoll);

    int expectedPlayerHitPoint = p1.Statistics ().HitPoint () - damageRoll;
    EXPECT_EQ (expectedPlayerHitPoint, p1.Statistics().HitPoint());
    
    EXPECT_GE (20, hitRoll);
    EXPECT_LE (1, hitRoll);

    EXPECT_GE (6, damageRoll);
    EXPECT_LE (0, damageRoll);
}

TEST (Monster, Attack_ToPlayer_CalculatingDamage)
{

}


