import Board;
import Player;
import <iostream>;
import <fstream>;
import <string>;
import <sstream>;
import <vector>;
import <ctime>;

using namespace std;

bool fair_dice = true; 

int DiceRoll(){
    srand(time(0));
    int dice1 = rand() % 6 + 1;
    cout << "Dice 1: " << dice1 <<std::endl;
    int dice2 = rand() % 6 + 1;
    cout << "Dice 2: " << dice2 <<std::endl;
    return dice1 + dice2;
}

void selectPlayers(int numPlayers, Board *b){
    cout << "here are the options: ... a,b,c ..." << endl; 
    int ct = 0; 
    char c; 
    string name;
    string line;
    string i;

    // For Testing:
    Player p1("P1", 'A', 0, 1500, 0, 0, 0);
    b->addPlayer(&p1);
    Player p2("P2", 'B', 0, 1500, 0, 0, 0);
    b->addPlayer(&p2);
    Player p3("P3", 'C', 0, 1500, 0, 0, 0);
    b->addPlayer(&p3);
}

// bool loadGame(char* filename, Board *B){ //need to have info on ownable buildings to implement
//     ifstream f;
//     if (!f.open(filename)){
//         return false;
//     } else {
//         istringstream iss;
//         string word;
//         int n; 
//         f >> n;
//         while (n > 0){
//             getline(f, iss);
//             string player1;
//             char c; 
//             int TimsCups;
//             int money; 
//             int position; 
//             int jail = 0; 
//             int turns = 0;
//             iss >> player1 >> c >> TimsCups >> money >> position; 
//             if (position == 10){
//                 iss >> jail;
//                 if (jail == 1) {
//                     iss >> turns; 
//                 }
//             }
//             Player p(player1, c, TimsCups, money, position, jail, turns);
//             B->addPlayer(p);
//             --n;
//         } //added all the players
//         int buildingPos = 0; //will keep track of each building
//         string buildingName;
//         string owner; 
//         int improvements;
//         while (getline(f, iss)){ 
//             iss >> buildingName >> owner >> improvements;
//             // !! Need to see how ctor is implemented for academic, gym, and res
//             B->addBuilding(buildingName, owner, improvements, buildingPos);
//             ++buildingPos;
//         } 
//     }
// }

int main(int argc, char* argv[]){
    Board boardMain; 
    // Display_Events DE; //observer //need display_events to implement 
    // boardMain.attach(&DE);
    if (argc > 1) {
        // //rmr the case when you could have both commands at once: -load file.txt -testing OR -testing -load file.txt
        // int ct = 1; 
        // while (ct < argc) {
        //     if (argv[ct] == "-load") {
        //         //check if filename is valid: 
        //             // if not valid state it and just exit 
        //         ++ct;
        //         char* filename = argv[ct]; 
        //         if (loadGame(filename, &boardMain)) {//get info from the file 
                    
        //         } else {
        //             cout << "invalid filename, exiting program" << endl;
        //             return 0; //exit program 
        //         }
        //     } else if (argv[ct] == "-testing"){
        //         //switch boolean to start calling the testing dice not the regular dice; 
        //         ++ct;
        //     }
        // }         
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
        cout << "number of players is: " << boardMain.getNumPlayers() << endl; 

        string command;
        while (cin >> command){
            cout << " you entered: " << command << endl;
            if (command == "roll"){ // if in testing mode then roll <int> <int>
                int sum_of_roll = 0;
                if (fair_dice){
                    sum_of_roll = DiceRoll();
                } else {
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
                //for testing:
                cout << "your dice sum is: " << sum_of_roll << endl; 

                boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setPos(sum_of_roll); //updates the player position
                if (boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getPos() >= 40){ //checks if went around the circle 
                    boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setPos(-40);
                    //means passed Go (or landed on Go) 
                    boardMain.vec_players_selected[boardMain.getCurrPlayer()]->setMoney(200);
                }

                // need to check if players pos is on owneable or unowneable space 
                int pos = boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getPos();
                //Player *currentPlayerPtr = boardMain.vec_players_selected[boardMain.getCurrPlayer()];  
                // if (boardMain.vec_buildings[pos]->getOwnableStatus()){ //means is an owneable building 
                //     //check owenrship 
                //     if (boardMain.vec_buildings[pos]->owner){ //owner by this player 
                //         if(boardMain.vec_buildings[pos]->owner->getName() == boardMain.vec_players_selected[boardMain.getCurrPlayer()]->getName()){
                //             cout << "You own this property, nice!" << endl;
                //         } else { //owned by other player
                //             cout << "This buliding is owned, please pay [...] [$...]. "; 
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
                //boardMain.stateOfBoardChange(); //notifies there is change in display 
                //boardMain.notifyObservers(); //notifies there is change in display 
            }else if (command == "save"){ 
                string filename;
                cin >> filename;
                while (filename == "") {
                    cout << "Not a valid filename, please input the filename again: " << endl;
                    cin >> filename;
                }
                ofstream f{filename};
                f << "INSERT THE GAME INFO HERE" << endl; //GIVE ALL GAME INFO HERE; *** // !!
                f.close(); 
            }else if (command == "next"){
                cout << "prev: " << boardMain.getCurrPlayer() << endl;
                int numPlayers = boardMain.getNumPlayers();
                boardMain.setCurrPlayer(boardMain.getCurrPlayer() + 1);
                if (boardMain.getCurrPlayer() > numPlayers){ //gives turn back to the first player after the last player calls "next"
                    boardMain.setCurrPlayer(0);
                }
                cout << "new: " << boardMain.getCurrPlayer()<< endl;
            }else if (command == "trade"){
                //trade(); //IMPLEMENT
            }else if (command == "improvements"){
                //improvements(); //IMPLEMENT
            }else if (command == "mortgage"){
                //mortgage(); //IMPLEMENT
            } else if (command == "bankrupt"){
                //bankrupt(); 
            } else {
                cout << "Not a valid command, please try again: " << endl;
            }
            //} // switch
        } // while
    } // else 
}
