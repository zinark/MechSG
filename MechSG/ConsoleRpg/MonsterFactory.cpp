#include "MonsterFactory.h"
MonsterFactory MonsterFactory::_Instance;

MonsterFactory::MonsterFactory( void )
{
    _Container["goblin"] = Monster ("GOBLIN", 100)
        .Weaponed(Weapon ("Dagger", Range(1,4)))
        .WithStat(Statistics ().SetHitPoint(5).SetArmor(5).SetAccuracy(5));

    _Container["orc"] = Monster ("ORC", 100)
        .Weaponed(Weapon ("Axe", Range(2,4)))
        .WithStat(Statistics ().SetHitPoint(8).SetArmor(6).SetAccuracy(6));
}

MonsterFactory::~MonsterFactory( void )
{
}

MonsterFactory& MonsterFactory::Instance()
{
    if (&_Instance == 0)
    {
        _Instance = MonsterFactory ();
    }
    return _Instance;
}

Monster MonsterFactory::Create( string name )
{
    return _Container[name];
}
