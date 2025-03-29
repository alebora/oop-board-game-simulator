module Board;
import Player;
import academic;
import Building;
import ownable;
import gym;
import Unownable;
import residence;
import <iostream>;
import <string>;
import <vector>;
import <memory>;

using namespace std;

vector<vector<int>> tuitionVec; 
vector<int> improvementCostVec;
vector<string> monopolyBlockVec;

Board::Board(): currPlayer(0), remainingRimCups(2) {
    //vec_buildings initilized harcoded;
}

Player* Board::getPlayer(string s){
    for (int i = 0; i < vec_players_selected.size(); ++i){
        if (vec_players_selected[i]->getName() == s){
            return vec_players_selected[i].get();
        }
    }
    return nullptr; 
}

// Board::~Board(){
//     //clear all heap allocated ctors in addBuilding
// }

void Board::stateOfBoardChange(){
    for (size_t i = 0; i < 40; i++){
        vec_buildings[i].get()->clearPlayer();
    }
    for (size_t i = 0; i < vec_players_selected.size(); i++){
        vec_players_selected[i].get()->broadcastPos(vec_buildings[vec_players_selected[i].get()->getPos()].get());
    }
}

void Board::printBoard(){
    for (int i = 0; i < 89; i++){
        cout << "_";
    }
    cout << endl;
    for (int k = 1; k <= 5; k++){
        cout << "|";
        for (size_t i = 20; i <= 30; i++){
            vec_buildings[i]->printLine(k);
        }
        cout << endl;
    }
    for (int i = 19; i >= 17; i--){
        for (int k = 1; k <= 5; k++){
            cout << "|";
            vec_buildings[i]->printLine(k);
            for (int i = 0; i <= 70; i++){
                cout << " ";
            }
            cout << "|";
            vec_buildings[50 - i]->printLine(k);
            cout << endl;
        }
    }
    for (int k = 1; k <= 3; k++){
        cout << "|";
        vec_buildings[16]->printLine(k);
        for (int i = 0; i <= 70; i++){
            cout << " ";
        }
        cout << "|";
        vec_buildings[34]->printLine(k);
        cout << endl;
    }

    cout << "|";
    vec_buildings[16]->printLine(4);
    for (int i = 0; i <= 12; i++){
        cout << " ";
    }
    for (int i = 0; i <= 44; i++){
        cout << "_";
    }
    for (int i = 0; i <= 12; i++){
        cout << " ";
    }
    cout << "|";
    vec_buildings[34]->printLine(4);
    cout <<  endl;

    cout << "|";
    vec_buildings[16]->printLine(5);
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "|";
    for (int i = 0; i <= 44; i++){
        cout << " ";
    }
    cout << "|";
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "|";
    vec_buildings[34]->printLine(5);
    cout <<  endl;

    cout << "|";
    vec_buildings[15]->printLine(1);
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "| ";
    cout << "#   #  ##  #####  ###  ###   ###  #   #   #";
    cout << " |";
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "|";
    vec_buildings[35]->printLine(1);
    cout <<  endl;

    cout << "|";
    vec_buildings[15]->printLine(2);
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "| ";
    cout << "#   # #  #   #   #   # #  # #   # #   #   #";
    cout << " |";
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "|";
    vec_buildings[35]->printLine(2);
    cout <<  endl;

    cout << "|";
    vec_buildings[15]->printLine(3);
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "| ";
    cout << "# # # ####   #   #   # ###  #   # #    # # ";
    cout << " |";
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "|";
    vec_buildings[35]->printLine(3);
    cout <<  endl;

    cout << "|";
    vec_buildings[15]->printLine(4);
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "| ";
    cout << "# # # #  #   #   #   # #    #   # #     #  ";
    cout << " |";
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "|";
    vec_buildings[35]->printLine(4);
    cout <<  endl;

    cout << "|";
    vec_buildings[15]->printLine(5);
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "| ";
    cout << "##### #  #   #    ###  #     ###  ## #  #  ";
    cout << " |";
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "|";
    vec_buildings[35]->printLine(5);
    cout <<  endl;

    cout << "|";
    vec_buildings[14]->printLine(1);
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "|";
    for (int i = 0; i <= 44; i++){
        cout << "_";
    }
    cout << "|";
    for (int i = 0; i <= 11; i++){
        cout << " ";
    }
    cout << "|";
    vec_buildings[36]->printLine(1);
    cout <<  endl;

    for (int k = 2; k <= 5; k++){
        cout << "|";
        vec_buildings[14]->printLine(k);
        for (int i = 0; i <= 70; i++){
            cout << " ";
        }
        cout << "|";
        vec_buildings[36]->printLine(k);
        cout << endl;
    }
    for (int i = 13; i >= 12; i--){
        for (int k = 1; k <= 5; k++){
            cout << "|";
            vec_buildings[i]->printLine(k);
            for (int i = 0; i <= 70; i++){
                cout << " ";
            }
            cout << "|";
            vec_buildings[50 - i]->printLine(k);
            cout << endl;
        }
    }
    for (int k = 1; k <= 4; k++){
        cout << "|";
        vec_buildings[11]->printLine(k);
        for (int i = 0; i <= 70; i++){
            cout << " ";
        }
        cout << "|";
        vec_buildings[39]->printLine(k);
        cout << endl;
    }
    cout << "|";
    vec_buildings[11]->printLine(5);
    for (int i = 0; i <= 70; i++){
        cout << "_";
    }
    cout << "|";
    vec_buildings[39]->printLine(5);
    cout <<  endl;
    for (int k = 1; k <= 5; k++){
        cout << "|";
        for (size_t i = 11; i >= 1; i--){
            vec_buildings[i - 1]->printLine(k);
        }
        cout << endl;
    }
}

