#include "generator.hpp"

#include <map>
#include <string>

static std::map<std::string, dsa::vent::tower::Generator*>& GetGeneratorMap()
{
	static std::map<std::string, dsa::vent::tower::Generator*> g_generator_map;
	return g_generator_map;
}

static std::map<std::string, dsa::vent::tower::Generator*>& g_generator_map_initializer = GetGeneratorMap();

namespace dsa
{
namespace vent
{
namespace tower
{
Generator::Generator()
{
}

Generator::~Generator()
{
}

void Generator::AddGenerator(std::string name, dsa::vent::tower::Generator* generator)
{
	std::map<std::string, dsa::vent::tower::Generator*>& generator_map = GetGeneratorMap();
	generator_map[name] = generator;
}

dsa::vent::tower::Generator* Generator::GetGenerator(std::string name)
{
	std::map<std::string, dsa::vent::tower::Generator*>& generator_map = GetGeneratorMap();
	std::map<std::string, dsa::vent::tower::Generator*>::iterator index = generator_map.find(name);
	
	if (index != generator_map.end())
	{
		return index->second;
	}
	
	return NULL;
}

std::list<std::string> Generator::GetGeneratorList()
{
	std::list<std::string> generators;
	std::map<std::string, dsa::vent::tower::Generator*>& generator_map = GetGeneratorMap();
	
	for (std::map<std::string, dsa::vent::tower::Generator*>::iterator index = generator_map.begin();index != generator_map.end();++index)
	{
		generators.push_back(index->first);
	}
	
	return generators;
}
};
};
};
