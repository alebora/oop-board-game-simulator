module Player;
import PRNG;
import Building;
import ownable;
import academic;
import <cstddef>;
import <cstdint>;
import <iostream>;
import <sstream>;
import <string>;
import <vector>;
import <ctime>;
import <map>;


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
            gainMoney(200);
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


void Player:: gainMoney(int amount){
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

void Player::addOwnable(Ownable* o){
   properties.emplace_back(o);
//    int groupSize = o->BlockGroupMembers.size(); // CHECK BlockGroupMembers HOW TO WORK AROUND
//    int ct = 0;
//    for (int i = 0; i < properties.size(); ++i){
//        for (int j = 0; j < o->BlockGroupMembers[j]; ++j){
//            if (properties[i] == o->BlockGroupMembers[j]){
//                ++ct;
//            }
//        }
//        if (ct == groupSize){
//            monopolies.emplace_back(o->monopolyBlock); //adds the name of the monopoly group to Players monopolies
//            break;
//        }
//    }
    if (o->getBType() == 'A'){ //if academic then looks for monopoly 
        map<string, int> m = {{"Arts1", 2}, {"Arts2", 3}, {"Eng", 3}, {"Health", 2}, {"Env", 3}, {"Sci1", 3}, {"Sci2", 3}, {"Math", 2}};
        string block = (static_cast<Academic*>(o))->getMonopolyBlock();
        int numBlocks = m[block];
        int ct = 0;
        
        for (int i = 0; i < properties.size(); ++i){
            if (properties[i]->getBType() == 'A'){
                if ((static_cast<Academic*>(properties[i]))->getMonopolyBlock() == block){
                    ++ct;
                }
            }
        }
        if (ct == numBlocks){ // found monopoly
            for (int i = 0; i < properties.size(); ++i){
                if (properties[i]->getBType() == 'A'){
                    if ((static_cast<Academic*>(properties[i]))->getMonopolyBlock() == block){
                        (static_cast<Academic*>(properties[i]))->setHasMonopoly(true);
                    }
                }
            }
        }
    }
   // NEED TO SET THE OTHER ONE TO TRUE AS WELL
   if (o->getBType() == 'G'){
       setNumGymOwned(1);
   }
   if (o->getBType() == 'R'){
       setNumResOwned(1);
   }
    //ALSO MAKE THE OTHER NEIGHBOUR BUILDINGS BOOL TO TRUE FOR MONOPOLY
}


bool Player::findMonopolies(string monopolyName){
    for (int i = 0; i < monopolies.size(); ++i){
        if (monopolies[i] == monopolyName){
            return true;
        }
    }
    return false;
}

void Player::removeOwnable(Ownable* o){
   int i = 0;
   for (i = 0; i < properties.size(); ++i){
       if (properties[i]->getBName() == o->getBName()){
           break;
       }
   }
   properties.erase(properties.begin() + i);
}


Ownable* Player::getOwnable(int pos){
   return properties[pos];
}


Ownable* Player::getOwnable(string name){
   for (int i = 0; i < properties.size(); ++i){
       if (properties[i]->getBName() == name){
           return properties[i];
       }
   }
}




int Player::total_worth(){
   //calculate total worth of Player money + assests (in properties and improvements)
   int moneyTotal = money;
   int improvementsTotal = 0;
   int propertiesTotal = 0;
   for (int i = 0; i < properties.size(); ++i){
       //sell an improvement, they receive half of the cost of the improvement!!!
       if (properties[i]->getBType() == 'A'){
            Academic *a = static_cast<Academic*>(properties[i]);
           if (a->getLevel() != 0) {
                for (int j = 0; j < a->getLevel(); ++j){
                    improvementsTotal += (a->getImprovementCost() / 2);
                }
           }
       }
       //When a property is mortgaged, they receive half of the cost of the property
       // CHECK IF ITS NOT MORTGAGED
       propertiesTotal += (properties[i]->getCost() / 2);
   }
   return moneyTotal + improvementsTotal + propertiesTotal;
}

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

void Player::printAssests(){
    cout << "Assets of: " << getName() << " " << getAcronym() << ":" << endl; 
    cout << "Money: $" << getMoney() << "  Number of RimCups: " << getRimCups() << endl; 
    cout << "Properties owned: " << endl; 
    int ct = 0; 
    while (ct < properties.size()){
        if (properties[ct]->getBType() == 'A') {
            cout << properties[ct]->getBName() << " - improvement number: " << (static_cast<Academic*>(properties[ct]))->getLevel() << "    Mortgage Status: " << properties[ct]->getMortgageState() << endl;
        } else {
            cout << properties[ct]->getBName() << endl;
        }
        ++ct;
    }
    cout << "Just in case you were too lazy to calculate your total worth..., it's: " << total_worth() << endl;
    cout << "---------------------------------------------------------" << endl;
}

