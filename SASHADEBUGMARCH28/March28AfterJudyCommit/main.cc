import Board;
import Player;
import Building;
import ownable;
import Unownable;
import gym;
import residence;
import academic;
import <iostream>;
import <fstream>;
import <string>;
import <sstream>;
import <vector>;
import <memory>;
//import <map>;
import <ctime>;

using namespace std;

bool fair_dice = true; 
bool load_game = false;

void setBuildings(Board *B){
    ifstream f("buildings.txt"); //all 40 
    if (!f.is_open()){
        cout << "invalid file name." << endl; 
    } else {
        //istringstream iss;
        string line;
        int pos = 0; 
        string Bname;
        string block;
        int improvements, pur, imp, z, o, t, thr, fo, fiv;
        while (getline(f, line)){
            if (pos == 12 || pos == 28 || pos == 5 || pos == 15 || pos == 25 || pos == 35 || pos == 0 || pos == 2 || pos == 4 || pos == 7 || pos == 10 || pos == 17 || pos == 20 || pos == 22 || pos == 30 || pos == 33 || pos == 36 || pos == 38){ 
                //cout << line << endl;
                B->addBuildingINIT(line, " ", 0, pos, 0,0,0,0,0,0,0,0);
            }else {
                istringstream iss(line);
                iss >> Bname >> block >> pur >> imp >> z >> o >> t >> thr >> fo >> fiv;
                B->addBuildingINIT(Bname, block, 0, pos, pur, imp, z, o, t, thr, fo, fiv);
                //Testing:
                //cout << Bname << " " << pos << pur << imp << z << o << t << thr << fo << fiv << endl;
            }
            ++pos;
        }
    }
    f.close(); 
}

vector<int> *DiceRoll(){
    vector<int> v;
    srand(time(0));
    int dice1 = rand() % 6 + 1;
    cout << "Dice 1: " << dice1 <<std::endl;
    int dice2 = rand() % 6 + 1;
    cout << "Dice 2: " << dice2 <<std::endl;
    v.emplace_back(dice1);
    v.emplace_back(dice2);
    return &v;
}

