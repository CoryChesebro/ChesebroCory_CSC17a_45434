/* 
 * File:   Dealer.cpp
 * Author: Cory
 * 
 * Created on July 26, 2018, 4:15 AM
 */

#include "Dealer.h"

template<class T>
Dealer<T>::Dealer() {
    this->size = 2;

    this->hand = new char[this->size];
    
    this->money = 0;
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