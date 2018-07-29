#include <iostream>
#include <cstdlib>
#include <ctime>


#include "Dealer.cpp"
#include "User.cpp"


void gmLoop(Game&);
void banner();

int main() {
    // Seed the random num generator
    srand(static_cast<unsigned int>(time(0)));

    Game game;

    gmLoop(game);
    
    return 0;
}

void gmLoop(Game &game){
    banner();
    
    game.player.genHand(game);
    game.dealer.genHand(game);
    
    std::string input;
    bool valid;
    
    do{
        valid = true;
        input = "";
        
        std::cout<<"Your hand contains: ";
        game.player.printHand();
        std::cout<<", which has a value of: "<<game.player.getTotal()
                <<std::endl;
        
        if(game.player.getTotal() >= 21){
            game.player.stand();
            break;
        }
        
        std::cout<<"Would you like to [h]it, or [s]tand?: ";
        
        std::cin>>input;
        std::cin.ignore();
        if(input[0] != 'h' && input[0] != 's'){
            valid = false;
            do{
                std::cout<<"Invalid input try again: ";
                std::cin>>input;
                std::cout<<input[0]<<std::endl;
                std::cin.ignore();
                if(input[0] == 'h' || input[0] == 's'){
                    valid = true;
                }
            }while(!valid);
        }
        else if(input[0] == 's'){
            game.player.stand();
            game.dealer.hit(game);
        }
        else if(input[0] == 'h'){
            game.player++;
            game.player.hit(game);
        }
        else{
            std::cout<<"You need better input validation :^)"<<std::endl;
            exit(EXIT_FAILURE);
        }        
    }while(input[0] == 'h');
    
    if(game.player.isBusted()){
        std::cout<<"Busted! You went over 21!"<<std::endl;
    }
    else if(game.player.hasBJ()){
        std::cout<<"You win by default with a score of 21!"<<std::endl;
    }
    else if(game.dealer.isBusted()){
        std::cout<<"The dealer busted! You win!"<<std::endl;
    }
    else{
        if(game.player.getTotal() > game.dealer.getTotal()){
            std::cout<<"You win! Your total was greater than the dealers"<<std::endl;
        }
        else{
            std::cout<<"You lose! Your total was less than the dealers which had: ";
            std::cout<<game.dealer.getTotal();
        }
    }
}

void banner(){
    std::string input;
    
    std::cout<<"Welcome to BlackJack!"<<std::endl;
    std::cout<<"Standard rules, you start with two cards \n"
            "if you have less than 21 you are allowed to hit \n"
            "to reach a max value of 21 to win the game! But, \n"
            "go over 21 and you lose! Cards with number values \n"
            "are worth their number, cards with face values \n"
            "excluding aces are worth 10 points. The ace card is worth \n"
            "either 1 or 11 points, whichever is in your favor."<<std::endl;
    std::cout<<"Are you ready to play?: y/n"<<std::endl;
    
    std::cin>>input;
    std::cin.ignore();
    
    if(input[0] != 'y' && input[0] != 'Y'){
        std::cout<<"Okay, cya later!";
        exit(EXIT_FAILURE);
    }
}