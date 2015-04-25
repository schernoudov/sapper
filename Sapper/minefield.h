#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <square.h>
#include <cstdlib>

class Minefield
{
	public:
		Minefield(unsigned short width, unsigned short height, int minesCount);
		void initialize();
		Square * getSquare(unsigned short width, unsigned short height);
		Minefield* placeMines();
		~Minefield();
	private:
		unsigned short height;
		unsigned short width;
		unsigned int minesCount;
		Square *** squares;
		inline int randomNumber(unsigned int min, unsigned int max);
		void resetSquares();
};

#endif // MINEFIELD_H