// void Board::stateOfBoardChange(){
//     notifyObservers();
// }

int Board::getNumPlayers(){
    return vec_players_selected.size();
}

void Board::addPlayer(unique_ptr<Player> player){
    vec_players_selected.emplace_back(move(player));
}

int Board::getCurrPlayer(){
    return currPlayer;
}

void Board::setCurrPlayer(int n){
    currPlayer = n;
}

int Board::getRemainingNumRimCups(){
    return remainingRimCups;
}

void Board::setRemainingNumRimCups(int n){
    remainingRimCups = n; 
}


int Board::moneyOwed(Building *building, int diceSum){
    // TO IMPLEMENT
    Ownable* ownableBuilding = static_cast<Ownable*>(building); //.get()?

    char bType = ownableBuilding->getBType();
    int owed = 0;
    if (bType == 'A') {

        Academic *academic = static_cast<Academic*>(ownableBuilding);
        //check the number of academic properties an owner owns?
        //tuition is the rent
        //Tuition is doubled for each building that has no improvements when the monopoly is owned by a single player.
        //check if the current building is a part of a monopoly and if there are no improvements
        //otherwise, just regular tuition cost
        
        //1. can check if the current building (getMonopolyBlock) is a part of the monopoly vector of player
        //2. if is part of a monopoly, check if there are improvements (getImprovementLevel) if 0 => double, else return Tuition
        
        //1. get owner
        //2. from academic building -> get getMonopolyBlock
        //2. from player, findMonopolies() => T/F

        //Player *owner = academic->getOwner();
        Player *owner = getOwner(academic);
        if (owner == nullptr) {
            std::cerr << "Error. There is no owner for this building." <<endl;
            return 0;
        }

        string monBlock = academic->getMonopolyBlock();
        bool isInMonopoly = owner->findMonopolies(monBlock);

        if (isInMonopoly) {
            int impLevel = academic->getLevel();
            if(impLevel == 0) {
                return 2*academic->getTuition();
            }
        }

        return academic->getTuition();

    } else if (bType = 'R') {
        Residence *residence = static_cast<Residence*>(ownableBuilding);
        //Player *owner = residence->getOwner();
        Player *owner = getOwner(residence);
        if (owner == nullptr) {
            std::cerr << "Error. There is no owner for this building." <<endl;
            return 0;
        }

        int numOwner = owner->getNumResOwned();
        return residence->calcResCost(numOwner);

    } else if (bType == 'G') {

        Gym *gym = static_cast<Gym*>(ownableBuilding);
        //Player* owner = gym->getOwner();
        Player *owner = getOwner(gym);

        if (owner == nullptr) {
            std::cerr << "Error. There is no owner for this building." <<endl;
            return 0;
        }
        
        int gymNum = owner->getNumGymOwned();
        return gym->usageFee(diceSum, gymNum);
    }

    return owed;

}

