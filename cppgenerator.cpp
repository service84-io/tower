#include <algorithm>
#include <fstream>
#include <iostream>
#include <locale>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>

#include "dbnf.hpp"
#include "generator.hpp"

namespace dsa
{
namespace vent
{
namespace tower
{
class CPPGenerator : public dsa::vent::tower::Generator
{
public:
	CPPGenerator()
	{
	}
	virtual ~CPPGenerator()
	{
	}

	virtual int GenerateParser(const char* buffer, std::string base_name)
	{
		const char* index = buffer;
		dsa::vent::tower::dbnf::Grammar* grammar = dsa::vent::tower::dbnf::Grammar::Parse(index);
		
		if(grammar)
		{
			std::ofstream header("dbnf.hpp", std::ofstream::trunc | std::ofstream::out);
			std::ofstream implementation("dbnf.cpp", std::ofstream::trunc | std::ofstream::out);
			std::list<std::string> base_name_tokens = TokenizeBaseName(base_name);
			GenerateHeader(grammar, header, base_name_tokens);
			GenerateImplementation(grammar, implementation, base_name_tokens);
			return 0;
		}
		else
		{
			return 1;
		}
	}

	void GenerateHeader(dsa::vent::tower::dbnf::Grammar* grammar, std::ostream& header, std::list<std::string> base_name_tokens)
	{
		std::string guard_name = GenerateGuardName(base_name_tokens);
		header << "#ifndef " << guard_name << std::endl;
		header << "#define " << guard_name << std::endl;
		header << std::endl;
		header << "#include <list>" << std::endl;
		header << "#include <string>" << std::endl;
		header << "#include <cstring>" << std::endl;
		header << std::endl;

		for(std::list<std::string>::iterator base_name_token = base_name_tokens.begin();base_name_token != base_name_tokens.end();++base_name_token)
		{
			header << "namespace " << ToLower(*base_name_token) << std::endl;
			header << "{" << std::endl;
		}

		header << "namespace dbnf" << std::endl;
		header << "{" << std::endl;
		WriteForwardDeclaration(grammar, header);
		header << std::endl;
		WriteClassDeclarations(grammar, header, GenerateFullNamespace(base_name_tokens));
		header << std::endl;

		for(std::list<std::string>::iterator base_name_token = base_name_tokens.begin();base_name_token != base_name_tokens.end();++base_name_token)
		{
			header << "};" << std::endl;
		}
		
		header << "};" << std::endl;
		header << std::endl;
		header << "#endif" << std::endl;
	}

	void GenerateImplementation(dsa::vent::tower::dbnf::Grammar* grammar, std::ostream& implementation, std::list<std::string> base_name_tokens)
	{
		implementation << "#include \"dbnf.hpp\"" << std::endl;
		implementation << std::endl;

		for(std::list<std::string>::iterator base_name_token = base_name_tokens.begin();base_name_token != base_name_tokens.end();++base_name_token)
		{
			implementation << "namespace " << ToLower(*base_name_token) << std::endl;
			implementation << "{" << std::endl;
		}

		implementation << "namespace dbnf" << std::endl;
		implementation << "{" << std::endl;
		WriteFunctionDefinitions(grammar, implementation, GenerateFullNamespace(base_name_tokens));
		implementation << std::endl;

		for(std::list<std::string>::iterator base_name_token = base_name_tokens.begin();base_name_token != base_name_tokens.end();++base_name_token)
		{
			implementation << "};" << std::endl;
		}
		
		implementation << "};" << std::endl;
	}

	void WriteForwardDeclaration(dsa::vent::tower::dbnf::Grammar* grammar, std::ostream& header)
	{
		header << "class Node;" << std::endl;
		header << "class String;" << std::endl;
		std::list<dsa::vent::tower::dbnf::Rule*> rules = grammar->GetRules()->GetList();

		for(std::list<dsa::vent::tower::dbnf::Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			if ((*index)->GetName()) {
				header << "class " << GenerateClassName((*index)->GetName()) << ";" << std::endl;
			}
		}
	}

