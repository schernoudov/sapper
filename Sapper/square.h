#ifndef SQUARE_H
#define SQUARE_H

class Square
{
	public:

		Square();

		~Square();

		bool isMined();

        void setMined(bool mined);

		bool isOpened();

		void setOpened(bool opened);

		unsigned short getNearMinesQuantity();

		void setNearMinesQuantity(unsigned short quantity);

		void reset();
	private:

		bool mined;

		bool opened;

		unsigned short nearMinesQuantity;
};

#endif // SQUARE_H
