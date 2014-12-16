#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
	public:

		virtual void initialize();

		virtual bool** create_state();

		virtual void update_state();

		virtual ~Engine();
	private:
		bool** state;

};

#endif // ENGINE_H
