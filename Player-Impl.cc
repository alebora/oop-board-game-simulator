module Player;
import ownable;
import <cstddef>;
import <cstdint>;
import <iostream>;
import <sstream>;
import <string>;
import <vector>;
import <ctime>;
import PRNG;

using namespace std;


Player::Player(string name, char acronym, int cups, int money, int pos, int jail, int turns) : 
    position(pos), name(name), money(money), acronym(acronym), inJail(jail), jailTurns(turns), isBankrupt(false), numRes(0), numGym(0), diceSum(0), rimCups(cups) { 
    }

// true: moveforward step
// false: movebackward step
void Player::move(size_t step, bool forward) {
    // *** implement
    if (forward){
        position += step;
        if (position > 40){
            position -= 40;
            cout << "Pass origin, get $200!" << endl;
            getMoney(200);
            // return true;        // reports to main that the player pass COLLECT OSAP
        }
        if (position == 40){
            position = 0;
        }
    } else {
        if (position < step){
            position = position - step + 40;
        }
        position -= step;
    }
    // return false            // reports to main that the player does not need to COLLECT OSAP
} // Player::move


void Player::addOwnable(Ownable* o){
    properties.emplace_back(o);
    // int groupSize = o->BlockGroupMembers.size(); // CHECK BlockGroupMembers HOW TO WORK AROUND
    // int ct = 0;
    // for (int i = 0; i < properties.size(); ++i){
    //     for (int j = 0; j < o->BlockGroupMembers[j]; ++j){
    //         if (properties[i] == o->BlockGroupMembers[j]){
    //             ++ct;
    //         }
    //     }
    //     if (ct == groupSize){
    //         monopolies.emplace_back(o->monopolyBlock); //adds the name of the monopoly group to Players monopolies
    //         break;
    //     }
    // }
    if (o->getBType() == 'G'){
        setNumGymOwned(1);
    }
    if (o->getBType() == 'R'){
        setNumResOwned(1);
    }
     //ALSO MAKE THE OTHER NEIGHBOUR BUILDINGS BOOL TO TRUE FOR MONOPOLY
}

void Player:: getMoney(int amount){
    money += amount;
    cout << "worth: " << money << endl;
}

void Player:: loseMoney(int amount){
    money -= amount;
    // if (amount < 0)  SELL OR MORTGAGE OR BANKRUPCY
}

void Player::loseCup(){
    rimCups -= 1;
}

void Player::sentTo(size_t pos){
    position = pos;
    if (pos == 10){
        inJail = 1;
    }
}

size_t Player::rollDice(){
    // PRNG prng(12345);  // Create PRNG with seed 12345
    // PRNG prng;
    PRNG prng(static_cast<std::uint32_t>(std::time(0)));  // Seed with current time
    size_t dice1 = prng(6) + 1;
    size_t dice2 = prng(6) + 1;
    cout << "Dice1: " << dice1 << " Dice2: " << dice2 << endl;
    return dice1 + dice2;
}

size_t Player::rollDouble(){
    // PRNG prng(12345);  // Create PRNG with seed 12345
    // PRNG prng;
    PRNG prng(static_cast<std::uint32_t>(std::time(0)));  // Seed with current time
    size_t dice1 = prng(6) + 1;
    size_t dice2 = prng(6) + 1;
    cout << "Dice1: " << dice1 << " Dice2: " << dice2 << endl;
    if (dice1 == dice2){
        return 2 * dice1;
    } else {
        return dice1 + dice2 + 12;
    }
}

int Player:: ifInJail(){
    return inJail;
}

int Player:: timesInJail(){
    return jailTurns;
}

int Player::cups(){
    return rimCups;
}

void Player::winCup(){
    rimCups += 1;
}

void Player::setFree(){
    inJail = 0;
    jailTurns = 0;
}

void Player:: incJailTurn(){
    jailTurns += 1;
}

void Player::broadcastPos(Building* bld){
    bld->attachPlayer(acronym);
}

void Player::printPlayer() {
    // *** implement
    cout << acronym;
} // Player::printPlayer

// void Player::addOwnable(Ownable* o){
//     properties.emplace_back(o);
//     int groupSize = o->BlockGroupMembers.size();
//     int ct = 0;
//     for (int i = 0; i < properties.size(); ++i){
//         for (int j = 0; j < o->BlockGroupMembers[j]; ++j){
//             if (properties[i] == o->BlockGroupMembers[j]){
//                 ++ct;
//             }
//         }
//         if (ct == groupSize){
//             monopolies.emplace_back(o->monopolyBlock); //adds the name of the monopoly group to Players monopolies
//             break;
//         }
//     }
// }


bool Player::findMonopolies(string monopolyName){
    for (int i = 0; i < monopolies.size(); ++i){
        if (monopolies[i] == monopolyName){
            return true;
        }
    }
    return false;
}

// void Player::removeOwnable(Ownable* o){
//     int i;
//     for (i = 0; i < properties.size(); ++i){
//         if (properties[i]->name == o->name){
//             break;
//         }
//     }
//     properties.erase(properties.begin() + i);
// }

// Ownable* Player::getOwnable(int pos){
//     return properties[pos];
// }

// Ownable* Player::getOwnable(string name){
//     for (i; i < properties.size(); ++i){
//         if (properties[i]->name == name){
//             return properties[i];
//         }
//     }
// }

// void Player::printPlayer(){
//     //ask Judy what fomat she needs
// }

// bool Player::payBank(){
//     //what is this
// }

// bool Player::payPlayer(){
//     //what is this
// }

// int Player::total_worth(){
//     //calculate total worth of Player money + assests (in properties and improvements) 
// }


// Getters and Setters: 

string Player::getName(){
    return name;
}

void Player::setName(string new_name){
    name = new_name;
}

size_t Player::getPos(){
    return position;
}

void Player::setPos(int pos){ //adds pos to the previous position value
    position = position + pos;
}

char Player::getAcronym(){
    return acronym;
}

void Player::setAcronym(char c){
    acronym = c; 
}

int Player::getMoney(){
    return money;
}

void Player::setMoney(int n){ //adds n to the previous money value
    money = money + n;
}

int Player::getDiceSum(){
    return diceSum;
}

void Player::setDiceSum(int n){
    diceSum = n;
}

int Player::getNumGymOwned(){
    return numGym;
}

void Player::setNumGymOwned(int n){
    numGym += n;
}

int Player::getNumResOwned(){
    return numRes;
}

void Player::setNumResOwned(int n){
    numRes += n;
}

int Player::getJailStatusNum(){
    return inJail;
}

void Player::setJailStatusNum(int n){
    inJail = n;
}

int Player::getJailTurns(){
    return jailTurns;
}

void Player::setJailTurns(int n){
    jailTurns += n;
}

int Player::getRimCups(){
    return rimCups;
}


void Player::setRimCups(int n){
    rimCups += n;
}

bool Player::getBankruptStatus(){
    return isBankrupt;
}

void Player::setBankruptStatus(bool b){
    isBankrupt = b;
}

// void Player::printAssests(){
//     cout << "Assets of: " << getName() << " " << getAcronym() << ":" << endl; 
//     cout << "Money: $" << getMoney() << "  Numer of RimCups: " << getRimCups() << endl; 
//     cout << "Properties owned: "; 
//     int ct = 0; 
//     // while (ct < properties.size()){
//     //     cout << properties[ct]->getBName() << " - improvement number: " << properties[ct]->getLevel() << endl;
//     // }
//     cout << "Just incase you were lazy to calculate total_worth... its: " << total_worth() << endl;
//     cout << "---------------------------------------------------------" << endl;
// }

