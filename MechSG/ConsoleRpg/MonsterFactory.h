#pragma once
#include "Monster.h"
#include <iostream>
#include <map>
using namespace std;
using namespace CRPG;

namespace CRPG
{
    class MonsterFactory
    {
    private:
        map<string, Monster> _Container;
        static MonsterFactory _Instance;

    public:
        MonsterFactory(void);
        ~MonsterFactory(void);
        Monster Create (string name);
        static MonsterFactory& Instance ();
    };


}
