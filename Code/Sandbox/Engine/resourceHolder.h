#ifndef RESOURCE_HOLDER_H
#define RESOURCE_HOLDER_H

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void					load(Identifier, const std::string&);

	template <typename Parameter>
	void					load (Identifier, const std::string&, const Parameter&);

	Resource&				get(Identifier id);
	const Resource&			get(Identifier id) const;


private:
	void					insertResource(Identifier, std::unique_ptr<Resource>);


private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "resourceHolder.inl"
#endif
