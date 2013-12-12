#ifndef BUTTON_H
#define BUTTON_H

#include "component.h"
#include "resourceIdentifiers.h"
#include "state.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>


namespace GUI
{

class Button : public Component
{
public:
	typedef std::shared_ptr<Button>		Ptr;
	typedef std::function<void()>		Callback;

	enum Type
	{
		Normal,
		Selected,
		Pressed,
		ButtonCount
	};

public:
							Button(State::Context context);
								
	void					setCallback(Callback);
	void					setText(const std::string&);
	void					setToggle(bool);

	virtual bool			isSelectable() const;
	virtual void			select();
	virtual void			deselect();

	virtual void			activate();
	virtual void			deactivate();

	virtual void			handleEvent(const sf::Event&);


private:
	virtual void			draw(sf::RenderTarget&, sf::RenderStates) const;
	void					changeTexture(Type buttonType);

private:
	Callback				mCallback;
	sf::Sprite				mSprite;
	sf::Text				mText;
	bool					mIsToggle;			// The button remains pressed (active) until explicitly changed (supports poll method).
	SoundPlayer&			mSounds;
};

}

#endif
