#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "resourceHolder.h"
#include "resourceIdentifiers.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include <map>
#include <string>


class MusicPlayer : private sf::NonCopyable
{
public:
								MusicPlayer();

	void						play(Music::ID);
	void						stop();

	void						setPaused(bool);
	void						setVolume(float);


private:
	sf::Music							mMusic;
	std::map<Music::ID, std::string>	mFilenames;
	float								mVolume;
};

#endif
