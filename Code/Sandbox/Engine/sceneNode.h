#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include "category.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <set>
#include <memory>
#include <utility>


struct Command;
class CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;
	typedef std::pair<SceneNode*, SceneNode*> Pair;


public:
	explicit				SceneNode(Category::Type category = Category::None);

	void					attachChild(Ptr child);
	Ptr						detachChild(const SceneNode&);

	void					update(sf::Time, CommandQueue& commands);

	sf::Vector2f			getWorldPosition() const;
	sf::Transform			getWorldTransform() const;

	void					onCommand(const Command&, sf::Time);
	virtual unsigned int	getCategory() const;

	void					checkSceneCollision(SceneNode&, std::set<Pair>&);
	void					checkNodeCollision(SceneNode&, std::set<Pair>&);
	void					removeWrecks();
	virtual sf::FloatRect	getBoundingRect() const;
	virtual bool			isMarkedForRemoval() const;
	virtual bool			isDestroyed() const;


private:
	virtual void			updateCurrent(sf::Time, CommandQueue&);
	void					updateChildren(sf::Time, CommandQueue&);

	virtual void			draw(sf::RenderTarget&, sf::RenderStates) const final;
	virtual void			drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
	void					drawChildren(sf::RenderTarget&, sf::RenderStates) const;
	void					drawBoundingRect(sf::RenderTarget&, sf::RenderStates) const;


private:
	std::vector<Ptr>		mChildren;
	SceneNode*				mParent;
	Category::Type			mDefaultCategory;
};

bool	collision(const SceneNode&, const SceneNode&);
float	distance(const SceneNode&, const SceneNode&);

#endif
