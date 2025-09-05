#include "S84.Tower.Generator.CPPGenerator.ctcode.hpp"

namespace s84 {
namespace tower {
namespace generator {
namespace cppgenerator {
namespace ctcode {

CPPGenerator::CPPGenerator()
{
}

int CPPGenerator::GenerateParser(OmniPointer<s84::tower::system::ctcode::System> system, OmniPointer<s84::tower::dbnf::ctcode::Grammar> grammar, std::string base_name)
{
    OmniPointer<s84::tower::system::ctcode::OutputStream> logger = system->GetLoggerDestination();
    logger->WriteLine(std::string("CPPGenerator not implemented."));
    return 0;
}


};
};
};
};
};
