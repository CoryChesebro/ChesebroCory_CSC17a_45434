#include <iostream>
#include <cstdlib>
#include <ctime>


#include "Dealer.cpp"
#include "User.cpp"


void gmLoop(const Game&);

int main() {
    // Seed the random num generator
    srand(static_cast<unsigned int>(time(0)));

    Game game;

    gmLoop(game);
    
    return 0;
}

void gmLoop(const Game &game){
    
}