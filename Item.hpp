/*********************************************************************
 * File Name: Item.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for Item.cpp.
 * *******************************************************************/

#ifndef Item_hpp
#define Item_hpp
#include <string>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Item {
private:
    std::string name;
    bool usable;
    int survivalPointsAffect;
public:
    Item(std::string name, bool usable, int SP);
    ~Item() {};
    std::string getName();
    bool isUsable();
    int getSP();
};

#endif /* Item_hpp */
