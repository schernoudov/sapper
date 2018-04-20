#include "square.h"

Square::Square()
{
	mined = false;
	opened = false;
	near_mines_quantity = 0;
}

Square::~Square()
{

}

bool Square::is_mined()
{
	return mined;
}

void Square::setMined(bool mined)
{
	this->mined = mined;
}

bool Square::is_opened()
{
	return opened;
}

void Square::set_opened(bool opened)
{
	this->opened = opened;
}

unsigned short Square::get_near_mines_quantity()
{
	return near_mines_quantity;
}

void Square::set_near_mines_quantity(unsigned short quantity)
{
	this->near_mines_quantity = quantity;
}

void Square::reset()
{
	mined = false;
	opened = false;
	near_mines_quantity = 0;
}
