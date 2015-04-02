#include "square.h"

Square::Square()
{
}

Square::~Square()
{

}

bool Square::is_mined()
{
	return mined;
}

void Square::set_mined(bool mined)
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

unsigned char Square::get_near_mines_quantity()
{
	return near_mines_quantity;
}

unsigned char Square::set_near_mines_quantity(unsigned char quantity)
{
	this->near_mines_quantity = quantity;
}
