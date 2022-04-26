///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: shapesDriver.cpp
// Date: January 22, 2020
// Programmer: Nathan Lembo             
//
// Description:
//    This program creates Point, Circle, and Cylinder Objects from the classes in a struct ShapeObjects. The array sizes will be generated as the number of shape objects is inputted.
//    We then display the contents of each individual parameters of the Point, Circle, and Cylinder shapes through a for loop which calls display functions. These display functions in turn
//    call the display functions of the Point, Circle, and Cylinder Classes. 
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "shapes.h"
#include <ctime> //time()
#include <cstdlib> //rand() and srand()
using namespace std;

//Prototypes

void displayPoints(Point &pointObject);
void displayCircles(Circle &circleObject);
void displayCylinders(Cylinder &cylinderObject);
//Constant
const int MAX_SIZE = 10;
static int shapeNum;

struct ShapeObjects {

	Point ptArr[MAX_SIZE];
	Circle cirArr[MAX_SIZE];
	Cylinder cylArr[MAX_SIZE];
};

int main()
{
	srand(time(0));
	int size = 0;
	ShapeObjects shapes;

	cout << "Hello there, how many Point Objects, Circle Objects, and Cylinder Objects do you wish to Create? (Note, do not go above 10 else we will ask the question again)" << endl;
	cin >> size;
	if (size <= MAX_SIZE)
	{
		for (int i = 0; i < size; i++)
		{
			displayPoints(shapes.ptArr[i]);
			displayCircles(shapes.cirArr[i]);
			displayCylinders(shapes.cylArr[i]);
		}
	}
	else
	{
		while (size > MAX_SIZE)
		{
			cout << "Hello there, how many Point Objects, Circle Objects, and Cylinder Objects do you wish to Create? (Note, do not go above 10 else we will ask the question again)" << endl;
			cin >> size;
		}
		for (int i = 0; i < size; i++)
		{
			displayPoints(shapes.ptArr[i]);
			displayCircles(shapes.cirArr[i]);
			displayCylinders(shapes.cylArr[i]);
		}
	}
	cout << "We have created " << shapeNum <<  " Circle, Cylinder, and Point Objects. Therefore, the total number of objects created is: " << shapeNum * 3 <<  endl;
	system("pause");
	return 0;
}


void displayPoints(Point &pointObject)
{
	//pointObject.display();
	cout << pointObject.toString() << endl;
	shapeNum = pointObject.getNum();
}
///////////////////////////////////////////////////////////////////////
//
// Function: displayPoints(Point &pointObject)                                        
//                                                                   
// Description:
//    This function accesses the individual elements of the shapes object, specifically the point array of that shapes object. It then calls upon the displayPoints function from
//    the Point class. 
//
// Parameters:  
//    firstParam  : Point &pointObject        
//    secondParam : NA               
//                                                       
// Returns:  
//    returnVal : NA              
//                                            
///////////////////////////////////////////////////////////////////////

void displayCircles(Circle &circleObject)
{
	//circleObject.display();
	cout << circleObject.toString() << endl;
	shapeNum = circleObject.getNum();
}
///////////////////////////////////////////////////////////////////////
//
// Function: displayCircles(Circle &circleObject)                                         
//                                                                   
// Description:
//    This function accesses the individual elements of the shapes object, specifically the circle array of that shapes object. It then calls upon the displayCircle function from
//    the Circle class. 
//
// Parameters:  
//    firstParam  : Circle &circleObject         
//    secondParam : NA               
//                                                       
// Returns:  
//    returnVal : NA                
//                                            
///////////////////////////////////////////////////////////////////////

void displayCylinders(Cylinder &cylinderObject)
{
	//cylinderObject.display();
	cout << cylinderObject.toString() << endl;
	shapeNum = cylinderObject.getNum();
}
///////////////////////////////////////////////////////////////////////
//
// Function: displayCylinders(Cylinder &cylinderObject)                                     
//                                                                   
// Description:
//    This function accesses the individual elements of the shapes object, specifically the cylinder array of that shapes object. It then calls upon the displayCylinder function from
//    the Cylinder class. 
//
// Parameters:  
//    firstParam  : Cylinder &cylinderObject          
//    secondParam : NA               
//                                                       
// Returns:  
//    returnVal : NA                
//                                            
///////////////////////////////////////////////////////////////////////