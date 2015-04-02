#include <engine.h>
#include <minefield.h>

Engine::Engine()
{

}

bool** Engine::create_state()
{
	return NULL;
}

void Engine::update_state()
{

}

void Engine::initialize()
{
	minefield = new Minefield(30, 16);
	minefield->initialize();
}

bool** Engine::calculate_state()
{
	return NULL;
}

Engine::~Engine()
{
	delete [] minefield;
}
