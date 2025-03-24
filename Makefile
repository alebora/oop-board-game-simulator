run:
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g -c Board.cc Board-Impl.cc Player.cc Player-Impl.cc building.cc building-impl.cc observer.cc subject.cc subject-Impl.cc main.cc
	g++-14.2.0 -std=c++20 -fmodules-ts -Wall -g *.o -o test1
	./test1 
