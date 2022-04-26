///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: vectorDriver.cpp
// Date: April 11, 2020
// Programmer: Nathan Lembo             
//
// Description:
//    This program creates 4 Vector Objects from the Item class from the item.h file.
//    Values are pushed from the text file inventory.txt into the parameters of the class objects for 
//    vector<Item> inventory. We uses functions getData to fill these paramemters from the text file and
//    sortData to then sort said entries alphabetically by the name of the items in the inventory.
//    We then display a menu with the menu function, allowing the user to interact with the inventory vector
//    to search it to see if a specific item is there, or to buy said item, or find the price of items, or 
//    print out a sheet of what items exist in the inventory with all their data such as stock, price, ect.
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include "item.h"
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;
//getData() reads input file into vectors.
void getData(ifstream& inp, vector<Item> &inventory);
///////////////////////////////////////////////////////////////////////
//
// Function: getData                                       
//                                                                   
// Description:
//    This function takes the data from the inventory text file and inputs it into the vector inventory
//
// Parameters:  
//    firstParam  : ifstream& inp is the parameter of inFile which is the data of the text file          
//    secondParam : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class            
//                                                       
// Returns:  
//    returnVal : NA                
//                                            
///////////////////////////////////////////////////////////////////////

//sortData() sorts data in the vectors
void sortData(vector<Item> &inventory);
///////////////////////////////////////////////////////////////////////
//
// Function: sortData                                       
//                                                                   
// Description:
//    This function takes the data witin inventory's colums/rows and sorts them by alphabetical order
// 
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : NA                
//                                            
///////////////////////////////////////////////////////////////////////
//binSearch returns the index of the data entry if searchItem is found, otherwise it returns -1 (not found)
int binSearch(vector<Item> &inventory);
///////////////////////////////////////////////////////////////////////
//
// Function: binSearch                                      
//                                                                   
// Description:
//    This function takes the positions of the vector<Item> inventory and performs a binary search,
//    allowing the uses to search for the item they typed based on their name
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : returns mid, which is simply the position of the found element in the vector, 
//                or -1 if it isn't found.               
//                                            
///////////////////////////////////////////////////////////////////////

//menu() displays menu
void menu(vector<Item> &inventory);
///////////////////////////////////////////////////////////////////////
//
// Function: menu                                     
//                                                                   
// Description:
//    This function sets up the console menu for the player to look over and interact with.
//    Giving a user range of selections to choose to interact with the inventory vector by calling the various functions
//    whether it be to buy items, print out the entire inventory, or search for them the menu gives the player these options
//    until they enter 9 to exit out of the program. 
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : NA              
//                                            
///////////////////////////////////////////////////////////////////////

//printReport() displays all of the data.
void printReport(const vector<Item> &inventory);
///////////////////////////////////////////////////////////////////////
//
// Function: printReport                                    
//                                                                   
// Description:
//    This function is called from the menu function and prints the entirity of the vector inventory for the player to see
//    This list updates depending on what the player sells, changing the pSold and the pInStore.
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : NA              
//                                            
///////////////////////////////////////////////////////////////////////

//makeSale() prompts user for item and number of pieces and displays the amount due (You don't need to remember total)
void makeSale(vector<Item> &inventory);
///////////////////////////////////////////////////////////////////////
//
// Function: makeSale                                    
//                                                                   
// Description:
//    This function is called from the menu function and asks the player to enter an item name. Searchs for it
//    and then prints the price and asks for how much the player wishes to buy. It then charges the player that amount
//    and them subtracts and adds the correct values to the pInStore and pSold.
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : NA              
//                                            
///////////////////////////////////////////////////////////////////////

void checkPrice(vector<Item> &inventory);
///////////////////////////////////////////////////////////////////////
//
// Function: makeSale                                    
//                                                                   
// Description:
//    This function is called from the menu function and asks the player to enter an item name. Searchs for it
//    and then prints the price of that item;
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : NA              
//                                            
///////////////////////////////////////////////////////////////////////


int main()
{
	const int size = 4;
	vector<Item> inventory(size);
	ifstream inFile;
	inFile.open("inventory.txt");
	if (!inFile)
	{
		cout << "Input file inventory.txt" << endl;
		return 1;
	}
	cout << "Welcome to the Friendly Hardware Store!" << endl;
	getData(inFile, inventory);
	sortData(inventory);
	menu(inventory);
	cout << endl;
	inFile.close();
	system("pause");
	return 0;
}

