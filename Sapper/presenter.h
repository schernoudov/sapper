#ifndef PRESENTER_H
#define PRESENTER_H

#include <engine.h>
#include <engineimpl.h>

class Presenter
{
	public:
		Presenter();

		bool** create_new_game();
	private:
		Engine *engine;
};

#endif // PRESENTER_H
