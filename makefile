ajedrez: main.o	pieza.o arfil.o rey.o reina.o peon.o torre.o caballo.o 
	g++ main.o pieza.o arfil.o -o dale

main.o: main.cpp pieza.h arfil.h rey.h reina.h peon.h torre.h caballo.h
	g++ -c main.cpp

pieza.o: pieza.h pieza.cpp
	g++ -c pieza.cpp

arfil.o: arfil.h arfil.cpp pieza.h
	g++ -c arfil.cpp

rey.o: rey.h rey.cpp pieza.h
	g++ -c rey.cpp

reina.o: reina.h reina.cpp pieza.h
	g++ -c reina.cpp

peon.o: peon.h peon.cpp pieza.h
	g++ -c peon.cpp

torre.o: torre.h torre.cpp pieza.h
	g++ -c torre.cpp

caballo.o: caballo.h caballo.cpp pieza.h
	g++ -c caballo.cpp
