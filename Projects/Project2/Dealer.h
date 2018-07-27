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
    
    void chkTotal() override;
private:
    void operator++() override;
    void operator--() override;
    
    
};

#endif /* DEALER_H */

