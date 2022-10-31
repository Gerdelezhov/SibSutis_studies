#include "circle.h"

tCircle::tCircle(float X, float Y, float R)
{
	setX(X);
	setY(Y);
	setR(R);
}

tCircle::tCircle()
{
	setX(rand () % 50 + 50);
	setY(rand () % 50 + 50);
	setR(rand () % 50 + 50);
}

void tCircle::setR(float R)
{
	this->_R = R;
}

float tCircle::getR()
{
	return this->_R;
}

float tCircle::getTmpX(float fi)
{
	return getX() + (getR() * cos(grTOrad(fi)));
}

float tCircle::getTmpY(float fi)
{
	return getY() + (getR() * sin(grTOrad(fi)));
}

float tCircle::grTOrad(float Gr)
{
	return Gr * M_PI / 180;
}

void tCircle::move()
{
	this->setX(this->getX() + (this->getVecX() * 0.01));
	this->setY(this->getY() + (this->getVecY() * 0.01));
}

void tCircle::draw()
{
	glBegin(GL_LINES);
	for (size_t i = 0; i < 360; ++i)
	{
		glVertex2f(this->getTmpX(i), this->getTmpY(i));
		glVertex2f(this->getTmpX(i + 1), this->getTmpY(i + 1));
	}
}
