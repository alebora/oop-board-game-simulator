//OWNABLE is a class that defines the general structure for a property that is ownable
//OWNABLE is an Abstract Base Class

export module ownable;
import Building;
import Player;
import <string>;

using namespace std;

export class Ownable: public Building {

    int propertyCost;
    bool isMortgaged;

    public:
        Player *owner; //pointer to the owner, with nullptr denoting no ownership status
        
        //add ctor

        string getPropName();
        int getCost() const;
        Player getOwner() const;
        bool getMortgageState() const;
        char getBType() const;
};