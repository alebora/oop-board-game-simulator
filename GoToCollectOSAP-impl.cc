module GoToCollectOSAP;
// #include "observer.h"
import <vector>;
import <algorithm>;
import <string>;
import <iomanip>;
import <memory>;
import <ctime>;
import <cstdint>;
using namespace std;

void GoToCollectOSAP::execute(Player& player) {
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
<<<<<<< HEAD
    player.getMoney(200);
=======
    player.gainMoney(200);
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
    player.sentTo(0);
    cout << "Go to collect OSAP!" << endl;
    // std::cout << "You gained $" << amount << "!" << std::endl;
}

