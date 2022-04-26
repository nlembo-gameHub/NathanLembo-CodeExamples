///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: shapes.h
// Date: February 5th, 2020
// Programmer: Nathan Lembo             
//
// Description:
//    This Program Initializes the Classes/Objects Point, Circle, and Cylinder and initializes there data members and functions to be accessed by the gemometryShapes program
//    and the shapesDriver program. 
//                                                                  
///////////////////////////////////////////////////////////////////////
#pragma once
#pragma once
#ifndef SHAPES_H
#define SHAPES_H
#include <iostream>
#include <string>
#include <ctime> //time()
#include <cstdlib> //rand() and srand()
using namespace std;

class Shapes
{
private:
	static int objectNum;
	int num;
public:
	Shapes();
	Shapes(int _num);
	virtual ~Shapes();
	int getNum();
	void setNum(int newNum);
	virtual void display() = 0;
	virtual string toString() = 0;
};
///////////////////////////////////////////////////////////////////////
//
// Class: Point                                         
//                                                                   
// Description:
//    This class holds the data members and functions of the Point Object. This containts information on the point's x & y points, its radius, and the number of points that exist
//	  This class updates the information of these members and is set up to be created by an array in the Driver Function.
//
//    List of data members
//	  int pointX, int pointY, static int pointNum, int num
//
//    List of member functions 
//	  Point(), Point(int _pointX, int _pointY, int _num), ~Point(), int getPointX(), int getPointY(), int getNum(), void setPointX(int newX), void setPointY(int newY) void setNum(int newNum), void display()
// 
///////////////////////////////////////////////////////////////////////
class Point : public Shapes
{
private:
	int pointX; //X Point
	int pointY; //Y Point
	static int pointNum; // Object ID Number
	int num; //Current Object Number
public:
	Point(); //Constructor
	Point(int _pointX, int _pointY, int _num); //Overload Constructor
	~Point(); //Deconstructor
	//Acessors
	//int getPoints();
	int getPointX();
	int getPointY();
	int getNum();
	//Mutators
	//void setPoints(int newX, int newY);
	void setPointX(int newX);
	void setPointY(int newY);
	void setNum(int newNum);
	void display();
	string toString();
};

///////////////////////////////////////////////////////////////////////
//
// Class: Circle                                          
//                                                                   
// Description:
//    This class holds the data members and functions of the Circle Object. This contains information on the circle's x & y points, its radius, and the number of circles that exist.         
//	  This class updates the information of these members and is set up to be created by an array in the Driver Function.
//
//    List of data members
//	  int radius, static int circleNum, int num 
//
//    List of member functions                                       
//	  Circle(), Circle(Circle(int _pointX, int _pointY, int _radius, int _num), ~Circle(), int getRadius(), int getNum(),
//    void setRadius(int newRadius), void setNum(int newNum), void display()
//
///////////////////////////////////////////////////////////////////////
class Circle : public Point
{
private:
	int radius; //Radius
	static int circleNum; //Circle ID Number
	int num; //Current Circle Number
public:
	Circle(); //Constructor
	Circle(int _pointX, int _pointY, int _radius, int _num); //Overload Constructor
	~Circle(); //Destructor
	//Accessors
	int getRadius();
	int getNum();
	//Mutators
	void setRadius(int newRadius);
	void setNum(int newNum);
	void display();
	string toString();
};

///////////////////////////////////////////////////////////////////////
//
// Class: Cylinder                                          
//                                                                   
// Description:
//    Description of the class and its purpose         
//
//    List of data members
//	  int height, static int cylinderNum, int num
//
//    List of member functions                                       
//	  Cylinder(), Cylinder(int _pointX, int _pointY, int _radius, int _height, int _num), ~Cylinder(), int getHeight(), int getNum(), 
//	  void setHeight(int newHeight), void setNum(int newNum), void display()
///////////////////////////////////////////////////////////////////////
class Cylinder : public Circle
{
private:
	int height; //Height
	static int cylinderNum; //Cylinder ID Number
	int num; //Current Cylinder Number
public:
	Cylinder(); //Default Constructor
	Cylinder(int _pointX, int _pointY, int _radius, int _height, int _num); //Overload Constructor
	~Cylinder(); //Destructor
	//Accessors
	int getHeight();
	int getNum();
	//Mutators
	void setHeight(int newHeight);
	void setNum(int newNum);
	void display();
	string toString();
};

#endif