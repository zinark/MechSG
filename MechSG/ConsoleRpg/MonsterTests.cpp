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
    Monster& monster = Monster ("Orc", xpReward);
    monster.WithStat (Statistics().SetHitPoint (10).SetAccuracy (5).SetArmor (10));
    monster.Weaponed (Weapon ("Sword", Range(1,6)));
    
    EXPECT_EQ (100, monster.XpReward ());
    EXPECT_EQ ("Orc", monster.Name ());
    EXPECT_EQ ("Sword", monster.GetWeapon().Name());
    EXPECT_EQ (10, monster.GetStatistics().HitPoint());
}

TEST (Monster, ReferenceAddressesShouldBeTheSameOnFluenting)
{
    Monster monster ("X", 1);

    EXPECT_EQ (&monster, &(monster.WithStat (Statistics ())));
    EXPECT_EQ (&monster, &(monster.Weaponed (Weapon())));
}

TEST (Monster, CanTakeDamage)
{
    Monster& m = Monster ("foo", 100);
    m.WithStat (Statistics().SetHitPoint(50));
    m.TakeDamage (50);

    EXPECT_EQ (0, m.GetStatistics ().HitPoint ());
}

TEST (Monster, CanDie)
{
    Monster& m = Monster ("m", 100);
    m.WithStat(Statistics().SetHitPoint(5));
    EXPECT_EQ (false, m.IsDie ());
    m.TakeDamage(5);
    EXPECT_EQ (true, m.IsDie());
}

TEST (Monster, AssertAfterUpCasting)
{
    Monster monster =(Monster&) Monster ("MONSTER", 100)
        .Weaponed(Weapon("Sword", Range(1,6)))
        .WithStat(Statistics()
        .SetHitPoint(5)
        .SetAccuracy(12)
        .SetArmor(5));

    string name = monster.Name();

    EXPECT_EQ ("MONSTER", monster.Name());
    EXPECT_EQ ("Sword", monster.GetWeapon().Name());
    EXPECT_EQ (1, monster.GetWeapon().DamageRange().LowRange ());
    EXPECT_EQ (6, monster.GetWeapon().DamageRange().HighRange ());
}

TEST (Monster, Attack_HitAndDamageRolls)
{
    Monster m = (Monster&) Monster ("m", 50)
        .Weaponed(Weapon("Sword", Range(1,6)))
        .WithStat(Statistics()
            .SetHitPoint(5)
            .SetAccuracy(12)
            .SetArmor(5));
    
    Player p1 = (Player&) Player ("P1")
        .WithStat(Statistics()
            .SetHitPoint(10)
            .SetArmor(5)
            .SetAccuracy(10));
    
    int hitRoll = 0;
    int damageRoll = 0;
    
    m.Attack (p1);

    //cout << "HIT ROLL " << hitRoll << endl;
    //cout << "DAMAGE ROLL " << damageRoll << endl;
    //cout << "PLAYER HP " << p1.GetStatistics().HitPoint () << endl;
        
    EXPECT_GE (20, m.GetLastHitRoll());
    EXPECT_LE (1, m.GetLastHitRoll());

    EXPECT_GE (6, m.GetLastDamageRoll());
    EXPECT_LE (0, m.GetLastDamageRoll());
}
