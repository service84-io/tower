#include "S84.Tower.Generator.CTCodeGenerator.ctcode.hpp"

namespace s84 {
namespace tower {
namespace generator {
namespace ctcodegenerator {
namespace ctcode {

MemberType::MemberType()
{
    this->base_type = "";
    this->is_list = false;
}

void MemberType::SetBaseType(std::string input)
{
    this->base_type = input;
}

std::string MemberType::GetBaseType()
{
    return this->base_type;
}

void MemberType::SetIsList(bool input)
{
    this->is_list = input;
}

bool MemberType::GetIsList()
{
    return this->is_list;
}

CTCodeGenerator::CTCodeGenerator()
{
    this->logger = NULL;
    this->ctcode_file = NULL;
}

int CTCodeGenerator::GenerateParser(OmniPointer<s84::tower::system::ctcode::System> system, OmniPointer<s84::tower::dbnf::ctcode::Grammar> grammar, std::string base_name)
{
    this->logger = system->GetLoggerDestination();
    this->ctcode_file = system->OpenFileWriter(Concat(base_name,std::string(".ctcode")));
    this->logger->WriteLine(std::string("Generating CTCode file..."));
    this->WriteClasses(grammar,base_name);
    this->logger->WriteLine(std::string("Done!"));
    return 0;
}

void CTCodeGenerator::WriteClasses(OmniPointer<s84::tower::dbnf::ctcode::Grammar> grammar, std::string base_name)
{
    std::vector<OmniPointer<s84::tower::dbnf::ctcode::Rule>> rules = grammar->GetRules();
    this->ctcode_file->WriteLine(std::string("class StringParser"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function bool ParseSingleSave(LengthString index, string value, StringResult result)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        int index_start = index.GetStart();"));
    this->ctcode_file->WriteLine(std::string("        int index_length = index.GetLength();"));
    this->ctcode_file->WriteLine(std::string("        LargeString index_data = index.GetData();"));
    this->ctcode_file->WriteLine(std::string("        LengthString consumed_string = new LengthString;"));
    this->ctcode_file->WriteLine(std::string("        consumed_string.SetData(index.GetData());"));
    this->ctcode_file->WriteLine(std::string("        consumed_string.SetStart(index.GetStart());"));
    this->ctcode_file->WriteLine(std::string("        consumed_string.SetLength(0);"));
    this->ctcode_file->WriteLine(std::string("        String instance = new String;"));
    this->ctcode_file->WriteLine(std::string("        int value_length = Length(value);"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        if (value_length > index.GetLength())"));
    this->ctcode_file->WriteLine(std::string("        {"));
    this->ctcode_file->WriteLine(std::string("            result.SetResult(false);"));
    this->ctcode_file->WriteLine(std::string("            return false;"));
    this->ctcode_file->WriteLine(std::string("        }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        int offset_index = 0;"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        while (offset_index < value_length)"));
    this->ctcode_file->WriteLine(std::string("        {"));
    this->ctcode_file->WriteLine(std::string("            if (index_data.GetAt(index.GetStart() + offset_index) != At(value, offset_index))"));
    this->ctcode_file->WriteLine(std::string("            {"));
    this->ctcode_file->WriteLine(std::string("                result.SetResult(false);"));
    this->ctcode_file->WriteLine(std::string("                return false;"));
    this->ctcode_file->WriteLine(std::string("            }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("            offset_index = offset_index + 1;"));
    this->ctcode_file->WriteLine(std::string("        }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        index.SetStart(index.GetStart() + value_length);"));
    this->ctcode_file->WriteLine(std::string("        index.SetLength(index.GetLength() - value_length);"));
    this->ctcode_file->WriteLine(std::string("        consumed_string.SetLength(index.GetStart() - index_start);"));
    this->ctcode_file->WriteLine(std::string("        instance.SetLengthString(consumed_string);"));
    this->ctcode_file->WriteLine(std::string("        result.SetValue(instance);"));
    this->ctcode_file->WriteLine(std::string("        result.SetResult(true);"));
    this->ctcode_file->WriteLine(std::string("        return true;"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string("    function bool ParseSingle(LengthString index, string value)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        StringResult result = new StringResult;"));
    this->ctcode_file->WriteLine(std::string("        return myself.ParseSingleSave(index, value, result);"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class StringResult"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetValue(String new_value) { myself.value = new_value; }"));
    this->ctcode_file->WriteLine(std::string("    function String GetValue() { return myself.value; }"));
    this->ctcode_file->WriteLine(std::string("    function void SetResult(bool new_result) { myself.result = new_result; }"));
    this->ctcode_file->WriteLine(std::string("    function bool GetResult() { return myself.result; }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    String value;"));
    this->ctcode_file->WriteLine(std::string("    bool result;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class StringListResult"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetValue(String[] new_value) { myself.value = new_value; }"));
    this->ctcode_file->WriteLine(std::string("    function String[] GetValue() { return myself.value; }"));
    this->ctcode_file->WriteLine(std::string("    function void SetResult(bool new_result) { myself.result = new_result; }"));
    this->ctcode_file->WriteLine(std::string("    function bool GetResult() { return myself.result; }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    String[] value;"));
    this->ctcode_file->WriteLine(std::string("    bool result;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class String"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetLengthString(LengthString new_value)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string = new LengthString;"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetData(new_value.GetData());"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetStart(new_value.GetStart());"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetLength(new_value.GetLength());"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    function string UnParse() { return myself.length_string.GetString(); }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    LengthString length_string;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class CharacterParser"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function bool ParseSingle(LengthString index, int value)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        if (0 == index.GetLength())"));
    this->ctcode_file->WriteLine(std::string("        {"));
    this->ctcode_file->WriteLine(std::string("            return false;"));
    this->ctcode_file->WriteLine(std::string("        }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        LargeString index_data = index.GetData();"));
    this->ctcode_file->WriteLine(std::string("        int current_character = index_data.GetIntAt(index.GetStart());"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        if (current_character == value)"));
    this->ctcode_file->WriteLine(std::string("        {"));
    this->ctcode_file->WriteLine(std::string("            index.SetStart(index.GetStart() + 1);"));
    this->ctcode_file->WriteLine(std::string("            index.SetLength(index.GetLength() - 1);"));
    this->ctcode_file->WriteLine(std::string("            return true;"));
    this->ctcode_file->WriteLine(std::string("        }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        return false;"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class CharacterResult"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetValue(Character new_value) { myself.value = new_value; }"));
    this->ctcode_file->WriteLine(std::string("    function Character GetValue() { return myself.value; }"));
    this->ctcode_file->WriteLine(std::string("    function void SetResult(bool new_result) { myself.result = new_result; }"));
    this->ctcode_file->WriteLine(std::string("    function bool GetResult() { return myself.result; }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    Character value;"));
    this->ctcode_file->WriteLine(std::string("    bool result;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class CharacterListResult"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetValue(Character[] new_value) { myself.value = new_value; }"));
    this->ctcode_file->WriteLine(std::string("    function Character[] GetValue() { return myself.value; }"));
    this->ctcode_file->WriteLine(std::string("    function void SetResult(bool new_result) { myself.result = new_result; }"));
    this->ctcode_file->WriteLine(std::string("    function bool GetResult() { return myself.result; }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    Character[] value;"));
    this->ctcode_file->WriteLine(std::string("    bool result;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class Character"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetLengthString(LengthString new_value)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string = new LengthString;"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetData(new_value.GetData());"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetStart(new_value.GetStart());"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetLength(new_value.GetLength());"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    function string UnParse() { return myself.length_string.GetString(); }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    LengthString length_string;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class CharacterRangeParser"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function bool ParseSingle(LengthString index, int low_value, int high_value)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        if (0 == index.GetLength())"));
    this->ctcode_file->WriteLine(std::string("        {"));
    this->ctcode_file->WriteLine(std::string("            return false;"));
    this->ctcode_file->WriteLine(std::string("        }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        LargeString index_data = index.GetData();"));
    this->ctcode_file->WriteLine(std::string("        int current_character = index_data.GetIntAt(index.GetStart());"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        if (low_value <= current_character && current_character <= high_value)"));
    this->ctcode_file->WriteLine(std::string("        {"));
    this->ctcode_file->WriteLine(std::string("            index.SetStart(index.GetStart() + 1);"));
    this->ctcode_file->WriteLine(std::string("            index.SetLength(index.GetLength() - 1);"));
    this->ctcode_file->WriteLine(std::string("            return true;"));
    this->ctcode_file->WriteLine(std::string("        }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        return false;"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class CharacterRangeResult"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetValue(CharacterRange new_value) { myself.value = new_value; }"));
    this->ctcode_file->WriteLine(std::string("    function CharacterRange GetValue() { return myself.value; }"));
    this->ctcode_file->WriteLine(std::string("    function void SetResult(bool new_result) { myself.result = new_result; }"));
    this->ctcode_file->WriteLine(std::string("    function bool GetResult() { return myself.result; }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    CharacterRange value;"));
    this->ctcode_file->WriteLine(std::string("    bool result;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class CharacterRangeListResult"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetValue(CharacterRange[] new_value) { myself.value = new_value; }"));
    this->ctcode_file->WriteLine(std::string("    function CharacterRange[] GetValue() { return myself.value; }"));
    this->ctcode_file->WriteLine(std::string("    function void SetResult(bool new_result) { myself.result = new_result; }"));
    this->ctcode_file->WriteLine(std::string("    function bool GetResult() { return myself.result; }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    CharacterRange[] value;"));
    this->ctcode_file->WriteLine(std::string("    bool result;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class CharacterRange"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetLengthString(LengthString new_value)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string = new LengthString;"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetData(new_value.GetData());"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetStart(new_value.GetStart());"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetLength(new_value.GetLength());"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    function string UnParse() { return myself.length_string.GetString(); }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    LengthString length_string;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class ParserNetwork"));
    this->ctcode_file->WriteLine(std::string("{"));
    int rule_index = 0;
    while (rule_index<Size(rules))
    {
        OmniPointer<s84::tower::dbnf::ctcode::Rule> rule = Element(rules,rule_index);
        if (rule->GetName())
        {
            std::string class_name = Concat(this->GenerateClassName(rule->GetName()),std::string("Parser"));
            std::string field_name = Concat(this->CamelCaseToSnakeCase(class_name),std::string("_field"));
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("    "),class_name),std::string(" ")),field_name),std::string(";")));
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("    function "),class_name),std::string(" ")),this->GenerateGetterName(field_name)),std::string("() { return myself.")),field_name),std::string("; }")));
        }
        rule_index = rule_index+1;
    }
    std::string string_parser_class_name = std::string("StringParser");
    std::string string_parser_field_name = Concat(this->CamelCaseToSnakeCase(string_parser_class_name),std::string("_field"));
    std::string character_parser_class_name = std::string("CharacterParser");
    std::string character_parser_field_name = Concat(this->CamelCaseToSnakeCase(character_parser_class_name),std::string("_field"));
    std::string character_range_parser_class_name = std::string("CharacterRangeParser");
    std::string character_range_parser_field_name = Concat(this->CamelCaseToSnakeCase(character_range_parser_class_name),std::string("_field"));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("    "),string_parser_class_name),std::string(" ")),string_parser_field_name),std::string(";")));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("    function "),string_parser_class_name),std::string(" ")),this->GenerateGetterName(string_parser_field_name)),std::string("() { return myself.")),string_parser_field_name),std::string(";}")));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("    "),character_parser_class_name),std::string(" ")),character_parser_field_name),std::string(";")));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("    function "),character_parser_class_name),std::string(" ")),this->GenerateGetterName(character_parser_field_name)),std::string("() { return myself.")),character_parser_field_name),std::string(";}")));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("    "),character_range_parser_class_name),std::string(" ")),character_range_parser_field_name),std::string(";")));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("    function "),character_range_parser_class_name),std::string(" ")),this->GenerateGetterName(character_range_parser_field_name)),std::string("() { return myself.")),character_range_parser_field_name),std::string(";}")));
    this->ctcode_file->WriteLine(std::string("    function void Initialize() {"));
    rule_index = 0;
    while (rule_index<Size(rules))
    {
        OmniPointer<s84::tower::dbnf::ctcode::Rule> rule = Element(rules,rule_index);
        if (rule->GetName())
        {
            std::string class_name = Concat(this->GenerateClassName(rule->GetName()),std::string("Parser"));
            std::string field_name = Concat(this->CamelCaseToSnakeCase(class_name),std::string("_field"));
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("        myself."),field_name),std::string(" = new ")),class_name),std::string(";")));
            this->ctcode_file->WriteLine(Concat(Concat(std::string("        myself."),field_name),std::string(".SetParserNetwork(myself);")));
        }
        rule_index = rule_index+1;
    }
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("        myself."),string_parser_field_name),std::string(" = new ")),string_parser_class_name),std::string(";")));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("        myself."),character_parser_field_name),std::string(" = new ")),character_parser_class_name),std::string(";")));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("        myself."),character_range_parser_field_name),std::string(" = new ")),character_range_parser_class_name),std::string(";")));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class DBNFOmniType"));
    this->ctcode_file->WriteLine(std::string("{"));
    rule_index = 0;
    while (rule_index<Size(rules))
    {
        OmniPointer<s84::tower::dbnf::ctcode::Rule> rule = Element(rules,rule_index);
        if (rule->GetName())
        {
            std::string class_name = this->GenerateClassName(rule->GetName());
            std::string field_name = Concat(this->CamelCaseToSnakeCase(class_name),std::string("_field"));
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("    "),class_name),std::string(" ")),field_name),std::string(";")));
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("    function void "),this->GenerateSetterName(field_name)),std::string("(")),class_name),std::string(" input_value) { myself.")),field_name),std::string(" = input_value; }")));
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("    function "),class_name),std::string(" ")),this->GenerateGetterName(field_name)),std::string("() { return myself.")),field_name),std::string("; }")));
        }
        rule_index = rule_index+1;
    }
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class DBNFOmniTypeResult"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetValue(DBNFOmniType new_value) { myself.value = new_value; }"));
    this->ctcode_file->WriteLine(std::string("    function DBNFOmniType GetValue() { return myself.value; }"));
    this->ctcode_file->WriteLine(std::string("    function void SetResult(bool new_result) { myself.result = new_result; }"));
    this->ctcode_file->WriteLine(std::string("    function bool GetResult() { return myself.result; }"));
    rule_index = 0;
    while (rule_index<Size(rules))
    {
        OmniPointer<s84::tower::dbnf::ctcode::Rule> rule = Element(rules,rule_index);
        if (rule->GetName())
        {
            std::string class_name = this->GenerateClassName(rule->GetName());
            std::string field_name = Concat(this->CamelCaseToSnakeCase(class_name),std::string("_field"));
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("    function void "),this->GenerateSetterName(field_name)),std::string("(")),class_name),std::string(" input_value)")));
            this->ctcode_file->WriteLine(std::string("    {"));
            this->ctcode_file->WriteLine(std::string("        myself.value = new DBNFOmniType;"));
            this->ctcode_file->WriteLine(Concat(Concat(std::string("        myself.value."),this->GenerateSetterName(field_name)),std::string("(input_value);")));
            this->ctcode_file->WriteLine(std::string("    }"));
        }
        rule_index = rule_index+1;
    }
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    DBNFOmniType value;"));
    this->ctcode_file->WriteLine(std::string("    bool result;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class DBNFOmniTypeListResult"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetValue(DBNFOmniType[] new_value) { myself.value = new_value; }"));
    this->ctcode_file->WriteLine(std::string("    function DBNFOmniType[] GetValue() { return myself.value; }"));
    this->ctcode_file->WriteLine(std::string("    function void SetResult(bool new_result) { myself.result = new_result; }"));
    this->ctcode_file->WriteLine(std::string("    function bool GetResult() { return myself.result; }"));
    rule_index = 0;
    while (rule_index<Size(rules))
    {
        OmniPointer<s84::tower::dbnf::ctcode::Rule> rule = Element(rules,rule_index);
        if (rule->GetName())
        {
            std::string class_name = this->GenerateClassName(rule->GetName());
            std::string field_name = Concat(this->CamelCaseToSnakeCase(class_name),std::string("_field"));
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("    function void "),this->GenerateSetterName(field_name)),std::string("(")),class_name),std::string("[] input_value)")));
            this->ctcode_file->WriteLine(std::string("    {"));
            this->ctcode_file->WriteLine(std::string("        int index = 0;"));
            this->ctcode_file->WriteLine(std::string("        while (index < Size(input_value))"));
            this->ctcode_file->WriteLine(std::string("        {"));
            this->ctcode_file->WriteLine(std::string("            DBNFOmniType value = new DBNFOmniType;"));
            this->ctcode_file->WriteLine(Concat(Concat(std::string("            value."),this->GenerateSetterName(field_name)),std::string("(Element(input_value, index));")));
            this->ctcode_file->WriteLine(std::string("            index = index + 1;"));
            this->ctcode_file->WriteLine(std::string("        }"));
            this->ctcode_file->WriteLine(std::string("    }"));
            this->ctcode_file->WriteLine(std::string(""));
        }
        rule_index = rule_index+1;
    }
    this->ctcode_file->WriteLine(std::string("    DBNFOmniType[] value;"));
    this->ctcode_file->WriteLine(std::string("    bool result;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class LargeString"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetData(string new_data) { myself.data = new_data; }"));
    this->ctcode_file->WriteLine(std::string("    function string GetData() { return myself.data; }"));
    this->ctcode_file->WriteLine(std::string("    function int GetIntAt(int offset) { return IntAt(myself.data, offset); }"));
    this->ctcode_file->WriteLine(std::string("    function string GetAt(int offset) { return At(myself.data, offset); }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    string data;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("class LengthString"));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetData(LargeString new_data) { myself.data = new_data; }"));
    this->ctcode_file->WriteLine(std::string("    function LargeString GetData() { return myself.data; }"));
    this->ctcode_file->WriteLine(std::string("    function void SetStart(int new_start) { myself.start = new_start; }"));
    this->ctcode_file->WriteLine(std::string("    function int GetStart() { return myself.start; }"));
    this->ctcode_file->WriteLine(std::string("    function void SetLength(int new_length) { myself.length = new_length; }"));
    this->ctcode_file->WriteLine(std::string("    function int GetLength() { return myself.length; }"));
    this->ctcode_file->WriteLine(std::string("    function string GetString()"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        string deep_data = myself.data.GetData();"));
    this->ctcode_file->WriteLine(std::string("        string result;"));
    this->ctcode_file->WriteLine(std::string("        int index = myself.start;"));
    this->ctcode_file->WriteLine(std::string("        int end = myself.start + myself.length;"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        while (index < end)"));
    this->ctcode_file->WriteLine(std::string("        {"));
    this->ctcode_file->WriteLine(std::string("            result = Concat(result, At(deep_data, index));"));
    this->ctcode_file->WriteLine(std::string("            index = index + 1;"));
    this->ctcode_file->WriteLine(std::string("        }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        return result;"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    LargeString data;"));
    this->ctcode_file->WriteLine(std::string("    int start;"));
    this->ctcode_file->WriteLine(std::string("    int length;"));
    this->ctcode_file->WriteLine(std::string("}"));
    rule_index = 0;
    while (rule_index<Size(rules))
    {
        OmniPointer<s84::tower::dbnf::ctcode::Rule> rule = Element(rules,rule_index);
        if (rule->GetName())
        {
            this->WriteClass(grammar,rule);
        }
        rule_index = rule_index+1;
    }
}

void CTCodeGenerator::WriteClass(OmniPointer<s84::tower::dbnf::ctcode::Grammar> grammar, OmniPointer<s84::tower::dbnf::ctcode::Rule> rule)
{
    std::string class_name = this->GenerateClassName(rule->GetName());
    std::unordered_map<std::string, OmniPointer<MemberType>> members = this->GetMembers(rule);
    std::vector<std::string> member_names = Keys(members);
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("class "),class_name),std::string("Parser")));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    ParserNetwork parser_network;"));
    this->ctcode_file->WriteLine(std::string("    function void SetParserNetwork(ParserNetwork input) { myself.parser_network = input; }"));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("    function bool ParseSingleSave(LengthString index, "),class_name),std::string("Result result)")));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        int index_start = index.GetStart();"));
    this->ctcode_file->WriteLine(std::string("        int index_length = index.GetLength();"));
    this->ctcode_file->WriteLine(std::string("        LengthString consumed_string = new LengthString;"));
    this->ctcode_file->WriteLine(std::string("        consumed_string.SetData(index.GetData());"));
    this->ctcode_file->WriteLine(std::string("        consumed_string.SetStart(index.GetStart());"));
    this->ctcode_file->WriteLine(std::string("        consumed_string.SetLength(0);"));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("        "),class_name),std::string(" instance = new ")),class_name),std::string(";")));
    int member_name_index = 0;
    while (member_name_index<Size(member_names))
    {
        std::string member_name = Element(member_names,member_name_index);
        OmniPointer<MemberType> member_type = GetKV(members,member_name);
        if (member_type->GetIsList())
        {
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("        "),member_type->GetBaseType()),std::string("ListResult ")),member_name),std::string(" = new ")),member_type->GetBaseType()),std::string("ListResult;")));
        }
        else
        {
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("        "),member_type->GetBaseType()),std::string("Result ")),member_name),std::string(" = new ")),member_type->GetBaseType()),std::string("Result;")));
        }
        member_name_index = member_name_index+1;
    }
    this->ctcode_file->WriteLine(std::string(""));
    std::vector<OmniPointer<s84::tower::dbnf::ctcode::Rule>> rules = grammar->GetRules();
    int rule_index = 0;
    while (rule_index<Size(rules))
    {
        OmniPointer<s84::tower::dbnf::ctcode::Rule> rule_for_parser = Element(rules,rule_index);
        if (rule_for_parser->GetName())
        {
            std::string rule_class_name = Concat(this->GenerateClassName(rule_for_parser->GetName()),std::string("Parser"));
            std::string field_name = Concat(this->CamelCaseToSnakeCase(rule_class_name),std::string("_field"));
            std::string local_name = Concat(this->CamelCaseToSnakeCase(rule_class_name),std::string("_instance"));
            this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("        "),rule_class_name),std::string(" ")),local_name),std::string(" = myself.parser_network.")),this->GenerateGetterName(field_name)),std::string("();")));
        }
        rule_index = rule_index+1;
    }
    std::string string_parser_class_name = std::string("StringParser");
    std::string string_parser_field_name = Concat(this->CamelCaseToSnakeCase(string_parser_class_name),std::string("_field"));
    std::string string_parser_local_name = Concat(this->CamelCaseToSnakeCase(string_parser_class_name),std::string("_instance"));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("        "),string_parser_class_name),std::string(" ")),string_parser_local_name),std::string(" = myself.parser_network.")),this->GenerateGetterName(string_parser_field_name)),std::string("();")));
    std::string character_parser_class_name = std::string("CharacterParser");
    std::string character_parser_field_name = Concat(this->CamelCaseToSnakeCase(character_parser_class_name),std::string("_field"));
    std::string character_parser_local_name = Concat(this->CamelCaseToSnakeCase(character_parser_class_name),std::string("_instance"));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("        "),character_parser_class_name),std::string(" ")),character_parser_local_name),std::string(" = myself.parser_network.")),this->GenerateGetterName(character_parser_field_name)),std::string("();")));
    std::string character_range_parser_class_name = std::string("CharacterRangeParser");
    std::string character_range_parser_field_name = Concat(this->CamelCaseToSnakeCase(character_range_parser_class_name),std::string("_field"));
    std::string character_range_parser_local_name = Concat(this->CamelCaseToSnakeCase(character_range_parser_class_name),std::string("_instance"));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(std::string("        "),character_range_parser_class_name),std::string(" ")),character_range_parser_local_name),std::string(" = myself.parser_network.")),this->GenerateGetterName(character_range_parser_field_name)),std::string("();")));
    this->ctcode_file->WriteLine(std::string(""));
    std::vector<OmniPointer<s84::tower::dbnf::ctcode::Expression>> expressions = rule->GetExpressions();
    int expression_index = 0;
    while (expression_index<Size(expressions))
    {
        OmniPointer<s84::tower::dbnf::ctcode::Expression> expression = Element(expressions,expression_index);
        if (expression->GetExpressionDiscriminator())
        {
            this->WriteExpression(expression);
            member_name_index = 0;
            while (member_name_index<Size(member_names))
            {
                std::string member_name = Element(member_names,member_name_index);
                OmniPointer<MemberType> member_type = GetKV(members,member_name);
                this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("            instance."),this->GenerateSetterName(member_name)),std::string("(")),member_name),std::string(".GetValue());")));
                member_name_index = member_name_index+1;
            }
            this->ctcode_file->WriteLine(std::string("            consumed_string.SetLength(index.GetStart() - index_start);"));
            this->ctcode_file->WriteLine(std::string("            instance.SetLengthString(consumed_string);"));
            this->ctcode_file->WriteLine(std::string("            result.SetValue(instance);"));
            this->ctcode_file->WriteLine(std::string("            result.SetResult(true);"));
            this->ctcode_file->WriteLine(std::string("            return result.GetResult();"));
            this->ctcode_file->WriteLine(std::string("        } else {"));
            this->ctcode_file->WriteLine(std::string("            index.SetStart(index_start);"));
            this->ctcode_file->WriteLine(std::string("            index.SetLength(index_length);"));
            member_name_index = 0;
            while (member_name_index<Size(member_names))
            {
                std::string member_name = Element(member_names,member_name_index);
                OmniPointer<MemberType> member_type = GetKV(members,member_name);
                if (member_type->GetIsList())
                {
                    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("            "),member_name),std::string(" = new ")),member_type->GetBaseType()),std::string("ListResult;")));
                }
                else
                {
                    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("            "),member_name),std::string(" = new ")),member_type->GetBaseType()),std::string("Result;")));
                }
                member_name_index = member_name_index+1;
            }
            this->ctcode_file->WriteLine(std::string("        }"));
            this->ctcode_file->WriteLine(std::string(""));
        }
        expression_index = expression_index+1;
    }
    this->ctcode_file->WriteLine(std::string("        result.SetResult(false);"));
    this->ctcode_file->WriteLine(std::string("        return result.GetResult();"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    function bool ParseSingle(LengthString index)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("        "),class_name),std::string("Result result = new ")),class_name),std::string("Result;")));
    this->ctcode_file->WriteLine(std::string("        return myself.ParseSingleSave(index, result);"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("    function bool ParseOptionalSave(LengthString index, "),class_name),std::string("Result result)")));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        myself.ParseSingleSave(index, result);"));
    this->ctcode_file->WriteLine(std::string("        result.SetResult(true);"));
    this->ctcode_file->WriteLine(std::string("        return true;"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    function bool ParseOptional(LengthString index)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("        "),class_name),std::string("Result result = new ")),class_name),std::string("Result;")));
    this->ctcode_file->WriteLine(std::string("        return myself.ParseOptionalSave(index, result);"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("    function bool ParseManySave(LengthString index, "),class_name),std::string("ListResult list_result, int minimum, int maximum)")));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        int index_start = index.GetStart();"));
    this->ctcode_file->WriteLine(std::string("        int index_length = index.GetLength();"));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("        "),class_name),std::string("[] results;")));
    this->ctcode_file->WriteLine(std::string("        int count = 0;"));
    this->ctcode_file->WriteLine(std::string("        int max_check = maximum;"));
    this->ctcode_file->WriteLine(std::string("        bool check_next = true;"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        if (maximum < 0)"));
    this->ctcode_file->WriteLine(std::string("        {"));
    this->ctcode_file->WriteLine(std::string("            max_check = count + 1;"));
    this->ctcode_file->WriteLine(std::string("        }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        while (check_next && count < max_check)"));
    this->ctcode_file->WriteLine(std::string("        {"));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("            "),class_name),std::string("Result result = new ")),class_name),std::string("Result;")));
    this->ctcode_file->WriteLine(std::string("            myself.ParseSingleSave(index, result);"));
    this->ctcode_file->WriteLine(std::string("            check_next = result.GetResult();"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("            if (result.GetResult())"));
    this->ctcode_file->WriteLine(std::string("            {"));
    this->ctcode_file->WriteLine(std::string("                count = count + 1;"));
    this->ctcode_file->WriteLine(std::string("                Append(results, result.GetValue());"));
    this->ctcode_file->WriteLine(std::string("            }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("            if (maximum < 0)"));
    this->ctcode_file->WriteLine(std::string("            {"));
    this->ctcode_file->WriteLine(std::string("                max_check = count + 1;"));
    this->ctcode_file->WriteLine(std::string("            }"));
    this->ctcode_file->WriteLine(std::string("        }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        if (count >= minimum && count <= max_check)"));
    this->ctcode_file->WriteLine(std::string("        {"));
    this->ctcode_file->WriteLine(std::string("            list_result.SetValue(results);"));
    this->ctcode_file->WriteLine(std::string("            list_result.SetResult(true);"));
    this->ctcode_file->WriteLine(std::string("        } else {"));
    this->ctcode_file->WriteLine(std::string("            index.SetStart(index_start);"));
    this->ctcode_file->WriteLine(std::string("            index.SetLength(index_length);"));
    this->ctcode_file->WriteLine(std::string("            list_result.SetResult(false);"));
    this->ctcode_file->WriteLine(std::string("        }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("        return list_result.GetResult();"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    function bool ParseMany(LengthString index, int minimum, int maximum)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(std::string("        "),class_name),std::string("ListResult result = new ")),class_name),std::string("ListResult;")));
    this->ctcode_file->WriteLine(std::string("        return myself.ParseManySave(index, result, minimum, maximum);"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("class "),class_name),std::string("Result")));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("    function void SetValue("),class_name),std::string(" new_value) { myself.value = new_value; }")));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("    function "),class_name),std::string(" GetValue() { return myself.value; }")));
    this->ctcode_file->WriteLine(std::string("    function void SetResult(bool new_result) { myself.result = new_result; }"));
    this->ctcode_file->WriteLine(std::string("    function bool GetResult() { return myself.result; }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("    "),class_name),std::string(" value;")));
    this->ctcode_file->WriteLine(std::string("    bool result;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("class "),class_name),std::string("ListResult")));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("    function void SetValue("),class_name),std::string("[] new_value) { myself.value = new_value; }")));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("    function "),class_name),std::string("[] GetValue() { return myself.value; }")));
    this->ctcode_file->WriteLine(std::string("    function void SetResult(bool new_result) { myself.result = new_result; }"));
    this->ctcode_file->WriteLine(std::string("    function bool GetResult() { return myself.result; }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(Concat(Concat(std::string("    "),class_name),std::string("[] value;")));
    this->ctcode_file->WriteLine(std::string("    bool result;"));
    this->ctcode_file->WriteLine(std::string("}"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(Concat(std::string("class "),class_name));
    this->ctcode_file->WriteLine(std::string("{"));
    this->ctcode_file->WriteLine(std::string("    function void SetLengthString(LengthString new_value)"));
    this->ctcode_file->WriteLine(std::string("    {"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string = new LengthString;"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetData(new_value.GetData());"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetStart(new_value.GetStart());"));
    this->ctcode_file->WriteLine(std::string("        myself.length_string.SetLength(new_value.GetLength());"));
    this->ctcode_file->WriteLine(std::string("    }"));
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    function string UnParse() { return myself.length_string.GetString(); }"));
    member_name_index = 0;
    while (member_name_index<Size(member_names))
    {
        std::string member_name = Element(member_names,member_name_index);
        OmniPointer<MemberType> member_type = GetKV(members,member_name);
        std::string list_suffix = std::string("");
        if (member_type->GetIsList())
        {
            list_suffix = std::string("[]");
        }
        this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(Concat(std::string("    function void "),this->GenerateSetterName(member_name)),std::string("(")),member_type->GetBaseType()),list_suffix),std::string(" input_value) { myself.")),member_name),std::string(" = input_value; }")));
        this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(Concat(std::string("    function "),member_type->GetBaseType()),list_suffix),std::string(" ")),this->GenerateGetterName(member_name)),std::string("() { return myself.")),member_name),std::string("; }")));
        member_name_index = member_name_index+1;
    }
    this->ctcode_file->WriteLine(std::string(""));
    this->ctcode_file->WriteLine(std::string("    LengthString length_string;"));
    member_name_index = 0;
    while (member_name_index<Size(member_names))
    {
        std::string member_name = Element(member_names,member_name_index);
        OmniPointer<MemberType> member_type = GetKV(members,member_name);
        std::string list_suffix = std::string("");
        if (member_type->GetIsList())
        {
            list_suffix = std::string("[]");
        }
        this->ctcode_file->WriteLine(Concat(Concat(Concat(Concat(Concat(std::string("    "),member_type->GetBaseType()),list_suffix),std::string(" ")),member_name),std::string(";")));
        member_name_index = member_name_index+1;
    }
    this->ctcode_file->WriteLine(std::string("}"));
}

