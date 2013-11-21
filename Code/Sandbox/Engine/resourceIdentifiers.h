#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H


// Forward declaration of SFML classes
namespace sf
{
		class Texture;
		class Font;
}

// Resource ID for sf::Texture
namespace Textures
{
	enum ID
	{
		Eagle,
		Raptor,
		Desert,
		TitleScreen,
		ButtonNormal,
		ButtonSelected,
		ButtonPressed
	};
}

// Resource ID for sf::Font
namespace Fonts
{
	enum ID
	{
		Main,
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>	TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>			FontHolder;

#endif
