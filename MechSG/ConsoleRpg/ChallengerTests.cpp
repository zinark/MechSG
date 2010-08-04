#include <gtest/gtest.h>
#include "IChallenger.h"
#include "Player.h"
#include <iostream>

using namespace CRPG;
using namespace std;

TEST (Challenger, PlayerIsAChallenger)
{
    Player q("P1");
    q.WithStat(Statistics ()
        .SetMaxHitPoint(100).SetHitPoint(95)
        .SetArmor(5).SetAccuracy(10)
        .SetLevel(1));

    IChallenger& p = (Player) Player("q").WithStat(Statistics ().SetMaxHitPoint(23));

    cout << &p << endl;
    cout << p.Name() << endl;
    cout << p.GetStatistics().MaxHitPoint() << endl;
    

    //IChallenger* p1 = &p;

    //EXPECT_EQ ("P1", p1->Name());
    //EXPECT_EQ (100, p1->GetStatistics ().MaxHitPoint());

    //delete p1;
}