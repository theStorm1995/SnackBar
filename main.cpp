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

#include "SnackBar.hpp"

#include <iostream>
#include <string>

using theStorm95::SnackBar::SnackBar;
using std::cout;
using std::cin;
using std::endl;

int main() {
    //
    cout << "Welcome to the Snack Bar Inventory" << endl;

    SnackBar my_snack_bar;
    std::string input = "";
    
    while (true) {
        //
        cout << "1. Add Item to Inventory" << endl
             << "2. Remove Item from Inventory" << endl
             << "3. Get current price of Snack Bar Inventory" << endl
             << "4. Change the Inventory of an Item" << endl
             << "5. Change the Price of an Item" << endl
             << "6. Get the Inventory of an Item" << endl
             << "7. Get the Price of an Item" << endl
             << "8. Get the numbe of Items in the Snack Bar" << endl
             << "9. Generate a Shopping List" << endl
        ;

        cout << "Enter an option or press q to quit: ";

        //
        cin >> input;

        if(input == "Q" || "q") {
            break;
        } 
        else if(input == "1") {

        }   
        else if(input == "2") {

        }
        else if(input == "3") {

        }
        else if (input == "4") {

        }
        else if (input == "5") {
            
        }
        else if (input == "6") {

        }
        else if (input == "7") {

        }
        else if (input == "8") {

        }
        else if (input == "9") {

        }
        else {
            break;
        }
    }









    return 0;
}