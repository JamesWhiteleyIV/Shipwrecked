/*********************************************************************
 * File Name: Space.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Implementation of abstract Space class. Represents Locations
 * for Player to interact with.
 * *******************************************************************/

#include "Space.hpp"

/*********************************************************************
 * Destructor
 * ******************************************************************
Space::~Space() {
    while(!this->spaceItems.empty()) {
        delete this->spaceItems.back();
        this->spaceItems.pop_back();
    }
    
    this->Top = nullptr;
    this->Bottom = nullptr;
    this->Right = nullptr;
    this->Left = nullptr;
}
 */

/*********************************************************************
 * Sets objects 4 pointers.
 * *******************************************************************/
void Space::set(Space *top, Space *bottom, Space *right, Space *left) {
    this->Top = top;
    this->Bottom = bottom;
    this->Right = right;
    this->Left = left;
}


/*********************************************************************
 * Return's space to Top
 * *******************************************************************/
Space* Space::getTop() {
    return this->Top;
}

/*********************************************************************
 * Return's space to Bottom
 * *******************************************************************/
Space* Space::getBottom() {
    return this->Bottom;
}

/*********************************************************************
 * Return's space to Right
 * *******************************************************************/
Space* Space::getRight() {
    return this->Right;
}

/*********************************************************************
 * Return's space to Left
 * *******************************************************************/
Space* Space::getLeft() {
    return this->Left;
}

/*********************************************************************
 * Return's space objects visited boolean, decides what menu to use.
 * *******************************************************************/
bool Space::hasVisited() {
    return this->visited;
}

/*********************************************************************
 * Sets Space object's visited bool to true.
 * *******************************************************************/
void Space::visitedTrue() {
    this->visited = true;
}

/*********************************************************************
 * Adds item to Space object's spaceItems vector.
 * *******************************************************************/
void Space::addItem(Item * item) {
    this->spaceItems.push_back(item);
}

/*********************************************************************
 * Return's integer representing size of Objects spaceItems inventory vector.
 * *******************************************************************/
int Space::inventorySize() {
    int accumulator = 0;
    
    for(int i = 0; i < int(spaceItems.size()); i++) {
        if(this->spaceItems[i] != nullptr) {
            accumulator++;
        }
    }
    
    return accumulator;
}

/*********************************************************************
 * Return's pointer to an Item in inventory.  Removes it from Space Object.
 * *******************************************************************/
Item *Space::openInventory() {
    cout << "Choose an item to add to backpack: " << endl;
    for(int i=0; i<inventorySize(); i++) {
        cout << i << ". " << this->spaceItems[i]->getName() << endl;
    }
    int choice = getInt(0, inventorySize() - 1);
    cout << string(50, '\n');
    
    Item *temp = this->spaceItems[choice];
    this->spaceItems[choice] = nullptr;
    this->spaceItems.erase(this->spaceItems.begin() + choice);
    return temp;
}
