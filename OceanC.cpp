/*********************************************************************
 * File Name: OceanC.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Derived from Space class, OceanC class.
 * *******************************************************************/

#include "OceanC.hpp"

/*********************************************************************
 * adds 9 Salt Water items to space object items vector in Ocean C
 * *******************************************************************/
OceanC::OceanC() {
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
OceanC::~OceanC() {
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
 * Option 1 Gets a quest item 'Sail'
 * Option 2 kills player
 * Option 3 Goes to Ocean B
 * returns choice to player object
 * *******************************************************************/
int OceanC::menuA() {
    cout << "You spot a dolphin and swim over to it.  It appears to be caught in a net." << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Help dolphin" << endl;
    cout << "2. Attack dolphin" << endl;
    cout << "3. Do nothing and swim away." << endl;
    
    int choice = getInt(1, 4);
    cout << string(50, '\n');
    
    switch (choice) {
        case 1:
            cout << "You help the dolphin out of the net.  The dolphin thanks you and takes you to another part of the beach where another broken down ship's sail is in working order.  Sail acquired!!" << endl;
            this->visitedTrue();
            return 9;
            break;
        case 2:
            cout << "You go to attack the dolphin (you jerk).  Suddenly a gang of dolphins come and beat the living crap out of you!!" << endl;
            return 6;
            break;
        case 3:
            cout << "You return to shallower waters." << endl;
            return 3;
            break;
    }
    
    return 0;
}


/*********************************************************************
 * Option 1 Opens pack
 * Option 2 adds salt Water to player's pack, removes from OCean C object
 * Option 3 Goes to Beach
 * Option 4 Goes back to Ocean B
 * returns choice to player object
 * *******************************************************************/
int OceanC::menuB() {
    cout << "Your dolphin friend swims up to you." << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Collect salt water." << endl;
    cout << "3. Take dolphin ride back to beach." << endl;
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
            cout << "You hop on the dolphin's back and return to the beach." << endl;
            return 2;
            break;
        case 4:
            cout << "You turn around and return to shallower waters." << endl;
            return 3;
            break;
    }
    
    return 0;
}
