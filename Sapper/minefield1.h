<<<<<<< HEAD
#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <cstdlib>
#include <QObject>

class Square : public QObject
{
    Q_OBJECT

    public:
        Square(unsigned int column_index, unsigned int row_index);
        ~Square();
        bool is_mined();
        void set_mined(bool mined);
        bool is_opened();
        void set_opened(bool opened);
        bool is_marked();
        void set_marked(bool marked);
        bool is_unknown();
        void set_unknown(bool unknown);
        unsigned short get_near_mines_quantity();
        void set_near_mines_quantity(unsigned short quantity);
        void reset();
        unsigned int get_column_index();
        unsigned int get_row_index();
    private:
        bool mined;
        bool opened;
        bool marked;
        bool unknown;
        unsigned short near_mines_quantity;
        unsigned int column_index;
        unsigned int row_index;
};

class Minefield : public QObject
{
    Q_OBJECT

	public:
        Minefield(unsigned short width, unsigned short height, int minesCount, QObject *parent = 0);
        Minefield * initialize();
        Minefield * reset();
        Square * get_square(unsigned short row_index, unsigned short column_index);
        Square ** collect_near_squares(Square *square, Square **near_squares);
        Minefield *initialize_squares();
        int calculate_near_mines_quantity(Square *square);
		~Minefield();
		unsigned short get_width();
		unsigned short get_height();
    private:
		unsigned short height;
		unsigned short width;
		unsigned int minesCount;
        Square ***squares;
        Square * get_top_left_near_square(unsigned int row_index, unsigned int column_index);
        Square * get_top_near_square(unsigned int row_index, unsigned int column_index);
        Square * get_top_right_near_square(unsigned int row_index, unsigned int column_index);
        Square * get_right_near_square(unsigned int row_index, unsigned int column_index);
        Square * get_bottom_right_near_square(unsigned int row_index, unsigned int column_index);
        Square * get_bottom_near_square(unsigned int row_index, unsigned int column_index);
        Square * get_bottom_left_near_square(unsigned int row_index, unsigned int column_index);
        Square * get_left_near_square(unsigned int row_index, unsigned int column_index);
		inline int randomNumber(unsigned int min, unsigned int max);
};

#endif // MINEFIELD_H

=======
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
>>>>>>> cdbb84bce18d4c5a9628b9816b9c94d4a04d6349
