module Unownable;
// #include "observer.h"
import <vector>;
// import <algorithm>;
import <string>;
import <iostream>;
using namespace std;
// import <iomanip>;

// const int bottomLength = 7;

// void Unownable::executeUnownable(int pos, Player &p){
//     if (pos == 10){ //DCTimsLine
//         DCTimsLine();
//     } else if (pos == 30){ //GoToTims 
//         GoToTims();
//     } else if (pos == 38){ //Coop Fee 
//         CoopFee();
//     } else if (pos == 4){ //Tuition
//         Tuition(p);
//     } else if (pos == 0){ //Collect OSAP 
//         cout << "You landed on COLLECT OSAP, you gain $200!" << endl;
//     } else if (pos == 20){//Goose Nest 
//         cout << "You landed on GOOSE NESTING. Look out, incoming Geese!!" << endl; 
//     }else { //SLC or Needles hall
//         //triggerEvent(p);
//     }
// }

// void Unownable::Tuition(){

// }
// void Unownable::CoopFee(){

// }
// void Unownable::DCTimsLine(Player &p){
//     //very FIRST time they land in jail, set all statuses to jail etc.
//     //if actually in jail or just landed on this square 
//     cout << "You are, unfortunently, stuck in the famous DC Tims Line." << endl;
//     boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setJailStatusNum(1);
//     cout << "This is your first turn in line (jail)." << endl;
//     boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setJailTurns(1);
// }
// void Unownable::GoToTims(){
//     //jail (if not 0 means in jail, the number is also the number of turns they were in jail, so if 4 then NEEDS to pay 50 or use card)
//     //change pos to 10 
// }


void Unownable::printLongName(int lineNum) {
    string name = this->getBName();
    int length = name.length();
    if (length <= 7){
        if (lineNum == 1){
            // cout << left << setw(7) << name;
        } else {
            // cout << left << setw(7) << "";
        }
    } else {
        size_t lastSpace = name.rfind(' ');
        string first = name.substr(0, lastSpace);
        string second = name.substr(lastSpace + 1);
        if (lineNum == 1){
            cout << first;
        } else {
            cout << second;
        }
    }
}

// 

// size_t Building::getBPos() const {
//     return buildingPosition;
// } // Building::getBPos

// void Building::printBottom() {
//     for (int i = 0; i < bottomLength; i++){
//         cout << "_";
//     }
// } // Subject::getObserverNames

