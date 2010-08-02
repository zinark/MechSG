#include <gtest/gtest.h>
#include "Player.h"
#include "Statistics.h"
#include "Monster.h"
#include "PlayerFactory.h"
#include "MonsterFactory.h"

using namespace CRPG;

TEST (Player, Construction)
{
    Player player = Player("P1")
        .WithStat (Statistics().SetHitPoint(100).SetAccuracy(10).SetArmor(10));

    EXPECT_EQ (100, player.Statistics ().HitPoint());
    EXPECT_EQ ("P1", player.Name());
}

TEST (Player, CanAttackToAnyMonster)
{
    Player p1 = PlayerFactory::Instance().Create("human");
    Monster m = MonsterFactory::Instance().Create("goblin");

    p1.Attack (m);
}