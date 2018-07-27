#include <iostream>
#include "DayOfYear.h"

std::string DayOfYear::months[12] = {"January", "February", "March", "April", "May", "June",
                    "July", "August", "September", "October", "November","December"};
int DayOfYear::daysMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

DayOfYear::DayOfYear() {
    this->day = 0;
    this->mDay = 0;
    this->month = "";
}

DayOfYear::DayOfYear(int input) {
    this->day = input;
    this->mDay = 0;
    this->month = "";
}

DayOfYear::~DayOfYear() {
}

void DayOfYear::setDay(){
    int temp = 0;
    int size;
    std::string temp2;
    bool valid = false;
    
    std::cout<<"Enter a number between 1 and 365 and find which month and day of"
            " the month it is: ";
    
    do{
        std::cin>>temp2;
        std::cout<<std::endl;
        
        size = temp2.length();
        if(size > 3){
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
            if(temp > 365 || temp == 0){
                std::cout<<"Incorrect input, try again please: ";
                temp = 0;
                break;  
            }
            else{
                valid = true;
            }
        }
    }while(!valid);
    
    day = temp;
}

void DayOfYear::print(){
    std::cout<<"Day - "<<day<<" lands on "<<month<<" "<<mDay;
}

void DayOfYear::calcDate(){
    int temp = day;
    int counter = 0;
    int index = 0;

    for(int i = 0; i < 12; i++){
        counter += daysMonths[i];
        std::cout<<counter<<std::endl;
        if(temp <= counter){
            counter -= daysMonths[i];
            index = i;
            break;
        }
    }
    
    month = months[index];
    mDay = day - counter;
}