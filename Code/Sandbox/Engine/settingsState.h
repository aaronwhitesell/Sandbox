#ifndef SETTINGS_STATE_H
#define SETTINGS_STATE_H

#include "state.h"
#include "player.h"
#include "container.h"
#include "button.h"
#include "label.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>


class SettingsState : public State
{
public:
							SettingsState(StateStack&, Context);

	virtual void			draw();
	virtual bool			update(sf::Time);
	virtual bool			handleEvent(const sf::Event&);


private:
	void					updateLabels();
	void					addButtonLabel(Player::Action, float, const std::string&, Context);


private:
	sf::Sprite											mBackgroundSprite;
	GUI::Container										mGUIContainer;
	std::array<GUI::Button::Ptr, Player::ActionCount>	mBindingButtons;
	std::array<GUI::Label::Ptr, Player::ActionCount>	mBindingLabels;
};

#endif
