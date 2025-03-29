export module LoseMoney;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;
import Event;
import Player;
import PRNG;
// #include "observer.h"
// #include "info.h"


export class LoseMoney : public Event {
    int amount;
    public:
        LoseMoney(int amount);
        void execute(Player& player) override;
};