void getData(ifstream& inp, vector<Item> &inventory)
{
	unsigned int i = 0;

	/*while (inp >> inventory[i])
	{
		//cout << inventory[i];
		i++;
	}*/
	for (i = 0; i < inventory.size(); i++)
	{
		inp >> inventory[i];
	}
		
}
///////////////////////////////////////////////////////////////////////
//
// Function: getData                                       
//                                                                   
// Description:
//    This function takes the data from the inventory text file and inputs it into the vector inventory
//
// Parameters:  
//    firstParam  : ifstream& inp is the parameter of inFile which is the data of the text file          
//    secondParam : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class            
//                                                       
// Returns:  
//    returnVal : NA                
//                                            
///////////////////////////////////////////////////////////////////////
void sortData(vector<Item> &inventory)
{
	/*
	Item temp;
	for (unsigned int firstOutOfOrder = 1; firstOutOfOrder < inventory.size(); firstOutOfOrder++)
	{
		if (inventory[firstOutOfOrder].getName() < inventory[firstOutOfOrder - 1].getName())
		{
			temp = inventory[firstOutOfOrder];
			unsigned int location = firstOutOfOrder;
			//inventory[i] = inventory[i1-]
			do
			{
				inventory[location] = inventory[location - 1];
			} 
			while (location > 0 && inventory[location - 1] > temp);

			inventory[location] = temp;
		}
	}*/

	
	unsigned int firstOutOfOrder, location;
	Item tempItem;
	for (firstOutOfOrder = 1; firstOutOfOrder < inventory.size(); firstOutOfOrder++)
	{
		if (inventory[firstOutOfOrder].getName() < inventory[firstOutOfOrder - 1].getName())
		{
			tempItem = inventory[firstOutOfOrder];
			location = firstOutOfOrder;
			do
			{
				inventory[location] = inventory[location - 1];
				location--;
			} 
			while (location > 0 && inventory[location - 1].getName() > tempItem.getName());

			inventory[location] = tempItem;
		}
	}

}
///////////////////////////////////////////////////////////////////////
//
// Function: sortData                                       
//                                                                   
// Description:
//    This function takes the data witin inventory's colums/rows and sorts them by alphabetical order
// 
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : NA                
//                                            
///////////////////////////////////////////////////////////////////////
int binSearch(vector<Item> &inventory)
{

	/*
	unsigned int first = 0;
	unsigned int last = inventory.size() - 1;
	unsigned int mid;
	bool found = false;
	string itemName = " ";
	cout << "Enter the Item name Here: ";
	cin.ignore();
	getline(cin, itemName);
	cout << itemName << endl;
	while (!found && first <= last)
	{
		mid = (first + last) / 2;
		cout << mid << endl;
		if (inventory[mid].getName() == itemName)
		{
			cout << "Found It!" << endl;
			found = true;
			cout << inventory[mid].getName() << endl;
		}
		else if (inventory[mid].getName() == itemName)
		{
			cout << "Moving Down the List" << endl;
			last = mid - 1;
			cout << inventory[mid].getName() << endl;
		}
		else
		{
			cout << "Moving Up the List" << endl;
			first = mid + 1;
			cout << inventory[mid].getName() << endl;
		}
	}
	if (found)
	{
		return mid;
	}
	else
	{
		return -1;
	}*/
	int first = 0;
	int last = inventory.size() - 1;
	int mid;
	bool found = false;
	string searchItem;
	cout << "Enter your Item Here: ";
	cin.ignore();
	getline(cin, searchItem);
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (inventory[mid].getName() < searchItem)
		{
			first = mid + 1;
		}
		else if (inventory[mid].getName() > searchItem)
		{
			last = mid - 1;
		}
		else
		{
			cout << inventory[mid].getName() << " is in store with a stock of: " << inventory[mid].getPinStore() << endl;
			cout << "Position in the vector is: ";
			return mid;
		}
	}
	return -1;
}
///////////////////////////////////////////////////////////////////////
//
// Function: binSearch                                      
//                                                                   
// Description:
//    This function takes the positions of the vector<Item> inventory and performs a binary search,
//    allowing the uses to search for the item they typed based on their name
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : returns mid, which is simply the position of the found element in the vector, 
//                or -1 if it isn't found.               
//                                            
///////////////////////////////////////////////////////////////////////
void menu(vector<Item> &inventory)
{
	char menuAnswer = ' ';
	string itemName = " ";
		while (menuAnswer != '9')
		{
			menuAnswer = ' ';
			cout << "\nChoose the Following Options!" << endl;
			cout << "Type '1' to check if an item is in the store." << endl;
			cout << "Type '2' to buy an item." << endl;
			cout << "Type '3' to check the price of an item." << endl;
			cout << "Type '4' to print the inventory." << endl;
			cout << "Type '9' to exit the program" << endl;
			cin >> menuAnswer;
			if (menuAnswer == '1')
			{
				cout << binSearch(inventory);

			}
			else if (menuAnswer == '2')
			{
				makeSale(inventory);
			}
			else if (menuAnswer == '3')
			{

				checkPrice(inventory);

			}
			else if (menuAnswer == '4')
			{
				printReport(inventory);
			}
		}

}
///////////////////////////////////////////////////////////////////////
//
// Function: menu                                     
//                                                                   
// Description:
//    This function sets up the console menu for the player to look over and interact with.
//    Giving a user range of selections to choose to interact with the inventory vector by calling the various functions
//    whether it be to buy items, print out the entire inventory, or search for them the menu gives the player these options
//    until they enter 9 to exit out of the program. 
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : NA              
//                                            
///////////////////////////////////////////////////////////////////////
void makeSale(vector<Item> &inventory) 
{
	Item temp;
	string itemName = " ";
	int amountBought = 0;
	cout << "Enter Item Name: " << endl;
	cin.ignore();
	getline(cin, itemName);

	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		if (itemName == inventory[i].getName())
		{
			cout << "Enter the amount you purchase: ";
			cin >> amountBought;
			cout << endl;
			cout << "The Price of " << inventory[i].getName() << " is: " << (inventory[i].getSellingPrice() * amountBought);

			inventory[i].setValues((inventory[i].getId()), (inventory[i].getName()), (inventory[i].getPordered()), 
				(inventory[i].getPinStore()-amountBought), (inventory[i].getPsold()+amountBought), (inventory[i].getManufPrice()), (inventory[i].getSellingPrice()));
		}
	}
	

}
///////////////////////////////////////////////////////////////////////
//
// Function: makeSale                                    
//                                                                   
// Description:
//    This function is called from the menu function and asks the player to enter an item name. Searchs for it
//    and then prints the price and asks for how much the player wishes to buy. It then charges the player that amount
//    and them subtracts and adds the correct values to the pInStore and pSold.
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : NA              
//                                            
///////////////////////////////////////////////////////////////////////
void checkPrice(vector<Item> &inventory)
{
	Item temp;
	string itemName = " ";
	cout << "Enter Item Name: " << endl;
	cin.ignore();
	getline(cin, itemName);

	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		if (itemName == inventory[i].getName())
		{
			cout << "The Price of " << inventory[i].getName() << " is: " << (inventory[i].getSellingPrice());
		}
	}
}
///////////////////////////////////////////////////////////////////////
//
// Function: makeSale                                    
//                                                                   
// Description:
//    This function is called from the menu function and asks the player to enter an item name. Searchs for it
//    and then prints the price of that item;
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : NA              
//                                            
///////////////////////////////////////////////////////////////////////
void printReport(const vector<Item> &inventory)
{
	double inventoryTotalValue = 0;
	double inventoryTotalItems = 0;
	cout << " ItemID " << setw(10) << " Name " << setw(15) << " POrdered " << setw(10) << " pInStore " << setw(10) << " pSold " << setw(10) << " manufPrice " << setw(10) << " sellingPrice " << setw(10) << "\n";
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i];

		inventoryTotalValue += (inventory[i].getSellingPrice() * inventory[i].getPinStore());
		inventoryTotalItems += inventory[i].getPinStore();
	}

	cout << "Total Inventory: $" << inventoryTotalValue << endl;
	cout << "Total number of items in the store: " << inventoryTotalItems;
}
///////////////////////////////////////////////////////////////////////
//
// Function: printReport                                    
//                                                                   
// Description:
//    This function is called from the menu function and prints the entirity of the vector inventory for the player to see
//    This list updates depending on what the player sells, changing the pSold and the pInStore.
// Parameters:  
//    firstParam  : vector<Item> &inventory is the parameter of vector<Item> inventory which
//                  is the data of the inventory vector that holds all the variables of the Item Class         
//    secondParam :            
//                                                       
// Returns:  
//    returnVal : NA              
//                                            
///////////////////////////////////////////////////////////////////////