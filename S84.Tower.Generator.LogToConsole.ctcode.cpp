#include "S84.Tower.Generator.LogToConsole.ctcode.hpp"

namespace s84 {
namespace tower {
namespace generator {
namespace logtoconsole {
namespace ctcode {

LogToConsole::LogToConsole()
{
}

int LogToConsole::GenerateParser(OmniPointer<s84::tower::system::ctcode::System> system, OmniPointer<s84::tower::dbnf::ctcode::Grammar> grammar, std::string base_name)
{
    OmniPointer<s84::tower::system::ctcode::OutputStream> logger = system->GetLoggerDestination();
    logger->WriteLine(grammar->UnParse());
    return 0;
}


};
};
};
};
};
