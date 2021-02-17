#include "game.h"

namespace stg
{

Game::Game(int widht, int height, std::string title)
{
	this->m_gameData->window.create(sf::VideoMode(widht, height), title,
									sf::Style::Close | sf::Style::Titlebar);
	this->run();
}


void Game::run()
{
	float newTime, frameTime, interpolation;
	float currentTime = m_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (m_gameData->window.isOpen())
	{
		m_gameData->stateMachine.processStateChanges();

		newTime = m_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
			frameTime = 0.25f;

		currentTime = newTime;
		accumulator += frameTime;

		while(accumulator >= DELTA_TIME)
		{
			m_gameData->stateMachine.getActiveState()->handleInput();
			m_gameData->stateMachine.getActiveState()->update(DELTA_TIME);

			accumulator -= DELTA_TIME;
		}
		interpolation = accumulator / DELTA_TIME;
		m_gameData->stateMachine.getActiveState()->draw(interpolation);

	}
}



}
