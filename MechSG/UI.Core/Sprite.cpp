#include "Sprite.h"
#include "ResourceSpriteLoader.h"
using namespace UI::Core;

Sprite::Sprite(unsigned int spriteId, unsigned int maskId)
{
	_Location = Vector2D ();
	HINSTANCE hInst = GetModuleHandle (0);
	_SpriteLoader = new ResourceSpriteLoader (hInst, spriteId);
	_MaskLoader = new ResourceSpriteLoader (hInst, maskId);
	_Sprite = _SpriteLoader->Load ();
	_Mask = _MaskLoader->Load ();

	_SubSpriteWidth = _SpriteLoader->GetWidth ();
	_SubSpriteHeight = _SpriteLoader->GetHeight ();
}


Sprite::~Sprite(void)
{
	delete _SpriteLoader;
	delete _MaskLoader;
	DeleteObject (_Sprite);
	DeleteObject (_Mask);
}

void Sprite::Draw(const HDC& hdc)
{
	int srcX = 0;
	int srcY = 0;

	if (_IsSubSprite)
	{
		srcX = _SelectedSubX * _SubSpriteWidth;
		srcY = _SelectedSubY * _SubSpriteHeight;
	}
	HDC pdc = CreateCompatibleDC(hdc);
	SelectObject (pdc, _Mask);
	BitBlt (hdc, (int) _Location.GetX (), (int) _Location.GetY (),_SubSpriteWidth, _SubSpriteHeight, pdc, srcX, srcY, SRCAND);
	SelectObject (pdc, _Sprite);
	BitBlt (hdc, (int) _Location.GetX (), (int) _Location.GetY (),_SubSpriteWidth, _SubSpriteHeight, pdc, srcX, srcY, SRCPAINT);
	DeleteDC (pdc);
}

void Sprite::SetLocation( const Vector2D& location )
{
	_Location = location;
}

void UI::Core::Sprite::Split( int width, int height )
{
	_SubSpriteWidth = width;
	_SubSpriteHeight = height;
	_IsSubSprite = true;
}

void Sprite::PickSubSprite (int x, int y)
{
	_SelectedSubX = x;
	_SelectedSubY = y;
}
