/* 
 * File:   Player.cpp
 * Author: Cory
 * 
 * Created on July 26, 2018, 2:45 AM
 */

#include <iostream>

#include "Game.h"

template<class T>
// ---- example of friend function and inheritance all in one ----
// Function returns a char which is a card that can be put into the players hand
char Player<T>::genCard(const Game &game){
    bool valid;
    int random;
    char card;
    
    do{
        valid = true;
        random = rand() % game.size;
        card = game.deck[random];
        if(card == '*'){
            valid = false;
        }
        else{
            game.deck[random] = '*';
        }
    }while(!valid);
    
    return card;
}
