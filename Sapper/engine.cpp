#include <engine.h>
#include <minefield.h>
#include <square.h>
#include <QPair>

Engine::Engine()
{

}

Minefield * Engine::placeMines()
{
    this->resetSquares();

    Minefield *minefield = this->getMinefield();

    unsigned short minefieldWidth = minefield->getWidth();
    unsigned short minefieldHeight = minefield->getHeight();

    int previousMinePlace = randomNumber(1, minefieldWidth);

    Square *square = minefield->getSquare(0, previousMinePlace);
    square->setMined(true);

    int mine_place;

    unsigned int minesCount = minefield->getMinesCount();

    unsigned int count = 1;

    while (count != minesCount) {

        mine_place = previousMinePlace + randomNumber(1, (minefieldHeight * minefieldWidth - previousMinePlace) / (minesCount - count));

        int rowNumber = (int) mine_place / minefieldWidth;
        int columnNumber = (int) mine_place % minefieldWidth;
        minefield->getSquare(rowNumber, columnNumber)->setMined(true);
        previousMinePlace = mine_place;
        count++;
    }

    return minefield;
}


void Engine::resetSquares()
{
    Minefield *minefield = this->getMinefield();

    unsigned short minefieldWidth = minefield->getWidth();
    unsigned short minefieldHeight = minefield->getHeight();

    for (unsigned short i = 0 ; i < minefieldHeight ; i++) {
        for (unsigned short j = 0 ; j < minefieldWidth ; j++) {
            Square * square = minefield->getSquare(j, i);
            square->reset();
        }
    }
}

bool Engine::openSquare(QPair<int, int> *position)
{

    Square *square = this->minefield->getSquare(position->first, position->second);
    square->setOpened(true);

    if (!square->isMined()) {
        return true;
    } else {
        return false;
    }
}


int Engine::randomNumber(unsigned int min, unsigned int max) {
    return min + (rand() % (int) (max - min + 1));
}

void Engine::initialize()
{
    minefield = new Minefield(30, 16, 99);
    minefield->initialize();
}

Engine::~Engine()
{
    delete minefield;
}

Minefield * Engine::getMinefield()
{
    if (this->minefield == NULL) {
        this->initialize();
    }

    return this->minefield;
}

void Engine::setMinefield(Minefield *minefield)
{
    if (this->minefield != NULL) {
        delete this->minefield;
    }

    this->minefield = minefield;
}
