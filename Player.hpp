/*********************************************************************
 * File Name: Player.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for Player.cpp.
 * *******************************************************************/


#ifndef Player_hpp
#define Player_hpp
#include "Backpack.hpp"
#include "Space.hpp"
#include <stdio.h>

class Player {
private:
    Backpack *pack;
    int survivalPoints;
    bool alive;
    bool hasPlanks;
    bool hasSail;
    Space *space;
    bool sailedAway;
public:
    Player(Space*);
    ~Player();
    void openPack();
    void updateSP(int);
    int getSP();
    void killPlayer();
    bool getSailedAway();
    void interact();
    
};

#endif /* Player_hpp */
