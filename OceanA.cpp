/*********************************************************************
 * File Name: OceanA.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Derived from Space class, OceanA class.
 * *******************************************************************/
#include "OceanA.hpp"

/*********************************************************************
 * adds 9 Salt Water items to space object items vector in Ocean A
 * *******************************************************************/
OceanA::OceanA() {
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
OceanA::~OceanA() {
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
 * Option 2 adds salt Water to player's pack, removes from OCean A object
 * Option 3 Goes to OceanB
 * Option 4 Goes back to Beach
 * returns choice to player object
 * *******************************************************************/
int OceanA::menuA() {
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Collect salt water." << endl;
    cout << "3. Continue deeper into the ocean." << endl;
    cout << "4. Go back to beach." << endl;
    
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
            cout << "You turn around and return to the beach." << endl;
            return 3;
            break;
    }
    
    return 0;
}

//nothing
int OceanA::menuB() {
    //intentionally blank, this menu doesn't change
    return 0;
}
