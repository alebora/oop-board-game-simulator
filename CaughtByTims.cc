export module CaughtByTims;
<<<<<<< HEAD
=======
import Event;
import Player;
import PRNG;
>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;
<<<<<<< HEAD
import Event;
import Player;
import PRNG;
=======

>>>>>>> fc5d07222dfee5709f5b2587a9f26c92b42d165f
// #include "observer.h"
// #include "info.h"


export class CaughtByTims : public Event {
    public:
        // LoseMoney(int amount) : amount(amount) {}
        void execute(Player& player) override;
};
