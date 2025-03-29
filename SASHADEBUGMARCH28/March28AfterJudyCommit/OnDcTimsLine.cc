export module OnDcTimsLine;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;
import <iostream>;
import Event;
import Player;
import PRNG;
// #include "observer.h"
// #include "info.h"


export class OnDcTimsLine : public Event {
    public:
        // LoseMoney(int amount) : amount(amount) {}
        void execute(Player& player) override;
};

