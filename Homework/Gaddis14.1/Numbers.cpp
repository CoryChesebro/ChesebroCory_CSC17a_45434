#include <iostream>

#include "Numbers.h"

Numbers::Numbers() {
    this->number = 0;
}

Numbers::Numbers(unsigned short number) {
    this->number = number;
}

Numbers::~Numbers() {
}

void Numbers::intToWrd(){
    unsigned short total = this->number;
    std::string number;
    bool teen = false;
    
    int thsnd = 1000;
    int hndrd = 100;
    int ten = 10;
    
    int nThsnd = 0;
    int nHndrd = 0;
    int nTen = 0;
    int nOne = 0;
    
    if(total >= thsnd){
        nThsnd = total / thsnd;
        total %= thsnd;
        
        nHndrd = total / hndrd;
        total %= hndrd;
        
        nTen = total / ten;
        total %= ten;
        nOne = total;
    }
    else if(total >= hndrd){
        nHndrd = total / hndrd;
        total %= hndrd;
        
        nTen = total / ten;
        total %= ten;
        
        nOne = total;
    }
    else if(total >= ten){
        nTen = total / ten;
        total %= ten;
        
        nOne = total;
    }
    else{
        nOne = total;
    }
    
    switch(nThsnd){
        case 9: number += "Nine Thousand ";break;
        case 8: number += "Eight Thousand ";break;
        case 7: number += "Seven Thousand ";break;
        case 6: number += "Six Thousand ";break;
        case 5: number += "Five Thousand ";break;
        case 4: number += "Four Thousand ";break;
        case 3: number += "Three Thousand ";break;
        case 2: number += "Two Thousand ";break;
        case 1: number += "One Thousand ";break;
    }
    
    switch(nHndrd){
        case 9: number += "Nine Hundred ";break;
        case 8: number += "Eight Hundred ";break;
        case 7: number += "Seven Hundred ";break;
        case 6: number += "Six Hundred ";break;
        case 5: number += "Five Hundred ";break;
        case 4: number += "Four Hundred ";break;
        case 3: number += "Three Hundred ";break;
        case 2: number += "Two Hundred ";break;
        case 1: number += "One Hundred ";break;
    }
    
    switch(nTen){
        case 9: number += "Ninety ";break;
        case 8: number += "Eighty ";break;
        case 7: number += "Seventy ";break;
        case 6: number += "Sixty ";break;
        case 5: number += "Fifty ";break;
        case 4: number += "Forty ";break;
        case 3: number += "Thirty ";break;
        case 2: number += "Twenty ";break;
        case 1: teen = true;break;
    }
    
    switch(nOne){
        case 9:(teen)?(number += "Nineteen "):(number += "Nine ");break;
        case 8:(teen)?(number += "Eighteen "):(number += "Eight ");break;
        case 7:(teen)?(number += "Seventeen "):(number += "Seven ");break;
        case 6:(teen)?(number += "Sixteen "):(number += "Six ");break;
        case 5:(teen)?(number += "Fifteen "):(number += "Five ");break;
        case 4:(teen)?(number += "Fourteen "):(number += "Four ");break;
        case 3:(teen)?(number += "Thirteen "):(number += "Three ");break;
        case 2:(teen)?(number += "Twelve "):(number += "Two ");break;
        case 1:(teen)?(number += "Eleven "):(number += "One ");break;
        case 0:(teen)?(number += "Ten "):(number = number);break;// Have to put something or it throws a fit
    }
    this->english = number;
}

void Numbers::print(){
    std::cout<<this->english<<std::endl;
}

void Numbers::setNum(){
    int temp = 0;
    int size;
    std::string temp2;
    bool valid = false;
    
    std::cout<<"Enter a number between 0 and 9999 to convert to english words: ";
    
    do{
        std::cin>>temp2;
        std::cout<<std::endl;
        
        size = temp2.length();
        if(size > 4){
            std::cout<<"Incorrect input, try again please: ";
            continue;
        }
        
        for(int i = 0; i < size; i++){
            if(temp2[i] < '0' || temp2[i] > '9'){
                std::cout<<"Incorrect input, try again please: ";
                temp = 0;
                break;
            }
            else{
                temp = (temp * 10) + (temp2[i] - '0');
            }
        }
        if(temp != 0){
            valid = true;
        }
    }while(!valid);
    
    this->number = temp;
}

unsigned short Numbers::getNum(){
    return this->number;
}