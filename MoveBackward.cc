export module MoveBackward;
import Event;
import Player;
import PRNG;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;

// #include "observer.h"
// #include "info.h"


export class MoveBackward : public Event {
    int spaces;
    public:
        MoveBackward(int spaces);
        void execute(Player& player) override;
};

