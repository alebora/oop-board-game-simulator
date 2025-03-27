export module academic;
import ownable;
import Player;
import <string>;
import <vector>;

using namespace std;

export class Academic: public Ownable {
    
    size_t improvementLevel;
    string monopolyBlock;
    vector<size_t> tuition;
    int improvementCost;
    bool hasMonopoly;

    public:
        Academic(string name,  size_t blockPosition, Player *owner, size_t improvementLevel, string monopolyBlock, vector<size_t> tuition, int improvementCost, bool hasMonopoly);
        vector<Ownable*> BlockGroupMembers;

        int getLevel() const;
        size_t getTuition() const;
        void buyImprovement();
        void sellImprovement();
        int getImprovementCost() const;
        string getMonopolyBlock() const;
};
