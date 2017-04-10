#include "scena.h"
#include "cFizyka.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>

cScena scena;


/***************/


void przerysuj()
{
	scena.rysuj();
}

cScena::cScena()
{
	aktywny = -1;
	
}

void idle()
{
	scena.Aktualizuj();
	glutPostRedisplay();
	Sleep(1);
}

void cScena::Aktualizuj()
{
	int czas = GetTickCount(); //zwraca czas w [ms]
	for (int i = 0; i< figury.size() - 1; i++)
		figury[i]->Aktualizuj(czas); //obliczanie nowych polozen
									 //wykrywanie kolizji
	for (int i = 0; i< figury.size() - 1; i++)
		for (int j = i + 1; j<figury.size() - 1; j++)
			if (figury[i]->Kolizja(*figury[j])) //znajduje kolizje
			{
				// tu mozna zareagowac na kolizje np. usuwajac „zbity” obiekt itp...
			}
}

void cScena::rysuj() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (auto f = figury.begin(); f != figury.end(); f++)
	{
		(*f)->rysuj();
	}
	glPopMatrix();
	glutSwapBuffers();
}
/***************************************/
void cScena::init()
{
	cKolo *okr = new cKolo;
	okr->setPredkosc(0, -90);
	okr->setFizyka(8.91*1E-7, -90);
	okr->przesun(0, 0.5);
	figury.push_back(okr);
	cProstokat *pr_1 = new cProstokat;
	figury.push_back(pr_1);
	pr_1->przesun(0, -.6);
	cProstokat *pr_2 = new cProstokat;
	pr_2->obroc(90);
	pr_2->przesun(-0.5, -0.3);
	pr_2->ustaw_kolor(1, 1, 0);
	figury.push_back(pr_2);
	
	cProstokat *pr_3 = new cProstokat;
	pr_3->obroc(90);
	pr_3->przesun(0.5,- 0.3);
	figury.push_back(pr_3);

}
void cScena::inicjuj(){
	glutInitWindowPosition(40, 40);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("Prostokaty");
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glutDisplayFunc(::przerysuj);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutIdleFunc(idle);
	init();
	glOrtho(-1, 1, -1, 1, -.1, .1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*********************************************/

