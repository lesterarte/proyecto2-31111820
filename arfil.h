#pragma once

#include "pieza.h"
#include <string> 
using std::string;

class Arfil:public Pieza{

	public:
		Arfil(string,int,int,char);
		virtual ~Arfil(); 
		bool mover()const;
};