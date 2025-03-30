export module academic;
import ownable;
//import Player;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;
import <memory>;

using namespace std;

export class Academic: public Ownable {
    
    size_t improvementLevel;
    string monopolyBlock;
    //vector<size_t> tuition;
    unique_ptr<vector<size_t>> tuition;
    int purchaseCost;
    int improvementCost;
    bool hasMonopoly;

    public:
        //Academic(string name,  size_t blockPosition, Player *owner, size_t improvementLevel, string monopolyBlock, unique_ptr<vector<size_t>> tuition, int purchaseCost, int improvementCost, bool hasMonopoly);

        Academic(string name,  size_t blockPosition, size_t improvementLevel, string monopolyBlock, unique_ptr<vector<size_t>> tuition, int purchaseCost, int improvementCost, bool hasMonopoly);
        vector<Ownable*> BlockGroupMembers;

        int getLevel() const;
        void setImprovments(size_t n);
        size_t getTuition() const;
        void buyImprovement();
        void sellImprovement();
        int getImprovementCost() const;
        char getBType() const override;
        string getMonopolyBlock() const;
        
        virtual void printName() override;
        void printImpr();
        // void tuitionWithImpr(int p0, int p1, int p2, int p3, int p4, int p5);
        virtual void printLine(int lineNum) override;
        void setHasMonopoly(bool b);
        bool getHasMonopoly();
};
