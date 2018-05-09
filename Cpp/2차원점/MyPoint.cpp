#include <cstdlib>
#include "MyPoint.h"
// constructors
MyPoint::MyPoint()
	:x(0), y(0) // set default to origin (0,0)
{
}
MyPoint::MyPoint(int coordX, int coordY)
	: x(coordX), y(coordY)
{
}
MyPoint::MyPoint(const MyPoint& p)
{
	x = p.getX();
	y = p.getY();
}
// accessor functions
int MyPoint::getX() const
{
	return x;
}
int MyPoint::getY() const
{
	return y;
}
// mutator functions
void MyPoint::setX(int coordX)
{
	x = coordX;
}
void MyPoint::setY(int coordY)
{
	y = coordY;
}
bool MyPoint::operator== (const MyPoint& p) const
{
	if (p.getX() == x && p.getY() == y) {
		return true;
	}
	return false;
}
bool MyPoint::operator!= (const MyPoint& p) const
{
	return !operator==(p);
}
// 직선거리(Euclidean distance)의 제곱을 계산
int MyPoint::dist2sqr(const MyPoint& p) const
{
	int result = 0;
	int px = p.getX();
	int py = p.getY();

	result = (x - px) * (x - px) + (y - py) * (y - py);

	return result;

}
// 직각거리(rectilinear distance)를 계산
int MyPoint::dist1(const MyPoint& p) const
{
	int result = 0;
	int px = p.getX();
	int py = p.getY();

	px = px - x;
	py = py - y;
	if (px < 0) {
		px = -px;
	}
	if (py < 0) {
		py = -py;
	}
	result = px + py;

	return result;
	
}