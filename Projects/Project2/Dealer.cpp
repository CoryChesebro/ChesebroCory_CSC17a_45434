/* 
 * File:   Dealer.cpp
 * Author: Cory
 * 
 * Created on July 26, 2018, 4:15 AM
 */

#include <iostream>

#include "Player.cpp"
#include "Dealer.h"



template<class T>
Dealer<T>::Dealer() {
    this->bust = false;
    
    this->bj = false;
    
    this->size = 2;

    this->hand = new char[this->size];
    
    this->money = 500;
}

template<class T>
Dealer<T>::Dealer(const Dealer& orig) {
    this->size = orig.size;
    this->hand = orig.hand;
    
    this->money = orig.money;
}

template<class T>
Dealer<T>::~Dealer() {
    
    delete [] this->hand;
}

template<class T>
void Dealer<T>::operator++(int){
    this->size++;
    char *temp = new char[this->size];
    
    for(int i = 0; i < this->size - 1; i++){
        temp[i] = this->hand[i];
    }
    
    this->hand = temp;
}

template<class T>
void Dealer<T>::operator--(){
    
}

template<class T>
void Dealer<T>::chkTotal(){
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
void Dealer<T>::genHand(const Game &game){
    this->hand[0] = this->genCard(game);
    this->hand[1] = this->genCard(game);
}

template<class T>
void Dealer<T>::prntTotal(){
    chkTotal();
    std::cout<<this->total;
}

template<class T>
void Dealer<T>::hit(const Game&){
    
}