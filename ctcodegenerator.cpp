#include <algorithm>
#include <fstream>
#include <iostream>
#include <locale>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>

#include "DSA.Vent.Tower.dbnf.hpp"
#include "generator.hpp"

using namespace dsa::vent::tower::dbnf;

template<typename T>
T raw(T value) { return value;}

std::vector<Rule*> UnwrapOmniList(RuleList* value) { return value->GetVector();}
std::vector<Token*> UnwrapOmniList(TokenList* value) { return value->GetVector();}
std::vector<Expression*> UnwrapOmniList(ExpressionList* value) { return value->GetVector();}

template<typename T>
T sequence(T value) { return value;}

namespace dsa
{
namespace vent
{
namespace tower
{
class CTCodeGenerator : public dsa::vent::tower::Generator
{
public:
	CTCodeGenerator()
	{
	}
	virtual ~CTCodeGenerator()
	{
	}

	virtual int GenerateParser(const char* buffer, std::string base_name)
	{
		const char* index = buffer;
		std::cout << "Parsing Grammar..." << std::endl;
		Grammar* grammar = Grammar::Parse(index);

		if(grammar)
		{
			std::cout << "Grammar parsed!" << std::endl;
			std::cout << "Generating CTCode..." << std::endl;
			std::ofstream ctcode(base_name + ".ctcode", std::ofstream::trunc | std::ofstream::out);
			WriteClasses(grammar, ctcode);
			std::cout << "Done!" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Failed to parse Grammar" << std::endl;
			return 1;
		}
	}

