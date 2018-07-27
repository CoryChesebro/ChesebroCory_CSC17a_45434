#include <iostream>
#include <cstdlib>
#include <fstream>

struct cDiv{
    std::string division;
    const static int sSize = 4;
    int sales[sSize];
};

void prcsDivs(cDiv*);
void prntDivs(cDiv*);
void divsOut(cDiv*);

int input();
void debug(cDiv*);

int main() {
    const int size = 4;
    cDiv *arr = new cDiv[size];
    
    cDiv east;
    east.division = "East";
    arr[0] = east;
    
    cDiv west;
    west.division = "West";
    arr[1] = west;
    
    cDiv north;
    north.division = "North";
    arr[2] = north;
    
    cDiv south;
    south.division = "South";
    arr[3] = south;
    
    prcsDivs(arr); // - allows user input
    //debug(arr); // -  sets all values to 123 
    prntDivs(arr);
    divsOut(arr);
    
    return 0;
}

void prcsDivs(cDiv* divs){
    
    int size =  divs[0].sSize;
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            
            std::cout<<"Enter quarter "<<j + 1<<" sales for division "<<
                    divs[i].division<<" : ";
            divs[i].sales[j] = input();
            std::cout<<std::endl;
            
        }
    }
}

void prntDivs(cDiv* divs){
    
    int size =  divs[0].sSize;
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            
            std::cout<<divs[i].division<<" sales for quarter "<<j + 1<<" - $"<<
                    divs[i].sales[j]<<std::endl;
        }
        std::cout<<std::endl;
    }
}

void divsOut(cDiv *divs){
    std::fstream file("out.txt", std::ios::out);
 
    int size =  divs[0].sSize;
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            
            file<<divs[i].division<<" sales for quarter "<<j + 1<<" - $"<<
                    divs[i].sales[j]<<'\r'<<'\n';// to get output to work in 
                                                 // notepad.exe
        }
        file<<'\r'<<'\n';
    }
}

int input(){
    
    int input = 0;

    do{
        if(input < 0){
            std::cout<<"Please enter a positive value: ";
        }
        std::cin>>input;
        
    }while(input < 0);
    
    return input;
}

void debug(cDiv *divs){
    int size =  divs[0].sSize;
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            
            std::cout<<"Enter quarter "<<j + 1<<" sales for division "<<
                    divs[i].division<<" : ";
            divs[i].sales[j] = 123;
            std::cout<<std::endl;
            
        }
    }
}