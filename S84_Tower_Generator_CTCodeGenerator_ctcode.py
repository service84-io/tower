import S84_Tower_System_ctcode
import S84_Tower_Generator_ctcode
import S84_Tower_dbnf_ctcode

def ClearList(input: list) -> None: input.clear()
def Size(input: list) -> int: return len(input)
def Element(input: list, element: int ) -> any: return input[element]
def Append(input: list, element: any) -> None: input.append(element)
def ClearMap(input: dict) -> None: input.clear()
def SetKV(input: dict, key: str, element: any) -> None: input[key] = element
def Keys(input: dict) -> list[str]:
    result: list[str] = []
    for key in input.keys():
        result.append(key)
    return result
def HasKV(input: dict, key: str) -> bool: return key in input
def GetKV(input: dict, key: str) -> any: return input[key]
def Length(input: str) -> int: return len(input)
def At(input: str, index: int) -> str: return input[index:index+1]
def IntAt(input: str, index: int) -> int: return ord(input[index:index+1])
def Concat(left: str, right: str) -> str: return left + right

class MemberType:
    def __init__(self: 'MemberType'):
        self.base_type: str = ""
        self.is_list: bool = False

    def SetBaseType(self: 'MemberType',input: 'str') -> 'None':
        self.base_type = input

    def GetBaseType(self: 'MemberType') -> 'str':
        return self.base_type

    def SetIsList(self: 'MemberType',input: 'bool') -> 'None':
        self.is_list = input

    def GetIsList(self: 'MemberType') -> 'bool':
        return self.is_list

