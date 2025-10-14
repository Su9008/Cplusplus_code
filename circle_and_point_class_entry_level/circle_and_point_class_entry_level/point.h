#pragma once
#include<iostream>
using namespace std;

class Point
{
private:
	int m_X;
	int m_Y;
public:
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};