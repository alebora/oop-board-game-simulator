export module Event;
import Player;
import PRNG;
import <cstddef>; // defines size_t i.e. an unsigned int
import <cstdint>;
import <ctime>;
import <iostream>;
import <string>;
import <vector>;

// #include "subject.h"
// #include "observer.h"
// #include "info.h"

// class Ownable;

export class Event {
    protected:
        const int totalCups = 4;
        int activeCups = 0;

    public:
        virtual void execute(Player& player) = 0;  // Abstract method to execute event effect
        virtual ~Event() = default;
};

