#include "main.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "rhombus.h"
#include "ellipse.h"

using namespace std;

const int arr_size = 4;

tPoint p[arr_size];
tLine l[arr_size];
tRectangle r[arr_size];
tTriangle t[arr_size];
tCircle c[arr_size];
tRhombus rh[arr_size];
tEllipse e[arr_size];

int iRad = 0;
int figu = 0;
int action = 2;

void Display()
{
	if (figu > 6)
		figu = 0;

	glClear(GL_COLOR_BUFFER_BIT);
	int mr = 255, mg = 255, mb = 255;

//point
	for(int i = 0; i < arr_size; i++){
		glPointSize(p[i].getSize());
		glColor3f(mr, mg, mb);
		glBegin(GL_POINTS);
		glVertex2f(p[i].getX(), p[i].getY());
		glEnd();
	}

//line
	for(int i = 0; i < arr_size; i++){
		glBegin(GL_LINES);
		glVertex2f(l[i].getXl(), l[i].getYl());
		glVertex2f(l[i].getXr(), l[i].getYr());
		glEnd();
	}

//rectangle
	for(int i = 0; i < arr_size; i++){
		glColor3f(mr, mg, mb);
		glBegin(GL_LINES);
		glVertex2f(r[i].getXtl(), r[i].getYtl());
		glVertex2f(r[i].getXtr(), r[i].getYtr());
		glVertex2f(r[i].getXtr(), r[i].getYtr());
		glVertex2f(r[i].getXbr(), r[i].getYbr());
		glVertex2f(r[i].getXbr(), r[i].getYbr());
		glVertex2f(r[i].getXbl(), r[i].getYbl());
		glVertex2f(r[i].getXbl(), r[i].getYbl());
		glVertex2f(r[i].getXtl(), r[i].getYtl());
		glEnd();
	}

//triangle
	for(int i = 0; i < arr_size; i++){
		glColor3f(mr, mg, mb);
		glPointSize(p[0].getSize());
		glBegin(GL_POINTS);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(t[i].getV1X(), t[i].getV1Y());
		glVertex2f(t[i].getV2X(), t[i].getV2Y());
		glVertex2f(t[i].getV2X(), t[i].getV2Y());
		glVertex2f(t[i].getV3X(), t[i].getV3Y());
		glVertex2f(t[i].getV3X(), t[i].getV3Y());
		glVertex2f(t[i].getV1X(), t[i].getV1Y());
		glEnd();
	}

//rhombus
	for(int i = 0; i < arr_size; i++){
		glColor3f(mr, mg, mb);
		glBegin(GL_LINES);
		glVertex2f(rh[i].getXtl(), rh[i].getYtl());
		glVertex2f(rh[i].getXtr(), rh[i].getYtr());
		glVertex2f(rh[i].getXtr(), rh[i].getYtr());
		glVertex2f(rh[i].getXbl(), rh[i].getYbl());
		glVertex2f(rh[i].getXbl(), rh[i].getYbl());
		glVertex2f(rh[i].getXbr(), rh[i].getYbr());
		glVertex2f(rh[i].getXbr(), rh[i].getYbr());
		glVertex2f(rh[i].getXtl(), rh[i].getYtl());
		glEnd();
	}


//circle
	for(int i = 0; i < arr_size; i++){
		glColor3f(mr, mg, mb);
		glBegin(GL_LINES);
		for (float j = 0; j < 5000; j += 0.3)
		{
			glVertex2f(c[i].getTmpX(j + 1), c[i].getTmpY(j + 1));
		}
		glEnd();
	}


//ellipse
	for(int i = 0; i < arr_size; i++){
		glColor3f(mr, mg, mb);
		glBegin(GL_LINES);
		for (float j = 0; j < 5000; j += 0.3)
		{
			e[i].setAngle(i);
			e[i].setR();
			e[i].settX();
			e[i].settY();
			e[i].setAngle(j+1);
			e[i].setR();
			e[i].settX();
			e[i].settY();
			glVertex2f(e[i].gettX(), e[i].gettY());
		}
		glEnd();
	}

if (figu == 0)
	glutSwapBuffers();
}

