#include <gtest/gtest.h>
#include "PlayerPersister.h"
#include "PlayerFactory.h"
using namespace CRPG;

TEST (Persistence, Challenger_Can_Be_Export_As_BinaryFile)
{
    PlayerPersister persister("test.bin");
    persister.Add (PlayerFactory::Instance().Create("fighter"));
    persister.Add (PlayerFactory::Instance().Create("wizard"));
    persister.Add (PlayerFactory::Instance().Create("cleric"));
    bool result = persister.Export ();
    EXPECT_EQ (true, result);
}

TEST (Persistence, Challenger_Can_Be_Import_From_BinaryFile)
{
    PlayerPersister persister("test.bin");
    persister.Add (PlayerFactory::Instance().Create("fighter"));
    persister.Add (PlayerFactory::Instance().Create("wizard"));
    persister.Add (PlayerFactory::Instance().Create("cleric"));
    persister.Export ();
    
    bool result = persister.Import ();
    EXPECT_EQ (true, result);
    EXPECT_EQ (3, persister.GetPlayers ().size());
}

