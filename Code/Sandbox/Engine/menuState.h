#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "state.h"
#include "container.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class MenuState : public State
{
public:
							MenuState(StateStack&, Context);

	virtual void			draw();
	virtual bool			update(sf::Time);
	virtual bool			handleEvent(const sf::Event&);

private:
	sf::Sprite				mBackgroundSprite;
	GUI::Container			mGUIContainer;
};

#endif
