#ifndef PICKUP_H
#define PICKUP_H

#include "entity.h"
#include "command.h"
#include "resourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>


class Aircraft;

class Pickup : public Entity
{
public:
	enum Type
	{
		HealthRefill,
		MissileRefill,
		FireSpread,
		FireRate,
		TypeCount
	};


public:
							Pickup(Type, const TextureHolder&);

	virtual unsigned int	getCategory() const;
	virtual sf::FloatRect	getBoundingRect() const;

	void					apply(Aircraft&) const;


protected:
	virtual void			drawCurrent(sf::RenderTarget&, sf::RenderStates) const;


private:
	Type					mType;
	sf::Sprite				mSprite;
};

#endif
