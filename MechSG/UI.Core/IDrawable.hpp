#pragma once
#include <Windows.h>

namespace UI { namespace Core {

	class IDrawable
	{
	public:
		virtual void Draw(const HDC& target) = 0;
		~IDrawable(void) {};
	};
}}
