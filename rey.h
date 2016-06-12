#pragma once

#include "pieza.h"
#include <string> 
using std::string;

class Rey:public Pieza{

	public:
		Rey(string,int,int,char);
		virtual ~Rey(); 
		bool mover()const;
};