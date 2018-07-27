#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>

char mfc(const char*);

int main(){
    std::cout<<mfc("aaabbbbccccc");
}

char mfc(const char *arr){
    int size = strlen(arr);
    int max = 0;
    int count = 0;
    char mChar;
    
    for(char i = 'a'; i < 'z'; i++){
        for(int j = 0; j < size; j++){
            if(arr[j] == i){
                count++;
            }
            if(count > max){
                max = count;
                mChar = i;
            }
        }
    }
    
    return mChar;
}