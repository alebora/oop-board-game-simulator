export module Unownable;
import Player;
import Event;
import OnDcTimsLine;
import EventFactory;
import Building;

import <cstddef>; // defines size_t i.e. an unsigned int
import <iostream>;
import <string>;
import <memory>;



export class Unownable : public Building {

  public:
    Unownable(std::string BName, size_t pos);
    void printLongName(int lineNum);
    void triggerEvent(Player& player);
    virtual void printName() override;
    virtual void printLine(int lineNum) override;

};

