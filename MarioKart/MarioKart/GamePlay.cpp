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
	if (sf::Event::KeyPressed == t_event.type)
	{
		if(sf::Keyboard::Up == t_event.key.code && m_jumpWait == 0)
		{
			m_jumpKeyPressed = true;
		} 
		if (sf::Keyboard::Escape == t_event.key.code)
		{
			Game::s_currentMode = GameMode::Pause;
		}
	}
}

void GamePlay::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_player.right();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_player.left();
	}
	m_player.update(t_deltaTime);
	if (m_player.departed())
	{
		Game::s_currentMode = GameMode::Menu;
		m_player.resetPosition();
	}
	if (m_jumpKeyPressed)
	{
		m_player.jump();
		m_jumpKeyPressed = false;
		m_jumpWait = 35; // half a second
	}
	if (m_jumpWait > 0)
	{
		m_jumpWait--;
	}
}
