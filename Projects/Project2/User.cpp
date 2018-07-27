/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.cpp
 * Author: Cory
 * 
 * Created on July 26, 2018, 9:00 PM
 */

#include "User.h"

// Default constructor
template<class T>
User<T>::User() {
    this->size = 2;

    this->hand = new char[this->size];
    
    this->money = 0;
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

