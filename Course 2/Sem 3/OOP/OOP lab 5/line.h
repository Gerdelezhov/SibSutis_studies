#ifndef LINE_H
#define LINE_H

#include <GL/glut.h>
#include <cmath>
#include "point.h"

class tLine : public tPoint
{
	private:
		float _Xl;
		float _Yl;
		float _Xr;
		float _Yr;

		float _R;
		float _Angle;
	public:
		tLine();

		void setXl(float c, float fi = 0);
		void setYl(float c, float fi = 0);
		void setXr(float c, float fi = 0);
		void setYr(float c, float fi = 0);

		void setR(float X, float Y);
		void setAngle(float X, float Y);

		float getXl();
		float getYl();
		float getXr();
		float getYr();

		float getR();
		float getAngle();

		float grTOrad(float Gr);
		virtual void rotate(float Gr);
		virtual void move();
		virtual void draw();
};

#endif
