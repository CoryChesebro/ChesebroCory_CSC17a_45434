/* 
 * File:   User.h
 * Author: Cory
 *
 * Created on July 26, 2018, 9:00 PM
 */

#ifndef USER_H
#define USER_H

#include "Player.h"

class Game;

template<class T>
class User : public Player<T>{
public:
    User();
    User(const User& orig);
    virtual ~User();
    
    void hit(const Game&);
    void stand();
    void reset(const Game&);
    
    
    void chkTotal() override;
    void genHand(const Game&);
    void prntTotal();
    void printHand();
    
    int getTotal();
    
    bool isBusted();
    bool hasBJ();
    
    T getMoney();
    void setMoney(T, bool);
    
    
    void operator++(int) override;
    void operator--() override;
private:

};

#endif /* USER_H */

