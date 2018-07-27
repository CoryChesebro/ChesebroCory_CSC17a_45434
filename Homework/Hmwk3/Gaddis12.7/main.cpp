#include <cstdlib>
#include <iostream>
#include <cctype>
#include <fstream>

// Sentence filter

void sntFltr(std::fstream&, std::fstream&);
std::string fltr(std::string&);

bool nameIn(std::string&, const std::string&);
bool isAlpha(char);
std::string trim(std::string&);

int main() {
    std::string iName;
    std::string oName;
    
//    iName = "input.txt";
//    oName = "output.txt";
    
    nameIn(iName, "in");
    nameIn(oName, "out");
    
    std::fstream input(iName, std::ios::in);
    std::fstream output(oName, std::ios::out);
    
    sntFltr(input, output);
    
    return 0;
}

void sntFltr(std::fstream &in, std::fstream &out){
    std::string temp;
    
    while(getline(in, temp)){
        fltr(temp);
        std::cout<<temp<<std::endl;
        temp = "";
    }
}

bool nameIn(std::string &name, const std::string &type){// Pass by reference is faster vs pass by copy ?
    bool period = false;
    
    if(type == "in"){
        std::cout<<"Enter the name of the file to input: ";
    }
    else if(type == "out"){
        std::cout<<"Enter the name of the file to output: ";
    }
    else{
        std::cout<<"You forgot to specify what the file name is for -- ";
        return false;
    }
    
    std::cin>>name;
    
    int size = name.length();

    for(int i = 0; i < size; i++){// Make sure its got all it needs
        if(!isAlpha(name[i]) && name[i] != '.'){
            std::cout<<name<<" is not a valid file name, try again.";
            return false;
        }
        else if(name[i] == '.'){
            if(!period){
                period = !period;
            }
            else{
                std::cout<<name<<" is not a valid file name - try again"; 
                return false;
            }
        }
    }

    for(int i = 1; i < size - 1; i++){
        if(isAlpha(name[i - 1]) && name [i] == '.' && isAlpha(name[i + 1]))
            return true;
    }
    
    return false;
}

bool isAlpha(char a){
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
        return true;
    }
    else return false;
}

std::string fltr(std::string &input){
    int size = input.length();
    
    input = trim(input);
    
    if(input[0] >= 'a' && input[0] <= 'z'){
        input[0] -= 32;
    }
    
    if(input[size - 1] != '.'){
        input += '.';
    }
    
    return input;
}

std::string trim(std::string &input){// Carriage returns ruining my life
    int size = input.length();
    
    for(int i = 0; i <= size; i++){
        if(input[i] == (char)(10) || input[i] == (char)(13)){
            input[i] = '\0';
        }
    }
    
    return input;
}