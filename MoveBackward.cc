export module MoveBackward;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;
import Event;
import Player;
import PRNG;


export class MoveBackward : public Event {
    int spaces;
    public:
        MoveBackward(int spaces);
        void execute(Player& player) override;
};

