//OWNABLE is a class that defines the general structure for a property that is ownable
//OWNABLE is an Abstract Base Class

export module ownable;
import Building;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <vector>;
import <string>;


using namespace std;

export class Ownable: public Building {

    //Player *owner;
    int propertyCost;
    bool isMortgaged;

    public:        
        //Ownable( string name, size_t blockPosition, bool isOwnable, Player *owner, int propertyCost );
        Ownable( string name, size_t blockPosition, bool isOwnable, int propertyCost );
        virtual ~Ownable() = 0; //to make it an ABC

        int getCost() const; //SHOULD BE PURE VIRTUAL?
        //Player* getOwner() const;
        //void setOwner( Player *player );
       //void removeOwner();
        bool getMortgageState() const;
        void setMortgageState( bool mortgage );
        
        virtual char getBType() const = 0; //DOUBLE CHECK
        virtual void printName() override;
        virtual void printLine(int lineNum) override;
        
};
