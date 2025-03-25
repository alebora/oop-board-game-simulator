module GainMoney;
import <vector>;
import <algorithm>;
import <string>;
import <iomanip>;
import <memory>;

GainMoney::GainMoney(int amount) : amount(amount) {}

void GainMoney::execute(Player& player) {
    if (activeCups < totalCups){
        PRNG prng(12345);  // Initialize PRNG with a seed
        uint32_t randomCup = prng(99);  // Generate a random number in [0,99]
        if (randomCup == 0){
            activeCups += 1;
            player.winCup();
        }
    }
    player.setMoney(amount);
}