	void WriteClassDeclarations(dsa::vent::tower::dbnf::Grammar* grammar, std::ostream& header, std::string full_namespace)
	{
		header << "struct LengthString" << std::endl;
		header << "{" << std::endl;
		header << "    const char* data;" << std::endl;
		header << "    int length;" << std::endl;
		header << "};" << std::endl;
		header << std::endl;
		header << "class Node" << std::endl;
		header << "{" << std::endl;
		header << "public:" << std::endl;
		header << "    Node();" << std::endl;
		header << "    virtual ~Node();" << std::endl;
		header << std::endl;
		header << "    std::string UnParse();" << std::endl;
		header << "    " << full_namespace << "LengthString UnParseLString();" << std::endl;
		header << "    std::list<" << full_namespace << "Node*> GetChildren();" << std::endl;
		header << std::endl;
		header << "protected:" << std::endl;
		header << "    void SetString(" << full_namespace << "LengthString data);" << std::endl;
		header << "    void SetChildren(std::list<" << full_namespace << "Node*> children);" << std::endl;
		header << std::endl;
		header << "private:" << std::endl;
		header << "    " << full_namespace << "LengthString data_;" << std::endl;
		header << "    std::list<" << full_namespace << "Node*> children_;" << std::endl;
		header << "};" << std::endl;
		header << std::endl;
		header << "template<class T>" << std::endl;
		header << "class List : public " << full_namespace << "Node" << std::endl;
		header << "{" << std::endl;
		header << "public:" << std::endl;
		header << "    List()" << std::endl;
		header << "    {" << std::endl;
		header << "    }" << std::endl;
		header << "    virtual ~List()" << std::endl;
		header << "    {" << std::endl;
		header << "    }" << std::endl;
		header << std::endl;
		header << "    virtual std::list<T*> GetList()" << std::endl;
		header << "    {" << std::endl;
		header << "        return list_;" << std::endl;
		header << "    }" << std::endl;
		header << std::endl;
		header << "protected:" << std::endl;
		header << "    std::list<T*> list_;" << std::endl;
		header << "};" << std::endl;
		header << std::endl;
		header << "class String : public " << full_namespace << "Node" << std::endl;
		header << "{" << std::endl;
		header << "public:" << std::endl;
		header << "    String(" << full_namespace << "LengthString data);" << std::endl;
		header << "    ~String();" << std::endl;
		header << "};" << std::endl;
		std::list<dsa::vent::tower::dbnf::Rule*> rules = grammar->GetRules()->GetList();

		for(std::list<dsa::vent::tower::dbnf::Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			if ((*index)->GetName()) {
				WriteClassDeclaration(*index, header, full_namespace);
			}
		}
	}

	void WriteClassDeclaration(dsa::vent::tower::dbnf::Rule* rule, std::ostream& header, std::string full_namespace)
	{
		std::string class_name = GenerateClassName(rule->GetName());
		std::map<std::string, std::string> members = GetMembers(rule, full_namespace);
		header << std::endl;
		header << "class " << class_name << " : public " << full_namespace << "Node" << std::endl;
		header << "{" << std::endl;
		header << "public:" << std::endl;
		header << "    " << class_name << "();" << std::endl;
		header << "    ~" << class_name << "();" << std::endl;
		header << std::endl;
		header << "    static " << full_namespace << class_name << "* Parse(const char*& index);" << std::endl;
		header << "    static " << full_namespace << class_name << "* Parse(" << full_namespace << "LengthString& index);" << std::endl;

		if(members.size() > 0)
		{
			header << std::endl;

			for (std::map<std::string, std::string>::iterator index = members.begin(); index != members.end();++index)
			{
				header << "    " << index->second << " " << GenerateAccessorName(index->first) << "();" << std::endl;
			}

			header << std::endl;
			header << "private:" << std::endl;

			for (std::map<std::string, std::string>::iterator index = members.begin(); index != members.end();++index)
			{
				header << "    " << index->second << " " << index->first << ";" << std::endl;
			}
		}

		header << "};" << std::endl;
	}

	void WriteFunctionDefinitions(dsa::vent::tower::dbnf::Grammar* grammar, std::ostream& implementation, std::string full_namespace)
	{
		std::map<std::string, std::string> literal_names = NameLiterals(GetGrammarLiterals(grammar));
		WriteLiteralValues(implementation, literal_names);
		WriteCommonFunctionDefinitions(implementation, full_namespace);
		std::list<dsa::vent::tower::dbnf::Rule*> rules = grammar->GetRules()->GetList();

		for(std::list<dsa::vent::tower::dbnf::Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			if ((*index)->GetName()) {
				WriteClassDefinition(*index, implementation, literal_names, full_namespace);
			}
		}
	}

