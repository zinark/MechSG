#pragma once
#include <string>
#include "Statistics.h"
#include "Weapon.h"
using namespace std;
using namespace CRPG;

namespace CRPG
{
    class IChallenger
    {
    public:
        virtual ~IChallenger () {};
        virtual string& Name () = 0;
        virtual Statistics& GetStatistics () = 0;
        virtual Weapon& GetWeapon () = 0;
        
        virtual bool IsDie () = 0;
        virtual void TakeDamage (int damageQuantity) = 0;
        virtual void Attack (IChallenger& monster) = 0;
        
        virtual IChallenger& WithStat (const Statistics& stat) = 0;
        virtual IChallenger& Weaponed (const Weapon& weapon) = 0;
    };
}
