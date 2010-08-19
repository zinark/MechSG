#pragma once
#include <Windows.h>
#include "ISpriteLoader.hpp"

namespace UI { namespace Core {

	class ResourceSpriteLoader : public ISpriteLoader
	{
	private:
		unsigned int _SpriteID;
		HINSTANCE _HInstance;
		BITMAP _Bitmap;

		int _Width;
		int GetWidth() const { return _Width; }
		
		int _Height;
		int GetHeight() const { return _Height; }

	public:
		HBITMAP Load();
		BITMAP& GetBitmap ();
		ResourceSpriteLoader(HINSTANCE hInstance, unsigned int spriteID);
		~ResourceSpriteLoader(void);
	};
}}
