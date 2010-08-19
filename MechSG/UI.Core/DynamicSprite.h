#pragma once
#include "Sprite.h"
#include "Vector2D.h"

namespace UI { namespace Core
{

	class DynamicSprite : public Sprite
	{
	private:
		Vector2D _Velocity;

	public:
		DynamicSprite(unsigned int spriteId, unsigned int maskId);
		void SetVelocity (const Vector2D& velocity);
		void Update (float speed);
		~DynamicSprite(void);
	};

}}