#include "input_manager.h"

namespace stg
{

bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button mouseButton)
{
	if (sf::Mouse::isButtonPressed(mouseButton))
	{
		sf::IntRect temprect(object.getPosition().x, object.getPosition().y,
							object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (temprect.contains(sf::Mouse::getPosition()))
			return true;
	}
	return false;
}


sf::Vector2i InputManager::getMousePosition()
{
	return sf::Mouse::getPosition();
}

}
