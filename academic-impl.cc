module academic;
import ownable;
import <string>;

using namespace std;


Academic::Academic(string name, size_t blockPosition, Player *owner, size_t improvementLevel, string monopolyBlock, unique_ptr<vector<size_t>> tuition, int purchaseCost, int improvementCost, bool hasMonopoly):
Ownable{name, blockPosition, true, owner, improvementCost}, improvementLevel{improvementLevel}, monopolyBlock{monopolyBlock}, tuition{move(tuition)}, purchaseCost{purchaseCost}, improvementCost{improvementCost}, hasMonopoly{hasMonopoly} {}

int Academic::getLevel() const {
    return improvementLevel;
}

void Academic::setImprovments(size_t newLevel) {
    improvementLevel = newLevel;
}

size_t Academic::getTuition() const {
    return (*tuition)[improvementLevel];
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
/* getBType -> returns the type of building from either {A, R, G} */
char Academic::getBType() const { return 'A'; }

string  Academic::getMonopolyBlock() const {
    return monopolyBlock;
}
