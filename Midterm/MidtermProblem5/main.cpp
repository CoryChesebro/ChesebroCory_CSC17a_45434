#include <iostream>
#include <cstdlib>
#include <cmath>


size_t factorial(int);// size_t is the biggest possible positive integer possible

void test(char);
void test(unsigned char);
void test(short);
void test(unsigned short);
void test(float);
void test(double);
void test(int);
void test(unsigned int);
void test(long);
void test(unsigned long);
void test(long long);
void test(unsigned long long);

int main(int argc, char** argv) {
    char a;
    unsigned char b;
    
    short c;
    unsigned short d;
    
    float e;
    
    double f;
    
    int g;
    unsigned int h;
    
    long i;
    unsigned long j;
    
    
    test(a);
    test(b);
    test(c);
    test(d);
    test(e);
    test(f);
    test(g);
    test(h);
    test(i);
    test(j);

    return 0;
}

size_t factorial(int x){
    size_t temp = 1;
    int temp2 = x;
    
    for(int i = 0; i < x; i++){
        temp *= temp2;
        temp2--;
    }
    
    return temp;
}

void test(char a){
    size_t maxSize = (pow(2, (sizeof(a) * 8)) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for char is "<<last<<" "<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(unsigned char a){
    size_t maxSize = pow(2, sizeof(a) * 8);
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for unsigned char is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(short a){
    size_t maxSize = (pow(2, sizeof(a) * 8) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for short is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(unsigned short a){
    size_t maxSize = pow(2, sizeof(a) * 8);
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for unsigned short is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(float a){
    size_t maxSize = (pow(2, sizeof(a) * 8) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for float is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(double a){
    size_t maxSize = (pow(2, sizeof(a) * 8) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for double is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(int a){
    size_t maxSize = (pow(2, sizeof(a) * 8) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for int is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(unsigned int a){
    size_t maxSize = pow(2, sizeof(a) * 8) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for unsigned int is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(long a){
    size_t maxSize = (pow(2, sizeof(a) * 8) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for long is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(unsigned long a){
    size_t maxSize = pow(2, sizeof(a) * 8) - 1;
    size_t last = 0;
    size_t last2 = 0;
    size_t temp = 0;
    
    for(int i = 0; i < 1000000; i++){
        temp = factorial(i);
        if(temp > maxSize){
            std::cout<<"Greatest factorial for unsigned long long is "<<last<<std::endl;
            break;
        }
        else{
            if(temp < last2){// to catch overflows
                std::cout<<"Greatest factorial for unsigned long long is "<<last<<std::endl;
                break;
            }
            last2 = temp;
            last = i;
        }
    }
}