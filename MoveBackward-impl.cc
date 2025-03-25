module MoveBackward;
import <vector>;
import <algorithm>;
import <string>;
import <iomanip>;
import <memory>;

MoveBackward::MoveBackward(int spaces): spaces{spaces} {}

void MoveBackward::execute(Player& player) {
    if (activeCups < totalCups){
        PRNG prng(12345);  // Initialize PRNG with a seed
        uint32_t randomCup = prng(99);  // Generate a random number in [0,99]
        if (randomCup == 0){
            activeCups += 1;
            player.winCup();
        }
    }
    player.move(spaces, false);
}

