/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.cpp
 * Author: Cory
 * 
 * Created on July 23, 2018, 4:02 PM
 */

#include "Inventory.h"

Inventory::Inventory() {
    this->itemNum = 0;
    this->quant = 0;
    this->cost = 0;
    this->tCost = 0;
}

Inventory::Inventory(int itemNum, int quant, float cost) {
    this->itemNum = itemNum;
    this->quant = quant;
    this->cost = cost;
    this->setTCost();
}

Inventory::~Inventory() {
}

void Inventory::setItemNum(int in){
    this->itemNum = in;
}

void Inventory::setQuant(int in){
    this->quant = in;
}

void Inventory::setCost(float in){
    this->cost = in;
}

void Inventory::setTCost(){
    this->tCost = this->quant * this->cost;
}


int Inventory::getItemNum(){
    return this->itemNum;
}

int Inventory::getQuant(){
    return this->quant;
}

float Inventory::getCost(){
    return this->cost;
}

float Inventory::getTCost(){
    return this->tCost;
}


