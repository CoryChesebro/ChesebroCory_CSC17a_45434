#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
    std::cout<<"2.875 base 10 = "<<std::endl;
    std::cout<<"0000 0010.1110 0000 base 2"<<std::endl;
    std::cout<<"2.7 base 8"<<std::endl;
    std::cout<<"2.E base 16"<<std::endl;
    std::cout<<"Float representation in hex = 5C000002"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"0.1796875 base 10 = "<<std::endl;
    std::cout<<"0000 0000.0010 1110 base 2"<<std::endl;
    std::cout<<"0.134 base 8"<<std::endl;
    std::cout<<"0.2E base 16"<<std::endl;
    std::cout<<"Float representation in hex = 5C0000FE"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"-2.875 base 10 = "<<std::endl;
    std::cout<<"1111 1101.0010 0000 base 2"<<std::endl;
    std::cout<<"-2.7 base 8"<<std::endl;
    std::cout<<"-2.E base 16"<<std::endl;
    std::cout<<"Float representation in hex = E9000004"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"-0.1796875 base 10 = "<<std::endl;
    std::cout<<"1111 1111.1101 0010 base 2"<<std::endl;
    std::cout<<"-0.134 base 8"<<std::endl;
    std::cout<<"-0.2E base 16"<<std::endl;
    std::cout<<"Float representation in hex = E9000000"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"Hex 59999901 = Decimal 1.06...(repeating 6)"<<std::endl;
    std::cout<<"Hex 59999902 = Decimal 2.12...(repeating 12)"<<std::endl;
    std::cout<<"Hex A66667FE = Decimal -2.666...(repeating 6)"<<std::endl;
    return 0;
}

