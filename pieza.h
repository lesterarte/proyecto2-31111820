#pragma once

#include <string> 
using std::string;

class Pieza{
	private:
		int x,y; 
		string color; 
		char tipo;

	public:
		Pieza(string,int,int,char);
		virtual ~Pieza(); 
		virtual bool mover(const Pieza&)const; 
		string getColor()const; 
		int getx()const;
		int gety()const; 
		void setx(int);
		void sety(int);
		char getTipo()const;
		
};