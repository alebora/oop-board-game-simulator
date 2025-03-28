export module Unownable;
import Building;
import Player;
import <iostream>;
import <string>;
using namespace std;

export class Unownable : public Building {

  public:
    Unownable(string Bname, int pos);
    // void executeUnownable(int pos, Player &p);
    // void Tuition();
    // void CoopFee();
    // void DCTimsLine();
    // void GoToTims();
    //virtual void triggerEvent(Player& player) = 0;
    // void triggerEvent(Player& player) //I think should not be virtual
    //methods not in UML yet: 
    void printLongName(int lineNum); //NOT IN UML 
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

