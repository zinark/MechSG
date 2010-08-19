#pragma once
#include <Windows.h>

namespace UI { namespace Core {

	class ISpriteLoader
	{
	public:
		virtual HBITMAP Load() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		~ISpriteLoader(void) {};
	};
}}