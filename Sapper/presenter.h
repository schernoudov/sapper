#ifndef PRESENTER_H
#define PRESENTER_H

#include <engine.h>

class Presenter
{
	public:
		Presenter();

		~Presenter();

		bool** create_new_game();
	private:
		Engine* engine;
};

#endif // PRESENTER_H
