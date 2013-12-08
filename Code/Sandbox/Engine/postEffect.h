#ifndef POST_EFFECT_H
#define POST_EFFECT_H

#include <SFML/System/NonCopyable.hpp>


namespace sf
{
	class RenderTarget;
	class RenderTexture;
	class Shader;
}

class PostEffect : sf::NonCopyable
{
public:
	virtual					~PostEffect();
	virtual void			apply(const sf::RenderTexture&, sf::RenderTarget&) = 0;

	static bool				isSupported();


protected:
	static void				applyShader(const sf::Shader&, sf::RenderTarget&);
};

#endif