	void WriteLiteralValues(std::ostream& implementation, std::map<std::string, std::string> literal_names)
	{
		for(std::map<std::string, std::string>::iterator index = literal_names.begin();index != literal_names.end();++index)
		{
			implementation << std::endl;
			implementation << "class " << index->second << std::endl;
			implementation << "{" << std::endl;
			implementation << "public:" << std::endl;
			implementation << "    static const char* GetLiteral()" << std::endl;
			implementation << "    {" << std::endl;
			implementation << "        return " << index->first << ";" << std::endl;
			implementation << "    }" << std::endl;
			implementation << "};" << std::endl;
		}
	}

	void WriteCommonFunctionDefinitions(std::ostream& implementation, std::string full_namespace)
	{
		implementation << std::endl;
		implementation << "static bool Match(std::list<" << full_namespace << "Node*>& nodes, " << full_namespace << "Node* node)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    if(node)" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "        nodes.push_back(node);" << std::endl;
		implementation << "        return true;" << std::endl;
		implementation << "    }" << std::endl;
		implementation << "    else" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "        return false;" << std::endl;
		implementation << "    }" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "static bool Optional(std::list<" << full_namespace << "Node*>& nodes, " << full_namespace << "Node* node)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    Match(nodes, node);" << std::endl;
		implementation << "    return true;" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "template<typename Reference, typename Parser>" << std::endl;
		implementation << "static bool Match(std::list<" << full_namespace << "Node*>& nodes, Reference*& reference, Parser* node)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    reference = node;" << std::endl;
		implementation << "    return Match(nodes, node);" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "template<typename Reference, typename Parser>" << std::endl;
		implementation << "static bool Optional(std::list<" << full_namespace << "Node*>& nodes, Reference*& reference, Parser* node)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    Match<Reference, Parser>(nodes, reference, node);" << std::endl;
		implementation << "    return true;" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "static bool Reset(" << full_namespace << "LengthString value, " << full_namespace << "LengthString& index)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    index = value;" << std::endl;
		implementation << "    return false;" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "static bool ClearNodes(std::list<" << full_namespace << "Node*>& nodes)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    while(!nodes.empty())" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "        " << full_namespace << "Node* node = nodes.front();" << std::endl;
		implementation << "        nodes.pop_front();" << std::endl;
		implementation << "        delete node;" << std::endl;
		implementation << "    }" << std::endl;
		implementation << std::endl;
		implementation << "    return true;" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "template<typename Parser, int minimum, int maximum>" << std::endl;
		implementation << "class RangeParser : public " << full_namespace << "List<Parser>" << std::endl;
		implementation << "{" << std::endl;
		implementation << "public:" << std::endl;
		implementation << "    RangeParser()" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "    }" << std::endl;
		implementation << "    virtual ~RangeParser()" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "    }" << std::endl;
		implementation << std::endl;
		implementation << "    static RangeParser<Parser, minimum, maximum>* Parse(" << full_namespace << "LengthString& index)" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "        " << full_namespace << "LengthString start = index;" << std::endl;
		implementation << "        " << full_namespace << "LengthString local_start = index;" << std::endl;
		implementation << "        std::list<" << full_namespace << "Node*> children;" << std::endl;
		implementation << "        RangeParser<Parser, minimum, maximum>* range_parser = NULL;" << std::endl;
		implementation << "        std::list<Parser*> list;" << std::endl;
		implementation << "        Parser* node = NULL;" << std::endl;
		implementation << "        int count = 0;" << std::endl;
		implementation << std::endl;
		implementation << "        while(((count < maximum) && (node = Parser::Parse(index))) || " << full_namespace << "Reset(local_start, index))" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            local_start = index;" << std::endl;
		implementation << "            ++count;" << std::endl;
		implementation << "            children.push_back(node);" << std::endl;
		implementation << "            list.push_back(node);" << std::endl;
		implementation << "        }" << std::endl;
		implementation << std::endl;
		implementation << "        if((count > minimum) || (" << full_namespace << "ClearNodes(children) && " << full_namespace << "Reset(start, index)))" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            range_parser = new RangeParser<Parser, minimum, maximum>();" << std::endl;
		implementation << "            range_parser->SetChildren(children);" << std::endl;
		implementation << "            range_parser->list_ = list;" << std::endl;
		implementation << "        }" << std::endl;
		implementation << std::endl;
		implementation << "        return range_parser;" << std::endl;
		implementation << "    }" << std::endl;
		implementation << "};" << std::endl;
		implementation << std::endl;
		implementation << "template<typename Parser, int minimum>" << std::endl;
		implementation << "class MinimumParser : public " << full_namespace << "List<Parser>" << std::endl;
		implementation << "{" << std::endl;
		implementation << "public:" << std::endl;
		implementation << "    MinimumParser()" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "    }" << std::endl;
		implementation << "    virtual ~MinimumParser()" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "    }" << std::endl;
		implementation << std::endl;
		implementation << "    static MinimumParser<Parser, minimum>* Parse(" << full_namespace << "LengthString& index)" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "        " << full_namespace << "LengthString start = index;" << std::endl;
		implementation << "        " << full_namespace << "LengthString local_start = index;" << std::endl;
		implementation << "        std::list<" << full_namespace << "Node*> children;" << std::endl;
		implementation << "        MinimumParser<Parser, minimum>* minimum_parser = NULL;" << std::endl;
		implementation << "        std::list<Parser*> list;" << std::endl;
		implementation << "        Parser* node = NULL;" << std::endl;
		implementation << "        int count = 0;" << std::endl;
		implementation << std::endl;
		implementation << "        while((node = Parser::Parse(index)) || " << full_namespace << "Reset(local_start, index))" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            local_start = index;" << std::endl;
		implementation << "            ++count;" << std::endl;
		implementation << "            children.push_back(node);" << std::endl;
		implementation << "            list.push_back(node);" << std::endl;
		implementation << "        }" << std::endl;
		implementation << std::endl;
		implementation << "        if((count >= minimum) || (" << full_namespace << "ClearNodes(children) && " << full_namespace << "Reset(start, index)))" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            minimum_parser = new MinimumParser<Parser, minimum>();" << std::endl;
		implementation << "            minimum_parser->SetChildren(children);" << std::endl;
		implementation << "            minimum_parser->list_ = list;" << std::endl;
		implementation << "        }" << std::endl;
		implementation << std::endl;
		implementation << "        return minimum_parser;" << std::endl;
		implementation << "    }" << std::endl;
		implementation << "};" << std::endl;
		implementation << std::endl;
		implementation << "template<char character>" << std::endl;
		implementation << "class CharacterParser" << std::endl;
		implementation << "{" << std::endl;
		implementation << "public:" << std::endl;
		implementation << "    static " << full_namespace << "String* Parse(" << full_namespace << "LengthString& index)" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "        " << full_namespace << "LengthString data = {index.data, 1};" << std::endl;
		implementation << std::endl;
		implementation << "        if((index.length > 0) && ((*(index.data)) == character))" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            ++(index.data);" << std::endl;
		implementation << "            --(index.length);" << std::endl;
		implementation << "            " << full_namespace << "String* string_node = new " << full_namespace << "String(data);" << std::endl;
		implementation << "            return string_node;" << std::endl;
		implementation << "        }" << std::endl;
		implementation << "        else" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            return NULL;" << std::endl;
		implementation << "        }" << std::endl;
		implementation << "    }" << std::endl;
		implementation << "};" << std::endl;
		implementation << std::endl;
		implementation << "template<typename Literal>" << std::endl;
		implementation << "class StringParser" << std::endl;
		implementation << "{" << std::endl;
		implementation << "public:" << std::endl;
		implementation << "    static bool MatchCharacter(char value, " << full_namespace << "LengthString& index)" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "        if((index.length > 0) && ((*(index.data)) == value))" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            ++(index.data);" << std::endl;
		implementation << "            --(index.length);" << std::endl;
		implementation << "            return true;" << std::endl;
		implementation << "        }" << std::endl;
		implementation << "        else" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            return false;" << std::endl;
		implementation << "        }" << std::endl;
		implementation << "    }" << std::endl;
		implementation << std::endl;
		implementation << "    static " << full_namespace << "String* Parse(" << full_namespace << "LengthString& index)" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "        " << full_namespace << "LengthString start = index;" << std::endl;
		implementation << "        const char* literal_index = Literal::GetLiteral();" << std::endl;
		implementation << "        " << full_namespace << "LengthString data = {index.data, strlen(literal_index)};" << std::endl;
		implementation << "        " << std::endl;
		implementation << "        while((*literal_index) && (start.length > 0) && MatchCharacter(*literal_index, start))" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            ++literal_index;" << std::endl;
		implementation << "        }" << std::endl;
		implementation << "        " << std::endl;
		implementation << "        if((*literal_index) == 0)" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            index = start;" << std::endl;
		implementation << "            " << full_namespace << "String* string_node = new " << full_namespace << "String(data);" << std::endl;
		implementation << "            return string_node;" << std::endl;
		implementation << "        }" << std::endl;
		implementation << "        else" << std::endl;
		implementation << "        {" << std::endl;
		implementation << "            return NULL;" << std::endl;
		implementation << "        }" << std::endl;
		implementation << "    }" << std::endl;
		implementation << std::endl;
		implementation << "};" << std::endl;
		implementation << std::endl;
		implementation << "Node::Node()" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    data_.data = NULL;" << std::endl;
		implementation << "    data_.length = 0;" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "Node::~Node()" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    " << full_namespace << "ClearNodes(children_);" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "std::string Node::UnParse()" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    std::string data(data_.data, data_.length);" << std::endl;
		implementation << "    return data;" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << full_namespace << "LengthString Node::UnParseLString()" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    return data_;" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "std::list<" << full_namespace << "Node*> Node::GetChildren()" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    return children_;" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "void Node::SetString(" << full_namespace << "LengthString data)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    data_ = data;" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "void Node::SetChildren(std::list<" << full_namespace << "Node*> children)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    " << full_namespace << "ClearNodes(children_);" << std::endl;
		implementation << "    children_ = children;" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "String::String(" << full_namespace << "LengthString data)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    SetString(data);" << std::endl;
		implementation << "}" << std::endl;
		implementation << std::endl;
		implementation << "String::~String()" << std::endl;
		implementation << "{" << std::endl;
		implementation << "}" << std::endl;
	}

