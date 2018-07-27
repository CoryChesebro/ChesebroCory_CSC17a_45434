/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.h
 * Author: Cory
 *
 * Created on July 26, 2018, 9:00 PM
 */

#ifndef USER_H
#define USER_H

#include "Player.h"

template<class T>
class User : public Player<T>{
public:
    User();
    User(const User& orig);
    virtual ~User();
    
private:

};

#endif /* USER_H */

