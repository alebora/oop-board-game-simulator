module OnDcTimsLine;
// #include "observer.h"
import <iostream>;
import <vector>;
import <algorithm>;
import <string>;
import <iomanip>;
import <memory>;
using namespace std;

void OnDcTimsLine::execute(Player& player) {
    if (player.ifInJail()){       // player.inJail == 0   
        cout << "Your passed turns in Line: " << player.timesInJail() + 1 << endl; 
        if (player.timesInJail() == 2){
            size_t steps;
            if (player.cups() > 0){
                char response;
                while (true){
                    std::cout << "Choose a way to leave the line: Roll dices (r), Pay $50 (p), Use a Roll UP the Rim Cup (c)" << std::endl;
                    std::cin >> response;
                    switch (response) {
                        case 'r': 
                            steps = player.rollDouble();
                            if (steps <= 12){
                                player.move(steps, true);
                            } else {
                                std::cout << "Choose a way to leave the line: Pay $50 (p), Use a Roll UP the Rim Cup (c)" << std::endl;
                                std::cin >> response;
                                while (true){
                                    switch (response) {
                                        case 'p': 
                                            player.loseMoney(50);
                                            break;
                                        case 'c': 
                                            player.loseCup();
                                            activeCups -= 1;
                                            break;
                                        default:
                                            std::cout << "Invalid input!" << std::endl;
                                            std::cout << "Choose a way to leave the line: Pay $50 (p), Use a Roll UP the Rim Cup (c)" << std::endl;
                                            std::cin >> response;
                                            continue;
                                    }
                                }
                                player.move(steps - 12, true);
                            }
                            player.setFree();
                            std::cout << "You leave the line!" << std::endl;
                            break;
                        case 'p': 
                            player.loseMoney(50);
                            player.move(player.rollDice(), true);
                            player.setFree();
                            std::cout << "You leave the line!" << std::endl;
                            break;
                        case 'c': 
                            player.loseCup();
                            activeCups -= 1;
                            player.move(player.rollDice(), true);
                            player.setFree();
                            std::cout << "You leave the line!" << std::endl;
                            break;
                        default:
                            std::cout << "Invalid input!" << std::endl;
                            continue;
                    }
                }
            } else {
                char response;
                while (true){
                    std::cout << "Choose a way to leave the line: Roll dices (r), Pay $50 (p)" << std::endl;
                    std::cin >> response;
                    switch (response) {
                        case 'r': 
                            steps = player.rollDouble();
                            if (steps <= 12){
                                player.move(steps, true);
                            } else {
                                std::cout << "You have to pay $50 to leave the line!" << std::endl;
                                std::cin >> response;
                                player.loseMoney(50);
                                player.move(steps - 12, true);
                            }
                            player.setFree();
                            std::cout << "You leave the line!" << std::endl;
                            break;
                        case 'p': 
                            player.loseMoney(50);
                            player.move(player.rollDice(), true);
                            player.setFree();
                            std::cout << "You leave the line!" << std::endl;
                            break;
                        default:
                            std::cout << "Invalid input!" << std::endl;
                            continue;
                    }
                }
            } 
        } else {
            size_t steps;
            if (player.cups() > 0){
                char response;
                while (true){
                    std::cout << "Choose a way to leave the line: Roll dices (r), Pay $50 (p), Use a Roll UP the Rim Cup (c)" << std::endl;
                    std::cin >> response;
                    switch (response) {
                        case 'r': 
                            steps = player.rollDouble();
                            if (steps <= 12){
                                player.move(steps, true);
                                player.setFree();
                                std::cout << "You leave the line!" << std::endl;
                            } else {
                                player.incJailTurn();
                                std::cout << "Failed to leave the line!" << std::endl;
                            }
                            break;
                        case 'p': 
                            player.loseMoney(50);
                            player.move(player.rollDice(), true);
                            player.setFree();
                            std::cout << "You leave the line!" << std::endl;
                            break;
                        case 'c': 
                            player.loseCup();
                            player.move(player.rollDice(), true);
                            player.setFree();
                            std::cout << "You leave the line!" << std::endl;
                            break;
                        default:
                            std::cout << "Invalid input!" << std::endl;
                            continue;
                    }
                }
            } else {
                char response;
                while (true){
                    std::cout << "Choose a way to leave the line: Roll dices (r), Pay $50 (p)" << std::endl;
                    std::cin >> response;
                    switch (response) {
                        case 'r': 
                            steps = player.rollDouble();
                            if (steps <= 12){
                                player.move(steps, true);
                            } else {
                                player.incJailTurn();
                                std::cout << "Failed to leave the line!" << std::endl;
                            }
                            break;
                        case 'p': 
                            player.loseMoney(50);
                            player.move(player.rollDice(), true);
                            player.setFree();
                            std::cout << "You leave the line!" << std::endl;
                            break;
                        default:
                            std::cout << "Invalid input!" << std::endl;
                            continue;
                    }
                }
            } 
        }
    } else {
        cout << "You are not in Line! You can continue!" << endl;
    }
    // std::cout << "You gained $" << amount << "!" << std::endl;
}

