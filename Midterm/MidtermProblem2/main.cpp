#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

#include "Employee.h"

/// Problem functions ///
void processEmp();
void calculate(Employee&);
void prntEmp(const Employee&,const std::string&, const std::string&);
void prntChck(const Employee&, const std::string&, const std::string&);

/// Personal Input Functions /// 
std::string sInput(const std::string& ,const std::string&);
int iInput(const std::string&, const std::string&);
float fInput(const std::string&, const std::string&);

/// Whatever else needed ///
bool isNums(const std::string&);
std::string englishNums(const int&, const float&);

int main() {
    // Screw float accuracy
    
    processEmp();
            
    return 0;
}

void processEmp(){
    std::string cmpName = sInput("the name of the company", "high");
    std::string addr = sInput("the address of the company", "low");
    int size = iInput("amount of employees to process", "low");
    Employee *arr = new Employee[size];
    
    for(int i = 0; i < size; i ++){
        arr[i].name = sInput("employee name", "low");
        arr[i].hours = iInput("hours worked", "low");
        arr[i].rop = fInput("hourly pay rate", "none");
        calculate(arr[i]);
        std::cout<<std::endl;
    }
    for(int i = 0; i < size; i++){
        //prntEmp(arr[i], cmpName, addr);
        prntChck(arr[i], cmpName, addr);
    } 
}

void calculate(Employee &emp){
    float total;
    
    if(emp.hours >= 50){
        total += (30 * emp.rop);
        total += (20 * emp.rop * 2);
        total += ((emp.hours - 50) * emp.rop * 3);
    }
    else if(emp.hours >= 30){
        total += (30 * emp.rop);
        total += ((emp.hours - 30) * emp.rop * 2);
    }
    else{
        total += (emp.rop * emp.hours);
    }
    
    emp.total = total;
    emp.cents = total - emp.total;
    englishNums(emp.total, emp.cents);
}

void prntEmp(const Employee &emp, const std::string &cmpName,
        const std::string &addr){
    std::cout<<cmpName<<std::endl;
    std::cout<<addr<<std::endl;
    std::cout<<emp.name<<" has worked "<<emp.hours<<" hours at $"<<emp.rop
            <<" per hour which comes out to $"<<emp.total<<std::endl<<std::endl;
}

