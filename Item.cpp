/*********************************************************************
 * File Name: Item.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Represents an item.
 * *******************************************************************/

#include "Item.hpp"

/*********************************************************************
 * Returns Item's name as a string.
 * *******************************************************************/
std::string Item::getName() {
    return this->name;
}

/*********************************************************************
 * Returns true if item is usable.
 * *******************************************************************/
bool Item::isUsable() {
    return this->usable;
}

/*********************************************************************
 * Constructor that initializes name, boolean usability, and affect on Player's
 * survival points as integer.
 * *******************************************************************/
Item::Item(std::string name, bool usable , int SP) {
    this->name = name;
    this->usable = usable;
    this->survivalPointsAffect = SP;
}

/*********************************************************************
 * Returns item's affect on survival points as integer.
 * *******************************************************************/
int Item::getSP() {
    return this->survivalPointsAffect;
}
