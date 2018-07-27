/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

char Game::genCard(){
    return card;
}
