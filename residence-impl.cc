module residence;
import ownable;
import <string>;

using namespace std;

Residence::Residence(string name, size_t blockPosition, Player *owner): Ownable{name, blockPosition, true, owner, 200} {}

/*
implement int calcResCost(int ownedNum);
*/