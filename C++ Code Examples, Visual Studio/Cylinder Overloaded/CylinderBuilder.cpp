///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: CylindersBuilder.cpp
// Date: February 22, 2020
// Programmer: Nathan Lembo             
//
// Description:
//    This Program is designed to run through the various data members and function members of the Classes created in the header file and fill in the empty variables
//    and set, get, and display those various variables through the functions.
//                                                                  
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Cylinder.h"
#include <cmath>
using namespace std;

//Constructors
//Overload Constructor
Cylinder::Cylinder(double _length, double _radius)
{
	setDimension(_length, _radius);
}
///////////////////////////////////////////////////////////////////////
//
// Function: Cylinder(int _pointX, int _pointY, int _radius, int _height, int _num) Overloaded                                         
//                                                                   
// Description:
//    This function is the Overloaded Constructor, a Constructor of the Cylinder class. This constructor allows us to call our Mutator Functions and set their variables equal to the data members
//	  we determined in the Default Constructor.
// Parameters:  
//    firstParam  : int _length is the value of length that Cylinder holds      
//    secondParam : int _radius is the value of radius that Cylinder holds
//
// Returns:  
//    returnVal : This function does not return the value and instead calls the various Mutator Functions that store the values of the parameters mentioned above                 
//                                            
///////////////////////////////////////////////////////////////////////
//Constructor
Cylinder::Cylinder()
{
	length = 1;
	radius = 1;
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
Cylinder::~Cylinder()
{
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
//Overload the stream insertion operator
ostream& operator<<(ostream& osObject, const Cylinder& cObject)
{
	cout << fixed << showpoint;
	cout << setprecision(2);
	osObject << "Length = " << cObject.length << "; Radius = " << cObject.radius << "; Volume = " << cObject.volume() << "; Area = " << cObject.area() << endl;
	return osObject;
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator<<                                    
//                                                                   
// Description:
//    This function is a friend stream inseration operation that allows us to return the object values to print out
//
// Parameters:  
//    firstParam  : ostream& osObject 
//    secondParam : const Cylinder& cObject              
//                                                       
// Returns:  
//    returnVal : returns the osObject that we get our object properties from    
//                                            
///////////////////////////////////////////////////////////////////////

//Overload the pre-increment operator
Cylinder Cylinder::operator++()
{
	length++;
	radius++;

	return *this;
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator++                                     
//                                                                   
// Description:
//    This function allows for the pre-increment of a Cylinder object from this class
//
// Parameters:  
//    firstParam  : NA 
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns the pre-incremented length and radius of *this       
//                                            
///////////////////////////////////////////////////////////////////////

//Overload the post-increment operator
Cylinder Cylinder::operator++(int u)
{
	++length;
	++radius;

	return *this;
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator++                                     
//                                                                   
// Description:
//    This function allows for the post-increment of a Cylinder object from this class
//
// Parameters:  
//    firstParam  : int u   
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns the post-incremented length and radius of *this       
//                                            
///////////////////////////////////////////////////////////////////////

//Overload the arthemitic operators
//Overload the operator +
Cylinder Cylinder::operator+(const Cylinder& otherCylinder) const
{
	Cylinder tempCylinder;

	tempCylinder.length = length + otherCylinder.length;
	tempCylinder.radius = radius + otherCylinder.radius;

	return tempCylinder;
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator+                                       
//                                                                   
// Description:
//    This function allows for the addition between two objects from the Cylinder Class
//
// Parameters:  
//    firstParam  : const Cylinder& otherCylinder         
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns a temporary Cylinder that holds the value of the Lengths and Radius added by the other Cylinder              
//                                            
///////////////////////////////////////////////////////////////////////
//Overload the operator -
Cylinder Cylinder::operator-(const Cylinder& otherCylinder) const
{
	Cylinder tempCylinder;

	tempCylinder.length = otherCylinder.length - length;
	tempCylinder.radius = otherCylinder.radius - radius ;

	return tempCylinder;
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator-                                       
//                                                                   
// Description:
//    This function allows for the subtraction between two objects from the Cylinder Class
//
// Parameters:  
//    firstParam  : const Cylinder& otherCylinder         
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns a temporary Cylinder that holds the value of the Lengths and Radius subtracted by the other Cylinder              
//                                            
///////////////////////////////////////////////////////////////////////
//Overloadd the operator *
Cylinder Cylinder::operator*(const Cylinder& otherCylinder) const
{
	Cylinder tempCylinder;

	tempCylinder.length = length * otherCylinder.length;
	tempCylinder.radius = radius * otherCylinder.radius;

	return tempCylinder;
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator*                                       
//                                                                   
// Description:
//    This function allows for the multiplication between two objects from the Cylinder Class
//
// Parameters:  
//    firstParam  : const Cylinder& otherCylinder         
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns a temporary Cylinder that holds the value of the Lengths and Radius multipled by the other Cylinder              
//                                            
///////////////////////////////////////////////////////////////////////
#pragma region Overload Relational Operators
//Overload Relational Operators
//Overload the ==
bool Cylinder::operator==(const Cylinder& otherCylinder) const
{
	return (volume() == otherCylinder.volume());
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator==                                       
//                                                                   
// Description:
//    This function allows for the comparison of volumes with the "Equal To"
//
// Parameters:  
//    firstParam  : const Cylinder& otherCylinder         
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns the volume is == the other Cylinder                
//                                            
///////////////////////////////////////////////////////////////////////
//Overload the !=
bool Cylinder::operator!=(const Cylinder& otherCylinder) const
{
	return (volume() != otherCylinder.volume());
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator!=                                       
//                                                                   
// Description:
//    This function allows for the comparison of volumes with the "Not Equal To"
//
// Parameters:  
//    firstParam  : const Cylinder& otherCylinder         
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns the volume is != the other Cylinder                
//                                            
///////////////////////////////////////////////////////////////////////
//Overload the <=
bool Cylinder::operator<=(const Cylinder& otherCylinder) const
{
	return(volume() <= otherCylinder.volume());
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator<=                                        
//                                                                   
// Description:
//    This function allows for the comparison of volumes with the "Less Than or Equal"
//
// Parameters:  
//    firstParam  : const Cylinder& otherCylinder         
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns the volume is <= the other Cylinder                
//                                            
///////////////////////////////////////////////////////////////////////
//Overload the operator <
bool Cylinder::operator<(const Cylinder& otherCylinder) const
{
	return(volume() < otherCylinder.volume());
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator<                                        
//                                                                   
// Description:
//    This function allows for the comparison of volumes with the "Less Than"
//
// Parameters:  
//    firstParam  : const Cylinder& otherCylinder         
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns the volume is < the other Cylinder                
//                                            
///////////////////////////////////////////////////////////////////////
//Overload the operator >=
bool Cylinder::operator>=(const Cylinder& otherCylinder) const
{
	return(volume() >= otherCylinder.volume());
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator>=                                       
//                                                                   
// Description:
//    This function allows for the comparison of volumes with the "Greater Than or Equal To"
//
// Parameters:  
//    firstParam  : const Cylinder& otherCylinder         
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns the volume is >= the other Cylinder                
//                                            
///////////////////////////////////////////////////////////////////////
//Overload the operator >
bool Cylinder::operator>(const Cylinder& otherCylinder) const
{
	return(volume() > otherCylinder.volume());
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator>                                        
//                                                                   
// Description:
//    This function allows for the comparison of volumes with the "Greater Than"
//
// Parameters:  
//    firstParam  : const Cylinder& otherCylinder         
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns the volume is > the other Cylinder                
//                                            
///////////////////////////////////////////////////////////////////////

#pragma endregion End of Relational Operators


//Mutators
void Cylinder::setDimension(double newL, double newR)
{
	length = newL;
	radius = newR;
}
///////////////////////////////////////////////////////////////////////
//
// Function: setDimension                                       
//                                                                   
// Description:
//    This function allows us to set the variable for the radius & length from the data member we get from the Default Constructor
//
// Parameters:  
//    firstParam  : double newL
//    secondParam : double nnewR             
//                                                       
// Returns:  
//    returnVal : this function does not return a variable and instead sets the radius  & length data member from the constructor to newL & newR, setting radius & length in the Overloaded equal to            
//    radius & length in the Default                
///////////////////////////////////////////////////////////////////////
#pragma region Accessors
//Accessors
double Cylinder::getLength() const
{
	return length;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getLength()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the lengh is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the double length value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
double Cylinder::getRadius() const
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
//    returnVal : returns the double radius value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////

double Cylinder::volume() const
{
	double volume;
	volume = (3.14 * (radius*radius) * length);
	return volume;
}
///////////////////////////////////////////////////////////////////////
//
// Function: volume                                         
//                                                                   
// Description:
//    This Function allows us to calculate the volume of the cylinder with the radius and length of the cylinder
//
// Parameters:  
//    firstParam  : NA        
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns the total volume of the cylinder                
//                                            
///////////////////////////////////////////////////////////////////////
double Cylinder::area() const
{
	double area;
	area = ((2 * 3.14 * radius * length) + (2 * 3.14 * (radius * radius)));
	return area;
}
///////////////////////////////////////////////////////////////////////
//
// Function: area                                         
//                                                                   
// Description:
//    This Function allows us to calculate the area of the cylinder with the radius and length of the cylinder
//
// Parameters:  
//    firstParam  : NA        
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns the total area of the cylinder                
//                                            
///////////////////////////////////////////////////////////////////////

void Cylinder::print() const
{
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << "Length = " << length << "; Radius = " << radius << "; Volume = " << volume() << "; Area = " << area() << endl;
}
///////////////////////////////////////////////////////////////////////
//
// Function: print                                      
//                                                                   
// Description:
//    This function allows us to Print all the Data members information for the user to see
//
// Parameters:  
//    firstParam  : NA
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : NA              
///////////////////////////////////////////////////////////////////////
#pragma endregion End of Accessors

