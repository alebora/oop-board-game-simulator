module Player;
//import ownable;
import <iostream>;
import <string>;
import <vector>;
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
        if (position >= 40){
            position -= 40;
            // return true;        // reports to main that the player pass COLLECT OSAP
        }
    } else {
        if (position < step){
            position = position - step + 40;
        }
        position -= step;
    }
    // return false            // reports to main that the player does not need to COLLECT OSAP
} // Player::move

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

int Player::getPos(){
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
    numGym = n;
}

int Player::getNumResOwned(){
    return numRes;
}

void Player::setNumResOwned(int n){
    numRes = n;
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

// increase RimCup by 1, called when the player wins a cup in SLC or Needles Hall
void Player::winCup(){
    rimCups += 1;
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

