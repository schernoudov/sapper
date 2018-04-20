#ifndef ENGINEIMPL_H
#define ENGINEIMPL_H

#include <stddef.h>
#include <engine.h>
#include <minefield.h>

class Engine
{
	public:

		Engine();

		virtual ~Engine();

        void initialize();

        Minefield * getMinefield();

        void setMinefield(Minefield *minefield);

        Minefield * placeMines();

        void resetSquares();
private:

		Minefield* minefield;

        int randomNumber(unsigned int min, unsigned int max);
};

#endif // ENGINEIMPL_H
