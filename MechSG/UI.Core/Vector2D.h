#pragma once
namespace UI { namespace Core 
{

	class Vector2D
	{

	public:
		Vector2D ();
		Vector2D(float x, float y);
		~Vector2D(void);
		Vector2D& operator* (float value);
		Vector2D& operator* (Vector2D& rhs);
		Vector2D& operator+ (const Vector2D& rhs);
		float GetX ();
		float GetY ();

	protected:
		float _X;
		float _Y;
	};

}}