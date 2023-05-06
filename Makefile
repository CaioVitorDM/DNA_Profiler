main: main.o perfil.o functions.o
	g++ -Wall -pedantic -std=c++17 -Iinclude -o ./bin/DNA_profiler main.o perfil.o functions.o

main.o: src/main.cpp
	g++ -std=c++17 -c src/main.cpp -Iinclude

functions.o: src/functions.cpp
	g++ -std=c++17 -c src/functions.cpp -Iinclude

perfil.o: src/perfil.cpp
	g++ -std=c++17 -c src/perfil.cpp -Iinclude