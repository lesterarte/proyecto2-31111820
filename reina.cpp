#include "reina.h"
#include "pieza.h"
#include <string> 
#include <cmath>
#include <ncurses.h>
using std::string;
using std::abs; 

Reina::Reina(string color,int x,int y, char tipo,bool isViva): Pieza(color,x,y,tipo,isViva){
}

Reina::~Reina(){
}

bool Reina::mover(Pieza** p,int moveX,int moveY){
	
	int comerPieza =32; 
	for(int i=0; i<32; i++){
		if(p[i]->getx() == moveX && p[i]->gety() == moveY && p[i]-> getIsViva()){

			if(p[i]->getColor() == getColor()){

				comerPieza=33;
			}
			else{
				comerPieza = i; 
			}
		}
	}

	if((abs(moveX-getx()) == abs(moveY-gety())) || moveX == getx() || moveY == gety()){

		if(comerPieza <32){
			setx(moveX);
			sety(moveY);
			p[comerPieza]->setIsViva(false);
			return true;
		}
		else if(comerPieza == 32){
			setx(moveX);
			sety(moveY);
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false; 
	}
} 
