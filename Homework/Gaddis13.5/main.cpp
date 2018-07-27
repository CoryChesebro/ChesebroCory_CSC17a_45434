#include <iostream>
#include <cstdlib>

#include "Retail_Item.h"

int main() {
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2;
    RetailItem item3("Shirt", 20, 24.95);
    
    item2.setDesc("Designer Jeans");
    item2.setPrice(34.95);
    item2.setUnits(40);
    
    
    std::cout<<item1.getDesc()<<" "<<item1.getPrice()<<" "<<item1.getUnits()<<std::endl;
    std::cout<<item2.getDesc()<<" "<<item2.getPrice()<<" "<<item2.getUnits()<<std::endl;
    std::cout<<item3.getDesc()<<" "<<item3.getPrice()<<" "<<item3.getUnits()<<std::endl;
    
    
    return 0;
}

