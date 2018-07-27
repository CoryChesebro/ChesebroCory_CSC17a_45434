#include <iostream>
#include <cstdlib>
#include <cctype>

#include "Customer.h"

void processCust(Cust*);
void prntCust(Cust*);

std::string sInput(const std::string& ,const std::string&);
int iInput(const std::string&, const std::string&);
bool isNums(const std::string&);

int main() {
    Cust *test = new Cust;
    processCust(test);
    
    return 0;
}

void processCust(Cust *customer){
    bool debug = false;
    if(debug){
        customer -> accntNum = 12345;
        customer -> name = "John Doe";
        customer -> address = "1234 Test St.";
        customer -> balance = 999;
        customer -> checks = 888;
        customer -> nBalance = 112;
        customer -> deposits = 1;
        customer -> overdraft = false;
    }
    
    customer -> accntNum = iInput("account number", "high");
    customer -> name = sInput("name", "high");
    customer -> address = sInput("address", "low");
    customer -> balance = iInput("starting balance", "low");
    customer -> deposits = iInput("total money deposited in the account", "low");
    customer -> checks = iInput("total money taken out of account", "low");
    
    customer -> nBalance = (customer -> balance) - (customer -> checks)
            + (customer -> deposits);
    if(customer -> nBalance < 0){
        customer -> overdraft = true;
        customer -> nBalance -= 15;
    }
    
    prntCust(customer);
}

void prntCust(Cust *customer){
    std::cout<<customer -> name<<" account number: "<<customer -> accntNum<<std::endl;
    std::cout<<"Starting balance: $"<<customer -> balance<<std::endl;
    std::cout<<"Amount deposited: $"<<customer -> deposits<<std::endl;
    std::cout<<"Amount withdrawn: $"<<customer -> checks<<std::endl;
    std::cout<<"Over-drafted: "<<std::boolalpha<<customer -> overdraft<<std::endl;
    if(customer -> overdraft){
        std::cout<<"You have overdrafter your account and have been charged $15"
                " subsequently."<<std::endl;
    }
    std::cout<<"Account total: $"<<customer -> nBalance<<std::endl;
}

bool isNums(const std::string &input){
    int size = input.length();
    for(int i = 0; i < size; i++){
        if(!(input[i] >= '0' && input[i] <= '9')){
            return false;
        }
    }
    return true;
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

std::string sInput(const std::string &type, const std::string &strictness){
    std::string temp = "";
    bool valid = true;
    int size;
    
    std::cout<<"Please enter "<<type<<": ";
    
    do{
        valid = true;
        getline(std::cin, temp);
        size = temp.length();
        
        if(size <= 0){
            valid = false;
        }
        
        if(strictness == "high"){// For names and stuff
            for(int i = 0; i < size; i++){
                if(!(isalpha(temp[i]) || isspace(temp[i]))){
                    valid = false;
                    break;
                }
            }
            if(!valid){
                std::cout<<"Incorrect input for "<<type<<", please try again."
                        <<std::endl;
            }
        }
        
        else if(strictness == "low"){// for addresses and stuff
            for(int i = 0; i < size; i++){
                if(!(isalnum(temp[i]) || isspace(temp[i]) || ispunct(temp[i]))){
                    valid = false;
                    break;
                }
            }
            if(!valid){
                std::cout<<"Incorrect input for "<<type<<", please try again."
                        <<std::endl;
            }
        }
        
        else{
            // you fucked up   
            std::cout<<"Missing strictness, try again dummy"<<std::endl;
        }
        
    }while(!valid);
    
    return temp;
}