module gym;
import ownable;
import Building;
import <string>;

using namespace std;

Gym::Gym(string name, size_t blockPosition): Ownable{name, blockPosition, true, 150} {}


//diceSum -> is the sum of the two dice rolled
//numGymOwner -> is the number of gym owners (maximum 2)
int Gym::usageFee(int diceSum, int numGymOwner) {
    //One can only claim rent if there exists and owner, so we do not consider the case of 0 gym owners here
    int fee = 0;
    if ( numGymOwner == 1) {
        fee = 4 * diceSum;
    } else if ( numGymOwner == 2 ) {
        fee = 10 * diceSum;
    }
    return fee;
}

//getBType -> returns the type of building from either {A, R, G}
char Gym::getBType() const { return 'G'; }
