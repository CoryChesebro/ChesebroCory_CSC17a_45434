/* 
 * File:   Game.cpp
 * Author: Cory
 * 
 * Created on July 26, 2018, 2:45 AM
 */

#include "Game.h"

#include <iostream>

Game::Game() {
    card = 'A';
    
    size = 52;
    deck = new char[size];
    
}

Game::Game(const Game& orig) {
}

Game::~Game() {
    delete [] deck;
}

char Game::genCard(){
    return card;
}
