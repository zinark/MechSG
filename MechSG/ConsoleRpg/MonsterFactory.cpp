#include "MonsterFactory.h"
MonsterFactory MonsterFactory::_Instance;

MonsterFactory::MonsterFactory( void )
{
    Monster m;
    m = Monster ("GOBLIN", 100);
    m.Weaponed(Weapon ("Dagger", Range(1,4)));
    m.WithStat(Statistics ().SetMaxHitPoint(5).SetHitPoint(5).SetArmor(5).SetAccuracy(5));
    _Container["goblin"] = m;

    m = Monster ("ORC", 100);
    m.Weaponed(Weapon ("Axe", Range(2,4)));
    m.WithStat(Statistics ().SetMaxHitPoint(8).SetHitPoint(8).SetArmor(6).SetAccuracy(6));
    _Container["orc"] = m;
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
