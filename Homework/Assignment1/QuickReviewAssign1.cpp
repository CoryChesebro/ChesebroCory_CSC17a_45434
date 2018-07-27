#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "globals.h"

// Accidentally did this for 3.12 not knowing 6.7 was the reverse. whoops.
void tempCnv(){// Chapter 3 problem 12 AND Chapter 6 problem 7
    char ans = '0';
    int temp = 0;
    std::cout<<"Would you like to 1. convert F to C or 2. conver C to F?: ";
    std::cin>>ans;
    
    if(ans != '1' && ans != '2'){
        std::cout<<"Incorrect response! enter 1 or 2 to choose a conversion method";
    }
    else if(ans == '1'){
        std::cout<<"Enter your tempurature in Fahrenheit: ";
        std::cin>>temp;
        std::cout<<std::endl<<"That tempurature in Celsius is : "<<((temp - 32) / 1.8f);
    }
    else{
        std::cout<<"Enter your tempurature in Celsius: ";
        std::cin>>temp;
        std::cout<<std::endl<<"That tempurature in Fahrenheit is : "<<((1.8f * temp) + 32);
    }
}

void cnvMny(){// Chapter 3 problem 13
    int usDoll = 0;
    
    std::cout<<"Enter the amount of US Dollars you have and I will magically convert"
            "them to Yen and Euros: ";
    std::cin>>usDoll;
    std::cout<<std::fixed<<std::showpoint<<std::setprecision(2)<<std::endl<<
            "Your money in Yen: "<<usDoll * 98.93<<std::endl<<
            "Your money in Euros: "<<usDoll * 0.74;
}

void leapYr(){// Chapter 4 problem 10
    int year = 0, month = 0;
    
    std::cout<<"Enter a month and a year and I will tell you how many days are"
            " in that month - "<<std::endl;
    
    std::cout<<"Month: ";
    std::cin>>month;
    
    if(!(month <= 12 && month >= 1)){
        std::cout<<"Incorrect month input you dummy, try again.";
        exit(EXIT_FAILURE);
    }
    
    std::cout<<std::endl<<"Year: ";
    std::cin>>year;
    
    if(year < 0){
        std::cout<<"Incorrect year input you dummy, try again.";
        exit(EXIT_FAILURE);
    }
    
    if(month == 2){
        if(year % 100 == 0 && year % 400 == 0){
            std::cout<<"Since "<<year<<" is a leap year, month "<<month<<" "
                    "has 29 days.";
        }
        else{
            if(year % 4 == 0){
                std::cout<<"Since "<<year<<" is a leap year, month "<<month<<" "
                    "has 29 days.";
            }
        }
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
            || month == 10 || month == 12){
        std::cout<<"Month "<<month<<" has 31 days";
    }
    else{
        std::cout<<"Month "<<month<<" has 30 days";
    }
}

void pPredic(){// Chapter 5 problem 11
    int pSize = 0, sSize = 0, days = 0;
    float rog = 0.0f, exp = 0.0f;
    
    std::cout<<"Input the initial population size: ";
    std::cin>>sSize;
    
    std::cout<<std::endl<<"Input daily average population change as a percent: ";
    std::cin>>rog;
    
    std::cout<<std::endl<<"Input how may days to calculate: ";
    std::cin>>days;
    
    rog /= 100.0f;
    exp = rog * days;

    pSize = sSize * (std::pow(GL_e,exp));
    
    std::cout<<std::endl<<pSize;
}

