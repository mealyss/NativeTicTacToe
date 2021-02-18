#include <sstream>
#include <iostream>

#include "main_menu_state.h"
#include "constants.h"

namespace stg
{

MainMenuState::MainMenuState(GameDataRef gameData) : m_gameData(gameData) {}

void MainMenuState::initialize()
{
	m_gameData->assetManager.loadTexture("main_menu_title", MAIN_MENU_TITLE_FILEPATH);
	m_gameData->assetManager.loadTexture("play_button", PLAY_BUTTON_FILEPATH);

	m_title.setTexture(m_gameData->assetManager.getTexture("main_menu_title"));
	m_playButton.setTexture(m_gameData->assetManager.getTexture("play_button"));

	m_playButton.setPosition((SCREEN_WIDTH / 2) - m_playButton.getGlobalBounds().width / 2,
							 (SCREEN_HEIGHT / 2) - m_playButton.getGlobalBounds().height / 2);
	m_title.setPosition((SCREEN_WIDTH / 2) - m_title.getGlobalBounds().width / 2,
								m_title.getGlobalBounds().height * 0.1);
}

void MainMenuState::handleInput()
{
	sf::Event event;
	while(m_gameData->window.pollEvent(event))
	{
		if(sf::Event::Closed == event.type)
			m_gameData->window.close();

		if(m_gameData->input.isSpriteClicked(m_playButton, sf::Mouse::Button::Left, m_gameData->window))
		{
			// Go to the game screen
			LOG("Go to the game screen");
		}
	}
}

void MainMenuState::update(float dt) {}

void MainMenuState::draw(float dt)
{
	m_gameData->window.clear(sf::Color::Black);

	m_gameData->window.draw(m_title);
	m_gameData->window.draw(m_playButton);

	m_gameData->window.display();
}

}
