/* 
 * File:   Dealer.h
 * Author: Cory
 *
 * Created on July 26, 2018, 4:15 AM
 */

#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "Game.h"

template<class T>
class Dealer : public Player <T>{
public:
    Dealer();
    Dealer(const Dealer& orig);
    virtual ~Dealer();
    
    void chkTotal() override;
    void genHand(const Game&);
    void prntTotal();
    
    void hit(const Game&);
    
    int getTotal();
    
    void operator++(int) override;
    void operator--() override;
private:

    
    
};

#endif /* DEALER_H */

