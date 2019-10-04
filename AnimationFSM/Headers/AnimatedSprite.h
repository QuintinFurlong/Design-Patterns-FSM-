#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Clock.hpp>
#include <vector>
#include <Headers\Debug.h>
#include <SDL.h>

using namespace std;
using namespace sf;

class AnimatedSprite : Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(const Texture&);
	AnimatedSprite(const Texture&, const SDL_Rect&);
	~AnimatedSprite();

	const Clock& getClock();
	const Time& getTime();
	const vector<SDL_Rect>& getFrames();
	SDL_Rect& getFrame(int);
	void addFrame(SDL_Rect&);
	const int getCurrentFrame();
	void update(int t_numOfAnimes);
	SDL_Texture* m_texture;
private:
	Clock m_clock;
	Time m_time;
	vector<SDL_Rect> m_frames;
	int m_current_frame;
};

#endif // !ANIMATED_SPRITE_H
