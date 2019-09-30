#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

#include <Headers\Input.h>
#include <Headers\Animation.h>
#include <Headers\Debug.h>

class State
{
public:
	virtual void handleInput() {}

	virtual void update() {}

	virtual void idle(Animation* a)
	{
		DEBUG_MSG("State::Idling");
	}
	virtual void jumping(Animation* a)
	{
		DEBUG_MSG("State::Jumping");
	}
	virtual void climbing(Animation* a)
	{
		DEBUG_MSG("State::Climbing");
	}
	virtual void shoveling(Animation* a)
	{
		DEBUG_MSG("State::Shoveling");
	}
	virtual void hammering(Animation* a)
	{
		DEBUG_MSG("State::Hammering");
	}
	virtual void swording(Animation* a)
	{
		DEBUG_MSG("State::Swording");
	}
};

#endif // ! ANIMATION_H

