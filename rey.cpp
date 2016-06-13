#include "rey.h"
#include "pieza.h"
#include <string> 
using std::string;

Rey::Rey(string color,int x,int y, char tipo,bool isViva): Pieza(color,x,y,tipo,isViva){
}

Rey::~Rey(){
}

bool Rey::mover()const{
	return true;
}