	void WriteClasses(Grammar* grammar, std::ostream& ctcode)
	{
		std::vector<Rule*> rules = UnwrapOmniList(grammar->GetRules());
		ctcode << "class StringParser" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function bool ParseSingleSave(LengthString index, string value, StringResult result)" << std::endl;
		ctcode << "    {" << std::endl;
        ctcode << "        int index_start = index.GetStart();" << std::endl;
		ctcode << "        int index_length = index.GetLength();" << std::endl;
        ctcode << "        LengthString consumed_string = new LengthString;" << std::endl;
        ctcode << "        consumed_string.SetData(index.GetData());" << std::endl;
        ctcode << "        consumed_string.SetStart(index.GetStart());" << std::endl;
        ctcode << "        consumed_string.SetLength(0);" << std::endl;
        ctcode << "        String instance = new String;" << std::endl;
		ctcode << "        int value_length = Length(value);" << std::endl;
		ctcode << std::endl;
		ctcode << "        if (value_length > index.GetLength())" << std::endl;
		ctcode << "        {" << std::endl;
		ctcode << "            result.SetResult(false);" << std::endl;
		ctcode << "            return false;" << std::endl;
		ctcode << "        }" << std::endl;
		ctcode << std::endl;
		ctcode << "        int offset_index = 0;" << std::endl;
		ctcode << std::endl;
		ctcode << "        while (offset_index < value_length)" << std::endl;
		ctcode << "        {" << std::endl;
		ctcode << "            if (At(index.GetData(), index.GetStart() + offset_index) != At(value, offset_index))" << std::endl;
		ctcode << "            {" << std::endl;
		ctcode << "                result.SetResult(false);" << std::endl;
		ctcode << "                return false;" << std::endl;
		ctcode << "            }" << std::endl;
		ctcode << std::endl;
		ctcode << "            offset_index = offset_index + 1;" << std::endl;
		ctcode << "        }" << std::endl;
		ctcode << std::endl;
		ctcode << "        index.SetStart(index.GetStart() + value_length);" << std::endl;
		ctcode << "        index.SetLength(index.GetLength() - value_length);" << std::endl;
		ctcode << "        consumed_string.SetLength(index.GetStart() - index_start);" << std::endl;
		ctcode << "        instance.SetLengthString(consumed_string);" << std::endl;
		ctcode << "        result.SetValue(instance);" << std::endl;
		ctcode << "        result.SetResult(true);" << std::endl;
		ctcode << "        return true;" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << "    function bool ParseSingle(LengthString index, string value)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        StringResult result = new StringResult;" << std::endl;
		ctcode << "        return ParseSingleSave(index, value, result);" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class StringResult" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetValue(String new_value) { value = new_value; }" << std::endl;
		ctcode << "    function String GetValue() { return value; }" << std::endl;
		ctcode << "    function void SetResult(bool new_result) { result = new_result; }" << std::endl;
		ctcode << "    function bool GetResult() { return result; }" << std::endl;
		ctcode << std::endl;
		ctcode << "    String value;" << std::endl;
		ctcode << "    bool result;" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class StringListResult" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetValue(String[] new_value) { value = new_value; }" << std::endl;
		ctcode << "    function String[] GetValue() { return value; }" << std::endl;
		ctcode << "    function void SetResult(bool new_result) { result = new_result; }" << std::endl;
		ctcode << "    function bool GetResult() { return result; }" << std::endl;
		ctcode << std::endl;
		ctcode << "    String[] value;" << std::endl;
		ctcode << "    bool result;" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class String" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetLengthString(LengthString new_value)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        length_string = new LengthString;" << std::endl;
		ctcode << "        length_string.SetData(new_value.GetData());" << std::endl;
		ctcode << "        length_string.SetStart(new_value.GetStart());" << std::endl;
		ctcode << "        length_string.SetLength(new_value.GetLength());" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << std::endl;
		ctcode << "    function string UnParse() { return length_string.GetString(); }" << std::endl;
		ctcode << std::endl;
		ctcode << "    LengthString length_string;" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;

		ctcode << "class CharacterParser" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function bool ParseSingle(LengthString index, int value)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        if (0 == index.GetLength())" << std::endl;
		ctcode << "        {" << std::endl;
		ctcode << "            return false;" << std::endl;
		ctcode << "        }" << std::endl;
		ctcode << std::endl;
		ctcode << "        int current_character = IntAt(index.GetData(), index.GetStart());" << std::endl;
		ctcode << std::endl;
		ctcode << "        if (current_character == value)" << std::endl;
		ctcode << "        {" << std::endl;
		ctcode << "            index.SetStart(index.GetStart() + 1);" << std::endl;
		ctcode << "            index.SetLength(index.GetLength() - 1);" << std::endl;
		ctcode << "            return true;" << std::endl;
		ctcode << "        }" << std::endl;
		ctcode << std::endl;
		ctcode << "        return false;" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class CharacterResult" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetValue(Character new_value) { value = new_value; }" << std::endl;
		ctcode << "    function Character GetValue() { return value; }" << std::endl;
		ctcode << "    function void SetResult(bool new_result) { result = new_result; }" << std::endl;
		ctcode << "    function bool GetResult() { return result; }" << std::endl;
		ctcode << std::endl;
		ctcode << "    Character value;" << std::endl;
		ctcode << "    bool result;" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class CharacterListResult" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetValue(Character[] new_value) { value = new_value; }" << std::endl;
		ctcode << "    function Character[] GetValue() { return value; }" << std::endl;
		ctcode << "    function void SetResult(bool new_result) { result = new_result; }" << std::endl;
		ctcode << "    function bool GetResult() { return result; }" << std::endl;
		ctcode << std::endl;
		ctcode << "    Character[] value;" << std::endl;
		ctcode << "    bool result;" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class Character" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetLengthString(LengthString new_value)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        length_string = new LengthString;" << std::endl;
		ctcode << "        length_string.SetData(new_value.GetData());" << std::endl;
		ctcode << "        length_string.SetStart(new_value.GetStart());" << std::endl;
		ctcode << "        length_string.SetLength(new_value.GetLength());" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << std::endl;
		ctcode << "    function string UnParse() { return length_string.GetString(); }" << std::endl;
		ctcode << std::endl;
		ctcode << "    LengthString length_string;" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;


		ctcode << "class ParserNetwork" << std::endl;
		ctcode << "{" << std::endl;

		for(std::vector<Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			Rule* rule = (*index);

			if ((*index)->GetName()) {
				std::string class_name = GenerateClassName(raw(rule->GetName())) + "Parser";
				std::string field_name = CamelCaseToSnakeCase(class_name) + "_field";
				ctcode << "    " << class_name << " " << field_name << ";" << std::endl;
				ctcode << "    function " << class_name << " " << GenerateGetterName(field_name) << "() { return " << field_name << "; }" << std::endl;
			}
		}

		std::string string_parser_class_name = "StringParser";
		std::string string_parser_field_name = CamelCaseToSnakeCase(string_parser_class_name) + "_field";
		std::string character_parser_class_name = "CharacterParser";
		std::string character_parser_field_name = CamelCaseToSnakeCase(character_parser_class_name) + "_field";

		ctcode << "    " << string_parser_class_name << " " << string_parser_field_name << ";" << std::endl;
		ctcode << "    function " << string_parser_class_name << " " << GenerateGetterName(string_parser_field_name) << "() { return " << string_parser_field_name << ";}" << std::endl;
		ctcode << "    " << character_parser_class_name << " " << character_parser_field_name << ";" << std::endl;
		ctcode << "    function " << character_parser_class_name << " " << GenerateGetterName(character_parser_field_name) << "() { return " << character_parser_field_name << ";}" << std::endl;

		ctcode << "    function void Initialize() {" << std::endl;

		for(std::vector<Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			Rule* rule = (*index);

			if ((*index)->GetName()) {
				std::string class_name = GenerateClassName(raw(rule->GetName())) + "Parser";
				std::string field_name = CamelCaseToSnakeCase(class_name) + "_field";
				ctcode << "        " << field_name << " = new " << class_name << ";" << std::endl;
				ctcode << "        " << field_name << ".SetParserNetwork(myself);" << std::endl;
			}
		}

		ctcode << "        " << string_parser_field_name << " = new " << string_parser_class_name << ";" << std::endl;
		ctcode << "        " << character_parser_field_name << " = new " << character_parser_class_name << ";" << std::endl;

		ctcode << "    }" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class DBNFOmniType" << std::endl;
		ctcode << "{" << std::endl;

		for(std::vector<Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			Rule* rule = (*index);

			if ((*index)->GetName()) {
				std::string class_name = GenerateClassName(raw(rule->GetName()));
				std::string field_name = CamelCaseToSnakeCase(class_name) + "_field";
				ctcode << "    " << class_name << " " << field_name << ";" << std::endl;
				ctcode << "    function void " << GenerateSetterName(field_name) << "(" << class_name << " input_value) { " << field_name << " = input_value; }" << std::endl;
				ctcode << "    function " << class_name << " " << GenerateGetterName(field_name) << "() { return " << field_name << "; }" << std::endl;
			}
		}

		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class DBNFOmniTypeResult" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetValue(DBNFOmniType new_value) { value = new_value; }" << std::endl;
		ctcode << "    function DBNFOmniType GetValue() { return value; }" << std::endl;
		ctcode << "    function void SetResult(bool new_result) { result = new_result; }" << std::endl;
		ctcode << "    function bool GetResult() { return result; }" << std::endl;

		for(std::vector<Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			Rule* rule = (*index);

			if ((*index)->GetName()) {
				std::string class_name = GenerateClassName(raw(rule->GetName()));
				std::string field_name = CamelCaseToSnakeCase(class_name) + "_field";
				ctcode << "    function void " << GenerateSetterName(field_name) << "(" << class_name << " input_value)" << std::endl;
				ctcode << "    {" << std::endl;
				ctcode << "        value = new DBNFOmniType;" << std::endl;
				ctcode << "        value." << GenerateSetterName(field_name) << "(input_value);" << std::endl;
				ctcode << "    }" << std::endl;
			}
		}

		ctcode << std::endl;
		ctcode << "    DBNFOmniType value;" << std::endl;
		ctcode << "    bool result;" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class DBNFOmniTypeListResult" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetValue(DBNFOmniType[] new_value) { value = new_value; }" << std::endl;
		ctcode << "    function DBNFOmniType[] GetValue() { return value; }" << std::endl;
		ctcode << "    function void SetResult(bool new_result) { result = new_result; }" << std::endl;
		ctcode << "    function bool GetResult() { return result; }" << std::endl;

		for(std::vector<Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			Rule* rule = (*index);

			if ((*index)->GetName()) {
				std::string class_name = GenerateClassName(raw(rule->GetName()));
				std::string field_name = CamelCaseToSnakeCase(class_name) + "_field";
				ctcode << "    function void " << GenerateSetterName(field_name) << "(" << class_name << "[] input_value)" << std::endl;
				ctcode << "    {" << std::endl;
				ctcode << "        int index = 0;" << std::endl;
				ctcode << "        while (index < Size(input_value))" << std::endl;
				ctcode << "        {" << std::endl;
				ctcode << "            DBNFOmniType value = new DBNFOmniType;" << std::endl;
				ctcode << "            value." << GenerateSetterName(field_name) << "(Element(input_value, index));" << std::endl;
				ctcode << "            index = index + 1;" << std::endl;
				ctcode << "        }" << std::endl;
				ctcode << "    }" << std::endl;
				ctcode << std::endl;
			}
		}

		ctcode << "    DBNFOmniType[] value;" << std::endl;
		ctcode << "    bool result;" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class LengthString" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetData(string new_data) { data = new_data; }" << std::endl;
		ctcode << "    function string GetData() { return data; }" << std::endl;
		ctcode << "    function void SetStart(int new_start) { start = new_start; }" << std::endl;
		ctcode << "    function int GetStart() { return start; }" << std::endl;
		ctcode << "    function void SetLength(int new_length) { length = new_length; }" << std::endl;
		ctcode << "    function int GetLength() { return length; }" << std::endl;
		ctcode << "    function string GetString()" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        string result;" << std::endl;
		ctcode << "        int index = start;" << std::endl;
		ctcode << "        int end = start + length;" << std::endl;
		ctcode <<  std::endl;
		ctcode << "        while (index < end)" << std::endl;
		ctcode << "        {" << std::endl;
		ctcode << "            result = Concat(result, At(data, index));" << std::endl;
		ctcode << "            index = index + 1;" << std::endl;
		ctcode << "        }" << std::endl;
		ctcode <<  std::endl;
		ctcode << "        return result;" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << std::endl;
		ctcode << "    string data;" << std::endl;
		ctcode << "    int start;" << std::endl;
		ctcode << "    int length;" << std::endl;
		ctcode << "}" << std::endl;

		for(std::vector<Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			Rule* rule = (*index);
			
			if ((*index)->GetName()) {
				WriteClass(grammar, *index, ctcode);
			}
		}
	}

