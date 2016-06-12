#include "peon.h"
#include "pieza.h"
#include <string> 
using std::string;

Peon::Peon(string color,int x,int y, char tipo): Pieza(color,x,y,tipo){
}

Peon::~Peon(){
}

bool Peon::mover()const{
	return true;
}

