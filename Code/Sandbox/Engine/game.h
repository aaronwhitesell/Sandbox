#ifndef GAME_H
#define GAME_H

#include "resourceIdentifiers.h"
#include "resourceHolder.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
							Game();
	void					run();

private:
	void					processEvents();
	void					update(sf::Time);
	void					render();

	void					updateStatistics(sf::Time elapsedTime);
	void					handlePlayerInput(sf::Keyboard::Key, bool);

private:
	static const float		PlayerSpeed;
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	TextureHolder			mTextures;
	sf::Sprite				mPlayer;
	FontHolder				mFonts;
	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;

	std::size_t				mStatisticsNumFrames;
	bool					mIsMovingUp;
	bool					mIsMovingDown;
	bool					mIsMovingLeft;
	bool					mIsMovingRight;
};

#endif
