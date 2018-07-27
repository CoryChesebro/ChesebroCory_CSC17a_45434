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

// Class forwarding for friendship
class Game;

// Template used for money variable either float or int 
template<class T>

// Abstract base class for Dealer and User
class Player {

// Public members    
public:
    // Friend function to get card from game object
    void getCard(const Game&);
    
// Protected members - for the child classes
protected:
    
    // Template for the money type
    T money;
    
    // Pointer to a char array for the players hand
    char *hand;
    // Size variable for the players hand
    int size;
    
    // Operator overloading, going to be used to add cards to the hand
    void operator++();
};

#endif /* PLAYER_H */