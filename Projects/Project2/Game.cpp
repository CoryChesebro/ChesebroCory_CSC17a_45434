/* 
 * File:   Game.cpp
 * Author: Cory
 * 
 * Created on July 26, 2018, 2:45 AM
 */

#include "Dealer.cpp"
#include "User.cpp"
#include "Game.h"

#include <iostream>

//Default constructor
Game::Game() {

    card = 'A';
    
    size = 52;
    deck = new char[size];
    
    // An array to use for reference to fill the deck
    char array[13] = {'2','3','4','5','6','7','8','9','T','Q','K','J','A'};
    
    // Counter to keep track of deck position
    int count = 0;
    
    //Fill the deck
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            deck[count] = array[j];
            count++;
        }
    }
}

// Copy constructor
Game::Game(const Game& orig) {
    this->card = orig.card;
    this->deck = orig.deck;
    this->size = orig.size;
}

//Deconstructor
Game::~Game() {
    delete [] deck;
}

void Game::reset(){
    Game game;
    this->deck = game.deck;
}
