export module gym;
import ownable;
import Building;
import <string>;

using namespace std;

export class Gym: public Ownable {
    
    public:
        Gym(string name, size_t blockPosition);
        int usageFee(int diceSum, int numGymOwner);
        char getBType() const override;

};
