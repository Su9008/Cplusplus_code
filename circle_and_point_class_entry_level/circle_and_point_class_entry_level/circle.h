#pragma once
#include<iostream>
using namespace std;
#include"point.h"

class Circle
{
public:
	void setR(int r);
	int getR();
	void setCenter(Point center);
	Point getCenter();
private:
	int m_R;// Radius

	// In a class, another class can be used as a member
	Point m_Center; // Center of the circle
};