#pragma once

#include <SFML/Graphics.hpp>

#include "game_state.h"
#include "game.h"

namespace stg
{

class SplashState : public GameState
{
public:
	SplashState(GameDataRef gameData);

	void initialize();

	void handleInput();
	void update(float dt);
	void draw(float dt);

private:
	GameDataRef m_gameData;
	sf::Clock m_clock;
	sf::Sprite m_background;
};

}
