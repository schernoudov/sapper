#ifndef ENGINEIMPL_H
#define ENGINEIMPL_H

#include <engine.h>
#include <engineimpl.h>

class EngineImpl : public Engine
{
	public:

		EngineImpl();

		virtual bool** create_state();

		virtual void update_state();

		virtual void initialize();

		~EngineImpl();

	private:

		bool** calculate_state();
};

#endif // ENGINEIMPL_H
