#include <Headers\Shoveling.h>
#include <Headers\Jumping.h>
#include <Headers\Climbing.h>
#include <Headers\Idle.h>

#include <string>

void Shoveling::idle(Animation* a)
{
	std::cout << "Shoveling -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Shoveling::jumping(Animation* a)
{
	std::cout << "Shoveling -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Shoveling::climbing(Animation * a)
{
	std::cout << "Shoveling -> Climb" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}