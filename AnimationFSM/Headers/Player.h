#ifndef PLAYER_H
#define PLAYER_H

#include <Headers\Input.h>
#include <Headers\Animation.h>
#include <Headers\AnimatedSprite.h>

class Player
{
private:
	Animation m_animation;
	AnimatedSprite m_animated_sprite;
	Player();

public:
	Player(const AnimatedSprite&);
	~Player();
	SDL_Rect& getAnimatedSprite();
	void handleInput(Input);
	void update(int t_numOfAnimes);
};

#endif // !PLAYER_H
