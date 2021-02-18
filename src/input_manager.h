#pragma once

#include <SFML/Graphics.hpp>

namespace stg
{

class InputManager
{
public:
	InputManager() {}
	~InputManager() {}

	bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button mouseButton, sf::RenderWindow& window);
	sf::Vector2i getMousePosition(sf::RenderWindow& window);
};

}