	void WriteClassDefinition(dsa::vent::tower::dbnf::Rule* rule, std::ostream& implementation, std::map<std::string, std::string> literal_names, std::string full_namespace)
	{
		std::string class_name = GenerateClassName(rule->GetName());
		std::map<std::string, std::string> members = GetMembers(rule, full_namespace);
		implementation << std::endl;
		implementation << class_name << "::" << class_name << "() : Node()" << std::endl;
		
		for (std::map<std::string, std::string>::iterator index = members.begin(); index != members.end();++index)
		{
			implementation << "    ," << index->first << "(NULL)" << std::endl;
		}

		implementation << "{" << std::endl;
		implementation << "}" << std::endl;

		for (std::map<std::string, std::string>::iterator index = members.begin(); index != members.end();++index)
		{
			implementation << std::endl;
			implementation << index->second << " " << class_name << "::" << GenerateAccessorName(index->first) << "()" << std::endl;
			implementation << "{" << std::endl;
			implementation << "    return " << index->first << ";" << std::endl;
			implementation << "}" << std::endl;
		}

		implementation << std::endl;
		implementation << class_name << "::~" << class_name << "()" << std::endl;
		implementation << "{" << std::endl;
		implementation << "}" << std::endl;

		implementation << std::endl;
		implementation << full_namespace << class_name << "* " << class_name << "::Parse(const char*& index)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    " << full_namespace << "LengthString length_string_index;" << std::endl;
		implementation << "    length_string_index.data = index;" << std::endl;
		implementation << "    length_string_index.length = strlen(index);" << std::endl;
		implementation << "    " << full_namespace << class_name << "* instance = Parse(length_string_index);" << std::endl;
		implementation << "    index = length_string_index.data;" << std::endl;
		implementation << "    return instance;" << std::endl;
		implementation << "}" << std::endl;

		implementation << std::endl;
		implementation << full_namespace << class_name << "* " << class_name << "::Parse(" << full_namespace << "LengthString& index)" << std::endl;
		implementation << "{" << std::endl;
		implementation << "    " << full_namespace << "LengthString start = index;" << std::endl;
		implementation << "    std::list<" << full_namespace << "Node*> children;" << std::endl;
		
		for (std::map<std::string, std::string>::iterator index = members.begin(); index != members.end();++index)
		{
			implementation << "    " << index->second << " " << GenerateMimicName(index->first) << " = NULL;" << std::endl;
		}

		implementation << std::endl;
		std::list<dsa::vent::tower::dbnf::Expression*> expressions = rule->GetExpressions()->GetList();
		
		for(std::list<dsa::vent::tower::dbnf::Expression*>::iterator index = expressions.begin();index != expressions.end();++index)
		{
			if ((*index)->GetTokenSequence()) {
				WriteExpression(*index, implementation, literal_names, full_namespace, class_name);
			}
		}

		implementation << "    " << full_namespace << "ClearNodes(children);" << std::endl;
		implementation << "    return NULL;" << std::endl;
		implementation << "}" << std::endl;
	}

