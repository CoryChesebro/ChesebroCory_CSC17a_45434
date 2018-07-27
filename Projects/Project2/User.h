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
    void operator++();
    void operator--();
};

#endif /* USER_H */

