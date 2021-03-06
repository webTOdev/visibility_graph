#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include "geometry.h"

class Point: public Geometry
{
 public:
	double x;
	double y;
	void* parentLine;
	int id; // for removing, comparing, etc
	double theta; // anglular amount from base line
	int index;
	
	Point();
	Point(double _x1, double _y1);

	virtual void print();
	virtual double value();
	virtual void addVisible(Point *p);
	virtual void printVisible();
	bool isVisible(Point* p);
	void removeVisible(Point *p);

	Point * visible[100];

};

#endif
