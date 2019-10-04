#include <iostream>
#include <Headers\Player.h>
#include <Headers\Idle.h>
#include <Headers\Debug.h>

Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

SDL_Rect& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	return m_animated_sprite.getFrame(frame);
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case Input::Action::IDLE:
		m_animation.idle();
		break;
	case Input::Action::CLIMB:
		m_animation.climbing();
		break;
	case Input::Action::JUMP:
		m_animation.jumping();
		break;
	case Input::Action::SHOVEL:
		m_animation.shoveling();
		break;
	case Input::Action::HAMMER:
		m_animation.hammering();
		break;
	case Input::Action::SWORD:
		m_animation.swording();
		break;
	default:
		break;
	}
}

void Player::update(int t_numOfAnimes)
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update(t_numOfAnimes);
}