	void WriteExpression(dsa::vent::tower::dbnf::Expression* expression, std::ostream& implementation, std::map<std::string, std::string> literal_names, std::string full_namespace, std::string class_name)
	{
		implementation << "    if ((" << full_namespace << "ClearNodes(children)";
		std::list<dsa::vent::tower::dbnf::Token*> token_sequence = expression->GetTokenSequence()->GetList();

		for (std::list<dsa::vent::tower::dbnf::Token*>::iterator index = token_sequence.begin();index != token_sequence.end();++index)
		{
			dsa::vent::tower::dbnf::Token* token = *index;
			std::string member = GenerateMemberName(token->GetName());
			std::string mimic = GenerateMimicName(member);
			implementation << " && ";
			std::string match_function = full_namespace + "Match";
			std::string match_function_parameters = "children, ";
			std::string parser = "";

			if (token->GetValue()->GetToken() != NULL)
			{
				parser = full_namespace + GenerateClassName(token->GetValue()->GetToken());
			}
			else if (token->GetValue()->GetLiteral() != NULL)
			{
				parser = "StringParser<" + literal_names[token->GetValue()->UnParse()] + ">";
			}
			else if ((token->GetValue()->GetHigh() != NULL) && (token->GetValue()->GetLow() != NULL))
			{
				parser = "CharacterParser<'\\" + token->GetValue()->UnParse().substr(1) + "'>";
			}

			if (token->GetName() != NULL)
			{
				match_function_parameters += mimic + ", ";
			}
			
			if (token->GetModifier() != NULL)
			{
				std::string modifier = token->GetModifier()->UnParse();

				if (modifier == "*")
				{
					parser = "MinimumParser<" + parser + ", 0>";
				}
				else if (modifier == "?")
				{
					match_function = full_namespace + "Optional";
				}
				else if (modifier == "+")
				{
					parser = "MinimumParser<" + parser + ", 1>";
				}
				else if (token->GetModifier()->GetCardinality() != NULL)
				{
					if(token->GetModifier()->GetCardinality()->GetMaximum() != NULL)
					{
						parser = "RangeParser<" + parser + ", " + token->GetModifier()->GetCardinality()->GetMinimum()->UnParse() + ", " + token->GetModifier()->GetCardinality()->GetMaximum()->UnParse()+ ">";
					}
					else if(token->GetModifier()->GetCardinality()->GetMinimum() != NULL)
					{
					    parser = "MinimumParser<" + parser + ", " + token->GetModifier()->GetCardinality()->GetMinimum()->UnParse() + ">";
					}
					else if(token->GetModifier()->GetCardinality()->GetCount() != NULL)
					{
						parser = "RangeParser<" + parser + ", " + token->GetModifier()->GetCardinality()->GetCount()->UnParse() + ", " + token->GetModifier()->GetCardinality()->GetCount()->UnParse()+ ">";
					}
				}
			}

			implementation << match_function << "(" << match_function_parameters << parser << "::Parse(index))";
		}

		implementation << ") || " + full_namespace + "Reset(start, index))" << std::endl;
		implementation << "    {" << std::endl;
		implementation << "        " << full_namespace << class_name << "* instance = new " << full_namespace << class_name << "();" << std::endl;
		implementation << "        " << full_namespace << "LengthString data;" << std::endl;
		implementation << "        data.length = start.length - index.length;" << std::endl;
		implementation << "        data.data = start.data;" << std::endl;
		implementation << "        instance->SetString(data);" << std::endl;
		implementation << "        instance->SetChildren(children);" << std::endl;
		token_sequence = expression->GetTokenSequence()->GetList();

		for (std::list<dsa::vent::tower::dbnf::Token*>::iterator index = token_sequence.begin();index != token_sequence.end();++index)
		{
			dsa::vent::tower::dbnf::Token* token = *index;
			std::string member = GenerateMemberName(token->GetName());

			if (member != "")
			{
				std::string mimic = GenerateMimicName(member);
				implementation << "        instance->" << member << " = " << mimic << ";" << std::endl;
			}
		}

		implementation << "        return instance;" << std::endl;
		implementation << "    }" << std::endl;
		implementation << std::endl;
	}

