/*********************************************************************
 * File Name: Game.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Game is the main driver of the RPG text game.
 * *******************************************************************/

#include "Game.hpp"

/*********************************************************************
 * Constructor that creates the map of Space objects, as well as linking them
 *  together.  Creates a new player object and initalizes the players' 
 *  starting space to the Beach.
 * *******************************************************************/
Game::Game() {
    
    this->map[0] = new Beach;
    this->map[1] = new Ship;
    this->map[2] = new OceanA;
    this->map[3] = new OceanB;
    this->map[4] = new OceanC;
    this->map[5] = new JungleA;
    this->map[6] = new JungleB;
    this->map[7] = new JungleC;
    
    this->map[0]->set(this->map[2], this->map[5], this->map[1], nullptr);
    this->map[1]->set(this->map[2], this->map[0], nullptr, nullptr);
    this->map[2]->set(this->map[3], this->map[0], nullptr, nullptr);
    this->map[3]->set(this->map[4], this->map[2], nullptr, nullptr);
    this->map[4]->set(this->map[0], this->map[3], nullptr, nullptr);
    this->map[5]->set(this->map[6], this->map[0], nullptr, nullptr);
    this->map[6]->set(this->map[7], this->map[5], nullptr, nullptr);
    this->map[7]->set(nullptr, this->map[6], nullptr, nullptr);
    
    
    this->player = new Player(this->map[0]);
    

}

/*********************************************************************
 * Destructor that frees Space objects and Player object.
 * *******************************************************************/
Game::~Game() {
    delete this->player;
    this->player = nullptr;
    
    for(int i=0; i<8; i++) {
        delete this->map[i];
        this->map[i] = nullptr;
    }
}


/*********************************************************************
 * runs the gameplay until players survival points go to <= 0 or wins the game.
 * calls gameover function once either of these happen.
 * *******************************************************************/
void Game::play() {
    
    while(this->player->getSP() > 0  && this->player->getSailedAway() != true) {
        cout << "Survival Points: " << this->player->getSP() << endl;
        this->player->interact();
        
    }
    
    this->gameOver();
    
}

/*********************************************************************
 * If the player beats the game or is killed this function will let the user
 *  know.
 * *******************************************************************/
void Game::gameOver() {
    //cout << string(50, '\n');
    if(this->player->getSP() > 0) {
        cout << "The sea monster laughs and submerges into the ocean. \nYou sail back to the main land and live happily ever after.  YOU WIN!!!!" << endl << endl;
    }
    else {
        cout << "GAME OVER!  YOU DIED!!." << endl << endl;
    }
    
}
