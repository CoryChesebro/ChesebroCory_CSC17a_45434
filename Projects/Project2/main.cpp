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
    // greeting to the game
    banner();
    
    // initialize player and dealers hands
    game.player.genHand(game);
    game.dealer.genHand(game);
    
    // necessary variables for the game to run 
    std::string input;
    int total;
    int temp = 0;
    bool valid;
    bool won;
    bool pAgain;
    bool bet = false;
    
    // determine if user wants betting enabled or not
    std::cout<<"Would you like betting to be available during your game?: y/n ";
    std::cin>>input;
    std::cin.ignore();
    if(input[0] == 'y'){
        std::cout<<"Betting enabled!"<<std::endl;
        bet = true;
    }
    else{
        std::cout<<"Betting disabled."<<std::endl;
    }
    
    input = "";
    
    // game loop used if the player wants to do multiple rounds
    do{
        pAgain = false;
        won = false;
        
        if(bet){
            total = game.player.getMoney();
            if(total == 0){
                std::cout<<"Since you lost all your money last round, the house"
                        " would like to give you $100 to keep playing."
                        <<std::endl;
                
                game.player.setMoney(100, true);
                total = game.player.getMoney();
            }
            std::cout<<"You have $"<<total<<", how much of it"
                    " would you like to bet?: ";
            
            // input validation for bet amount
            do{
                temp = 0;
                valid = true;
                input = "";
                std::cin>>input;
                for(int i = 0; i < input.length(); i++){
                    if(input[i] >= '0' && input[i] <= '9'){
                        temp = temp * 10 + input[i] - '0';
                    }
                    else{
                        std::cout<<"Invalid input, try again: ";
                        valid = false;
                        break;
                    }
                }
                if(!valid){
                    continue;
                }
                if(temp > total){
                    std::cout<<"You cant bet more than you have! Try again: ";
                    valid = false;
                }
            }while(!valid);
        }
        
        // main game loop that contains game logic
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
                
                // input validation for player moves
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
    
        // if else structure to determine game outcome
        if(game.player.isBusted()){
            std::cout<<"Busted! You went over 21!"<<std::endl;
            won = false;
            game.player.setMoney(temp, won);
        }
        else if(game.player.hasBJ()){
            std::cout<<"You win by default with a score of 21!"<<std::endl;
            won = true;
            game.player.setMoney(temp, won);
        }
        else if(game.dealer.isBusted()){
            std::cout<<"The dealer busted! You win!"<<std::endl;
            won = true;
            game.player.setMoney(temp, won);
        }
        else{
            if(game.player.getTotal() > game.dealer.getTotal()){
                std::cout<<"You win! Your total was greater than the dealers"<<std::endl;
                won = true;
                game.player.setMoney(temp, won);
            }
            else{
                std::cout<<"You lose! Your total was less than the dealers which had: ";
                std::cout<<game.dealer.getTotal();
                won = false;
                game.player.setMoney(temp, won);
            }
        }
        
        // asks player if they would like to play again to get more money
        input = "";
        std::cout<<std::endl<<std::endl<<std::endl;
        std::cout<<"Would you like to play again? y/n: ";
        
        std::cin>>input;
        std::cin.ignore();

        if(input[0] != 'y' && input[0] != 'Y'){
            std::cout<<"Okay, cya later!";
            exit(EXIT_FAILURE);
        }
        else{
            pAgain = true;
            game.reset();
            game.player.reset(game);
            game.dealer.reset(game);
        }
    }while(pAgain);
    
}

// outputs rules and necessary info
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