#include "Game.h"

namespace stg
{

Game::Game(int widht, int height, std::string title)
{
	this->_gameData->window.create(sf::VideoMode(widht, height), title,
									sf::Style::Close | sf::Style::Titlebar);
	this->run();
}


void Game::run()
{
	float newTime, frameTime, interpolation;
	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->_gameData->window.isOpen())
	{
		this->_gameData->stateMachine.processStateChanges();

		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
			frameTime = 0.25f;

		currentTime = newTime;
		accumulator += frameTime;

		while(accumulator >= DELTA_TIME)
		{
			this->_gameData->stateMachine.getActiveState()->HandleInput();
			this->_gameData->stateMachine.getActiveState()->Update(DELTA_TIME);

			accumulator -= DELTA_TIME;
		}
		interpolation = accumulator / DELTA_TIME;
		this->_gameData->stateMachine.getActiveState()->Draw(interpolation);

	}
}



}
