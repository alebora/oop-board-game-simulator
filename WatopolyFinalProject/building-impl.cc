module building;

using namespace std;

Building::Building(string BName, size_t blockPosition): BName{BName}, blockPosition{blockPosition} {}

string Building::getBName() const {
    return BName;
}

size_t Building::getBPos() const {
    return blockPosition;
}