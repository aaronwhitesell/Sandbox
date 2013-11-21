#ifndef BUTTON_H
#define BUTTON_H

#include "component.h"
#include "resourceIdentifiers.h"
#include "resourceHolder.h"

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


public:
							Button(const FontHolder&, const TextureHolder&);
								
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


private:
	Callback				mCallback;
	const sf::Texture&		mNormalTexture;
	const sf::Texture&		mSelectedTexture;
	const sf::Texture&		mPressedTexture;
	sf::Sprite				mSprite;
	sf::Text				mText;
	bool					mIsToggle;			// The button remains pressed (active) until explicitly changed (supports poll method).
};

}

#endif
