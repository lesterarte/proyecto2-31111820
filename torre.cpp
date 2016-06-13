#include "torre.h"
#include "pieza.h"
#include <string> 
#include <cmath>
using std::string;

Torre::Torre(string color,int x,int y, char tipo, bool isViva): Pieza(color,x,y,tipo,isViva){
}

Torre::~Torre(){
}

bool Torre::mover(Pieza** p, int moveX, int moveY){

	int comerpieza=32;
	for(int i=0; i<32; i++){

		if(p[i]->getx() == moveX && p[i]->gety()== moveY && p[i]->getColor() != getColor()){
			comerpieza = i;
			break;
		}
	}

	if((getx() == moveX || gety() == moveY) && validarSalto(p,moveX,moveY)){
		setx(moveX);
		sety(moveY);
		if(comerpieza<32){
			p[comerpieza]->setIsViva(false);
		}
		return true;
	}
	else{
		return false;
	}
}
bool Torre::validarSalto(Pieza** p, int moveX, int moveY){

	for(int i=0; i<32; i++){

		if((p[i]->getx() == getx() || p[i]->gety() == gety()) && p[i]->getIsViva()){
				
			if(sqrt(pow(moveX-getx(),2)+pow(moveY-gety(),2)) > 
				sqrt(pow(p[i]->getx()-getx(),2)+pow(p[i]->gety()-gety(),2))){

				return false; 
			}
		}
	}
	return true;
}