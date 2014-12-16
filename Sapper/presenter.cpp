#include "presenter.h"
#include "engineimpl.h"

Presenter::Presenter()
{
	this->engine = new EngineImpl();
}


bool** Presenter::create_new_game() {
	return engine->create_state();
}
