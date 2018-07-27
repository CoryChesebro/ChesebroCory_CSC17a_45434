#include <iostream>
#include <cstdlib>
#include <string>

float mean(int, int*);
float median(int, int*);
int *mode(int, int*, int&);

int *inputArr(int);
int sToI(std::string);
void sort(int*, int);
void prntArr(int*, int);

int main() {
    float sMean = 0.0f, sMedian = 0.0f;
    int *modes;
    int *arr;
    int size = 0;
    int size2 = 0;
    std::string temp = "";
    
    std::cout<<"Enter the size of the array youd like to analyze: ";
    std::cin>>temp;
    size = sToI(temp);
    
    // Input the array
    arr = inputArr(size);
    // Sort the array
    sort(arr, size);
    prntArr(arr,size);
    // Process the array
    modes = mode(size, arr, size2);
    sMean = mean(size, arr);
    sMedian = median(size, arr);
    std::cout<<"Mean - "<<sMean<<std::endl<<"Median - "<<sMedian<<std::endl;
    for(int i = 0; i < size2; i++){
        if(i == 0){
            std::cout<<"Number of modes: ";
        }
        else if(i == 1){
            std::cout<<"Max frequency: ";
        }
        else if (i == 2){
            std::cout<<"The modes themselves: ";
        }
        std::cout<<modes[i]<<" ";
    }
    // Output data
    return 0;
}


float mean(int size, int *arr){
    
    int sum = 0;
    float mean = 0.0f;
    
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    
    mean = (float)(sum) / size;
    
    return mean;
}

float median(int size, int *arr){
    float medn = 0.0f;
    if(size % 2 == 0){
        medn = arr[(size / 2)] + arr[((size / 2) - 1)];
        medn /= 2.0f;
    }
    else{
        medn = arr[size / 2];
    }

    return medn;
}

int *mode(int size, int *arr, int &size2){// MUST BE SORTED TO WORK PROPERLY
    int *modes;
    int freq = 1;
    int nModes = 0;
    
    int cFreq = 1;
    for(int i = 1; i < size; i++){
        if(arr[i] == arr[i - 1]){
            cFreq++;
            if(cFreq == freq){
                nModes++;
            }
            if(cFreq > freq){
                freq = cFreq;
                nModes = 1;
            }
        }
        else cFreq = 1;
    }
    
    // num of modes - max frequency - the modes themselves
    int count = 0;
    size2 = 2 + nModes;
    modes = new int[size2];
    for(int i = 0; i < size2; i++){modes[i] = -1;}
    modes[count] = nModes;count++;
    modes[count] = freq;count++;
    
    int temp = 1;
    for(int i = 1; i < size; i++){
        if(arr[i] == arr[i - 1]){
            temp++;
            if(temp == freq){
                modes[count] = arr[i];
                count++;
            }
        }
        else temp = 1;
    }
    //prntArr(modes, size2);
    return modes;
}

int sToI(std::string input){// Input validation 
    int temp = 0;
    for(int i = 0; i < input.length(); i++){
        if(input[i] >= '0' && input[i] <= '9'){
            temp = (temp * 10) + (input[i] - '0');
        }
        else{
            std::cout<<"INVALID INPUT - "<<input<<" - is not an integer."<<
                    std::endl<<"Try again please.";
            exit(EXIT_FAILURE);
        }
    }
    return temp;
}

int *inputArr(int size){
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        std::string temp = "";
        int temp2 = 0;
        std::cout<<"Enter the numbers youd like in your array: ";
        std::cin>>temp;
        temp2 = sToI(temp);
        arr[i] = temp2;
    }
    return arr;
}

void sort(int *arr, int size){
    int minIndx, minVal, temp;
    for(int i = 0; i < size; i++){
        minIndx = i;
        minVal = arr[i];
        for(int j = i + 1; j < size; j++){
            if(arr[j] < minVal){
                minIndx = j;
            }
        }
        temp = arr[minIndx];
        arr[minIndx] = arr[i];
        arr[i] = temp;
    }
}

void prntArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        std::cout<<arr[i]<<" ";
    }
}