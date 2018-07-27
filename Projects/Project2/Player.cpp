/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: Cory
 * 
 * Created on July 26, 2018, 2:45 AM
 */

#include <iostream>

#include "Game.h"

template<class T>
void Player<T>::getCard(const Game &game){
    std::cout<<game.card;
}
