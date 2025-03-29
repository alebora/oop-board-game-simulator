module MoveBackward;
// #include "observer.h"
import <vector>;
import <algorithm>;
import <string>;
import <iomanip>;
import <memory>;
import <ctime>;
import <cstdint>;
using namespace std;

MoveBackward::MoveBackward(int spaces): spaces{spaces} {}

void MoveBackward::execute(Player& player) {
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
    player.move(spaces, false);
    cout << "Movebackward: " << spaces << " steps!" << endl;
    // std::cout << player.getName() << " moves forward " << spaces << " spaces!" << std::endl;
}

