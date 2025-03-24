/*Implementation File for ownable properties*/
module ownable;
import Player;
import Building;

using namespace std;

Ownable::Ownable(string name, size_t blockPosition, bool isOwnable, Player *owner, int propertyCost): Building{name, blockPosition, isOwnable}, owner{owner}, propertyCost{propertyCost}, isMortgaged{false} {}

Player* Ownable::getOwner() const {
    return owner;
}

void Ownable::setOwner( Player *player ) {
    owner = player;
}

void Ownable::removeOwner() {
    owner = nullptr;
}

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

Ownable::~Ownable() {}

