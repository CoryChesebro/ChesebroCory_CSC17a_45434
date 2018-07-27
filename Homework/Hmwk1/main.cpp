#include <cstdlib>
#include <iostream>

void menu();

void prob1();
void sort(int*, int);
float avg(int*, int);
int sToI(std::string);
void order(int *tests,int size);

void prob2();
void prob3();

void prob4();
int *revrs (int*, int);

void prob5();
int *expand(int *, int);

int main(int argc, char** argv) {
    menu();
    return 0;
}


void menu(){
    std::string input = "\0\0";
    std::cout<<"Please choose which problem youd like to see"
            " by entering the corresponding number: "<<std::endl;
    std::cout<<"1. Problem 1"<<std::endl;
    std::cout<<"2. Problem 2"<<std::endl;
    std::cout<<"3. Problem 3"<<std::endl;
    std::cout<<"4. Problem 4"<<std::endl;
    std::cout<<"5. Problem 5"<<std::endl;
    
    std::cin>>input;
    
    if(input[0] > '9' || input[0] < '0' || input[1] != '\0'){
        std::cout<<"You chose incorrectly! So either you "
                "cant read or you dont want to be here"<<std::endl;
    }
    else{
        switch(input[0] - '0'){
            case 1: prob1();break;
            case 2: prob2();break;
            case 3: prob3();break;
            case 4: prob4();break;
            case 5: prob5();break;
        } 
    }
}

void prob1(){
    int *test;
    int SIZE = 0;
    std::string size = "";
    
    std::cout<<"To begin input the number of tests to average: ";
    std::cin>>size;
    std::cin.ignore();
    
    for(int i = 0; i < size.length(); i++){
        if(!(size[i] >= '0' || size[i] <= '9')){
            std::cout<<"invalid input!! Try again."<<std::endl;
            exit(EXIT_FAILURE);
        }
    }
    SIZE = sToI(size);
    if(SIZE == 0){std::cout<<"No tests were calculated";exit(EXIT_FAILURE);}
    test = new int[SIZE];
    
    for(int i = 0; i < SIZE; i++){
        int temp = 0;
        std::cout<<"Enter test score "<<i + 1<<": ";
        std::cin>>temp;
        test[i] = temp;
        std::cin.ignore();
    }
    sort(test, SIZE);
    //order(test, SIZE);
    std::cout<<"The sorted test scores are: "<<std::endl;
    for(int i = 0; i < SIZE; i++){
        std::cout<<test[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"The average test score is: "<<avg(test, SIZE);
    
}

void prob2(){
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
    std::cout<<"The donations in ascending order are: "<<std::endl;
    for(int i = 0; i < size; i++){
        std::cout<<donos[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"The donations in their original order are: "<<std::endl;
    for(int i = 0; i < size; i++){
        std::cout<<arrPtr[i]<<" ";
    }
}

void prob3(){
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
}

void prob4(){
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
}

void prob5(){
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
}

int sToI(std::string input){
    int total = 0;
    for(int i = 0; i < input.length(); i++){
        total = (total * 10) + (input[i] - '0');
    }
    return total;
}

void sort(int *arr, int SIZE){
    int minIndx = 0;
    int minVal = 0;
    int temp;
    for(int i = 0; i < SIZE; i++){
        minIndx = i;
        minVal = arr[i];
        for(int j = i + 1; j < SIZE; j++){
            if(arr[j] < minVal){
                minVal = arr[j];
                minIndx = j;
            }
        }
        temp = arr[minIndx];
        arr[minIndx] = arr[i];
        arr[i] = temp;
    }
}

float avg(int *arr, int SIZE){
    int temp = 0;
    for(int i = 0; i < SIZE; i ++){
        temp += arr[i];
    }
    return (temp / SIZE);
}

int *revrs(int *arr, int size){
    int *temp = new int[size];
    for(int i = 0, j = size - 1; i < size; i++,j--){
        temp[i] = arr[j];
    }
    return temp;
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