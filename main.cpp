#include <ncurses.h>
#include <string>
#include "pieza.h"
#include "arfil.h"
#include "rey.h"
#include "reina.h"
#include "peon.h"
#include "torre.h"
#include "caballo.h"
#include <cmath>
#include <stdlib.h>

int mapainicial();
void iniciarpiezas(Pieza**);
void eliminarPiezas(Pieza**);
void dibujarpiezas(Pieza**);
void borrarmapa();
void montarpartidaGuardada(Pieza**);
void guardarPartidaJugada(Pieza**);
int positionPiece(Pieza**,int,int);

int main(int argc, char*argv[])
{
	char seleccionMenu;
	bool quienEstaJugando = true;
	int contandoVAloresEntrada=0;
	char guardaCoordenadasAMover[6];
	char tomandoValoresEntrada;
	char salirDelTablero;
	Pieza* arr[32];	
	initscr();
	refresh();

	start_color();
	attron(A_BOLD);
	scrollok(curscr,TRUE);
	init_pair(1, COLOR_RED,     COLOR_BLACK);
    init_pair(2, COLOR_GREEN,   COLOR_BLACK);
    init_pair(3, COLOR_CYAN,    COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_WHITE,   COLOR_BLACK);
    init_pair(7,COLOR_WHITE, COLOR_BLACK);
    bkgd(COLOR_PAIR(7) | A_BOLD);

    attron(COLOR_PAIR(3));
	mvprintw(17,35,"----------------------------BIENVENIDO--------------------------------");
	mvprintw(18,35,"-------------------------------MENU-----------------------------------");
	mvprintw(20,35,"		1 - JUGAR PARTIDA");
	mvprintw(21,35,"		2 - CARGAR PARTIDA");
	mvprintw(22,35,"		3 - SALIR");
	attroff(COLOR_PAIR(3));
	move(23,48);
	noecho(); 

	while(seleccionMenu != '1' && seleccionMenu != '2' && seleccionMenu != '3'){

		seleccionMenu = getch();

		if(seleccionMenu == '1'){
			clear();
			mapainicial();
			iniciarpiezas(arr);
			dibujarpiezas(arr);
						
			while(salirDelTablero != 'S' && salirDelTablero != 's' ){
				attron(COLOR_PAIR(2));
				move(19,112);
				while(quienEstaJugando == true){
					while(contandoVAloresEntrada<5){

						noecho();
						tomandoValoresEntrada = getch();
					
						if(contandoVAloresEntrada == 0  || contandoVAloresEntrada == 3){

							if((tomandoValoresEntrada >= 65) && (tomandoValoresEntrada <= 72)){

								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada; 
								contandoVAloresEntrada++;
							}
						}

						if(contandoVAloresEntrada == 1 || contandoVAloresEntrada == 4)
						{
							if((tomandoValoresEntrada >= 49) && (tomandoValoresEntrada <= 56)){

								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada;
								contandoVAloresEntrada++; 
							}
						}
						if(contandoVAloresEntrada == 2)
						{
							if(tomandoValoresEntrada == 45)
							{
								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada;
								contandoVAloresEntrada++; 
							}
						}	
					}//fin while para validacion de entrada
					attroff(COLOR_PAIR(2));
					contandoVAloresEntrada=0;
					int ubicacionPieza = positionPiece(arr,(guardaCoordenadasAMover[0])-'A',(guardaCoordenadasAMover[1])-'1');
					if( ubicacionPieza < 32 && arr[ubicacionPieza]->getColor() == "Blanca" 
						&& arr[ubicacionPieza]->mover(arr,(guardaCoordenadasAMover[3])-'A',(guardaCoordenadasAMover[4])-'1')){

						borrarmapa();
						dibujarpiezas(arr);
						mvprintw(19,112,"             ");	
						move(22,112);
						quienEstaJugando = false;								
					}
					else{
						attron(COLOR_PAIR(1));
						mvprintw(26,90,"MOVIMIENTO INCORRECTO");
						attroff(COLOR_PAIR(1));
						getch();
						mvprintw(26,90,"                      ");
						mvprintw(19,112,"             ");
						move(19,112);
					}
				}//while final del primer jugador jugador 
			
				contandoVAloresEntrada=0;
				// ------------------------------------------------- movimiento negras----------------------------------- 
				while(quienEstaJugando == false){
					attron(COLOR_PAIR(4));
					while(contandoVAloresEntrada<5){

						noecho();
						tomandoValoresEntrada = getch();
					
						if(contandoVAloresEntrada == 0  || contandoVAloresEntrada == 3){

							if((tomandoValoresEntrada >= 65) && (tomandoValoresEntrada <= 72)){

								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada; 
								contandoVAloresEntrada++;
							}
						}

						if(contandoVAloresEntrada == 1 || contandoVAloresEntrada == 4)
						{
							if((tomandoValoresEntrada >= 49) && (tomandoValoresEntrada <= 56)){

								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada;
								contandoVAloresEntrada++; 
							}
						}
						if(contandoVAloresEntrada == 2)
						{
							if(tomandoValoresEntrada == 45)
							{
								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada;
								contandoVAloresEntrada++; 
							}
						}	
					}//fin while para validacion de entrada
					attroff(COLOR_PAIR(4));
					contandoVAloresEntrada=0;
					int ubicacionPieza = positionPiece(arr,(guardaCoordenadasAMover[0])-'A',(guardaCoordenadasAMover[1])-'1');
					if( ubicacionPieza < 32 && arr[ubicacionPieza]->getColor() == "Negra" 
						&& arr[ubicacionPieza]->mover(arr,(guardaCoordenadasAMover[3])-'A',(guardaCoordenadasAMover[4])-'1')){

						borrarmapa();
						dibujarpiezas(arr);
						mvprintw(19,112,"             ");	
						move(22,112);
						quienEstaJugando = true;								
					}
					else{
						attron(COLOR_PAIR(1));
						mvprintw(26,90,"MOVIMIENTO INCORRECTO");
						attroff(COLOR_PAIR(1));
						getch();
						mvprintw(26,90,"                      ");
						mvprintw(22,112,"             ");
						move(22,112);
					}
				}//while final del segundo jugador
				attron(COLOR_PAIR(1));
				mvprintw(26,90,"SALIR?? (S/s)");
				mvprintw(27,90,"Cualquier tecla para continuar");
				attroff(COLOR_PAIR(1));
				salirDelTablero = getch();
				mvprintw(26,90,"                     ");
				mvprintw(27,90,"                                      ");
				mvprintw(22,112,"             ");
				guardarPartidaJugada(arr);
			}//while de la opcion de jugar otra vez o salir 	
			guardarPartidaJugada(arr);
		}// fin de la opcion de jugar nueva partida

		if(seleccionMenu == '2'){

			clear();
			montarpartidaGuardada(arr);
			mapainicial();
			dibujarpiezas(arr);
			
			while(salirDelTablero != 'S' && salirDelTablero != 's' ){
				move(19,112);
				while(quienEstaJugando == true){
					attron(COLOR_PAIR(2));
					while(contandoVAloresEntrada<5){

						noecho();
						tomandoValoresEntrada = getch();
					
						if(contandoVAloresEntrada == 0  || contandoVAloresEntrada == 3){

							if((tomandoValoresEntrada >= 65) && (tomandoValoresEntrada <= 72)){

								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada; 
								contandoVAloresEntrada++;
							}
						}

						if(contandoVAloresEntrada == 1 || contandoVAloresEntrada == 4)
						{
							if((tomandoValoresEntrada >= 49) && (tomandoValoresEntrada <= 56)){

								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada;
								contandoVAloresEntrada++; 
							}
						}
						if(contandoVAloresEntrada == 2)
						{
							if(tomandoValoresEntrada == 45)
							{
								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada;
								contandoVAloresEntrada++; 
							}
						}	
					}//fin while para validacion de entrada

					attroff(COLOR_PAIR(2));

					contandoVAloresEntrada=0;
					int ubicacionPieza = positionPiece(arr,(guardaCoordenadasAMover[0])-'A',(guardaCoordenadasAMover[1])-'1');

					if( ubicacionPieza < 32 && arr[ubicacionPieza]->getColor() == "Blanca" 
						&& arr[ubicacionPieza]->mover(arr,(guardaCoordenadasAMover[3])-'A',(guardaCoordenadasAMover[4])-'1')){

						borrarmapa();
						dibujarpiezas(arr);
						mvprintw(19,112,"             ");	
						move(22,112);
						quienEstaJugando = false;								
					}
					else{
						attron(COLOR_PAIR(1));
						mvprintw(26,90,"MOVIMIENTO INCORRECTO");
						attroff(COLOR_PAIR(1));
						getch();
						mvprintw(26,90,"                      ");
						mvprintw(19,112,"             ");
						move(19,112);
					}
				}//while final del primer jugador jugador 
			
				contandoVAloresEntrada=0;
				// ------------------------------------------------- movimiento negras----------------------------------- 
				while(quienEstaJugando == false){
					attron(COLOR_PAIR(4));
					while(contandoVAloresEntrada<5){

						noecho();
						tomandoValoresEntrada = getch();
					
						if(contandoVAloresEntrada == 0  || contandoVAloresEntrada == 3){

							if((tomandoValoresEntrada >= 65) && (tomandoValoresEntrada <= 72)){

								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada; 
								contandoVAloresEntrada++;
							}
						}

						if(contandoVAloresEntrada == 1 || contandoVAloresEntrada == 4)
						{
							if((tomandoValoresEntrada >= 49) && (tomandoValoresEntrada <= 56)){

								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada;
								contandoVAloresEntrada++; 
							}
						}
						if(contandoVAloresEntrada == 2)
						{
							if(tomandoValoresEntrada == 45)
							{
								addch(tomandoValoresEntrada);
								echo();
								guardaCoordenadasAMover[contandoVAloresEntrada]= tomandoValoresEntrada;
								contandoVAloresEntrada++; 
							}
						}	
					}//fin while para validacion de entrada
					attroff(COLOR_PAIR(4));
					contandoVAloresEntrada=0;
					int ubicacionPieza = positionPiece(arr,(guardaCoordenadasAMover[0])-'A',(guardaCoordenadasAMover[1])-'1');
					if( ubicacionPieza < 32 && arr[ubicacionPieza]->getColor() == "Negra" 
						&& arr[ubicacionPieza]->mover(arr,(guardaCoordenadasAMover[3])-'A',(guardaCoordenadasAMover[4])-'1')){

						borrarmapa();
						dibujarpiezas(arr);
						mvprintw(19,112,"             ");	
						move(22,112);
						quienEstaJugando = true;								
					}
					else{
						attron(COLOR_PAIR(1));
						mvprintw(26,90,"MOVIMIENTO INCORRECTO");
						attroff(COLOR_PAIR(1));
						getch();
						mvprintw(26,90,"                      ");
						mvprintw(22,112,"             ");
						move(22,112);
					}
				}//while final del segundo jugador
				attron(COLOR_PAIR(1));
				mvprintw(26,90,"SALIR?? (S/s)");
				mvprintw(27,90,"Cualquier tecla para continuar");
				attroff(COLOR_PAIR(1));
				salirDelTablero = getch();
				mvprintw(26,90,"                     ");
				mvprintw(27,90,"                                      ");
				mvprintw(22,112,"             ");
				guardarPartidaJugada(arr);
			}
		}

		if(seleccionMenu == '3'){
			endwin();
			exit(0);
		}
	}

	eliminarPiezas(arr);
	endwin();			
	return 0;
}

