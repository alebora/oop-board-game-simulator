module Unownable;
<<<<<<< HEAD
=======
// #include "observer.h
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
import <iostream>;
import <vector>;
import <algorithm>;
import <string>;
<<<<<<< HEAD
//import <iomanip>;
=======
import <iomanip>;
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
import <memory>;
using namespace std;

const int bottomLength = 7;
<<<<<<< HEAD

Unownable::Unownable(std::string BName, size_t pos): Building{BName, pos, false} {
    // ownable = false;
}
=======
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f

Unownable::Unownable(std::string BName, size_t pos): Building{BName, pos, false} {
    // ownable = false;
}

void Unownable::printLongName(int lineNum) {
    std::string name = this->getBName();
    int length = name.length();
    if (length <= 7){
        if (lineNum == 1){
<<<<<<< HEAD
            //std::cout << std::left << std::setw(bottomLength) << name << "|";
=======
            std::cout << std::left << std::setw(bottomLength) << name << "|";
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
        } else {
            emptyRow();
        }
    } else {
        size_t lastSpace = name.rfind(' ');
        std::string first = name.substr(0, lastSpace);
        std::string second = name.substr(lastSpace + 1);
        if (lineNum == 1){
<<<<<<< HEAD
            //std::cout << left << setw(bottomLength) << first << "|";
        } else {
            //std::cout << left << setw(bottomLength) << second << "|";
=======
            std::cout << left << setw(bottomLength) << first << "|";
        } else {
            std::cout << left << setw(bottomLength) << second << "|";
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
        }
    }
}

void Unownable::printLine(int lineNum){
    if (lineNum == 1){
        printLongName(1);
    }
    if (lineNum == 2){
        printLongName(2);
    }
    if (lineNum == 3){
        emptyRow();
    }
    if (lineNum == 4){
        printPlayer();
    }
    if (lineNum == 5){
        printBottom();
    }
}

void Unownable::printName(){
    cout << "";
}

void Unownable::triggerEvent(Player& player){
    string BName = getBName();
    if (BName == "SLC"){
        std::unique_ptr event = EventFactory::createEvent(true);
        event->execute(player);
    } 
    if (BName == "NEEDLES HALL"){
        std::unique_ptr event = EventFactory::createEvent(false);
        event->execute(player);
    } 
    if (BName == "COLLECT OSAP"){
        cout << "Collect $200!" << endl;
<<<<<<< HEAD
        player.getMoney(200);
=======
        player.gainMoney(200);
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
    } 
    if (BName == "DC Tims Line"){
        std::unique_ptr event = std::make_unique<OnDcTimsLine>();
        event->execute(player);
    } 
    if (BName == "GO TO TIMS"){
        cout << "Go to DC Tims Line!" << endl;
        player.sentTo(10);
    }
    if (BName == "Goose Nesting"){
        cout << "Oops! You are attacked by a flock of nesting geese!" << endl;
    }
    if (BName == "COOP FEE"){
        cout << "Pay $150 Coop fee!" << endl;
<<<<<<< HEAD
        player.getMoney(-150);
=======
        player.loseMoney(150);
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
    }
    if (BName == "TUITION"){
        cout << "Pay tuition: $300(1) or 1/10 total worth(2)?" << endl;
        char response;
        while (true){
            cin >> response;
            if (response == '1'){
<<<<<<< HEAD
                player.getMoney(-300);
=======
                player.loseMoney(300);
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
                break;
            }
            if (response == '2'){

            }
            // implement player.totalWorth();
        }
    }
}

// void Unownable::triggerEvent(Player& player){
//     if (this->getBName() == "Collect OSAP"){
//         std::unique_ptr event = std::make_unique<GoToCollectOSAP>();
//         event->execute(player);
//     }
    
// }
<<<<<<< HEAD

// size_t Building::getBPos() const {
//     return buildingPosition;
// } // Building::getBPos

// void Building::printBottom() {
//     for (int i = 0; i < bottomLength; i++){
//         cout << "_";
//     }
// } // Subject::getObserverNames

=======
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f

// size_t Building::getBPos() const {
//     return buildingPosition;
// } // Building::getBPos

// void Building::printBottom() {
//     for (int i = 0; i < bottomLength; i++){
//         cout << "_";
//     }
// } // Subject::getObserverNames

