/*********************************************************************
 * File Name: JungleB.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Derived from Space class, JungleB class presents a monster.
 * *******************************************************************/

#include "JungleB.hpp"

/*********************************************************************
 * Destructor frees any items in vector of items.
 * *******************************************************************/
JungleB::~JungleB() {
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
 * Option 2 updates object to visited and changes menu
 * Option 3 kills player
 * returns choice to player object
 * *******************************************************************/
int JungleB::menuA() {
    cout << "You hear a rustle in the bush next to you.  A massive angry looking gorilla appears!!" << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Wrestle gorilla." << endl;
    cout << "2. Toss banana to gorilla." << endl;
    cout << "3. Attempt to run." << endl;
    
    int choice = getInt(1, 3);
    cout << string(50, '\n');
    
    switch (choice) {
        case 1:
            cout << "The gorilla straight up murders you!!!" << endl;
            return 6;
            break;
        case 2:
            cout << "You toss a banana to the gorilla, he smiles at you and runs off into the jungle." << endl;
            this->visitedTrue();
            return 0;
            break;
        case 3:
            cout << "You attempt to run, the gorilla chases you down and breaks your face!!!" << endl;
            return 6;
            break;
    }
    
    return 0;
}


/*********************************************************************
 * Option 1 Opens pack
 * Option 2 goes to Jungle C
 * Option 3 goes to Jungle A
 * returns choice to player object
 * *******************************************************************/
int JungleB::menuB() {
    cout << "Banana peels are on the ground in front of you.  It doesn't look like there is much else here." << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Open backpack. " << endl;
    cout << "2. Continue deeper into the jungle." << endl;
    cout << "3. Go back to the banana tree." << endl;
    
    int choice = getInt(1, 3);
    cout << string(50, '\n');
    
    switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            cout << "You continue deeper into the jungle." << endl;
            return 2;
            break;
        case 3:
            cout << "You turn around and return to the banana tree." << endl;
            return 3;
            break;
    }
    
    return 0;
}
