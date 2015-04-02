#ifndef MINEFIELD_H
#define MINEFIELD_H

class Minefield
{
	public:
		Minefield(unsigned char width, unsigned char height);
		void initialize();
	private:
		unsigned char height;
		unsigned char width;
};

#endif // MINEFIELD_H
