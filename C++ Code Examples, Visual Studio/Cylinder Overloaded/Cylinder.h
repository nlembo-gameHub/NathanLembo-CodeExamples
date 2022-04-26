///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Cylinder.h
// Date: February 22, 2020
// Programmer: Nathan Lembo            
//
// Description:
//    This is a header file that contains the Cylinder Class that we will then call in the next two programs 
//    It initilizies the Classes/Objects of the Cylinder and initializes there data members 
//    and functions to be accessed by the CylinderBuilder program
//    and the CylinderDriver program. 
//                                                                 
///////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CYLINDER_H
#define CYLINDER_H
#include <iostream>
#include <string>
#include <ctime> //time()
#include <cstdlib> //rand() and srand()
#include <cmath>
#include <iomanip>
using namespace std;

///////////////////////////////////////////////////////////////////////
//
// Class: Cylinder                                          
//                                                                   
// Description:
//    This Class sets the parameters, data members, and functions that allow us to set the values of the Cylinder and perform operations with them     
//
//    List of data members
//	  double length, double radius
//
//    List of member functions
//	  friend ostream& operator<<(ostream&, const Cylinder &),
//	  Cylinder(), Cylinder(double _length, double _radius), ~Cylinder(), setDimension(double newL, double newR), 
//	  double getLength(), double getRadius(), double volume(), double area(), void print(),
//    Cylinder operator+(const Cylinder& otherCylinder), Cylinder operator-(const Cylinder& otherCylinder), Cylinder operator*(const Cylinder& otherCylinder),
//    Cylinder operator++(), Cylinder operator++(int), bool operator==(const Cylinder& otherCylinder),
//    bool operator!=(const Cylinder& otherCylinder), bool operator<=(const Cylinder& otherCylinder) 
//    bool operator<(const Cylinder& otherCylinder), bool operator>=(const Cylinder& otherCylinder), bool operator>(const Cylinder& otherCylinder) 
//
///////////////////////////////////////////////////////////////////////
class Cylinder
{
	//Overload the stream insertion and extraction operators
	friend ostream& operator<<(ostream&, const Cylinder &);
	//friend istream& operator>>(istream&, Cylinder &);
private:
	double length;
	double radius;

public:
	//Overload the arthemitic operators
	Cylinder operator+(const Cylinder& otherCylinder) const; //Overload the operator +
	Cylinder operator-(const Cylinder& otherCylinder) const; //Overload the operator -
	Cylinder operator*(const Cylinder& otherCylinder) const; //Overloadd the operator *

	//Overload the increment and decrement operators
	Cylinder operator++(); //Pre-increment
	Cylinder operator++(int); //Post-increment

	//Overload the relational operators
	bool operator==(const Cylinder& otherCylinder) const; //Overload the operator ==
	bool operator!=(const Cylinder& otherCylinder) const; //Overload the operator !=
	bool operator<=(const Cylinder& otherCylinder) const; //Overload the operator <=
	bool operator<(const Cylinder& otherCylinder) const; //Overload the operator <
	bool operator>=(const Cylinder& otherCylinder) const; //Overload the operator >=
	bool operator>(const Cylinder& otherCylinder) const; //Overload the operator >

	//Constructors
	Cylinder(); //Constructor
	Cylinder(double _length, double _radius); //Overload Constructor
	~Cylinder(); //Deconstructor
	
	//Mutators
	void setDimension(double newL, double newR);
	//Acessors
	double getLength() const;
	double getRadius() const;
	double volume() const;
	double area() const;
	void print() const;
};


#endif
