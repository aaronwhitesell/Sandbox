#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H

#include "state.h"
#include "container.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class GameOverState : public State
{
	public:
							GameOverState(StateStack&, Context);

		virtual void		draw();
		virtual bool		update(sf::Time);
		virtual bool		handleEvent(const sf::Event&);


	private:
		sf::Text			mGameOverText;
		sf::Time			mElapsedTime;
};

#endif // BOOK_GAMEOVERSTATE_HPP