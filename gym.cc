export module gym;
import ownable;
import Building;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;

using namespace std;

export class Gym: public Ownable {
    
    public:
        //Gym(string name, size_t blockPosition, Player *owner);
        Gym(string name, size_t blockPosition);
        int usageFee(int diceSum, int numGymOwner);
        char getBType() const override;

        virtual void printName() override;
        virtual void printLine(int lineNum) override;

};