	std::string SanitizeLiteral(std::string dirty_literal)
	{
		std::string sanitized_literal;
		dirty_literal = ToUpper(dirty_literal);

		for(std::string::iterator index = dirty_literal.begin();index != dirty_literal.end();++index)
		{
			if (((*index >= 'A') && (*index <= 'Z')) ||
				((*index >= '0') && (*index <= '9')) ||
				(*index == '_'))
			{
				sanitized_literal += *index;
			}
		}

		if (sanitized_literal != "")
		{
			sanitized_literal += '_';
		}

		return sanitized_literal;
	}

	std::map<std::string, std::string> NameLiterals(std::set<std::string> literals)
	{
		std::map<std::string, std::string> named_literals;
		std::list<std::string> ordered_literals(literals.begin(), literals.end());
		ordered_literals.sort();
		int identifier = 0;

		for(std::list<std::string>::iterator index = ordered_literals.begin();index != ordered_literals.end();++index)
		{
			std::stringstream literal_name;
			literal_name << "LITERAL_" << SanitizeLiteral(*index) << "ID" << identifier;
			named_literals[*index] = literal_name.str();
			++identifier;
		}

		return named_literals;
	}
	
	std::set<std::string> GetGrammarLiterals(dsa::vent::tower::dbnf::Grammar* grammar)
	{
		std::set<std::string> literals;
		std::list<dsa::vent::tower::dbnf::Rule*> rules = grammar->GetRules()->GetList();

		for(std::list<dsa::vent::tower::dbnf::Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			if ((*index)->GetName()) {
				std::set<std::string> rule_literals = GetRuleLiterals(*index);
				literals.insert(rule_literals.begin(), rule_literals.end());
			}
		}

		return literals;
	}

