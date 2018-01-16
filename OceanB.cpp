/*********************************************************************
 * File Name: OceanB.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Derived from Space class, OceanB class.
 * *******************************************************************/

#include "OceanB.hpp"

/*********************************************************************
 * adds 9 Salt Water items to space object items vector in Ocean B
 * *******************************************************************/
OceanB::OceanB() {
    this->addItem(new Item("Salt Water", true, -10));
    this->addItem(new Item("Salt Water", true, -10));
    this->addItem(new Item("Salt Water", true, -10));
    this->addItem(new Item("Salt Water", true, -10));
    this->addItem(new Item("Salt Water", true, -10));
    this->addItem(new Item("Salt Water", true, -10));
    this->addItem(new Item("Salt Water", true, -10));
    this->addItem(new Item("Salt Water", true, -10));
    this->addItem(new Item("Salt Water", true, -10));
}

/*********************************************************************
 * Destructor frees any items in vector of items.
 * *******************************************************************/
OceanB::~OceanB() {
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
 * Option 1 kills player
 * Option 2 kills player
 * Option 3 kills player
 * Option 4 changes object to visited and updates menu
 * returns choice to player object
 * *******************************************************************/
int OceanB::menuA() {
    cout << "A shark has appeared!!  It swims up to you and asks..." << endl;
    cout << "10 fish are in a tank, 2 drown, 4 swim away, and 3 die.  How many fish are left?" << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Answer 1" << endl;
    cout << "2. Answer 2" << endl;
    cout << "3. Answer 7" << endl;
    cout << "4. Answer 10" << endl;
    
    int choice = getInt(1, 4);
    cout << string(50, '\n');
    
    switch (choice) {
        case 1:
            cout << "WRONG ANSWER!!!!  The shark eats you!" << endl;
            return 6;
            break;
        case 2:
            cout << "WRONG ANSWER!!!!  The shark eats you!" << endl;
            return 6;
            break;
        case 3:
            cout << "WRONG ANSWER!!!!  The shark eats you!" << endl;
            return 6;
            break;
        case 4:
            cout << "THAT'S CORRECT!!!" << endl;
            cout << "The shark swims away with a toothy smile." << endl;
            this->visitedTrue();
            return 0;
            break;
    }
    
    return 0;
    
}


/*********************************************************************
 * Option 1 Opens pack
 * Option 2 adds salt Water to player's pack, removes from OCean B object
 * Option 3 Goes to OceanC
 * Option 4 Goes back to Ocean A
 * returns choice to player object
 * *******************************************************************/
int OceanB::menuB() {
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Collect salt water." << endl;
    cout << "3. Continue deeper into the ocean." << endl;
    cout << "4. Go back to shallower waters." << endl;
    
    int choice = getInt(1, 4);
    cout << string(50, '\n');
    
    switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            if(this->inventorySize() > 0) {
                return 7; // to open space inventory screen
            }
            else {
                cout << "Why are you collecting so much salt water?!?!." << endl;
                return 0;
            }
            break;
        case 3:
            cout << "The water gets deeper and darker as you swim out into the sea." << endl;
            return 2;
            break;
        case 4:
            cout << "You turn around and return to shallower waters." << endl;
            return 3;
            break;
    }
    
    return 0;
}
