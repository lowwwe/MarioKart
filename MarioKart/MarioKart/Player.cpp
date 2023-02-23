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
	resetPosition();
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerSprite);
}

void Player::update(sf::Time t_deltaTime)
{
	fall();
	m_playerSprite.setPosition(m_playerLocation);
}

void Player::jump()
{
	m_playerLocation.y -= 100.0f;
	m_playerSprite.setPosition(m_playerLocation);
}

void Player::fall()
{
	if (m_playerLocation.y < m_roadLevel)
	{
		m_playerLocation.y += 1.4f;
	}
}

void Player::left()
{
	m_playerLocation.x -= m_speed;
	if (m_playerSprite.getScale().x == 1.0f)
	{
		m_playerSprite.setScale(-1.0f, 1.0f);
		m_playerLocation.x += 118.0f;
	}
}

void Player::right()
{
	m_playerLocation.x += m_speed;
	if (m_playerSprite.getScale().x == -1.0f)
	{
		m_playerSprite.setScale(1.0f, 1.0f);
		m_playerLocation.x -= 118.0f;
	}

}

bool Player::departed()
{
	if (m_playerLocation.x < 0 || m_playerLocation.x > WIDTH)
	{
		return true;
	}
	return false;
}

void Player::resetPosition()
{
	float posX = WIDTH / 2.0f;
	m_playerLocation = sf::Vector2f(posX, m_roadLevel);
	m_playerSprite.setPosition(m_playerLocation);
}
