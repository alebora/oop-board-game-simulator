module LoseMoney;
// #include "observer.h"
import <vector>;
import <algorithm>;
import <string>;
import <iomanip>;
import <memory>;
import <ctime>;
import <cstdint>;
using namespace std;

LoseMoney::LoseMoney(int amount) : amount(amount) {}

void LoseMoney::execute(Player& player) {
    if (activeCups < totalCups){
        // PRNG prng(12345);  // Initialize PRNG with a seed
        // PRNG prng;
        PRNG prng(static_cast<std::uint32_t>(std::time(0)));  // Seed with current time
        std::uint32_t randomCup = prng(99);  // Generate a random number in [0,99]
        if (randomCup == 0){
            activeCups += 1;
            player.winCup();
            cout << "You win a cup!" << endl;
        }
    }
    cout << "Lose money: $" << amount << endl;
<<<<<<< HEAD
    player.getMoney(-amount);
=======
    player.loseMoney(amount);
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
    // std::cout << "You gained $" << amount << "!" << std::endl;
}

