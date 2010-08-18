#include "Sprite.h"


Sprite::Sprite( HINSTANCE hinstance, UINT imageId, UINT maskId )
{
	_HInstance = hinstance;
	_Image = (HBITMAP) LoadBitmap (hinstance, MAKEINTRESOURCE (imageId));
	_Mask = (HBITMAP) LoadBitmap (hinstance, MAKEINTRESOURCE (maskId));

	GetObject (_Image, sizeof(BITMAP), &_BitImage);
	GetObject (_Mask, sizeof(BITMAP), &_BitMask);
}


Sprite::~Sprite(void)
{
	DeleteObject(_Image);
	DeleteObject(_Mask);
}

int Sprite::GetWidth()
{
	return _BitImage.bmWidth;
}

int Sprite::GetHeight()
{
	return _BitImage.bmHeight;
}

void Sprite::Draw( const HDC& hdc )
{
	HDC temp = CreateCompatibleDC(hdc);

	HGDIOBJ old = SelectObject (temp, _Mask);
	BitBlt (hdc, (int)_Position.GetX(), (int)_Position.GetY(), GetWidth(), GetHeight(), temp, 0,0, SRCAND);
	SelectObject (temp, _Image);
	BitBlt (hdc, (int)_Position.GetX(), (int)_Position.GetY(),GetWidth(), GetHeight(), temp, 0,0, SRCPAINT);
	SelectObject(temp, old);

	DeleteDC(temp);
}

void Sprite::UpdatePosition(float quantity)
{
	
	Vectoric v = _Velocity * quantity;
	_Position = _Position + v;
}
