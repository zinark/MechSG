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
        .WithStat (Statistics().HitPoint (10).Accuracy (5).Armor (10))
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
    EXPECT_EQ (&monster, &(monster.Weaponed(Weapon())));
}

TEST (Monster, CanTakeDamage)
{
    Monster m = Monster ("foo", 100).WithStat (Statistics().HitPoint(50));
    m.TakeDamage (50);

    EXPECT_EQ (0, m.Statistics ().HitPoint ());
}

TEST (Monster, CanDie)
{
    Monster m = Monster ("m", 100).WithStat(Statistics().HitPoint(5));
    EXPECT_EQ (false, m.IsDie ());
    m.TakeDamage(5);
    EXPECT_EQ (true, m.IsDie());
}

TEST (Monster, CanAttack)
{
    Monster m = Monster ("m", 50)
        .Weaponed(Weapon("Sword", Range(1,6)))
        .WithStat(Statistics().HitPoint(5).Accuracy(12).Armor(5));
    Player player = Player ("P1").WithStat(Statistics().HitPoint(10).Armor(5).Accuracy(10));
    m.Attack (player);
}