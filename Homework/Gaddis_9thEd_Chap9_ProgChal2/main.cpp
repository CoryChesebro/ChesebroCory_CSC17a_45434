#include <iostream>
#include <cstdlib>

void sort(int*, int);
float avg(int*, int);
int sToI(std::string);
void order(int *tests,int size);

int main() {
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
    
    
    return 0;
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
