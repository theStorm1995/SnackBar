#ifndef SNACKBAR_HPP
#define SNACKBAR_HPP

/**
 * @file SnackBar.hpp
 * @author Nathan Storm (nathanstorm95@gmail.com)
 * @brief Snack Bar main file
 * @version 0.1
 * @date 2022-05-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//
#include "Item.hpp"


//
#include <iostream>
#include <string>
#include <algorithm>
#include <list>

//
namespace theStorm95::SnackBar
{
    class SnackBar 
    {
        //
        public:

            // CTORS
            SnackBar();

            // DTORS
            ~SnackBar();

            // Accessors 
            std::list<Item>* getSnackBarItems() const;
            float getSnackBarPrice() const;
            size_t getUniqueItems() const;

            // Get Item information
            size_t getInventoryItem(const std::string & name) const;
            float getPriceItem(const std::string & name) const;

            // Change Item info
            void changeQuantity(const std::string & name, size_t quantity);
            void changePrice(const std::string & name, float price);

            // Add/Remove Items
            void addItem(std::string name, float price, size_t quantity);
            void removeItem(std::string name);

            // Generate Shopping list
            std::list<Item>& genShoppingList();

            // Cleanup
            void clear();

            // Exists 
            bool itemExists(const std::string name) const;

            // Empty
            bool isEmpty() const;

        private:

            // Helper Methods

            /**
             * This method will recieve the name of an item and return its object
             */

            Item findItem(const std::string name) const;

            // Data Variable

            std::list<Item> * inventory_list_ = nullptr;
            std::list<Item> * shopping_list_ = nullptr;

            size_t unique_items_ = 0; 

            float snack_bar_price_ = 0;

    };
}







#endif