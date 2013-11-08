#ifndef ENTITY_H
#define ENTITY_H

#include "sceneNode.h"

class Entity : public SceneNode
{
public:
	void					setVelocity(sf::Vector2f);
	void					setVelocity(float, float);
	void					accelerate(sf::Vector2f);
	void					accelerate(float, float);
	sf::Vector2f			getVelocity() const;


private:
	virtual void			updateCurrent(sf::Time);


private:
	sf::Vector2f			mVelocity;
};

#endif
