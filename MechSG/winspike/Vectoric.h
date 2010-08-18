#pragma once
class Vectoric
{
public:
	
	Vectoric ()
	{
		_X = 0;
		_Y = 0;
		_Z = 0;
	}
	Vectoric(float x, float y, float z)
	{
		_X = x;
		_Y = y;
		_Z = z;
	}
	~Vectoric(void);
	Vectoric& operator* (float value)
	{
		Vectoric result (_X,_Y,_Z);
		result._X *= value;
		result._Y *= value;
		result._Z *= value;
		return result;
	}

	Vectoric& operator+ (const Vectoric& rhs)
	{
		return Vectoric (_X + rhs._X, _Y + rhs._Y, _Z + rhs._Z);
	}

	float GetX ()
	{
		return _X;
	}
	
	float GetY ()
	{
		return _Y;
	}

	float GetZ ()
	{
		return _Z;
	}

protected:
	float _X;
	float _Y;
	float _Z;
};

