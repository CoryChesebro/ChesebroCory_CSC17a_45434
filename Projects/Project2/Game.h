/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Cory
 *
 * Created on July 26, 2018, 2:45 AM
 */

#ifndef GAME_H
#define GAME_H

#include "Player.h"


class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    char genCard();
    
    template <typename T> friend void Player<T>::getCard(const Game&);
    
    void shrink(int);
    
private:
    char card;// For testing
    
    char *deck;
    int size;
};

#endif /* GAME_H */

