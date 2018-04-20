#ifndef SQUARE_H
#define SQUARE_H

class Square
{
	public:
		Square();
		~Square();
		bool is_mined();
        void setMined(bool mined);
		bool is_opened();
		void set_opened(bool opened);
		unsigned short get_near_mines_quantity();
		void set_near_mines_quantity(unsigned short quantity);
		void reset();
	private:
		bool mined;
		bool opened;
		unsigned short near_mines_quantity;
};

#endif // SQUARE_H
