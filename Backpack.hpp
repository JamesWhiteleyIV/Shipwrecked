/*********************************************************************
 * File Name: Backpack.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for Backpack.cpp.
 * *******************************************************************/

#ifndef Backpack_hpp
#define Backpack_hpp
#include "Item.hpp"
#include <stdio.h>

class Backpack {
private:
    Item* items[5];
public:
    Backpack();
    ~Backpack();
    int useItem();
    void removeItem();
    void removeItemAt(int);
    void addItem(Item*);
    int numItems();
    int getItemSPat(int);
    
};

#endif /* Backpack_hpp */
