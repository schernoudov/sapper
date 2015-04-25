#include <engine.h>
#include <minefield.h>

Engine::Engine()
{

}

Minefield* Engine::create_state()
{
	return minefield->placeMines();
}

void Engine::update_state()
{

}

void Engine::initialize()
{
	minefield = new Minefield(30, 16, 99);
	minefield->initialize();
}

bool** Engine::calculate_state()
{
	return NULL;
}

Engine::~Engine()
{
	delete minefield;
}
