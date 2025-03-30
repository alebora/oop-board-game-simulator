export module Building;
import <vector>;
import <string>;
<<<<<<< HEAD
import <cstddef>;
=======
import <cstddef>; 
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f

using namespace std;


export class Building {
    string name;
    size_t blockPosition;
    std::vector<char> playerOn;
    bool isOwnable;

    public:
        Building(string name, size_t blockPosition, bool isOwnable); //ctor
        string getBName() const; //should this be pure virtual?
        size_t getBPos() const; //should this be pure virtual?
        bool getOwnableStatus() const;
        void setOwnable(bool b);
        //virtual void setImprovments(size_t numImprovs);
       //virtual int getLevel();
        //virtual ~Building() = 0; //so it is an ABC
<<<<<<< HEAD
        virtual void printBottom();
        virtual void printName() = 0;
        // virtual void printImpr() = 0;
=======
        
        virtual void printBottom();
        virtual void printName() = 0;
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
        virtual void printLine(int lineNum) = 0;
        void emptyRow();
        void printPlayer();
        void attachPlayer(char token);
        void clearPlayer();
        bool ifOwnable();
};
