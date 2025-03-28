export module Player;
//import ownable;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;
import PRNG;
import Building;
using namespace std;


export class Player{
    size_t position;
    string name;
    int money;
    char acronym;
    //vector<Ownable*> properties;
    int inJail; //jail (if not 0 means in jail, the number is also the number of turns they were in jail, so if 4 then NEEDS to pay 50 or use card)
    int jailTurns;
    bool isBankrupt;
    int numRes;
    int numGym;
    int diceSum;
    int rimCups;
    public: 
        vector<string> monopolies;
        Player(string name, char acronym, int cups, int money, int pos, int jail, int turns);
        string getName();
        void setName(string name);
        size_t getPos();
        void setPos(int pos);
        char getAcronym();
        void setAcronym(char c);
        int getMoney();
        void setMoney(int n);
        int getDiceSum();
        void setDiceSum(int n);
        int getNumGymOwned();
        void setNumGymOwned(int n);
        int getNumResOwned();
        void setNumResOwned(int n);
        int getJailStatusNum();
        void setJailStatusNum(int n);
        int getJailTurns();
        void setJailTurns(int n);
        int getRimCups();
        void setRimCups(int n);
        bool getBankruptStatus();
        void setBankruptStatus(bool b);
        bool payBank();
        bool payPlayer();
        int total_worth();
        bool findMonopolies(string monopolyName);
        // void addOwnable(Ownable* o);
        // void removeOwnable(Ownable* o);
        // Ownable *getOwnable(int pos);
        // Ownable *getOwnable(string name);
        void printPlayer();
        void move(size_t step, bool forward);
        void getMoney(int amount);
        void loseMoney(int amount);
        void loseCup();
        void sentTo(size_t pos);
        int ifInJail();
        int timesInJail();
        int cups();
        size_t rollDice();
        size_t rollDouble();
        void setFree();
        void incJailTurn();
        void winCup();
        void broadcastPos(Building* bld);
        
        //void printAssests();
};



