/*Implementation File for ownable properties*/
module ownable;
import Building;
import <vector>;
import <algorithm>;
import <string>;
import <iostream>;

using namespace std;

const int bottomLength = 7;

//Ownable::Ownable(string name, size_t blockPosition, bool isOwnable, Player *owner, int propertyCost): Building{name, blockPosition, isOwnable}, owner{owner}, propertyCost{propertyCost}, isMortgaged{false} {}

Ownable::Ownable(string name, size_t blockPosition, bool isOwnable, int propertyCost): Building{name, blockPosition, isOwnable}, propertyCost{propertyCost}, isMortgaged{false} {}


/*
Player* Ownable::getOwner() const {
    return owner;
}

void Ownable::setOwner( Player *player ) {
    owner = player;
}

void Ownable::removeOwner() {
    owner = nullptr;
}
*/


int Ownable::getCost() const {
    return propertyCost;
} //should this be pure virtual or something bc building cost depends on which building it is

bool Ownable::getMortgageState() const {
    return isMortgaged;
}
void Ownable::setMortgageState(bool mortgage) {
    isMortgaged = mortgage;
}

/*
char Ownable::getBType() const {

} //should this be pure virtual or something bc building cost depends on which building it is
*/

void Ownable::printName(){
    string name = getBName();
    cout << name;
}

void Ownable::printLine(int lineNum){
}

Ownable::~Ownable() {}

