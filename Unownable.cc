export module Unownable;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <memory>;
import Building;
import Player;
import Event;
import OnDcTimsLine;
import EventFactory;

export class Unownable : public Building {

  public:
    Unownable(std::string BName, size_t pos);
    void printLongName(int lineNum);
    void triggerEvent(Player& player);
    virtual void printName() override;
    virtual void printLine(int lineNum) override;
    // Unownable(string Bname, int pos);
    // void executeUnownable(int pos, Player &p);
    // void Tuition();
    // void CoopFee();
    // void DCTimsLine();
    // void GoToTims();
    //virtual void triggerEvent(Player& player) = 0;
    // void triggerEvent(Player& player) //I think should not be virtual
    //methods not in UML yet: 
    // void printLongName(int lineNum); //NOT IN UML 
    // void setLiving();                   // Marks cell as alive. Called by Grid::turnOn.
    // void reset();                       // Resets neighbour count to 0.

    // Grid calls this to start the process whereby a cell notifies its neighbours if it
    // is alive.
    // void broadcastIfAlive();
    
    // // My neighbours will call this to let me know if they're alive. 
    // void notify( Subject & whoNotified ) override;
                                                
    // // Reassess my living-or-dead status, based on information from neighbours.
    // void recalculate(); 

    // // Observer calls this to get information about cell.
    // virtual Info getInfo() const override;
};

