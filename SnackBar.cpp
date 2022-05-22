/**
 * @file SnackBar.cpp
 * @author Nathan Storm (nathanstorm95@gmail.com)
 * @brief Implementation for SnackBar.hpp
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//
#include "SnackBar.hpp"
#include "Item.hpp"

//
#include <iostream>
#include <string>
#include <algorithm>
#include <list>

namespace theStorm95::SnackBar
{
    //
    SnackBar::SnackBar() { 
        inventory_list_ = new std::list<Item>;
    }

    //
    std::list<Item>* SnackBar::getSnackBarItems() const{
        return inventory_list_;
    }

    //
    float SnackBar::getSnackBarPrice() const {
        return snack_bar_price_;
    }

    //
    size_t SnackBar::getUniqueItems() const {
        return unique_items_;
    }

    //
    size_t SnackBar::getInventoryItem(const std::string & name) const {
        return this->findItem(name).getQuantity();
    }

    //
    float SnackBar::getPriceItem(const std::string & name) const {
        return this->findItem(name).getPrice();
    }

    //
    void SnackBar::changeQuantity(const std::string & name, int new_quantity) {
        //
        Item item = this->findItem(name);
        snack_bar_price_ -= (item.getPrice() * item.getQuantity());

        //
        item.adjustQuantity(new_quantity);
        snack_bar_price_ += (item.getPrice() * new_quantity);
    }

    // 
    void SnackBar::changePrice(const std::string & name, float price) {
        //
        Item item = this->findItem(name);

        //
        item.adjustPrice(price);
    }

    //
    void SnackBar::addItem(std::string name, float price, size_t quantity) {
        //
        Item item(name, price, quantity);
        inventory_list_->push_back(item);

        //
        unique_items_++;
        snack_bar_price_ += (price * quantity);
    }

    //
    void SnackBar::removeItem(const std::string name) {
        // 
        for(auto itr = inventory_list_->begin(); itr != inventory_list_->end(); itr++) {
            //
            if((*itr).getName() == name) {
                inventory_list_->erase(itr);
            }
            else {
                throw std::range_error("Item doesn't exist.");
            }
        }
    }

    //
    std::list<Item> SnackBar::genShoppingList() {
        //
        std::list<Item> shop_list;

        //
        for(auto itr = inventory_list_->begin(); itr != inventory_list_->end(); itr++) {
            if((*itr).getQuantity() <= 5) {
                shop_list.push_back(*itr);
            }
        }

        //
        return shop_list;
    }

    // Helper Methods

    Item SnackBar::findItem(const std::string name) const {
        //
        for(auto itr = inventory_list_->begin(); itr != inventory_list_->end(); itr++) {
            //
            if((*itr).getName() == name) {
                return *itr;
            }
            else {
                throw std::range_error("Item doesn't exist.");
            }
        }
    }
}