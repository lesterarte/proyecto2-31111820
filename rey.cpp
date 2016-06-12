#include "rey.h"
#include "pieza.h"
#include <string> 
using std::string;

Rey::Rey(string color,int x,int y, char tipo): Pieza(color,x,y,tipo){
}

Rey::~Rey(){
}

bool Rey::mover()const{
	return true;
}




