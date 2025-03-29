import <string>;
export module building;
using namespace std;


export class Building {
    string BName;
    size_t blockPosition;

    public:
        Building(string BName, size_t blockPosition); //ctor
        string getBName();
        size_t getBPos();
        virtual ~Building() = 0; //so it is an ABC
};