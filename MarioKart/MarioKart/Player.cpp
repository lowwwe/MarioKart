#include "Player.h"
#include <iostream>
#include "Game.h"

void Player::initialise()
{
	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\mario.png"))
	{
		std::cout << "problem with player" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);
	float posX = WIDTH / 2.0f;
	m_playerLocation = sf::Vector2f(posX, m_roadLevel);
	m_playerSprite.setPosition(m_playerLocation);
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerSprite);
}

void Player::update(sf::Time t_deltaTime)
{
	m_playerSprite.setPosition(m_playerLocation);
}

void Player::jump()
{
}

void Player::fall()
{
}

void Player::left()
{
}

void Player::right()
{
	m_playerLocation.x += m_speed;


}

bool Player::departed()
{
	return false;
}

void Player::resetPosition()
{
}
