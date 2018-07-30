/* 
 * File:   User.cpp
 * Author: Cory
 * 
 * Created on July 26, 2018, 9:00 PM
 */
#include <iostream>

#include "User.h"
#include "Game.h"

// Default constructor

template<class T>
User<T>::User() {

    this->bust = false;
    
    this->bj = false;
    
    this->size = 2;

    this->hand = new char[this->size];

    this->money = 500;
}

// Copy constructor
template<class T>
User<T>::User(const User& orig) {
    this->size = orig.size;
    this->hand = orig.hand;

    this->money = orig.money;
}

// Deconstructor
template<class T>
User<T>::~User() {

    // Free up allocated memory
    delete [] this->hand;
}

// This operator expands the hand array getting it ready for the addition
// of a new card when the player hits
template<class T>
void User<T>::operator++(int) {
    this->size++;
    char *temp = new char[this->size];
    
    for(int i = 0; i < this->size - 1; i++){
        temp[i] = this->hand[i];
    }
    
    this->hand = temp;
}

template<class T>
void User<T>::operator--() {

}

template<class T>
void User<T>::hit(const Game &game){
    this->hand[this->size - 1] = this->genCard(game);
}

template<class T>
void User<T>::stand(){
    if(this->total > 21){
        this->bust = true;
    }
    else if(this->total == 21){
        this->bj = true;
    }
}

template<class T>
void User<T>::chkTotal(){
    int total = 0;
    int arrSize = this->size;
    int aceCnt = 0;
    
    for(int i = 0; i < arrSize; i++){
        char temp = this->hand[i];
        switch(temp){
            case '2': total += 2;break;
            case '3': total += 3;break;
            case '4': total += 4;break;
            case '5': total += 5;break;
            case '6': total += 6;break;
            case '7': total += 7;break;
            case '8': total += 8;break;
            case '9': total += 9;break;
            case 'T': total += 10;break;
            case 'J': total += 10;break;
            case 'Q': total += 10;break;
            case 'K': total += 10;break;
            case 'A': aceCnt += 1;break;
            default: std::cout<<"Something is wrong in your chkTotal function";
        }
    }
    for(int i = 0; i < aceCnt; i++){
        ((total + 11) > 21)?(total += 1):(total += 11);
    }
    this->total = total;
}

template<class T>
void User<T>::prntTotal(){
    chkTotal();
    std::cout<<this->total;
}

template<class T>
void User<T>::genHand(const Game &game){
    this->hand[0] = this->genCard(game);
    this->hand[1] = this->genCard(game);
}

template<class T>
int User<T>::getTotal(){
    chkTotal();
    return this->total;
}

template<class T>
void User<T>::printHand(){
    for(int i = 0; i < this->size; i++){
        std::cout<<this->hand[i]<<" ";
    }
}

template<class T>
bool User<T>::isBusted(){
    return this->bust;
}

template<class T>
bool User<T>::hasBJ(){
    return this->bj;
}

template<class T>
T User<T>::getMoney(){
    return this->money;
}

template<class T>
void User<T>::setMoney(T bet, bool won){
    if(this->bust || !won){
        this->money -= bet;
    }
    else if(this->bj){
        this->money = bet * 3 / 2;
    }
    else{
        this->money += bet;
    }
}

template<class T>
void User<T>::reset(const Game &game){
    this->hand = nullptr;
    this->size = 2;
    
    this->hand = new char[this->size];
    this->genHand(game);
    
    this->bust = false;
    this->bj = false;
}