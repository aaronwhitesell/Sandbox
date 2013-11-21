#ifndef CONTAINER_H
#define CONTAINER_H

#include "component.h"

#include <vector>
#include <memory>


namespace GUI
{

class Container : public Component
{
public:
	typedef std::shared_ptr<Container> Ptr;


public:
							Container();

	void					pack(Component::Ptr component);

	virtual bool			isSelectable() const;
	virtual void			handleEvent(const sf::Event&);


private:
	virtual void			draw(sf::RenderTarget&, sf::RenderStates) const;

	bool					hasSelection() const;
	void					select(std::size_t);
	void					selectNext();
	void					selectPrevious();


private:
	std::vector<Component::Ptr>		mChildren;
	int								mSelectedChild;
};

}

#endif
