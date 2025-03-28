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
        void setOwnable(bool b);
        virtual void setImprovments(size_t numImprovs);
        virtual int getLevel();
        //virtual void getOwner(size_t numImprovs);
        //virtual ~Building() = 0; //so it is an ABC
};
