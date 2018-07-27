#include <iostream>
#include <cstdlib>

#include "Inventory.h"

int main() {
    Inventory shirt;
    Inventory pants(12345, 100, 49.95);
    
    shirt.setCost(29.95);
    shirt.setItemNum(1234567890);
    shirt.setQuant(100);
    shirt.setTCost();
    
    std::cout<<shirt.getCost()<<" "<<shirt.getTCost()<<" "<<shirt.getItemNum()<<" "
            <<shirt.getQuant()<<std::endl;
    
    std::cout<<pants.getCost()<<" "<<pants.getTCost()<<" "<<pants.getItemNum()<<" "
        <<pants.getQuant()<<std::endl;
    
    
    return 0;
}

