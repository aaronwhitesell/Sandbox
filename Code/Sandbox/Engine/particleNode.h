#ifndef PARTICLE_NODE_H
#define PARTICLE_NODE_H

#include "sceneNode.h"
#include "resourceIdentifiers.h"
#include "particle.h"

#include <SFML/Graphics/VertexArray.hpp>

#include <deque>


class ParticleNode : public SceneNode
{
public:
							ParticleNode(Particle::Type, const TextureHolder&);

	void					addParticle(sf::Vector2f);
	Particle::Type			getParticleType() const;
	virtual unsigned int	getCategory() const;


private:
	virtual void			updateCurrent(sf::Time, CommandQueue&);
	virtual void			drawCurrent(sf::RenderTarget&, sf::RenderStates) const;

	void					addVertex(float, float, float, float, const sf::Color&) const;
	void					computeVertices() const;


private:
	std::deque<Particle>	mParticles;
	const sf::Texture&		mTexture;
	Particle::Type			mType;

	mutable sf::VertexArray mVertexArray;
	mutable bool			mNeedsVertexUpdate;
};

#endif
