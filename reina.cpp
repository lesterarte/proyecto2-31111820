#include "reina.h"
#include "pieza.h"
#include <string> 
using std::string;

Reina::Reina(string color,int x,int y, char tipo): Pieza(color,x,y,tipo){
}

Reina::~Reina(){
}

bool Reina::mover()const{
	return true;
}