void Board::academicImprovements(Building *property, string action, Player *player){ //NEED TO CHECK IF USER GETS BANKRUPT
    // TO IMPLEMENT

    //verifying ownership
   try {
        string playerName = player->getName();
        Ownable *o = static_cast<Ownable*>(property);
        //o->getOwner()
        if (getOwner(o) == nullptr) {
            std::cerr << "Unsuccesful attempt at improvement. The building has no owner. " << endl;
            return;
        }

        //string buildingOwner = o->getOwner()->getName();
        string buildingOwner = getOwner(o)->getName();

        if (buildingOwner != playerName) { //verifying ownership
            std::cerr << "Unsuccesful attempt at improvement. " << playerName << "does not own " << property->getBName() <<endl;
            return;
        }


        if (action == "buy") {
            Academic *a = static_cast<Academic*>(property);

            //1. check that player owns that building
            //2. check if they have enough money -> checking bankruptcy


            //take money out of their money
            int impCost = a->getImprovementCost();

            if (player->getMoney() < impCost) {
                std::cerr << "Unable to purchase improvement, you do not have enough funds. Consider selling or mortgaging properties if possible." << endl;
                return;
            }
            if (player->getMoney() == impCost) {
                cout << "If you make this improvement purchase, you will have a cash balance of $0. Would you like to proceed?" << endl;
                char response;
                while (true) {
                    cout << "Please enter Y for yes and N for no:" << endl;
                    cin >> response;
                    if (response == 'Y') {
                        break;
                    } 
                    if (response == 'N') {
                        cout << "You have decided to terminate this purchase. Good choice." << endl;
                        return;
                    }
                }
            }

            impCost = -impCost;
            player->setMoney(impCost);
            a->buyImprovement();
        }
        if (action == "sell") {
            //add money into their money
            //check which monopoly block they are a part of and check if they have a monopoly
            Academic *a = static_cast<Academic*>(property);
            int impCost = a->getImprovementCost() / 2;
            player->setMoney(impCost);
            a->sellImprovement();
        }
   } catch (...) {
        std::cerr << "Invalid action. Denied." <<endl;
        return;
   }
}

