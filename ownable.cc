//OWNABLE is a class that defines the general structure for a property that is ownable
//OWNABLE is an Abstract Base Class

export module ownable;
import Building;
import Player;
import <string>;

using namespace std;

export class Ownable: public Building {

    Player *owner;
    int propertyCost;
    bool isMortgaged;

    public:
         //pointer to the owner, with nullptr denoting no ownership status
        
        //add ctor
        Ownable( string name, size_t blockPosition, bool isOwnable, int propertyCost );
        virtual ~Ownable() = 0; //to make it an ABC

        int getCost() const;
        Player* getOwner() const;
        void setOwner( Player *player );
        void removeOwner();
        bool getMortgageState() const;
        void setMortgageState( bool mortgage );
        
        virtual char getBType() const = 0; //DOUBLE CHECK
        
};