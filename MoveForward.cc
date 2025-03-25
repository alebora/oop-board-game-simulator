export module MoveForward;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;
import Event;
import Player;
import PRNG;


export class MoveForward : public Event {
    int spaces;
    public:
        MoveForward(int spaces);
        void execute(Player& player) override;
};

