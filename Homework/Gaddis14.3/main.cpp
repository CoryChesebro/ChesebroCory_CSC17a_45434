#include <iostream>
#include <cstdlib>

#include "DayOfYear.h"

int main() {
    
    DayOfYear obj;
    
    obj.setDay();
    obj.calcDate();
    obj.print();
    
    return 0;
}

