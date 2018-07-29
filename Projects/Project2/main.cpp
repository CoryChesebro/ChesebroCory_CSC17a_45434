#include <iostream>
#include <cstdlib>
#include <ctime>


#include "Dealer.cpp"
#include "User.cpp"


int main() {
    // Seed the random num generator
    srand(static_cast<unsigned int>(time(0)));
    
    
    
    Game game;
    
    game.player.genHand(game);
    game.player.prntTotal();

    game.dealer.genHand(game);
    game.dealer.prntTotal();
    
    std::cout<<std::endl;
    

    
    return 0;
}

