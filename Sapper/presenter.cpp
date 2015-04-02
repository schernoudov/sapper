#include "presenter.h"
#include "engine.h"

Presenter::Presenter()
{
	this->engine = new Engine();
	engine->initialize();
}

Presenter::~Presenter()
{
	delete engine;
}

bool** Presenter::create_new_game() {
	return engine->create_state();
}
