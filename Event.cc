export module Event;
import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <vector>;
import Player;
import PRNG;

export class Event {
    protected:
        const int totalCups = 4;
        int activeCups = 0;

    public:
        virtual void execute(Player& player) = 0;  // Abstract method to execute event effect
        virtual ~Event() {}  
};

