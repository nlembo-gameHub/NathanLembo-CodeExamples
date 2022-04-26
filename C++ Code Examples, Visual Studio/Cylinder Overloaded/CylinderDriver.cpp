///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: CylindersDriver.cpp
// Date: February 22, 2020
// Programmer: Nathan Lembo             
//
// Description:
//    This program creates 5 Cylinder Objects from the classe in the Cylinder.h header file. 
//    Values are pushed into the parameters of the class objects for both Cylinder1 & 2, those parameters being a double length and radius
//    in the CylinderBuilder.cpp file, these values are used to find the area, volume, and set the radius and lenngth
//    When those values are set in the objects 1 & 2, operations are then performed to create Cylinder Objects 3, 4, and 5.
//                                                                  
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Cylinder.h"
using namespace std;

int main()
{
	Cylinder Cylinder1(5, 3);
	Cylinder Cylinder2(7, 5);
	Cylinder Cylinder3;
	Cylinder Cylinder4;
	Cylinder Cylinder5;

	cout << fixed << showpoint;
	cout << setprecision(2);

	cout << "Cylinder1: " << Cylinder1 << endl;

	cout << "Cylinder2: " << Cylinder2 << endl;

	Cylinder3 = Cylinder1 + Cylinder2;

	cout << "Cylinder1 + Cylinder2 = " << "Cylinder3: " << Cylinder3 << endl;

	Cylinder4 = Cylinder1 - Cylinder2;

	cout << "Cylinder1 - Cylinder2 = " << "Cylinder4: " << Cylinder4 << endl;

	Cylinder5 = Cylinder1 * Cylinder2;

	cout << "Cylinder1 * Cylinder2 = " << "Cylinder5: " << Cylinder5 << endl;

	if (Cylinder1 > Cylinder2)
	{
		cout << "Volume of Cylinder1 is greater than the volume "
			<< "of Cylinder2 ." << endl;
	}
	else
	{
		cout << "Volume of Cylinder1 is less than or equal to the volume "
			<< "of Cylinder2 ." << endl;
	}
		
	Cylinder1++;

	cout << "After increment the radius and height of "
		<< "Cylinder1 by one unit, \nCylinder1: "
		<< Cylinder1 << endl;

	Cylinder4 = ++Cylinder3;
	Cylinder4 = Cylinder3++;

	cout << "New dimension of Cylinder3: " << Cylinder3 << endl;
	cout << "New dimension of Cylinder4: " << Cylinder4 << endl;

	cout << "Cylinder4 is " << (Cylinder4 != Cylinder3 ? "Not Equal to Cylinder3 " : "Equal to Cylinder3") << endl;
	cout << "Cylinder4 is " << (Cylinder4 >= Cylinder3 ? "Greater or Equal to Cylinder3 " : "Not Greater or Equal to Cylinder3 ") << endl;
	cout << "Cylinder4 is " << (Cylinder4 == Cylinder3 ? "Equal to Cylinder3 " : "Not Equal to Cylinder3") << endl;
	cout << "Cylinder4 is " << (Cylinder4 < Cylinder3 ? "Less Than Cylinder3 " : "Not Less Than to Cylinder3") << endl;
	cout << "Cylinder4 is " << (Cylinder4 <= Cylinder3 ? "Less Than or Equal to Cylinder3 " : "Not Less Than or Equal to Cylinder3") << endl;

	system("pause");
	return 0;
}
