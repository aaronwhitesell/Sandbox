#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "entity.h"
#include "resourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>

class Aircraft : public Entity // inherits SceneNode indirectly 
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};


public:
	explicit				Aircraft(Type type, const TextureHolder&);

	virtual unsigned int	getCategory() const;


private:
	virtual void			drawCurrent(sf::RenderTarget&, sf::RenderStates) const;


private:
	Type					mType;
	sf::Sprite				mSprite;
};

#endif
