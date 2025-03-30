export module gym;
import ownable;
import Building;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;

using namespace std;

export class Gym: public Ownable {
    
    public:
<<<<<<< HEAD
=======
        //Gym(string name, size_t blockPosition, Player *owner);
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
        Gym(string name, size_t blockPosition);
        int usageFee(int diceSum, int numGymOwner);
        char getBType() const override;

        virtual void printName() override;
        virtual void printLine(int lineNum) override;

};
