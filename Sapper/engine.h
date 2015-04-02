#ifndef ENGINEIMPL_H
#define ENGINEIMPL_H

#include <stddef.h>
#include <engine.h>
#include <minefield.h>

class Engine
{
	public:

		Engine();
		void initialize();
		bool** create_state();
		void update_state();
		virtual ~Engine();

	private:

		Minefield* minefield;
		bool** calculate_state();
};

#endif // ENGINEIMPL_H
