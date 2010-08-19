#include "ResourceSpriteLoader.h"
#include <Windows.h>
using namespace UI::Core;

ResourceSpriteLoader::~ResourceSpriteLoader(void)
{
}

HBITMAP ResourceSpriteLoader::Load()
{
	HBITMAP hbitmap = LoadBitmap (_HInstance, MAKEINTRESOURCE (_SpriteID));
	BITMAP bitmap;
	GetObject (hbitmap, sizeof(BITMAP), &bitmap);
	_Width = bitmap.bmWidth;
	_Height = bitmap.bmHeight;
	return hbitmap;
}

ResourceSpriteLoader::ResourceSpriteLoader( HINSTANCE hInstance, unsigned int spriteID )
{
	_SpriteID = spriteID;
	_HInstance = hInstance;
}
