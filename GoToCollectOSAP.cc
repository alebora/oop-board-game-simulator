export module GoToCollectOSAP;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;
import Event;
import Player;
import PRNG;


export class GoToCollectOSAP : public Event {
    public:
        void execute(Player& player) override;
};

