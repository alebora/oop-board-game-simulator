export module Board;
import Player;
import Subject;
import Building;
import <iostream>;
import <string>;
import <memory>;
import <vector>;

using namespace std;

export class Board: public Subject {
    int currPlayer;
    int remainingRimCups;
    public: 
        Board();
        vector<unique_ptr<Player>> vec_players_selected;
        vector<unique_ptr<Building>> vec_buildings;
        //Player* getPlayer(int n); //DEL LATER
        unique_ptr<Player> getPlayer(string s); //DID NOT ADD TO UML BUT IS IMPLEMENTED 
        void printBoard();
        void stateOfBoardChange();
        int getNumPlayers();
        unique_ptr<Building> getBuilding(string Bname);
        void addPlayer(unique_ptr<Player> player);
        void addBuildingINIT(string Bname, string block, Player *owner, int improvements, int pos, int pur, int imp, size_t z, size_t o, size_t t, size_t thr, size_t f, size_t fiv);
        int getCurrPlayer();
        void setCurrPlayer(int n);
        int getRemainingNumRimCups();
        void setRemainingNumRimCups(int n);
        int moneyOwed(Building *building, int diceSum);
        void trade(string name, string giveMoney, string receiveMoney, Player *player);
        void academicImprovements(Building *property, string action, Player *player);
        void mortgage(Building *property, Player *player);
        //void bankrupt(Player *player, int Owed, Player *toWho);
        bool bankrupt(Player *player, int Owed, Player *toWho);
        void auction(Building *building);
        void pay(Player *whoOwes, int howMuchOwed, Player *toWhoOwed);
        Player* getOwner(Building *b);
        void setOwner(Building *b, Player *p); 
        void removeOwner(Building *b);
};


