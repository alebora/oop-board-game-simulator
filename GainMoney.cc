export module GainMoney;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;
import Event;
import Player;
import PRNG;


export class GainMoney : public Event {
    int amount;
    public:
        GainMoney(int amount);
        void execute(Player& player) override;
};

