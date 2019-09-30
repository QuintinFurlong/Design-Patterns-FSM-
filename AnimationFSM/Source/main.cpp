#include <iostream>
#include <SFML/Graphics.hpp>
#include <Headers\AnimatedSprite.h>
#include <Headers\Player.h>
#include <Headers\Input.h>
#include <Headers\Debug.h>

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	sf::Font font;
	if (!font.loadFromFile("assets\\ariblk.ttf")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}
	sf::Text mess;
	mess.setFont(font);
	mess.setPosition(100,100);
	mess.setCharacterSize(20);
	mess.setFillColor(sf::Color::Red);
	mess.setString("UP TO CLIMB\nDOWN TO JUMP\nLEFT TO SHOVEL\nRIGHT TO HAMMER\nDELETE TO SWORD");
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
			animated_sprite.addFrame(sf::IntRect(3 + (85 * frame), 3 + (84 * lines), 84, 84));
		}
	}
	Player player(animated_sprite);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && input.getCurrent() != Input::Action::JUMP)
				{
					input.setCurrent(Input::Action::JUMP);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && input.getCurrent() != Input::Action::CLIMB)
				{
					input.setCurrent(Input::Action::CLIMB);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && input.getCurrent() != Input::Action::SHOVEL)
				{
					input.setCurrent(Input::Action::SHOVEL);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && input.getCurrent() != Input::Action::HAMMER)
				{
					input.setCurrent(Input::Action::HAMMER);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && input.getCurrent() != Input::Action::SWORD)
				{
					input.setCurrent(Input::Action::SWORD);
				}
				break;
			default:
				input.setCurrent(Input::Action::IDLE);
				break;
			}
		}
		player.handleInput(input);
		player.update(input.getCurrent());


		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());
		window.draw(mess);

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};