#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

struct Vector2
{
	float x,y;
	Vector2(float _x = 0, float _y = 0) 
	{
		x = _x;
		y = _y;
	}

	float len();
	float len(float x);

	Vector2 operator+(const Vector2& other) const
	{
		Vector2 result;
		result.x = x + other.x;
		result.y = y + other.y;
		return result;
	}

	Vector2 operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	
	Vector2 operator-(const Vector2& other) const
	{
		Vector2 result;
		result.x = x - other.x;
		result.y = y - other.y;
		return result;
	}
	
	Vector2 operator-=(const Vector2& other) 
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	float operator*(const Vector2& other) const
	{
		float result;
		result = x * other.x + y * other.y;
		return result;
	}

	Vector2 operator*(float c) const
	{
		return Vector2(x * c, y * c);
	}

	Vector2 operator/(const float c) const
	{
		Vector2 result;
		result.x = x / c;
		result.y = y / c;
		return result;
	}

	float operator^(const Vector2& other) const
	{
		float result;
		result = sqrt((x * other.y)* (x * other.y) + (y * other.x)* (x * other.y));
		return result;
	}

	Vector2 norm()
	{
		Vector2 result;
		result.x = x / len();
		result.y = y / len();
		return result;
	}

	float squareLen()
	{
		return len() * len();
	}

	Vector2 rotate(float fi) 
	{
		Vector2 result;
		double di = fi * M_PI / 180;
		result.x = x * cos(di) - y * sin(di);
		result.y = x * sin(di) + y * cos(di);
		return result;
	}

	Vector2 getRotated(float fi) 
	{
		double di = fi * M_PI / 180;
		float k = x * cos(di) - y * sin(di);
		y = x * sin(di) + y * cos(di);
		x = k;
		return *this;
	}

	
};

const std::ostream& operator<<(std::ostream& stream, const Vector2& other) {
	stream << other.x << " " << other.y;
	return stream;
}

std::istream& operator>>(std::istream& stream, Vector2& other)
{
	stream >> other.x >> other.y;
	return stream;
}

class Vector {

};


