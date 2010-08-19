#include "ResourceSpriteLoader.h"
#include <Windows.h>
using namespace UI::Core;

ResourceSpriteLoader::~ResourceSpriteLoader(void)
{
}

HBITMAP ResourceSpriteLoader::Load()
{
	HBITMAP hbitmap = LoadBitmap (_HInstance, MAKEINTRESOURCE (_SpriteID));
	GetObject (hbitmap, sizeof(BITMAP), &_Bitmap);
	_Width = _Bitmap.bmWidth;
	_Height = _Bitmap.bmHeight;
	return hbitmap;
}

ResourceSpriteLoader::ResourceSpriteLoader( HINSTANCE hInstance, unsigned int spriteID )
{
	_SpriteID = spriteID;
	_HInstance = hInstance;
}

BITMAP& UI::Core::ResourceSpriteLoader::GetBitmap()
{
	return _Bitmap;
}
