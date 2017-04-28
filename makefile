all: Project2

Project2: main.o Map.o tree.o MapItr.o
	g++ -std=c++11 -Wall main.o Map.o tree.o MapItr.o -o Project2

main.o: main.cpp Map.cpp
	g++ -std=c++11 -c -Wall main.cpp Map.cpp

Map.o: Map.cpp tree.cpp MapItr.cpp
	g++ -std=c++11 -c -Wall Map.cpp tree.cpp MapItr.cpp

tree.o: tree.cpp
	g++ -std=c++11 -c -Wall tree.cpp

MapItr.o: MapItr.cpp
	g++ -std=c++11 -c -Wall MapItr.cpp
