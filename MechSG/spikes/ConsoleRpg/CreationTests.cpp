#include <gtest/gtest.h>
#include "MonsterFactory.h"
#include "Monster.h"
#include <iostream>
#include "PlayerFactory.h"
using namespace CRPG;
using namespace std;

TEST (Creation, MonsterFactory_Instances)
{
    EXPECT_EQ (&MonsterFactory::Instance(), &MonsterFactory::Instance());
    MonsterFactory& f1 = MonsterFactory::Instance();
    MonsterFactory& f2 = MonsterFactory::Instance();
    EXPECT_EQ (&f1, &f2);
}

TEST (Creation, MonsterFactory_MonsterCreation)
{
    EXPECT_EQ ("GOBLIN", MonsterFactory::Instance().Create("goblin").Name());
    EXPECT_EQ ("ORC", MonsterFactory::Instance().Create("orc").Name());
}

TEST (Creation, PlayerFactory_PlayerCreation)
{
    EXPECT_EQ ("FIGHTER", PlayerFactory::Instance().Create ("fighter").Name());
    EXPECT_EQ ("WIZARD", PlayerFactory::Instance().Create ("wizard").Name());
    EXPECT_EQ ("CLERIC", PlayerFactory::Instance().Create ("cleric").Name());
    EXPECT_EQ ("THIEF", PlayerFactory::Instance().Create ("thief").Name());
}