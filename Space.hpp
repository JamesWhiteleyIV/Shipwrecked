/*********************************************************************
 * File Name: Space.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for Space.cpp.
 * *******************************************************************/

#ifndef Space_hpp
#define Space_hpp
#include "Item.hpp"
#include <vector>
#include <stdio.h>
#include "utility.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Space {
protected:
    Space *Top = nullptr;
    Space *Bottom = nullptr;
    Space *Right = nullptr;
    Space *Left = nullptr;
    bool visited = false;
    vector<Item*> spaceItems;
public:
    Space() {};
    virtual ~Space() {};
    virtual int menuA() {return 0;};
    virtual int menuB() {return 0;};
    void set(Space*, Space*, Space*, Space*);
    Space *getTop();
    Space *getBottom();
    Space *getRight();
    Space *getLeft();
    bool hasVisited();
    void visitedTrue();
    void addItem(Item*);
    int inventorySize();
    Item *openInventory();
    
};

#endif /* Space_hpp */
