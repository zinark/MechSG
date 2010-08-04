#pragma once
#include <iostream>
#include "Statistics.h"
#include "Monster.h"
#include "IChallenger.h"
using namespace std;
using namespace CRPG;

namespace CRPG
{
    class Monster;

    class Player : public IChallenger
    {

    private:
        string _Name;
        Statistics _Statistics;
        Weapon _Weapon;
        int _Experience;
        int _NextLevelExperience;

    public:
        Player(void);
        Player (string name);
        ~Player(void);

        
        void Attack (Monster& monster);
        void TakeDamage (int value);
        bool IsDie ();
        bool CanRun ();
        void LevelUpIfApplicable ();
        void Rest ();
        void AddExperience (int totalExperience);

        Statistics& GetStatistics () { return _Statistics; }
        Weapon& GetWeapon () { return _Weapon; }

        string& Name () { return _Name;}
        int NextLevelExperience () const { return _NextLevelExperience; }

        Player& WithStat (const Statistics& stat);
        Player& Weaponed (const Weapon& weapon);
        Player& Experienced (int value);

        // NewOnes
        // virtual IChallenger& WithStat (const Statistics& stat) = 0;
        // virtual IChallenger& Weaponed (const Weapon& weapon) = 0;

    };
}
