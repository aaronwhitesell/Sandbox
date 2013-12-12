#ifndef SOUND_NODE_H
#define SOUND_NODE_H

#include "sceneNode.h"
#include "resourceIdentifiers.h"


class SoundPlayer;

class SoundNode : public SceneNode
{
public:
	explicit				SoundNode(SoundPlayer&);
	
	void					playSound(SoundEffect::ID, sf::Vector2f);
	virtual unsigned int	getCategory() const;


private:
	SoundPlayer&			mSounds;
};

#endif
