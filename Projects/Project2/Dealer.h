/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dealer.h
 * Author: Cory
 *
 * Created on July 26, 2018, 4:15 AM
 */

#ifndef DEALER_H
#define DEALER_H

#include "Player.cpp"

template<class T>
class Dealer : public Player <T>{
public:
    Dealer();
    Dealer(const Dealer& orig);
    virtual ~Dealer();
    
private:
    
};

#endif /* DEALER_H */

