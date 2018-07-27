/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Customer.h
 * Author: Cory
 *
 * Created on July 14, 2018, 4:43 PM
 */

#ifndef CUSTOMER_H

#define CUSTOMER_H

struct Cust {
    std::string name;
    std::string address;
    
    int accntNum;
    int balance;
    int nBalance;
    int checks;
    int deposits;
    
    bool overdraft;
};

#endif /* CUSTOMER_H */

