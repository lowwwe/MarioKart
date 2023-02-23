#pragma once

#include <SFML/Graphics.hpp>

class GamePlay
{
public:
	void initialise();
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);
	void update(sf::Time t_deltaTime);

private:
	sf::Texture m_backbroundTexture;// background texture
	sf::Sprite m_backgroundSprite; // background sprite
	// player

};

