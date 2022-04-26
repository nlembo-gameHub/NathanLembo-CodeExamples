///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: vectorBuilder.cpp
// Date: April 11, 2020
// Programmer: Nathan Lembo             
//
// Description:
//    This Program is designed to run through the various data members and function members of the Classes created in the header file and fill in the empty variables
//    and set, get, and display those various variables through the functions as well as operator functions.
//                                                                  
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "item.h"
using namespace std;

ostream& operator<<(ostream& osObject, const Item& cObject)
{
	cout << fixed << showpoint;
	cout << setprecision(2);
	osObject << " " << cObject.id << right << setw(15) << cObject.name << right << setw(8) << cObject.pOrdered << right << setw(10) << cObject.pInStore << right << setw(12) << cObject.pSold << right << setw(12) << cObject.manuPrice << right << setw(15) << cObject.sellingPrice << endl;
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
//    secondParam : const Item& cObject              
//                                                       
// Returns:  
//    returnVal : returns the osObject that we get our object properties from    
//                                            
///////////////////////////////////////////////////////////////////////
istream& operator>>(istream& isObject, Item& cObject)
{
	isObject >> cObject.id;
	isObject.ignore();
	getline(isObject, cObject.name);// getline(isObject,cObject.name);
	isObject >> cObject.pInStore;
	isObject >> cObject.manuPrice >> cObject.sellingPrice;
	return isObject;
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator>>                                    
//                                                                   
// Description:
//    This function is a friend stream inseration operation that allows us to input the object values from the text file
//
// Parameters:  
//    firstParam  : istream& osObject 
//    secondParam : const Item& cObject              
//                                                       
// Returns:  
//    returnVal : returns the osObject that we get our object properties from the text file    
//                                            
///////////////////////////////////////////////////////////////////////
Item Item::operator+(const Item& otherItem) const
{
	Item tempItem;

	tempItem.pSold = otherItem.pSold + pSold;
	return tempItem;
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator+                                       
//                                                                   
// Description:
//    This function allows for the addition between two objects from the Item Class
//
// Parameters:  
//    firstParam  : const Item& otherItem        
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns a temporary Item that holds the value of the Item Class Data Member pSold added         
//                                            
///////////////////////////////////////////////////////////////////////
Item Item::operator-(const Item& otherItem) const
{
	Item tempItem;

	tempItem.pSold = pSold - otherItem.pSold;
	return tempItem;
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator-                                       
//                                                                   
// Description:
//    This function allows for the subtraction between two objects from the Item Class
//
// Parameters:  
//    firstParam  : const Item& otherItem        
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns a temporary Item that holds the value of the Item Class Data Member pSold subtracted              
//                                            
///////////////////////////////////////////////////////////////////////
bool Item::operator<(const Item& otherItem) const
{
	return((getId() < otherItem.getId()) || (getId() == otherItem.getId() && getName() < otherItem.getName()) ||
		(getId() == otherItem.getId() && getName() == otherItem.getName() && getPordered() < otherItem.getPordered()) ||
		(getId() == otherItem.getId() && getName() == otherItem.getName() && getPordered() == otherItem.getPordered() && getPinStore() < otherItem.getPinStore()) ||
		(getId() == otherItem.getId() && getName() == otherItem.getName() && getPordered() == otherItem.getPordered() && getPinStore() == otherItem.getPinStore() && getPsold() < otherItem.getPsold()) ||
		(getId() == otherItem.getId() && getName() == otherItem.getName() && getPordered() == otherItem.getPordered() && getPinStore() == otherItem.getPinStore() && getPsold() == otherItem.getPsold() && getManufPrice() < otherItem.getManufPrice()) ||
		(getId() == otherItem.getId() && getName() == otherItem.getName() && getPordered() == otherItem.getPordered() && getPinStore() == otherItem.getPinStore() && getPsold() == otherItem.getPsold() && getManufPrice() == otherItem.getManufPrice() && getSellingPrice() < otherItem.getSellingPrice()));

	//return(name < otherItem.name);
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator<                                        
//                                                                   
// Description:
//    This function allows for the comparison of volumes with the "Less Than"
//
// Parameters:  
//    firstParam  : const Item& otherItem       
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns that the data members are < the other Item               
//                                            
///////////////////////////////////////////////////////////////////////
bool Item::operator>(const Item& otherItem) const
{
	
	return((getId() > otherItem.getId()) || (getId() == otherItem.getId() && getName() > otherItem.getName()) ||
		(getId() == otherItem.getId() && getName() == otherItem.getName() && getPordered() > otherItem.getPordered()) ||
		(getId() == otherItem.getId() && getName() == otherItem.getName() && getPordered() == otherItem.getPordered() && getPinStore() > otherItem.getPinStore()) ||
		(getId() == otherItem.getId() && getName() == otherItem.getName() && getPordered() == otherItem.getPordered() && getPinStore() == otherItem.getPinStore() && getPsold() > otherItem.getPsold()) ||
		(getId() == otherItem.getId() && getName() == otherItem.getName() && getPordered() == otherItem.getPordered() && getPinStore() == otherItem.getPinStore() && getPsold() == otherItem.getPsold() && getManufPrice() > otherItem.getManufPrice()) ||
		(getId() == otherItem.getId() && getName() == otherItem.getName() && getPordered() == otherItem.getPordered() && getPinStore() == otherItem.getPinStore() && getPsold() == otherItem.getPsold() && getManufPrice() == otherItem.getManufPrice() && getSellingPrice() > otherItem.getSellingPrice()));
		
	//return(name > otherItem.name);
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator>                                        
//                                                                   
// Description:
//    This function allows for the comparison of volumes with the "Greater Than"
//
// Parameters:  
//    firstParam  : const Item& otherItem         
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns that the data members are > the other Item                
//                                            
///////////////////////////////////////////////////////////////////////
bool Item::operator==(const Item& otherItem) const
{
	return((getName() == otherItem.getName()) && (getId() == otherItem.getId()) && (getPordered() == otherItem.getPordered()) 
		&& (getPinStore() == otherItem.getPinStore() && (getPsold() == otherItem.getPsold()) 
			&& (getManufPrice() == otherItem.getManufPrice()) && (getSellingPrice() == otherItem.getSellingPrice())));
	//return(name == otherItem.name);
}
///////////////////////////////////////////////////////////////////////
//
// Function: operator==                                       
//                                                                   
// Description:
//    This function allows for the comparison of volumes with the "Equal To"
//
// Parameters:  
//    firstParam  : const Item& otherItem        
//    secondParam : NA              
//                                                       
// Returns:  
//    returnVal : returns that the data members are == the other Item               
//                                            
///////////////////////////////////////////////////////////////////////
Item::Item()
{
	id = 0;
	name = " ";
	pOrdered = 0;
	pInStore = 0;
	pSold = 0;
	manuPrice = 0;
	sellingPrice = 0;
}
///////////////////////////////////////////////////////////////////////
//
// Function: Item() Default                                      
//                                                                   
// Description:
//    The Item() function is a Default Constructor of the Item class. In this function we will instantiate all the variables of the class. 
//    These variables will then be set within the Overloaded Constructor
//
// Parameters:  
//    firstParam  : NA          
//    secondParam : NA               
//                                                       
// Returns:  
//    returnVal : This function does not return values and instead asks as the main definer of what the values of the data members will be.                 
//
Item::Item(int _id, string _itemName, int _pOrdered, int _pInStore, int _pSold, double _manuPrice, double _sellingPrice)
{
	setValues(_id, _itemName, _pOrdered, _pInStore, _pSold, _manuPrice, _sellingPrice);
}
///////////////////////////////////////////////////////////////////////
//
// Function: Item(int _id, string _itemName, int _pOrdered, int _pInStore, 
//                int _pSold, double _manuPrice, double _sellingPrice) Overloaded                                         
//                                                                   
// Description:
//    This function is the Overloaded Constructor, a Constructor of the Item class. This constructor allows us to call our Mutator Functions and set their variables equal to the data members
//	  we determined in the Default Constructor.
// Parameters:  
//    firstParam  : int _id is the value of id that Item holds   
//    secondParam : string _itemName is the value of string that Item holds
//    thirdParam  : int _pOrdered is the value of pOrdered that Item holds
//    fourthParam : int _pInStore is the value of pInStore that Item holds
//    fifthParam  : int _pSold is the value of pSold that Item holds
//    sixthParam  : double _manuPrice is the value of manuPrice that Item holds
//    seventhParam: double _sellingPrice is the value of sellingPrice that Item holds
//
// Returns:  
//    returnVal : This function does not return the value and instead calls the various Mutator Functions that store the values of the parameters mentioned above                 
//                                            
///////////////////////////////////////////////////////////////////////
void Item::setValues(int _id, string _itemName, int _pOrdered, int _pInStore, int _pSold, double _manuPrice, double _sellingPrice)
{
	id = _id;
	name = _itemName;
	pOrdered = _pOrdered;
	pInStore = _pInStore;
	pSold = _pSold;
	manuPrice = _manuPrice;
	sellingPrice = _sellingPrice;
}
///////////////////////////////////////////////////////////////////////
//
// Function: setValues                                       
//                                                                   
// Description:
//    This function allows us to set the variable for the data member we get from the Default Constructor/Overload Construstor
//
// Parameters:  
//    firstParam  : int _id is the value of id that Item holds   
//    secondParam : string _itemName is the value of string that Item holds
//    thirdParam  : int _pOrdered is the value of pOrdered that Item holds
//    fourthParam : int _pInStore is the value of pInStore that Item holds
//    fifthParam  : int _pSold is the value of pSold that Item holds
//    sixthParam  : double _manuPrice is the value of manuPrice that Item holds
//    seventhParam: double _sellingPrice is the value of sellingPrice that Item holds          
//                                                       
// Returns:  
//    returnVal : this function does not return a variable and instead sets the data members from the constructor to equal the variables from the       
//                overloaded constructor          
///////////////////////////////////////////////////////////////////////
int Item::getId() const
{
	return id;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getId()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the id is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int id value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
string Item::getName() const
{
	return name;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getName()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the name is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the string name value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
int Item::getPordered() const
{
	return pOrdered;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getPordered()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the pOrdered is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int pOrdered value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
int Item::getPinStore() const
{
	return pInStore;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getPinStore()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the pInStore is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int pInStore value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
int Item::getPsold() const
{
	return pSold;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getPsold()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the pSold is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the int pSold value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
double Item::getManufPrice() const
{
	return manuPrice;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getManufPrice()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the manuPrice is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the double manuPrice value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////
double Item::getSellingPrice() const
{
	return sellingPrice;
}
///////////////////////////////////////////////////////////////////////
//
// Function: getSellingPrice()                                       
//                                                                   
// Description:
//    This function allows us to analyze what the sellingPrice is and returns those values back to be remembered.
//	  
// Parameters:  
//    firstParam  : NA    
//    secondParam : NA
//
// Returns:  
//    returnVal : returns the double sellingPrice value that we will be displayed to the user                
//                                            
///////////////////////////////////////////////////////////////////////