#include <Headers\Swording.h>
#include <Headers\Jumping.h>
#include <Headers\Climbing.h>
#include <Headers\Idle.h>

#include <string>

void Swording::idle(Animation* a)
{
	std::cout << "Swording -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Swording::jumping(Animation* a)
{
	std::cout << "Swording -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Swording::climbing(Animation * a)
{
	std::cout << "Swording -> Climb" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}