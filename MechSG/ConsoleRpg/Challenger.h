#pragma once
#include "IChallenger.h"

class Challenger : public IChallenger
{
protected :
    string _Name;
    Statistics _Statistics;
    Weapon _Weapon;

public:
    virtual ~Challenger (void) = 0 { };
    bool IsDie ();
    void TakeDamage (int damageQuantity);
    
    virtual string& Name () 
    { 
        return _Name; 
    }
    
    virtual Statistics& GetStatistics () 
    { 
        return _Statistics; 
    }
    
    virtual Weapon& GetWeapon () 
    { 
        return _Weapon;
    }
    
    virtual IChallenger& WithStat (const Statistics& stat) 
    { 
        _Statistics = stat; 
        return *this; 
    }
    
    virtual IChallenger& Weaponed (const Weapon& weapon) 
    { 
        _Weapon = weapon; 
        return *this; 
    }
};

