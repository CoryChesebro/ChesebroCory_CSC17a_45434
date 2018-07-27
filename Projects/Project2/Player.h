/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Cory
 *
 * Created on July 26, 2018, 2:45 AM
 */


#ifndef PLAYER_H
#define PLAYER_H

class Game;

template<class T>
class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
    
    void getCard(const Game&);
    
private:
    
protected:
    T money;
    
    char *hand;
    int size;

};

#endif /* PLAYER_H */

