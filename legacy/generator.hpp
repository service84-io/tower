#ifndef DSA_VENT_TOWER_GENERATOR_H
#define DSA_VENT_TOWER_GENERATOR_H

#include <list>
#include <string>

#include "DSA.Vent.Tower.dbnf.hpp"

namespace dsa
{
namespace vent
{
namespace tower
{
class Generator
{
public:
	Generator();
	virtual ~Generator();

	static void AddGenerator(std::string name, dsa::vent::tower::Generator* generator);
	static dsa::vent::tower::Generator* GetGenerator(std::string name);
	static std::list<std::string> GetGeneratorList();

	virtual int GenerateParser(const char* buffer, std::string base_name) = 0;
};
};
};
};

#endif