void timer(int = 0)
{
//point
	for(int i = 0; i < arr_size; i++){
		p[i].move();
		if (p[i].getX() < 0 || p[i].getX() > win_size)
			p[i].setVecX(-p[i].getVecX());
		if (p[i].getY() < 0 || p[i].getY() > win_size)
			p[i].setVecY(-p[i].getVecY());

		++figu;
	}

	for(int i = 0; i < arr_size; i++){
		if (l[i].getXl() < 0 || l[i].getXr() < 0 || l[i].getXl() > win_size || l[i].getXr() > win_size)
			l[i].setVecX(-l[i].getVecX());
		if (l[i].getYl() < 0 || l[i].getYr() < 0 || l[i].getYl() > win_size || l[i].getYr() > win_size)
			l[i].setVecY(-l[i].getVecY());
		switch (action)
		{
			case 0:
				l[i].move();
				break;
			case 1:
				l[i].rotate(iRad);
				break;
			case 2:
				l[i].move();
				l[i].rotate(iRad);
				break;
		}
		++figu;
	}

//line
	for(int i = 0; i < arr_size; i++){
		if (r[i].getXtl() < 0 || r[i].getXtr() < 0 || r[i].getXbl() < 0 || r[i].getXbr() < 0)
			r[i].setVecX(-r[i].getVecX());
		if (r[i].getYtl() < 0 || r[i].getYtr() < 0 || r[i].getYbl() < 0 || r[i].getYbr() < 0)
			r[i].setVecY(-r[i].getVecY());
		if (r[i].getXtl() > win_size || r[i].getXtr() > win_size || r[i].getXbl() > win_size || r[i].getXbr() > win_size)
			r[i].setVecX(-r[i].getVecX());
		if (r[i].getYtl() > win_size || r[i].getYtr() > win_size || r[i].getYbl() > win_size || r[i].getYbr() > win_size)
			r[i].setVecY(-r[i].getVecY());
		switch (action)
		{
			case 0:
				r[i].move();
				break;
			case 1:
				r[i].rotate(iRad);
				break;
			case 2:
				r[i].move();
				r[i].rotate(iRad);
				break;
		}

		++figu;
	}

//rectangle
	for(int i = 0; i < arr_size; i++){
		if (e[i].getA() > e[i].getX() || e[i].getA() > (win_size - e[i].getX()))
			e[i].setVecX(-e[i].getVecX());
		if (e[i].getB() > e[i].getY() || e[i].getB() > (win_size - e[i].getY()))
			e[i].setVecY(-e[i].getVecY());
		switch (action)
		{
			case 0:
				e[i].move();
				break;
			case 1:
				e[i].rotate(iRad);
				break;
			case 2:
				e[i].move();
				e[i].rotate(iRad);
			break;
		}
		++figu;
	}

//triangle
	for(int i = 0; i < arr_size; i++){
		if (t[i].getV1X() < 0 || t[i].getV2X() < 0 || t[i].getV3X() < 0)
			t[i].setVecX(-t[i].getVecX());
		if (t[i].getV1Y() < 0 || t[i].getV2Y() < 0 || t[i].getV3Y() < 0)
			t[i].setVecY(-t[i].getVecY());
		if (t[i].getV1X() > win_size || t[i].getV2X() > win_size || t[i].getV3X() > win_size)
			t[i].setVecX(-t[i].getVecX());
		if (t[i].getV1Y() > win_size || t[i].getV2Y() > win_size || t[i].getV3Y() > win_size)
			t[i].setVecY(-t[i].getVecY());
		switch (action)
		{
			case 0:
				t[i].move();
				break;
			case 1:
				t[i].rotate(iRad);
				break;
			case 2:
				t[i].move();
				t[i].rotate(iRad);
				break;
		}
		++figu;
	}

//circle
	for(int i = 0; i < arr_size; i++){
		if (c[i].getR() > c[i].getX() || c[i].getR() > (win_size - c[i].getX()))
			c[i].setVecX(-c[i].getVecX());
		if (c[i].getR() > c[i].getY() || c[i].getR() > (win_size - c[i].getY()))
			c[i].setVecY(-c[i].getVecY());
		c[i].move();

		++figu;
	}


//rhombus
	for(int i = 0; i < arr_size; i++){
		if (rh[i].getXtl() < 0 || rh[i].getXtr() < 0 || rh[i].getXbl() < 0 || rh[i].getXbr() < 0)
			rh[i].setVecX(-rh[i].getVecX());
		if (rh[i].getYtl() < 0 || rh[i].getYtr() < 0 || rh[i].getYbl() < 0 || rh[i].getYbr() < 0)
			rh[i].setVecY(-rh[i].getVecY());
		if (rh[i].getXtl() > win_size || rh[i].getXtr() > win_size || rh[i].getXbl() > win_size || rh[i].getXbr() > win_size)
			rh[i].setVecX(-rh[i].getVecX());
		if (rh[i].getYtl() > win_size || rh[i].getYtr() > win_size || rh[i].getYbl() > win_size || rh[i].getYbr() > win_size)
			rh[i].setVecY(-rh[i].getVecY());
		switch (action)
		{
			case 0:
				rh[i].move();
				break;
			case 1:
				rh[i].rotate(iRad);
				break;
			case 2:
				rh[i].move();
				rh[i].rotate(iRad);
				break;
		}
		++figu;
	}

//ellipse
for(int i = 0; i < arr_size; i++){
	if (e[i].getA() > e[i].getX() || e[i].getA() > (win_size - e[i].getX()))
		e[i].setVecX(-e[i].getVecX());
	if (e[i].getB() > e[i].getY() || e[i].getB() > (win_size - e[i].getY()))
		e[i].setVecY(-e[i].getVecY());
	switch (action)
	{
		case 0:
			e[i].move();
			break;
		case 1:
			e[i].rotate(iRad);
			break;
		case 2:
			e[i].move();
			e[i].rotate(iRad);
			break;
	}
	++figu;
}

	Display();
	iRad <=359 ? ++iRad : iRad = 0;

	glutTimerFunc(1, timer, 0);
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(win_size, win_size);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("4");
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, win_size, 0, win_size);
	glutDisplayFunc(Display);
	timer();
	glutMainLoop();
}
