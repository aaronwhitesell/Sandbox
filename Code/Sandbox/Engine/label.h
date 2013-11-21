#ifndef LABEL_H
#define LABEL_H

#include "component.h"
#include "resourceIdentifiers.h"
#include "resourceHolder.h"

#include <SFML/Graphics/Text.hpp>


namespace GUI
{

class Label : public Component
{
public:
	typedef std::shared_ptr<Label> Ptr;


public:
							Label(const std::string&, const FontHolder&);
	
	virtual bool			isSelectable() const;
	void					setText(const std::string&);

	virtual void			handleEvent(const sf::Event&);


private:
	void					draw(sf::RenderTarget&, sf::RenderStates) const;

private:
	sf::Text				mText;
};

}

#endif
