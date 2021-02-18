#include <sstream>
#include <iostream>

#include "splash_state.h"
#include "main_menu_state.h"
#include "constants.h"

namespace stg
{

SplashState::SplashState(GameDataRef gameData) : m_gameData(gameData) {}

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
		// Swich to the main menu
		LOG("Go to the main menu");
		m_gameData->stateMachine.addState(GameStateRef(new MainMenuState(m_gameData)), true);
	}
}

void SplashState::draw(float dt)
{
	m_gameData->window.clear(sf::Color::Black);

	m_gameData->window.draw(m_background);

	m_gameData->window.display();
}

}
