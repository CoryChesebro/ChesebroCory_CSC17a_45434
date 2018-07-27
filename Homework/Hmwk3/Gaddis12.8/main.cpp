#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

void arrToF(int*, const std::string&, const int);
void fToArr(int*, const std::string&, const int);

void fillArr(int*, const int);
void prntArr(int*, const int);


int main() {
    
    srand(static_cast<unsigned int>(time(0)));
    
    const int SIZE = 42;
    
    int *arrIn = new int[42];
    int *arrOut = new int[42];
    
    fillArr(arrOut, SIZE);
    
    std::cout<<"Arayy sent to file     : ";
    prntArr(arrOut, SIZE);
    std::cout<<std::endl;
    
    arrToF(arrOut, "arr.dat", SIZE);
    fToArr(arrIn, "arr.dat", SIZE);
    
    std::cout<<"Array pulled from file : ";
    prntArr(arrIn, SIZE);
    
    
    return 0;
}

void arrToF(int *arr, const std::string &name, const int size){
    
    std::fstream file;
    
    file.open(name, std::ios::out | std::ios::binary);
    
    file.write(reinterpret_cast<char *>(arr), sizeof(int) * size);
    
    file.close();
}

void fToArr(int *arr, const std::string &name, const int size){
    
    std::fstream file;
    
    file.open(name, std::ios::in | std::ios::binary);
    
    file.read(reinterpret_cast<char *>(arr), sizeof(int) * size);
    
    file.close();
}

void fillArr(int *arr, const int size){

    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100 + 1;
    }
}

void prntArr(int *arr, const int size){

    for(int i = 0; i < size; i++){
        std::cout<<arr[i]<<" ";
    }
}