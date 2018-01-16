/*********************************************************************
 * File Name: Player.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Implementation of Player class.  Represents the hero of
 * our game.
 * *******************************************************************/



#include "Player.hpp"


/*********************************************************************
 * Constructor that initalizes a new Backpack object, survival points at 100,
 * player is alive, parameter of Space object that sets Player's starting location,
 * Does not have quest items and has not sailed away to win the game.
 * *******************************************************************/
Player::Player(Space* startSpace) {
    this->pack = new Backpack();
    this->survivalPoints = 100;
    this->alive = true;
    this->space = startSpace;
    this->hasPlanks = false;
    this->hasSail = false;
    this->sailedAway = false;
    
}

/*********************************************************************
 * Destructor that deletes backpack object
 * *******************************************************************/
Player::~Player() {
    delete this->pack;
    this->pack = nullptr;
    
    this->space = nullptr;
}

/*********************************************************************
 * Allows user to interact with backpack object
 * *******************************************************************/
void Player::openPack() {
    int choice;
    
    do {
        cout << "What would you like to do? " << endl;
        cout << "1. Use item." << endl;
        cout << "2. Remove item." << endl;
        cout << "3. Close backpack." << endl;
        choice = getInt(1, 3);
        cout << string(50, '\n');
        
        int item = -1;
        int itemSP = -1;
        switch (choice) {
            case 1:
                item = this->pack->useItem();
                if(item != -1) {
                    itemSP = this->pack->getItemSPat(item);
                    this->updateSP(itemSP);
                    if(itemSP < 0) {
                        cout << "Lossed " << itemSP << " Survival Points." << endl;
                    }
                    else {
                        cout << "Gained " << itemSP << " Survival Points." << endl;
                    }
                    this->pack->removeItemAt(item);
                }
                break;
            case 2:
                this->pack->removeItem();
                break;
            case 3:
                cout << string(50, '\n');
                break;
        }
        
        
    } while(choice != 3);
}

/*********************************************************************
 * takes an integer and adds that to player objects' survival points.
 * *******************************************************************/
void Player::updateSP(int SP) {
    this->survivalPoints += SP;
}

/*********************************************************************
 * Returns integer representing Player's current survival points.
 * *******************************************************************/
int Player::getSP() {
    return this->survivalPoints;
}

/*********************************************************************
 * updates Player object's survival points to 0.
 * *******************************************************************/
void Player::killPlayer() {
    this->updateSP(-1 * getSP());
}

/*********************************************************************
 * When true, player wins game.
 * *******************************************************************/
bool Player::getSailedAway() {
    return this->sailedAway;
}

/*********************************************************************
 * Main function allowing Player object to interact with whatever Space 
 * they are currently in.
 * *******************************************************************/
// 0 = wasted turn
// 1 = open pack
// 2 = move up
// 3 = move bottom
// 4 = move right
// 5 = move left
// 6 = kill player
// 7 = collect item
// 8 = aquire plank quest item
// 9 = aquire sail quest item
// 10 = fix ship
// 11 = sail ship
void Player::interact() {
    int choice;
    int starve = -5;  //decrease SP by this amount when moving
    
    if(this->space->hasVisited()) {
        choice = this->space->menuB();
    }
    else {
        choice = this->space->menuA();
    }
    
    switch (choice) {
        case 0: // wasted turn
            break;
        case 1:
            this->openPack();
            break;
        case 2:
            this->space = this->space->getTop();
            this->updateSP(starve);
            break;
        case 3:
            this->space = this->space->getBottom();
            this->updateSP(starve);
            break;
        case 4:
            this->space = this->space->getRight();
            this->updateSP(starve);
            break;
        case 5:
            this->space = this->space->getLeft();
            this->updateSP(starve);
            break;
        case 6:
            this->killPlayer();
            break;
        case 7: //get item from space
            if(this->pack->numItems() < 5) {
                this->pack->addItem(this->space->openInventory());
            }
            else {
                cout << "Your pack is full." << endl;
            }
            break;
        case 8: //get plank quest item
            this->hasPlanks = true;
            break;
        case 9: //get sail quest item
            this->hasSail = true;
            break;
        case 10: //attempt to repair ship
            if(this->hasPlanks == true && this->hasSail == true) {
                this->space->visitedTrue();
                cout << "You use the planks and the sail to fully repair your ship!!" << endl;
            }
            else {
                cout << "You don't have the necessary items to repair the ship." << endl;
                this->updateSP(starve);
            }
            break;
        case 11: //sail ship away
            cout << "You push your boat into the ocean and hop on.";
            cout << " A massive sea monster approaches as you sail away!!.";
            cout << " The sea monster asks you in a rumbling voice..." << endl;
            cout << "What do sea monsters eat?" << endl;
            cout << "1. Fish and chips" << endl;
            cout << "2. Fish and ships" << endl;
            cout << "3. Don't respond" << endl;
            cout << "4. Try to escape" << endl;
            int choice = getInt(1, 4);
            cout << string(50, '\n');
            
            switch (choice) {
                case 1:
                    cout << "WRONG ANSWER!!! The sea monster crushes your ship and swallows you whole!" << endl;
                    this->killPlayer();
                    break;
                case 2:
                    this->sailedAway = true;
                    break;
                case 3:
                    cout << "HOW DARE YOU IGNORE ME!!! The sea monster crushes your ship and swallows you whole!" << endl;
                    this->killPlayer();
                    break;
                case 4:
                    cout << "THERE IS NO ESCAPING ME!!! The sea monster crushes your ship and swallows you whole!" << endl;
                    this->killPlayer();
                    break;
            }
            
            break;

    }
    
    
}

