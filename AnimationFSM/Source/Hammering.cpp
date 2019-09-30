#include <Headers\Hammering.h>
#include <Headers\Jumping.h>
#include <Headers\Climbing.h>
#include <Headers\Idle.h>

#include <string>

void Hammering::idle(Animation* a)
{
	std::cout << "Hammering -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Hammering::jumping(Animation* a)
{
	std::cout << "Hammering -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Hammering::climbing(Animation * a)
{
	std::cout << "Hammering -> Climb" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}