void Board::trade(string name, string giveMoney, string receiveMoney, Player *player){
       try {
        //Player *player is the person trade is requested from
        Player *reqFrom = getPlayer(name);

        //if user is receiving/giving building else money and stoi()
        bool giveBuilding = false;
        bool receiveBuilding = false;

        bool isGiveMortgaged = false;
        bool isReceiveMortgaged = false;

        int giveMortgage = 0; //if mortgaged, player receive building + pay 10%
        int receiveMortgage = 0;  //if mortgaged, player receive building + pay 10%

        //if there is time, do a check for ownership for building in the below loop?

        //doing check for mortgage in here and calcalate the 10%
        vector<string> trading = {giveMoney, receiveMoney};
        Ownable *give;
        Ownable *receive;
        for (int i = 0; i < trading.size(); ++ i) {
            for (int j = 0; j < vec_buildings.size(); ++j) {
                if (vec_buildings[j]->getBName() == trading[i]){
                    if (trading[i] == giveMoney) {
                        giveBuilding = true;
                        //should this be academic or OWNABLE??? is the below correct
                        //give = static_cast<Ownable*>(vec_buildings[j].get());
                        give = static_cast<Ownable*>(vec_buildings[j].get());
                        if(give->getBType() == 'A') {
                            //CAST TO ACADEMIC?????
                            if(static_cast<Academic*>(give)->getLevel() != 0) {
                                cout << "Trade rejected, you cannot trade a property with improvements." << endl;      
                            }
                            return;
                        }
                        if (give->getMortgageState()) { //get getMortgageState
                            isGiveMortgaged = true;
                            giveMortgage = give->getCost() * 0.1;
                        }
                    } else {
                        receiveBuilding = true;
                        receive = static_cast<Ownable*>(vec_buildings[j].get());
                        if(receive->getBType() == 'A') {
                            if(static_cast<Academic*>(receive)->getLevel() != 0) {
                                cout << "Trade rejected. You cannot trade a property with improvements." << endl;      
                            }
                            return;
                        }
                        if (receive->getMortgageState()) { //get getMortgageState
                            isGiveMortgaged = true;
                            giveMortgage = receive->getCost() * 0.1;
                        }
                    }
                }
            }
        }

        //Accept/Reject Stage
        cout << name << ", do you accept or reject this offer?" << endl;
        string choice;
        while(true) {
            cout << "Please enter accept or reject." << endl;      
            cin >> choice;
            if(choice == "accept" || choice == "reject") {
                break;
            }
        }

        if (choice == "reject") {
            cout << name << " has rejected the offer.";
            return;
        }

        //HERE:
        //1. check bool of giveBuilding and receiveBuilding
        //2. check BType
        //3. cast to the correct type
        //4. redefine give and receive
        //5. if the building is mortgaged, need to consider differently!! march 28th
        

        //Money Building
        if (!giveBuilding && receiveBuilding) {
            //how much the player is giving, convert to integer
            int giveM = stoi(giveMoney);
            int bank = player->getMoney(); 

        
            //check if the building is mortgaged

            if ((giveM + receiveMortgage) > bank) {
                cout << "Trade rejected. You do not have enough money to make this trade" <<endl;
                return;
            }
            //Player *tmpPlayer = receive->getOwner();
            Player *tmpPlayer = getOwner(receive);
            if(tmpPlayer == nullptr) {
                cout << "Trade rejected. " << name << "does not own " << receiveMoney <<endl;
                return;
            }

            string receiveName = tmpPlayer->getName();

            if ( receiveName != name) { //verifying ownership
                cout << "Trade rejected. " << name << "does not own " << receiveMoney <<endl;
                return;
            }

            //giveMortgage = -giveMortgage;
            receiveMortgage = -receiveMortgage;

            //receive->removeOwner();
            removeOwner(receive);
            //receive->setOwner(player);
            setOwner(receive, player);
            reqFrom->setMoney(giveM);

            giveM = -giveM;
            player->setMoney(giveM);
            player->setMoney(receiveMortgage);

            cout << "Trade succesful! " <<endl;
            return;
        }

        //Building Building
        if (giveBuilding && receiveBuilding) {
            // Player *tmpPlayer1 = receive->getOwner();
            Player *tmpPlayer1 = getOwner(receive);

            if(tmpPlayer1) {
                cout << "Trade rejected. " << name << "does not own " << receiveMoney <<endl;
                return;
            }

            string receiverBuilding = tmpPlayer1->getName();

            if ( receiverBuilding != name ) { //verifying ownership
                cout << "Trade rejected. " << name << "does not own " << receiveMoney <<endl;
                return;
            }

            string giveName = player->getName();

            // Player *tmpPlayer = give->getOwner();
            Player *tmpPlayer = getOwner(give);
            //if no owner
            if(tmpPlayer == nullptr) {
                cout << "Trade rejected. " << giveName << "does not own " << receiveMoney <<endl;
                return;
            }

            string buildingOwner = tmpPlayer->getName();


            if ( buildingOwner != giveName) { //verifying ownership
                cout << "Trade rejected. " << giveName << "does not own " << giveMoney <<endl;
                return;
            }

            //check mortgaging 
            int bankP = player->getMoney(); 
            int bankR = reqFrom->getMoney(); 

            if ( receiveMortgage > bankP ) {
                cout << "Trade rejected. You do not have enough money to make this trade" <<endl;
                return;
            }

            if ( giveMortgage > bankR ) {
                cout << "Trade rejected. You do not have enough money to make this trade" <<endl;
                return;
            }

            giveMortgage = -giveMortgage;
            receiveMortgage = -receiveMortgage;

            reqFrom->setMoney(giveMortgage);
            player->setMoney(receiveMortgage);

            //receive->removeOwner();
            removeOwner(receive);
            //receive->setOwner(player);
            setOwner(receive, player);

            //give->removeOwner();
            removeOwner(give);
            //give->setOwner(reqFrom);
            setOwner(give, reqFrom);

            cout << "Trade succesful! " <<endl;
            return;
        }

        //Building Money 
        if (giveBuilding && !receiveBuilding) {
            int receiveM = stoi(receiveMoney);
            int bank = reqFrom->getMoney(); 

            if ((receiveM + giveMortgage) > bank) {
                cout << "Trade rejected. " << name << " does not have enough money to make this trade" <<endl;
                return;
            }

            string giveName = player->getName();
            // Player *tmpPlayer = give->getOwner();
            Player *tmpPlayer = getOwner(give);

            if(tmpPlayer == nullptr) {
                cout << "Trade rejected. " << giveName << "does not own " << receiveMoney <<endl;
                return;
            }

            string buildingOwner = tmpPlayer->getName();

            if (buildingOwner != giveName) { //verifying ownership
                cout << "Trade rejected. " << giveName << "does not own " << giveMoney <<endl;
                return;
            }

            //give->removeOwner();
            removeOwner(give);
            //give->setOwner(reqFrom);
            setOwner(give, reqFrom);

            player->setMoney(receiveM);

            receiveM = -receiveM;
            giveMortgage = -giveMortgage;
            reqFrom->setMoney(receiveM);
            reqFrom->setMoney(giveMortgage);
            cout << "Trade succesful! " <<endl;
            return;
            
        } else {
            //throw error
            std::cerr << "Unsuccesful attempt at trading. " << endl;
            return;
        }    
    } catch (...) {
        std::cerr << "Invalid action. Denied." <<endl;
        return;
    }

}

