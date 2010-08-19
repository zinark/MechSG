#pragma once
#include <Windows.h>
#include "IDrawable.hpp"
#include "ISpriteLoader.hpp"
#include "Vector2D.h"

namespace UI { namespace Core {

	class Sprite : public IDrawable
	{
	protected:
		Vector2D _Location;
	
	private:
		ISpriteLoader* _SpriteLoader;
		ISpriteLoader* _MaskLoader;
		int _SelectedSubX, _SelectedSubY;
		int _SubSpriteWidth, _SubSpriteHeight;
		HBITMAP _Sprite, _Mask;
		bool _IsSubSprite;

	public:
		Sprite(unsigned int spriteId, unsigned int maskId);
		virtual ~Sprite(void);
		void SetLocation (const Vector2D& location);
		void Draw(const HDC& target);
		void Split (int width, int height);
		void PickSubSprite (int x, int y);
		Vector2D& GetLocation () { return _Location; }

		int GetWidth() const { return _SubSpriteWidth;}
		int GetHeight() const { return _SubSpriteHeight;}
	};
}}
