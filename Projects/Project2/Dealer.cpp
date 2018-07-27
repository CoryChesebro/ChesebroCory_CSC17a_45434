/* 
 * File:   Dealer.cpp
 * Author: Cory
 * 
 * Created on July 26, 2018, 4:15 AM
 */

#include <iostream>

#include "Dealer.h"



template<class T>
Dealer<T>::Dealer() {
    std::cout<<"Dealer constructed";
    
    this->total = 72;
    
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
void Dealer<T>::operator++(){
    
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
        std::cout<<total<<" ";
    }
    
    for(int i = 0; i < aceCnt; i++){
        ((total + 11) > 21)?(total += 1):(total += 11);
    }
    
    this->total = total;
    
    std::cout<<"Size :"<<this->size<<" total :"<<total;
    
}

template<class T>
void Dealer<T>::genHand(const Game &game){
    this->hand[0] = this->genCard(game);
    this->hand[1] = this->genCard(game);
    std::cout<<"Gen hand called";
}

template<class T>
void Dealer<T>::prntTotal(){
    std::cout<<"print called"<<std::endl;
    chkTotal();
    //std::cout<<this->total;
}