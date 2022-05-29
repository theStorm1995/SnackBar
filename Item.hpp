#ifndef ITEM_HPP
#define ITEM_HPP

/**
 * @file Item.hpp
 * @author Nathan Storm (nathanstorm95@gmail.com)
 * @brief This will be a class of items in a snack bar.
 * @version 0.1
 * @date 2022-05-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <string>

namespace theStorm95::SnackBar
{
    class Item
    {
        //
        public:

            // CTORs 
            Item();
            Item(std::string name, float price, size_t quantity);

            // Getters
            std::string getName() const;
            float getPrice() const;
            size_t getQuantity() const;

            // Methods
            void adjustName(std::string name);
            void adjustQuantity(int new_quantity);
            void adjustPrice(float new_price);

        //
        private:

            // Data members
            std::string name_ = "";
            float price_ = 0.00;
            size_t quantity_ = 0;
    };
}




#endif