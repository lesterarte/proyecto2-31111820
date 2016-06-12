#pragma once

#include "pieza.h"
#include <string> 
using std::string;

class Caballo:public Pieza{

	public:
		Caballo(string,int,int,char);
		virtual ~Caballo(); 
		bool mover()const;
};