/*********************************************************************
 * File Name: JungleA.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Derived from Space class, JungleA class.
 * *******************************************************************/

#include "JungleA.hpp"

/*********************************************************************
 * adds 3 banana items to space object items vector in Jungle A
 * *******************************************************************/
JungleA::JungleA() {
    this->addItem(new Item("Banana", true, 5));
    this->addItem(new Item("Banana", true, 5));
    this->addItem(new Item("Banana", true, 5));
}

/*********************************************************************
 * Destructor frees any items in vector of items.
 * *******************************************************************/
JungleA::~JungleA() {
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
 * Option 2 adds banana to player's pack, removes from Jungle A object
 * Option 3 Goes to Jungle B
 * Option 4 Goes back to beach
 * returns choice to player object
 * *******************************************************************/
int JungleA::menuA() {
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Collect Banana." << endl;
    cout << "3. Continue deeper into jungle." << endl;
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
                cout << "There are no more bananas on the tree." << endl;
                return 0;
            }
            break;
        case 3:
            cout << "The jungle gets even darker, a strange smell lingers in the air." << endl;
            return 2;
            break;
        case 4:
            cout << "You turn around and return to the beach." << endl;
            return 3;
            break;
    }
    
    return 0;
}


/*********************************************************************
 * Option 1 Opens pack
 * Option 2 adds banana to player's pack, removes from Jungle A object
 * Option 3 Goes to Jungle B
 * Option 4 Goes back to beach
 * returns choice to player object
 * *******************************************************************/
int JungleA::menuB() {
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Collect Banana." << endl;
    cout << "3. Continue deeper into jungle." << endl;
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
                cout << "There are no more bananas on the tree." << endl;
                return 0;
            }
            break;
        case 3:
            cout << "The jungle gets even darker, a strange smell lingers in the air." << endl;
            return 2;
            break;
        case 4:
            cout << "You turn around and return to the beach." << endl;
            return 3;
            break;
    }
    
    return 0;
}



