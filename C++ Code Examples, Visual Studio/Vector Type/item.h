///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: item.h
// Date: April 11, 2020
// Programmer: Nathan Lembo             
//
// Description:
//    This header file contains the Item Class that we will then call in the next two programs
//    It initilizes the Classes/Objects of the Item and initializes their data members
//    and the functions to be accessed by the vectorBuilder and vectorDriver Program.
/////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//
// Class: Item                                          
//                                                                   
// Description:
//    This Class takes in the values of the inventory.txt file and sets the parameters, data members, 
//    and functions that allow us to set those values to the appropriate data members 
//    and perform operations with them.
//
//    List of data members:
// int id, string name, int pOrdered, int pInStore, int pSold, double manuPrice, double sellingPrice
//
//    List of member functions:                                       
// friend ostream& operator<<(ostream& osObject, const Item& cObject), friend istream& operator>>(istream& isObject, Item &),
// Item(), Item(int _id, string _itemName, int _pOrdered, int _pInStore, int _pSold, double _manuPrice, double _sellingPrice),
// void setValues(int _id, string _itemName, int _pOrdered, int _pInStore, int _pSold, double _manuPrice, double _sellingPrice),
// bool operator<(const Item& otherItem) const, bool operator>(const Item& otherItem) const, bool operator==(const Item& otherItem) const,
// Item operator+(const Item& otherItem) const, Item operator-(const Item& otherItem) const,
// int getId() const, string getName() const, int getPordered() const, int getPinStore() const, int getPsold() const,
// double getManufPrice() const, double getSellingPrice() const
///////////////////////////////////////////////////////////////////////

class Item
{
	friend ostream& operator<<(ostream& osObject, const Item& cObject);
	friend istream& operator>>(istream& isObject, Item &);
public:
	Item();
	Item(int _id, string _itemName, int _pOrdered, int _pInStore, int _pSold,
		double _manuPrice, double _sellingPrice);
	void setValues(int _id, string _itemName, int _pOrdered, int _pInStore, int _pSold, double _manuPrice, double _sellingPrice);
	bool operator<(const Item& otherItem) const; //Overload the operator <
	bool operator>(const Item& otherItem) const; //Overload the operator <
	bool operator==(const Item& otherItem) const;
	Item operator+(const Item& otherItem) const;
	Item operator-(const Item& otherItem) const;
	int getId() const;
	string getName() const;
	int getPordered() const;
	int getPinStore() const;
	int getPsold() const;
	double getManufPrice() const;
	double getSellingPrice() const;
	//Allowed to Add additional member functions to assist with managing the 
	//item.
private:
	int id; // The item ID
	string name; // The item name
	int pOrdered;
	int pInStore; // Number of pieces kept in the store
	int pSold; // Number of pieces sold 
	double manuPrice; // Manufacturer's price for the item
	double sellingPrice; // Store's selling price
};
#endif