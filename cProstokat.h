#ifndef _CPROSTOKAT_H
#define _CPROSTOKAT_H

#include <iostream>
#include <string>
#include <cmath>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include "cFizyka.h"


using namespace std;
class cFigura:public CFizyka
{
protected:
	float h, w,r;
	
	float R, G, B;
	float alpha;
public:
	virtual void rysuj()=0;
	void przesun(float dx, float dy);
	void obroc(float dalpha);

};

class cProstokat:public cFigura
{	
public:
	cProstokat();
	void rysuj();
	void ustaw_kolor(float r, float g, float b);
};

class cKolo :public cFigura
{
public:
	cKolo();
	void rysuj();
};

#endif