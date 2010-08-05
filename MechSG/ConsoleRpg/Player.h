#pragma once
#include <iostream>
#include "Statistics.h"
#include "Monster.h"
#include "Challenger.h"
using namespace std;
using namespace CRPG;

namespace CRPG
{
    class Monster;

    class Player : public Challenger
    {

    private:
        int _Experience;
        int _NextLevelExperience;

    public:
        Player(void);
        Player (string name);
        ~Player(void);

        
        void Attack (Monster& monster);
        bool CanRun ();
        void LevelUpIfApplicable ();
        void Rest ();
        void AddExperience (int totalExperience);

        int NextLevelExperience () const { return _NextLevelExperience; }

        Player& WithStat (const Statistics& stat);
        Player& Weaponed (const Weapon& weapon);
        Player& Experienced (int value);

        // NewOnes
        // virtual IChallenger& WithStat (const Statistics& stat) = 0;
        // virtual IChallenger& Weaponed (const Weapon& weapon) = 0;
        // Statistics& GetStatistics () { return _Statistics; }
        // Weapon& GetWeapon () { return _Weapon; }
        // string& Name () { return _Name;}

    };
}