class CTCodeGenerator(S84_Tower_Generator_ctcode.Generator):
    def __init__(self: 'CTCodeGenerator'):
        self.logger: S84_Tower_System_ctcode.OutputStream = None
        self.ctcode_file: S84_Tower_System_ctcode.OutputStream = None

    def GenerateParser(self: 'CTCodeGenerator',system: 'S84_Tower_System_ctcode.System',grammar: 'S84_Tower_dbnf_ctcode.Grammar',base_name: 'str') -> 'int':
        self.logger = system.GetLoggerDestination()
        self.ctcode_file = system.OpenFileWriter(Concat(base_name,".ctcode"))
        self.logger.WriteLine("Generating CTCode file...")
        self.WriteClasses(grammar,base_name)
        self.logger.WriteLine("Done!")
        return 0

    def WriteClasses(self: 'CTCodeGenerator',grammar: 'S84_Tower_dbnf_ctcode.Grammar',base_name: 'str') -> 'None':
        rules: 'list[S84_Tower_dbnf_ctcode.Rule]' = grammar.GetRules()
        self.ctcode_file.WriteLine("class StringParser")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function bool ParseSingleSave(LengthString index, string value, StringResult result)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        int index_start = index.GetStart();")
        self.ctcode_file.WriteLine("        int index_length = index.GetLength();")
        self.ctcode_file.WriteLine("        LargeString index_data = index.GetData();")
        self.ctcode_file.WriteLine("        LengthString consumed_string = new LengthString;")
        self.ctcode_file.WriteLine("        consumed_string.SetData(index.GetData());")
        self.ctcode_file.WriteLine("        consumed_string.SetStart(index.GetStart());")
        self.ctcode_file.WriteLine("        consumed_string.SetLength(0);")
        self.ctcode_file.WriteLine("        String instance = new String;")
        self.ctcode_file.WriteLine("        int value_length = Length(value);")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        if (value_length > index.GetLength())")
        self.ctcode_file.WriteLine("        {")
        self.ctcode_file.WriteLine("            result.SetResult(false);")
        self.ctcode_file.WriteLine("            return false;")
        self.ctcode_file.WriteLine("        }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        int offset_index = 0;")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        while (offset_index < value_length)")
        self.ctcode_file.WriteLine("        {")
        self.ctcode_file.WriteLine("            if (index_data.GetAt(index.GetStart() + offset_index) != At(value, offset_index))")
        self.ctcode_file.WriteLine("            {")
        self.ctcode_file.WriteLine("                result.SetResult(false);")
        self.ctcode_file.WriteLine("                return false;")
        self.ctcode_file.WriteLine("            }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("            offset_index = offset_index + 1;")
        self.ctcode_file.WriteLine("        }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        index.SetStart(index.GetStart() + value_length);")
        self.ctcode_file.WriteLine("        index.SetLength(index.GetLength() - value_length);")
        self.ctcode_file.WriteLine("        consumed_string.SetLength(index.GetStart() - index_start);")
        self.ctcode_file.WriteLine("        instance.SetLengthString(consumed_string);")
        self.ctcode_file.WriteLine("        result.SetValue(instance);")
        self.ctcode_file.WriteLine("        result.SetResult(true);")
        self.ctcode_file.WriteLine("        return true;")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("    function bool ParseSingle(LengthString index, string value)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        StringResult result = new StringResult;")
        self.ctcode_file.WriteLine("        return myself.ParseSingleSave(index, value, result);")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class StringResult")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetValue(String new_value) { myself.value = new_value; }")
        self.ctcode_file.WriteLine("    function String GetValue() { return myself.value; }")
        self.ctcode_file.WriteLine("    function void SetResult(bool new_result) { myself.result = new_result; }")
        self.ctcode_file.WriteLine("    function bool GetResult() { return myself.result; }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    String value;")
        self.ctcode_file.WriteLine("    bool result;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class StringListResult")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetValue(String[] new_value) { myself.value = new_value; }")
        self.ctcode_file.WriteLine("    function String[] GetValue() { return myself.value; }")
        self.ctcode_file.WriteLine("    function void SetResult(bool new_result) { myself.result = new_result; }")
        self.ctcode_file.WriteLine("    function bool GetResult() { return myself.result; }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    String[] value;")
        self.ctcode_file.WriteLine("    bool result;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class String")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetLengthString(LengthString new_value)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        myself.length_string = new LengthString;")
        self.ctcode_file.WriteLine("        myself.length_string.SetData(new_value.GetData());")
        self.ctcode_file.WriteLine("        myself.length_string.SetStart(new_value.GetStart());")
        self.ctcode_file.WriteLine("        myself.length_string.SetLength(new_value.GetLength());")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    function string UnParse() { return myself.length_string.GetString(); }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    LengthString length_string;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class CharacterParser")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function bool ParseSingle(LengthString index, int value)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        if (0 == index.GetLength())")
        self.ctcode_file.WriteLine("        {")
        self.ctcode_file.WriteLine("            return false;")
        self.ctcode_file.WriteLine("        }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        LargeString index_data = index.GetData();")
        self.ctcode_file.WriteLine("        int current_character = index_data.GetIntAt(index.GetStart());")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        if (current_character == value)")
        self.ctcode_file.WriteLine("        {")
        self.ctcode_file.WriteLine("            index.SetStart(index.GetStart() + 1);")
        self.ctcode_file.WriteLine("            index.SetLength(index.GetLength() - 1);")
        self.ctcode_file.WriteLine("            return true;")
        self.ctcode_file.WriteLine("        }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        return false;")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class CharacterResult")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetValue(Character new_value) { myself.value = new_value; }")
        self.ctcode_file.WriteLine("    function Character GetValue() { return myself.value; }")
        self.ctcode_file.WriteLine("    function void SetResult(bool new_result) { myself.result = new_result; }")
        self.ctcode_file.WriteLine("    function bool GetResult() { return myself.result; }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    Character value;")
        self.ctcode_file.WriteLine("    bool result;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class CharacterListResult")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetValue(Character[] new_value) { myself.value = new_value; }")
        self.ctcode_file.WriteLine("    function Character[] GetValue() { return myself.value; }")
        self.ctcode_file.WriteLine("    function void SetResult(bool new_result) { myself.result = new_result; }")
        self.ctcode_file.WriteLine("    function bool GetResult() { return myself.result; }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    Character[] value;")
        self.ctcode_file.WriteLine("    bool result;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class Character")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetLengthString(LengthString new_value)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        myself.length_string = new LengthString;")
        self.ctcode_file.WriteLine("        myself.length_string.SetData(new_value.GetData());")
        self.ctcode_file.WriteLine("        myself.length_string.SetStart(new_value.GetStart());")
        self.ctcode_file.WriteLine("        myself.length_string.SetLength(new_value.GetLength());")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    function string UnParse() { return myself.length_string.GetString(); }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    LengthString length_string;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class CharacterRangeParser")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function bool ParseSingle(LengthString index, int low_value, int high_value)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        if (0 == index.GetLength())")
        self.ctcode_file.WriteLine("        {")
        self.ctcode_file.WriteLine("            return false;")
        self.ctcode_file.WriteLine("        }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        LargeString index_data = index.GetData();")
        self.ctcode_file.WriteLine("        int current_character = index_data.GetIntAt(index.GetStart());")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        if (low_value <= current_character && current_character <= high_value)")
        self.ctcode_file.WriteLine("        {")
        self.ctcode_file.WriteLine("            index.SetStart(index.GetStart() + 1);")
        self.ctcode_file.WriteLine("            index.SetLength(index.GetLength() - 1);")
        self.ctcode_file.WriteLine("            return true;")
        self.ctcode_file.WriteLine("        }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        return false;")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class CharacterRangeResult")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetValue(CharacterRange new_value) { myself.value = new_value; }")
        self.ctcode_file.WriteLine("    function CharacterRange GetValue() { return myself.value; }")
        self.ctcode_file.WriteLine("    function void SetResult(bool new_result) { myself.result = new_result; }")
        self.ctcode_file.WriteLine("    function bool GetResult() { return myself.result; }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    CharacterRange value;")
        self.ctcode_file.WriteLine("    bool result;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class CharacterRangeListResult")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetValue(CharacterRange[] new_value) { myself.value = new_value; }")
        self.ctcode_file.WriteLine("    function CharacterRange[] GetValue() { return myself.value; }")
        self.ctcode_file.WriteLine("    function void SetResult(bool new_result) { myself.result = new_result; }")
        self.ctcode_file.WriteLine("    function bool GetResult() { return myself.result; }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    CharacterRange[] value;")
        self.ctcode_file.WriteLine("    bool result;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class CharacterRange")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetLengthString(LengthString new_value)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        myself.length_string = new LengthString;")
        self.ctcode_file.WriteLine("        myself.length_string.SetData(new_value.GetData());")
        self.ctcode_file.WriteLine("        myself.length_string.SetStart(new_value.GetStart());")
        self.ctcode_file.WriteLine("        myself.length_string.SetLength(new_value.GetLength());")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    function string UnParse() { return myself.length_string.GetString(); }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    LengthString length_string;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class ParserNetwork")
        self.ctcode_file.WriteLine("{")
        rule_index: 'int' = 0
        while rule_index<Size(rules):
            rule: 'S84_Tower_dbnf_ctcode.Rule' = Element(rules,rule_index)
            if rule.GetName():
                class_name: 'str' = Concat(self.GenerateClassName(rule.GetName()),"Parser")
                field_name: 'str' = Concat(self.CamelCaseToSnakeCase(class_name),"_field")
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("    ",class_name)," "),field_name),";"))
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("    function ",class_name)," "),self.GenerateGetterName(field_name)),"() { return myself."),field_name),"; }"))
            rule_index = rule_index+1
        string_parser_class_name: 'str' = "StringParser"
        string_parser_field_name: 'str' = Concat(self.CamelCaseToSnakeCase(string_parser_class_name),"_field")
        character_parser_class_name: 'str' = "CharacterParser"
        character_parser_field_name: 'str' = Concat(self.CamelCaseToSnakeCase(character_parser_class_name),"_field")
        character_range_parser_class_name: 'str' = "CharacterRangeParser"
        character_range_parser_field_name: 'str' = Concat(self.CamelCaseToSnakeCase(character_range_parser_class_name),"_field")
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("    ",string_parser_class_name)," "),string_parser_field_name),";"))
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("    function ",string_parser_class_name)," "),self.GenerateGetterName(string_parser_field_name)),"() { return myself."),string_parser_field_name),";}"))
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("    ",character_parser_class_name)," "),character_parser_field_name),";"))
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("    function ",character_parser_class_name)," "),self.GenerateGetterName(character_parser_field_name)),"() { return myself."),character_parser_field_name),";}"))
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("    ",character_range_parser_class_name)," "),character_range_parser_field_name),";"))
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("    function ",character_range_parser_class_name)," "),self.GenerateGetterName(character_range_parser_field_name)),"() { return myself."),character_range_parser_field_name),";}"))
        self.ctcode_file.WriteLine("    function void Initialize() {")
        rule_index = 0
        while rule_index<Size(rules):
            rule: 'S84_Tower_dbnf_ctcode.Rule' = Element(rules,rule_index)
            if rule.GetName():
                class_name: 'str' = Concat(self.GenerateClassName(rule.GetName()),"Parser")
                field_name: 'str' = Concat(self.CamelCaseToSnakeCase(class_name),"_field")
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("        myself.",field_name)," = new "),class_name),";"))
                self.ctcode_file.WriteLine(Concat(Concat("        myself.",field_name),".SetParserNetwork(myself);"))
            rule_index = rule_index+1
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("        myself.",string_parser_field_name)," = new "),string_parser_class_name),";"))
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("        myself.",character_parser_field_name)," = new "),character_parser_class_name),";"))
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("        myself.",character_range_parser_field_name)," = new "),character_range_parser_class_name),";"))
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class DBNFOmniType")
        self.ctcode_file.WriteLine("{")
        rule_index = 0
        while rule_index<Size(rules):
            rule: 'S84_Tower_dbnf_ctcode.Rule' = Element(rules,rule_index)
            if rule.GetName():
                class_name: 'str' = self.GenerateClassName(rule.GetName())
                field_name: 'str' = Concat(self.CamelCaseToSnakeCase(class_name),"_field")
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("    ",class_name)," "),field_name),";"))
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("    function void ",self.GenerateSetterName(field_name)),"("),class_name)," input_value) { myself."),field_name)," = input_value; }"))
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("    function ",class_name)," "),self.GenerateGetterName(field_name)),"() { return myself."),field_name),"; }"))
            rule_index = rule_index+1
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class DBNFOmniTypeResult")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetValue(DBNFOmniType new_value) { myself.value = new_value; }")
        self.ctcode_file.WriteLine("    function DBNFOmniType GetValue() { return myself.value; }")
        self.ctcode_file.WriteLine("    function void SetResult(bool new_result) { myself.result = new_result; }")
        self.ctcode_file.WriteLine("    function bool GetResult() { return myself.result; }")
        rule_index = 0
        while rule_index<Size(rules):
            rule: 'S84_Tower_dbnf_ctcode.Rule' = Element(rules,rule_index)
            if rule.GetName():
                class_name: 'str' = self.GenerateClassName(rule.GetName())
                field_name: 'str' = Concat(self.CamelCaseToSnakeCase(class_name),"_field")
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("    function void ",self.GenerateSetterName(field_name)),"("),class_name)," input_value)"))
                self.ctcode_file.WriteLine("    {")
                self.ctcode_file.WriteLine("        myself.value = new DBNFOmniType;")
                self.ctcode_file.WriteLine(Concat(Concat("        myself.value.",self.GenerateSetterName(field_name)),"(input_value);"))
                self.ctcode_file.WriteLine("    }")
            rule_index = rule_index+1
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    DBNFOmniType value;")
        self.ctcode_file.WriteLine("    bool result;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class DBNFOmniTypeListResult")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetValue(DBNFOmniType[] new_value) { myself.value = new_value; }")
        self.ctcode_file.WriteLine("    function DBNFOmniType[] GetValue() { return myself.value; }")
        self.ctcode_file.WriteLine("    function void SetResult(bool new_result) { myself.result = new_result; }")
        self.ctcode_file.WriteLine("    function bool GetResult() { return myself.result; }")
        rule_index = 0
        while rule_index<Size(rules):
            rule: 'S84_Tower_dbnf_ctcode.Rule' = Element(rules,rule_index)
            if rule.GetName():
                class_name: 'str' = self.GenerateClassName(rule.GetName())
                field_name: 'str' = Concat(self.CamelCaseToSnakeCase(class_name),"_field")
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("    function void ",self.GenerateSetterName(field_name)),"("),class_name),"[] input_value)"))
                self.ctcode_file.WriteLine("    {")
                self.ctcode_file.WriteLine("        int index = 0;")
                self.ctcode_file.WriteLine("        while (index < Size(input_value))")
                self.ctcode_file.WriteLine("        {")
                self.ctcode_file.WriteLine("            DBNFOmniType value = new DBNFOmniType;")
                self.ctcode_file.WriteLine(Concat(Concat("            value.",self.GenerateSetterName(field_name)),"(Element(input_value, index));"))
                self.ctcode_file.WriteLine("            index = index + 1;")
                self.ctcode_file.WriteLine("        }")
                self.ctcode_file.WriteLine("    }")
                self.ctcode_file.WriteLine("")
            rule_index = rule_index+1
        self.ctcode_file.WriteLine("    DBNFOmniType[] value;")
        self.ctcode_file.WriteLine("    bool result;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class LargeString")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetData(string new_data) { myself.data = new_data; }")
        self.ctcode_file.WriteLine("    function string GetData() { return myself.data; }")
        self.ctcode_file.WriteLine("    function int GetIntAt(int offset) { return IntAt(myself.data, offset); }")
        self.ctcode_file.WriteLine("    function string GetAt(int offset) { return At(myself.data, offset); }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    string data;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("class LengthString")
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetData(LargeString new_data) { myself.data = new_data; }")
        self.ctcode_file.WriteLine("    function LargeString GetData() { return myself.data; }")
        self.ctcode_file.WriteLine("    function void SetStart(int new_start) { myself.start = new_start; }")
        self.ctcode_file.WriteLine("    function int GetStart() { return myself.start; }")
        self.ctcode_file.WriteLine("    function void SetLength(int new_length) { myself.length = new_length; }")
        self.ctcode_file.WriteLine("    function int GetLength() { return myself.length; }")
        self.ctcode_file.WriteLine("    function string GetString()")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        string deep_data = myself.data.GetData();")
        self.ctcode_file.WriteLine("        string result;")
        self.ctcode_file.WriteLine("        int index = myself.start;")
        self.ctcode_file.WriteLine("        int end = myself.start + myself.length;")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        while (index < end)")
        self.ctcode_file.WriteLine("        {")
        self.ctcode_file.WriteLine("            result = Concat(result, At(deep_data, index));")
        self.ctcode_file.WriteLine("            index = index + 1;")
        self.ctcode_file.WriteLine("        }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        return result;")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    LargeString data;")
        self.ctcode_file.WriteLine("    int start;")
        self.ctcode_file.WriteLine("    int length;")
        self.ctcode_file.WriteLine("}")
        rule_index = 0
        while rule_index<Size(rules):
            rule: 'S84_Tower_dbnf_ctcode.Rule' = Element(rules,rule_index)
            if rule.GetName():
                self.WriteClass(grammar,rule)
            rule_index = rule_index+1

    def WriteClass(self: 'CTCodeGenerator',grammar: 'S84_Tower_dbnf_ctcode.Grammar',rule: 'S84_Tower_dbnf_ctcode.Rule') -> 'None':
        class_name: 'str' = self.GenerateClassName(rule.GetName())
        members: 'dict[str, MemberType]' = self.GetMembers(rule)
        member_names: 'list[str]' = Keys(members)
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine(Concat(Concat("class ",class_name),"Parser"))
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    ParserNetwork parser_network;")
        self.ctcode_file.WriteLine("    function void SetParserNetwork(ParserNetwork input) { myself.parser_network = input; }")
        self.ctcode_file.WriteLine(Concat(Concat("    function bool ParseSingleSave(LengthString index, ",class_name),"Result result)"))
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        int index_start = index.GetStart();")
        self.ctcode_file.WriteLine("        int index_length = index.GetLength();")
        self.ctcode_file.WriteLine("        LengthString consumed_string = new LengthString;")
        self.ctcode_file.WriteLine("        consumed_string.SetData(index.GetData());")
        self.ctcode_file.WriteLine("        consumed_string.SetStart(index.GetStart());")
        self.ctcode_file.WriteLine("        consumed_string.SetLength(0);")
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("        ",class_name)," instance = new "),class_name),";"))
        member_name_index: 'int' = 0
        while member_name_index<Size(member_names):
            member_name: 'str' = Element(member_names,member_name_index)
            member_type: 'MemberType' = GetKV(members,member_name)
            if member_type.GetIsList():
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("        ",member_type.GetBaseType()),"ListResult "),member_name)," = new "),member_type.GetBaseType()),"ListResult;"))
            else:
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("        ",member_type.GetBaseType()),"Result "),member_name)," = new "),member_type.GetBaseType()),"Result;"))
            member_name_index = member_name_index+1
        self.ctcode_file.WriteLine("")
        rules: 'list[S84_Tower_dbnf_ctcode.Rule]' = grammar.GetRules()
        rule_index: 'int' = 0
        while rule_index<Size(rules):
            rule: 'S84_Tower_dbnf_ctcode.Rule' = Element(rules,rule_index)
            if rule.GetName():
                class_name: 'str' = Concat(self.GenerateClassName(rule.GetName()),"Parser")
                field_name: 'str' = Concat(self.CamelCaseToSnakeCase(class_name),"_field")
                local_name: 'str' = Concat(self.CamelCaseToSnakeCase(class_name),"_instance")
                self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("        ",class_name)," "),local_name)," = myself.parser_network."),self.GenerateGetterName(field_name)),"();"))
            rule_index = rule_index+1
        string_parser_class_name: 'str' = "StringParser"
        string_parser_field_name: 'str' = Concat(self.CamelCaseToSnakeCase(string_parser_class_name),"_field")
        string_parser_local_name: 'str' = Concat(self.CamelCaseToSnakeCase(string_parser_class_name),"_instance")
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("        ",string_parser_class_name)," "),string_parser_local_name)," = myself.parser_network."),self.GenerateGetterName(string_parser_field_name)),"();"))
        character_parser_class_name: 'str' = "CharacterParser"
        character_parser_field_name: 'str' = Concat(self.CamelCaseToSnakeCase(character_parser_class_name),"_field")
        character_parser_local_name: 'str' = Concat(self.CamelCaseToSnakeCase(character_parser_class_name),"_instance")
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("        ",character_parser_class_name)," "),character_parser_local_name)," = myself.parser_network."),self.GenerateGetterName(character_parser_field_name)),"();"))
        character_range_parser_class_name: 'str' = "CharacterRangeParser"
        character_range_parser_field_name: 'str' = Concat(self.CamelCaseToSnakeCase(character_range_parser_class_name),"_field")
        character_range_parser_local_name: 'str' = Concat(self.CamelCaseToSnakeCase(character_range_parser_class_name),"_instance")
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat("        ",character_range_parser_class_name)," "),character_range_parser_local_name)," = myself.parser_network."),self.GenerateGetterName(character_range_parser_field_name)),"();"))
        self.ctcode_file.WriteLine("")
        expressions: 'list[S84_Tower_dbnf_ctcode.Expression]' = rule.GetExpressions()
        expression_index: 'int' = 0
        while expression_index<Size(expressions):
            expression: 'S84_Tower_dbnf_ctcode.Expression' = Element(expressions,expression_index)
            if expression.GetExpressionDiscriminator():
                self.WriteExpression(expression)
                member_name_index = 0
                while member_name_index<Size(member_names):
                    member_name: 'str' = Element(member_names,member_name_index)
                    member_type: 'MemberType' = GetKV(members,member_name)
                    self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("            instance.",self.GenerateSetterName(member_name)),"("),member_name),".GetValue());"))
                    member_name_index = member_name_index+1
                self.ctcode_file.WriteLine("            consumed_string.SetLength(index.GetStart() - index_start);")
                self.ctcode_file.WriteLine("            instance.SetLengthString(consumed_string);")
                self.ctcode_file.WriteLine("            result.SetValue(instance);")
                self.ctcode_file.WriteLine("            result.SetResult(true);")
                self.ctcode_file.WriteLine("            return result.GetResult();")
                self.ctcode_file.WriteLine("        } else {")
                self.ctcode_file.WriteLine("            index.SetStart(index_start);")
                self.ctcode_file.WriteLine("            index.SetLength(index_length);")
                member_name_index = 0
                while member_name_index<Size(member_names):
                    member_name: 'str' = Element(member_names,member_name_index)
                    member_type: 'MemberType' = GetKV(members,member_name)
                    if member_type.GetIsList():
                        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("            ",member_name)," = new "),member_type.GetBaseType()),"ListResult;"))
                    else:
                        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("            ",member_name)," = new "),member_type.GetBaseType()),"Result;"))
                    member_name_index = member_name_index+1
                self.ctcode_file.WriteLine("        }")
                self.ctcode_file.WriteLine("")
            expression_index = expression_index+1
        self.ctcode_file.WriteLine("        result.SetResult(false);")
        self.ctcode_file.WriteLine("        return result.GetResult();")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    function bool ParseSingle(LengthString index)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("        ",class_name),"Result result = new "),class_name),"Result;"))
        self.ctcode_file.WriteLine("        return myself.ParseSingleSave(index, result);")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine(Concat(Concat("    function bool ParseOptionalSave(LengthString index, ",class_name),"Result result)"))
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        myself.ParseSingleSave(index, result);")
        self.ctcode_file.WriteLine("        result.SetResult(true);")
        self.ctcode_file.WriteLine("        return true;")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    function bool ParseOptional(LengthString index)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("        ",class_name),"Result result = new "),class_name),"Result;"))
        self.ctcode_file.WriteLine("        return myself.ParseOptionalSave(index, result);")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine(Concat(Concat("    function bool ParseManySave(LengthString index, ",class_name),"ListResult list_result, int minimum, int maximum)"))
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        int index_start = index.GetStart();")
        self.ctcode_file.WriteLine("        int index_length = index.GetLength();")
        self.ctcode_file.WriteLine(Concat(Concat("        ",class_name),"[] results;"))
        self.ctcode_file.WriteLine("        int count = 0;")
        self.ctcode_file.WriteLine("        int max_check = maximum;")
        self.ctcode_file.WriteLine("        bool check_next = true;")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        if (maximum < 0)")
        self.ctcode_file.WriteLine("        {")
        self.ctcode_file.WriteLine("            max_check = count + 1;")
        self.ctcode_file.WriteLine("        }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        while (check_next && count < max_check)")
        self.ctcode_file.WriteLine("        {")
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("            ",class_name),"Result result = new "),class_name),"Result;"))
        self.ctcode_file.WriteLine("            myself.ParseSingleSave(index, result);")
        self.ctcode_file.WriteLine("            check_next = result.GetResult();")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("            if (result.GetResult())")
        self.ctcode_file.WriteLine("            {")
        self.ctcode_file.WriteLine("                count = count + 1;")
        self.ctcode_file.WriteLine("                Append(results, result.GetValue());")
        self.ctcode_file.WriteLine("            }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("            if (maximum < 0)")
        self.ctcode_file.WriteLine("            {")
        self.ctcode_file.WriteLine("                max_check = count + 1;")
        self.ctcode_file.WriteLine("            }")
        self.ctcode_file.WriteLine("        }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        if (count >= minimum && count <= max_check)")
        self.ctcode_file.WriteLine("        {")
        self.ctcode_file.WriteLine("            list_result.SetValue(results);")
        self.ctcode_file.WriteLine("            list_result.SetResult(true);")
        self.ctcode_file.WriteLine("        } else {")
        self.ctcode_file.WriteLine("            index.SetStart(index_start);")
        self.ctcode_file.WriteLine("            index.SetLength(index_length);")
        self.ctcode_file.WriteLine("            list_result.SetResult(false);")
        self.ctcode_file.WriteLine("        }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("        return list_result.GetResult();")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    function bool ParseMany(LengthString index, int minimum, int maximum)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat("        ",class_name),"ListResult result = new "),class_name),"ListResult;"))
        self.ctcode_file.WriteLine("        return myself.ParseManySave(index, result, minimum, maximum);")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine(Concat(Concat("class ",class_name),"Result"))
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine(Concat(Concat("    function void SetValue(",class_name)," new_value) { myself.value = new_value; }"))
        self.ctcode_file.WriteLine(Concat(Concat("    function ",class_name)," GetValue() { return myself.value; }"))
        self.ctcode_file.WriteLine("    function void SetResult(bool new_result) { myself.result = new_result; }")
        self.ctcode_file.WriteLine("    function bool GetResult() { return myself.result; }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine(Concat(Concat("    ",class_name)," value;"))
        self.ctcode_file.WriteLine("    bool result;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine(Concat(Concat("class ",class_name),"ListResult"))
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine(Concat(Concat("    function void SetValue(",class_name),"[] new_value) { myself.value = new_value; }"))
        self.ctcode_file.WriteLine(Concat(Concat("    function ",class_name),"[] GetValue() { return myself.value; }"))
        self.ctcode_file.WriteLine("    function void SetResult(bool new_result) { myself.result = new_result; }")
        self.ctcode_file.WriteLine("    function bool GetResult() { return myself.result; }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine(Concat(Concat("    ",class_name),"[] value;"))
        self.ctcode_file.WriteLine("    bool result;")
        self.ctcode_file.WriteLine("}")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine(Concat("class ",class_name))
        self.ctcode_file.WriteLine("{")
        self.ctcode_file.WriteLine("    function void SetLengthString(LengthString new_value)")
        self.ctcode_file.WriteLine("    {")
        self.ctcode_file.WriteLine("        myself.length_string = new LengthString;")
        self.ctcode_file.WriteLine("        myself.length_string.SetData(new_value.GetData());")
        self.ctcode_file.WriteLine("        myself.length_string.SetStart(new_value.GetStart());")
        self.ctcode_file.WriteLine("        myself.length_string.SetLength(new_value.GetLength());")
        self.ctcode_file.WriteLine("    }")
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    function string UnParse() { return myself.length_string.GetString(); }")
        member_name_index = 0
        while member_name_index<Size(member_names):
            member_name: 'str' = Element(member_names,member_name_index)
            member_type: 'MemberType' = GetKV(members,member_name)
            list_suffix: 'str' = ""
            if member_type.GetIsList():
                list_suffix = "[]"
            self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(Concat("    function void ",self.GenerateSetterName(member_name)),"("),member_type.GetBaseType()),list_suffix)," input_value) { myself."),member_name)," = input_value; }"))
            self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat(Concat(Concat("    function ",member_type.GetBaseType()),list_suffix)," "),self.GenerateGetterName(member_name)),"() { return myself."),member_name),"; }"))
            member_name_index = member_name_index+1
        self.ctcode_file.WriteLine("")
        self.ctcode_file.WriteLine("    LengthString length_string;")
        member_name_index = 0
        while member_name_index<Size(member_names):
            member_name: 'str' = Element(member_names,member_name_index)
            member_type: 'MemberType' = GetKV(members,member_name)
            list_suffix: 'str' = ""
            if member_type.GetIsList():
                list_suffix = "[]"
            self.ctcode_file.WriteLine(Concat(Concat(Concat(Concat(Concat("    ",member_type.GetBaseType()),list_suffix)," "),member_name),";"))
            member_name_index = member_name_index+1
        self.ctcode_file.WriteLine("}")

    def WriteExpression(self: 'CTCodeGenerator',expression: 'S84_Tower_dbnf_ctcode.Expression') -> 'None':
        line: 'str' = ""
        line = Concat(line,"        if (true")
        token_sequence: 'list[S84_Tower_dbnf_ctcode.Token]' = expression.GetTokenSequence()
        token_sequence_index: 'int' = 0
        while token_sequence_index<Size(token_sequence):
            token: 'S84_Tower_dbnf_ctcode.Token' = Element(token_sequence,token_sequence_index)
            simple_token: 'S84_Tower_dbnf_ctcode.SimpleToken' = token.GetValue()
            modifier_node: 'S84_Tower_dbnf_ctcode.Modifier' = token.GetModifier()
            member: 'str' = self.GenerateMemberName(token.GetName())
            line = Concat(line," && ")
            match_function: 'str' = "ParseSingle"
            match_function_parameters: 'str' = "index"
            parser: 'str' = ""
            if simple_token.GetToken():
                parser = Concat(self.GenerateClassName(simple_token.GetToken()),"Parser")
            else:
                if simple_token.GetLiteral():
                    parser = "StringParser"
                    match_function_parameters = Concat(Concat(match_function_parameters,", "),simple_token.UnParse())
                else:
                    if simple_token.GetHigh() and simple_token.GetLow():
                        parser = "CharacterParser"
                        match_function_parameters = Concat(Concat(match_function_parameters,", "),simple_token.UnParse())
                    else:
                        if simple_token.GetHighHigh() and simple_token.GetHighLow() and simple_token.GetLowHigh() and simple_token.GetLowLow():
                            high_high: 'S84_Tower_dbnf_ctcode.HexDigit' = simple_token.GetHighHigh()
                            high_low: 'S84_Tower_dbnf_ctcode.HexDigit' = simple_token.GetHighLow()
                            low_high: 'S84_Tower_dbnf_ctcode.HexDigit' = simple_token.GetLowHigh()
                            low_low: 'S84_Tower_dbnf_ctcode.HexDigit' = simple_token.GetLowLow()
                            parser = "CharacterRangeParser"
                            match_function_parameters = Concat(Concat(Concat(match_function_parameters,", 0x"),low_high.UnParse()),low_low.UnParse())
                            match_function_parameters = Concat(Concat(Concat(match_function_parameters,", 0x"),high_high.UnParse()),high_low.UnParse())
            if token.GetName():
                match_function_parameters = Concat(Concat(match_function_parameters,", "),member)
            if modifier_node:
                modifier: 'str' = modifier_node.UnParse()
                cardinality: 'S84_Tower_dbnf_ctcode.Cardinality' = modifier_node.GetCardinality()
                if modifier=="*":
                    match_function = "ParseMany"
                    match_function_parameters = Concat(match_function_parameters,", 0, -1")
                else:
                    if modifier=="?":
                        match_function = "ParseOptional"
                    else:
                        if modifier=="+":
                            match_function = "ParseMany"
                            match_function_parameters = Concat(match_function_parameters,", 1, -1")
                        else:
                            if cardinality:
                                maximum: 'S84_Tower_dbnf_ctcode.Number' = cardinality.GetMaximum()
                                minimum: 'S84_Tower_dbnf_ctcode.Number' = cardinality.GetMinimum()
                                count: 'S84_Tower_dbnf_ctcode.Number' = cardinality.GetCount()
                                match_function = "ParseMany"
                                if maximum:
                                    match_function_parameters = Concat(Concat(Concat(Concat(match_function_parameters,", "),minimum.UnParse()),", "),maximum.UnParse())
                                else:
                                    if minimum:
                                        match_function_parameters = Concat(Concat(Concat(match_function_parameters,", "),minimum.UnParse()),", -1")
                                    else:
                                        if count:
                                            match_function_parameters = Concat(Concat(Concat(Concat(match_function_parameters,", "),count.UnParse()),", "),count.UnParse())
            if token.GetName():
                match_function = Concat(match_function,"Save")
            parser_instance_name: 'str' = Concat(self.CamelCaseToSnakeCase(parser),"_instance")
            line = Concat(Concat(Concat(Concat(Concat(Concat(line,parser_instance_name),"."),match_function),"("),match_function_parameters),")")
            token_sequence_index = token_sequence_index+1
        line = Concat(line,") {")
        self.ctcode_file.WriteLine(line)

    def GetMembers(self: 'CTCodeGenerator',rule: 'S84_Tower_dbnf_ctcode.Rule') -> 'dict[str, MemberType]':
        members: 'dict[str, MemberType]' = {}
        expressions: 'list[S84_Tower_dbnf_ctcode.Expression]' = rule.GetExpressions()
        expression_index: 'int' = 0
        while expression_index<Size(expressions):
            expression: 'S84_Tower_dbnf_ctcode.Expression' = Element(expressions,expression_index)
            token_sequence: 'list[S84_Tower_dbnf_ctcode.Token]' = expression.GetTokenSequence()
            token_sequence_index: 'int' = 0
            while token_sequence_index<Size(token_sequence):
                token: 'S84_Tower_dbnf_ctcode.Token' = Element(token_sequence,token_sequence_index)
                modifier_node: 'S84_Tower_dbnf_ctcode.Modifier' = token.GetModifier()
                token_member_name: 'str' = self.GenerateMemberName(token.GetName())
                if token_member_name!="":
                    simple_token: 'S84_Tower_dbnf_ctcode.SimpleToken' = token.GetValue()
                    token_type_name: 'str' = self.GenerateClassName(simple_token.GetToken())
                    is_list: 'bool' = False
                    if not HasKV(members,token_member_name):
                        new_member_type: 'MemberType' = MemberType()
                        SetKV(members,token_member_name,new_member_type)
                    member_type: 'MemberType' = GetKV(members,token_member_name)
                    previous_type: 'str' = member_type.GetBaseType()
                    modifier: 'str' = ""
                    if modifier_node:
                        modifier = modifier_node.UnParse()
                    if simple_token.GetHigh() or simple_token.GetLow() or simple_token.GetHighHigh() or simple_token.GetHighLow() or simple_token.GetLowHigh() or simple_token.GetLowLow() or simple_token.GetLiteral():
                        token_type_name = "String"
                    if modifier=="*" or modifier=="+" or At(modifier,0)=="{":
                        is_list = True
                    if previous_type!="" and previous_type!=token_type_name:
                        if modifier=="*" or modifier=="+" or At(modifier,0)=="{":
                            is_list = True
                            token_type_name = "DBNFOmniType"
                        else:
                            token_type_name = "DBNFOmniType"
                    member_type.SetBaseType(token_type_name)
                    member_type.SetIsList(is_list)
                token_sequence_index = token_sequence_index+1
            expression_index = expression_index+1
        return members

    def GenerateClassName(self: 'CTCodeGenerator',name_node: 'S84_Tower_dbnf_ctcode.Name') -> 'str':
        if name_node:
            return self.SnakeCaseToCamelCase(name_node.UnParse())
        else:
            return ""

    def GenerateMemberName(self: 'CTCodeGenerator',name_node: 'S84_Tower_dbnf_ctcode.Name') -> 'str':
        if name_node:
            return Concat(name_node.UnParse(),"_field")
        else:
            return ""

    def GenerateMimicName(self: 'CTCodeGenerator',member: 'str') -> 'str':
        result: 'str' = ""
        member_index: 'int' = 0
        while member_index<Length(member)-6:
            result = Concat(result,At(member,member_index))
            member_index = member_index+1
        return result

    def GenerateGetterName(self: 'CTCodeGenerator',member: 'str') -> 'str':
        return Concat("Get",self.SnakeCaseToCamelCase(self.GenerateMimicName(member)))

    def GenerateSetterName(self: 'CTCodeGenerator',member: 'str') -> 'str':
        return Concat("Set",self.SnakeCaseToCamelCase(self.GenerateMimicName(member)))

    def SnakeCaseToCamelCase(self: 'CTCodeGenerator',snake_case: 'str') -> 'str':
        capitalize_this_letter: 'bool' = False
        capitalize_this_letter = True
        camel_case: 'str' = ""
        camel_case = ""
        index: 'int' = 0
        index = 0
        while index<Length(snake_case):
            source_character: 'str' = ""
            source_character = At(snake_case,index)
            if source_character=="_":
                capitalize_this_letter = True
            else:
                if capitalize_this_letter==True:
                    upper_character: 'str' = ""
                    upper_character = self.CharacterToUpper(source_character)
                    capitalize_this_letter = False
                    camel_case = Concat(camel_case,upper_character)
                else:
                    capitalize_this_letter = False
                    camel_case = Concat(camel_case,source_character)
            index = index+1
        return camel_case

    def CamelCaseToSnakeCase(self: 'CTCodeGenerator',camel_case: 'str') -> 'str':
        delimiter: 'str' = ""
        delimiter = "_"
        snake_case: 'str' = ""
        snake_case = ""
        index: 'int' = 0
        index = 0
        while index<Length(camel_case):
            source_character: 'str' = ""
            source_character = At(camel_case,index)
            lower_character: 'str' = ""
            lower_character = self.CharacterToLower(source_character)
            if self.IsUpper(source_character) or self.IsDigit(source_character):
                is_first_character: 'bool' = False
                is_first_character = Length(snake_case)==0
                if not is_first_character:
                    snake_case = Concat(snake_case,delimiter)
                snake_case = Concat(snake_case,lower_character)
            else:
                if source_character==delimiter:
                    snake_case = Concat(snake_case,delimiter)
                else:
                    snake_case = Concat(snake_case,lower_character)
            index = index+1
        return snake_case

    def IsUpper(self: 'CTCodeGenerator',character: 'str') -> 'bool':
        result: 'bool' = False
        result = False
        result = result or character=="A"
        result = result or character=="B"
        result = result or character=="C"
        result = result or character=="D"
        result = result or character=="E"
        result = result or character=="F"
        result = result or character=="G"
        result = result or character=="H"
        result = result or character=="I"
        result = result or character=="J"
        result = result or character=="K"
        result = result or character=="L"
        result = result or character=="M"
        result = result or character=="N"
        result = result or character=="O"
        result = result or character=="P"
        result = result or character=="Q"
        result = result or character=="R"
        result = result or character=="S"
        result = result or character=="T"
        result = result or character=="U"
        result = result or character=="V"
        result = result or character=="W"
        result = result or character=="X"
        result = result or character=="Y"
        result = result or character=="Z"
        return result

    def IsDigit(self: 'CTCodeGenerator',character: 'str') -> 'bool':
        result: 'bool' = False
        result = False
        result = result or character=="0"
        result = result or character=="1"
        result = result or character=="2"
        result = result or character=="3"
        result = result or character=="4"
        result = result or character=="5"
        result = result or character=="6"
        result = result or character=="7"
        result = result or character=="8"
        result = result or character=="9"
        return result

    def ToLower(self: 'CTCodeGenerator',input: 'str') -> 'str':
        index: 'int' = 0
        index = 0
        result: 'str' = ""
        result = ""
        while index<Length(input):
            character: 'str' = ""
            character = At(input,index)
            lower_character: 'str' = ""
            lower_character = self.CharacterToLower(character)
            result = Concat(result,lower_character)
            index = index+1
        return result

    def CharacterToLower(self: 'CTCodeGenerator',input: 'str') -> 'str':
        if input=="A":
            return "a"
        if input=="B":
            return "b"
        if input=="C":
            return "c"
        if input=="D":
            return "d"
        if input=="E":
            return "e"
        if input=="F":
            return "f"
        if input=="G":
            return "g"
        if input=="H":
            return "h"
        if input=="I":
            return "i"
        if input=="J":
            return "j"
        if input=="K":
            return "k"
        if input=="L":
            return "l"
        if input=="M":
            return "m"
        if input=="N":
            return "n"
        if input=="O":
            return "o"
        if input=="P":
            return "p"
        if input=="Q":
            return "q"
        if input=="R":
            return "r"
        if input=="S":
            return "s"
        if input=="T":
            return "t"
        if input=="U":
            return "u"
        if input=="V":
            return "v"
        if input=="W":
            return "w"
        if input=="X":
            return "x"
        if input=="Y":
            return "y"
        if input=="Z":
            return "z"
        return input

    def ToUpper(self: 'CTCodeGenerator',input: 'str') -> 'str':
        index: 'int' = 0
        index = 0
        result: 'str' = ""
        result = ""
        while index<Length(input):
            character: 'str' = ""
            character = At(input,index)
            upper_character: 'str' = ""
            upper_character = self.CharacterToUpper(character)
            result = Concat(result,upper_character)
            index = index+1
        return result

    def CharacterToUpper(self: 'CTCodeGenerator',input: 'str') -> 'str':
        if input=="a":
            return "A"
        if input=="b":
            return "B"
        if input=="c":
            return "C"
        if input=="d":
            return "D"
        if input=="e":
            return "E"
        if input=="f":
            return "F"
        if input=="g":
            return "G"
        if input=="h":
            return "H"
        if input=="i":
            return "I"
        if input=="j":
            return "J"
        if input=="k":
            return "K"
        if input=="l":
            return "L"
        if input=="m":
            return "M"
        if input=="n":
            return "N"
        if input=="o":
            return "O"
        if input=="p":
            return "P"
        if input=="q":
            return "Q"
        if input=="r":
            return "R"
        if input=="s":
            return "S"
        if input=="t":
            return "T"
        if input=="u":
            return "U"
        if input=="v":
            return "V"
        if input=="w":
            return "W"
        if input=="x":
            return "X"
        if input=="y":
            return "Y"
        if input=="z":
            return "Z"
        return input

