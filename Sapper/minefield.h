#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <square.h>
#include <cstdlib>

class Minefield
{
	public:

		Minefield(unsigned short width, unsigned short height, int minesCount);

        ~Minefield();

		void initialize();

		Square * getSquare(unsigned short width, unsigned short height);

        unsigned short getHeight() const;
        void setHeight(unsigned short value);

        unsigned short getWidth() const;
        void setWidth(unsigned short value);

        unsigned int getMinesCount() const;
        void setMinesCount(unsigned int value);

        Square ***getSquares() const;
        void setSquares(Square ***value);

private:
        unsigned short height;
        unsigned short width;
        unsigned int minesCount;
		Square *** squares;
};

#endif // MINEFIELD_H
