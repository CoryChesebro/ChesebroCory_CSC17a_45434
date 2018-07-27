/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.h
 * Author: Cory
 *
 * Created on July 23, 2018, 4:37 PM
 */

#include <string>

#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers {
public:
    Numbers();
    Numbers(unsigned short);
    virtual ~Numbers();
    
    void setNum();
    void intToWrd();
    void print();
    
    unsigned short getNum();
    
    
private:
    unsigned short number;
    std::string english;
};

#endif /* NUMBERS_H */