void Board::mortgage(Building *property, Player *player){
    // TO IMPLEMENT

    //1. check the owner of property is in fact player
    //2. check mortgage is false, otherwise, cerr already mortgaged
    //3. determine building type
    //4. check improvements are sold
    //5. change mortgage to true, by setMortgage(false) => non-owners do not have to pay rent when landed
    //6. increase player money by half of the property cost, through getCost in ownable

    //cout << "hello" <<endl;

    Ownable *ownable = static_cast<Ownable*>(property);
    //Academic *ownable = static_cast<Ownable*>(property);
    //above can only access ownable type
    // Player *tmp = ownable->getOwner();
    Player *tmp = getOwner(ownable);

    
    if (tmp == nullptr) {
        std::cerr << "Mortgage failed. You do not own this property." << endl;
        return;
    }
    string name = tmp->getName();

    if (name != player->getName()) {
        std::cerr << "Mortgage failed. You do not own this property." << endl;
        return;
    }
    //check bType
    //mortgageThis = static_cast to A R or G else 

    if (ownable->getBType() == 'A') {

        Academic *a = static_cast<Academic*>(ownable);
        if (a->getLevel() != 0) {
            std::cerr << "Mortgage failed. You must sell improvements before mortgaging." << endl;          
            return;
        }

        int mortgageValue = a->getCost() / 2;
        player->setMoney(mortgageValue);
        a->setMortgageState(true);


    } else if (ownable->getBType() == 'R') {

        Residence *r = static_cast<Residence*>(ownable);
        int mortgageValue = r->getCost() / 2;
        player->setMoney(mortgageValue);
        r->setMortgageState(true);

    } else if (ownable->getBType() == 'G') {

        Gym *g = static_cast<Gym*>(ownable);
        int mortgageValue = g->getCost() / 2;
        player->setMoney(mortgageValue);
        g->setMortgageState(true);

    } else {
        std::cerr << "Mortgage failed. Property is not of Academic, Residence, or Gym." << endl;
        return;
    }

    cout << "Mortgage successful!" << endl;
    return;

}

void Board::unmortgage(Building *property, Player *player){
   //To unmortgage a property, the player must pay half of the cost of the property plus 10% more of the cost of the property (a total of 60% of the cost of the property).
   int unmortgageCost = ((static_cast<Ownable*>(property))->getCost()) * 0.6;
   if (player->getMoney() >= unmortgageCost){
       player->setMoney(unmortgageCost * -1); // removes the money from the player
       (static_cast<Ownable*>(property))->setMortgageState(false); //set state of mortgage to false
    //    property->setOwner(player); // sets the player as the owner of the property (might not need since mortgaging doesnt change ownership)
       setOwner(property, player); // sets the player as the owner of the property (might not need since mortgaging doesnt change ownership)
   } else { //player doesnt have enough to pay
       cout << "You do not have enough money to unmortgage this property. To unmortgage this property you need to pay: $" << unmortgageCost << endl;
   }
}


