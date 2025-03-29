export module residence;
import ownable;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;

using namespace std;

export class Residence: public Ownable {

    public:
        Residence(string name, size_t blockPosition);
        int calcResCost(int ownedNum);
        char getBType() const override;
        virtual void printName() override;
        virtual void printLine(int lineNum) override;
};

