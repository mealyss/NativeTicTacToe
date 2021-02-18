#pragma once

#include <SFML/Graphics.hpp>

#include "game.h"
#include "game_state.h"

namespace stg
{

class MainMenuState : public GameState
{
public:
	MainMenuState(GameDataRef gameData);

	void initialize();

	void handleInput();
	void update(float dt);
	void draw(float dt);
private:
	GameDataRef m_gameData;
	sf::Sprite m_title;
	sf::Sprite m_playButton;
};

}
