#pragma once
#include <string>
#include "Player.h"
#include "Challenger.h"
using namespace std;
using namespace CRPG;

namespace CRPG
{
    class Player;

    class Monster : public Challenger
    {

    private:
        int _XpReward;

    public:
        Monster (void);
        Monster(const string& name, int xpReward);
        virtual ~Monster(void);

        int XpReward () const { return _XpReward; }
    };
}
