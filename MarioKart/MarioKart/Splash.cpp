#include "Splash.h"
#include "Game.h"
#include <iostream>

void Splash::initialise(sf::Font& t_font)
{
	if (!m_wallPaperTexture.loadFromFile("ASSETS\\IMAGES\\splash.jpg"))
	{
		std::cout << "problem with wall paper" << std::endl;
	}
	m_wallPaperTexture.setRepeated(true);
	m_wallPaperSprite.setTexture(m_wallPaperTexture);
	m_wallPaperSprite.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));


}

void Splash::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_wallPaperSprite);
	t_window.draw(m_message);
}

void Splash::update(sf::Time t_deltaTime)
{
}

void Splash::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		Game::s_currentMode = GameMode::Menu;
	}
}
