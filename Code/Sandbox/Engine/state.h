#ifndef STATE_H
#define STATE_H

#include "stateIdentifiers.h"
#include "resourceIdentifiers.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>


namespace sf
{
	class RenderWindow;
}

class StateStack;
class Player;
class MusicPlayer;
class SoundPlayer;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context
	{
							Context(sf::RenderWindow&, TextureHolder&, FontHolder&, Player&, MusicPlayer&, SoundPlayer&);

		sf::RenderWindow*	window;
		TextureHolder*		textures;
		FontHolder*			fonts;
		Player*				player;
		MusicPlayer*		music;
		SoundPlayer*		sounds;
	};


public:
						State(StateStack&, Context);
	virtual				~State();

	virtual void		draw() = 0;
	virtual bool		update(sf::Time) = 0;
	virtual bool		handleEvent(const sf::Event&) = 0;


protected:
	void				requestStackPush(States::ID);
	void				requestStackPop();
	void				requestStateClear();

	Context				getContext() const;


private:
	StateStack*			mStack;
	Context				mContext;
};

#endif