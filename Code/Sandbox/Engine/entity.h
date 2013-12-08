#ifndef ENTITY_H
#define ENTITY_H

#include "sceneNode.h"


class Entity : public SceneNode
{
public:
	explicit				Entity(int);

	void					setVelocity(sf::Vector2f);
	void					setVelocity(float, float);
	void					accelerate(sf::Vector2f);
	void					accelerate(float, float);
	sf::Vector2f			getVelocity() const;

	int						getHitpoints() const;
	void					repair(int);
	void					damage(int);
	void					destroy();
	virtual void			remove();
	virtual bool			isDestroyed() const;


protected:
	virtual void			updateCurrent(sf::Time, CommandQueue&);


private:
	sf::Vector2f			mVelocity;
	int						mHitpoints;
};

#endif
