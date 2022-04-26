///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: geometryShapes.cpp
// Date: January 22, 2020
// Programmer: Nathan Lembo            
//
// Description:
//    This Program is designed to run through the various data members and function members of the Classes created in the header file and fill in the empty variables
//    and set, get, and display those various variables through the functions.
//                                                                  
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "shapes.h"
#include <ctime> //time()
#include <cstdlib> //rand() and srand()
using namespace std;
//Object Num
int Shapes::objectNum = 0;
Shapes::Shapes()
{
	objectNum += 1;
	num = objectNum;
}
///////////////////////////////////////////////////////////////////////
//
// Function: Shapes() Default                                      
//                                                                   
// Description:
//    The Shapes() function is a Default Constructor of the Shapes class. In this function we will define all the variables of the function with various randomly generated
//	  values for the data members within the function itself. These variables will then be set within the Overloaded Constructor
//
// Parameters:  
//    firstParam  : NA          
//    secondParam : NA               
//                                                       
// Returns:  
//    returnVal : This function does not return values and instead asks as the main definer of what the values of the data members will be.                 
//                                            
///////////////////////////////////////////////////////////////////////
Shapes::Shapes(int _num)
{
	setNum(_num);
}
///////////////////////////////////////////////////////////////////////
//
// Function: Shapes(int _num) Overloaded                                         
//                                                                   
// Description:
//    This function is the Overloaded Constructor, a Constructor of the Shape class. This constructor allows us to call our Mutator Functions and set their variables equal to the data members
//	  we determined in the Default Constructor.
// Parameters:  
//    firstParam  : int _num is the current number of the Shapes being created         
//    secondParam : NA
//
// Returns:  
//    returnVal : This function does not return the value and instead calls the various Mutator Functions that store the values of the parameters mentioned above                 
//    
Shapes::~Shapes()
{
	//Does Nothing. Does housekeeping before object is destroyed.
}
int Shapes::getNum()
{
	return num;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getNum()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the number of the Object is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int num value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
void Shapes::setNum(int newNum)
{
	num = newNum;
}
///////////////////////////////////////////////////////////////////////
//
// Function: setNum(int newNum)                                        
//                                                                   
// Description:
//    This function allows us to set the variable for num from the data member we get from the Default Constructor
//
// Parameters:  
//    firstParam  : int newNum
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : this function does not return a variable and instead sets the num data member from the constructor to newNum, setting num in the Overloaded equal to            
//    num in the Default                
///////////////////////////////////////////////////////////////////////

//Point Functions
int Point::pointNum = 0;
Point::Point()
{
	//Point X & Y
	pointNum += 1;
	num = pointNum;
	pointX = rand() % 10;
	pointY = rand() % 10;
}
///////////////////////////////////////////////////////////////////////
//
// Function: Point() Default                                      
//                                                                   
// Description:
//    The Point() function is a Default Constructor of the Point class. In this function we will define all the variables of the function with various randomly generated
//	  values for the data members within the function itself. These variables will then be set within the Overloaded Constructor
//
// Parameters:  
//    firstParam  : NA          
//    secondParam : NA               
//                                                       
// Returns:  
//    returnVal : This function does not return values and instead asks as the main definer of what the values of the data members will be.                 
//                                            
///////////////////////////////////////////////////////////////////////
Point::Point(int _pointX, int _pointY, int _num) : Shapes(_num)
{
	setPointX(_pointX);
	setPointY(_pointY);
	setNum(_num);
}
///////////////////////////////////////////////////////////////////////
//
// Function: Point(int _pointX, int _pointY, int _num) Overloaded                                         
//                                                                   
// Description:
//    This function is the Overloaded Constructor, a Constructor of the Point class. This constructor allows us to call our Mutator Functions and set their variables equal to the data members
//	  we determined in the Default Constructor.
// Parameters:  
//    firstParam  : int _pointX is the value of point x          
//    secondParam : int _pointY is the value of point y
//	  thirdParam  : int _num is the current number of the Point being created
//
// Returns:  
//    returnVal : This function does not return the value and instead calls the various Mutator Functions that store the values of the parameters mentioned above                 
//                                            
Point::~Point()
{
	pointNum -= 1;
	//Does Nothing. Does housekeeping before object is destroyed.
}
///////////////////////////////////////////////////////////////////////
//
// Function: ~Point() Desconstructor                                         
//                                                                   
// Description:
//    This function is the Deconstrucor, it cleans up the object before destroying. 
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : NA               
//                                            
///////////////////////////////////////////////////////////////////////
//Accessors
int Point::getPointX()
{
	return pointX;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getPointX()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the point X is and returns that value back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int pointX value that we will display to the user                
//                                            
///////////////////////////////////////////////////////////////////////
int Point::getPointY()
{
	return pointY;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getPointY()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the point Y is and returns that value back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int pointY value that we will display to the user                
//                                            
///////////////////////////////////////////////////////////////////////
int Point::getNum()
{
	return num;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getNumt()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the number of the Object is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int num value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
//Mutators
void Point::setPointX(int newX)
{
	pointX = newX;
}
///////////////////////////////////////////////////////////////////////
//
// Function: setPointX(int newX)                                        
//                                                                   
// Description:
//    This function allows us to set the variable for the x point from the data member we get from the Default Constructor
//
// Parameters:  
//    firstParam  : int newX
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : this function does not return a variable and instead sets the pointX data member from the constructor to newX, setting pointX in the Overloaded equal to            
//    pointX in the Default                
///////////////////////////////////////////////////////////////////////
void Point::setPointY(int newY)
{
	pointX = newY;
}
///////////////////////////////////////////////////////////////////////
//
// Function: setPointY(int newY)                                        
//                                                                   
// Description:
//    This function allows us to set the variable for the y point from the data member we get from the Default Constructor
//
// Parameters:  
//    firstParam  : int newY
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : this function does not return a variable and instead sets the pointY data member from the constructor to newY, setting pointY in the Overloaded equal to            
//    pointY in the Default                
///////////////////////////////////////////////////////////////////////
void Point::setNum(int newNum)
{
	num = newNum;
}
///////////////////////////////////////////////////////////////////////
//
// Function: setNum(int newNum)                                        
//                                                                   
// Description:
//    This function allows us to set the variable for num from the data member we get from the Default Constructor
//
// Parameters:  
//    firstParam  : int newNum
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : this function does not return a variable and instead sets the num data member from the constructor to newNum, setting num in the Overloaded equal to            
//    num in the Default                
///////////////////////////////////////////////////////////////////////
void Point::display()
{
	cout << "\nThe Points" << endl;
	cout << "This is Point Number: #" << num << endl;
	cout << "Point X is: " << pointX << endl;
	cout << "Point Y is: " << pointY << endl;
}
///////////////////////////////////////////////////////////////////////
//
// Function: display                                        
//                                                                   
// Description:
//    This function allows us to Display all the Data members information for the user to see
//
// Parameters:  
//    firstParam  : NA
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : NA              
///////////////////////////////////////////////////////////////////////

string Point::toString()
{
	string pointXStr = to_string(getPointX());
	string pointYStr = to_string(getPointY());
	string numStr = to_string(num);
	string finalDesc = "\nThis is Point Number: # " + numStr + "\nPoint X is: " + pointXStr + "\nPoint Y is: " + pointYStr + "\n";
	return finalDesc;
}
///////////////////////////////////////////////////////////////////////
//
// Function: toString()                                     
//                                                                   
// Description:
//    This function allows us to convert the data of the Circle to string variable, combines them, and then returns that value
//
// Parameters:  
//    firstParam  : NA
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : NA              
///////////////////////////////////////////////////////////////////////

//Circle
int Circle::circleNum = 0;
Circle::Circle()
{
	circleNum += 1;
	num = circleNum;
	radius = rand() % 15 + 1;
}
///////////////////////////////////////////////////////////////////////
//
// Function: Circle() Default                                      
//                                                                   
// Description:
//    The Circle() function is a Default Constructor of the Circle class. In this function we will define all the variables of the function with various randomly generated
//	  values for the data members within the function itself. These variables will then be set within the Overloaded Constructor
//
// Parameters:  
//    firstParam  : NA          
//    secondParam : NA               
//                                                       
// Returns:  
//    returnVal : This function does not return values and instead asks as the main definer of what the values of the data members will be.                 
//                                            
///////////////////////////////////////////////////////////////////////
Circle::Circle(int _pointX, int _pointY, int _radius, int _num) : Point(_pointX, _pointY, _num)
{
	setRadius(_radius);
	setNum(_num);
}
///////////////////////////////////////////////////////////////////////
//
// Function: Circle(int _pointX, int _pointY, int _radius, int _num) Overloaded                                         
//                                                                   
// Description:
//    This function is the Overloaded Constructor, a Constructor of the Circle class. This constructor allows us to call our Mutator Functions and set their variables equal to the data members
//	  we determined in the Default Constructor.
// Parameters:  
//    firstParam  : int _pointX is the value of point x from Circle's Base Class Point       
//    secondParam : int _pointY is the value of point y from Circle's Base Class Point
//	  thirdParam  : int _radius is the value of the circle's radius
//	  fourthParam : int _num is the current number of the Circle being created
//
// Returns:  
//    returnVal : This function does not return the value and instead calls the various Mutator Functions that store the values of the parameters mentioned above                 
//                                            
///////////////////////////////////////////////////////////////////////
Circle::~Circle()
{
	circleNum -= 1;
	//Does Nothing. Does housekeeping before object is destroyed.
}
///////////////////////////////////////////////////////////////////////
//
// Function: ~Circle() Desconstructor                                         
//                                                                   
// Description:
//    This function is the Deconstrucor, it cleans up the object before destroying. 
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : NA               
//                                            
///////////////////////////////////////////////////////////////////////
//Mutators
int Circle::getRadius()
{
	return radius;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getRadius()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the radius is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int radius value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
int Circle::getNum()
{
	return num;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getNumt()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the number of the Object is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int num value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
//Accessors
void Circle::setRadius(int newRadius)
{
	radius = newRadius;
}
///////////////////////////////////////////////////////////////////////
//
// Function: setRadius(int newRadius)                                        
//                                                                   
// Description:
//    This function allows us to set the variable for the radius from the data member we get from the Default Constructor
//
// Parameters:  
//    firstParam  : int newRadius
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : this function does not return a variable and instead sets the radius data member from the constructor to newRadius, setting radius in the Overloaded equal to            
//    radius in the Default                
///////////////////////////////////////////////////////////////////////
void Circle::setNum(int newNum)
{
	num = newNum;
}
///////////////////////////////////////////////////////////////////////
//
// Function: setNum(int newNum)                                        
//                                                                   
// Description:
//    This function allows us to set the variable for num from the data member we get from the Default Constructor
//
// Parameters:  
//    firstParam  : int newNum
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : this function does not return a variable and instead sets the num data member from the constructor to newNum, setting num in the Overloaded equal to            
//    num in the Default                
///////////////////////////////////////////////////////////////////////
void Circle::display()
{
	cout << "\nThe Circle" << endl;
	cout << "This is Circle Number: #" << num << endl;
	cout << "Circle X is: " << getPointX() << endl;
	cout << "Circle Y is: " << getPointY() << endl;
	cout << "Circle Radius is: " << radius << endl;
}
///////////////////////////////////////////////////////////////////////
//
// Function: display                                       
//                                                                   
// Description:
//    This function allows us to Display all the Data members information for the user to see
//
// Parameters:  
//    firstParam  : NA
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : NA              
///////////////////////////////////////////////////////////////////////
string Circle::toString()
{
	string pointXStr = to_string(getPointX());
	string pointYStr = to_string(getPointY());
	string radiusStr = to_string(getRadius());
	string numStr = to_string(num);
	string finalDesc = "\nThis is Circle Number: # " + numStr + "\nCircle X is: " + pointXStr + "\nCircle Y is: " + pointYStr + "\nCircle Radius is: " + radiusStr + "\n";
	return finalDesc;
}
///////////////////////////////////////////////////////////////////////
//
// Function: toString()                                     
//                                                                   
// Description:
//    This function allows us to convert the data of the Circle to string variable, combines them, and then returns that value
//
// Parameters:  
//    firstParam  : NA
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : NA              
///////////////////////////////////////////////////////////////////////

//Cylinder
int Cylinder::cylinderNum = 0;
Cylinder::Cylinder()
{
	cylinderNum += 1;
	num = cylinderNum;
	height = rand() % 8 + 1;
}
///////////////////////////////////////////////////////////////////////
//
// Function: Cylinder() Default                                      
//                                                                   
// Description:
//    The Cylinder() function is a Default Constructor of the Cylinder class. In this function we will define all the variables of the function with various randomly generated
//	  values for the data members within the function itself. These variables will then be set within the Overloaded Constructor
//
// Parameters:  
//    firstParam  : NA          
//    secondParam : NA               
//                                                       
// Returns:  
//    returnVal : This function does not return values and instead asks as the main definer of what the values of the data members will be.                 
//        
Cylinder::Cylinder(int _pointX, int _pointY, int _radius, int _height, int _num) : Circle(_pointX, _pointY, _radius, _num)
{
	setHeight(_height);
	setNum(_num);
}
///////////////////////////////////////////////////////////////////////
//
// Function: Cylinder(int _pointX, int _pointY, int _radius, int _height, int _num) Overloaded                                         
//                                                                   
// Description:
//    This function is the Overloaded Constructor, a Constructor of the Cylinder class. This constructor allows us to call our Mutator Functions and set their variables equal to the data members
//	  we determined in the Default Constructor.
// Parameters:  
//    firstParam  : int _pointX is the value of point x that Cylinder's Base Class Circle gets from Circle's Base Class Point          
//    secondParam : int _pointY is the value of point y that Cylinder's Base Class Circle gets from Circle's Base Class Point
//	  thirdParam  : int _radius is the value of the radius that Cylinder's Bae Class Circle gets
//	  fourthParam : int _height is the value of the cylinder's height
//	  fifthParam  : int _num is the current number of the Cylinders being created
//
// Returns:  
//    returnVal : This function does not return the value and instead calls the various Mutator Functions that store the values of the parameters mentioned above                 
//                                            
///////////////////////////////////////////////////////////////////////
Cylinder::~Cylinder()
{
	cylinderNum -= 1;
	//Does Nothing. Does housekeeping before object is destroyed.
}
///////////////////////////////////////////////////////////////////////
//
// Function: ~Cylinder() Desconstructor                                         
//                                                                   
// Description:
//    This function is the Deconstrucor, it cleans up the object before destroying. 
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : NA               
//                                            
///////////////////////////////////////////////////////////////////////
//Mutators
int Cylinder::getHeight()
{
	return height;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getHeight()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the height is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int height value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
int Cylinder::getNum()
{
	return num;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getNumt()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the number of the Object is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int num value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
//Accessors
void Cylinder::setHeight(int newHeight)
{
	height = newHeight;
}
///////////////////////////////////////////////////////////////////////
//
// Function: setHeight(int newHeight)                                        
//                                                                   
// Description:
//    This function allows us to set the variable for the height from the data member we get from the Default Constructor
//
// Parameters:  
//    firstParam  : int newHeight
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : this function does not return a variable and instead sets the height data member from the constructor to newHeight, setting radius in the Overloaded equal to            
//    height in the Default                
///////////////////////////////////////////////////////////////////////
void Cylinder::setNum(int newNum)
{
	num = newNum;
}
///////////////////////////////////////////////////////////////////////
//
// Function: setNum(int newNum)                                        
//                                                                   
// Description:
//    This function allows us to set the variable for num from the data member we get from the Default Constructor
//
// Parameters:  
//    firstParam  : int newNum
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : this function does not return a variable and instead sets the num data member from the constructor to newNum, setting num in the Overloaded equal to            
//    num in the Default                
///////////////////////////////////////////////////////////////////////
void Cylinder::display()
{
	cout << "\nThe Cylinder" << endl;
	cout << "This is Cylinder Number: #" << num << endl;
	cout << "Cylinder X is: " << getPointX() << endl;;
	cout << "Cylinder Y is: " << getPointY() << endl;;
	cout << "Cylinder Radius is: " << getRadius() << endl;;
	cout << "Cylinder Height is: " << height << endl;
}
///////////////////////////////////////////////////////////////////////
//
// Function: display                                      
//                                                                   
// Description:
//    This function allows us to Display all the Data members information for the user to see
//
// Parameters:  
//    firstParam  : NA
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : NA              
///////////////////////////////////////////////////////////////////////
string Cylinder::toString()
{
	string pointXStr = to_string(getPointX());
	string pointYStr = to_string(getPointY());
	string radiusStr = to_string(getRadius());
	string heightStr = to_string(height);
	string numStr = to_string(num);
	string finalDesc = "\nThis is Cylinder Number: # " + numStr + "\nCylinder X is: " + pointXStr + "\nCylinder Y is: " + pointYStr + "\nCylinder Radius is: " + radiusStr + "\nCylinder Height is: " + heightStr + "\n";
	return finalDesc;
}
///////////////////////////////////////////////////////////////////////
//
// Function: toString()                                     
//                                                                   
// Description:
//    This function allows us to convert the data of the Cylinder to string variable, combines them, and then returns that value
//
// Parameters:  
//    firstParam  : NA
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : NA              
///////////////////////////////////////////////////////////////////////