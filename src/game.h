#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "asset_manager.h"
#include "input_manager.h"
#include "state_machine.h"

namespace stg
{

struct GameData
{
	StateMachine stateMachine;
	sf::RenderWindow window;
	AssetManager assetManager;
	InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
	Game(int widht, int height, std::string title);
	~Game() {}
private:
	const float DELTA_TIME = 1.0f / 60.0f;
	sf::Clock m_clock;
	GameDataRef m_gameData = std::make_shared<GameData>();

	void run();

};

}
