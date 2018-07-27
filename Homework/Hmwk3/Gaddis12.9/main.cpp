#include <iostream>
#include <cstdlib>
#include <fstream>

std::string encrypt(const std::string&);
std::string decrypt(const std::string&);

int main(int argc, char** argv) {
    
    std::string test = "Hello World.";
    std::string test2;
    
    test2 = encrypt(test);
    std::cout<<test2<<std::endl;
    
    test2 = decrypt(test2);
    std::cout<<test2<<std::endl;
    
    return 0;
}

std::string encrypt(const std::string &secret){
    std::string output;
    int size = secret.length();
    int keyPos = size / 2;
    char key = secret[keyPos];

    for(int i = 0; i < size; i++){
        if(i == keyPos){
            output += secret[i];
        }
        else{
            output += secret[i] ^ key;
        }
    }
    return output;
}

std::string decrypt(const std::string &secret){
    std::string output;
    int size = secret.length();
    int keyPos = size / 2;
    char key = secret[keyPos];

    for(int i = 0; i < size; i++){
        if(i == keyPos){
            output += secret[i];
        }
        else{
            output += secret[i] ^ key;
        }
    }
    return output;
}