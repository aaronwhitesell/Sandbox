#ifndef WORLD_H
#define WORLD_H

#include "resourceHolder.h"
#include "resourceIdentifiers.h"
#include "sceneNode.h"
#include "spriteNode.h"
#include "aircraft.h"
#include "commandQueue.h"
#include "command.h"
#include "bloomEffect.h"
#include "soundPlayer.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>


// Forward declaration
namespace sf
{
	class RenderTarget;
}

class World : private sf::NonCopyable
{
public:
										World(sf::RenderTarget&, FontHolder&,  SoundPlayer&);

	void								update(sf::Time);
	void								draw();

	CommandQueue&						getCommandQueue();

	bool								hasAlivePlayer() const;
	bool								hasPlayerReachedEnd() const;


private:
	void								loadTextures();
	void								adaptPlayerPosition();
	void								adaptPlayerVelocity();
	void								handleCollisions();
	void								updateSounds();

	void								buildScene();
	void								addEnemies();
	void								addEnemy(Aircraft::Type, float, float);
	void								spawnEnemies();
	void								destroyEntitiesOutsideView();
	void								guideMissiles();
	sf::FloatRect						getViewBounds() const;
	sf::FloatRect						getBattlefieldBounds() const;


private:
	enum Layer
	{
		Background,
		LowerAir,
		UpperAir,
		LayerCount
	};

	struct SpawnPoint
	{
		SpawnPoint(Aircraft::Type type, float x, float y)
		: type(type)
		, x(x)
		, y(y)
		{
		}

		Aircraft::Type type;
		float x;
		float y;
	};


private:
	sf::RenderTarget&					mTarget;
	sf::RenderTexture					mSceneTexture;
	sf::View							mWorldView;
	TextureHolder						mTextures;
	FontHolder&							mFonts;
	SoundPlayer&						mSounds;
	
	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;
	CommandQueue						mCommandQueue;

	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	float								mScrollSpeed;
	Aircraft*							mPlayerAircraft;

	std::vector<SpawnPoint>				mEnemySpawnPoints;
	std::vector<Aircraft*>				mActiveEnemies;

	BloomEffect							mBloomEffect;
};

#endif
