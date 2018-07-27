/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.h
 * Author: Cory
 *
 * Created on July 22, 2018, 10:57 PM
 */
#include <string>

#ifndef RETAILITEM_H
#define RETAILITEM_H

class RetailItem{
    private:
        std::string desc;
        int units;
        float price;

    public:
        RetailItem();
        RetailItem(std::string description, int units, float price);

        void setDesc(std::string);
        void setUnits(int);
        void setPrice(float);

        std::string getDesc();
        int getUnits();
        float getPrice();
};

#endif /* RETAILITEM_H */

