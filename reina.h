#pragma once

#include "pieza.h"
#include <string> 
using std::string;

class Reina:public Pieza{

	public:
		Reina(string,int,int,char,bool);
		virtual ~Reina(); 
		bool mover(Pieza**,int,int); 
};
