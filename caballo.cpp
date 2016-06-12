#include "caballo.h"
#include "pieza.h"
#include <string> 
using std::string;

Caballo::Caballo(string color,int x,int y, char tipo): Pieza(color,x,y,tipo){
}

Caballo::~Caballo(){
}

bool Caballo::mover()const{
	return true;
}
