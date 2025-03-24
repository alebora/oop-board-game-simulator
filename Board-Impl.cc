module Board;
import Player;
import <iostream>;
import <string>;
import <vector>;

using namespace std;

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

// void Board::addBuilding(string Bname, string owner, int improvements, int pos){ // !! Need to see how ctor is implemented for academic, gym, and res
//     // !! Building ctor !! ?? can be any of 4 types: 
//     if(...){ //ownable
//         Player *Theowner = getplayer(owner);
//         Academic *b(Bname, pos, Theowner, improvements);
//     }else if (...){
//         Player *Theowner = getplayer(owner);
//         Gym *b(Bname, pos, Theowner);
//     } else if (...){
//         Player *Theowner = getplayer(owner);
//         Res *b(Bname, pos, Theowner);
//     } else {
//         Unownable *b(Bname, pos);
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
}

void Board::trade(string name, string giveMoney, string receiveMoney){
    // TO IMPLEMENT
}

void Board::academicImprovements(Building *property, string action){
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
            trade(name, give, receive);

        } else if (com == "improvements") { //improve <property> sell/buy
            string propertyName; 
            string status; 
            cin >> propertyName >> status;
            Building *b = getBuilding(propertyName);
            if (b) {
                academicImprovements(b, status); 
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

