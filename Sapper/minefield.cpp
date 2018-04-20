#include "minefield.h"
#include "square.h"
#include "cstdlib"

Minefield::Minefield(unsigned short width, unsigned short height, int minesCount)
{
	this->width = width;
	this->height = height;
	this->squares = new Square**[height];
	this->minesCount = minesCount;
}

void Minefield::initialize()
{
	for (unsigned short i = 0 ; i < height ; i++) {
		Square ** row = new Square * [width];
		for (unsigned short j = 0 ; j < width ; j++) {
			Square * square = new Square();
			row[j] = square;
		}
		squares[i] = row;
	}
}

Square * Minefield::getSquare(unsigned short x, unsigned short y)
{
	return squares[x][y];
}

Minefield::~Minefield()
{
	for (short i = 0 ; i < height ; i++) {
		delete [] squares[i];
	}
}

unsigned short Minefield::getHeight() const
{
    return height;
}

void Minefield::setHeight(unsigned short value)
{
    height = value;
}

unsigned short Minefield::getWidth() const
{
    return width;
}

void Minefield::setWidth(unsigned short value)
{
    width = value;
}

unsigned int Minefield::getMinesCount() const
{
    return minesCount;
}

void Minefield::setMinesCount(unsigned int value)
{
    minesCount = value;
}

Square ***Minefield::getSquares() const
{
    return squares;
}

void Minefield::setSquares(Square ***value)
{
    squares = value;
}
