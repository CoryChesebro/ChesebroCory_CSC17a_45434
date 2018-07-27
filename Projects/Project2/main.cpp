#include <iostream>
#include <cstdlib>


#include "Dealer.cpp"
#include "User.cpp"

int main() {

    Game game;
    
    Dealer<int> dealer;
    User<float> player;
    
    dealer.getCard(game);
    player.getCard(game);
    
    return 0;
}