void prntChck(const Employee &emp, const std::string &cmpName, const std::string &addr){
    std::cout<<cmpName<<std::endl;
    std::cout<<addr<<std::endl;
    std::cout<<"Name: "<<emp.name;
    std::cout<<std::setw(15)<<std::right<<std::fixed<<std::setprecision(2);
    std::cout<<"Amount: $"<<emp.total<<"."<<(int)(emp.cents * 100)<<std::endl;
    std::cout<<"Amount: "<<englishNums(emp.total, emp.cents)<<std::endl; 
    std::cout<<"Signature Line: "<<std::endl;
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

float fInput(const std::string &type, const std::string &strictness){
    std::string temp = "";
    bool valid = true;
    bool decimal = false;
    int placeCnt = 0;
    int floatMaker = 1;
    int size;
    float result = 0;
    
    std::cout<<"Please enter "<<type<<": ";
    
    do{
        valid = true;
        decimal = false;
        placeCnt = 0;
        
        getline(std::cin, temp);
        size = temp.length();
        
        if(size <= 0){
            valid = false;
        }
        
        for(int i = 0; i < size; i++){
            if(decimal)placeCnt++;
            if(temp[i] != '.' && temp[i] < '0' || temp[i] > '9'){
                valid = false;
                std::cout<<"Incorrect input for "<<type<<", please try again."
                        <<std::endl;
                break;
            }
            if(temp[i] != '.'){
                result = (result * 10) + (temp[i] - '0');
            }
            else{
                decimal = true;
            }
        }

    }while(!valid);
    
    for(int i = 0; i < placeCnt; i++){
        floatMaker *= 10;
    }
    
    return result / floatMaker;
}

std::string englishNums(const int &total, const float &cents){
    int temp = total;
    float cent = cents;
    bool teen = false;
    bool teenThsnd = false;
    std::string number;
    
    int hThsnd = 100000;
    int tThsnd = 10000;
    int thsnd = 1000;
    int hndrd = 100;
    int ten = 10;
    int one = 1;

    
    
    int nHThsnd = -1;
    int nTThsnd = -1;
    int nThsnd = -1;
    int nHndrd = -1;
    int nTen = -1;
    int nOne = -1;
    
    if(temp >= hThsnd){
        nHThsnd = temp / hThsnd;
        temp %= hThsnd;
        
        nTThsnd = temp / tThsnd;
        temp %= tThsnd;
        
        nThsnd = temp / thsnd;
        temp %= thsnd;
        
        nHndrd = temp / hndrd;
        temp %= hndrd;
        
        nTen = temp / ten;
        temp %= ten;
        
        nOne = temp;
    }
    else if(temp >= tThsnd){
        nTThsnd = temp / tThsnd;
        temp %= tThsnd;
        
        nThsnd = temp / thsnd;
        temp %= thsnd;
        
        nHndrd = temp / hndrd;
        temp %= hndrd;
        
        nTen = temp / ten;
        temp %= ten;
        
        nOne = temp;
    }
    else if(temp >= thsnd){
        nThsnd = temp / thsnd;
        temp %= thsnd;
        
        nHndrd = temp / hndrd;
        temp %= hndrd;
        
        nTen = temp / ten;
        temp %= ten;
        
        nOne = temp;
    }
    else if(temp >= hndrd){
        nHndrd = temp / hndrd;
        temp %= hndrd;
        
        nTen = temp / ten;
        temp %= ten;
        
        nOne = temp;
    }
    else if(temp >= ten){
        nTen = temp / ten;
        temp %= ten;
        
        nOne = temp;
    }
    else{
        nOne = temp;
    }
    
    switch(nHThsnd){
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
    
    switch(nTThsnd){
        case 9: number += "Ninety ";break;
        case 8: number += "Eighty ";break;
        case 7: number += "Seventy ";break;
        case 6: number += "Sixty ";break;
        case 5: number += "Fifty ";break;
        case 4: number += "Forty ";break;
        case 3: number += "Thirty ";break;
        case 2: number += "Twenty ";break;
        case 1: teenThsnd = true;break;
    }
    
    switch(nThsnd){
        case 9: (teenThsnd)?(number += "Nineteen Thousand "):(number += "Nine Thousand ");break;
        case 8: (teenThsnd)?(number += "Eighteen Thousand "):(number += "Eight Thousand ");break;
        case 7: (teenThsnd)?(number += "Seventeen Thousand "):(number += "Seven Thousand ");break;
        case 6: (teenThsnd)?(number += "Sixteen Thousand "):(number += "Six Thousand ");break;
        case 5: (teenThsnd)?(number += "Fifteen Thousand "):(number += "Five Thousand ");break;
        case 4: (teenThsnd)?(number += "Fourteen Thousand "):(number += "Four Thousand ");break;
        case 3: (teenThsnd)?(number += "Thirteen Thousand "):(number += "Three Thousand ");break;
        case 2: (teenThsnd)?(number += "Twelve Thousand "):(number += "Two Thousand ");break;
        case 1: (teenThsnd)?(number += "Eleven Thousand "):(number += "One Thousand ");break;
        case 0: (teenThsnd)?(number += "Ten Thousand "):(number += "Thousand ");break;
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
    
    number += "dollars ";
    
    cent *= 100;
    int temp2 = cent;

    
    if(temp2 == 0){
        number += "and 00/100 cents.";
    }
    else{
        
        number += " and " + std::to_string(temp2) + "/100 cents.";
    }
    
    
    return number;
}