	std::set<std::string> GetRuleLiterals(dsa::vent::tower::dbnf::Rule* rule)
	{
		std::set<std::string> literals;
		std::list<dsa::vent::tower::dbnf::Expression*> expressions = rule->GetExpressions()->GetList();
		
		for(std::list<dsa::vent::tower::dbnf::Expression*>::iterator expression = expressions.begin();expression != expressions.end();++expression)
		{
			if ((*expression)->GetTokenSequence()) {
				std::list<dsa::vent::tower::dbnf::Token*> token_sequence = (*expression)->GetTokenSequence()->GetList();

				for (std::list<dsa::vent::tower::dbnf::Token*>::iterator index = token_sequence.begin();index != token_sequence.end();++index)
				{
					dsa::vent::tower::dbnf::Token* token = *index;
					dsa::vent::tower::dbnf::SimpleToken* value = token->GetValue();

					if (value->GetLiteral())
					{
						literals.insert(value->UnParse());
					}
				}
			}
		}

		return literals;
	}

	std::list<std::string> TokenizeBaseName(std::string name)
	{
		std::list<std::string> base_name_tokens;
		std::stringstream splitter(name);
		std::string item;
		
		while(std::getline(splitter, item, '.'))
		{
			base_name_tokens.push_back(item);
		}

		base_name_tokens.pop_back();
		return base_name_tokens;
	}

	std::string GenerateGuardName(std::list<std::string> base_name_tokens)
	{
		std::string guard_name;
		std::locale locale;

		for(std::list<std::string>::iterator base_name_token = base_name_tokens.begin();base_name_token != base_name_tokens.end();++base_name_token)
		{
			guard_name += ToUpper(*base_name_token) + "_";
		}

		guard_name += "DBNF_H";
		return guard_name;
	}

	std::string GenerateAccessorName(std::string member)
	{
		return "Get" + SnakeCaseToCamelCase(member);
	}

