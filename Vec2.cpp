#include "Vec2.h" 
#include <math.h>
#include <iostream>

Vec2::Vec2() {}

Vec2::Vec2(float xin, float yin)
	: x(xin), y(yin)
{}

bool Vec2::operator == (const Vec2 & rhs) const
{
	return (x == rhs.x && y == rhs.y);
}

bool Vec2::operator != (const Vec2 & rhs) const
{
	return (x != rhs.x || y != rhs.y);
}

Vec2 Vec2::operator + (const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}	

Vec2 Vec2::operator - (const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}	

Vec2 Vec2::operator / (const float & val) const
{
	return Vec2(x / val, y / val);
}

Vec2 Vec2::operator * (const float & val) const
{
	return Vec2(x * val, y * val);
};	


void Vec2::operator += (const Vec2 & rhs)
{
	x += rhs.x;
	y += rhs.y;
}

void Vec2::operator -= (const Vec2 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
}

void Vec2::operator *= (const float & val)
{
	x *= val;
	y *= val;
}

void Vec2::operator /= (const float & val)
{
	x /= val;
	y /= val;
}

float Vec2::dist(const Vec2 & rhs) const
{
	float tmp;
	tmp = (x - rhs.x)*(x - rhs.x) + (y - rhs.y)*(y - rhs.y);
	return sqrt(tmp);
}

void Vec2::print()
{
	std::cout << "x = " << x <<" , y = " << y <<"\n";
}


int main()
{
	Vec2 v1(1,3),v2(2,2);
	v1 = (v2 * 2) + v1 ;
	v1.print();
	return 0;
}
