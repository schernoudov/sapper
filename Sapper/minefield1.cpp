<<<<<<< HEAD
#include "minefield.h"
#include "cstdlib"

Minefield::Minefield(unsigned short width, unsigned short height, int minesCount, QObject *parent) : QObject(parent)
{
	this->width = width;
	this->height = height;
	this->squares = new Square**[height];
	this->minesCount = minesCount;

    initialize();
}

Minefield* Minefield::initialize()
{
	for (unsigned short i = 0 ; i < height ; i++)
	{
		Square ** row = new Square * [width];

		for (unsigned short j = 0 ; j < width ; j++)
		{
            Square * square = new Square(j, i);

			row[j] = square;
		}

		squares[i] = row;
	}

    initialize_squares();

    return this;
}

Minefield* Minefield::initialize_squares()
{
    unsigned int count = 1;

	int previous_mine_place = randomNumber(1, width);

    int mine_place;

	while (count != minesCount)
	{
		mine_place = previous_mine_place + randomNumber(1, (height * width - previous_mine_place) / (minesCount - count));

        int row_index = (int) mine_place / width;

        int column_index = (int) mine_place % width;

        squares[row_index][column_index]->set_mined(true);

		previous_mine_place = mine_place;

		count++;
	}

    return this;
}

int Minefield::calculate_near_mines_quantity(Square *square)
{
    int minesCount = 0;

    Square ** squares = new Square * [8];

    collect_near_squares(square, squares);

    for (int i = 0; i < 8; i++)
    {
        Square *near_square = squares[i];

        if (near_square != NULL && near_square->is_mined())
        {
            minesCount++;
        }
    }

    delete squares;

    return minesCount;
}

Square **Minefield::collect_near_squares(Square *square, Square **near_squares)
{
    unsigned int column_index = square->get_column_index();

    unsigned int row_index = square->get_row_index();

    near_squares[0] = get_top_left_near_square(row_index, column_index);
    near_squares[1] = get_top_near_square(row_index, column_index);
    near_squares[2] = get_top_right_near_square(row_index, column_index);
    near_squares[3] = get_right_near_square(row_index, column_index);
    near_squares[4] = get_bottom_right_near_square(row_index, column_index);
    near_squares[5] = get_bottom_near_square(row_index, column_index);
    near_squares[6] = get_bottom_left_near_square(row_index, column_index);
    near_squares[7] = get_left_near_square(row_index, column_index);

    return near_squares;
}

Square * Minefield::get_top_left_near_square(unsigned int row_index, unsigned int column_index)
{
    if (row_index == 0 || column_index == 0)
    {
        return NULL;
    }

    return squares[row_index - 1][column_index - 1];
}

Square * Minefield::get_top_near_square(unsigned int row_index, unsigned int column_index)
{
    if (row_index == 0)
    {
        return NULL;
    }

    return squares[row_index - 1][column_index];
}

Square * Minefield::get_top_right_near_square(unsigned int row_index, unsigned int column_index)
{
    if (row_index == 0 || (short) column_index == width - 1)
    {
        return NULL;
    }

    return squares[row_index - 1][column_index + 1];
}

Square * Minefield::get_right_near_square(unsigned int row_index, unsigned int column_index)
{
    if ((short) column_index == width - 1)
    {
        return NULL;
    }

    return squares[row_index][column_index + 1];
}

Square * Minefield::get_bottom_right_near_square(unsigned int row_index, unsigned int column_index)
{
    if ((short) row_index == height - 1 || (short) column_index == width - 1)
    {
        return NULL;
    }

    return squares[row_index + 1][column_index + 1];
}

Square * Minefield::get_bottom_near_square(unsigned int row_index, unsigned int column_index)
{
    if ((short) row_index == height - 1)
    {
        return NULL;
    }

    return squares[row_index + 1][column_index];
}

Square * Minefield::get_bottom_left_near_square(unsigned int row_index, unsigned int column_index)
{
    if ((short) row_index == height - 1 || column_index == 0)
    {
        return NULL;
    }

    return squares[row_index + 1][column_index - 1];
}

Square * Minefield::get_left_near_square(unsigned int row_index, unsigned int column_index)
{
    if (column_index == 0)
    {
        return NULL;
    }

    return squares[row_index][column_index - 1];
}


Minefield* Minefield::reset()
{
	for (unsigned short i = 0 ; i < height ; i++)
	{
		for (unsigned short j = 0 ; j < width ; j++)
		{
			Square * square = squares[i][j];
			square->reset();
		}
	}

    initialize_squares();

    return this;
}

int Minefield::randomNumber(unsigned int min, unsigned int max)
{
	return min + (rand() % (int) (max - min + 1));
}

Square * Minefield::get_square(unsigned short row_index, unsigned short column_index)
{
    return squares[row_index][column_index];
}

Minefield::~Minefield()
{
	for (short i = 0 ; i < height ; i++)
	{
		delete [] squares[i];
	}
}

unsigned short Minefield::get_height()
{
	return this->height;
}


unsigned short Minefield::get_width()
{
	return this->width;
}

Square::Square(unsigned int x, unsigned int y)
{
    this->column_index = x;
    this->row_index = y;
    this->mined = false;
    this->opened = false;
    this->unknown = false;
    this->marked = false;
    this->near_mines_quantity = 0;
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
    this->mined = false;
    this->opened = false;
    this->unknown = false;
    this->marked = false;
    this->near_mines_quantity = 0;
}

bool Square::is_marked()
{
    return marked;
}

void Square::set_marked(bool marked)
{
    this->marked = marked;
}

bool Square::is_unknown()
{
    return unknown;
}

void Square::set_unknown(bool unknown)
{
    this->unknown = unknown;
}

unsigned int Square::get_column_index()
{
    return this->column_index;
}

unsigned int Square::get_row_index()
{
    return this->row_index;
}
=======
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
>>>>>>> cdbb84bce18d4c5a9628b9816b9c94d4a04d6349
