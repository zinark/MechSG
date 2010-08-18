#pragma once
#include <Windows.h>
#include "Vectoric.h"

class Sprite
{
public:
	Sprite(HINSTANCE hinstance, UINT imageId, UINT maskId);
	~Sprite(void);
	int GetWidth ();
	int GetHeight ();
	void Draw (const HDC& hdc);
	void UpdatePosition (float quantity);
	
	void SetVectors (const Vectoric& velocity, const Vectoric& position)
	{
		_Velocity = velocity;
		_Position = position;
	}

	void SetPosition (const Vectoric& position)
	{
		_Position = position;
	}
	
	void SetVelocity (const Vectoric& velocity)
	{
		_Velocity = velocity;
	}

	Vectoric& GetPosition ()
	{
		return _Position;
	}
	
protected:
	HINSTANCE _HInstance;
	HBITMAP _Image;
	HBITMAP _Mask;
	BITMAP _BitImage;
	BITMAP _BitMask;
	Vectoric _Velocity;
	Vectoric _Position;
};

