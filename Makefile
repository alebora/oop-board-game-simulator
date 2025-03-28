libs: 
	g++-14.2.0 -std=c++20 -fmodules-ts -c -x c++-system-header iostream sstream fstream vector memory ctime map algorithm cstddef iomanip cstdint cassert string

run:
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g -c Board.cc Board-Impl.cc Player.cc Player-Impl.cc building.cc building-impl.cc observer.cc subject.cc subject-Impl.cc main.cc
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g *.o -o test1
	./test1 

run2:
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g -c Board.cc Board-Impl.cc Player.cc Player-Impl.cc building.cc building-impl.cc ownable.cc ownable-impl.cc gym.cc gym-impl.cc observer.cc subject.cc subject-Impl.cc main.cc
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g *.o -o test1
	./test1 

run3:
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g -c Board.cc Board-Impl.cc Player.cc Player-Impl.cc building.cc building-impl.cc Unownable.cc Unownable-impl.cc ownable.cc ownable-impl.cc gym.cc gym-impl.cc observer.cc subject.cc subject-Impl.cc main.cc
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g *.o -o test1
	./test1 

run4:
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g -c Board.cc Board-Impl.cc Player.cc Player-Impl.cc building.cc building-impl.cc Unownable.cc Unownable-impl.cc ownable.cc ownable-impl.cc gym.cc gym-impl.cc observer.cc subject.cc subject-Impl.cc prng.cc Event.cc MoveForward.cc MoveForward-impl.cc MoveBackward.cc MoveBackward-impl.cc GainMoney.cc GainMoney-impl.cc LoseMoney.cc LoseMoney-impl.cc GoToCollectOSAP.cc GoToCollectOSAP-impl.cc main.cc
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g *.o -o test1
	./test1 

run5:
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g -c Board.cc Board-Impl.cc Player.cc Player-Impl.cc building.cc building-impl.cc Unownable.cc Unownable-impl.cc ownable.cc ownable-impl.cc gym.cc gym-impl.cc residence.cc residence-impl.cc academic.cc academic-impl.cc observer.cc subject.cc subject-Impl.cc prng.cc Event.cc MoveForward.cc MoveForward-impl.cc MoveBackward.cc MoveBackward-impl.cc GainMoney.cc GainMoney-impl.cc LoseMoney.cc LoseMoney-impl.cc GoToCollectOSAP.cc GoToCollectOSAP-impl.cc main.cc
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g *.o -o test1
	./test1 

test:
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g -c Board.cc Board-Impl.cc Player.cc Player-Impl.cc building.cc building-impl.cc Unownable.cc Unownable-impl.cc ownable.cc ownable-impl.cc gym.cc gym-impl.cc residence.cc residence-impl.cc academic.cc academic-impl.cc observer.cc subject.cc subject-Impl.cc prng.cc Event.cc MoveForward.cc MoveForward-impl.cc MoveBackward.cc MoveBackward-impl.cc GainMoney.cc GainMoney-impl.cc LoseMoney.cc LoseMoney-impl.cc GoToCollectOSAP.cc GoToCollectOSAP-impl.cc main.cc
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g *.o -o test1
	./test1 -load test.txt

