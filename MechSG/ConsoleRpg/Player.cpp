#include "Player.h"
using namespace CRPG;

Player::Player(void)
{
    Player ("");
}

Player::Player( string name )
{
    _Name = name;
}


Player::~Player(void)
{
}

Player& Player::WithStat( const CRPG::Statistics& stat )
{
    _Statistics = stat;
    return *this;
}

void Player::TakeDamage( int value )
{
    _Statistics.SetHitPoint(_Statistics.HitPoint() - value);
}

void Player::Attack( const Monster& monster )
{

}
