#ifndef SWORDING_H
#define SWORDING_H

#include <Headers\State.h>

class Swording : public State
{
public:
	Swording() {};
	~Swording() {};
	void idle(Animation* a);
	void jumping(Animation* a);
	void climbing(Animation* a);
};

#endif // !SWORDING_H
