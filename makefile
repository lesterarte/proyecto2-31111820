ajedrez: main.o	pieza.o arfil.o
	g++ main.o pieza.o arfil.o -o dale

main.o: main.cpp pieza.h arfil.h
	g++ -c main.cpp

pieza.o: pieza.h pieza.cpp
	g++ -c pieza.cpp

arfil.o: arfil.h arfil.cpp pieza.h
	g++ -c arfil.cpp
