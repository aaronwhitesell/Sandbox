#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

#include "resourceHolder.h"
#include "resourceIdentifiers.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include <list>


class SoundPlayer : private sf::NonCopyable
{
public:
								SoundPlayer();

	void						play(SoundEffect::ID);
	void						play(SoundEffect::ID, sf::Vector2f);

	void						removeStoppedSounds();
	void						setListenerPosition(sf::Vector2f);
	sf::Vector2f				getListenerPosition() const;

private:
	SoundBufferHolder			mSoundBuffers;
	std::list<sf::Sound>		mSounds;
};

#endif
