#include "Player.h"


CRPG::Player::Player(void)
{
    Player ("");
}

CRPG::Player::Player( string name )
{
    _Name = name;
}


CRPG::Player::~Player(void)
{
}

CRPG::Player& CRPG::Player::WithStat( const CRPG::Statistics& stat )
{
    _Statistics = stat;
    return *this;
}
