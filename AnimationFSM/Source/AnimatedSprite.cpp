#include <Headers\AnimatedSprite.h>

AnimatedSprite::AnimatedSprite() 
{
	m_current_frame = 0;
}

AnimatedSprite::AnimatedSprite(const sf::Texture& t) : Sprite(t), m_current_frame(0), m_time(seconds(0.5f)) {}

AnimatedSprite::AnimatedSprite(const sf::Texture& t, const SDL_Rect& rect) : Sprite(t), m_current_frame(0), m_time(seconds(0.5f)) {
	m_frames.push_back(rect);
}

AnimatedSprite::~AnimatedSprite() {}

const sf::Clock& AnimatedSprite::getClock() {
	return m_clock;
}

const sf::Time& AnimatedSprite::getTime() {
	return m_time;
}

const vector<SDL_Rect>& AnimatedSprite::getFrames() {
	return m_frames;
}

SDL_Rect& AnimatedSprite::getFrame(int n) {
	return m_frames[n];
}

void AnimatedSprite::addFrame(SDL_Rect& frame) {
	m_frames.push_back(frame);
}

const int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

void AnimatedSprite::update(int t_numOfAnimes){
	if (m_current_frame < 6 * t_numOfAnimes || m_current_frame > (6 * t_numOfAnimes) + 6)
	{
		m_current_frame = 6 * t_numOfAnimes;
	}

	if (m_clock.getElapsedTime() > m_time) {
		if (6 * (t_numOfAnimes + 1) > m_current_frame + 1)
		{
			m_current_frame++;
		}
		else {
			m_current_frame = 6 * t_numOfAnimes;
		}
		m_clock.restart();
	}
}

