#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>


#include "Dealer.cpp"
#include "User.cpp"

int main() {

    Game game;
    
    Dealer<int> dealer;
    User<int> player;
    
    dealer.getCard(game);
    player.getCard(game);
    
    return 0;
}