	std::string GenerateFullNamespace(std::list<std::string> base_name_tokens)
	{
		std::string full_namespace;

		for(std::list<std::string>::iterator base_name_token = base_name_tokens.begin();base_name_token != base_name_tokens.end();++base_name_token)
		{
			full_namespace += ToLower(*base_name_token) + "::";
		}

		full_namespace += "dbnf::";
		return full_namespace;
	}

	std::map<std::string, std::string> GetMembers(dsa::vent::tower::dbnf::Rule* rule, std::string full_namespace)
	{
		std::map<std::string, std::string> members;
		std::list<dsa::vent::tower::dbnf::Expression*> expressions = rule->GetExpressions()->GetList();
		
		for(std::list<dsa::vent::tower::dbnf::Expression*>::iterator expression = expressions.begin();expression != expressions.end();++expression)
		{
			if ((*expression)->GetTokenSequence()) {
				std::list<dsa::vent::tower::dbnf::Token*> token_sequence = (*expression)->GetTokenSequence()->GetList();

				for (std::list<dsa::vent::tower::dbnf::Token*>::iterator index = token_sequence.begin();index != token_sequence.end();++index)
				{
					dsa::vent::tower::dbnf::Token* token = *index;
					std::string token_member_name = GenerateMemberName(token->GetName());

					if(token_member_name != "")
					{
						std::string token_type_name = full_namespace + GenerateClassName(token->GetValue()->GetToken());
						std::string previous_type = members[token_member_name];
						std::string modifier = "";

						if (token->GetModifier() != NULL)
						{
							modifier = token->GetModifier()->UnParse();
						}

						if ((token->GetValue()->GetHigh() != NULL) ||
							(token->GetValue()->GetLow() != NULL) ||
							(token->GetValue()->GetLiteral() != NULL))
						{
							token_type_name = full_namespace + "String";
						}

						if ((modifier == "*") ||
							(modifier == "+") ||
							(modifier[0] == '{'))
						{
							token_type_name = "List<" + token_type_name + ">";
						}

						token_type_name = token_type_name + "*";

						if ((previous_type != "") && (previous_type != token_type_name))
						{
							if ((modifier == "*") ||
								(modifier == "+") ||
								(modifier[0] == '{'))
							{
								token_type_name = "List<" + full_namespace + "Node>*";
							}
							else
							{
								token_type_name = full_namespace + "Node*";
							}
						}

						members[token_member_name] = token_type_name;
					}
				}
			}
		}

		return members;
	}

	std::string GenerateClassName(dsa::vent::tower::dbnf::Name* name_node)
	{
		if (name_node)
		{
			return SnakeCaseToCamelCase(name_node->UnParse());
		}
		else
		{
			return "";
		}
	}

	std::string SnakeCaseToCamelCase(std::string snake_case)
	{
		bool capitalize_this_letter = true;
		std::string camel_case = "";

		for(std::string::iterator index = snake_case.begin();index != snake_case.end();++index)
		{
			if(*index == '_')
			{
				capitalize_this_letter = true;
			}
			else if(capitalize_this_letter)
			{
				capitalize_this_letter = false;
				camel_case += static_cast<char>(toupper(*index));
			}
			else
			{
				capitalize_this_letter = false;
				camel_case += *index;
			}
		}

		return camel_case;
	}

	std::string GenerateMemberName(dsa::vent::tower::dbnf::Name* name_node)
	{
		if(name_node)
		{
			return name_node->UnParse() + "_";
		}
		else
		{
			return "";
		}
	}

	std::string GenerateMimicName(std::string member)
	{
		if (member.size() > 0)
		{
			return member.substr(0, member.size() - 1);
		}
		
		return "";
	}

	std::string ToLower(std::string string)
	{
		std::transform(string.begin(), string.end(), string.begin(), tolower);
		return string;
	}

	std::string ToUpper(std::string string)
	{
		std::transform(string.begin(), string.end(), string.begin(), toupper);
		return string;
	}
};
};
};
};

static int AddCPPGenerator()
{
	static dsa::vent::tower::CPPGenerator g_cpp_generator;
	dsa::vent::tower::Generator::AddGenerator("DSA::Vent::Tower::CPPGenerator", &g_cpp_generator);
	return 0;
}

static int initializer = AddCPPGenerator();
