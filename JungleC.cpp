/*********************************************************************
 * File Name: JungleC.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Derived from Space class, JungleC class that gives quest item.
 * *******************************************************************/

#include "JungleC.hpp"

/*********************************************************************
 * Destructor frees any items in vector of items.
 * *******************************************************************/
JungleC::~JungleC() {
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
 * Option 2 gives quest item 'Planks'
 * Option 3 kills player by pirhannas
 * Option 4 returns player to JungleB
 * returns choice to player object
 * *******************************************************************/
int JungleC::menuA() {
    cout << "The jungle opens and you see a pond in front of you, there is a broken tree to the side." << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Inspect broken tree." << endl;
    cout << "3. Take a dip in the pond." << endl;
    cout << "4. Go back into the jungle." << endl;
    
    int choice = getInt(1, 4);
    cout << string(50, '\n');
    
    switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            cout << "You have found the planks quest item! This could be used to repair the ship." << endl;
            this->visitedTrue();
            return 8;
            break;
        case 3:
            cout << "Pirhana's devoure you!!!!" << endl;
            return 6;
            break;
        case 4:
            cout << "You turn around and head back into the jungle." << endl;
            return 3;
            break;
    }
    
    return 0;
}

/*********************************************************************
 * Secondary menu after quest item is retrieved from broken tree
 * returns choice to player object.
 * *******************************************************************/
int JungleC::menuB() {
    cout << "The jungle opens and you see a pond in front of you." << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Take a dip in the pond." << endl;
    cout << "3. Go back into the jungle." << endl;
    
    int choice = getInt(1, 3);
    cout << string(50, '\n');
    
    switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            cout << "Pirhana's devoure you!!!!" << endl;
            return 6;
            break;
        case 3:
            cout << "You turn around and head back into the jungle." << endl;
            return 3;
            break;

    }
    
    return 0;
}
