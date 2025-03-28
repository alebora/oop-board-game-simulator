module Board;
import Player;
import academic;
import Building;
import gym;
import ownable;
import residence;
import <iostream>;
import <string>;
import <vector>;

using namespace std;

vector<vector<int>> tuitionVec; 
vector<int> improvementCostVec;
vector<string> monopolyBlockVec;

Board::Board(): currPlayer(0), remainingRimCups(2) {
    //vec_buildings initilized harcoded;
}

Player* Board::getPlayer(string s){
    for (int i = 0; i < vec_players_selected.size(); ++i){
        if (vec_players_selected[i]->getName() == s){
            return vec_players_selected[i];
        }
    }
    return nullptr; 
}

// Board::~Board(){
//     //clear all heap allocated ctors in addBuilding
// }

// void Board::addBuilding(string Bname, string owner, int improvements, int pos){ // !! Need to see how ctor is implemented for academic, gym, and res
//     // !! Building ctor !! ?? can be any of 4 types:
//     // !! MAKE EACH ONE HEAP ALLOCATED 
//     Player *p;
//     if (Bname != "BANK") {
//         p = getPlayer(Bname);
//     } else {
//         p = nullptr;
//     }
//     if (pos == 12 || pos == 28){ //gym
//         Gym *b(Bname, pos, p); 
//     }else if (pos == 5 || pos == 15 || pos == 25 || pos == 35){ //res
//         Res *b(Bname, pos, p); 
//     } else if (pos == 0 || pos == 2 || pos == 4 || pos == 7 || pos == 10 || pos == 17 || pos == 20 || pos == 22 || pos == 30 || pos == 33 || pos == 36 || pos == 38){ //unownable
//         Unownable *b(Bname, pos);
//     } else { 
//         // Academic *b(Bname, pos, p, improvements, string monopolyBlock, vector<size_t> tuition, int improvementCost, bool hasMonopoly);
//         // need to find the monopolyBlock, fill in all the tuitions manually :(, and improvement cost, and the hasmonopoly boolean.
//     }
//     vec_buildings.emplace_back(b);
// }

// int Board::getSize(){
//     return vec_players_selected.size();
// }

void Board::printBoard(){
    //ask Judy what she needs 
}

// void Board::stateOfBoardChange(){
//     notifyObservers();
// }

int Board::getNumPlayers(){
    return vec_players_selected.size();
}

void Board::addPlayer(Player *player){
    vec_players_selected.emplace_back(player);
}

int Board::getCurrPlayer(){
    return currPlayer;
}

void Board::setCurrPlayer(int n){
    currPlayer = n;
}

int Board::getRemainingNumRimCups(){
    return remainingRimCups;
}

void Board::setRemainingNumRimCups(int n){
    remainingRimCups = n; 
}

int Board::moneyOwed(Building *building, int diceSum){
    // TO IMPLEMENT
    
    Ownable *ownableBuilding = static_cast<Academic*>(building);

    char bType = ownableBuilding->getBType();
    int owed = 0;
    if (bType == 'A') {

        Academic *academic = static_cast<Academic*>(ownableBuilding);
        //check the number of academic properties an owner owns?
        //tuition is the rent
        //Tuition is doubled for each building that has no improvements when the monopoly is owned by a single player.
        //check if the current building is a part of a monopoly and if there are no improvements
        //otherwise, just regular tuition cost
        
        //1. can check if the current building (getMonopolyBlock) is a part of the monopoly vector of player
        //2. if is part of a monopoly, check if there are improvements (getImprovementLevel) if 0 => double, else return Tuition
        
        //1. get owner
        //2. from academic building -> get getMonopolyBlock
        //2. from player, findMonopolies() => T/F

        Player *owner = academic->getOwner();

        if (owner == nullptr) {
            std::cerr << "Error. There is no owner for this building." <<endl;
            return 0;
        }

        string monBlock = academic->getMonopolyBlock();
        bool isInMonopoly = owner->findMonopolies(monBlock);

        if (isInMonopoly) {
            int impLevel = academic->getLevel();
            if(impLevel == 0) {
                return 2*academic->getTuition();
            }
        }

        return academic->getTuition();

    } else if (bType = 'R') {
        Residence *residence = static_cast<Residence*>(ownableBuilding);
        Player *owner = residence->getOwner();

        if (owner == nullptr) {
            std::cerr << "Error. There is no owner for this building." <<endl;
            return 0;
        }

        int numOwner = owner->getNumResOwned();
        return residence->calcResCost(numOwner);

    } else if (bType == 'G') {

        Gym *gym = static_cast<Gym*>(ownableBuilding);
        Player* owner = gym->getOwner();

        if (owner == nullptr) {
            std::cerr << "Error. There is no owner for this building." <<endl;
            return 0;
        }
        
        int gymNum = owner->getNumGymOwned();
        return gym->usageFee(diceSum, gymNum);
    }

    return owed;

}

