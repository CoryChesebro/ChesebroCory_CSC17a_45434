/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.h
 * Author: Cory
 *
 * Created on July 23, 2018, 4:02 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
public:
    Inventory();
    Inventory(int, int, float);
    virtual ~Inventory();
    
    void setItemNum(int);
    void setQuant(int);
    void setCost(float);
    void setTCost();
    
    int getItemNum();
    int getQuant();
    float getCost();
    float getTCost();
    
private:
    int itemNum;
    int quant;
    float cost;
    float tCost;
};

#endif /* INVENTORY_H */

