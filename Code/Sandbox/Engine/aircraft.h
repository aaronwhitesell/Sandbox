#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "entity.h"
#include "command.h"
#include "resourceIdentifiers.h"
#include "projectile.h"
#include "textNode.h"

#include <SFML/Graphics/Sprite.hpp>


class Aircraft : public Entity // inherits SceneNode indirectly 
{
public:
	enum Type
	{
		Eagle,
		Raptor,
		Avenger,
		TypeCount
	};


public:
							Aircraft(Type, const TextureHolder&, const FontHolder&);

	virtual void			updateCurrent(sf::Time, CommandQueue&);
	virtual unsigned int	getCategory() const;
	virtual sf::FloatRect	getBoundingRect() const;
	virtual bool			isMarkedForRemoval() const;
	bool					isAllied() const;
	float					getMaxSpeed() const;

	void					increaseFireRate();
	void					increaseSpread();
	void					collectMissiles(unsigned int count);

	void					fire();
	void					launchMissile();


private:
	virtual void			drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
	void					updateMovementPattern(sf::Time);
	void					checkPickupDrop(CommandQueue&);
	void					checkProjectileLaunch(sf::Time, CommandQueue&);

	void					createBullets(SceneNode&, const TextureHolder&) const;
	void					createProjectile(SceneNode&, Projectile::Type, float, float, const TextureHolder&) const;
	void					createPickup(SceneNode& , const TextureHolder&) const;

	void					updateTexts();
	

private:
	Type					mType;
	sf::Sprite				mSprite;
	Command					mFireCommand;
	Command					mMissileCommand;
	sf::Time				mFireCountdown;
	bool					mIsFiring;
	bool					mIsLaunchingMissile;
	bool					mIsMarkedForRemoval;

	int						mFireRateLevel;
	int						mSpreadLevel;
	int						mMissileAmmo;

	Command					mDropPickupCommand;
	float					mTravelledDistance;
	std::size_t				mDirectionIndex;
	TextNode*				mHealthDisplay;
	TextNode*				mMissileDisplay;
};

#endif