int mapainicial()
{
	//titulo del juego 
	attron(COLOR_PAIR(1));
	mvprintw(1,40,"*"); 
	mvprintw(2,39,"* *"); 
	mvprintw(3,38,"*****"); 
	mvprintw(4,37,"*     *"); 
	mvprintw(5,36,"*       *"); 
	
	mvprintw(1,53,"*"); 
	mvprintw(2,53,"*"); 
	mvprintw(3,53,"*"); 
	mvprintw(4,53,"*"); 
	mvprintw(5,52,"*"); 
	mvprintw(5,51,"*"); 
	mvprintw(5,50,"*"); 
	mvprintw(4,48,"*"); 

	mvprintw(1,59,"******");
	mvprintw(2,59,"*");
	mvprintw(3,59,"****");
	mvprintw(4,59,"*");
	mvprintw(5,59,"******");
	
	mvprintw(1,69,"* *");
	mvprintw(2,69,"*   *");
	mvprintw(3,69,"*    *");
	mvprintw(4,69,"*   *");
	mvprintw(5,69,"* *");

	mvprintw(1,79,"* *");
	mvprintw(2,79,"*   *");
	mvprintw(3,79,"*  *");
	mvprintw(4,79,"*   *");
	mvprintw(5,79,"*     *");

	mvprintw(1,89,"******");
	mvprintw(2,89,"*");
	mvprintw(3,89,"****");
	mvprintw(4,89,"*");
	mvprintw(5,89,"******");

	mvprintw(1,99,"*******");
	mvprintw(2,99,"     *");
	mvprintw(3,99,"   *");
	mvprintw(4,99,"  *");
	mvprintw(5,99,"*******");
	attroff(COLOR_PAIR(1));

	//damero indices
	
    attron(COLOR_PAIR(2));
	mvprintw(12,25,"+------+------+------+------+------+------+------+------+");
	mvprintw(13,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(14,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(15,25,"|------|------|------|------|------|------|------|------|");
	mvprintw(16,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(17,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(18,25,"|------|------|------|------|------|------|------|------|");
	mvprintw(19,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(20,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(21,25,"|------|------|------|------|------|------|------|------|");
	mvprintw(22,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(23,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(24,25,"|------|------|------|------|------|------|------|------|");
	mvprintw(25,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(26,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(27,25,"|------|------|------|------|------|------|------|------|");
	mvprintw(28,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(29,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(30,25,"|------|------|------|------|------|------|------|------|");
	mvprintw(31,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(32,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(33,25,"|------|------|------|------|------|------|------|------|");
	mvprintw(34,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(35,25,"|      |      |      |      |      |      |      |      |");
	mvprintw(36,25,"+------+------+------+------+------+------+------+------+");
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	mvprintw(9,25,"+------+------+------+------+------+------+------+------+"); 
	mvprintw(10,25,"|   1  |   2  |   3  |   4  |   5  |   6  |   7  |  8   |"); 
	mvprintw(11,25,"+------+------+------+------+------+------+------+------+");
	mvprintw(37,25,"+------+------+------+------+------+------+------+------+"); 
	mvprintw(38,25,"|   1  |   2  |   3  |   4  |   5  |   6  |   7  |  8   |"); 
	mvprintw(39,25,"+------+------+------+------+------+------+------+------+");
	mvprintw(12,19,"+---+"); 
	mvprintw(13,19,"| A |"); 
	mvprintw(14,19,"|   |"); 
	mvprintw(15,19,"+---+"); 
	mvprintw(16,19,"| B |"); 
	mvprintw(17,19,"|   |"); 
	mvprintw(18,19,"+---+"); 
	mvprintw(19,19,"| C |"); 
	mvprintw(20,19,"|   |"); 
	mvprintw(21,19,"+---+"); 
	mvprintw(22,19,"| D |"); 
	mvprintw(23,19,"|   |"); 
	mvprintw(24,19,"+---+"); 
	mvprintw(25,19,"| E |"); 
	mvprintw(26,19,"|   |"); 
	mvprintw(27,19,"+---+"); 
	mvprintw(28,19,"| F |"); 
	mvprintw(29,19,"|   |"); 
	mvprintw(30,19,"+---+"); 
	mvprintw(31,19,"| G |"); 
	mvprintw(32,19,"|   |"); 
	mvprintw(33,19,"+---+"); 
	mvprintw(34,19,"| H |"); 
	mvprintw(35,19,"|   |"); 
	mvprintw(36,19,"+---+"); 

	mvprintw(12,83,"+---+"); 
	mvprintw(13,83,"| A |"); 
	mvprintw(14,83,"|   |"); 
	mvprintw(15,83,"+---+"); 
	mvprintw(16,83,"| B |"); 
	mvprintw(17,83,"|   |"); 
	mvprintw(18,83,"+---+"); 
	mvprintw(19,83,"| C |"); 
	mvprintw(20,83,"|   |"); 
	mvprintw(21,83,"+---+"); 
	mvprintw(22,83,"| D |"); 
	mvprintw(23,83,"|   |"); 
	mvprintw(24,83,"+---+"); 
	mvprintw(25,83,"| E |"); 
	mvprintw(26,83,"|   |"); 
	mvprintw(27,83,"+---+"); 
	mvprintw(28,83,"| F |"); 
	mvprintw(29,83,"|   |"); 
	mvprintw(30,83,"+---+"); 
	mvprintw(31,83,"| G |"); 
	mvprintw(32,83,"|   |"); 
	mvprintw(33,83,"+---+"); 
	mvprintw(34,83,"| H |"); 
	mvprintw(35,83,"|   |"); 
	mvprintw(36,83,"+---+"); 
	attroff(COLOR_PAIR(3));


	mvprintw(13,90,"J1 = Jugador 1 ");
	mvprintw(14,90,"J2 = Jugador 2 ");
	mvprintw(15,90,"Ejemplo Movimiento: A2-D3");
	mvprintw(19,90,"MOVIMIENTO JUGADOR 1: ");
	mvprintw(22,90,"MOVIMIENTO JUGADOR 2: ");
}//fin mapeo 

void iniciarpiezas(Pieza** p){

	
	p[0]= new Peon("Negra",1,7,'P',true);
	p[1]= new Peon("Negra",1,0,'P',true);
	p[2]= new Peon("Negra",1,1,'P',true);
	p[3]= new Peon("Negra",1,2,'P',true);
	p[4]= new Peon("Negra",1,3,'P',true);
	p[5]= new Peon("Negra",1,4,'P',true);
	p[6]= new Peon("Negra",1,5,'P',true);
	p[7]= new Peon("Negra",1,6,'P',true);
	p[8]= new Peon("Blanca",6,0,'P',true);
	p[9]= new Peon("Blanca",6,1,'P',true);
	p[10]= new Peon("Blanca",6,2,'P',true);
	p[11]= new Peon("Blanca",6,3,'P',true);
	p[12]= new Peon("Blanca",6,4,'P',true);
	p[13]= new Peon("Blanca",6,5,'P',true);
	p[14]= new Peon("Blanca",6,6,'P',true);
	p[15]= new Peon("Blanca",6,7,'P',true);

	//arfiles

	p[16]= new Arfil("Blanca",7,2,'A',true);
	p[17]= new Arfil("Blanca",7,5,'A',true);
	p[18]= new Arfil("Negra",0,2,'A',true);
	p[19]= new Arfil("Negra",0,5,'A',true);

	//Reyes

	p[20]= new Rey("Blanca",7,3,'K',true);
	p[21]= new Rey("Negra",0,3,'K',true);
	p[22]= new Reina("Blanca",7,4,'Q',true);
	p[23]= new Reina("Negra",0,4,'Q',true);

	//torres
	p[24]= new Torre("Blanca",7,0,'T',true);
	p[25]= new Torre("Blanca",7,7,'T',true);

	p[26]= new Torre("Negra",0,0,'T',true);
	p[27]= new Torre("Negra",0,7,'T',true);

	p[28]= new Caballo("Blanca",7,1,'C',true);
	p[29]= new Caballo("Blanca",7,6,'C',true);
	p[30]= new Caballo("Negra",0,1,'C',true);
	p[31]= new Caballo("Negra",0,6,'C',true);
}
void eliminarPiezas(Pieza** p){

	for (int i=0; i<32; i++){
		delete p[i];
	}
}

void dibujarpiezas(Pieza** p)
{
	for(int i=0; i<32; i++)
	{
		if (p[i]->getIsViva()){

			if ((p[i]->getColor()) == "Blanca")
			{
				if (p[i]->getTipo()=='T'){
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), " Rook ");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J1");
				}
				if (p[i]->getTipo()=='C'){
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "Knight");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J1");
				}
				if (p[i]->getTipo()=='A'){
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "Bishop");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J1");
				}
				if (p[i]->getTipo()=='K'){
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), " King");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J1");
				}
				if (p[i]->getTipo()=='Q'){
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), " Queen");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J1");
				}
				if (p[i]->getTipo()=='P'){
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), " Pawn");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J1");
				}
			}
			else{
				if (p[i]->getTipo()=='T'){
					attron(COLOR_PAIR(6));
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), " Rook ");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J2");
					attroff(COLOR_PAIR(6));
				}
				if (p[i]->getTipo()=='C'){
					attron(COLOR_PAIR(6));
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "Knight");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J2");
					attroff(COLOR_PAIR(6));
				}
				if (p[i]->getTipo()=='A'){
					attron(COLOR_PAIR(6));
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "Bishop");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J2");
					attroff(COLOR_PAIR(6));
				}
				if (p[i]->getTipo()=='K'){
					attron(COLOR_PAIR(6));
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), " King");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J2");
					attroff(COLOR_PAIR(6));
				}
				if (p[i]->getTipo()=='Q'){
					attron(COLOR_PAIR(6));
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), " Queen");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J2");
					attroff(COLOR_PAIR(6));
				}
				if (p[i]->getTipo()=='P'){
					attron(COLOR_PAIR(6));
					mvprintw((13 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), " Pawn");
					mvprintw((14 + (p[i]->getx()*3)),(26 + (p[i]->gety()*7)), "  J2");
					attroff(COLOR_PAIR(6));
				}
			}
		}
	}
}
	
