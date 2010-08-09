#pragma once
#include "IChallenger.h"
using namespace CRPG;

namespace CRPG
{
    class Challenger : public IChallenger
    {
    private:
        int _LastHitRoll;
        int _LastDamageRoll;
        

    public:
        int GetLastHitRoll () const { return _LastHitRoll; }
        int GetLastDamageRoll () const { return _LastDamageRoll; }

    protected :
        string _Name;
        Statistics _Statistics;
        Weapon _Weapon;
        Challenger () { _LastDamageRoll = 0; _LastHitRoll = 0;}

    public:
        virtual ~Challenger (void) = 0 { };
        
        bool IsDie ();
        void TakeDamage (int damageQuantity);
        void Attack (IChallenger& monster);

        string& Name () 
        { 
            return _Name; 
        }

        Statistics& GetStatistics () 
        { 
            return _Statistics; 
        }

        Weapon& GetWeapon () 
        { 
            return _Weapon;
        }

        IChallenger& WithStat (const Statistics& stat) 
        { 
            _Statistics = stat; 
            return *this; 
        }

        IChallenger& Weaponed (const Weapon& weapon) 
        { 
            _Weapon = weapon; 
            return *this; 
        }
    };
}
