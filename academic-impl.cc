module academic;
import ownable;
import <vector>;
import <algorithm>;
import <string>;
<<<<<<< HEAD
//import <iomanip>;
=======
import <iomanip>;
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f

using namespace std;

const int bottomLength = 7;

<<<<<<< HEAD
=======
//Academic::Academic(string name, size_t blockPosition, Player *owner, size_t improvementLevel, string monopolyBlock, unique_ptr<vector<size_t>> tuition, int purchaseCost, int improvementCost, bool hasMonopoly):
//Ownable{name, blockPosition, true, owner, improvementCost}, improvementLevel{improvementLevel}, monopolyBlock{monopolyBlock}, tuition{move(tuition)}, purchaseCost{purchaseCost}, improvementCost{improvementCost}, hasMonopoly{hasMonopoly} {}

>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
Academic::Academic(string name, size_t blockPosition, size_t improvementLevel, string monopolyBlock, unique_ptr<vector<size_t>> tuition, int purchaseCost, int improvementCost, bool hasMonopoly):
Ownable{name, blockPosition, true, improvementCost}, improvementLevel{improvementLevel}, monopolyBlock{monopolyBlock}, tuition{move(tuition)}, purchaseCost{purchaseCost}, improvementCost{improvementCost}, hasMonopoly{hasMonopoly} {}

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

string Academic::getMonopolyBlock() const {
    return monopolyBlock;
}
<<<<<<< HEAD
void Academic::printName() {
    string name = getBName();
    //cout << left << setw(bottomLength) << name << "|";
=======

void Academic::printName() {
    string name = getBName();
    cout << left << setw(bottomLength) << name << "|";
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
}

void Academic::printImpr() {
    for (size_t i = 0; i < improvementLevel; i++){
        cout << "I";
    }
    for (size_t i = 0; i < (bottomLength - improvementLevel); i++){
        cout << "-";
    }
    cout << "|";
}

void Academic::printLine(int lineNum){
    if (lineNum == 1){
        emptyRow();
    }
    if (lineNum == 2){
        printImpr();
    }
    if (lineNum == 3){
        printName();
    }
    if (lineNum == 4){
        printPlayer();
    }
    if (lineNum == 5){
        printBottom();
    }
}

<<<<<<< HEAD
=======
void Academic::setHasMonopoly(bool b){
    hasMonopoly = b;
}

bool Academic::getHasMonopoly(){
    return hasMonopoly;
}

>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
// void Academic::tuitionWithImpr(int p0, int p1, int p2, int p3, int p4, int p5){
//     // tuitionBePaid = {};
//     tuitionBePaid.clear();  // Clear the vector before pushing new values
//     tuitionBePaid = {p0, p1, p2, p3, p4, p5};
// }
<<<<<<< HEAD
=======



>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
