#include "cProstokat.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>

cProstokat::cProstokat(){
	h = .2; w = .8;
	x = 0; y = 0;
	R = 1; G = 0; B = 0;
	alpha = 0;
	setGeometria(x, y, -w / 2, -h / 2, w / 2, h / 2);
}

void cProstokat::rysuj(){


	glPushMatrix();
	glColor3f(0,0, 0);
	glTranslatef(x,y, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	{
		glVertex2d(-w / 2, h / 2);
		glVertex2d(w / 2, h / 2);
		glVertex2d(w / 2, -h / 2);
		glVertex2d(-w / 2, -h / 2);
	}
	glEnd();
	glPopMatrix();

}

void cFigura::przesun(float dx, float dy)
{
	x += dx;
	y += dy;
}


void cFigura::obroc(float dalpha)
{
	alpha += dalpha;
}


void cProstokat::ustaw_kolor(float r, float g, float b){
	R = r;
	G = g;
	B = b;
}

cKolo::cKolo()
{
	r = 0.05;
	x = 0; y = 0;
	R = 0; G = .6; B = 0;
	setGeometria(x, y, -r , -r , r , r );
}
void cKolo::rysuj()
{
	glPushMatrix();
	glColor3f(R, G, B);
	glTranslatef(x, y, 0);

	glBegin(GL_POLYGON);
	for (float kat = 0; kat<360; kat += 10)
	{
		GLfloat x, y;
		x = r*cos(kat / 180 * 3.14);
		y = r*sin(kat / 180 * 3.14);
		glVertex2f(x, y);
	}
	glEnd();	glPopMatrix();

}
