#include "PlayerFactory.h"
#include <stdexcept>
using namespace CRPG;

PlayerFactory PlayerFactory::_Instance;

PlayerFactory::PlayerFactory(void)
{
    _Container["fighter"] = (Player&) Player ("FIGHTER")
        .SetNextLevelExperience (1000)
        .Experienced(0)
        .Weaponed(Weapon ("Sword", Range(1,8)))
        .WithStat(Statistics()
        .SetLevel(1)
        .SetAccuracy(10)
        .SetHitPoint(20)
        .SetMaxHitPoint(20)
        .SetArmor(4));

    _Container["wizard"] = (Player&) Player("WIZARD")
        .SetNextLevelExperience (1000)
        .Experienced(0)
        .Weaponed(Weapon ("Staff", Range(1,4)))
        .WithStat(Statistics()
        .SetLevel(1)
        .SetAccuracy(5)
        .SetHitPoint(10)
        .SetMaxHitPoint(10)
        .SetArmor(1));


    _Container["cleric"] = (Player&) Player("CLERIC")
        .SetNextLevelExperience (1000)
        .Experienced (0)
        .Weaponed(Weapon ("Flail", Range(1,6)))
        .WithStat(Statistics()
        .SetLevel(1)
        .SetAccuracy(8)
        .SetHitPoint(15)
        .SetMaxHitPoint(15)
        .SetArmor(3));



    _Container["thief"] = (Player&) Player("THIEF")
        .SetNextLevelExperience (1000)
        .Experienced (0)
        .Weaponed(Weapon ("Short Sword", Range(1,6)))
        .WithStat(Statistics()
        .SetLevel(1)
        .SetAccuracy(7)
        .SetHitPoint(12)
        .SetMaxHitPoint(12)
        .SetArmor(2));

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
