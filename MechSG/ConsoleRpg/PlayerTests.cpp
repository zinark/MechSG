#include <gtest/gtest.h>
#include "Player.h"
#include "Statistics.h"
#include "Monster.h"
#include "PlayerFactory.h"
#include "MonsterFactory.h"

using namespace CRPG;

TEST (Player, Construction)
{
    Player player = (Player&) Player("P1")
        .WithStat (Statistics().SetHitPoint(100).SetAccuracy(10).SetArmor(10));

    EXPECT_EQ (100, player.GetStatistics ().HitPoint());
    EXPECT_EQ ("P1", player.Name());
}

TEST (Player, CanAttackToAnyMonster)
{
    Player p1 = PlayerFactory::Instance().Create("fighter");
    Monster m = MonsterFactory::Instance().Create("goblin");
    p1.Attack (m);
}

TEST (Player, CanRun)
{
    Player p1 = PlayerFactory::Instance().Create("fighter");
}

TEST (Player, CanLevelup)
{
    Player p1 = PlayerFactory::Instance().Create("fighter");
    Statistics oldStat = p1.GetStatistics();
    p1.LevelUpIfApplicable ();
    Statistics newStat = p1.GetStatistics();

    EXPECT_GT (newStat.Accuracy (), oldStat.Accuracy ());
    EXPECT_GT (newStat.Armor(), oldStat.Armor ());
    EXPECT_GT (newStat.HitPoint(), oldStat.HitPoint());
    EXPECT_GT (newStat.MaxHitPoint(), oldStat.MaxHitPoint());
    
    EXPECT_EQ (1, newStat.Level() - oldStat.Level());
}

TEST (Player, CanRest)
{
    Player p1 = PlayerFactory::Instance().Create("fighter");
    p1.GetStatistics ().SetHitPoint (1);
    p1.Rest ();
    EXPECT_EQ (p1.GetStatistics().MaxHitPoint(), p1.GetStatistics().HitPoint());
}

TEST (Player, CanWinExperience)
{
    Player p1 = PlayerFactory::Instance().Create("fighter");
    p1.AddExperience (1000);
    EXPECT_EQ (2, p1.GetStatistics ().Level());
    EXPECT_EQ (4000, p1.NextLevelExperience());
}