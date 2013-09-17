#include "point.h"


Point::Point()
{

}
Point::Point(double _x1, double _y1)
{
	x = _x1;
	y = _y1;
	static int id_counter = 0;
	id = id_counter++;
	index=0;
	Point();
	//std::cout << "Constructing Point x: " << x << " y: " << y << " \t ID: " << id << " index " << index  <<std::endl;

}
void Point::print()
{
	std::cout << "Point x: " << x << " y: " << y << " \t ID: " << id << std::endl;
}
double Point::value()
{
	// this is the angular distance from the base line
	// for point.cpp, we just cache the initial calculation
	return theta;
}
void Point::printVisible()
{
	for(int i=0;i<index;i++){
		if(visible[i]!=NULL){
			std::cout << "Point " << id <<" \t can see Point " << visible[i]->id <<  std::endl;
		}
	}
}
/*
 * This function will check whether that Point p is visible to this point*/
bool Point::isVisible(Point* p)
{
	std::cout<<"Testing is visible "<<id<<" "<<p->id;
	bool found=false;
	for(int i=0;i<index;i++){
		if(visible[i]!=NULL){
			{
				if(visible[i]->id == p->id){
					found=true;
					break;
			}
		}

		}
	}
	std::cout<<" Found : "<<found<<std::endl;
	return found;
}
void Point::addVisible(Point *p)
{
	//std::cout << "At " << x <<"," << y <<"   for  " << p->x <<","<<p->y <<" Index "<<index<<std::endl;
	visible[index]=p;
	index++;
}
void Point::removeVisible(Point *p)
{
	int i;
	//std::cout << "At " << x <<"," << y <<"   for  " << p->x <<","<<p->y <<" Index "<<index<<std::endl;
	for(i=0;i<index;i++){
			if(visible[i]!=NULL){
				if(visible[i]->id == p->id){
					visible[i]=NULL;
					break;
				}
				std::cout << "Point " << id <<" \t removed Point " << visible[i]->id <<  std::endl;
			}
		}
}
void Point::setVisibilityCheckDone(Point* p){
	visibilityCheckDone[p->id]=true;
}
bool Point::isVisibilityCheckDone(Point* p){
	return visibilityCheckDone[p->id];
}
void Point::printVisibilityCheckDone(int numOfPoints){
	std::cout<<"Visibility Test Done Result for Point "<<id<<" : "<<std::endl;
	for(int i=0;i<numOfPoints;i++){
		std::cout << i<<" ";

	}
	std::cout<<std::endl;
	for(int i=0;i<numOfPoints;i++){
		if(i==id){
			std::cout<<"  ";
			continue;
		}
		std::cout << visibilityCheckDone[i]<<" ";
	}
	std::cout<<std::endl;
}

