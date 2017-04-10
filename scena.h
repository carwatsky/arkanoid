#ifndef _SCENA_H
#define _SCENA_H

#include <vector>
#include "cProstokat.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

class cScena
{
private:
	int aktywny;
	vector<cFigura*>figury;
	
public:
	cScena();
	void rysuj();
	void inicjuj();
	void init();
	void Aktualizuj();
};
extern cScena scena;

#endif

/*cKolcek *k =(cKolcek*)tab[i];






cKlocek*k= dynamic_cast<cKlocek*>(tab[i]);
if(k!=NULL)
{
punkty+=k->punktacja();
}



*/