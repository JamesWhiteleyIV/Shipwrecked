/*********************************************************************
 * File Name: Game.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for Game.cpp
 * *******************************************************************/

#ifndef Game_hpp
#define Game_hpp
#include "Space.hpp"
#include "Player.hpp"
#include "JungleA.hpp"
#include "JungleB.hpp"
#include "JungleC.hpp"
#include "OceanA.hpp"
#include "OceanB.hpp"
#include "OceanC.hpp"
#include "Ship.hpp"
#include "Beach.hpp"
#include <stdio.h>

class Game {
private:
    Player *player;
    Space *map[8];
    
public:
    Game();
    ~Game();
    void play();
    void gameOver();
};

#endif /* Game_hpp */
