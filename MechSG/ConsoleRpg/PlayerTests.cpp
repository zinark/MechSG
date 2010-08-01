#include <gtest/gtest.h>
#include "Player.h"
#include "Statistics.h"

using namespace CRPG;

TEST (Player, Construction)
{
    Player player = Player("P1")
        .WithStat (Statistics().SetHitPoint(100).SetAccuracy(10).SetArmor(10));

    EXPECT_EQ (100, player.Statistics ().HitPoint());
    EXPECT_EQ ("P1", player.Name());
}