export module Board;
import Player;
import Subject;
import Building;
import <iostream>;
import <string>;
import <vector>;

using namespace std;

export class Board: public Subject {
    int currPlayer;
    int remainingRimCups;
    public: 
        Board();
        vector<Player*> vec_players_selected;
        vector<Building*> vec_buildings;
        //Player* getPlayer(int n); //DEL LATER
        Player* getPlayer(string s); //DID NOT ADD TO UML BUT IS IMPLEMENTED 
        void printBoard();
        void stateOfBoardChange();
        int getNumPlayers();
        Building* getBuilding(string Bname);
        void addPlayer(Player *player);
        void addBuilding(string Bname, string owner, int improvements, int pos);
        int getCurrPlayer();
        void setCurrPlayer(int n);
        int getRemainingNumRimCups();
        void setRemainingNumRimCups(int n);
        int moneyOwed(Building *building, int diceSum);
        void trade(string name, string giveMoney, string receiveMoney);
        void academicImprovements(Building *property, string action);
        void mortgage(Building *property, Player *player);
        void bankrupt(Player *player, int Owed, Player *toWho);
        void auction(Building *building);
        void pay(Player *whoOwes, int howMuchOwed, Player *toWhoOwed);
};


