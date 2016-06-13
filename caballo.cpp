#include "caballo.h"
#include "pieza.h"
#include <string> 
#include <cmath>
using std::string;


Caballo::Caballo(string color,int x,int y, char tipo,bool isViva): Pieza(color,x,y,tipo,isViva){
}

Caballo::~Caballo(){
}

bool Caballo::mover(Pieza** p,int moveX,int moveY){

	int comerpieza=32;
	for(int i=0; i<32; i++){

		if(p[i]->getx() == moveX && p[i]->gety()== moveY && p[i]->getColor() != getColor()){
			comerpieza = i;
			break;
		}
	}

	if(sqrt(pow(moveX-getx(),2)+pow(moveY-gety(),2)) == sqrt(5)){
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