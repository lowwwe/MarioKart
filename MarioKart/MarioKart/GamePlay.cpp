#include "GamePlay.h"
#include "Game.h"
#include <iostream>

void GamePlay::initialise()
{
	if (!m_backbroundTexture.loadFromFile("ASSETS\\IMAGES\\background.jpg"))
	{
		std::cout << "problem with background" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backbroundTexture);
	float scaleX = WIDTH / static_cast<float>(m_backbroundTexture.getSize().x);
	float scaleY = static_cast<float>(HEIGHT) / m_backbroundTexture.getSize().y;
	m_backgroundSprite.setScale(scaleX, scaleY);
	m_backgroundSprite.setPosition(0.0f, 0.0f);
	m_player.initialise();
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	m_player.render(t_window);
}

void GamePlay::processEvents(sf::Event t_event)
{
}

void GamePlay::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_player.right();
	}
	m_player.update(t_deltaTime);
	if (m_player.departed())
	{
		Game::s_currentMode = GameMode::Menu;
		m_player.resetPosition();
	}
}
