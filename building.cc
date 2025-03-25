export module Building;
import <string>;

using namespace std;


export class Building {
    string name;
    size_t blockPosition;
    bool isOwnable;

    public:
        Building(string name, size_t blockPosition, bool isOwnable); //ctor
        string getBName() const; //should this be pure virtual?
        size_t getBPos() const; //should this be pure virtual?
        bool getOwnableStatus() const;
        virtual ~Building() = 0; //so it is an ABC
};
