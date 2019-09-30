#include <Headers\Idle.h>
#include <Headers\Jumping.h>
#include <Headers\Climbing.h>
#include <Headers\Shoveling.h>
#include <Headers\Hammering.h>
#include <Headers\Swording.h>

#include <string>

void Idle::handleInput() {}
void Idle::update() {}

void Idle::jumping(Animation* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(Animation* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Idle::shoveling(Animation * a)
{
	std::cout << "Idle -> Shoveling" << std::endl;
	a->setCurrent(new Shoveling());
	delete this;
}

void Idle::hammering(Animation * a)
{
	std::cout << "Idle -> Hammering" << std::endl;
	a->setCurrent(new Hammering());
	delete this;
}

void Idle::swording(Animation * a)
{
	std::cout << "Idle -> Swording" << std::endl;
	a->setCurrent(new Swording());
	delete this;
}
