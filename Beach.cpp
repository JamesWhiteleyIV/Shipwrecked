/*********************************************************************
 * File Name: Beach.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Beginning location of player. Derived from Space class.
 * *******************************************************************/

#include "Beach.hpp"

/*********************************************************************
 * Destructor frees any items in vector of items.
 * *******************************************************************/
Beach::~Beach() {
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
 * Updates location to visited and switches to next menu that has no intro.
 * Option 1 Opens pack
 * Option 2 goes to OceanA
 * Option 3 Goes to JungleA
 * Option 4 Goes to Ship
 * returns choice to player object
 * *******************************************************************/
int Beach::menuA() {
    this->visitedTrue();
    
    //describe game
    cout << "You awake to find yourself covered in sea weed in a strange environment." << endl;
    cout << "You look over and see your ship with a large hole in the side and a torn sail." << endl;
    cout << "There's no way it will sail without repair. You look around and notice you are on an island." << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Swim from the beach into the ocean." << endl;
    cout << "3. Go into the jungle." << endl;
    cout << "4. Inspect broken ship." << endl;
    
    int choice = getInt(1, 4);
    cout << string(50, '\n');
    
    
    switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            cout << "You jump into the frigid ocean and begin to swim." << endl;
            return 2;
            break;
        case 3:
            cout << "The jungle is dark and eerie, you spot a banana tree." << endl;
            return 3;
            break;
        case 4:
            cout << "You step into the ship you arrived on." << endl;
            return 4;
            break;
    }
    
    return 0;
}

/*********************************************************************
 * Option 1 Opens pack
 * Option 2 goes to OceanA
 * Option 3 Goes to JungleA
 * Option 4 Goes to Ship
 * returns choice to player object
 * *******************************************************************/
int Beach::menuB() {
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack." << endl;
    cout << "2. Swim from the beach into the ocean." << endl;
    cout << "3. Go into the jungle." << endl;
    cout << "4. Inspect broken ship." << endl;
    
    int choice = getInt(1, 4);
    cout << string(50, '\n');
    
    switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            cout << "You jump into the frigid ocean and begin to swim." << endl;
            return 2;
            break;
        case 3:
            cout << "The jungle is dark and eerie, you spot a banana tree." << endl;
            return 3;
            break;
        case 4:
            cout << "You step into the ship you arrived on." << endl;
            return 4;
            break;
    }
    
    return 0;
}
