#include <iostream>
#include <cstdlib>

int *revrs (int*, int);

int main(int argc, char** argv) {

    int *arr, *arrCpy;
    int size = -1;
    
    std::cout<<"This fills an array with user input then reverses the array -"
            <<std::endl;  
    std::cout<<"How many numbers would you like to input: ";
    std::cin>>size;
    do{
        if(!(size > 0)){
            std::cout<<"Incorrect input, try again: ";
            std::cin>>size;
        }
    }while(size < 0);
    
    arr = new int[size];
    arrCpy =  new int[size];
    
    std::cout<<"Please enter the numbers youd like in the array"<<std::endl;
    for(int i = 0; i < size; i ++){
        int temp = 0;
        std::cout<<"Index "<<i+1<<" ";
        std::cin>>temp;
        std::cin.ignore();
        arr[i] = temp;
        arrCpy[i] = 0;
    }
    arrCpy = revrs(arr,size);
    
    std::cout<<"The original array - "<<std::endl;
    for(int i = 0; i < size; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"The array reversed - "<<std::endl;
    for(int i = 0; i < size; i++){
        std::cout<<arrCpy[i]<<" ";
    }
    
    
    return 0;
}

int *revrs(int *arr, int size){
    int *temp = new int[size];
    for(int i = 0, j = size - 1; i < size; i++,j--){
        temp[i] = arr[j];
    }
    return temp;
}