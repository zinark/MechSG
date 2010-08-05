#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
using namespace CRPG;
using namespace std;

namespace CRPG
{
    class PlayerPersister
    {
    private:
        string _FileName;
        vector<Player> _Players;

    public:
        vector<Player>& GetPlayers () { return _Players; }
    
    public:
        PlayerPersister(string fileName);
        ~PlayerPersister(void);

        void Add (const Player& player);
        bool Export ();
        bool Import ();

    };

}
