#ifndef GAME_H
#define GAME_H

#include "world.h"
#include "player.h"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Game : private sf::NonCopyable
{
public:
							Game();
	void					run();


private:
	void					processEvents();
	void					update(sf::Time);
	void					render();
	void					updateStatistics(sf::Time elapsedTime);


private:
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	World					mWorld;
	Player					mPlayer;

	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	std::size_t				mStatisticsNumFrames;
};

#endif