//change type to bool
bool Board::bankrupt(Player *player, int Owed, Player *toWho){
    // TO IMPLEMENT
    //need to verify if they really want to declare bankruptcy 
    //NEED to chnage the currPlayer to next player index (check doc) 

    try {
        int raisedMoney = player->getMoney();

        if (player->getMoney() >= Owed) { //has enough money to pay
            cout << "You have enough money to pay your debts, you do not meet the criteria to declare Bankruptcy." << endl; 
            return false;
        } else { //doesnt have enough money 
            // see if assests allow to get more money to pay off debts 
            //player->total_worth() in the condition
            if ( player->getMoney()>= Owed) {
                cout << "You have enough assets to sell/mortgage to pay your debts, you do not meet the criteria to declare Bankruptcy." << endl; 
                return false;
            } else {
                //PLAYER IS BANKRUPT
                //cout << "Your total worth if you sell/mortgage all of your improvements and properties is: $" << player->total_worth() << ". Unfortunently, you still wont have enough money to pay your debts. We are sorry to see you go, better luck next time." << endl;
                

                //now trying to raise money by sellling improvements and mortgage properties
                
                //1. sell improvements and mortgage
                for (int i = 0; i < player->properties.size(); ++i) {
                    
                    if (static_cast<Ownable*>(player->properties[i])->getBType() == 'A') {
                        Academic *a = static_cast<Academic*>(player->properties[i]);
                        while (a->getLevel() > 0) {
                            string action = "sell";
                            academicImprovements(a, action, player);
                            raisedMoney += a->getImprovementCost() / 2;
                        }
                    }
                    Ownable *o = static_cast<Ownable*>(player->properties[i]);
                    if (o->getMortgageState()) {
                        raisedMoney += o->getCost() / 2;
                        mortgage(o, player);
                    }

                }

                //check if avoided bankruptcy
                if (raisedMoney >= Owed) {
                    cout << "You successfully raised enough money to pay off your debt!" << endl;
                    //player->setMoney(raisedMoney - Owed);  DO WE NEED TO DO THIS?
                    return false;
                }
                cout << player->getName() << " has declared bankruptcy! We are sorry to see you go, better luck next time." << endl;

                if (toWho) {
                    cout << toWho->getName() << " receives all assets from " << player->getName() << endl;
                    for (int i = 0; i < player->properties.size(); ++i) {
                        Ownable *prop = static_cast<Ownable*>(player->properties[i]);
                        setOwner(prop, player);
                        if (prop->getMortgageState()) {
                            int fee = prop->getCost() * 0.1;
                            toWho->setMoney(-fee);
                            cout << toWho->getName() << " pays $" << fee << " to the bank for the mortgaged property " << prop->getBName() << endl;
                        }
                    }
                    toWho->setMoney(player->getMoney());                    
                } else { //TO BANK
                    cout << player->getName() << "'s properties go to auction!" << endl;
                    
                    for (int i = 0; i < player->properties.size(); ++i) {
                        Ownable *prop = static_cast<Ownable*>(player->properties[i]);
                        removeOwner(prop);
                        prop->setMortgageState(false);
                        auction(prop);
                    }                
                }
                //get rid of their rim card 
                if (player->getRimCups() != 0){ //if player had a rim cup this gives them back into the game (no need to remove from player bc the player will be deleted anyway) 
                    setRemainingNumRimCups(player->getRimCups());
                }
            }
        }
        string name = player->getName();
        player->setBankruptStatus(true);

        for (int i = 0; i < vec_players_selected.size(); ++i){ //removes the player from vec of players in the game
            char one = vec_players_selected[i]->getAcronym();
            char two = player->getAcronym();

            if (one == two){ //player found in the vec
                vec_players_selected.erase(vec_players_selected.begin() + i);
                break;
            }
        }
        if (currPlayer == vec_players_selected.size() - 1){ //shifts the turn to the next player if the player removed was at the end, else the currPlayer int stays the same as before becuase the next player shifted into the pos of the removed player 
            currPlayer = 0;
        }
        cout << name << " has left the game!" << endl;
        stateOfBoardChange();
        printBoard();
        return true;

    } catch (...) {
        cout << "Invalid occurence." << endl;
        return false;
    }
}

void Board::auction(Building *building){
    // TO IMPLEMENT
}

Building* Board::getBuilding(string Bname){
    int i;
    for (i = 0; i < vec_buildings.size(); ++i){
        if (vec_buildings[i]->getBName() == Bname){
            return vec_buildings[i].get();
        }
    }
    cout << Bname << " is not a valid building name" << endl;
    return nullptr;
}


