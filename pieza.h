#pragma once

#include <string> 
using std::string;

class Pieza{
	private:
		int x,y; 
		string color; 
		char tipo;
		bool isViva;


	public:
		Pieza(string,int,int,char,bool);
		virtual ~Pieza(); 
		virtual bool mover(int,int); 
		string getColor()const; 
		int getx()const;
		int gety()const; 
		void setx(int);
		void sety(int);
		char getTipo()const;
		bool getIsViva()const;
		void setIsViva(bool);
		
};