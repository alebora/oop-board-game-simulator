module Building;
import <string>;
import <iostream>;

using namespace std;

Building::Building(string name, size_t blockPosition, bool isOwnable): name{name}, blockPosition{blockPosition}, isOwnable{isOwnable} {}

string Building::getBName() const {
    return name;
}

size_t Building::getBPos() const {
    return blockPosition;
}

bool Building::getOwnableStatus() const {
    return isOwnable;
}
void Building::setOwnable(bool b){
    isOwnable = b;
}

void Building::setImprovments(size_t numImprovs){
    cout << "TRYING TO SET IMPROVEMENT NUM IN BUILDING CLASS" << endl;
}

int Building::getLevel(){
    return -1;
}

//Building::~Building() {}

