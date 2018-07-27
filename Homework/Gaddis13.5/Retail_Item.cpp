/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Retail_Item.h"


RetailItem::RetailItem(){
    this -> desc = "";
    this -> units = 0;
    this -> price = 0.0f;
}

RetailItem::RetailItem(std::string desc, int units, float price){
    this -> desc = desc;
    this -> units = units;
    this -> price = price;
}

void RetailItem::setDesc(std::string input){
    this -> desc = input;
}

void RetailItem::setPrice(float input){
    this -> price = input;
}

void RetailItem::setUnits(int input){
    this -> units = input;
}

std::string RetailItem::getDesc(){
    return this -> desc;
}

int RetailItem::getUnits(){
    return this -> units;
}

float RetailItem::getPrice(){
    return this -> price;
}

