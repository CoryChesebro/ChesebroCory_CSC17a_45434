#include <iostream>
#include <cstdlib>

int *expand(int *, int);

int main() {

    int *arr,*nArr, size = -1;
    
    std::cout<<"This program takes in an array and then doubles the size"
            " filling the extra space with 0s"<<std::endl;
    
    std::cout<<"How many numbers would you like to put in the array: ";
    std::cin>>size;
    
    if(size <= 0){
        std::cout<<"Thats not a valid input try again."<<std::endl;
        exit(EXIT_FAILURE);
    }
    arr = new int[size];
    std::cout<<"Enter the numbers to put in the array - "<<std::endl;
    for(int i = 0; i < size; i++){
        int temp = 0;
        
        std::cout<<"Index "<<i+1<<" :";
        std::cin>>temp;
        arr[i] = temp;
    }
    nArr = expand(arr,size);
    std::cout<<"The new array is: "<<std::endl;
    for(int i = 0; i < (size * 2); i++){
        std::cout<<nArr[i]<<" ";
    }
    
    return 0;
}

int *expand(int *arr, int size){
    int temp = size * 2;
    int *nArr = new int[temp];
    for(int i = 0; i < temp; i++){
        if(i >= size){
            nArr[i] = 0;
        }
        else{
            nArr[i] = arr[i];
        }
    }
    return nArr;
}