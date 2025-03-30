module gym;
import ownable;
import Building;
import <vector>;
import <algorithm>;
<<<<<<< HEAD
//import <iomanip>;
=======
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
import <string>;
import <iomanip>;


using namespace std;

const int bottomLength = 7;

<<<<<<< HEAD
=======
//Gym::Gym(string name, size_t blockPosition, Player *owner): Ownable{name, blockPosition, true, owner, 150} {}
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
Gym::Gym(string name, size_t blockPosition): Ownable{name, blockPosition, true, 150} {}


/* diceSum -> is the sum of the two dice rolled */
/* numGymOwner -> is the number of gym owners (maximum 2) */
int Gym::usageFee(int diceSum, int numGymOwner) {
    //One can only claim rent if there exists and owner, so we do not consider the case of 0 gym owners here
    int fee = 0;
    if ( numGymOwner == 1) {
        fee = 4 * diceSum;
    } else if ( numGymOwner == 2 ) {
        fee = 10 * diceSum;
    }
    return fee;
}
void Gym::printName() {
    string name = getBName();
    //cout << left << setw(bottomLength) << name << "|";
}

void Gym::printLine(int lineNum){
    if (lineNum == 1){
        printName();
    }
    if (lineNum == 2){
        emptyRow();
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

// size_t Building::getBPos() const {
//     return buildingPosition;
// } // Building::getBPos

// void Building::printBottom() {
//     for (int i = 0; i < bottomLength; i++){
//         cout << "_";
//     }
// } // Subject::getObserverNames




void Gym::printName() {
    string name = getBName();
    cout << left << setw(bottomLength) << name << "|";
}

void Gym::printLine(int lineNum){
    if (lineNum == 1){
        printName();
    }
    if (lineNum == 2){
        emptyRow();
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

// size_t Building::getBPos() const {
//     return buildingPosition;
// } // Building::getBPos

// void Building::printBottom() {
//     for (int i = 0; i < bottomLength; i++){
//         cout << "_";
//     }
// } // Subject::getObserverNames



/* getBType -> returns the type of building from either {A, R, G} */
char Gym::getBType() const { return 'G'; }
