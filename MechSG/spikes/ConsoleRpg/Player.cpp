#include "Player.h"
#include "Dice.h"
using namespace CRPG;

Player::Player(void)
{
    _Name = "";
}

Player::Player( string name )
{
    _Name = name;
}


Player::~Player(void)
{
}


Player& CRPG::Player::Experienced( int value )
{
    _Experience = value;
    return *this;
}

bool Player::CanRun()
{
    Dice dice (Range(1,4));
    return dice.Roll() == 1;
}

void Player::AddExperience( int totalExperience )
{
    _Experience += totalExperience;
    LevelUpIfApplicable();
}

void Player::Rest()
{
    _Statistics.SetHitPoint(_Statistics.MaxHitPoint());
}

void Player::LevelUpIfApplicable()
{
    if (_Experience >= _NextLevelExperience)
    {
        _Experience = 0;
        _Statistics.SetLevel(_Statistics.Level() + 1);
        _Statistics.SetAccuracy(_Statistics.Accuracy() + Dice(Range(1,4)).Roll());
        _Statistics.SetMaxHitPoint(_Statistics.MaxHitPoint() + Dice(Range(3,9)).Roll());
        _Statistics.SetArmor(_Statistics.Armor() + Dice(Range(1,4)).Roll());

        _NextLevelExperience = _Statistics.Level() * _Statistics.Level() * 1000;
        _Statistics.SetHitPoint(_Statistics.MaxHitPoint());
    }
}
