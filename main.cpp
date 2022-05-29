/**
 * @file main.cpp
 * @author Nathan Storm (nathanstorm95@gmail.com)
 * @brief Runs the Snack Bar
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Header Files
#include "SnackBar.hpp"
#include "Item.hpp"

//
#include <iostream>
#include <string>

//
using theStorm95::SnackBar::SnackBar;
using std::cout;
using std::cin;
using std::endl;

// Prototype
void addItem(SnackBar& snack);
void removeItem(SnackBar& snack);
void changeInventory(SnackBar& snack);
void chagePrice(SnackBar& snack);


int main() {
    //
    cout << "\nWelcome to the Snack Bar Inventory\n" << endl;

    //
    SnackBar snack;
    std::string input = "";
    
    //
    while (true) {
        //
        cout << "1. Add Item to Inventory" << endl
             << "2. Remove Item from Inventory" << endl
             << "3. Get current price of Snack Bar Inventory" << endl
             << "4. Change the Inventory of an Item" << endl
             << "5. Change the Price of an Item" << endl
             << "6. Get the Inventory of an Item" << endl
             << "7. Get the Price of an Item" << endl
             << "8. Get the number of Items in the Snack Bar" << endl
             << "9. Generate a Shopping List" << endl
        ;

        cout << "\nEnter an option or press q to quit: ";

        //
        cin >> input;
        cout << "Your Input: " << input << endl;

        // Quit 
        if(input == "Q" || input == "q") {
            break;
        } 

        // Add an Item
        else if(input == "1") {
            addItem(snack);
        } 

        // Remove an Item
        else if(input == "2") {
            removeItem(snack);
        }

        // Current Snack Bar Price 
        else if(input == "3") {
            cout << "\nCurrent Price of Snack Bar Inventory is: " << snack.getSnackBarPrice() << endl;
            cout << "\n";
        }

        // Change the Inventory of an Item
        else if (input == "4") {
            changeInventory(snack);
        }

        // Change price of Item
        else if (input == "5") {
            chagePrice(snack);
        }

        // Get Inventory of Item
        else if (input == "6") {
            //
            std::string name = "";

            //
            cout << "\n***Inventory of Item***" << endl;
            cout << "Enter the name of the Item: ";
            cin >> name;
            cout << "Current Inventory is: " << snack.getInventoryItem(name)
                 << "\n" << endl;

        }

        //
        else if (input == "7") {

        }
        
        // Prints number of Items in SnackBar
        else if (input == "8") {
            cout << "\nNumber of Items in the Snack Bar is: " << snack.getUniqueItems() << endl;
            cout << "\n";
        }
        
        // 
        else if (input == "9") {

        }

        //
        else {
            cout << "Invalid Input!";
        }
    }
    return 0;
}

//
void addItem(SnackBar& snack) {
    //
    std::string name = "";
    float price = 0.00;
    size_t quantity = 0;
            
    //
    cout << "\nEnter the following about the item to be added: \n" << endl;
    cout << "Name: ";
    cin >> name;
            
    //
    cout << "Price: ";
    cin >> price;

    //
    cout << "Quantity: ";
    cin >> quantity;
    cout << "\n";

    //
    snack.addItem(name, price, quantity);
}

//
void removeItem(SnackBar& snack) {
    //
    std::string name = "";

    // 
    cout << "\nEnter the name of the Item to remove: ";
    cin >> name;
    cout << "\n";

    // 
    snack.removeItem(name);
}

//
void changeInventory(SnackBar& snack) {
    // 
    std::string name = "";
    size_t quantity = 0;

    // 
    cout << "\n***Change Item Inventory***" << endl;
    cout << "Enter the name of the Item: ";
    cin >> name;

    //
    cout << "Enter the new Quantity: ";
    cin >> quantity;
    snack.changeQuantity(name, quantity);

    // 
    cout << "New Inventory for " << name << " is " 
         << snack.getInventoryItem(name) << "\n" << endl;
}

void changePrice(SnackBar& snack) {
        // 
    std::string name = "";
    float price = 0.00;

    // 
    cout << "\n***Change Item Price***" << endl;
    cout << "Enter the name of the Item: ";
    cin >> name;

    //
    cout << "Enter the new Price: ";
    cin >> price;
    snack.changePrice(name, price);

    // 
    cout << "New Inventory for " << name << " is " 
         << snack.getPriceItem(name) << "\n" << endl;
}