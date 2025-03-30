module residence;
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

Residence::Residence(string name, size_t blockPosition): Ownable{name, blockPosition, true, 200} {}
=======
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f

//Residence::Residence(string name, size_t blockPosition, Player *owner): Ownable{name, blockPosition, true, owner, 200} {}

Residence::Residence(string name, size_t blockPosition): Ownable{name, blockPosition, true, 200} {}

int Residence::calcResCost(int ownedNum) {
    int feeOwed = 0;
    
    if (ownedNum == 1) {
        return 25;
    } else if (ownedNum == 2) {
        return 50;
    } else if (ownedNum == 3) {
        return 100;
    } else if (ownedNum == 4) {
        return 200;
    }

    return feeOwed;
}

void Residence::printName() {
    string name = getBName();
<<<<<<< HEAD
    //cout << left << setw(bottomLength) << name << "|";
=======
    cout << left << setw(bottomLength) << name << "|";
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
}

void Residence::printLine(int lineNum){
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

<<<<<<< HEAD

=======
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
char Residence::getBType() const { return 'R'; }