void selectPlayers(int numPlayers, Board *b){
    if (load_game == false){
        cout << "Character select! Please choose your character, here are the options: <Name> <Char>" << endl;
        cout << "---------------------------------------------------------------------------------------------------\n";
        cout << "| Name | Goose | GRT Bus | Tim Hortons Donghnut | Professor | Student | Money | Laptop | Pink Tie |\n";
        cout << "---------------------------------------------------------------------------------------------------\n";
        cout << "| Char |   G   |    B    |           D          |     P     |    S    |   $   |    L   |    T     |\n";
        cout << "---------------------------------------------------------------------------------------------------\n";
    
        //map<char,string> m {{'G', "Goose"}, {'B', "Bo"}, {'D', "Do"}, {'P', "Prof"}, {'S', "Stu"}, {'$', "Mon"}, {'L', "Laptop"}, {'T', "Pink"}};

        int ct = 0; 
        //char c; 
        string name;
        char chara;
        //string i;
        while (ct < numPlayers){
            cin.clear();
            cin.ignore();
            //bool nameFound = false;
            //bool duplicate = false;
            while (!(cin >> name)){
                cout << "Invalid input, please try again: " << endl;
            }
            cout << "Welcome, " << name << "!" << endl;
            while (true){    
                bool duplicate = false;
                while (!(cin >> chara)){
                    cout << "Invalid input, please try again: " << endl;
                }
                for (int i = 0; i < ct; ++i){ //need to check if the chara is already used 
                    if (b->vec_players_selected[i]->getAcronym() == chara){
                        cout << "This token is already taken, please choose again: <Char>" << endl;
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate){
                    break;
                }
            }
            // if (m.find(chara) == m.end()){ //not found
            //     cout << "Way to be unique! Your token is represented by: " << chara << endl;
            //} else {
                cout << "Your token is represented by: " << chara << endl;
           // }
            unique_ptr<Player> p = make_unique<Player>(name, chara, 0, 1500, 0, 0, 0); 
            //m.erase(chara); 
            b->vec_players_selected.emplace_back(move(p));
            //b->addPlayer(&p);
            ++ct;
            // Testing: 
            cout << "You chose: " << b->vec_players_selected[ct-1]->getName() << " " << b->vec_players_selected[ct-1]->getAcronym() << endl;
        }
    } 
}

bool loadGame(string filename, Board *B){ //need to have info on ownable buildings to implement
    ifstream f(filename); //all 40 
    if (!f.is_open()){
        return false;
    } else {
        string line;
        int n; 
        f >> n;
        while (n > 0){
            getline(f, line);
            istringstream iss(line);
            string player1;
            char c; 
            int TimsCups;
            int money; 
            int position; 
            int jail = 0; 
            int turns = 0;
            iss >> player1 >> c >> TimsCups >> money >> position; 
            if (position == 10){
                iss >> jail;
                if (jail == 1) {
                    iss >> turns; 
                }
            }
            unique_ptr<Player> p = make_unique<Player>(player1, c, TimsCups, money, position, jail, turns); 
            B->vec_players_selected.emplace_back(move(p));
            --n;
        } //added all the players
        cout << "All the players have been added!" << endl;
        //int buildingPos = 0; //will keep track of each building
        string buildingName;
        string owner; 
        int improvements;
        while (getline(f, line)){ 
            istringstream iss(line);
            iss >> buildingName >> owner >> improvements;
            for (int i = 0; i < B->vec_buildings.size(); ++i){
                if (B->vec_buildings[i]->getBName() == buildingName){
                    B->vec_buildings[i]->setImprovments(improvements);
                    //find player by name, add this building to their properties vector !!!!!!!!
                    // SET ISOWNED FIELD AS TRUE !!!!!!!
                    // determine if has monopoly from owner buildings - covered by addOwnable
                    if (owner != "BANK"){
                        for (int j = 0; j < B->getNumPlayers(); ++j){
                            if (B->vec_players_selected[j]->getName() == owner){
                                B->vec_buildings[i]->setOwnable(true);
                                //B->vec_buildings[i]->setOwner(B->vec_players_selected[j].get());
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            //++buildingPos;
        } 
    }
}

int main(int argc, char* argv[]){
    Board boardMain; 
    setBuildings(&boardMain); //initializes all buildings
    //bool worked = loadGame("buildingTEST.txt", &boardMain);
    //if (worked){
        cout << "WORKED" << endl;
        cout << "size:" << boardMain.vec_buildings.size() << endl;
        for (int i = 0; i < boardMain.vec_buildings.size(); ++i){
            cout << i << ": " << boardMain.vec_buildings[i]->getBName() << endl;
        }
    //}
    //setBuildings(&boardMain);
    //Display_Events DE = ctor call and pass boardMain; //observer //need display_events to implement 
    //boardMain.attach(&DE);
    if (argc > 1 ) {
        cout << "ENTERED" << endl;
        //rmr the case when you could have both commands at once: -load file.txt -testing OR -testing -load file.txt
        int ct = 1; 
        cout << "argv first el: " << argv[1] << endl;
        while (ct < argc) {
            if (argv[ct] == "-load") { // !! why does this not equal 
                cout << "before1" << endl;
                //check if filename is valid: 
                    // if not valid state it and just exit 
                ++ct;
                string filename = argv[ct]; 
                cout << "before" << endl;
                if (loadGame(filename, &boardMain)) {//get info from the file 
                    cout << "worked" << endl;
                    cout << boardMain.getNumPlayers() << endl;
                    //cout << boardMain.vec_buildings[1]->getBName() << " num improvs: " << boardMain.vec_buildings[1]->getLevel() << endl;
                } else {
                    cout << "invalid filename, exiting program" << endl;
                    return 0; //exit program 
                }
            } else if (argv[ct] == "-testing"){
                //switch boolean to start calling the testing dice not the regular dice;
                fair_dice = false;
                ++ct;
            }
        }         
    } else {
        //vector<Player*> vec_players;
        cout << "Hello!! Welcome to Watopoly, please enter the number of players (between 2 and 6): " << endl;
        int n; //numPlayers
        while(!(cin >> n) || n < 2 || n > 6) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Thats not a number please enter a valid number between 2 and 6: " << endl;
            } else {
                if (n < 2){
                    cout << "Cannot have less than two players, please enter again: " << endl;
                }
                if (n > 6){
                    cout << "Cannot have more than six players, please enter again: " << endl; 
                }
            }
        }
        cout << "out of while loop" << endl;
        // !! n is numer of players
        selectPlayers(n, &boardMain);
        
     // else for the player selection
        // unique_ptr<Player> p = make_unique<Player>("player1", 'p', 0, 1500, 0, 0, 0); 
        // boardMain.vec_players_selected.emplace_back(move(p));
        cout << "number of players is: " << boardMain.getNumPlayers() << endl; 
        cout << "the players chosen are: " << endl;
        for (int i = 0; i < n; ++i){
            cout << boardMain.vec_players_selected[i]->getName() << " " << boardMain.vec_players_selected[i]->getAcronym() << endl;
        }
        cout << "It is now " << boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getName() << "'s turn!" << endl;
        string command;
        while (cin >> command){
            // !! DO WE ADD END OF GAME CHECK HERE??? 
            if (boardMain.vec_players_selected.size() == 1){ // indicates end of game
                cout << "after while:" << endl; 
                cout << "Congratulations " << boardMain.vec_players_selected[0]->getName() << "!! YOu have won the game and dominatd Watopoly, thank you for playing:)" << endl;
                cout << "Game made by: Sasha Boruk, Shirley Xiao, and Jiayi Zhao. 2025" << endl;
                return 0;
            }
            // 
            cout << " you entered: " << command << endl;
            if (command == "roll"){ // roll OR roll <int> <int> if -testing in args
                int sum_of_roll = 0;
                vector<int> v; 
                if (boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getJailStatusNum() == 0) {
                    if (fair_dice){
                        v = *DiceRoll();
                        sum_of_roll = v[0] + v[1];
                    } else { // are we allowed a unfair dice when in jail? 
                        int x; 
                        int y; 
                        cin >> x; 
                        cin >> y; 
                        while (x < 0) {
                            cout << "Oops, the first number is negative: please enter a postive number: " << endl;
                            cin >> x;
                        }
                        while (x < 0) {
                            cout << "Oops, the second number is negative: please enter a postive number: " << endl;
                            cin >> y;
                        }
                        sum_of_roll = x + y;
                    }
                } else {
                    //in jail 
                    static_cast<Unownable*>(boardMain.vec_buildings[boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getPos()].get())->triggerEvent(boradMain.vec_players_selected[boardMain.getCurrPlayer()]);
                }
                //for testing:
                cout << "your dice sum is: " << sum_of_roll << endl; 

                boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setPos(sum_of_roll); //updates the player position
                if (boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getPos() > 40){ //checks if went around the circle  // WHEN LANDING ON OSAP WILL NOT GAIN 200 THROUGH THIS (so when pos == 0)
                    boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setPos(-40);
                    //means passed Go (or landed on Go) 
                    boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setMoney(200);
                } //maybe change this whole block to be move(sum_of_roll, true). so player*->move(...);
                
                boardMain.stateOfBoardChange();
                boardMain.printBoard();
                // // need to check if players pos is on owneable or unowneable space 
                int pos = boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getPos();
                //Player *currentPlayerPtr = boardMain.vec_players_selected[boardMain.getCurrPlayer()];  
                if (boardMain.vec_buildings[boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getPos()]->getOwnableStatus()){ //means is an owneable building 
                    //check owenrship 
                    if (boardMain.getOwner(vec_buildings[pos])){ //has an owner
                        if(boardMain.getOwner(vec_buildings[pos])->getName() == boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getName()){ //owner by this player 
                            cout << "You own this property, nice!" << endl;
                        } else { //owned by other player
                            int owed = boardMain.moneyOwed(boardMain.vec_buildings[pos], sum_of_roll);
                            cout << "This buliding is owned, please pay $" << owed; 
                            if (boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getMoney() >= owed){ //moneyOwed is the owneable building's rent/tuiton (with monopoly and/or improvements IF ITS ACADEMIC etc) (moneyOwed will check if it is a RES or GYM - maybe consider adding a bool in buildings)
                                boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setMoney((owed * -1)); // removes the money owed from the player who landed on the space 
                                boardMain.vec_buildings[pos]->owner->setMoney(owed); //pays the owner the money owed
                                cout << "You have enough money, the rent has been paid. Your current balance is: $" << boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getMoney() << endl;
                            } else {
                                cout << "You do not have enough money, please do any of the following - trade <name> <give> <receive>, improve <property> sell, mortgage <property>, or bankrupt : " << endl; 
                                boardMain.pay(boardMain.vec_players_selected[boardMain.getCurrPlayer()], owed, boardMain.getOwner(vec_buildings[pos]));
                            }
                        }  
                    } else {
                        //unowned (owner is nullptr) !!!
                        cout << "This property costs $" << static_cast<Ownable*>(boardMain.vec_buildings[pos])->getCost() << " would you like to buy this property?: [YES or NO] " << endl; 
                            string ans; 
                            cin >> ans;
                            if (ans == "YES"){
                                if (boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getMoney() < << static_cast<Ownable*>(boardMain.vec_buildings[pos])->getCost()){
                                    cout << "You do not have enough money to get this building. Continue your turn: " << endl;
                                } else {
                                    boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setMoney((boardMain.vec_buildings[pos]->getCost() * -1)); //removes the money from the player who bought it
                                    boardMain.vec_buildings[pos]->setOwner(boardMain.vec_players_selected[boardMain.getCurrPlayer()].get()); //sets the player to be the owner of the building 
                                    boardMain.vec_players_selected[boardMain.getCurrPlayer()]->addOwnable(boardMain.vec_buildings[pos].get()); //adds the building to the players vector of buildings bought 
                                }
                            } else {
                                cout << "Okay, please continue your turn." << endl;
                            }  
                    }                     
                } else { //unowneable properties
                    cout << "unownable" << endl;
                    // !! ask judy what to put here
                    if (pos == 2 || pos == 17 || pos == 33){ //means landed on SLC
                        bool slc = true;
                    }
                    static_cast<Unownable*>(boardMain.vec_buildings[boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getPos()].get())->triggerEvent(boradMain.vec_players_selected[boardMain.getCurrPlayer()])
                    if (slc){
                        boardMain.stateOfBoardChange();
                        boardMain.printBoard();
                    }
                }
                // boardMain.stateOfBoardChange(); //notifies there is change in display 
                // boardMain.notifyObservers(); //notifies there is change in display
            }else if (command == "save"){ // save <filename>
                boardMain.stateOfBoardChange();
                string filename;
                cin >> filename;
                while (filename == "") {
                    cout << "Not a valid filename, please input the filename again: " << endl;
                    cin >> filename;
                }
                ofstream f{filename};
                f << "INSERT THE GAME INFO HERE" << endl; //GIVE ALL GAME INFO HERE; *** // !!
                f.close(); 
            }else if (command == "next"){ // next 
                cout << "prev: " << boardMain.getCurrPlayer() << endl;
                int numPlayers = boardMain.getNumPlayers();
                boardMain.setCurrPlayer(boardMain.getCurrPlayer() + 1); // !!! CHECK EDGE CASE WITH ONLY 1 PLAYER IN VEC 
                if (boardMain.getCurrPlayer() > (numPlayers - 1)){ //gives turn back to the first player after the last player calls "next"
                    boardMain.setCurrPlayer(0);
                }
                cout << "new: " << boardMain.getCurrPlayer()<< endl;
                if (boardMain.vec_players_selected.size() == 1){ // indicates end of game 
                    cout << "Congratulations " << boardMain.vec_players_selected[0]->getName() << "!! YOu have won the game and dominatd Watopoly, thank you for playing:)" << endl;
                    cout << "Game made by: Sasha Boruk, Shirley Xiao, and Jiayi Zhao. 2025" << endl;
                    return 0;
                } else {
                    cout << "It is now " << boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getName() << "'s turn!" << endl;
                }
            }else if (command == "trade"){ // trade <name> <give> <receive>
                string name, give, receive;
                cin >> name >> give >> receive; 
                boardMain.trade(name, give, receive, boardMain.vec_players_selected[boardMain.getCurrPlayer()].get()); 
            }else if (command == "improve"){ // improve <property> buy/sell
                string propertyName,status; 
                cin >> propertyName >> status;
                Building *b = getBuilding(propertyName).get();
                if (b) {
                    boardMain.academicImprovements(b, status, boardMain.vec_players_selected[boardMain.getCurrPlayer()].get()); 
                }
                boardMain.printBoard();
            }else if (command == "mortgage"){ // mortgage <property>
                

                string propertyName; 
                cin >> propertyName;
                Building *b = getBuilding(propertyName).get();
                if (b) {
                    boardMain.mortgage(b, boardMain.vec_players_selected[boardMain.getCurrPlayer()].get()); 
                }
            } else if (command == "bankrupt"){ 
                cout << "You currently do not need to pay more money than you have, this is not a valid command please enter again: " << endl;
                // bankrupt // CAN WE EVEN HAVE THIS HERE?? 
                // does this mean they are just bankrupt in general, so technically to bank? or do we allow them to just drop out of game 
                // possible solution: 
                // remove from here 
                //boardMain.bankrupt(); 
            } else if (command == "unmortgage"){ // unmortgage <property>
                string propertyName; 
                cin >> propertyName;
                Building *b = getBuilding(propertyName).get();
                if (b) {
                    boardMain.unmortgage(b, boardMain.vec_players_selected[boardMain.getCurrPlayer()].get());
                }
            } else if (command == "assets"){ // assets
                boardMain.vec_players_selected[boardMain.getCurrPlayer()]->printAssests();
            } else if (command == "all"){ // all
                int cttt = 0;
                boardMain.vec_players_selected[boardMain.getCurrPlayer()]->printAssests(); // extra feature: prints the player who called assets before everyone else
                while (cttt < boardMain.vec_players_selected.size()){
                    if (cttt != boardMain.getCurrPlayer()){
                        boardMain.vec_players_selected[cttt]->printAssests();
                    }
                    ++cttt;
                }
            } else if (command == "print"){
                boardMain.stateOfBoardChange();
                boardMain.printBoard();           
            } else {
                cout << "Not a valid command, please try again: " << endl;
            }
            //} // switch
        } // while
    } // else 
}
