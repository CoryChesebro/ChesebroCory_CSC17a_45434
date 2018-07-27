#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>


#include "Dealer.cpp"
#include "User.cpp"

int main() {
    // Seed the random num generator
    srand(static_cast<unsigned int>(time(0)));
    
    
    Game game;
    
    Dealer<int> dealer;
    User<int> player;
    
    dealer.genHand(game);
    dealer.prntTotal();
    
    return 0;
}

