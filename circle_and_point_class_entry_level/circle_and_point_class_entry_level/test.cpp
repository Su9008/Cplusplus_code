#include<iostream>
#include"circle.h"
#include"point.h"
using namespace std;

// Determine the relationship between a point and a circle
void isInCircle(Circle& c, Point& p)
{
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();
	if (distance == rDistance)
	{
		cout << "The point is on the circle" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "The point is outside the circle" << endl;
	}
	else
	{
		cout << "The point is inside the circle" << endl;
	}
}
int main()
{
	// Create a circle
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	// Create a point
	Point p;
	p.setX(10);
	p.setY(10); // 10 on ; 11 outside ; 9 inside

	// Determine the relationship
	isInCircle(c, p);
	return 0;
}