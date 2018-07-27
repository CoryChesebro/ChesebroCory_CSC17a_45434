#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>

char *lower(const char*);
char *upper(const char*);
char *rev(const char*);

void prntArr(const char*);

int main(int argc, char** argv) {
    int size = 99999;
    char *arr = new char[size];
    char *uChars, *lChars, *rChars;
    
    std::cout<<"Enter a string and I will convert it to lowercase, upper case, "
            "and reverse case: ";
    std::cin.getline(arr, size);
    
    
    std::cout<<"Reverse case: ";
    rChars = rev(arr);
    std::cout<<rChars;
    std::cout<<std::endl;
    
    std::cout<<"Lower case: ";
    lChars = lower(arr);
    std::cout<<lChars;
    std::cout<<std::endl;
    
    std::cout<<"Upper case: ";
    uChars = upper(arr);
    std::cout<<uChars;
    std::cout<<std::endl;
    
    delete [] arr;
    delete [] rChars;
    delete [] lChars;
    delete [] uChars;
    
    
    return 0;
}

void prntArr(const char *arr){
    int size = strlen(arr);
    
    for(int i = 0; i < size; i++){
        std::cout<<arr[i];
    }
}

char *lower(const char *arr){
    char shift = 32;
    int size = strlen(arr) + 1;
    
    char *newArr = new char[size];
    newArr[size - 1] = '\0';
    
    for(int i = 0; i < size; i++){
        if(arr[i] >= 'A' && arr[i] <= 'Z'){
            newArr[i] = arr[i] + shift;
        }
        else{
            newArr[i] = arr[i];
        }
    }
    
    return newArr;
}

char *upper(const char *arr){
    char shift = 32;
    int size = strlen(arr) + 1;
    
    char *newArr = new char[size];
    newArr[size - 1] = '\0';
    
    for(int i = 0; i < size; i++){
        if(arr[i] >= 'a' && arr[i] <= 'z'){
            newArr[i] = arr[i] - shift;
        }
        else{
            newArr[i] = arr[i];
        }
    }
    return newArr;
}

char *rev(const char *arr){
    char shift = 32;
    int size = strlen(arr) + 1;
    
    char *newArr = new char[size];
    newArr[size - 1] = '\0';
    
    
    for(int i = 0; i < size; i++){
        if(arr[i] >= 'a' && arr[i] <= 'z'){
            newArr[i] = arr[i] - shift;
        }
        else if(arr[i] >= 'A' && arr[i] <= 'Z'){
            newArr[i] = arr[i] + shift;
        }
        else{
            newArr[i] = arr[i];
        }
    }
    return newArr;
}