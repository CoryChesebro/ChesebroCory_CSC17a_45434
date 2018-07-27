#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>

// Globals
#define GLOBALS_DECL
#include "globals.h"

////    Prototypes   ////

// Menus
void menu();
void subMenu1();

// Assignment 1
void tempCnv();// 3.12 / 6.7
void cnvMny();// 3.13
void leapYr();// 4.10
void pPredic();// 5.11

// Assignment 2

// Assignment 3

// Assignment 4

// Assignment N...

int main() {

    menu();

    // End program
    return 0;
}

void menu(){
    std::string input = "";
    std::cout<<"Please choose which assignment youd like to browse"
            " by entering the corresponding number: ";
    std::cout<<std::endl<<"1. Assignment 1"<<std::endl;
    std::cout<<"More to come.."<<std::endl;
    
    std::cin>>input;
    
    if(input[0] != '1'){
        std::cout<<"You chose incorrectly! So either you "
                "cant read or you dont want to be here"<<std::endl;
    }
    else{
        switch(input[0] - '0'){
            case 1: subMenu1();break;
        } 
    }
}

void subMenu1(){
    std::string input = "";
    
    std::cout<<"Please select which problem youd like to view by entering"
            " the corresponding number: "<<std::endl;
    std::cout<<"1. Problem 1 - 3.12 / 6.7"<<std::endl;
    std::cout<<"2. Problem 2 - 3.13"<<std::endl;
    std::cout<<"3. Problem 3 - 4.10"<<std::endl;
    std::cout<<"4. Problem 4 - 5.11"<<std::endl;
    std::cout<<"5. Problem 5 - 6.7 / 3.12"<<std::endl;
    std::cout<<"Your choice: ";
    std::cin>>input;
    
    if(!(input[0] >= '1' || input[0] <= '9')){
        std::cout<<"You chose incorrectly! So either you "
                "cant read or you dont want to be here"<<std::endl;
    }
    else{
        std::cout<<std::endl;
        switch(input[0] - '0'){
            case 1: tempCnv();break;
            case 2: cnvMny();break;
            case 3: leapYr();break;
            case 4: pPredic();break;
            case 5: tempCnv();break;
        }
    }
    
}
