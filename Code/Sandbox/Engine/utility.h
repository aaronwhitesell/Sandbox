#ifndef UTILITY_H
#define UTILITY_H

#include <SFML/Window/Keyboard.hpp>

#include <sstream>


namespace sf
{
	class Sprite;
	class Text;
}

// Convert enumerators to strings
std::string toString(sf::Keyboard::Key key);

void centerOrigin(sf::Sprite&);
void centerOrigin(sf::Text&);

#endif