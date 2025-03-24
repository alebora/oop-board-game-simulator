module Building;
import <string>;

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

Building::~Building() {}