void Board::trade(string name, string giveMoney, string receiveMoney, Player *player){
    //Player *player is the person requesting the trade
    Player *reqFrom = getPlayer(name);

    //if user is receiving/giving building else money and stoi()
    bool giveBuilding = false;
    bool receiveBuilding = false;

    vector<string> trading = {giveMoney, receiveMoney};
    Academic *give;
    Academic *receive;
    for (int i = 0; i < trading.size(); ++ i) {
        for (int j = 0; j < vec_buildings.size(); ++j) {
            if (vec_buildings[j]->getBName() == trading[i]){
                if (trading[i] == giveMoney) {
                    giveBuilding = true;
                    give = static_cast<Academic*>(vec_buildings[j]);
                    if(give->getBType() == 'A') {
                        
                        if(give->getLevel() != 0) {
                            cout << "Trade rejected, you cannot trade a property with improvements." << endl;      
                        }
                        return;
                    }
                } else {
                    receiveBuilding = true;
                    receive = static_cast<Academic*>(vec_buildings[j]);
                    if(receive->getBType() == 'A') {
                        if(receive->getLevel() != 0) {
                            cout << "Trade rejected. You cannot trade a property with improvements." << endl;      
                        }
                        return;
                    }
                }
            }
        }
    }

    //Accept/Reject Stage
    cout << name << ", do you accept or reject this offer?" << endl;
    string choice;
    while(true) {
        cout << "Please enter accept or reject." << endl;      
        cin >> choice;
        if(choice == "accept" || choice == "reject") {
            break;
        }
    }

    if (choice == "reject") {
        cout << name << " has rejected the offer.";
        return;
    }

    //Money Building
    if (!giveBuilding && receiveBuilding) {
        //how much the player is giving, convert to integer
        int giveM = stoi(giveMoney);
        int bank = reqFrom->getMoney(); 

        if (giveM > bank) {
            cout << "Trade rejected. You do not have enough money to make this trade" <<endl;
            return;
        }
        Player *tmpPlayer = receive->getOwner();
        if(tmpPlayer == nullptr) {
            cout << "Trade rejected. " << name << "does not own " << receiveMoney <<endl;
            return;
        }

        string receiveName = tmpPlayer->getName();

        if ( receiveName != name) { //verifying ownership
            cout << "Trade rejected. " << name << "does not own " << receiveMoney <<endl;
            return;
        }

        receive->removeOwner();
        receive->setOwner(player);
        reqFrom->setMoney(giveM);
        giveM = -giveM;
        player->setMoney(giveM);

        cout << "Trade succesful! " <<endl;
        return;
    }

    //Building Building
    if (giveBuilding && receiveBuilding) {
        Player *tmpPlayer1 = receive->getOwner();

        if(tmpPlayer1) {
            cout << "Trade rejected. " << name << "does not own " << receiveMoney <<endl;
            return;
        }

        string receiverBuilding = tmpPlayer1->getName();

        if ( receiverBuilding != name ) { //verifying ownership
            cout << "Trade rejected. " << name << "does not own " << receiveMoney <<endl;
            return;
        }

        string giveName = player->getName();

        Player *tmpPlayer = give->getOwner();
        //if no owner
        if(tmpPlayer == nullptr) {
            cout << "Trade rejected. " << giveName << "does not own " << receiveMoney <<endl;
            return;
        }

        string buildingOwner = tmpPlayer->getName();


        if ( buildingOwner != giveName) { //verifying ownership
            cout << "Trade rejected. " << giveName << "does not own " << giveMoney <<endl;
            return;
        }
        receive->removeOwner();
        receive->setOwner(player);

        give->removeOwner();
        give->setOwner(reqFrom);

        cout << "Trade succesful! " <<endl;
        return;
    }

    //Building Money 
    if (giveBuilding && !receiveBuilding) {
        int receiveM = stoi(receiveMoney);
        int bank = reqFrom->getMoney(); 

        if (receiveM > bank) {
            cout << "Trade rejected. " << name << " does not have enough money to make this trade" <<endl;
            return;
        }

        string giveName = player->getName();
        Player *tmpPlayer = give->getOwner();

        if(tmpPlayer == nullptr) {
            cout << "Trade rejected. " << giveName << "does not own " << receiveMoney <<endl;
            return;
        }

        string buildingOwner = tmpPlayer->getName();

        if (buildingOwner != giveName) { //verifying ownership
            cout << "Trade rejected. " << giveName << "does not own " << giveMoney <<endl;
            return;
        }

        give->removeOwner();
        give->setOwner(reqFrom);

        player->setMoney(receiveM);
        receiveM = -receiveM;
        reqFrom->setMoney(receiveM);
        cout << "Trade succesful! " <<endl;
        return;
        
    } else {
        //throw error
        std::cerr << "Unsuccesful attempt at trading. " << endl;
        return;
    }    
}

