#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>

#include "Primes.h"

Primes *factor(const int &x);
void prntPrm(Primes*);

int iInput(const std::string&, const std::string&);

int main(int argc, char** argv) {
    
    int x = iInput("the number you would like to factor", "low");
    
    Primes *temp;
    temp = factor(x);
    prntPrm(temp);

    
    return 0;
}

Primes *factor(const int &x){
    int temp = x;
    int size = std::sqrt(x);
    int size2 = 25;
    int count = 0;
    
    int primes[size2] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
        53, 59, 61, 67, 71, 73, 79, 83, 89, 97};// Size 25
    
    Primes *set1 = new Primes;
    set1 -> primes = new Prime[x];// Just to be safe
    
    for(int i = 0; i < size2; i++){
        while(temp % primes[i] == 0){
            if(set1 -> primes[count].power == 0){
                set1 -> primes[count].power++;
                set1 -> primes[count].prime = primes[i];
            }
            else{
                set1 -> primes[count].power++;
            }
            temp /= primes[i];
            if(temp < 2){break;}
        }
        if(set1 -> primes[count].power != 0){
            count++;
        }
        //std::cout<<count<<std::endl;
    }
    if(temp > 2 && count != 0){
        set1 -> primes[count].power++;
        set1 -> primes[count].prime = temp;
        count++;
    }
    else if(temp > 100){
        set1 -> nPrimes = -1;
    }
//    if(temp >= 2){
//        set1 -> primes[count].power = 1;
//        set1 -> primes[count].prime = temp;
//        count++;
//    }
    set1 -> nPrimes = count;
    return set1;
}

void prntPrm(Primes *primes){
    int size = primes -> nPrimes;
    
    if(size > 0){
        for(int i = 0; i < size; i++){
            std::cout<<static_cast<int>(primes -> primes[i].prime)<<"^"
                <<static_cast<int>(primes -> primes[i].power);
            if(i != size - 1){
                std::cout<<", ";
            }
        }
    }
    else{
        std::cout<<"This number is prime"<<std::endl;
    }

}

int iInput(const std::string &type, const std::string &strictness){
    std::string temp = "";
    bool valid = true;
    int size;
    int result = 0;
    
    std::cout<<"Please enter the "<<type<<": ";
    
    do{
        valid = true;
        getline(std::cin, temp);
        size = temp.length();
        
        if(size <= 0){
            valid = false;
        }
        
        if(strictness == "high"){
            if(size != 5){
                valid = false;
                std::cout<<"Incorrect input for the "<<type<<
                        ", please try again."<<std::endl;
            }
        }
        
        result = 0;
        for(int i = 0; i < size; i++){
            if(isdigit(temp[i])){
                result = (result * 10) + (temp[i] - '0');
            }
            else{
                std::cout<<"Incorrect input for the "<<type<<
                        ", please try again."<<std::endl;
                valid = false;
                break;
            }
        }
    }while(!valid);
    return result;
}