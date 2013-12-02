#ifndef TEXT_NODE_H
#define TEXT_NODE_H

#include "resourceHolder.h"
#include "resourceIdentifiers.h"
#include "sceneNode.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


class TextNode : public SceneNode
{
public:
	explicit			TextNode(const FontHolder&, const std::string&);

	void				setString(const std::string&);


private:
	virtual void		drawCurrent(sf::RenderTarget&, sf::RenderStates) const;


private:
	sf::Text			mText;
};

#endif
