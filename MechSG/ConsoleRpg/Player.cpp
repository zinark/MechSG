#include "Player.h"
#include "Dice.h"
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

Player& Player::Weaponed( const Weapon& weapon )
{
    _Weapon = weapon;
    return *this;
}


void Player::Attack( Monster& monster )
{
    Dice hitDice (Range(1,20));
    Dice damageDice (_Weapon.DamageRange());
    int hitRoll = hitDice.Roll();
    if (_Statistics.Accuracy() > hitRoll)
    {
        int damageRoll = damageDice.Roll();
        int damage = damageRoll - monster.GetStatistics().Armor();
        if (damage < 0) damage = 0;
        monster.TakeDamage(damage);
    }
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
