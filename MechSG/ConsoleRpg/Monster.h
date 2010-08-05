#pragma once
#include <string>
#include "Statistics.h"
#include "Weapon.h"
#include "Player.h"
#include "IChallenger.h"
using namespace std;
using namespace CRPG;

namespace CRPG
{
    class Player;

    class Monster : public IChallenger
    {
    private:
        int _XpReward;
        string _Name;
        Statistics _Statistics;
        Weapon _Weapon;

    public:
        Monster(const string& name, int xpReward);
        Monster ();
        virtual ~Monster(void);

        Monster& WithStat (const Statistics& statistics);
        Monster& Weaponed (const Weapon& weapon);

        int XpReward () const { return _XpReward; }
        string& Name () { return _Name; }
        Statistics& GetStatistics () { return _Statistics;}
        Weapon& GetWeapon () { return _Weapon; }

        void TakeDamage (int damagePoint);
        void Attack ( Player& player);
        bool Attack ( Player& player, int& hitRoll, int& damageRoll);
        bool IsDie () { return _Statistics.HitPoint() <= 0; }


    };
}
