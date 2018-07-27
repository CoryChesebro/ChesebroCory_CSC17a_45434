#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

#include "Cards.h"

char genCard(Game&);
void fillDeck(Game&);
void genHand(Cards&, Game&);
int chkVal(const Cards&);
void output(const std::string&, Game&);
void recap(Game&);
void expand(char*, int&, const int&);
void hit(Cards&, Game&);
void prntHnd(const Cards&, Game&);
void cmpTrn(Cards&, Game&);
void myLog(const std::string&, Game&);

void BJGame(Game&);


int main() {
    srand(static_cast<unsigned int>(time(0)));
    Game game;
    game.moves.open("moves.binary", std::ios::out | std::ios::trunc);
    game.moves.close();
    
    BJGame(game);

    return 0;
}

char genCard(Game &deck){
    int size = deck.deckSize;
    bool valid;
    int random;
    char card;
    
    do{
        valid = true;
        random = rand() % size;// no + 1 because arrays start at 0
        card = deck.deck[random];
        if(card == '*'){
            valid = false;
        }
        else{
            deck.deck[random] = '*';
        }
        
    }while(!valid);
    
    return card;
}

void genHand(Cards &hand, Game &game){
    hand.size = 2;
    hand.cards = new char[hand.size];
    hand.cards[0] = genCard(game);
    hand.cards[1] = genCard(game);
}


void fillDeck(Game &game){
    int size = game.deckSize;
    int count = 0;
    game.deck = new char[size];
    char array[13] = {'2','3','4','5','6','7','8','9','T','Q','K','J','A'};
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            game.deck[count] = array[j];
            count++;
        }
    }
}

void expand(char *arr, int &size, const int &inc){
    char *temp = new char[size + inc];
    
    for(int i = 0; i < size; i++){
        temp[i] = arr[i];
    }
    
    for(int j = size; j < size + inc; j++){
        temp[j] = '\0';
    }
    
    arr = temp;
    size += inc;
}

int chkVal(const Cards &hand){
    int total = 0;
    int size = hand.size;
    int aceCnt = 0;
    
    for(int i = 0; i < size; i++){
        char temp = hand.cards[i];
        switch(temp){
            case '2': total += 2;break;
            case '3': total += 3;break;
            case '4': total += 4;break;
            case '5': total += 5;break;
            case '6': total += 6;break;
            case '7': total += 7;break;
            case '8': total += 8;break;
            case '9': total += 9;break;
            case 'T': total += 10;break;
            case 'J': total += 10;break;
            case 'Q': total += 10;break;
            case 'K': total += 10;break;
            case 'A': aceCnt += 1;break;
            default: std::cout<<"Something is wrong in your chkVal function";
        }
    }
    
    for(int i = 0; i < aceCnt; i++){
        ((total + 11) > 21)?(total += 1):(total += 11);
    }
    
    return total;
}

void output(const std::string &move, Game &game){
    int size = move.length();
    char *temp = new char[size];
    
    for(int i = 0; i < size; i++){
        temp[i] = move[i];
    }
    
    game.moves.open("moves.binary", std::ios::out | std::ios::binary | std::ios::app);
    game.moves.write(temp, size);
    game.moves.close();
}

void recap(Game &game){
    std::string recapMoves;
    game.moves.open("moves.binary", std::ios::in | std::ios::binary);
    
    game.moves.seekg(0, game.moves.end);// Puts seek at end and records length
    int length = game.moves.tellg();// records length part
    game.moves.seekg(0, game.moves.beg);// Puts seek back at begginging
    
    char *buf = new char[length];
    game.moves.read(buf, length);
    
    for(int i = 0; i < length; i++){
        recapMoves += buf[i];
    }
    std::cout<<"The recap of last game is.. "<<std::endl<<std::endl;
    std::cout<<recapMoves<<std::endl;
}

void hit(Cards &cards, Game &game){
    expand(cards.cards, cards.size, 1);
    cards.cards[cards.size - 1] = genCard(game); // put card in end of arr
}

void prntHnd(const Cards &hand, Game &game){
    int value = chkVal(hand);
    int size = hand.size;
    std::string card;
    
    myLog("Your hand contains: ", game);
    
    for(int i = 0; i < size; i++){
        card = hand.cards[i];
        card += " ";
        myLog(card, game);
    }
    
    myLog(" which has a value of - " + std::to_string(value) + " \n", game);
}

void cmpTrn(Cards &hand, Game &game){
    int val = 0;
    
    do{
        val = chkVal(hand);
        if(val < 17){
            hit(hand, game);
        }
        
    }while(val < 17);
}

void myLog(const std::string &in, Game &game){
    std::cout<<in;
    std::cout<<std::flush;
    output(in, game);
}

void BJGame(Game &game){
    Player player;
    Player cmpter;
    
    fillDeck(game);
    
    genHand(player.hand,game);
    genHand(cmpter.hand,game);
    
    int playerVal = 0;
    int cmpterVal = 0;
    
    std::string input;
    bool valid;
    
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
    std::cout<<input[0]<<std::endl;
    std::cin.ignore();
    
    if(input[0] != 'y' && input[0] != 'Y'){
        std::cout<<"Okay, cya later!";
        exit(EXIT_FAILURE);
    }
    input = "";
    
    do{ 
        valid = true;
        input = "";
        prntHnd(player.hand, game);
        
        if(chkVal(player.hand) >= 21){
            break;
        }
        std::cout<<"would you like to [h]it, or [s]tand?: ";
        //myLog("would you like to [h]it, or [s]tand?: ", game);
        
        std::cin>>input;
        std::cout<<input[0]<<std::endl;
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
            cmpTrn(cmpter.hand, game);
        }
        else if(input[0] == 'h'){
            hit(player.hand, game);
        }
        else{
            std::cout<<"something went wrong ";
        }
    }while(input[0] == 'h');
    
    
    playerVal = chkVal(player.hand);
    cmpterVal = chkVal(cmpter.hand);
    
    if(playerVal == 21){
        myLog("Congratulations! You won \n", game);
    }
    else if(playerVal > 21){
        myLog("Busted!! You lost since you went over 21 \n", game);  
    }
    else if(cmpterVal > 21){
        myLog("Dealer busted! You win! \n", game);
    }
    else if(playerVal > cmpterVal){
        myLog("Congratulations! You won! the dealer had a hand worth " +
                std::to_string(cmpterVal) + "\n", game);
    }
    else if(playerVal == cmpterVal){
        myLog("Draw! You and the dealer had the same value \n", game);
    }
    else{
        myLog("You lose! The dealer had a value of " + std::to_string(cmpterVal) + "\n", game);
    }
    
    do{
        std::cout<<"Would you like a recap of the game you just played?: y/n"<<std::endl;
        std::cin>>input;
        std::cout<<input[0]<<std::endl;
        std::cin.ignore();
        if(input[0] != 'y' && input[0] != 'n'){
            std::cout<<"Invalid choice, try again: "<<std::endl;
        }
    }while(input[0] != 'y' && input[0] != 'n');
    
    if(input[0] == 'y'){
        recap(game);
    }
    std::cout<<std::endl<<"Cya later!";
}


