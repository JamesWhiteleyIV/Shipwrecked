/*********************************************************************
 * File Name: Backpack.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Container class that holds Player objects items, also allows
 * user to use and remove items from pack.
 * *******************************************************************/

#include "Backpack.hpp"
#include "utility.hpp"


/*********************************************************************
 * adds 1 Fresh Water items to Player's backpack initially.
 * *******************************************************************/
Backpack::Backpack() {
    this->items[0] = new Item("Fresh Water", true, 10);
    for(int i=1; i<5; i++) {
        this->items[i] = new Item("Open Slot", false, 0);
    }
}

/*********************************************************************
 * Frees dynamically allocated Item objects from backpack
 * *******************************************************************/
Backpack::~Backpack() {
    for(int i = 0; i < 5; i++) {
        if(this->items[i] != nullptr) {
            delete items[i];
            items[i] = nullptr;
        }
    }
}

/*********************************************************************
 * Allows user to use an item from there backpack.
 * returns integer location of item.
 * *******************************************************************/
int Backpack::useItem() {
    
    int choice;
    
    if(this->numItems() == 0) {
        cout << string(50, '\n');
        cout << "There are no items to use!" << endl;
        return -1;
    }
    
    cout << string(50, '\n');
    cout << "Which item would you like to use?" << endl;
    for(int i = 0; i < 5; i++) {
        if(this->items[i]->getName() != "Open Slot" && this->items[i]->isUsable()) {
            cout << i << ". " << this->items[i]->getName() << endl;
        }
    }
    cout << "5. Go back." << endl;
    choice = getInt(0, 5);
    cout << string(50, '\n');
    
    if(choice < 5) {
        if(this->items[choice]->getName() == "Open Slot"){
            //cout << string(50, '\n');
            cout << "There is no item here to use. " << endl;
            return -1;
        }
        else {
            return choice;
        }
    }
   
    return -1;
}

/*********************************************************************
 * Removes an item from players bag (with choice)
 * *******************************************************************/
void Backpack::removeItem() {

    int choice;
    do {
        if(this->numItems() == 0) {
            cout << string(50, '\n');
            cout << "There are no items to remove!" << endl;
            return;
        }
        
        cout << string(50, '\n');
        cout << "Which item would you like to remove?" << endl;
        for(int i = 0; i < 5; i++) {
            if(this->items[i]->getName() != "Open Slot") {
                cout << i << ". " << this->items[i]->getName() << endl;
            }
        }
        cout << "5. Go back." << endl;
        choice = getInt(0, 5);
        cout << string(50, '\n');
        
        //choice is not go back
        if(choice < 5) {
            if(this->items[choice]->getName() == "Open Slot"){
                //cout << string(50, '\n');
                cout << "There is no item here to delete. " << endl;
                return;
            }
            else {
                delete this->items[choice];
                this->items[choice] = new Item("Open Slot", false, 0);
                return;
            }
        }
    } while(choice != 5);
        
    
}

/*********************************************************************
 * takes an integer parameter to locate the position of the item to remove.
 * removes item at that location in pack.
 * *******************************************************************/
void Backpack::removeItemAt(int position) {
    delete this->items[position];
    this->items[position] = new Item("Open Slot", false, 0);
}


/*********************************************************************
 * takes an Item object as a parameter.  Adds it to player's backpack
 * as long as the pack isn't full (5 items)
 * *******************************************************************/
void Backpack::addItem(Item *item) {
    
    for(int i = 0; i < 5; i++) {
        if(this->items[i]->getName() == "Open Slot") {
            delete this->items[i];
            this->items[i] = item;
            return;
        }
    }

}


/*********************************************************************
 * takes item position as a parameter, return an integer of the affect
 * that item has on survival points.
 * *******************************************************************/
int Backpack::getItemSPat(int position) {
    return this->items[position]->getSP();
}

/*********************************************************************
 * returns an integer representing the number of items in the players pack.
 * *******************************************************************/
int Backpack::numItems() {
    int accumulator = 0;
    
    for(int i = 0; i < 5; i++) {
        if(this->items[i]->getName() != "Open Slot") {
            accumulator++;
        }
    }
    
    return accumulator;
}
