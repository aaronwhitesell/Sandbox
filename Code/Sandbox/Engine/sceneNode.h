#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <memory>
#include <vector>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;


public:
						SceneNode();

	void				attachChild(Ptr);
	Ptr					detachChild(const SceneNode&);

	void				update(sf::Time);

	sf::Transform		getWorldTransform() const;
	sf::Vector2f		getWorldPosition() const;


private:
	virtual void		updateCurrent(sf::Time);
	void				updateChildren(sf::Time);

	virtual void		draw(sf::RenderTarget&, sf::RenderStates) const;
	virtual void		drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
	void				drawChildren(sf::RenderTarget&, sf::RenderStates) const;


private:
	std::vector<Ptr>	mChildren;
	SceneNode*			mParent;
};

#endif
