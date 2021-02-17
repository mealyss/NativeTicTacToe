#include <sstream>
#include <iostream>

#include "constants.h"
#include "splash_state.h"

namespace stg
{

SplashState::SplashState(GameDataRef gameData) : m_gameData(gameData)
{

}

void SplashState::initialize()
{
	m_gameData->assetManager.loadTexture("splash_bkg", SPLASH_SCREEN_BACKGROUND_FILEPATH);

	m_background.setTexture(m_gameData->assetManager.getTexture("splash_bkg"));

}

void SplashState::handleInput()
{
	sf::Event event;
	while(m_gameData->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
			m_gameData->window.close();
	}

}

void SplashState::update(float dt)
{
	if (m_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		// TODO Swich to the main menu
		LOG("Go to the main menu");
	}
}

void SplashState::draw(float dt)
{
	m_gameData->window.clear(sf::Color::Black);

	m_gameData->window.draw(m_background);

	m_gameData->window.display();
}

}
