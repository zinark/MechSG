#pragma once
#include <iostream>
#include "Player.h"
#include <map>
#include <string>
using namespace std;
using namespace CRPG;

namespace CRPG
{
    class PlayerFactory
    {
    private:
        static PlayerFactory _Instance;
        map<string, Player> _Container;
    
    public:
        static PlayerFactory& Instance ();
        PlayerFactory(void);
        ~PlayerFactory(void);
        Player Create (string name);
    };
}