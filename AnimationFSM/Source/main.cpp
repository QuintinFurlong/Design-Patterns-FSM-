#include <iostream>
#include <SFML/Graphics.hpp>
#include <Headers\AnimatedSprite.h>
#include <Headers\Player.h>
#include <Headers\Input.h>
#include <Headers\Debug.h>
#include <stdio.h>
#include <SDL.h>
#include <Headers\SDL_image.h>

using namespace std;

int main(int argc, char* args[])
{

	//if (!font.loadFromFile("assets\\ariblk.ttf"))
	//mess.setString("UP TO CLIMB\nDOWN TO JUMP\nLEFT TO SHOVEL\nRIGHT TO HAMMER\nDELETE TO SWORD");
	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}
	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);
	for (short lines = 0; lines < 6; lines++)
	{
		for (short frame = 0; frame < 6; frame++)
		{
			animated_sprite.addFrame(SDL_Rect{ 3 + (85 * frame), 3 + (85 * lines), 84, 84 });
		}
	}
	Player player(animated_sprite);
	Input input;
	
	bool quit = false;
	SDL_Event sdl_event;
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* sdl_window = SDL_CreateWindow("SDL2 Displaying Image",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(sdl_window, -1, 0);
	SDL_Surface* image = SDL_LoadBMP("assets/grid.bmp");
	SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_Rect dstrect = { 10, 10, 300, 300 };

	// Start the game loop
	while (!quit)
	{
		SDL_WaitEvent(&sdl_event);

		if (sdl_event.type == SDL_KEYDOWN)
		{
			if (sdl_event.key.keysym.sym == SDLK_LEFT && input.getCurrent() != Input::Action::SHOVEL)
			{
				input.setCurrent(Input::Action::SHOVEL);
			}
			else if (sdl_event.key.keysym.sym == SDLK_RIGHT && input.getCurrent() != Input::Action::HAMMER)
			{
				input.setCurrent(Input::Action::HAMMER);
			}
			else if (sdl_event.key.keysym.sym == SDLK_UP && input.getCurrent() != Input::Action::CLIMB)
			{
				input.setCurrent(Input::Action::CLIMB);
			}
			else if (sdl_event.key.keysym.sym == SDLK_DOWN && input.getCurrent() != Input::Action::JUMP)
			{
				input.setCurrent(Input::Action::JUMP);
			}
			else if (sdl_event.key.keysym.sym == SDLK_DELETE && input.getCurrent() != Input::Action::SWORD)
			{
				input.setCurrent(Input::Action::SWORD);
			}
		}
		else
		{
			input.setCurrent(Input::Action::IDLE);
		}
		SDL_UpdateWindowSurface(sdl_window);
		switch (sdl_event.type)
		{
		case SDL_QUIT:
			
			quit = true;
			break;
		}
		if (quit)
		{
			SDL_DestroyTexture(sdl_texture);
			SDL_FreeSurface(image);
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(sdl_window);
			SDL_Quit();
		}

		player.handleInput(input);
		player.update(input.getCurrent());

		// Draw the Players Current Animated Sprite
		//window.draw(player.getAnimatedSprite());
		SDL_RenderCopy(renderer, sdl_texture, &player.getAnimatedSprite(), &dstrect);
		SDL_RenderPresent(renderer);
	}

	return EXIT_SUCCESS;
};