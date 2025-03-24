module residence;
import ownable;
import <string>;

using namespace std;

Residence::Residence(string name, size_t blockPosition, Player *owner, int rentCost): Ownable{name, blockPosition, true, owner, 200}, rentCost{rentCost} {}

/*
implement int calcResCost(int ownedNum);
*/