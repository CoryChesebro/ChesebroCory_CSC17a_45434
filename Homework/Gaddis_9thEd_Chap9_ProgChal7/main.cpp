#include <iostream>
#include <cstdlib>

void sort(int*, int);

int main() {
    int *arrPtr, *donos;
    int size = 0;
    
    std::cout<<"To begin please enter the number of donations youd like to give: ";
    std::cin>>size;
    std::cin.ignore();
    
    arrPtr = new int[size];
    donos = new int[size];
    
    for(int i = 0; i < size; i++){
        donos[i] = 0;
        arrPtr[i] = NULL;
    }
    
    std::cout<<"Next, enter the amount for each donation - "<<std::endl;
    for(int i = 0; i < size; i++){
        do{
            if(donos[i] < 0){std::cout<<"Invalid Entry. Please try again: ";}
            else{std::cout<<"Enter donation amount: ";}
            std::cin>>donos[i];
        }while(donos[i] <= 0);
    }
    
    for(int i = 0; i < size; i++){
        arrPtr[i] = donos[i];
    }
    sort(arrPtr, size);
    std::cout<<"The donations in descending order are: "<<std::endl;
    for(int i = 0; i < size; i++){
        std::cout<<donos[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"The donations in their original order are: "<<std::endl;
    for(int i = 0; i < size; i++){
        std::cout<<arrPtr[i]<<" ";
    }
    
    return 0;
}

void sort(int *arr, int SIZE){
    int minIndx = 0;
    int minVal = 0;
    int temp;
    for(int i = 0; i < SIZE; i++){
        minIndx = i;
        minVal = arr[i];
        for(int j = i + 1; j < SIZE; j++){
            if(arr[j] > minVal){
                minVal = arr[j];
                minIndx = j;
            }
        }
        temp = arr[minIndx];
        arr[minIndx] = arr[i];
        arr[i] = temp;
    }
}