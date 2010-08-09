#include <gtest/gtest.h>
#include "IChallenger.h"
#include "Player.h"
#include <iostream>
#include "PlayerFactory.h"
#include "MonsterFactory.h"

using namespace CRPG;
using namespace std;

TEST (Challenger, PlayerIsAChallenger)
{
    IChallenger* challenger = new Player ("P1");
    challenger->WithStat (Statistics ().SetMaxHitPoint(20));
    challenger->Weaponed (Weapon("club", Range(1,2)));

    EXPECT_EQ ("P1", challenger->Name());
    EXPECT_EQ (20, challenger->GetStatistics ().MaxHitPoint());

    delete challenger;
}

TEST (Challenger, PolymorphicRelationOnMonsterAndPlayer)
{
    IChallenger& p = PlayerFactory::Instance().Create("fighter");
    IChallenger& m = MonsterFactory::Instance().Create("goblin");

    EXPECT_EQ ("FIGHTER", p.Name());
    EXPECT_EQ ("GOBLIN", m.Name());
}

TEST (Challenger, ChallengerCanTakeDamageAndDie)
{
    IChallenger& c = Player ("q");
    c = c
        .WithStat (Statistics ().SetMaxHitPoint(10).SetMaxHitPoint(10))
        .Weaponed (Weapon ("club", Range (1,2)));

    c.TakeDamage(10);

    EXPECT_EQ (true, c.IsDie ());
}

TEST (Challenger, AbstractChallengerImplementationForPlayer)
{
    Player& player = PlayerFactory::Instance().Create("fighter");
    Challenger& challenger = PlayerFactory::Instance().Create("fighter");

    EXPECT_EQ (
        player.Name (), 
        challenger.Name ());

    EXPECT_EQ (
        player.GetWeapon ().Name (), 
        challenger.GetWeapon ().Name());

    EXPECT_EQ (
        player.GetWeapon ().DamageRange ().HighRange (), 
        challenger.GetWeapon ().DamageRange().HighRange());
    
    EXPECT_EQ (
        player.GetWeapon ().DamageRange ().LowRange (), 
        challenger.GetWeapon ().DamageRange().LowRange());

    EXPECT_EQ (
        player.GetStatistics().HitPoint(), 
        challenger.GetStatistics().HitPoint());
}