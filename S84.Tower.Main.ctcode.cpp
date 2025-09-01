#include "S84.Tower.Main.ctcode.hpp"

#include "S84.Tower.System.ctcode.hpp"
#include "S84.Tower.Generator.ctcode.hpp"
#include "S84.Tower.Generator.CPPGenerator.ctcode.hpp"
#include "S84.Tower.Generator.CTCodeGenerator.ctcode.hpp"
#include "S84.Tower.Generator.LogToConsole.ctcode.hpp"
#include "S84.Tower.dbnf.ctcode.hpp"

namespace s84
{
namespace tower
{
namespace main
{
namespace ctcode
{
    OmniPointer<s84::tower::generator::ctcode::Generator> Main::GetCPPGenerator()
    {
        return std::shared_ptr<s84::tower::generator::cppgenerator::ctcode::CPPGenerator>(new s84::tower::generator::cppgenerator::ctcode::CPPGenerator());
    }

    OmniPointer<s84::tower::generator::ctcode::Generator> Main::GetCTCodeGenerator()
    {
        return std::shared_ptr<s84::tower::generator::ctcodegenerator::ctcode::CTCodeGenerator>(new s84::tower::generator::ctcodegenerator::ctcode::CTCodeGenerator());
    }

    OmniPointer<s84::tower::generator::ctcode::Generator> Main::GetLogToConsole()
    {
        return std::shared_ptr<s84::tower::generator::logtoconsole::ctcode::LogToConsole>(new s84::tower::generator::logtoconsole::ctcode::LogToConsole());
    }

    int Main::RunMain(OmniPointer<s84::tower::system::ctcode::System> system, std::string dbnf_file_name, std::string generator)
    {
        OmniPointer<s84::tower::system::ctcode::OutputStream> logger = system->GetLoggerDestination();
        std::unordered_map<std::string, OmniPointer<s84::tower::generator::ctcode::Generator>> generators;
        SetKV(generators, std::string("CPPGenerator"), this->GetCPPGenerator());
        SetKV(generators, std::string("CTCodeGenerator"), this->GetCTCodeGenerator());
        SetKV(generators, std::string("LogToConsole"), this->GetLogToConsole());
        if (dbnf_file_name == std::string("") || !HasKV(generators, generator))
        {
            logger->WriteLine(std::string("tower <DBNF_File> <Generator>"));
            logger->WriteLine(std::string("Known generators:"));
            std::vector<std::string> registered_generators = Keys(generators);
            int index = 0;
            while (index < Size(registered_generators))
            {
                logger->WriteLine(Concat(std::string("    "), Element(registered_generators, index)));
                index = index + 1;
            }

            return 1;
        }

        std::string dbnf = system->ReadFileToString(dbnf_file_name);
        if (dbnf == std::string(""))
        {
            logger->WriteLine(Concat(std::string("The file "), Concat(dbnf_file_name, std::string(" is empty or does not exist."))));
            return 1;
        }

        OmniPointer<s84::tower::dbnf::ctcode::LargeString> dbnf_large_string = std::shared_ptr<s84::tower::dbnf::ctcode::LargeString>(new s84::tower::dbnf::ctcode::LargeString());
        dbnf_large_string->SetData(dbnf);
        OmniPointer<s84::tower::dbnf::ctcode::LengthString> index = std::shared_ptr<s84::tower::dbnf::ctcode::LengthString>(new s84::tower::dbnf::ctcode::LengthString());
        index->SetData(dbnf_large_string);
        index->SetStart(0);
        index->SetLength(Length(dbnf));
        OmniPointer<s84::tower::dbnf::ctcode::ParserNetwork> parser_network = std::shared_ptr<s84::tower::dbnf::ctcode::ParserNetwork>(new s84::tower::dbnf::ctcode::ParserNetwork());
        parser_network->Initialize();
        OmniPointer<s84::tower::dbnf::ctcode::GrammarResult> grammar_result = std::shared_ptr<s84::tower::dbnf::ctcode::GrammarResult>(new s84::tower::dbnf::ctcode::GrammarResult());
        OmniPointer<s84::tower::dbnf::ctcode::GrammarParser> grammar_parser = parser_network->GetGrammarParser();
        logger->WriteLine(std::string("Parsing Grammar..."));
        grammar_parser->ParseSingleSave(index, grammar_result);
        if (grammar_result->GetResult() && index->GetLength() == 0)
        {
            logger->WriteLine(std::string("Done Parsing Grammar!"));
            OmniPointer<s84::tower::generator::ctcode::Generator> target_generator = GetKV(generators, generator);
            return target_generator->GenerateParser(system, grammar_result->GetValue(), dbnf_file_name);
        }
        else
        {
            logger->WriteLine(Concat(std::string("Failed to parse "), Concat(dbnf_file_name, std::string("."))));
            return 1;
        }
    }

};
};
};
};
