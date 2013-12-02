#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"
#include "resourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>


class Projectile : public Entity
{
public:
	enum Type
	{
		AlliedBullet,
		EnemyBullet,
		Missile,
		TypeCount
	};


public:
							Projectile(Type, const TextureHolder&);

	void					guideTowards(sf::Vector2f);
	bool					isGuided() const;

	virtual unsigned int	getCategory() const;
	virtual sf::FloatRect	getBoundingRect() const;
	float					getMaxSpeed() const;
	int						getDamage() const;


private:
	virtual void			updateCurrent(sf::Time, CommandQueue&);
	virtual void			drawCurrent(sf::RenderTarget&, sf::RenderStates) const;


private:
	Type					mType;
	sf::Sprite				mSprite;
	sf::Vector2f			mTargetDirection;
};

#endif
