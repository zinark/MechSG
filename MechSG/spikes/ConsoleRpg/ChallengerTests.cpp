#include <gtest/gtest.h>
#include "IChallenger.h"
#include "Player.h"
#include <iostream>
#include "PlayerFactory.h"
#include "MonsterFactory.h"

using namespace CRPG;
using namespace std;

template <typename T>
class CustomList
{
private:
    std::list<T> mList;

public:
    void Add (const T& toAdd)
    {
        list<T>::iterator iterator;
        for (iterator = mList.begin(); iterator != mList.end(); ++iterator)
        {
            if (*iterator > toAdd)
            {
                cout << "inserted" << *iterator << " > " << toAdd << endl;
                mList.insert(iterator, toAdd);
                return;
            }
        }

        mList.push_back(toAdd);
    }

    void PrintAll ()
    {
        for (auto iterator = mList.begin(); iterator != mList.end(); ++iterator)
        {
            cout << *iterator << endl;
        }
    }

    T& GetItem (int order)
    {
        T result = T();

        int index = 0;
        for (auto iterator = mList.begin(); iterator != mList.end(); ++iterator)
        {
            if (index == order)
                return *iterator;
            ++index;

        }
        return result;
    }
};

TEST (CustomSortedList, Add_WhenAdd12_ToSorted3ItemedArray_ElementLocatesIn2thOrder)
{
    CustomList<int> theList;
    theList.Add(0);
    theList.Add(10);
    theList.Add(20);

    theList.Add(12);

    EXPECT_EQ (12, theList.GetItem (2));
}

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