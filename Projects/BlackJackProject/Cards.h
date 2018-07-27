/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cards.h
 * Author: Cory
 *
 * Created on July 15, 2018, 3:18 PM
 */

#ifndef CARDS_H
#define CARDS_H

struct Game{
    std::fstream moves;
    char *deck;
    int deckSize = 52;
};

struct Cards{
    char *cards;
    int size;
};

struct Player{
    Cards hand;
    int money;
};


#endif /* CARDS_H */

