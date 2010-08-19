#include "DynamicSprite.h"

using namespace UI::Core;

DynamicSprite::DynamicSprite(unsigned int spriteId, unsigned int maskId) : Sprite (spriteId, maskId)
{
	_Location = Vector2D ();
	_Velocity = Vector2D();
}


DynamicSprite::~DynamicSprite(void)
{
}

void DynamicSprite::SetVelocity( const Vector2D& velocity )
{
	_Velocity = velocity;
}

void DynamicSprite::Update( float speed )
{
	Vector2D velo = _Velocity * speed;
	_Location = _Location + velo;
}
