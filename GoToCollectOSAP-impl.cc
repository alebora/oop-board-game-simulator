module GoToCollectOSAP;
import <vector>;
import <algorithm>;
import <string>;
import <iomanip>;
import <memory>;

void GoToCollectOSAP::execute(Player& player) {
    if (activeCups < totalCups){
        PRNG prng(12345);  // Initialize PRNG with a seed
        uint32_t randomCup = prng(99);  // Generate a random number in [0,99]
        if (randomCup == 0){
            activeCups += 1;
            player.winCup();
        }
    }
    player.setMoney(200);
    // player.sentTo(0);  need confirmation from Sasha
}

