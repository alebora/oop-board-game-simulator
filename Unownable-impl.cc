module Unownable;
// #include "observer.h"
import <vector>;
// import <algorithm>;
import <string>;
import <iostream>;
using namespace std;
// import <iomanip>;

// const int bottomLength = 7;

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

