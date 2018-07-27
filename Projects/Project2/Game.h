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
    
    
    template <typename T> friend char Player<T>::genCard(const Game&);
    
    
    
private:
    char card;// For testing
    
    char *deck;
    int size;
    
    
};

#endif /* GAME_H */

