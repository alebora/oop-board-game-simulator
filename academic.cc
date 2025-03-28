export module academic;
import ownable;
import Player;
import <string>;
import <memory>;
import <vector>;

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
        Academic(string name,  size_t blockPosition, Player *owner, size_t improvementLevel, string monopolyBlock, unique_ptr<vector<size_t>> tuition, int purchaseCost, int improvementCost, bool hasMonopoly);
        vector<Ownable*> BlockGroupMembers;

        int getLevel() const;
        void setImprovments(size_t n);
        size_t getTuition() const;
        void buyImprovement();
        void sellImprovement();
        int getImprovementCost() const;
        char getBType() const override;
        string getMonopolyBlock() const;
};
