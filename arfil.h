#pragma once

#include "pieza.h"
#include <string> 
using std::string;

class Arfil:public Pieza{

	char tipo;

	public:
		Arfil(string,int,int,char);
		virtual ~Arfil(); 
		bool mover()const;
		char gettipo()const; 
};