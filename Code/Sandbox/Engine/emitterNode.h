#ifndef EMITTER_NODE_H
#define EMITTER_NODE_H

#include "sceneNode.h"
#include "particle.h"


class ParticleNode;

class EmitterNode : public SceneNode
{
public:
	explicit				EmitterNode(Particle::Type);


private:
	virtual void			updateCurrent(sf::Time, CommandQueue&);

	void					emitParticles(sf::Time);


private:
	sf::Time				mAccumulatedTime;
	Particle::Type			mType;
	ParticleNode*			mParticleSystem;
};

#endif
