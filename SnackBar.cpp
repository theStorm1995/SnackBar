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
        shopping_list_ = new std::list<Item>;
    }


    //
    SnackBar::~SnackBar() {
        this->clear();

        //
        delete inventory_list_;
        inventory_list_ = nullptr;

        //
        delete shopping_list_;
        shopping_list_ = nullptr;
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
    void SnackBar::changeQuantity(const std::string & name, size_t new_quantity) {
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
        if(this->itemExists(name)) {
            throw std::out_of_range("Item already exists");
        }

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
        if(!itemExists(name)) {
            throw std::out_of_range("Item doesn't exist.");
        }

        // 
        for(auto itr = inventory_list_->begin(); itr != inventory_list_->end(); ++itr) {
            //
            std::string itr_name = (*itr).getName();

            //
            if(itr_name == name) {
                //
                unique_items_--;
                snack_bar_price_ -= ((*itr).getPrice() * (*itr).getQuantity());
                //
                inventory_list_->erase(itr);
                break;
            }
        }
    }


    //
    std::list<Item>& SnackBar::genShoppingList() {
        //
        for (auto itr = inventory_list_->begin(); itr != inventory_list_->end(); itr++) {
            if((*itr).getQuantity() <= 5) {
                shopping_list_->push_back(*itr);
            }
        }

        //
        return *shopping_list_;
    }


    //
    void SnackBar::clear() {
        inventory_list_->clear();
        shopping_list_->clear();
        unique_items_ = 0;
        snack_bar_price_ = 0;
    }


    //
    bool SnackBar::itemExists(const std::string name) const {
        //
        for(auto itr = inventory_list_->begin(); itr != inventory_list_->end(); itr++) {
            //
            if((*itr).getName() == name) {
                return true;
            }
        }
        
        return false;
    }


    //
    bool SnackBar::isEmpty() const {
        //
        if(unique_items_ == 0) {
            return true;
        }

        return false;
    }


    // Helper Methods

    // 
    Item SnackBar::findItem(const std::string name) const {
        //
        if(!itemExists(name)) {
            throw std::out_of_range("Item not found");
        }

        //
        Item item;

        //
        for(auto itr = inventory_list_->begin(); itr != inventory_list_->end(); itr++) {
            //
            if((*itr).getName() == name) {
                item = *itr;
                break;
            }
        }

        return item;
    }
}