void borrarmapa()
{
	for(int i=0; i<32; i++)
	{
		for(int j=0; j<8; j++)
		{
			for(int k=0; k<8; k++)
			{
				mvprintw((13 + (k*3)),(26 + (j*7)), "      ");
				mvprintw((14 + (k*3)),(26 + (j*7)), "      ");		
			}
		}
	}
}

int positionPiece(Pieza** p, int inX,int inY){

	int position = 32;
	for(int i=0; i<32; i++){

		if(p[i]->getx() == inX &&  p[i]->gety() == inY && p[i]->getIsViva()){
			return i;
		}
	}

	return position;
}

void montarpartidaGuardada(Pieza**  p ){

	char tempGuardar[32][5];
	
	FILE *guardarpartida; 
	
	guardarpartida = fopen("partidaGuardada.txt","r"); 

	for (int i = 0; i < 32; i++){

		for(int j=0; j<5;j++){

			fread(&(tempGuardar[i][j]),sizeof(char),1,guardarpartida);
		}
	}

	fclose(guardarpartida);

	

	//crear objetos con partida guardada

	for(int i = 0; i<32; i++){
		
		if(tempGuardar[i][0] == 'N'){
			if(tempGuardar[i][3] == 'P' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Peon("Negra",tempx,tempy,'P',true);
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Peon("Negra",tempx,tempy,'P',false);
				}
			}

			if(tempGuardar[i][3] == 'A' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Arfil("Negra",tempx,tempy,'A',true);

				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Arfil("Negra",tempx,tempy,'A',false);
				}
			}

			if(tempGuardar[i][3] == 'K' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Rey("Negra",tempx,tempy,'K',true);
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Rey("Negra",tempx,tempy,'K',false);
				}
			}

			if(tempGuardar[i][3] == 'T' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Torre("Negra",tempx,tempy,'T',true);
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Torre("Negra",tempx,tempy,'T',false);
				}
			}

			if(tempGuardar[i][3] == 'C' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Caballo("Negra",tempx,tempy,'C',true);
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Caballo("Negra",tempx,tempy,'C',false);
				}
			}
			if(tempGuardar[i][3] == 'Q' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Reina("Negra",tempx,tempy,'Q',true);
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Reina("Negra",tempx,tempy,'Q',false);
				}
			}
		}//fin si son negras
		else{

			if(tempGuardar[i][3] == 'P' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Peon("Blanca",tempx,tempy,'P',true);
					
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Peon("Blanca",tempx,tempy,'P',false);
					
				}
			}

			if(tempGuardar[i][3] == 'A' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Arfil("Blanca",tempx,tempy,'A',true);
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Arfil("Blanca",tempx,tempy,'A',false);
				}
			}

			if(tempGuardar[i][3] == 'K' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Rey("Blanca",tempx,tempy,'K',true);
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Rey("Blanca",tempx,tempy,'K',false);
				}
			}

			if(tempGuardar[i][3] == 'T' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Torre("Blanca",tempx,tempy,'T',true);
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Torre("Blanca",tempx,tempy,'T',false);
				}
			}

			if(tempGuardar[i][3] == 'C' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Caballo("Blanca",tempx,tempy,'C',true);
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Caballo("Blanca",tempx,tempy,'C',false);
				}
			}
			if(tempGuardar[i][3] == 'Q' ){
				if(tempGuardar[i][4] == 'S'){
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Reina("Blanca",tempx,tempy,'Q',true);
				}
				else{
					int tempx = tempGuardar[i][1]-48;
					int tempy = tempGuardar[i][2]-48;
					p[i] = new Reina("Blanca",tempx,tempy,'Q',false);
				}
			}
		}
	}
}

void guardarPartidaJugada(Pieza** p){

	char tempGuardar [32][5];

	for(int i =0; i<32; i++){
		if(p[i]->getColor() == "Blanca"){
			tempGuardar[i][0] = 'B';
		} 
		else{
			tempGuardar[i][0] = 'N';
		}
		
		tempGuardar[i][1] = p[i]->getx() +'0';
		tempGuardar[i][2] = p[i]->gety() + '0';
		tempGuardar[i][3] = p[i]->getTipo();
		if(p[i]->getIsViva()){
			tempGuardar[i][4] = 'S';
		}
		else{
			tempGuardar[i][4] = 'n';
		}
	}
	
	FILE *guardarpartida; 
	
	guardarpartida = fopen("partidaGuardada.txt","w"); 

	for (int i = 0; i < 32; i++){

		for(int j=0; j<5;j++){

			fwrite(&(tempGuardar[i][j]),sizeof(char),1,guardarpartida);
		}
	}
	fclose(guardarpartida);	
}