void Board::academicImprovements(Building *property, string action, Player *player){
    // TO IMPLEMENT
}

void Board::mortgage(Building *property, Player *player){
    // TO IMPLEMENT
}

void Board::bankrupt(Player *player, int Owed, Player *toWho){
    // TO IMPLEMENT
    //need to verify if they really want to declare bankruptcy 
    //NEED to chnage the currPlayer to next player index (check doc) 
}

void Board::auction(Building *building){
    // TO IMPLEMENT
}

Building* Board::getBuilding(string Bname){
    int i;
    for (i = 0; i < vec_buildings.size(); ++i){
        if (vec_buildings[i]->getBName() == Bname){
            return vec_buildings[i];
        }
    }
    cout << Bname << " is not a valid building name" << endl;
    return nullptr;
}


void Board::pay(Player *whoOwes, int howMuchOwed, Player *toWhoOwed){
    string com;
    while (whoOwes->getMoney() < howMuchOwed || whoOwes->getBankruptStatus()) {
        while (!(cin >> com)){
            cout << "invalid command, please chose any of - trade <name> <give> <receive>, improve <property> sell, mortgage <property>, or bankrupt: //assets and all  " << endl; //declare bankruptcy??
        }
        if (com == "trade") { //trade <name> <give> <receive>
            string name; 
            string give;
            string receive;
            cin >> name >> give >> receive; 
            trade(name, give, receive, whoOwes);

        } else if (com == "improvements") { //improve <property> sell/buy
            string propertyName; 
            string status; 
            cin >> propertyName >> status;
            Building *b = getBuilding(propertyName);
            if (b) {
                academicImprovements(b, status, whoOwes); 
            }
        } else if (com == "mortgage") { // mortgage <property>
            string propertyName; 
            cin >> propertyName;
            Building *b = getBuilding(propertyName);
            if (b) {
                mortgage(b, whoOwes); //whoOwes is player who is doing the mortgaging
            }
        } else if (com == "bankrupt"){ 
            bankrupt(whoOwes, howMuchOwed, toWhoOwed); //maybe do a double check if they really want to bankrupt bc it is irreversible if it works 
        } else {
            cout << "not a valid choice, please chose any of - trade <name> <give> <receive>, improve <property> sell, mortgage <property>, or bankrupt: " << endl; //declare bankruptcy??
        }
    }
    if (whoOwes->getBankruptStatus()){
        cout << "It was nice having you in the game, now it is the next players turn." << endl;
    } else {
        whoOwes->setMoney((howMuchOwed * -1)); // removes the money owed from the player who landed on the space 
        toWhoOwed->setMoney(howMuchOwed); //pays the owner the money owed
        cout << "You have enough money, the rent has been paid. Your current balance is: " << whoOwes->getMoney() << endl;
    }
}