	void WriteExpression(Expression* expression, std::ostream& ctcode)
	{
		ctcode << "        if (true";

		std::vector<Token*> token_sequence = UnwrapOmniList(expression->GetTokenSequence());

		for (std::vector<Token*>::iterator index = token_sequence.begin();index != token_sequence.end();++index)
		{
			Token* token = *index;
			std::string member = GenerateMemberName(raw(token->GetName()));
			ctcode << " && ";
			std::string match_function = "ParseSingle";
			std::string match_function_parameters = "index";
			std::string parser = "";

			if (token->GetValue()->GetToken())
			{
				parser = GenerateClassName(raw(token->GetValue()->GetToken())) + "Parser";
			}
			else if (token->GetValue()->GetLiteral())
			{
				parser = "StringParser";
				match_function_parameters += ", " + token->GetValue()->UnParse();
			}
			else if ((token->GetValue()->GetHigh()) && (token->GetValue()->GetLow()))
			{
				parser = "CharacterParser";
				match_function_parameters += ", " + token->GetValue()->UnParse();
			}

			if (token->GetName())
			{
				match_function_parameters += ", " + member;
			}

			if (token->GetModifier())
			{
				std::string modifier = token->GetModifier()->UnParse();

				if (modifier == "*")
				{
					match_function = "ParseMany";
					match_function_parameters += ", 0, -1";
				}
				else if (modifier == "?")
				{
					match_function = "ParseOptional";
				}
				else if (modifier == "+")
				{
					match_function = "ParseMany";
					match_function_parameters += ", 1, -1";
				}
				else if (token->GetModifier()->GetCardinality())
				{
					match_function = "ParseMany";

					if(token->GetModifier()->GetCardinality()->GetMaximum())
					{
						match_function_parameters += ", " + token->GetModifier()->GetCardinality()->GetMinimum()->UnParse() + ", " + token->GetModifier()->GetCardinality()->GetMaximum()->UnParse();
					}
					else if(token->GetModifier()->GetCardinality()->GetMinimum())
					{
						match_function_parameters += ", " + token->GetModifier()->GetCardinality()->GetMinimum()->UnParse() + ", -1";
					}
					else if(token->GetModifier()->GetCardinality()->GetCount())
					{
						match_function_parameters += ", " + token->GetModifier()->GetCardinality()->GetCount()->UnParse() + ", " + token->GetModifier()->GetCardinality()->GetCount()->UnParse();
					}
				}
			}

			if (token->GetName())
			{
				match_function += "Save";
			}

			std::string parser_instance_name = CamelCaseToSnakeCase(parser) + "_instance";
			ctcode << parser_instance_name << "." << match_function << "(" << match_function_parameters << ")";
		}

		ctcode << ") {" << std::endl;
	}

