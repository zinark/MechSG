#include "PlayerFactory.h"
#include <stdexcept>
using namespace CRPG;

PlayerFactory PlayerFactory::_Instance;

PlayerFactory::PlayerFactory(void)
{
    Player p;

    p = Player ("FIGHTER");
    p.Experienced(0);
    p.Weaponed(Weapon ("Sword", Range(1,8)));
    p.WithStat(Statistics()
        .SetLevel(1)
        .SetAccuracy(10)
        .SetHitPoint(20)
        .SetMaxHitPoint(20)
        .SetArmor(4));
    _Container["fighter"] = p;

    p = Player("WIZARD");
    p.Experienced(0);
    p.Weaponed(Weapon ("Staff", Range(1,4)));
    p.WithStat(Statistics()
        .SetLevel(1)
        .SetAccuracy(5)
        .SetHitPoint(10)
        .SetMaxHitPoint(10)
        .SetArmor(1));
    _Container["wizard"] = p;

    p = Player("CLERIC");
    p.Experienced (0);
    p.Weaponed(Weapon ("Flail", Range(1,6)));
    p.WithStat(Statistics()
        .SetLevel(1)
        .SetAccuracy(8)
        .SetHitPoint(15)
        .SetMaxHitPoint(15)
        .SetArmor(3));
    _Container["cleric"] = p;
        
        
    p = Player("THIEF");
    p.Experienced (0);
    p.Weaponed(Weapon ("Short Sword", Range(1,6)));
    p.WithStat(Statistics()
        .SetLevel(1)
        .SetAccuracy(7)
        .SetHitPoint(12)
        .SetMaxHitPoint(12)
        .SetArmor(2));
    _Container["thief"] = p;
}

PlayerFactory::~PlayerFactory(void)
{
}

Player PlayerFactory::Create( string name )
{
    map<string, Player>::iterator it;
    it = _Container.find (name);
    return it->second;
}

PlayerFactory& PlayerFactory::Instance()
{
    if (&_Instance == 0)
    {
        _Instance = PlayerFactory ();
    }
    return _Instance;
}
