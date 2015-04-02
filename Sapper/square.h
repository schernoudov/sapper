#ifndef SQUARE_H
#define SQUARE_H

class Square
{
	public:
		Square();
		~Square();
		bool is_mined();
		void set_mined(bool mined);
		bool is_opened();
		void set_opened(bool opened);
		unsigned char get_near_mines_quantity();
		unsigned char set_near_mines_quantity(unsigned char quantity);

	private:
		bool mined;
		bool opened;
		unsigned char near_mines_quantity;
};

#endif // SQUARE_H
