#ifndef BLOOM_EFFECT_H
#define BLOOM_EFFECT_H

#include "postEffect.h"
#include "resourceIdentifiers.h"
#include "resourceHolder.h"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <array>


class BloomEffect : public PostEffect
{
public:
						BloomEffect();

	virtual void		apply(const sf::RenderTexture&, sf::RenderTarget&);


private:
	typedef std::array<sf::RenderTexture, 2> RenderTextureArray;


private:
	void				prepareTextures(sf::Vector2u);

	void				filterBright(const sf::RenderTexture&, sf::RenderTexture&);
	void				blurMultipass(RenderTextureArray&);
	void				blur(const sf::RenderTexture&, sf::RenderTexture&, sf::Vector2f);
	void				downsample(const sf::RenderTexture&, sf::RenderTexture&);
	void				add(const sf::RenderTexture&, const sf::RenderTexture&, sf::RenderTarget&);


private:
	ShaderHolder		mShaders;
	sf::RenderTexture	mBrightnessTexture;
	RenderTextureArray  mFirstPassTextures;
	RenderTextureArray  mSecondPassTextures;
};

#endif
