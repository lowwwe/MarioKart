/// <summary>
/// author Peter Lowe Feb 2023
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

enum class GameMode
{
	None,
	Licence,
	Splash,
	Menu,
	Help,
	GamePlay,
	Pause
};


class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();


	sf::RenderWindow m_window; // main SFML window
	sf::Font m_gameFont; // font used by message
	bool m_exitGame; // control exiting game


	GameMode m_currentMode{ GameMode::Licence }; // current game mode
};

#endif // !GAME_HPP