	void WriteClass(Grammar* grammar, Rule* rule, std::ostream& ctcode)
	{
		std::string class_name = GenerateClassName(raw(rule->GetName()));
		std::map<std::string, std::pair<std::string, bool>> members = GetMembers(rule);
		ctcode << std::endl;
		ctcode << "class " << class_name << "Parser" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    ParserNetwork parser_network;" << std::endl;
		ctcode << "    function void SetParserNetwork(ParserNetwork input) { parser_network = input; }" << std::endl;
		ctcode << "    function bool ParseSingleSave(LengthString index, " << class_name << "Result result)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        int index_start = index.GetStart();" << std::endl;
		ctcode << "        int index_length = index.GetLength();" << std::endl;
		ctcode << "        LengthString consumed_string = new LengthString;" << std::endl;
		ctcode << "        consumed_string.SetData(index.GetData());" << std::endl;
		ctcode << "        consumed_string.SetStart(index.GetStart());" << std::endl;
		ctcode << "        consumed_string.SetLength(0);" << std::endl;
		ctcode << "        " << class_name << " instance = new " << class_name << ";" << std::endl;

		if(members.size() > 0)
		{
			for (std::map<std::string, std::pair<std::string, bool>>::iterator index = members.begin(); index != members.end();++index)
			{
				if (index->second.second) {
					ctcode << "        " << index->second.first << "ListResult " << index->first << " = new " << index->second.first << "ListResult;" << std::endl;
				} else {
					ctcode << "        " << index->second.first << "Result " << index->first << " = new " << index->second.first << "Result;" << std::endl;
				}
			}
		}

		ctcode << std::endl;
		std::vector<Rule*> rules = UnwrapOmniList(grammar->GetRules());

		for(std::vector<Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			Rule* rule_index = (*index);

			if ((*index)->GetName()) {
				std::string class_name = GenerateClassName(raw(rule_index->GetName())) + "Parser";
				std::string field_name = CamelCaseToSnakeCase(class_name) + "_field";
				std::string local_name = CamelCaseToSnakeCase(class_name) + "_instance";
				ctcode << "        " << class_name << " " << local_name << " = parser_network." << GenerateGetterName(field_name) << "();" << std::endl;
			}
		}

		std::string string_parser_class_name = "StringParser";
		std::string string_parser_field_name = CamelCaseToSnakeCase(string_parser_class_name) + "_field";
		std::string string_parser_local_name = CamelCaseToSnakeCase(string_parser_class_name) + "_instance";
		ctcode << "        " << string_parser_class_name << " " << string_parser_local_name << " = parser_network." << GenerateGetterName(string_parser_field_name) << "();" << std::endl;

		std::string character_parser_class_name = "CharacterParser";
		std::string character_parser_field_name = CamelCaseToSnakeCase(character_parser_class_name) + "_field";
		std::string character_parser_local_name = CamelCaseToSnakeCase(character_parser_class_name) + "_instance";
		ctcode << "        " << character_parser_class_name << " " << character_parser_local_name << " = parser_network." << GenerateGetterName(character_parser_field_name) << "();" << std::endl;

		ctcode << std::endl;
		std::vector<Expression*> expressions = UnwrapOmniList(rule->GetExpressions());

		for(std::vector<Expression*>::iterator index = expressions.begin();index != expressions.end();++index)
		{
			if (sequence((*index)->GetTokenSequence())) {
				WriteExpression(*index, ctcode);

				for (std::map<std::string, std::pair<std::string, bool>>::iterator index = members.begin(); index != members.end();++index)
				{
					ctcode << "            instance." << GenerateSetterName(index->first) << "(" << index->first << ".GetValue());" << std::endl;
				}

				ctcode << "            consumed_string.SetLength(index.GetStart() - index_start);" << std::endl;
				ctcode << "            instance.SetLengthString(consumed_string);" << std::endl;
				ctcode << "            result.SetValue(instance);" << std::endl;
				ctcode << "            result.SetResult(true);" << std::endl;
				ctcode << "            return result.GetResult();" << std::endl;
				ctcode << "        } else {" << std::endl;
				ctcode << "            index.SetStart(index_start);" << std::endl;
				ctcode << "            index.SetLength(index_length);" << std::endl;

				for (std::map<std::string, std::pair<std::string, bool>>::iterator index = members.begin(); index != members.end();++index)
				{
					if (index->second.second) {
						ctcode << "            " << index->first << " = new " << index->second.first << "ListResult;" << std::endl;
					} else {
						ctcode << "            " << index->first << " = new " << index->second.first << "Result;" << std::endl;
					}
				}

				ctcode << "        }" << std::endl;
				ctcode << std::endl;
			}
		}

		ctcode << "        result.SetResult(false);" << std::endl;
		ctcode << "        return result.GetResult();" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << std::endl;
		ctcode << "    function bool ParseSingle(LengthString index)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        " << class_name << "Result result = new " << class_name << "Result;" << std::endl;
		ctcode << "        return ParseSingleSave(index, result);" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << std::endl;
		ctcode << "    function bool ParseOptionalSave(LengthString index, " << class_name << "Result result)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        ParseSingleSave(index, result);" << std::endl;
		ctcode << "        result.SetResult(true);" << std::endl;
		ctcode << "        return true;" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << std::endl;
		ctcode << "    function bool ParseOptional(LengthString index)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        " << class_name << "Result result = new " << class_name << "Result;" << std::endl;
		ctcode << "        return ParseOptionalSave(index, result);" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << std::endl;
		ctcode << "    function bool ParseManySave(LengthString index, " << class_name << "ListResult list_result, int minimum, int maximum)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        int index_start = index.GetStart();" << std::endl;
		ctcode << "        int index_length = index.GetLength();" << std::endl;
		ctcode << "        " << class_name << "[] results;" << std::endl;
		ctcode << "        int count = 0;" << std::endl;
		ctcode << "        int max_check = maximum;" << std::endl;
		ctcode << "        bool check_next = true;" << std::endl;
		ctcode << std::endl;
		ctcode << "        if (maximum < 0)" << std::endl;
		ctcode << "        {" << std::endl;
		ctcode << "            max_check = count + 1;" << std::endl;
		ctcode << "        }" << std::endl;
		ctcode << std::endl;
		ctcode << "        while (check_next && count < max_check)" << std::endl;
		ctcode << "        {" << std::endl;
		ctcode << "            " << class_name << "Result result = new " << class_name << "Result;" << std::endl;
		ctcode << "            ParseSingleSave(index, result);" << std::endl;
		ctcode << "            check_next = result.GetResult();" << std::endl;
		ctcode << std::endl;
		ctcode << "            if (result.GetResult())" << std::endl;
		ctcode << "            {" << std::endl;
		ctcode << "                count = count + 1;" << std::endl;
		ctcode << "                Append(results, result.GetValue());" << std::endl;
		ctcode << "            }" << std::endl;
		ctcode << std::endl;
		ctcode << "            if (maximum < 0)" << std::endl;
		ctcode << "            {" << std::endl;
		ctcode << "                max_check = count + 1;" << std::endl;
		ctcode << "            }" << std::endl;
		ctcode << "        }" << std::endl;
		ctcode << std::endl;
		ctcode << "        if (count >= minimum && count <= max_check)" << std::endl;
		ctcode << "        {" << std::endl;
		ctcode << "            list_result.SetValue(results);" << std::endl;
		ctcode << "            list_result.SetResult(true);" << std::endl;
		ctcode << "        } else {" << std::endl;
		ctcode << "            index.SetStart(index_start);" << std::endl;
		ctcode << "            index.SetLength(index_length);" << std::endl;
		ctcode << "            list_result.SetResult(false);" << std::endl;
		ctcode << "        }" << std::endl;
		ctcode << std::endl;
		ctcode << "        return list_result.GetResult();" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << std::endl;
		ctcode << "    function bool ParseMany(LengthString index, int minimum, int maximum)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        " << class_name << "ListResult result = new " << class_name << "ListResult;" << std::endl;
		ctcode << "        return ParseManySave(index, result, minimum, maximum);" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class " << class_name << "Result" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetValue(" << class_name << " new_value) { value = new_value; }" << std::endl;
		ctcode << "    function " << class_name << " GetValue() { return value; }" << std::endl;
		ctcode << "    function void SetResult(bool new_result) { result = new_result; }" << std::endl;
		ctcode << "    function bool GetResult() { return result; }" << std::endl;
		ctcode << std::endl;
		ctcode << "    " << class_name << " value;" << std::endl;
		ctcode << "    bool result;" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class " << class_name << "ListResult" << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetValue(" << class_name << "[] new_value) { value = new_value; }" << std::endl;
		ctcode << "    function " << class_name << "[] GetValue() { return value; }" << std::endl;
		ctcode << "    function void SetResult(bool new_result) { result = new_result; }" << std::endl;
		ctcode << "    function bool GetResult() { return result; }" << std::endl;
		ctcode << std::endl;
		ctcode << "    " << class_name << "[] value;" << std::endl;
		ctcode << "    bool result;" << std::endl;
		ctcode << "}" << std::endl;
		ctcode << std::endl;
		ctcode << "class " << class_name << std::endl;
		ctcode << "{" << std::endl;
		ctcode << "    function void SetLengthString(LengthString new_value)" << std::endl;
		ctcode << "    {" << std::endl;
		ctcode << "        length_string = new LengthString;" << std::endl;
		ctcode << "        length_string.SetData(new_value.GetData());" << std::endl;
		ctcode << "        length_string.SetStart(new_value.GetStart());" << std::endl;
		ctcode << "        length_string.SetLength(new_value.GetLength());" << std::endl;
		ctcode << "    }" << std::endl;
		ctcode << std::endl;
		ctcode << "    function string UnParse() { return length_string.GetString(); }" << std::endl;
		if(members.size() > 0)
		{
			for (std::map<std::string, std::pair<std::string, bool>>::iterator index = members.begin(); index != members.end();++index)
			{
				std::string list_suffix = "";

				if (index->second.second) {
					list_suffix = "[]";
				}

				ctcode << "    function void " << GenerateSetterName(index->first) << "(" << index->second.first << list_suffix << " input_value) { " << index->first << " = input_value; }" << std::endl;
				ctcode << "    function " << index->second.first << list_suffix << " " << GenerateGetterName(index->first) << "() { return " << index->first << "; }" << std::endl;
			}
		}

		ctcode << std::endl;
		ctcode << "    LengthString length_string;" << std::endl;

		if(members.size() > 0)
		{
			for (std::map<std::string, std::pair<std::string, bool>>::iterator index = members.begin(); index != members.end();++index)
			{
				std::string list_suffix = "";

				if (index->second.second) {
					list_suffix = "[]";
				}

				ctcode << "    " << index->second.first << list_suffix << " " << index->first << ";" << std::endl;
			}
		}

		ctcode << "}" << std::endl;
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

	std::set<std::string> GetGrammarLiterals(Grammar* grammar)
	{
		std::set<std::string> literals;
		std::vector<Rule*> rules = UnwrapOmniList(grammar->GetRules());

		for(std::vector<Rule*>::iterator index = rules.begin();index != rules.end();++index)
		{
			if ((*index)->GetName()) {
				std::set<std::string> rule_literals = GetRuleLiterals(*index);
				literals.insert(rule_literals.begin(), rule_literals.end());
			}
		}

		return literals;
	}

	std::set<std::string> GetRuleLiterals(Rule* rule)
	{
		std::set<std::string> literals;
		std::vector<Expression*> expressions = UnwrapOmniList(rule->GetExpressions());

		for(std::vector<Expression*>::iterator expression = expressions.begin();expression != expressions.end();++expression)
		{
			if (sequence((*expression)->GetTokenSequence())) {
				std::vector<Token*> token_sequence = UnwrapOmniList((*expression)->GetTokenSequence());

				for (std::vector<Token*>::iterator index = token_sequence.begin();index != token_sequence.end();++index)
				{
					Token* token = *index;
					SimpleToken* value = raw(token->GetValue());

					if (value->GetLiteral())
					{
						literals.insert(value->UnParse());
					}
				}
			}
		}

		return literals;
	}

	std::map<std::string, std::pair<std::string, bool>> GetMembers(Rule* rule)
	{
		std::map<std::string, std::pair<std::string, bool>> members;
		std::vector<Expression*> expressions = UnwrapOmniList(rule->GetExpressions());

		for(std::vector<Expression*>::iterator expression = expressions.begin();expression != expressions.end();++expression)
		{
			if (sequence((*expression)->GetTokenSequence())) {
				std::vector<Token*> token_sequence = UnwrapOmniList((*expression)->GetTokenSequence());

				for (std::vector<Token*>::iterator index = token_sequence.begin();index != token_sequence.end();++index)
				{
					Token* token = *index;
					std::string token_member_name = GenerateMemberName(raw(token->GetName()));

					if(token_member_name != "")
					{
						std::string token_type_name = GenerateClassName(raw(token->GetValue()->GetToken()));
						bool is_list = false;
						std::string previous_type = members[token_member_name].first;
						std::string modifier = "";

						if (token->GetModifier())
						{
							modifier = token->GetModifier()->UnParse();
						}

						if ((token->GetValue()->GetHigh()) ||
							(token->GetValue()->GetLow()) ||
							(token->GetValue()->GetLiteral()))
						{
							token_type_name = "String";
						}

						if ((modifier == "*") ||
							(modifier == "+") ||
							(modifier[0] == '{'))
						{
							is_list = true;
						}

						if ((previous_type != "") && (previous_type != token_type_name))
						{
							if ((modifier == "*") ||
								(modifier == "+") ||
								(modifier[0] == '{'))
							{
								is_list = true;
								token_type_name = "DBNFOmniType";
							}
							else
							{
								token_type_name = "DBNFOmniType";
							}
						}

						members[token_member_name] = std::pair<std::string, bool>(token_type_name, is_list);
					}
				}
			}
		}

		return members;
	}

	std::string GenerateClassName(Name* name_node)
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

	std::string GenerateMemberName(Name* name_node)
	{
		if(name_node)
		{
			return name_node->UnParse() + "_field";
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
			return member.substr(0, member.size() - 6);
		}

		return "";
	}

	std::vector<std::string> TokenizeBaseName(std::string name)
	{
		std::vector<std::string> base_name_tokens;
		std::stringstream splitter(name);
		std::string item;

		while(std::getline(splitter, item, '.'))
		{
			base_name_tokens.push_back(item);
		}

		base_name_tokens.pop_back();
		return base_name_tokens;
	}

	std::string GenerateGuardName(std::vector<std::string> base_name_tokens)
	{
		std::string guard_name;
		std::locale locale;

		for(std::vector<std::string>::iterator base_name_token = base_name_tokens.begin();base_name_token != base_name_tokens.end();++base_name_token)
		{
			guard_name += ToUpper(*base_name_token) + "_";
		}

		guard_name += "DBNF_H";
		return guard_name;
	}

	std::string GenerateGetterName(std::string member)
	{
		return "Get" + SnakeCaseToCamelCase(GenerateMimicName(member));
	}

	std::string GenerateSetterName(std::string member)
	{
		return "Set" + SnakeCaseToCamelCase(GenerateMimicName(member));
	}

	std::string GenerateFullNamespace(std::vector<std::string> base_name_tokens)
	{
		std::string full_namespace;

		for(std::vector<std::string>::iterator base_name_token = base_name_tokens.begin();base_name_token != base_name_tokens.end();++base_name_token)
		{
			full_namespace += ToLower(*base_name_token) + "::";
		}

		full_namespace += "dbnf::";
		return full_namespace;
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

	std::string CamelCaseToSnakeCase(std::string camel_case)
	{
		std::string snake_case = "";

		for(std::string::iterator index = camel_case.begin();index != camel_case.end();++index)
		{
			if(isupper(*index))
			{
				if (!snake_case.empty()) {
					snake_case += "_";
				}
			}

			snake_case += tolower(*index);
		}

		return snake_case;
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

static int AddCTCodeGenerator()
{
	static dsa::vent::tower::CTCodeGenerator g_ctcode_generator;
	dsa::vent::tower::Generator::AddGenerator("DSA::Vent::Tower::CTCodeGenerator", &g_ctcode_generator);
	return 0;
}

static int initializer = AddCTCodeGenerator();
