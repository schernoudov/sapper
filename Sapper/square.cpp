#include "square.h"

Square::Square()
{
	mined = false;
	opened = false;
    nearMinesQuantity = 0;
}

Square::~Square()
{

}

bool Square::isMined()
{
	return mined;
}

void Square::setMined(bool mined)
{
	this->mined = mined;
}

bool Square::isOpened()
{
	return opened;
}

void Square::setOpened(bool opened)
{
	this->opened = opened;
}

unsigned short Square::getNearMinesQuantity()
{
    return nearMinesQuantity;
}

void Square::setNearMinesQuantity(unsigned short quantity)
{
    this->nearMinesQuantity = quantity;
}

void Square::reset()
{
	mined = false;
	opened = false;
    nearMinesQuantity = 0;
}
