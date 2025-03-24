export module residence;
import ownable;
import Player;
import <string>;

using namespace std;

export class Residence: public Ownable {
    int rentCost;

    public:
        Residence(string name, size_t blockPosition, Player *owner, int rentCost);
        int calcResCost(int ownedNum);
};

