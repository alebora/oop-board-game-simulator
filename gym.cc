export module gym;
import ownable;
import Building;
import Player;
import <string>;

using namespace std;

export class Gym: public Ownable {
    
    public:
        Gym(string name, size_t blockPosition, Player *owner);
        int usageFee(int diceSum, int numGymOwner);
        char getBType() const override;

};
