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
                B->addBuildingINIT(line, " ", nullptr, 0, pos, 0,0,0,0,0,0,0,0);
            }else {
                istringstream iss(line);
                iss >> Bname >> block >> pur >> imp >> z >> o >> t >> thr >> fo >> fiv;
                B->addBuildingINIT(Bname, block, nullptr, 0, pos, pur, imp, z, o, t, thr, fo, fiv);
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

// //TEMPORARY: 
// void addBuildingINMAIN(string Bname, string owner, int improvements, int pos){ //DELETE AFTER TEST 
//     // !! MAKE EACH ONE HEAP ALLOCATED 
//     //Player *p; 
//     // if (Bname != "BANK") {
//     //     p = getPlayer(Bname); 
//     // } else {
//          //p = nullptr;
//     // }
//     if (pos == 12 || pos == 28){ //gym
//     //     Gym *b(Bname, pos, p); 
//         //unique_ptr<Gym> b = make_unique<Gym>(Bname, pos, p);
//         unique_ptr<Gym> b = make_unique<Gym>(Bname, pos, nullptr);
//     } else if (pos == 5 || pos == 15 || pos == 25 || pos == 35){ //res
//     //     Res *b(Bname, pos, p); 
//         //unique_ptr<Res> b = make_unique<Res>(Bname, pos, p);
//         unique_ptr<Residence> b = make_unique<Residence>(Bname, pos, nullptr);
//     } else if (pos == 0 || pos == 2 || pos == 4 || pos == 7 || pos == 10 || pos == 17 || pos == 20 || pos == 22 || pos == 30 || pos == 33 || pos == 36 || pos == 38){ //unownable
//     //     Unownable *b(Bname, pos);
//         unique_ptr<Unownable> b = make_unique<Unownable>(Bname, pos);
//     } else { 
//         //find the monopoly string 
//         // add the tuition manually for each building (manual)
//         //improvement cost for each building  (manual)
//         //and check if the owner of the building has a monopoly (bool)
//         unique_ptr<vector<size_t>> v = make_unique<vector<size_t>>(6, 0);

//         //unique_ptr<Academic> b = make_unique<Academic>(Bname, pos, p, "string", get(v), 0, true);
//         unique_ptr<Academic> b = make_unique<Academic>(Bname, pos, nullptr, "string", move(v), 0, true);
//     }
//     //     // Academic *b(Bname, pos, p, improvements, string monopolyBlock, vector<size_t> tuition, int improvementCost, bool hasMonopoly);
//     //     // need to find the monopolyBlock, fill in all the tuitions manually :(, and improvement cost, and the hasmonopoly boolean.

//     vec_buildings.emplace_back(move(b)); //no access to board 

//     cout << "here1" << b->getBPos() << endl;
//     cout << "here1" << b->getBName() << endl;
//     // cout << "here2" << b.vec_buildings[0]->getBPos() << endl;
//     // cout << "here2" << b.vec_buildings[0]->getBName() << endl;
// }


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
                    //find owner * 
                    // determine if has monopoly from owner buildings 
                    //change ownable status to tue
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
        // cout << "here3" << boardMain.vec_buildings[0]->getBPos() << endl;
        // cout << "here3" << boardMain.vec_buildings[0]->getBName() << endl;
        // cout << "here4" << boardMain.vec_buildings[39]->getBPos() << endl;
        // cout << "here4" << boardMain.vec_buildings[39]->getBName() << endl;
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
        // Player p1("P1", 'A', 0, 1500, 0, 0, 0);
        // boardMain.addPlayer(&p1);
        // Player p2("P2", 'B', 0, 1500, 0, 0, 0);
        // boardMain.addPlayer(&p2);
        // Player p3("P3", 'C', 0, 1500, 0, 0, 0);
        // boardMain.addPlayer(&p3);
     // else for the player selection
        // unique_ptr<Player> p = make_unique<Player>("player1", 'p', 0, 1500, 0, 0, 0); 
        // boardMain.vec_players_selected.emplace_back(move(p));
        cout << "number of players is: " << boardMain.getNumPlayers() << endl; 
        cout << "the players chosen are: " << endl;
        for (int i = 0; i < n; ++i){
            cout << boardMain.vec_players_selected[i]->getName() << " " << boardMain.vec_players_selected[i]->getAcronym() << endl;
        }
        // cout << "they are: " << endl; 
        // int ctt = 0; 
        // while (ctt < n){
        //     cout << boardMain.vec_players_selected[ctt]->getName() << " " << boardMain.vec_players_selected[ctt]->getAcronym() << endl;
        //     ++ctt;
        // }
        cout << "It is now " << boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getName() << "'s turn!" << endl;
        string command;
        while (cin >> command){
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
                    // v = *DiceRoll();
                    // cout << "the result of your dice are: " << endl; 
                    // cout << "dice 1: " << v[0];
                    // cout << "dice 2: " << v[1]; 
                    // if (v[0] == v[1]) { //rolled doubles
                    //     cout << "Congratulations, you rolled doubles. You got your coffee." << endl;
                    //     boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setJailStatusNum(0);
                    //     boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setJailTurns(0);
                    // } else if (boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getJailTurns() < 3){ //still in jail, less turns than 3
                    //     boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setJailTurns(1);
                    //     cout << "Sorry, no doubles, keep wiating in line. You are on your: " << boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getJailTurns() << " turn." << end;
                    //     if (boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getRimCups() > 0){
                    //         cout << "You have " << boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getRimCups() << " TimsCups, would you like to use it? [yes/no]: " << endl;
                    //         string s; 
                    //         while (!cin >> s || (s != "yes" && s != "no")){
                    //             cout << "Invalid command please choose from [yes/no] (all lowercase): " << endl;
                    //         }
                    //         if (s == "yes"){
                    //             boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setRimCups(-1);
                    //             cout << "You have " << boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getRimCups() << " remaining TimsCups." << endl;
                    //             cout << "Congratulations, you got your coffee." << endl;
                    //             boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setJailStatusNum(0);
                    //             boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setJailTurns(0);
                    //         } else { // "no"
                    //             cout << "Do you want ..." << endl; //!! FINSIH UP LOGIC 
                    //         }
                    //     }
                    // } else { //third and final turn 
                    //     cout << "This is your third turn in the line, $50 has been taken from your balance. You are free to leave next turn." << endl; // !! do they need to pay 50?? or can they choose not to 
                    //     boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setJailStatusNum(0);
                    //     boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setMoney(-50);
                    //     boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setJailTurns(0);
                    // }
                }
                //for testing:
                cout << "your dice sum is: " << sum_of_roll << endl; 

                boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setPos(sum_of_roll); //updates the player position
                if (boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getPos() > 40){ //checks if went around the circle  // WHEN LANDING ON OSAP WILL NOT GAIN 200 THROUGH THIS (so when pos == 0)
                    boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setPos(-40);
                    //means passed Go (or landed on Go) 
                    boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setMoney(200);
                } //maybe change this whole block to be move(sum_of_roll, true). so player*->move(...);

                // // need to check if players pos is on owneable or unowneable space 
                // int pos = boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getPos();
                // //Player *currentPlayerPtr = boardMain.vec_players_selected[boardMain.getCurrPlayer()];  
                // if (boardMain.vec_buildings[pos]->getOwnableStatus()){ //means is an owneable building 
                //     //check owenrship 
                //     if (boardMain.vec_buildings[pos]->getOwner()){ //is ownable 
                //         if(boardMain.vec_buildings[pos]->getOwner()->getName() == boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getName()){ //owner by this player 
                //             cout << "You own this property, nice!" << endl;
                //         } else { //owned by other player
                //             //cout << "This buliding is owned, please pay [...] [$...]. "; 
                //             //just pay right away (can_pay)
                //             int owed = boardMain.moneyOwed(boardMain.vec_buildings[pos], sum_of_roll);
                //             if (boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getMoney() >= owed){ //moneyOwed is the owneable building's rent/tuiton (with monopoly and/or improvements IF ITS ACADEMIC etc) (moneyOwed will check if it is a RES or GYM - maybe consider adding a bool in buildings)
                //                 boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setMoney((owed * -1)); // removes the money owed from the player who landed on the space 
                //                 boardMain.vec_buildings[pos]->owner->setMoney(owed); //pays the owner the money owed
                //                 cout << "You have enough money, the rent has been paid. Your current balance is: " << boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getMoney() << endl;
                //             } else {
                //                 cout << "You do not have enough money, please do any of the following - trade <name> <give> <receive>, improve <property> sell, mortgage <property>, or bankrupt : " << endl; 
                //                 //pay(whoOwes, howMuchOwed, toWhoOwed, buildingPos) 
                //                 boardMain.pay(boardMain.vec_players_selected[boardMain.getCurrPlayer()], owed, boardMain.vec_buildings[pos]->owner);
                //             }
                //         }  
                //     } else {
                //         //unowned (owner is nullptr) !!!
                //         // cout << "do you want to buy?: YES or NO " << endl; 
                //         //     if (cin >> "YES"){
                //         //         buy(); //will remove the price money from currPlayer 
                //         //     } 
                //         cout << "no owner" << endl;  
                //     }                     
                // } else { //unowneable properties
                //     cout << "unownable" << endl;
                // }
                // boardMain.stateOfBoardChange(); //notifies there is change in display 
                // boardMain.notifyObservers(); //notifies there is change in display 
            }else if (command == "save"){ // save <filename>
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
                boardMain.setCurrPlayer(boardMain.getCurrPlayer() + 1);
                if (boardMain.getCurrPlayer() > (numPlayers - 1)){ //gives turn back to the first player after the last player calls "next"
                    boardMain.setCurrPlayer(0);
                }
                cout << "new: " << boardMain.getCurrPlayer()<< endl;
                cout << "It is now " << boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getName() << "'s turn!" << endl;
            }else if (command == "trade"){ // trade <name> <give> <receive>
                //trade(); //IMPLEMENT
            }else if (command == "improve"){ // improve <property> buy/sell
                //improvements(); //IMPLEMENT
            }else if (command == "mortgage"){ // mortgage <property>
                //mortgage(); //IMPLEMENT
            } else if (command == "bankrupt"){ // bankrupt
                //bankrupt(); 
            } else if (command == "unmortgage"){ // unmortgage <property>
                 
            } else if (command == "assets"){ // assets
                //boardMain.vec_players_selected[boardMain.getCurrPlayer()]->printAssests();
            } else if (command == "all"){ // all
                // int cttt = 0;
                // boardMain.vec_players_selected[boardMain.getCurrPlayer()]->printAssests(); // extra feature: prints the player who called assets before everyone else
                // while (cttt < boardMain.vec_players_selected.size()){
                //     if (cttt != boardMain.getCurrPlayer()){
                //         boardMain.vec_players_selected[cttt]->printAssests();
                //     }
                // }
            } else {
                cout << "Not a valid command, please try again: " << endl;
            }
            //} // switch
        } // while
    } // else 
}
