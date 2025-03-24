export module Building;
import <string>;

using namespace std;


export class Building {
    string BName;
    size_t blockPosition;

    public:
        Building(string BName, size_t blockPosition); //ctor
        string getBName() const;
        size_t getBPos() const;
        virtual ~Building() = 0; //so it is an ABC
};
