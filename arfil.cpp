#include "arfil.h"
#include "pieza.h"
#include <string> 
using std::string;

Arfil::Arfil(string color,int x,int y, char tipo,bool isViva): Pieza(color,x,y,tipo,isViva){
}

Arfil::~Arfil(){
}

bool Arfil::mover(int moveX, int moveY){

	return true;
}
