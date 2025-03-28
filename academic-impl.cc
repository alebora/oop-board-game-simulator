module academic;
import ownable;
import <string>;

using namespace std;


Academic::Academic(string name, size_t blockPosition, Player *owner, size_t improvementLevel, string monopolyBlock, vector<size_t> tuition, int improvementCost, bool hasMonopoly):
Ownable{name, blockPosition, true, owner, improvementCost}, improvementLevel{improvementLevel}, monopolyBlock{monopolyBlock}, tuition{tuition}, improvementCost{improvementCost}, hasMonopoly{hasMonopoly} {}

int Academic::getLevel() const {
    return improvementLevel;
}

size_t Academic::getTuition() const {
    return tuition[improvementLevel];
}

int Academic::getImprovementCost() const {
    return improvementCost;
}

void Academic::buyImprovement() {
    ++improvementLevel;
}

void Academic::sellImprovement() {
    --improvementLevel;
}

string Academic::getMonopolyBlock() const {
    return monopolyBlock;
}

