/*********************************************************************
 * File Name: Ship.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Derived from Space class, Ship class that you need to repair
 * in order to win the game.
 * *******************************************************************/

#include "Ship.hpp"

/*********************************************************************
 * adds 3 items: 2 whiskey and 1 rum to space object items vector in Ship
 * *******************************************************************/
Ship::Ship() {
    this->addItem(new Item("Whiskey", true, -5));
    this->addItem(new Item("Rum", true, -6));
    this->addItem(new Item("Whiskey", true, -5));
}

/*********************************************************************
 * Destructor frees any items in vector of items.
 * *******************************************************************/
Ship::~Ship() {
    while(!this->spaceItems.empty()) {
        delete this->spaceItems.back();
        this->spaceItems.pop_back();
    }
    
    this->Top = nullptr;
    this->Bottom = nullptr;
    this->Right = nullptr;
    this->Left = nullptr;
}

/*********************************************************************
 * Option 1 Opens pack
 * Option 2 opens ship's inventory with option to remove the whiskey or rum,
 *      will add to player's pack and remove from Ship vector.
 * Option 3 Goes to OceanA
 * Option 4 Goes back to Beach
 * Option 5 If player has aquired quest items (plank and sail) the ship object
 *  will be set to visited and the menu will change allowing player to sail ship
 *  and beat the game.
 * returns choice to player object
 * *******************************************************************/
int Ship::menuA() {
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Look in cupboard." << endl;
    cout << "3. Jump into ocean." << endl;
    cout << "4. Go back to beach." << endl;
    cout << "5. Attempt to repair ship." << endl;
    int choice = getInt(1, 5);
    cout << string(50, '\n');
    
    switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            if(this->inventorySize() > 0) {
                return 7;
            }
            else {
                cout << "There is nothing in the cupboard." << endl;
                return 0;
            }
            break;
        case 3:
            cout << "You dive into the frigid ocean." << endl;
            return 2;
            break;
        case 4:
            cout << "You leave the ship and return to the beach." << endl;
            return 3;
            break;
        case 5:
            return 10;
            break;
    }
    
    return 0;
}

/*********************************************************************
 * Option 1 Opens pack
 * Option 2 opens ship's inventory with option to remove the whiskey or rum,
 *      will add to player's pack and remove from Ship vector.
 * Option 3 Goes to OceanA
 * Option 4 Goes back to Beach
 * Option 5 Allows player to sail ship and beat the game.
 * returns choice to player object
 * *******************************************************************/
int Ship::menuB() {
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Look in cupboard." << endl;
    cout << "3. Jump into ocean." << endl;
    cout << "4. Go back to beach." << endl;
    cout << "5. Sail ship." << endl;
    int choice = getInt(1, 5);
    cout << string(50, '\n');
    
    switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            if(this->inventorySize() > 0) {
                return 7;
            }
            else {
                cout << "There is nothing in the cupboard." << endl;
                return 0;
            }
            break;
        case 3:
            cout << "You dive into the frigid ocean." << endl;
            return 2;
            break;
        case 4:
            cout << "You leave the ship and return to the beach." << endl;
            return 3;
            break;
        case 5:
            return 11;
            break;
    }
    return 0;
}
