#include <iostream>
#include <cstdlib>

int encrypt(const int&);
bool verify(const int&);

int iInput(const std::string&, const std::string&);

int main(int argc, char** argv) {
    int temp = iInput("number to encrypt", "medium");
    if(verify(temp)){
        std::cout<<encrypt(temp)<<std::endl;
    }
    else{
        std::cout<<"Invalid key!! "<<temp<<" is not base 8"<<std::endl;
    }
    return 0;
}

int encrypt(const int &secret){
    int temp = secret;
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 0;
    
    first = temp / 1000;
    temp %= 1000;
    
    second = temp / 100;
    temp %= 100;
    
    third = temp / 10;
    temp %= 10;
    
    fourth = temp;
    
    first = (first + 5) % 8;
    std::cout<<first<<std::endl;
    second = (second + 5) % 8;
    std::cout<<second<<std::endl;
    third = (third + 5) % 8;
    std::cout<<third<<std::endl;
    fourth = (fourth + 5) % 8;
    std::cout<<fourth<<std::endl;
    
    int swap;
    swap = first;
    first = third;
    third = swap;
    
    swap = second;
    second = fourth;
    fourth = swap;
    
    temp = (first * 1000) + (second * 100) + (third * 10) + fourth;
    return temp;
}

bool verify(const int &input){
    int temp = input;
    int nThsnd = 0;
    int nHndrd = 0;
    int nTen = 0;
    int nOne = 0;
    
    nThsnd = temp / 1000;
    if(nThsnd > 7)return false;
    temp %= 1000;
    
    nHndrd = temp / 100;
    if(nHndrd > 7)return false;
    temp %= 100;
    
    nTen = temp / 10;
    if(nTen > 7)return false;
    temp %= 10;
    
    nOne = temp;
    if(nOne > 7)return false;
    
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
        else if(strictness == "medium"){
            if(size != 4){
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