/**
 * @file Item.cpp
 * @author your name (nathanstorm95)
 * @brief Implementation of Item.hpp
 * @version 0.1
 * @date 2022-05-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//
#include "Item.hpp"

//
#include <string>
#include <iostream>


namespace theStorm95::SnackBar
{
    // Empty Constructor
    Item::Item(){}

    // 3 arg Constructor
    Item::Item(std::string name, float price, size_t quantity) : name_(name), price_(price), quantity_(quantity) {}

    //
    std::string Item::getName() const {return name_;}

    // 
    float Item::getPrice() const {return price_;}

    //
    size_t Item::getQuantity() const {return quantity_;}

    //
    void Item::adjustName(std::string name) {
        name_ = name;
    }

    //
    void Item::adjustPrice(float price) {
        price_ = price;
    }

    //
    void Item::adjustQuantity(int quantity) {
        quantity_ = quantity;
    }
}
