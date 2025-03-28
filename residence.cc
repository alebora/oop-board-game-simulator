export module residence;
import ownable;
import Player;
import <string>;

using namespace std;

export class Residence: public Ownable {
   //int rentCost; //remove??????

    public:
        Residence(string name, size_t blockPosition, Player *owner);
        int calcResCost(int ownedNum);
        char getBType() const override;
};

