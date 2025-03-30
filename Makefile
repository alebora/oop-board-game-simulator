watopoly:
	g++-14.2.0 -std=c++20 -fmodules-ts -c -x c++-system-header algorithm cassert cstddef cstdint ctime fstream iomanip iostream map memory sstream string vector
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g -c prng.cc building.cc building-impl.cc ownable.cc ownable-impl.cc academic.cc academic-impl.cc Player.cc Player-Impl.cc Event.cc MoveForward.cc MoveForward-impl.cc MoveBackward.cc MoveBackward-impl.cc GainMoney.cc GainMoney-impl.cc LoseMoney.cc LoseMoney-impl.cc GoToCollectOSAP.cc GoToCollectOSAP-impl.cc CaughtByTims.cc CaughtByTims-impl.cc OnDcTimsLine.cc OnDcTimsLine-impl.cc EventFactory.cc gym.cc gym-impl.cc residence.cc residence-impl.cc Unownable.cc Unownable-impl.cc observer.cc subject.cc subject-Impl.cc Board.cc Board-Impl.cc main.cc
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g *.o -o watopoly
	./watopoly
