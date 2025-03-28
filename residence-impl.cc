module residence;
import ownable;
import <string>;

using namespace std;

Residence::Residence(string name, size_t blockPosition, Player *owner): Ownable{name, blockPosition, true, owner, 200} {}


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

char Residence::getBType() const { return 'R'; }


