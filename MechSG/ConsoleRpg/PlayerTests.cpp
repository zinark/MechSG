#include <gtest/gtest.h>
#include "Player.h"
#include "Statistics.h"

using namespace CRPG;

TEST (Player, Construction)
{
    Player player = Player("P1")
        .WithStat (Statistics().HitPoint(100).Accuracy(10).Armor(10));

    EXPECT_EQ (100, player.Statistics ().HitPoint());
    EXPECT_EQ ("P1", player.Name());
}