void CTCodeGenerator::WriteExpression(OmniPointer<s84::tower::dbnf::ctcode::Expression> expression)
{
    std::string line = std::string("");
    line = Concat(line,std::string("        if (true"));
    std::vector<OmniPointer<s84::tower::dbnf::ctcode::Token>> token_sequence = expression->GetTokenSequence();
    int token_sequence_index = 0;
    while (token_sequence_index<Size(token_sequence))
    {
        OmniPointer<s84::tower::dbnf::ctcode::Token> token = Element(token_sequence,token_sequence_index);
        OmniPointer<s84::tower::dbnf::ctcode::SimpleToken> simple_token = token->GetValue();
        OmniPointer<s84::tower::dbnf::ctcode::Modifier> modifier_node = token->GetModifier();
        std::string member = this->GenerateMemberName(token->GetName());
        line = Concat(line,std::string(" && "));
        std::string match_function = std::string("ParseSingle");
        std::string match_function_parameters = std::string("index");
        std::string parser = std::string("");
        if (simple_token->GetToken())
        {
            parser = Concat(this->GenerateClassName(simple_token->GetToken()),std::string("Parser"));
        }
        else
        {
            if (simple_token->GetLiteral())
            {
                parser = std::string("StringParser");
                match_function_parameters = Concat(Concat(match_function_parameters,std::string(", ")),simple_token->UnParse());
            }
            else
            {
                if (simple_token->GetHigh()&&simple_token->GetLow())
                {
                    parser = std::string("CharacterParser");
                    match_function_parameters = Concat(Concat(match_function_parameters,std::string(", ")),simple_token->UnParse());
                }
                else
                {
                    if (simple_token->GetHighHigh()&&simple_token->GetHighLow()&&simple_token->GetLowHigh()&&simple_token->GetLowLow())
                    {
                        OmniPointer<s84::tower::dbnf::ctcode::HexDigit> high_high = simple_token->GetHighHigh();
                        OmniPointer<s84::tower::dbnf::ctcode::HexDigit> high_low = simple_token->GetHighLow();
                        OmniPointer<s84::tower::dbnf::ctcode::HexDigit> low_high = simple_token->GetLowHigh();
                        OmniPointer<s84::tower::dbnf::ctcode::HexDigit> low_low = simple_token->GetLowLow();
                        parser = std::string("CharacterRangeParser");
                        match_function_parameters = Concat(Concat(Concat(match_function_parameters,std::string(", 0x")),low_high->UnParse()),low_low->UnParse());
                        match_function_parameters = Concat(Concat(Concat(match_function_parameters,std::string(", 0x")),high_high->UnParse()),high_low->UnParse());
                    }
                }
            }
        }
        if (token->GetName())
        {
            match_function_parameters = Concat(Concat(match_function_parameters,std::string(", ")),member);
        }
        if (modifier_node)
        {
            std::string modifier = modifier_node->UnParse();
            OmniPointer<s84::tower::dbnf::ctcode::Cardinality> cardinality = modifier_node->GetCardinality();
            if (modifier==std::string("*"))
            {
                match_function = std::string("ParseMany");
                match_function_parameters = Concat(match_function_parameters,std::string(", 0, -1"));
            }
            else
            {
                if (modifier==std::string("?"))
                {
                    match_function = std::string("ParseOptional");
                }
                else
                {
                    if (modifier==std::string("+"))
                    {
                        match_function = std::string("ParseMany");
                        match_function_parameters = Concat(match_function_parameters,std::string(", 1, -1"));
                    }
                    else
                    {
                        if (cardinality)
                        {
                            OmniPointer<s84::tower::dbnf::ctcode::Number> maximum = cardinality->GetMaximum();
                            OmniPointer<s84::tower::dbnf::ctcode::Number> minimum = cardinality->GetMinimum();
                            OmniPointer<s84::tower::dbnf::ctcode::Number> count = cardinality->GetCount();
                            match_function = std::string("ParseMany");
                            if (maximum)
                            {
                                match_function_parameters = Concat(Concat(Concat(Concat(match_function_parameters,std::string(", ")),minimum->UnParse()),std::string(", ")),maximum->UnParse());
                            }
                            else
                            {
                                if (minimum)
                                {
                                    match_function_parameters = Concat(Concat(Concat(match_function_parameters,std::string(", ")),minimum->UnParse()),std::string(", -1"));
                                }
                                else
                                {
                                    if (count)
                                    {
                                        match_function_parameters = Concat(Concat(Concat(Concat(match_function_parameters,std::string(", ")),count->UnParse()),std::string(", ")),count->UnParse());
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (token->GetName())
        {
            match_function = Concat(match_function,std::string("Save"));
        }
        std::string parser_instance_name = Concat(this->CamelCaseToSnakeCase(parser),std::string("_instance"));
        line = Concat(Concat(Concat(Concat(Concat(Concat(line,parser_instance_name),std::string(".")),match_function),std::string("(")),match_function_parameters),std::string(")"));
        token_sequence_index = token_sequence_index+1;
    }
    line = Concat(line,std::string(") {"));
    this->ctcode_file->WriteLine(line);
}

std::unordered_map<std::string, OmniPointer<MemberType>> CTCodeGenerator::GetMembers(OmniPointer<s84::tower::dbnf::ctcode::Rule> rule)
{
    std::unordered_map<std::string, OmniPointer<MemberType>> members;
    std::vector<OmniPointer<s84::tower::dbnf::ctcode::Expression>> expressions = rule->GetExpressions();
    int expression_index = 0;
    while (expression_index<Size(expressions))
    {
        OmniPointer<s84::tower::dbnf::ctcode::Expression> expression = Element(expressions,expression_index);
        std::vector<OmniPointer<s84::tower::dbnf::ctcode::Token>> token_sequence = expression->GetTokenSequence();
        int token_sequence_index = 0;
        while (token_sequence_index<Size(token_sequence))
        {
            OmniPointer<s84::tower::dbnf::ctcode::Token> token = Element(token_sequence,token_sequence_index);
            OmniPointer<s84::tower::dbnf::ctcode::Modifier> modifier_node = token->GetModifier();
            std::string token_member_name = this->GenerateMemberName(token->GetName());
            if (token_member_name!=std::string(""))
            {
                OmniPointer<s84::tower::dbnf::ctcode::SimpleToken> simple_token = token->GetValue();
                std::string token_type_name = this->GenerateClassName(simple_token->GetToken());
                bool is_list = false;
                if (!HasKV(members,token_member_name))
                {
                    OmniPointer<MemberType> new_member_type = std::shared_ptr<MemberType>(new MemberType());
                    SetKV(members,token_member_name,new_member_type);
                }
                OmniPointer<MemberType> member_type = GetKV(members,token_member_name);
                std::string previous_type = member_type->GetBaseType();
                std::string modifier = std::string("");
                if (modifier_node)
                {
                    modifier = modifier_node->UnParse();
                }
                if (simple_token->GetHigh()||simple_token->GetLow()||simple_token->GetHighHigh()||simple_token->GetHighLow()||simple_token->GetLowHigh()||simple_token->GetLowLow()||simple_token->GetLiteral())
                {
                    token_type_name = std::string("String");
                }
                if (modifier==std::string("*")||modifier==std::string("+")||At(modifier,0)==std::string("{"))
                {
                    is_list = true;
                }
                if (previous_type!=std::string("")&&previous_type!=token_type_name)
                {
                    if (modifier==std::string("*")||modifier==std::string("+")||At(modifier,0)==std::string("{"))
                    {
                        is_list = true;
                        token_type_name = std::string("DBNFOmniType");
                    }
                    else
                    {
                        token_type_name = std::string("DBNFOmniType");
                    }
                }
                member_type->SetBaseType(token_type_name);
                member_type->SetIsList(is_list);
            }
            token_sequence_index = token_sequence_index+1;
        }
        expression_index = expression_index+1;
    }
    return members;
}

std::string CTCodeGenerator::GenerateClassName(OmniPointer<s84::tower::dbnf::ctcode::Name> name_node)
{
    if (name_node)
    {
        return this->SnakeCaseToCamelCase(name_node->UnParse());
    }
    else
    {
        return std::string("");
    }
}

std::string CTCodeGenerator::GenerateMemberName(OmniPointer<s84::tower::dbnf::ctcode::Name> name_node)
{
    if (name_node)
    {
        return Concat(name_node->UnParse(),std::string("_field"));
    }
    else
    {
        return std::string("");
    }
}

std::string CTCodeGenerator::GenerateMimicName(std::string member)
{
    std::string result = std::string("");
    int member_index = 0;
    while (member_index<Length(member)-6)
    {
        result = Concat(result,At(member,member_index));
        member_index = member_index+1;
    }
    return result;
}

std::string CTCodeGenerator::GenerateGetterName(std::string member)
{
    return Concat(std::string("Get"),this->SnakeCaseToCamelCase(this->GenerateMimicName(member)));
}

std::string CTCodeGenerator::GenerateSetterName(std::string member)
{
    return Concat(std::string("Set"),this->SnakeCaseToCamelCase(this->GenerateMimicName(member)));
}

std::string CTCodeGenerator::SnakeCaseToCamelCase(std::string snake_case)
{
    bool capitalize_this_letter = false;
    capitalize_this_letter = true;
    std::string camel_case = "";
    camel_case = std::string("");
    int index = 0;
    index = 0;
    while (index<Length(snake_case))
    {
        std::string source_character = "";
        source_character = At(snake_case,index);
        if (source_character==std::string("_"))
        {
            capitalize_this_letter = true;
        }
        else
        {
            if (capitalize_this_letter==true)
            {
                std::string upper_character = "";
                upper_character = this->CharacterToUpper(source_character);
                capitalize_this_letter = false;
                camel_case = Concat(camel_case,upper_character);
            }
            else
            {
                capitalize_this_letter = false;
                camel_case = Concat(camel_case,source_character);
            }
        }
        index = index+1;
    }
    return camel_case;
}

std::string CTCodeGenerator::CamelCaseToSnakeCase(std::string camel_case)
{
    std::string delimiter = "";
    delimiter = std::string("_");
    std::string snake_case = "";
    snake_case = std::string("");
    int index = 0;
    index = 0;
    while (index<Length(camel_case))
    {
        std::string source_character = "";
        source_character = At(camel_case,index);
        std::string lower_character = "";
        lower_character = this->CharacterToLower(source_character);
        if (this->IsUpper(source_character)||this->IsDigit(source_character))
        {
            bool is_first_character = false;
            is_first_character = Length(snake_case)==0;
            if (!is_first_character)
            {
                snake_case = Concat(snake_case,delimiter);
            }
            snake_case = Concat(snake_case,lower_character);
        }
        else
        {
            if (source_character==delimiter)
            {
                snake_case = Concat(snake_case,delimiter);
            }
            else
            {
                snake_case = Concat(snake_case,lower_character);
            }
        }
        index = index+1;
    }
    return snake_case;
}

bool CTCodeGenerator::IsUpper(std::string character)
{
    bool result = false;
    result = false;
    result = result||character==std::string("A");
    result = result||character==std::string("B");
    result = result||character==std::string("C");
    result = result||character==std::string("D");
    result = result||character==std::string("E");
    result = result||character==std::string("F");
    result = result||character==std::string("G");
    result = result||character==std::string("H");
    result = result||character==std::string("I");
    result = result||character==std::string("J");
    result = result||character==std::string("K");
    result = result||character==std::string("L");
    result = result||character==std::string("M");
    result = result||character==std::string("N");
    result = result||character==std::string("O");
    result = result||character==std::string("P");
    result = result||character==std::string("Q");
    result = result||character==std::string("R");
    result = result||character==std::string("S");
    result = result||character==std::string("T");
    result = result||character==std::string("U");
    result = result||character==std::string("V");
    result = result||character==std::string("W");
    result = result||character==std::string("X");
    result = result||character==std::string("Y");
    result = result||character==std::string("Z");
    return result;
}

bool CTCodeGenerator::IsDigit(std::string character)
{
    bool result = false;
    result = false;
    result = result||character==std::string("0");
    result = result||character==std::string("1");
    result = result||character==std::string("2");
    result = result||character==std::string("3");
    result = result||character==std::string("4");
    result = result||character==std::string("5");
    result = result||character==std::string("6");
    result = result||character==std::string("7");
    result = result||character==std::string("8");
    result = result||character==std::string("9");
    return result;
}

std::string CTCodeGenerator::ToLower(std::string input)
{
    int index = 0;
    index = 0;
    std::string result = "";
    result = std::string("");
    while (index<Length(input))
    {
        std::string character = "";
        character = At(input,index);
        std::string lower_character = "";
        lower_character = this->CharacterToLower(character);
        result = Concat(result,lower_character);
        index = index+1;
    }
    return result;
}

std::string CTCodeGenerator::CharacterToLower(std::string input)
{
    if (input==std::string("A"))
    {
        return std::string("a");
    }
    if (input==std::string("B"))
    {
        return std::string("b");
    }
    if (input==std::string("C"))
    {
        return std::string("c");
    }
    if (input==std::string("D"))
    {
        return std::string("d");
    }
    if (input==std::string("E"))
    {
        return std::string("e");
    }
    if (input==std::string("F"))
    {
        return std::string("f");
    }
    if (input==std::string("G"))
    {
        return std::string("g");
    }
    if (input==std::string("H"))
    {
        return std::string("h");
    }
    if (input==std::string("I"))
    {
        return std::string("i");
    }
    if (input==std::string("J"))
    {
        return std::string("j");
    }
    if (input==std::string("K"))
    {
        return std::string("k");
    }
    if (input==std::string("L"))
    {
        return std::string("l");
    }
    if (input==std::string("M"))
    {
        return std::string("m");
    }
    if (input==std::string("N"))
    {
        return std::string("n");
    }
    if (input==std::string("O"))
    {
        return std::string("o");
    }
    if (input==std::string("P"))
    {
        return std::string("p");
    }
    if (input==std::string("Q"))
    {
        return std::string("q");
    }
    if (input==std::string("R"))
    {
        return std::string("r");
    }
    if (input==std::string("S"))
    {
        return std::string("s");
    }
    if (input==std::string("T"))
    {
        return std::string("t");
    }
    if (input==std::string("U"))
    {
        return std::string("u");
    }
    if (input==std::string("V"))
    {
        return std::string("v");
    }
    if (input==std::string("W"))
    {
        return std::string("w");
    }
    if (input==std::string("X"))
    {
        return std::string("x");
    }
    if (input==std::string("Y"))
    {
        return std::string("y");
    }
    if (input==std::string("Z"))
    {
        return std::string("z");
    }
    return input;
}

std::string CTCodeGenerator::ToUpper(std::string input)
{
    int index = 0;
    index = 0;
    std::string result = "";
    result = std::string("");
    while (index<Length(input))
    {
        std::string character = "";
        character = At(input,index);
        std::string upper_character = "";
        upper_character = this->CharacterToUpper(character);
        result = Concat(result,upper_character);
        index = index+1;
    }
    return result;
}

std::string CTCodeGenerator::CharacterToUpper(std::string input)
{
    if (input==std::string("a"))
    {
        return std::string("A");
    }
    if (input==std::string("b"))
    {
        return std::string("B");
    }
    if (input==std::string("c"))
    {
        return std::string("C");
    }
    if (input==std::string("d"))
    {
        return std::string("D");
    }
    if (input==std::string("e"))
    {
        return std::string("E");
    }
    if (input==std::string("f"))
    {
        return std::string("F");
    }
    if (input==std::string("g"))
    {
        return std::string("G");
    }
    if (input==std::string("h"))
    {
        return std::string("H");
    }
    if (input==std::string("i"))
    {
        return std::string("I");
    }
    if (input==std::string("j"))
    {
        return std::string("J");
    }
    if (input==std::string("k"))
    {
        return std::string("K");
    }
    if (input==std::string("l"))
    {
        return std::string("L");
    }
    if (input==std::string("m"))
    {
        return std::string("M");
    }
    if (input==std::string("n"))
    {
        return std::string("N");
    }
    if (input==std::string("o"))
    {
        return std::string("O");
    }
    if (input==std::string("p"))
    {
        return std::string("P");
    }
    if (input==std::string("q"))
    {
        return std::string("Q");
    }
    if (input==std::string("r"))
    {
        return std::string("R");
    }
    if (input==std::string("s"))
    {
        return std::string("S");
    }
    if (input==std::string("t"))
    {
        return std::string("T");
    }
    if (input==std::string("u"))
    {
        return std::string("U");
    }
    if (input==std::string("v"))
    {
        return std::string("V");
    }
    if (input==std::string("w"))
    {
        return std::string("W");
    }
    if (input==std::string("x"))
    {
        return std::string("X");
    }
    if (input==std::string("y"))
    {
        return std::string("Y");
    }
    if (input==std::string("z"))
    {
        return std::string("Z");
    }
    return input;
}


};
};
};
};
};
