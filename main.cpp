/*********************************************************************
 * File Name: main.cpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Final Project for CS162.
 *  This program is an RPG based text game.  Each choice the user has
 * will determince where they go next and if they will live to see another day.
 * *******************************************************************/

#include <iostream>
#include "Game.hpp"
#include "utility.hpp"

int main() {
    
    Game *game;
    int choice;
    
    do {
        cout << "Welcome to Shipwrecked!!!" << endl;
        cout << "Navigate through a dangerous island in order to get parts to repair your ship!" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Quit" << endl;
        choice = getInt(1, 2);
        cout << string(50, '\n');
        
        switch (choice) {
            case 1:
                game = new Game();
                game->play();
                delete game;
                game = nullptr;
                break;
            case 2:
                break;
        }
    } while(choice != 2);

    
    
    return 0;
}
