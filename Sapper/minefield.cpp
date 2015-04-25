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

Minefield * Minefield::placeMines()
{
	resetSquares();
	unsigned int count = 1;
	int previous_mine_place = randomNumber(1, width);
	Square * square = squares[0][previous_mine_place];
	square->set_mined(true);
	int mine_place;
	while (count != minesCount) {
		mine_place = previous_mine_place + randomNumber(1, (height * width - previous_mine_place) / (minesCount - count));
		int rowNumber = (int) mine_place / width;
		int columnNumber = (int) mine_place % width;
		squares[rowNumber][columnNumber]->set_mined(true);
		previous_mine_place = mine_place;
		count++;
	}
	return this;
}

void Minefield::resetSquares()
{
	for (unsigned short i = 0 ; i < height ; i++) {
		for (unsigned short j = 0 ; j < width ; j++) {
			Square * square = squares[i][j];
			square->reset();
		}
	}
}

int Minefield::randomNumber(unsigned int min, unsigned int max) {
	return min + (rand() % (int) (max - min + 1));
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
