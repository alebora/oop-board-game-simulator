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

        /* functions to implement
        + getLevel(): Integer
        + getTuition(): Size_t
        + buyImprovement(): void
        + getImprovementCost(): Integer + sellImprovement(): void
        */
};