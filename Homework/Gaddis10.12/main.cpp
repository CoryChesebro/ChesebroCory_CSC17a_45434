#include <cstdlib>
#include <iostream>
#include <cctype>
#include <cstring>

enum req {
    tooShrt,// Less that 6 characters
    noUppr,// No uppercase character
    noLwer,// No lowercase character
    noDigit,// No number
    pass// Passed
};

enum req passChk(const char*);

int main(int argc, char** argv) {
    int size = 100;
    
    char *arr = new char[size];
    
    std::cout<<"Please enter a password and I will verify if it passes the "
            "requirements for you: ";
    std::cin>>arr;
    
    req errors = passChk(arr);
    
    switch(errors){
        case tooShrt: 
            std::cout<<"Your password is too short, try again.";break;
        case noUppr: 
            std::cout<<"Your password contains no uppercase character";break;
        case noLwer: 
            std::cout<<"Your password contains no lowercase character.";break;
        case noDigit: 
            std::cout<<"Your password contains no number.";break;
        case pass: 
            std::cout<<"Your password passes all requirements!.";break;
        default: 
            std::cout<<"Unknown error, try again.";
    }
    
    return 0;
}

enum req passChk(const char *arr){
    req temp;
    bool length = false;
    bool upper = false;
    bool lower = false;
    bool digit = false;
    
    int size = strlen(arr);
    if(size < 6){
        temp = tooShrt;
        return temp;
    }
    
    for(int i = 0; i < size; i++){
        if(isupper(arr[i])){
         upper = true;   
        }
        if(islower(arr[i])){
            lower = true;
        }
        if(isdigit(arr[i])){
            digit = true;
        }
    }
    
    if(!upper){
        temp = noUppr;
    }
    else if(!lower){
        temp = noLwer;
    }
    else if(!digit){
        temp = noDigit;
    }
    else{
        temp = pass;
    }
    
    return temp;
}