void Board::pay(Player *whoOwes, int howMuchOwed, Player *toWhoOwed){
   string com;
   bool bankruptcyStatus = false;
   cout << "You need to pay $" << howMuchOwed << ", please choose any of the following commands - trade <name> <give> <receive>, improve <property> sell, mortgage <property>, or bankrupt: " <<endl;
   while (whoOwes->getMoney() < howMuchOwed || !(bankruptcyStatus)) {
       while (!(cin >> com)){
           cout << "invalid command, please chose any of - trade <name> <give> <receive>, improve <property> sell, mortgage <property>, or bankrupt: //assets and all  " << endl; //declare bankruptcy??
       }
       if (com == "trade") { //trade <name> <give> <receive>
           string name;
           string give;
           string receive;
           cin >> name >> give >> receive;
           trade(name, give, receive, whoOwes);


       } else if (com == "improvements") { //improve <property> sell/buy
           string propertyName;
           string status;
           cin >> propertyName >> status;
           Building *b = getBuilding(propertyName);
           if (b) {
               academicImprovements(b, status, whoOwes);
           }
       } else if (com == "mortgage") { // mortgage <property>
           string propertyName;
           cin >> propertyName;
           Building *b = getBuilding(propertyName);
           if (b) {
               mortgage(b, whoOwes); //whoOwes is player who is doing the mortgaging
           }
       } else if (com == "bankrupt"){
           bankruptcyStatus = bankrupt(whoOwes, howMuchOwed, toWhoOwed); //maybe do a double check if they really want to bankrupt bc it is irreversible if it works
       } else {
           cout << "not a valid choice, please chose any of - trade <name> <give> <receive>, improve <property> sell, mortgage <property>, or bankrupt: " << endl; //declare bankruptcy??
       }
   }
   if (bankruptcyStatus){
       cout << "It was nice having you in the game, now it is the next players turn." << endl;
   } else {
       whoOwes->setMoney((howMuchOwed * -1)); // removes the money owed from the player who landed on the space
       toWhoOwed->setMoney(howMuchOwed); //pays the owner the money owed
       cout << "You have enough money, the rent has been paid. Your current balance is: " << whoOwes->getMoney() << endl;
   }
}


//get set remove Owner

Player* Board::getOwner(Building *b){ //if there is no owner then will return nullptr
    for (int i = 0; i < vec_players_selected.size(); ++i){
        if (vec_players_selected[i]->properties.size() != 0){
            for (int j = 0; j < vec_players_selected[i]->properties.size(); ++j){
                if (b->getBPos() == vec_players_selected[i]->properties[j]->getBPos()){
                    return vec_players_selected[i].get();
                }
            }
        }
    }
    return nullptr;
}

void Board::setOwner(Building *b, Player *p) {
    //emplace back to properties in player p
    //loop thorugh all the buildings the player owns when BName is the same, remove
    
    //check if this building already exists in the properties
    // cast to ownable and emplace back

    for (int i = 0; i < p->properties.size(); ++i) {
        if (b->getBName() == p->properties[i]->getBName()) {
            cout << p->getName() << " already owns this building" <<endl;
            return;
        }
    }
    Ownable *o = static_cast<Ownable*>(b);
    p->addOwnable(o);
}


void Board::removeOwner(Building *b) {
    //get the player through getOwner then loop through all the buildings and remove the one they own
    //-properties: Vector<Ownable *>

    Player *removeOwnership = getOwner(b);
    for (int i = 0; i < removeOwnership->properties.size(); ++i) {
        if (b->getBName() == removeOwnership->properties[i]->getBName()) {
            //remove building
            removeOwnership->properties.erase(removeOwnership->properties.begin() + i);
        }
    }
}

void Board::addBuildingINIT(string Bname, string block, int improvements, int pos, int pur, int imp, size_t z, size_t o, size_t t, size_t thr, size_t f, size_t fiv){
   unique_ptr<Building> b;
   if (pos == 12 || pos == 28){ //gym
       b = make_unique<Gym>(Bname, pos);
   } else if (pos == 5 || pos == 15 || pos == 25 || pos == 35){ //res
       b = make_unique<Residence>(Bname, pos);
   } else if (pos == 0 || pos == 2 || pos == 4 || pos == 7 || pos == 10 || pos == 17 || pos == 20 || pos == 22 || pos == 30 || pos == 33 || pos == 36 || pos == 38){ //unownable
       b = make_unique<Unownable>(Bname, pos);
   } else {
       unique_ptr<vector<size_t>> v = make_unique<vector<size_t>>(initializer_list<size_t>{z, o, t, thr, f, fiv});
       b = make_unique<Academic>(Bname, pos, 0, block, move(v), pur, imp, false);
   }
   vec_buildings.emplace_back(move(b)); //no access to board
}
