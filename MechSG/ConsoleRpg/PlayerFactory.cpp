#include "PlayerFactory.h"
using namespace CRPG;

PlayerFactory PlayerFactory::_Instance;

PlayerFactory::PlayerFactory(void)
{
    _Container["human"] = Player("HUMAN")
        .WithStat(Statistics().SetHitPoint(10).SetArmor(5).SetAccuracy(10));

    _Container["elf"] = Player("ELF")
        .WithStat(Statistics().SetHitPoint(8).SetArmor(4).SetAccuracy(12));
}

PlayerFactory::~PlayerFactory(void)
{
}

Player& PlayerFactory::Create( string name )
{
    map<string, Player>::iterator it;
    it = _Container.find (name);
    return it->second;
}

PlayerFactory PlayerFactory::Instance()
{
    if (&_Instance == 0)
    {
        _Instance = PlayerFactory ();
    }
    return _Instance;
}
