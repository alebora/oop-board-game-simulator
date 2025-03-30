//OWNABLE is a class that defines the general structure for a property that is ownable
//OWNABLE is an Abstract Base Class

export module ownable;
import Building;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
<<<<<<< HEAD
import <string>;
=======
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
import <vector>;
import <string>;


using namespace std;

export class Ownable: public Building {

<<<<<<< HEAD
=======
    //Player *owner;
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
    int propertyCost;
    bool isMortgaged;

    public:        
<<<<<<< HEAD
=======
        //Ownable( string name, size_t blockPosition, bool isOwnable, Player *owner, int propertyCost );
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
        Ownable( string name, size_t blockPosition, bool isOwnable, int propertyCost );
        virtual ~Ownable() = 0; //to make it an ABC

        int getCost() const; //SHOULD BE PURE VIRTUAL?
<<<<<<< HEAD
=======
        //Player* getOwner() const;
        //void setOwner( Player *player );
       //void removeOwner();
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
        bool getMortgageState() const;
        void setMortgageState( bool mortgage );
        
        virtual char getBType() const = 0; //DOUBLE CHECK
        virtual void printName() override;
        virtual void printLine(int lineNum) override;
        
};
