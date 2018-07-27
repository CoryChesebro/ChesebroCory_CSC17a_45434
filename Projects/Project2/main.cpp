#include <iostream>
#include <cstdlib>



#include "Dealer.cpp"

int main() {

    Game game;
    Player<int> player;
    
    Dealer<int> dealer;
    
    dealer.getCard(game);
    
    player.getCard(game);
    
    return 0;
}

