#include "Vector2D.h"

using namespace UI::Core;

Vector2D::~Vector2D(void)
{
}

Vector2D::Vector2D()
{
	_X = 0;
	_Y = 0;
}

UI::Core::Vector2D::Vector2D( float x, float y)
{
	_X = x;
	_Y = y;
}

Vector2D& UI::Core::Vector2D::operator*( float value )
{
	return Vector2D (_X * value,_Y * value);
}

Vector2D& UI::Core::Vector2D::operator*( Vector2D& rhs )
{
	return Vector2D (_X * rhs.GetX(), _Y * rhs.GetY());
}

float UI::Core::Vector2D::GetX()
{
	return _X;
}

float UI::Core::Vector2D::GetY()
{
	return _Y;
}


Vector2D& UI::Core::Vector2D::operator+( const Vector2D& rhs )
{
	return Vector2D (_X + rhs._X, _Y + rhs._Y);
}
