export module residence;
import ownable;
import Player;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;

using namespace std;

export class Residence: public Ownable {
   //int rentCost; //remove??????

    public:
        Residence(string name, size_t blockPosition, Player *owner);
        int calcResCost(int ownedNum);
        char getBType() const override;
        
        virtual void printName() override;
        virtual void printLine(int lineNum) override;
};

