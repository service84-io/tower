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

class StringParser:
    def __init__(self: 'StringParser'):
        pass

    def ParseSingleSave(self: 'StringParser',index: 'LengthString',value: 'str',result: 'StringResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        index_data: 'LargeString' = index.GetData()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'String' = String()
        value_length: 'int' = Length(value)
        if value_length>index.GetLength():
            result.SetResult(False)
            return False
        offset_index: 'int' = 0
        while offset_index<value_length:
            if index_data.GetAt(index.GetStart()+offset_index)!=At(value,offset_index):
                result.SetResult(False)
                return False
            offset_index = offset_index+1
        index.SetStart(index.GetStart()+value_length)
        index.SetLength(index.GetLength()-value_length)
        consumed_string.SetLength(index.GetStart()-index_start)
        instance.SetLengthString(consumed_string)
        result.SetValue(instance)
        result.SetResult(True)
        return True

    def ParseSingle(self: 'StringParser',index: 'LengthString',value: 'str') -> 'bool':
        result: 'StringResult' = StringResult()
        return self.ParseSingleSave(index,value,result)

class StringResult:
    def __init__(self: 'StringResult'):
        self.value: String = None
        self.result: bool = False

    def SetValue(self: 'StringResult',new_value: 'String') -> 'None':
        self.value = new_value

    def GetValue(self: 'StringResult') -> 'String':
        return self.value

    def SetResult(self: 'StringResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'StringResult') -> 'bool':
        return self.result

class StringListResult:
    def __init__(self: 'StringListResult'):
        self.value: list[String] = []
        self.result: bool = False

    def SetValue(self: 'StringListResult',new_value: 'list[String]') -> 'None':
        self.value = new_value

    def GetValue(self: 'StringListResult') -> 'list[String]':
        return self.value

    def SetResult(self: 'StringListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'StringListResult') -> 'bool':
        return self.result

class String:
    def __init__(self: 'String'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'String',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'String') -> 'str':
        return self.length_string.GetString()

class CharacterParser:
    def __init__(self: 'CharacterParser'):
        pass

    def ParseSingle(self: 'CharacterParser',index: 'LengthString',value: 'int') -> 'bool':
        if 0==index.GetLength():
            return False
        index_data: 'LargeString' = index.GetData()
        current_character: 'int' = index_data.GetIntAt(index.GetStart())
        if current_character==value:
            index.SetStart(index.GetStart()+1)
            index.SetLength(index.GetLength()-1)
            return True
        return False

class CharacterResult:
    def __init__(self: 'CharacterResult'):
        self.value: Character = None
        self.result: bool = False

    def SetValue(self: 'CharacterResult',new_value: 'Character') -> 'None':
        self.value = new_value

    def GetValue(self: 'CharacterResult') -> 'Character':
        return self.value

    def SetResult(self: 'CharacterResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'CharacterResult') -> 'bool':
        return self.result

class CharacterListResult:
    def __init__(self: 'CharacterListResult'):
        self.value: list[Character] = []
        self.result: bool = False

    def SetValue(self: 'CharacterListResult',new_value: 'list[Character]') -> 'None':
        self.value = new_value

    def GetValue(self: 'CharacterListResult') -> 'list[Character]':
        return self.value

    def SetResult(self: 'CharacterListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'CharacterListResult') -> 'bool':
        return self.result

class Character:
    def __init__(self: 'Character'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'Character',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Character') -> 'str':
        return self.length_string.GetString()

class CharacterRangeParser:
    def __init__(self: 'CharacterRangeParser'):
        pass

    def ParseSingle(self: 'CharacterRangeParser',index: 'LengthString',low_value: 'int',high_value: 'int') -> 'bool':
        if 0==index.GetLength():
            return False
        index_data: 'LargeString' = index.GetData()
        current_character: 'int' = index_data.GetIntAt(index.GetStart())
        if low_value<=current_character and current_character<=high_value:
            index.SetStart(index.GetStart()+1)
            index.SetLength(index.GetLength()-1)
            return True
        return False

class CharacterRangeResult:
    def __init__(self: 'CharacterRangeResult'):
        self.value: CharacterRange = None
        self.result: bool = False

    def SetValue(self: 'CharacterRangeResult',new_value: 'CharacterRange') -> 'None':
        self.value = new_value

    def GetValue(self: 'CharacterRangeResult') -> 'CharacterRange':
        return self.value

    def SetResult(self: 'CharacterRangeResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'CharacterRangeResult') -> 'bool':
        return self.result

class CharacterRangeListResult:
    def __init__(self: 'CharacterRangeListResult'):
        self.value: list[CharacterRange] = []
        self.result: bool = False

    def SetValue(self: 'CharacterRangeListResult',new_value: 'list[CharacterRange]') -> 'None':
        self.value = new_value

    def GetValue(self: 'CharacterRangeListResult') -> 'list[CharacterRange]':
        return self.value

    def SetResult(self: 'CharacterRangeListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'CharacterRangeListResult') -> 'bool':
        return self.result

class CharacterRange:
    def __init__(self: 'CharacterRange'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'CharacterRange',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'CharacterRange') -> 'str':
        return self.length_string.GetString()

class ParserNetwork:
    def __init__(self: 'ParserNetwork'):
        self.grammar_parser_field: GrammarParser = None
        self.rule_parser_field: RuleParser = None
        self.expression_parser_field: ExpressionParser = None
        self.token_parser_field: TokenParser = None
        self.simple_token_parser_field: SimpleTokenParser = None
        self.modifier_parser_field: ModifierParser = None
        self.cardinality_parser_field: CardinalityParser = None
        self.name_parser_field: NameParser = None
        self.name_character_parser_field: NameCharacterParser = None
        self.number_parser_field: NumberParser = None
        self.digit_parser_field: DigitParser = None
        self.punctuation_parser_field: PunctuationParser = None
        self.comment_character_parser_field: CommentCharacterParser = None
        self.comment_parser_field: CommentParser = None
        self.literal_parser_field: LiteralParser = None
        self.literal_character_parser_field: LiteralCharacterParser = None
        self.hex_digit_parser_field: HexDigitParser = None
        self.whitespace_parser_field: WhitespaceParser = None
        self.eol_parser_field: EolParser = None
        self.string_parser_field: StringParser = None
        self.character_parser_field: CharacterParser = None
        self.character_range_parser_field: CharacterRangeParser = None

    def GetGrammarParser(self: 'ParserNetwork') -> 'GrammarParser':
        return self.grammar_parser_field

    def GetRuleParser(self: 'ParserNetwork') -> 'RuleParser':
        return self.rule_parser_field

    def GetExpressionParser(self: 'ParserNetwork') -> 'ExpressionParser':
        return self.expression_parser_field

    def GetTokenParser(self: 'ParserNetwork') -> 'TokenParser':
        return self.token_parser_field

    def GetSimpleTokenParser(self: 'ParserNetwork') -> 'SimpleTokenParser':
        return self.simple_token_parser_field

    def GetModifierParser(self: 'ParserNetwork') -> 'ModifierParser':
        return self.modifier_parser_field

    def GetCardinalityParser(self: 'ParserNetwork') -> 'CardinalityParser':
        return self.cardinality_parser_field

    def GetNameParser(self: 'ParserNetwork') -> 'NameParser':
        return self.name_parser_field

    def GetNameCharacterParser(self: 'ParserNetwork') -> 'NameCharacterParser':
        return self.name_character_parser_field

    def GetNumberParser(self: 'ParserNetwork') -> 'NumberParser':
        return self.number_parser_field

    def GetDigitParser(self: 'ParserNetwork') -> 'DigitParser':
        return self.digit_parser_field

    def GetPunctuationParser(self: 'ParserNetwork') -> 'PunctuationParser':
        return self.punctuation_parser_field

    def GetCommentCharacterParser(self: 'ParserNetwork') -> 'CommentCharacterParser':
        return self.comment_character_parser_field

    def GetCommentParser(self: 'ParserNetwork') -> 'CommentParser':
        return self.comment_parser_field

    def GetLiteralParser(self: 'ParserNetwork') -> 'LiteralParser':
        return self.literal_parser_field

    def GetLiteralCharacterParser(self: 'ParserNetwork') -> 'LiteralCharacterParser':
        return self.literal_character_parser_field

    def GetHexDigitParser(self: 'ParserNetwork') -> 'HexDigitParser':
        return self.hex_digit_parser_field

    def GetWhitespaceParser(self: 'ParserNetwork') -> 'WhitespaceParser':
        return self.whitespace_parser_field

    def GetEolParser(self: 'ParserNetwork') -> 'EolParser':
        return self.eol_parser_field

    def GetStringParser(self: 'ParserNetwork') -> 'StringParser':
        return self.string_parser_field

    def GetCharacterParser(self: 'ParserNetwork') -> 'CharacterParser':
        return self.character_parser_field

    def GetCharacterRangeParser(self: 'ParserNetwork') -> 'CharacterRangeParser':
        return self.character_range_parser_field

    def Initialize(self: 'ParserNetwork') -> 'None':
        self.grammar_parser_field = GrammarParser()
        self.grammar_parser_field.SetParserNetwork(self)
        self.rule_parser_field = RuleParser()
        self.rule_parser_field.SetParserNetwork(self)
        self.expression_parser_field = ExpressionParser()
        self.expression_parser_field.SetParserNetwork(self)
        self.token_parser_field = TokenParser()
        self.token_parser_field.SetParserNetwork(self)
        self.simple_token_parser_field = SimpleTokenParser()
        self.simple_token_parser_field.SetParserNetwork(self)
        self.modifier_parser_field = ModifierParser()
        self.modifier_parser_field.SetParserNetwork(self)
        self.cardinality_parser_field = CardinalityParser()
        self.cardinality_parser_field.SetParserNetwork(self)
        self.name_parser_field = NameParser()
        self.name_parser_field.SetParserNetwork(self)
        self.name_character_parser_field = NameCharacterParser()
        self.name_character_parser_field.SetParserNetwork(self)
        self.number_parser_field = NumberParser()
        self.number_parser_field.SetParserNetwork(self)
        self.digit_parser_field = DigitParser()
        self.digit_parser_field.SetParserNetwork(self)
        self.punctuation_parser_field = PunctuationParser()
        self.punctuation_parser_field.SetParserNetwork(self)
        self.comment_character_parser_field = CommentCharacterParser()
        self.comment_character_parser_field.SetParserNetwork(self)
        self.comment_parser_field = CommentParser()
        self.comment_parser_field.SetParserNetwork(self)
        self.literal_parser_field = LiteralParser()
        self.literal_parser_field.SetParserNetwork(self)
        self.literal_character_parser_field = LiteralCharacterParser()
        self.literal_character_parser_field.SetParserNetwork(self)
        self.hex_digit_parser_field = HexDigitParser()
        self.hex_digit_parser_field.SetParserNetwork(self)
        self.whitespace_parser_field = WhitespaceParser()
        self.whitespace_parser_field.SetParserNetwork(self)
        self.eol_parser_field = EolParser()
        self.eol_parser_field.SetParserNetwork(self)
        self.string_parser_field = StringParser()
        self.character_parser_field = CharacterParser()
        self.character_range_parser_field = CharacterRangeParser()

class DBNFOmniType:
    def __init__(self: 'DBNFOmniType'):
        self.grammar_field: Grammar = None
        self.rule_field: Rule = None
        self.expression_field: Expression = None
        self.token_field: Token = None
        self.simple_token_field: SimpleToken = None
        self.modifier_field: Modifier = None
        self.cardinality_field: Cardinality = None
        self.name_field: Name = None
        self.name_character_field: NameCharacter = None
        self.number_field: Number = None
        self.digit_field: Digit = None
        self.punctuation_field: Punctuation = None
        self.comment_character_field: CommentCharacter = None
        self.comment_field: Comment = None
        self.literal_field: Literal = None
        self.literal_character_field: LiteralCharacter = None
        self.hex_digit_field: HexDigit = None
        self.whitespace_field: Whitespace = None
        self.eol_field: Eol = None

    def SetGrammar(self: 'DBNFOmniType',input_value: 'Grammar') -> 'None':
        self.grammar_field = input_value

    def GetGrammar(self: 'DBNFOmniType') -> 'Grammar':
        return self.grammar_field

    def SetRule(self: 'DBNFOmniType',input_value: 'Rule') -> 'None':
        self.rule_field = input_value

    def GetRule(self: 'DBNFOmniType') -> 'Rule':
        return self.rule_field

    def SetExpression(self: 'DBNFOmniType',input_value: 'Expression') -> 'None':
        self.expression_field = input_value

    def GetExpression(self: 'DBNFOmniType') -> 'Expression':
        return self.expression_field

    def SetToken(self: 'DBNFOmniType',input_value: 'Token') -> 'None':
        self.token_field = input_value

    def GetToken(self: 'DBNFOmniType') -> 'Token':
        return self.token_field

    def SetSimpleToken(self: 'DBNFOmniType',input_value: 'SimpleToken') -> 'None':
        self.simple_token_field = input_value

    def GetSimpleToken(self: 'DBNFOmniType') -> 'SimpleToken':
        return self.simple_token_field

    def SetModifier(self: 'DBNFOmniType',input_value: 'Modifier') -> 'None':
        self.modifier_field = input_value

    def GetModifier(self: 'DBNFOmniType') -> 'Modifier':
        return self.modifier_field

    def SetCardinality(self: 'DBNFOmniType',input_value: 'Cardinality') -> 'None':
        self.cardinality_field = input_value

    def GetCardinality(self: 'DBNFOmniType') -> 'Cardinality':
        return self.cardinality_field

    def SetName(self: 'DBNFOmniType',input_value: 'Name') -> 'None':
        self.name_field = input_value

    def GetName(self: 'DBNFOmniType') -> 'Name':
        return self.name_field

    def SetNameCharacter(self: 'DBNFOmniType',input_value: 'NameCharacter') -> 'None':
        self.name_character_field = input_value

    def GetNameCharacter(self: 'DBNFOmniType') -> 'NameCharacter':
        return self.name_character_field

    def SetNumber(self: 'DBNFOmniType',input_value: 'Number') -> 'None':
        self.number_field = input_value

    def GetNumber(self: 'DBNFOmniType') -> 'Number':
        return self.number_field

    def SetDigit(self: 'DBNFOmniType',input_value: 'Digit') -> 'None':
        self.digit_field = input_value

    def GetDigit(self: 'DBNFOmniType') -> 'Digit':
        return self.digit_field

    def SetPunctuation(self: 'DBNFOmniType',input_value: 'Punctuation') -> 'None':
        self.punctuation_field = input_value

    def GetPunctuation(self: 'DBNFOmniType') -> 'Punctuation':
        return self.punctuation_field

    def SetCommentCharacter(self: 'DBNFOmniType',input_value: 'CommentCharacter') -> 'None':
        self.comment_character_field = input_value

    def GetCommentCharacter(self: 'DBNFOmniType') -> 'CommentCharacter':
        return self.comment_character_field

    def SetComment(self: 'DBNFOmniType',input_value: 'Comment') -> 'None':
        self.comment_field = input_value

    def GetComment(self: 'DBNFOmniType') -> 'Comment':
        return self.comment_field

    def SetLiteral(self: 'DBNFOmniType',input_value: 'Literal') -> 'None':
        self.literal_field = input_value

    def GetLiteral(self: 'DBNFOmniType') -> 'Literal':
        return self.literal_field

    def SetLiteralCharacter(self: 'DBNFOmniType',input_value: 'LiteralCharacter') -> 'None':
        self.literal_character_field = input_value

    def GetLiteralCharacter(self: 'DBNFOmniType') -> 'LiteralCharacter':
        return self.literal_character_field

    def SetHexDigit(self: 'DBNFOmniType',input_value: 'HexDigit') -> 'None':
        self.hex_digit_field = input_value

    def GetHexDigit(self: 'DBNFOmniType') -> 'HexDigit':
        return self.hex_digit_field

    def SetWhitespace(self: 'DBNFOmniType',input_value: 'Whitespace') -> 'None':
        self.whitespace_field = input_value

    def GetWhitespace(self: 'DBNFOmniType') -> 'Whitespace':
        return self.whitespace_field

    def SetEol(self: 'DBNFOmniType',input_value: 'Eol') -> 'None':
        self.eol_field = input_value

    def GetEol(self: 'DBNFOmniType') -> 'Eol':
        return self.eol_field

class DBNFOmniTypeResult:
    def __init__(self: 'DBNFOmniTypeResult'):
        self.value: DBNFOmniType = None
        self.result: bool = False

    def SetValue(self: 'DBNFOmniTypeResult',new_value: 'DBNFOmniType') -> 'None':
        self.value = new_value

    def GetValue(self: 'DBNFOmniTypeResult') -> 'DBNFOmniType':
        return self.value

    def SetResult(self: 'DBNFOmniTypeResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'DBNFOmniTypeResult') -> 'bool':
        return self.result

    def SetGrammar(self: 'DBNFOmniTypeResult',input_value: 'Grammar') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetGrammar(input_value)

    def SetRule(self: 'DBNFOmniTypeResult',input_value: 'Rule') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetRule(input_value)

    def SetExpression(self: 'DBNFOmniTypeResult',input_value: 'Expression') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetExpression(input_value)

    def SetToken(self: 'DBNFOmniTypeResult',input_value: 'Token') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetToken(input_value)

    def SetSimpleToken(self: 'DBNFOmniTypeResult',input_value: 'SimpleToken') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetSimpleToken(input_value)

    def SetModifier(self: 'DBNFOmniTypeResult',input_value: 'Modifier') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetModifier(input_value)

    def SetCardinality(self: 'DBNFOmniTypeResult',input_value: 'Cardinality') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetCardinality(input_value)

    def SetName(self: 'DBNFOmniTypeResult',input_value: 'Name') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetName(input_value)

    def SetNameCharacter(self: 'DBNFOmniTypeResult',input_value: 'NameCharacter') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetNameCharacter(input_value)

    def SetNumber(self: 'DBNFOmniTypeResult',input_value: 'Number') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetNumber(input_value)

    def SetDigit(self: 'DBNFOmniTypeResult',input_value: 'Digit') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetDigit(input_value)

    def SetPunctuation(self: 'DBNFOmniTypeResult',input_value: 'Punctuation') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetPunctuation(input_value)

    def SetCommentCharacter(self: 'DBNFOmniTypeResult',input_value: 'CommentCharacter') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetCommentCharacter(input_value)

    def SetComment(self: 'DBNFOmniTypeResult',input_value: 'Comment') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetComment(input_value)

    def SetLiteral(self: 'DBNFOmniTypeResult',input_value: 'Literal') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetLiteral(input_value)

    def SetLiteralCharacter(self: 'DBNFOmniTypeResult',input_value: 'LiteralCharacter') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetLiteralCharacter(input_value)

    def SetHexDigit(self: 'DBNFOmniTypeResult',input_value: 'HexDigit') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetHexDigit(input_value)

    def SetWhitespace(self: 'DBNFOmniTypeResult',input_value: 'Whitespace') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetWhitespace(input_value)

    def SetEol(self: 'DBNFOmniTypeResult',input_value: 'Eol') -> 'None':
        self.value = DBNFOmniType()
        self.value.SetEol(input_value)

class DBNFOmniTypeListResult:
    def __init__(self: 'DBNFOmniTypeListResult'):
        self.value: list[DBNFOmniType] = []
        self.result: bool = False

    def SetValue(self: 'DBNFOmniTypeListResult',new_value: 'list[DBNFOmniType]') -> 'None':
        self.value = new_value

    def GetValue(self: 'DBNFOmniTypeListResult') -> 'list[DBNFOmniType]':
        return self.value

    def SetResult(self: 'DBNFOmniTypeListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'DBNFOmniTypeListResult') -> 'bool':
        return self.result

    def SetGrammar(self: 'DBNFOmniTypeListResult',input_value: 'list[Grammar]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetGrammar(Element(input_value,index))
            index = index+1

    def SetRule(self: 'DBNFOmniTypeListResult',input_value: 'list[Rule]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetRule(Element(input_value,index))
            index = index+1

    def SetExpression(self: 'DBNFOmniTypeListResult',input_value: 'list[Expression]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetExpression(Element(input_value,index))
            index = index+1

    def SetToken(self: 'DBNFOmniTypeListResult',input_value: 'list[Token]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetToken(Element(input_value,index))
            index = index+1

    def SetSimpleToken(self: 'DBNFOmniTypeListResult',input_value: 'list[SimpleToken]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetSimpleToken(Element(input_value,index))
            index = index+1

    def SetModifier(self: 'DBNFOmniTypeListResult',input_value: 'list[Modifier]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetModifier(Element(input_value,index))
            index = index+1

    def SetCardinality(self: 'DBNFOmniTypeListResult',input_value: 'list[Cardinality]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetCardinality(Element(input_value,index))
            index = index+1

    def SetName(self: 'DBNFOmniTypeListResult',input_value: 'list[Name]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetName(Element(input_value,index))
            index = index+1

    def SetNameCharacter(self: 'DBNFOmniTypeListResult',input_value: 'list[NameCharacter]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetNameCharacter(Element(input_value,index))
            index = index+1

    def SetNumber(self: 'DBNFOmniTypeListResult',input_value: 'list[Number]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetNumber(Element(input_value,index))
            index = index+1

    def SetDigit(self: 'DBNFOmniTypeListResult',input_value: 'list[Digit]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetDigit(Element(input_value,index))
            index = index+1

    def SetPunctuation(self: 'DBNFOmniTypeListResult',input_value: 'list[Punctuation]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetPunctuation(Element(input_value,index))
            index = index+1

    def SetCommentCharacter(self: 'DBNFOmniTypeListResult',input_value: 'list[CommentCharacter]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetCommentCharacter(Element(input_value,index))
            index = index+1

    def SetComment(self: 'DBNFOmniTypeListResult',input_value: 'list[Comment]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetComment(Element(input_value,index))
            index = index+1

    def SetLiteral(self: 'DBNFOmniTypeListResult',input_value: 'list[Literal]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetLiteral(Element(input_value,index))
            index = index+1

    def SetLiteralCharacter(self: 'DBNFOmniTypeListResult',input_value: 'list[LiteralCharacter]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetLiteralCharacter(Element(input_value,index))
            index = index+1

    def SetHexDigit(self: 'DBNFOmniTypeListResult',input_value: 'list[HexDigit]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetHexDigit(Element(input_value,index))
            index = index+1

    def SetWhitespace(self: 'DBNFOmniTypeListResult',input_value: 'list[Whitespace]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetWhitespace(Element(input_value,index))
            index = index+1

    def SetEol(self: 'DBNFOmniTypeListResult',input_value: 'list[Eol]') -> 'None':
        index: 'int' = 0
        while index<Size(input_value):
            value: 'DBNFOmniType' = DBNFOmniType()
            value.SetEol(Element(input_value,index))
            index = index+1

class LargeString:
    def __init__(self: 'LargeString'):
        self.data: str = ""

    def SetData(self: 'LargeString',new_data: 'str') -> 'None':
        self.data = new_data

    def GetData(self: 'LargeString') -> 'str':
        return self.data

    def GetIntAt(self: 'LargeString',offset: 'int') -> 'int':
        return IntAt(self.data,offset)

    def GetAt(self: 'LargeString',offset: 'int') -> 'str':
        return At(self.data,offset)

class LengthString:
    def __init__(self: 'LengthString'):
        self.data: LargeString = None
        self.start: int = 0
        self.length: int = 0

    def SetData(self: 'LengthString',new_data: 'LargeString') -> 'None':
        self.data = new_data

    def GetData(self: 'LengthString') -> 'LargeString':
        return self.data

    def SetStart(self: 'LengthString',new_start: 'int') -> 'None':
        self.start = new_start

    def GetStart(self: 'LengthString') -> 'int':
        return self.start

    def SetLength(self: 'LengthString',new_length: 'int') -> 'None':
        self.length = new_length

    def GetLength(self: 'LengthString') -> 'int':
        return self.length

    def GetString(self: 'LengthString') -> 'str':
        deep_data: 'str' = self.data.GetData()
        result: 'str' = ""
        index: 'int' = self.start
        end: 'int' = self.start+self.length
        while index<end:
            result = Concat(result,At(deep_data,index))
            index = index+1
        return result

class GrammarParser:
    def __init__(self: 'GrammarParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'GrammarParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'GrammarParser',index: 'LengthString',result: 'GrammarResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Grammar' = Grammar()
        rules_field: 'RuleListResult' = RuleListResult()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and rule_parser_instance.ParseManySave(index,rules_field,0,-1):
            instance.SetRules(rules_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            rules_field = RuleListResult()
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'GrammarParser',index: 'LengthString') -> 'bool':
        result: 'GrammarResult' = GrammarResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'GrammarParser',index: 'LengthString',result: 'GrammarResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'GrammarParser',index: 'LengthString') -> 'bool':
        result: 'GrammarResult' = GrammarResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'GrammarParser',index: 'LengthString',list_result: 'GrammarListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Grammar]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'GrammarResult' = GrammarResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'GrammarParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'GrammarListResult' = GrammarListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class GrammarResult:
    def __init__(self: 'GrammarResult'):
        self.value: Grammar = None
        self.result: bool = False

    def SetValue(self: 'GrammarResult',new_value: 'Grammar') -> 'None':
        self.value = new_value

    def GetValue(self: 'GrammarResult') -> 'Grammar':
        return self.value

    def SetResult(self: 'GrammarResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'GrammarResult') -> 'bool':
        return self.result

class GrammarListResult:
    def __init__(self: 'GrammarListResult'):
        self.value: list[Grammar] = []
        self.result: bool = False

    def SetValue(self: 'GrammarListResult',new_value: 'list[Grammar]') -> 'None':
        self.value = new_value

    def GetValue(self: 'GrammarListResult') -> 'list[Grammar]':
        return self.value

    def SetResult(self: 'GrammarListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'GrammarListResult') -> 'bool':
        return self.result

class Grammar:
    def __init__(self: 'Grammar'):
        self.length_string: LengthString = None
        self.rules_field: list[Rule] = []

    def SetLengthString(self: 'Grammar',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Grammar') -> 'str':
        return self.length_string.GetString()

    def SetRules(self: 'Grammar',input_value: 'list[Rule]') -> 'None':
        self.rules_field = input_value

    def GetRules(self: 'Grammar') -> 'list[Rule]':
        return self.rules_field

class RuleParser:
    def __init__(self: 'RuleParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'RuleParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'RuleParser',index: 'LengthString',result: 'RuleResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Rule' = Rule()
        expressions_field: 'ExpressionListResult' = ExpressionListResult()
        name_field: 'NameResult' = NameResult()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,"<") and name_parser_instance.ParseSingleSave(index,name_field) and string_parser_instance.ParseSingle(index,">") and expression_parser_instance.ParseManySave(index,expressions_field,0,-1):
            instance.SetExpressions(expressions_field.GetValue())
            instance.SetName(name_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            expressions_field = ExpressionListResult()
            name_field = NameResult()
        if True and comment_parser_instance.ParseSingle(index):
            instance.SetExpressions(expressions_field.GetValue())
            instance.SetName(name_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            expressions_field = ExpressionListResult()
            name_field = NameResult()
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'RuleParser',index: 'LengthString') -> 'bool':
        result: 'RuleResult' = RuleResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'RuleParser',index: 'LengthString',result: 'RuleResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'RuleParser',index: 'LengthString') -> 'bool':
        result: 'RuleResult' = RuleResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'RuleParser',index: 'LengthString',list_result: 'RuleListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Rule]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'RuleResult' = RuleResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'RuleParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'RuleListResult' = RuleListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class RuleResult:
    def __init__(self: 'RuleResult'):
        self.value: Rule = None
        self.result: bool = False

    def SetValue(self: 'RuleResult',new_value: 'Rule') -> 'None':
        self.value = new_value

    def GetValue(self: 'RuleResult') -> 'Rule':
        return self.value

    def SetResult(self: 'RuleResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'RuleResult') -> 'bool':
        return self.result

class RuleListResult:
    def __init__(self: 'RuleListResult'):
        self.value: list[Rule] = []
        self.result: bool = False

    def SetValue(self: 'RuleListResult',new_value: 'list[Rule]') -> 'None':
        self.value = new_value

    def GetValue(self: 'RuleListResult') -> 'list[Rule]':
        return self.value

    def SetResult(self: 'RuleListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'RuleListResult') -> 'bool':
        return self.result

class Rule:
    def __init__(self: 'Rule'):
        self.length_string: LengthString = None
        self.expressions_field: list[Expression] = []
        self.name_field: Name = None

    def SetLengthString(self: 'Rule',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Rule') -> 'str':
        return self.length_string.GetString()

    def SetExpressions(self: 'Rule',input_value: 'list[Expression]') -> 'None':
        self.expressions_field = input_value

    def GetExpressions(self: 'Rule') -> 'list[Expression]':
        return self.expressions_field

    def SetName(self: 'Rule',input_value: 'Name') -> 'None':
        self.name_field = input_value

    def GetName(self: 'Rule') -> 'Name':
        return self.name_field

class ExpressionParser:
    def __init__(self: 'ExpressionParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'ExpressionParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'ExpressionParser',index: 'LengthString',result: 'ExpressionResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Expression' = Expression()
        token_sequence_field: 'TokenListResult' = TokenListResult()
        expression_discriminator_field: 'StringResult' = StringResult()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingleSave(index,"::=",expression_discriminator_field) and token_parser_instance.ParseManySave(index,token_sequence_field,0,-1) and eol_parser_instance.ParseSingle(index):
            instance.SetTokenSequence(token_sequence_field.GetValue())
            instance.SetExpressionDiscriminator(expression_discriminator_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            token_sequence_field = TokenListResult()
            expression_discriminator_field = StringResult()
        if True and comment_parser_instance.ParseSingle(index):
            instance.SetTokenSequence(token_sequence_field.GetValue())
            instance.SetExpressionDiscriminator(expression_discriminator_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            token_sequence_field = TokenListResult()
            expression_discriminator_field = StringResult()
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'ExpressionParser',index: 'LengthString') -> 'bool':
        result: 'ExpressionResult' = ExpressionResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'ExpressionParser',index: 'LengthString',result: 'ExpressionResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'ExpressionParser',index: 'LengthString') -> 'bool':
        result: 'ExpressionResult' = ExpressionResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'ExpressionParser',index: 'LengthString',list_result: 'ExpressionListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Expression]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'ExpressionResult' = ExpressionResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'ExpressionParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'ExpressionListResult' = ExpressionListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class ExpressionResult:
    def __init__(self: 'ExpressionResult'):
        self.value: Expression = None
        self.result: bool = False

    def SetValue(self: 'ExpressionResult',new_value: 'Expression') -> 'None':
        self.value = new_value

    def GetValue(self: 'ExpressionResult') -> 'Expression':
        return self.value

    def SetResult(self: 'ExpressionResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'ExpressionResult') -> 'bool':
        return self.result

class ExpressionListResult:
    def __init__(self: 'ExpressionListResult'):
        self.value: list[Expression] = []
        self.result: bool = False

    def SetValue(self: 'ExpressionListResult',new_value: 'list[Expression]') -> 'None':
        self.value = new_value

    def GetValue(self: 'ExpressionListResult') -> 'list[Expression]':
        return self.value

    def SetResult(self: 'ExpressionListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'ExpressionListResult') -> 'bool':
        return self.result

class Expression:
    def __init__(self: 'Expression'):
        self.length_string: LengthString = None
        self.token_sequence_field: list[Token] = []
        self.expression_discriminator_field: String = None

    def SetLengthString(self: 'Expression',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Expression') -> 'str':
        return self.length_string.GetString()

    def SetTokenSequence(self: 'Expression',input_value: 'list[Token]') -> 'None':
        self.token_sequence_field = input_value

    def GetTokenSequence(self: 'Expression') -> 'list[Token]':
        return self.token_sequence_field

    def SetExpressionDiscriminator(self: 'Expression',input_value: 'String') -> 'None':
        self.expression_discriminator_field = input_value

    def GetExpressionDiscriminator(self: 'Expression') -> 'String':
        return self.expression_discriminator_field

class TokenParser:
    def __init__(self: 'TokenParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'TokenParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'TokenParser',index: 'LengthString',result: 'TokenResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Token' = Token()
        modifier_field: 'ModifierResult' = ModifierResult()
        value_field: 'SimpleTokenResult' = SimpleTokenResult()
        name_field: 'NameResult' = NameResult()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,"attribute") and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,"(") and whitespace_parser_instance.ParseMany(index,0,-1) and name_parser_instance.ParseSingleSave(index,name_field) and whitespace_parser_instance.ParseMany(index,0,-1) and simple_token_parser_instance.ParseSingleSave(index,value_field) and whitespace_parser_instance.ParseMany(index,0,-1) and modifier_parser_instance.ParseSingleSave(index,modifier_field) and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,")") and whitespace_parser_instance.ParseMany(index,0,-1):
            instance.SetModifier(modifier_field.GetValue())
            instance.SetValue(value_field.GetValue())
            instance.SetName(name_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            modifier_field = ModifierResult()
            value_field = SimpleTokenResult()
            name_field = NameResult()
        if True and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,"attribute") and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,"(") and whitespace_parser_instance.ParseMany(index,0,-1) and name_parser_instance.ParseSingleSave(index,name_field) and whitespace_parser_instance.ParseMany(index,0,-1) and simple_token_parser_instance.ParseSingleSave(index,value_field) and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,")") and whitespace_parser_instance.ParseMany(index,0,-1):
            instance.SetModifier(modifier_field.GetValue())
            instance.SetValue(value_field.GetValue())
            instance.SetName(name_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            modifier_field = ModifierResult()
            value_field = SimpleTokenResult()
            name_field = NameResult()
        if True and whitespace_parser_instance.ParseMany(index,0,-1) and simple_token_parser_instance.ParseSingleSave(index,value_field) and whitespace_parser_instance.ParseMany(index,0,-1) and modifier_parser_instance.ParseSingleSave(index,modifier_field) and whitespace_parser_instance.ParseMany(index,0,-1):
            instance.SetModifier(modifier_field.GetValue())
            instance.SetValue(value_field.GetValue())
            instance.SetName(name_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            modifier_field = ModifierResult()
            value_field = SimpleTokenResult()
            name_field = NameResult()
        if True and whitespace_parser_instance.ParseMany(index,0,-1) and simple_token_parser_instance.ParseSingleSave(index,value_field) and whitespace_parser_instance.ParseMany(index,0,-1):
            instance.SetModifier(modifier_field.GetValue())
            instance.SetValue(value_field.GetValue())
            instance.SetName(name_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            modifier_field = ModifierResult()
            value_field = SimpleTokenResult()
            name_field = NameResult()
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'TokenParser',index: 'LengthString') -> 'bool':
        result: 'TokenResult' = TokenResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'TokenParser',index: 'LengthString',result: 'TokenResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'TokenParser',index: 'LengthString') -> 'bool':
        result: 'TokenResult' = TokenResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'TokenParser',index: 'LengthString',list_result: 'TokenListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Token]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'TokenResult' = TokenResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'TokenParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'TokenListResult' = TokenListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class TokenResult:
    def __init__(self: 'TokenResult'):
        self.value: Token = None
        self.result: bool = False

    def SetValue(self: 'TokenResult',new_value: 'Token') -> 'None':
        self.value = new_value

    def GetValue(self: 'TokenResult') -> 'Token':
        return self.value

    def SetResult(self: 'TokenResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'TokenResult') -> 'bool':
        return self.result

class TokenListResult:
    def __init__(self: 'TokenListResult'):
        self.value: list[Token] = []
        self.result: bool = False

    def SetValue(self: 'TokenListResult',new_value: 'list[Token]') -> 'None':
        self.value = new_value

    def GetValue(self: 'TokenListResult') -> 'list[Token]':
        return self.value

    def SetResult(self: 'TokenListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'TokenListResult') -> 'bool':
        return self.result

class Token:
    def __init__(self: 'Token'):
        self.length_string: LengthString = None
        self.modifier_field: Modifier = None
        self.value_field: SimpleToken = None
        self.name_field: Name = None

    def SetLengthString(self: 'Token',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Token') -> 'str':
        return self.length_string.GetString()

    def SetModifier(self: 'Token',input_value: 'Modifier') -> 'None':
        self.modifier_field = input_value

    def GetModifier(self: 'Token') -> 'Modifier':
        return self.modifier_field

    def SetValue(self: 'Token',input_value: 'SimpleToken') -> 'None':
        self.value_field = input_value

    def GetValue(self: 'Token') -> 'SimpleToken':
        return self.value_field

    def SetName(self: 'Token',input_value: 'Name') -> 'None':
        self.name_field = input_value

    def GetName(self: 'Token') -> 'Name':
        return self.name_field

class SimpleTokenParser:
    def __init__(self: 'SimpleTokenParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'SimpleTokenParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'SimpleTokenParser',index: 'LengthString',result: 'SimpleTokenResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'SimpleToken' = SimpleToken()
        high_low_field: 'HexDigitResult' = HexDigitResult()
        high_high_field: 'HexDigitResult' = HexDigitResult()
        low_low_field: 'HexDigitResult' = HexDigitResult()
        low_high_field: 'HexDigitResult' = HexDigitResult()
        low_field: 'HexDigitResult' = HexDigitResult()
        literal_field: 'LiteralResult' = LiteralResult()
        high_field: 'HexDigitResult' = HexDigitResult()
        token_field: 'NameResult' = NameResult()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and string_parser_instance.ParseSingle(index,"<") and name_parser_instance.ParseSingleSave(index,token_field) and string_parser_instance.ParseSingle(index,">"):
            instance.SetHighLow(high_low_field.GetValue())
            instance.SetHighHigh(high_high_field.GetValue())
            instance.SetLowLow(low_low_field.GetValue())
            instance.SetLowHigh(low_high_field.GetValue())
            instance.SetLow(low_field.GetValue())
            instance.SetLiteral(literal_field.GetValue())
            instance.SetHigh(high_field.GetValue())
            instance.SetToken(token_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            high_low_field = HexDigitResult()
            high_high_field = HexDigitResult()
            low_low_field = HexDigitResult()
            low_high_field = HexDigitResult()
            low_field = HexDigitResult()
            literal_field = LiteralResult()
            high_field = HexDigitResult()
            token_field = NameResult()
        if True and string_parser_instance.ParseSingle(index,"0x") and hex_digit_parser_instance.ParseSingleSave(index,high_field) and hex_digit_parser_instance.ParseSingleSave(index,low_field):
            instance.SetHighLow(high_low_field.GetValue())
            instance.SetHighHigh(high_high_field.GetValue())
            instance.SetLowLow(low_low_field.GetValue())
            instance.SetLowHigh(low_high_field.GetValue())
            instance.SetLow(low_field.GetValue())
            instance.SetLiteral(literal_field.GetValue())
            instance.SetHigh(high_field.GetValue())
            instance.SetToken(token_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            high_low_field = HexDigitResult()
            high_high_field = HexDigitResult()
            low_low_field = HexDigitResult()
            low_high_field = HexDigitResult()
            low_field = HexDigitResult()
            literal_field = LiteralResult()
            high_field = HexDigitResult()
            token_field = NameResult()
        if True and string_parser_instance.ParseSingle(index,"\"") and literal_parser_instance.ParseSingleSave(index,literal_field) and string_parser_instance.ParseSingle(index,"\""):
            instance.SetHighLow(high_low_field.GetValue())
            instance.SetHighHigh(high_high_field.GetValue())
            instance.SetLowLow(low_low_field.GetValue())
            instance.SetLowHigh(low_high_field.GetValue())
            instance.SetLow(low_field.GetValue())
            instance.SetLiteral(literal_field.GetValue())
            instance.SetHigh(high_field.GetValue())
            instance.SetToken(token_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            high_low_field = HexDigitResult()
            high_high_field = HexDigitResult()
            low_low_field = HexDigitResult()
            low_high_field = HexDigitResult()
            low_field = HexDigitResult()
            literal_field = LiteralResult()
            high_field = HexDigitResult()
            token_field = NameResult()
        if True and string_parser_instance.ParseSingle(index,"[0x") and hex_digit_parser_instance.ParseSingleSave(index,low_high_field) and hex_digit_parser_instance.ParseSingleSave(index,low_low_field) and string_parser_instance.ParseSingle(index,"-0x") and hex_digit_parser_instance.ParseSingleSave(index,high_high_field) and hex_digit_parser_instance.ParseSingleSave(index,high_low_field) and string_parser_instance.ParseSingle(index,"]"):
            instance.SetHighLow(high_low_field.GetValue())
            instance.SetHighHigh(high_high_field.GetValue())
            instance.SetLowLow(low_low_field.GetValue())
            instance.SetLowHigh(low_high_field.GetValue())
            instance.SetLow(low_field.GetValue())
            instance.SetLiteral(literal_field.GetValue())
            instance.SetHigh(high_field.GetValue())
            instance.SetToken(token_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            high_low_field = HexDigitResult()
            high_high_field = HexDigitResult()
            low_low_field = HexDigitResult()
            low_high_field = HexDigitResult()
            low_field = HexDigitResult()
            literal_field = LiteralResult()
            high_field = HexDigitResult()
            token_field = NameResult()
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'SimpleTokenParser',index: 'LengthString') -> 'bool':
        result: 'SimpleTokenResult' = SimpleTokenResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'SimpleTokenParser',index: 'LengthString',result: 'SimpleTokenResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'SimpleTokenParser',index: 'LengthString') -> 'bool':
        result: 'SimpleTokenResult' = SimpleTokenResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'SimpleTokenParser',index: 'LengthString',list_result: 'SimpleTokenListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[SimpleToken]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'SimpleTokenResult' = SimpleTokenResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'SimpleTokenParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'SimpleTokenListResult' = SimpleTokenListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class SimpleTokenResult:
    def __init__(self: 'SimpleTokenResult'):
        self.value: SimpleToken = None
        self.result: bool = False

    def SetValue(self: 'SimpleTokenResult',new_value: 'SimpleToken') -> 'None':
        self.value = new_value

    def GetValue(self: 'SimpleTokenResult') -> 'SimpleToken':
        return self.value

    def SetResult(self: 'SimpleTokenResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'SimpleTokenResult') -> 'bool':
        return self.result

class SimpleTokenListResult:
    def __init__(self: 'SimpleTokenListResult'):
        self.value: list[SimpleToken] = []
        self.result: bool = False

    def SetValue(self: 'SimpleTokenListResult',new_value: 'list[SimpleToken]') -> 'None':
        self.value = new_value

    def GetValue(self: 'SimpleTokenListResult') -> 'list[SimpleToken]':
        return self.value

    def SetResult(self: 'SimpleTokenListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'SimpleTokenListResult') -> 'bool':
        return self.result

class SimpleToken:
    def __init__(self: 'SimpleToken'):
        self.length_string: LengthString = None
        self.high_low_field: HexDigit = None
        self.high_high_field: HexDigit = None
        self.low_low_field: HexDigit = None
        self.low_high_field: HexDigit = None
        self.low_field: HexDigit = None
        self.literal_field: Literal = None
        self.high_field: HexDigit = None
        self.token_field: Name = None

    def SetLengthString(self: 'SimpleToken',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'SimpleToken') -> 'str':
        return self.length_string.GetString()

    def SetHighLow(self: 'SimpleToken',input_value: 'HexDigit') -> 'None':
        self.high_low_field = input_value

    def GetHighLow(self: 'SimpleToken') -> 'HexDigit':
        return self.high_low_field

    def SetHighHigh(self: 'SimpleToken',input_value: 'HexDigit') -> 'None':
        self.high_high_field = input_value

    def GetHighHigh(self: 'SimpleToken') -> 'HexDigit':
        return self.high_high_field

    def SetLowLow(self: 'SimpleToken',input_value: 'HexDigit') -> 'None':
        self.low_low_field = input_value

    def GetLowLow(self: 'SimpleToken') -> 'HexDigit':
        return self.low_low_field

    def SetLowHigh(self: 'SimpleToken',input_value: 'HexDigit') -> 'None':
        self.low_high_field = input_value

    def GetLowHigh(self: 'SimpleToken') -> 'HexDigit':
        return self.low_high_field

    def SetLow(self: 'SimpleToken',input_value: 'HexDigit') -> 'None':
        self.low_field = input_value

    def GetLow(self: 'SimpleToken') -> 'HexDigit':
        return self.low_field

    def SetLiteral(self: 'SimpleToken',input_value: 'Literal') -> 'None':
        self.literal_field = input_value

    def GetLiteral(self: 'SimpleToken') -> 'Literal':
        return self.literal_field

    def SetHigh(self: 'SimpleToken',input_value: 'HexDigit') -> 'None':
        self.high_field = input_value

    def GetHigh(self: 'SimpleToken') -> 'HexDigit':
        return self.high_field

    def SetToken(self: 'SimpleToken',input_value: 'Name') -> 'None':
        self.token_field = input_value

    def GetToken(self: 'SimpleToken') -> 'Name':
        return self.token_field

class ModifierParser:
    def __init__(self: 'ModifierParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'ModifierParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'ModifierParser',index: 'LengthString',result: 'ModifierResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Modifier' = Modifier()
        cardinality_field: 'CardinalityResult' = CardinalityResult()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and string_parser_instance.ParseSingle(index,"*"):
            instance.SetCardinality(cardinality_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            cardinality_field = CardinalityResult()
        if True and string_parser_instance.ParseSingle(index,"?"):
            instance.SetCardinality(cardinality_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            cardinality_field = CardinalityResult()
        if True and string_parser_instance.ParseSingle(index,"+"):
            instance.SetCardinality(cardinality_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            cardinality_field = CardinalityResult()
        if True and string_parser_instance.ParseSingle(index,"{") and whitespace_parser_instance.ParseMany(index,0,-1) and cardinality_parser_instance.ParseSingleSave(index,cardinality_field) and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,"}"):
            instance.SetCardinality(cardinality_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            cardinality_field = CardinalityResult()
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'ModifierParser',index: 'LengthString') -> 'bool':
        result: 'ModifierResult' = ModifierResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'ModifierParser',index: 'LengthString',result: 'ModifierResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'ModifierParser',index: 'LengthString') -> 'bool':
        result: 'ModifierResult' = ModifierResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'ModifierParser',index: 'LengthString',list_result: 'ModifierListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Modifier]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'ModifierResult' = ModifierResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'ModifierParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'ModifierListResult' = ModifierListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class ModifierResult:
    def __init__(self: 'ModifierResult'):
        self.value: Modifier = None
        self.result: bool = False

    def SetValue(self: 'ModifierResult',new_value: 'Modifier') -> 'None':
        self.value = new_value

    def GetValue(self: 'ModifierResult') -> 'Modifier':
        return self.value

    def SetResult(self: 'ModifierResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'ModifierResult') -> 'bool':
        return self.result

class ModifierListResult:
    def __init__(self: 'ModifierListResult'):
        self.value: list[Modifier] = []
        self.result: bool = False

    def SetValue(self: 'ModifierListResult',new_value: 'list[Modifier]') -> 'None':
        self.value = new_value

    def GetValue(self: 'ModifierListResult') -> 'list[Modifier]':
        return self.value

    def SetResult(self: 'ModifierListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'ModifierListResult') -> 'bool':
        return self.result

class Modifier:
    def __init__(self: 'Modifier'):
        self.length_string: LengthString = None
        self.cardinality_field: Cardinality = None

    def SetLengthString(self: 'Modifier',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Modifier') -> 'str':
        return self.length_string.GetString()

    def SetCardinality(self: 'Modifier',input_value: 'Cardinality') -> 'None':
        self.cardinality_field = input_value

    def GetCardinality(self: 'Modifier') -> 'Cardinality':
        return self.cardinality_field

class CardinalityParser:
    def __init__(self: 'CardinalityParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'CardinalityParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'CardinalityParser',index: 'LengthString',result: 'CardinalityResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Cardinality' = Cardinality()
        maximum_field: 'NumberResult' = NumberResult()
        count_field: 'NumberResult' = NumberResult()
        minimum_field: 'NumberResult' = NumberResult()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and number_parser_instance.ParseSingleSave(index,minimum_field) and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,",") and whitespace_parser_instance.ParseMany(index,0,-1) and number_parser_instance.ParseSingleSave(index,maximum_field):
            instance.SetMaximum(maximum_field.GetValue())
            instance.SetCount(count_field.GetValue())
            instance.SetMinimum(minimum_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            maximum_field = NumberResult()
            count_field = NumberResult()
            minimum_field = NumberResult()
        if True and number_parser_instance.ParseSingleSave(index,minimum_field) and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,","):
            instance.SetMaximum(maximum_field.GetValue())
            instance.SetCount(count_field.GetValue())
            instance.SetMinimum(minimum_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            maximum_field = NumberResult()
            count_field = NumberResult()
            minimum_field = NumberResult()
        if True and number_parser_instance.ParseSingleSave(index,count_field):
            instance.SetMaximum(maximum_field.GetValue())
            instance.SetCount(count_field.GetValue())
            instance.SetMinimum(minimum_field.GetValue())
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            maximum_field = NumberResult()
            count_field = NumberResult()
            minimum_field = NumberResult()
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'CardinalityParser',index: 'LengthString') -> 'bool':
        result: 'CardinalityResult' = CardinalityResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'CardinalityParser',index: 'LengthString',result: 'CardinalityResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'CardinalityParser',index: 'LengthString') -> 'bool':
        result: 'CardinalityResult' = CardinalityResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'CardinalityParser',index: 'LengthString',list_result: 'CardinalityListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Cardinality]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'CardinalityResult' = CardinalityResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'CardinalityParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'CardinalityListResult' = CardinalityListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class CardinalityResult:
    def __init__(self: 'CardinalityResult'):
        self.value: Cardinality = None
        self.result: bool = False

    def SetValue(self: 'CardinalityResult',new_value: 'Cardinality') -> 'None':
        self.value = new_value

    def GetValue(self: 'CardinalityResult') -> 'Cardinality':
        return self.value

    def SetResult(self: 'CardinalityResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'CardinalityResult') -> 'bool':
        return self.result

class CardinalityListResult:
    def __init__(self: 'CardinalityListResult'):
        self.value: list[Cardinality] = []
        self.result: bool = False

    def SetValue(self: 'CardinalityListResult',new_value: 'list[Cardinality]') -> 'None':
        self.value = new_value

    def GetValue(self: 'CardinalityListResult') -> 'list[Cardinality]':
        return self.value

    def SetResult(self: 'CardinalityListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'CardinalityListResult') -> 'bool':
        return self.result

class Cardinality:
    def __init__(self: 'Cardinality'):
        self.length_string: LengthString = None
        self.maximum_field: Number = None
        self.count_field: Number = None
        self.minimum_field: Number = None

    def SetLengthString(self: 'Cardinality',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Cardinality') -> 'str':
        return self.length_string.GetString()

    def SetMaximum(self: 'Cardinality',input_value: 'Number') -> 'None':
        self.maximum_field = input_value

    def GetMaximum(self: 'Cardinality') -> 'Number':
        return self.maximum_field

    def SetCount(self: 'Cardinality',input_value: 'Number') -> 'None':
        self.count_field = input_value

    def GetCount(self: 'Cardinality') -> 'Number':
        return self.count_field

    def SetMinimum(self: 'Cardinality',input_value: 'Number') -> 'None':
        self.minimum_field = input_value

    def GetMinimum(self: 'Cardinality') -> 'Number':
        return self.minimum_field

class NameParser:
    def __init__(self: 'NameParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'NameParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'NameParser',index: 'LengthString',result: 'NameResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Name' = Name()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and name_character_parser_instance.ParseMany(index,1,-1):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'NameParser',index: 'LengthString') -> 'bool':
        result: 'NameResult' = NameResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'NameParser',index: 'LengthString',result: 'NameResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'NameParser',index: 'LengthString') -> 'bool':
        result: 'NameResult' = NameResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'NameParser',index: 'LengthString',list_result: 'NameListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Name]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'NameResult' = NameResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'NameParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'NameListResult' = NameListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class NameResult:
    def __init__(self: 'NameResult'):
        self.value: Name = None
        self.result: bool = False

    def SetValue(self: 'NameResult',new_value: 'Name') -> 'None':
        self.value = new_value

    def GetValue(self: 'NameResult') -> 'Name':
        return self.value

    def SetResult(self: 'NameResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'NameResult') -> 'bool':
        return self.result

class NameListResult:
    def __init__(self: 'NameListResult'):
        self.value: list[Name] = []
        self.result: bool = False

    def SetValue(self: 'NameListResult',new_value: 'list[Name]') -> 'None':
        self.value = new_value

    def GetValue(self: 'NameListResult') -> 'list[Name]':
        return self.value

    def SetResult(self: 'NameListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'NameListResult') -> 'bool':
        return self.result

class Name:
    def __init__(self: 'Name'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'Name',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Name') -> 'str':
        return self.length_string.GetString()

class NameCharacterParser:
    def __init__(self: 'NameCharacterParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'NameCharacterParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'NameCharacterParser',index: 'LengthString',result: 'NameCharacterResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'NameCharacter' = NameCharacter()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and character_range_parser_instance.ParseSingle(index,0x30,0x39):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and character_range_parser_instance.ParseSingle(index,0x41,0x5A):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and string_parser_instance.ParseSingle(index,"_"):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and character_range_parser_instance.ParseSingle(index,0x61,0x7A):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'NameCharacterParser',index: 'LengthString') -> 'bool':
        result: 'NameCharacterResult' = NameCharacterResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'NameCharacterParser',index: 'LengthString',result: 'NameCharacterResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'NameCharacterParser',index: 'LengthString') -> 'bool':
        result: 'NameCharacterResult' = NameCharacterResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'NameCharacterParser',index: 'LengthString',list_result: 'NameCharacterListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[NameCharacter]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'NameCharacterResult' = NameCharacterResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'NameCharacterParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'NameCharacterListResult' = NameCharacterListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class NameCharacterResult:
    def __init__(self: 'NameCharacterResult'):
        self.value: NameCharacter = None
        self.result: bool = False

    def SetValue(self: 'NameCharacterResult',new_value: 'NameCharacter') -> 'None':
        self.value = new_value

    def GetValue(self: 'NameCharacterResult') -> 'NameCharacter':
        return self.value

    def SetResult(self: 'NameCharacterResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'NameCharacterResult') -> 'bool':
        return self.result

class NameCharacterListResult:
    def __init__(self: 'NameCharacterListResult'):
        self.value: list[NameCharacter] = []
        self.result: bool = False

    def SetValue(self: 'NameCharacterListResult',new_value: 'list[NameCharacter]') -> 'None':
        self.value = new_value

    def GetValue(self: 'NameCharacterListResult') -> 'list[NameCharacter]':
        return self.value

    def SetResult(self: 'NameCharacterListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'NameCharacterListResult') -> 'bool':
        return self.result

class NameCharacter:
    def __init__(self: 'NameCharacter'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'NameCharacter',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'NameCharacter') -> 'str':
        return self.length_string.GetString()

class NumberParser:
    def __init__(self: 'NumberParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'NumberParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'NumberParser',index: 'LengthString',result: 'NumberResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Number' = Number()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and digit_parser_instance.ParseMany(index,1,-1):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'NumberParser',index: 'LengthString') -> 'bool':
        result: 'NumberResult' = NumberResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'NumberParser',index: 'LengthString',result: 'NumberResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'NumberParser',index: 'LengthString') -> 'bool':
        result: 'NumberResult' = NumberResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'NumberParser',index: 'LengthString',list_result: 'NumberListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Number]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'NumberResult' = NumberResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'NumberParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'NumberListResult' = NumberListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class NumberResult:
    def __init__(self: 'NumberResult'):
        self.value: Number = None
        self.result: bool = False

    def SetValue(self: 'NumberResult',new_value: 'Number') -> 'None':
        self.value = new_value

    def GetValue(self: 'NumberResult') -> 'Number':
        return self.value

    def SetResult(self: 'NumberResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'NumberResult') -> 'bool':
        return self.result

class NumberListResult:
    def __init__(self: 'NumberListResult'):
        self.value: list[Number] = []
        self.result: bool = False

    def SetValue(self: 'NumberListResult',new_value: 'list[Number]') -> 'None':
        self.value = new_value

    def GetValue(self: 'NumberListResult') -> 'list[Number]':
        return self.value

    def SetResult(self: 'NumberListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'NumberListResult') -> 'bool':
        return self.result

class Number:
    def __init__(self: 'Number'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'Number',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Number') -> 'str':
        return self.length_string.GetString()

class DigitParser:
    def __init__(self: 'DigitParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'DigitParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'DigitParser',index: 'LengthString',result: 'DigitResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Digit' = Digit()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and character_range_parser_instance.ParseSingle(index,0x30,0x39):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'DigitParser',index: 'LengthString') -> 'bool':
        result: 'DigitResult' = DigitResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'DigitParser',index: 'LengthString',result: 'DigitResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'DigitParser',index: 'LengthString') -> 'bool':
        result: 'DigitResult' = DigitResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'DigitParser',index: 'LengthString',list_result: 'DigitListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Digit]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'DigitResult' = DigitResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'DigitParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'DigitListResult' = DigitListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class DigitResult:
    def __init__(self: 'DigitResult'):
        self.value: Digit = None
        self.result: bool = False

    def SetValue(self: 'DigitResult',new_value: 'Digit') -> 'None':
        self.value = new_value

    def GetValue(self: 'DigitResult') -> 'Digit':
        return self.value

    def SetResult(self: 'DigitResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'DigitResult') -> 'bool':
        return self.result

class DigitListResult:
    def __init__(self: 'DigitListResult'):
        self.value: list[Digit] = []
        self.result: bool = False

    def SetValue(self: 'DigitListResult',new_value: 'list[Digit]') -> 'None':
        self.value = new_value

    def GetValue(self: 'DigitListResult') -> 'list[Digit]':
        return self.value

    def SetResult(self: 'DigitListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'DigitListResult') -> 'bool':
        return self.result

class Digit:
    def __init__(self: 'Digit'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'Digit',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Digit') -> 'str':
        return self.length_string.GetString()

class PunctuationParser:
    def __init__(self: 'PunctuationParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'PunctuationParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'PunctuationParser',index: 'LengthString',result: 'PunctuationResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Punctuation' = Punctuation()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and string_parser_instance.ParseSingle(index,","):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and string_parser_instance.ParseSingle(index,"."):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and string_parser_instance.ParseSingle(index,"?"):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and string_parser_instance.ParseSingle(index,"!"):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'PunctuationParser',index: 'LengthString') -> 'bool':
        result: 'PunctuationResult' = PunctuationResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'PunctuationParser',index: 'LengthString',result: 'PunctuationResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'PunctuationParser',index: 'LengthString') -> 'bool':
        result: 'PunctuationResult' = PunctuationResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'PunctuationParser',index: 'LengthString',list_result: 'PunctuationListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Punctuation]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'PunctuationResult' = PunctuationResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'PunctuationParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'PunctuationListResult' = PunctuationListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class PunctuationResult:
    def __init__(self: 'PunctuationResult'):
        self.value: Punctuation = None
        self.result: bool = False

    def SetValue(self: 'PunctuationResult',new_value: 'Punctuation') -> 'None':
        self.value = new_value

    def GetValue(self: 'PunctuationResult') -> 'Punctuation':
        return self.value

    def SetResult(self: 'PunctuationResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'PunctuationResult') -> 'bool':
        return self.result

class PunctuationListResult:
    def __init__(self: 'PunctuationListResult'):
        self.value: list[Punctuation] = []
        self.result: bool = False

    def SetValue(self: 'PunctuationListResult',new_value: 'list[Punctuation]') -> 'None':
        self.value = new_value

    def GetValue(self: 'PunctuationListResult') -> 'list[Punctuation]':
        return self.value

    def SetResult(self: 'PunctuationListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'PunctuationListResult') -> 'bool':
        return self.result

class Punctuation:
    def __init__(self: 'Punctuation'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'Punctuation',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Punctuation') -> 'str':
        return self.length_string.GetString()

class CommentCharacterParser:
    def __init__(self: 'CommentCharacterParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'CommentCharacterParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'CommentCharacterParser',index: 'LengthString',result: 'CommentCharacterResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'CommentCharacter' = CommentCharacter()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and name_character_parser_instance.ParseSingle(index):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and punctuation_parser_instance.ParseSingle(index):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and string_parser_instance.ParseSingle(index," "):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and string_parser_instance.ParseSingle(index,"#"):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'CommentCharacterParser',index: 'LengthString') -> 'bool':
        result: 'CommentCharacterResult' = CommentCharacterResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'CommentCharacterParser',index: 'LengthString',result: 'CommentCharacterResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'CommentCharacterParser',index: 'LengthString') -> 'bool':
        result: 'CommentCharacterResult' = CommentCharacterResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'CommentCharacterParser',index: 'LengthString',list_result: 'CommentCharacterListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[CommentCharacter]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'CommentCharacterResult' = CommentCharacterResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'CommentCharacterParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'CommentCharacterListResult' = CommentCharacterListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class CommentCharacterResult:
    def __init__(self: 'CommentCharacterResult'):
        self.value: CommentCharacter = None
        self.result: bool = False

    def SetValue(self: 'CommentCharacterResult',new_value: 'CommentCharacter') -> 'None':
        self.value = new_value

    def GetValue(self: 'CommentCharacterResult') -> 'CommentCharacter':
        return self.value

    def SetResult(self: 'CommentCharacterResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'CommentCharacterResult') -> 'bool':
        return self.result

class CommentCharacterListResult:
    def __init__(self: 'CommentCharacterListResult'):
        self.value: list[CommentCharacter] = []
        self.result: bool = False

    def SetValue(self: 'CommentCharacterListResult',new_value: 'list[CommentCharacter]') -> 'None':
        self.value = new_value

    def GetValue(self: 'CommentCharacterListResult') -> 'list[CommentCharacter]':
        return self.value

    def SetResult(self: 'CommentCharacterListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'CommentCharacterListResult') -> 'bool':
        return self.result

class CommentCharacter:
    def __init__(self: 'CommentCharacter'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'CommentCharacter',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'CommentCharacter') -> 'str':
        return self.length_string.GetString()

class CommentParser:
    def __init__(self: 'CommentParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'CommentParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'CommentParser',index: 'LengthString',result: 'CommentResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Comment' = Comment()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and whitespace_parser_instance.ParseMany(index,0,-1) and string_parser_instance.ParseSingle(index,"#") and comment_character_parser_instance.ParseMany(index,0,-1) and eol_parser_instance.ParseSingle(index):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'CommentParser',index: 'LengthString') -> 'bool':
        result: 'CommentResult' = CommentResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'CommentParser',index: 'LengthString',result: 'CommentResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'CommentParser',index: 'LengthString') -> 'bool':
        result: 'CommentResult' = CommentResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'CommentParser',index: 'LengthString',list_result: 'CommentListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Comment]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'CommentResult' = CommentResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'CommentParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'CommentListResult' = CommentListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class CommentResult:
    def __init__(self: 'CommentResult'):
        self.value: Comment = None
        self.result: bool = False

    def SetValue(self: 'CommentResult',new_value: 'Comment') -> 'None':
        self.value = new_value

    def GetValue(self: 'CommentResult') -> 'Comment':
        return self.value

    def SetResult(self: 'CommentResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'CommentResult') -> 'bool':
        return self.result

class CommentListResult:
    def __init__(self: 'CommentListResult'):
        self.value: list[Comment] = []
        self.result: bool = False

    def SetValue(self: 'CommentListResult',new_value: 'list[Comment]') -> 'None':
        self.value = new_value

    def GetValue(self: 'CommentListResult') -> 'list[Comment]':
        return self.value

    def SetResult(self: 'CommentListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'CommentListResult') -> 'bool':
        return self.result

class Comment:
    def __init__(self: 'Comment'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'Comment',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Comment') -> 'str':
        return self.length_string.GetString()

class LiteralParser:
    def __init__(self: 'LiteralParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'LiteralParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'LiteralParser',index: 'LengthString',result: 'LiteralResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Literal' = Literal()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and literal_character_parser_instance.ParseMany(index,0,-1):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'LiteralParser',index: 'LengthString') -> 'bool':
        result: 'LiteralResult' = LiteralResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'LiteralParser',index: 'LengthString',result: 'LiteralResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'LiteralParser',index: 'LengthString') -> 'bool':
        result: 'LiteralResult' = LiteralResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'LiteralParser',index: 'LengthString',list_result: 'LiteralListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Literal]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'LiteralResult' = LiteralResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'LiteralParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'LiteralListResult' = LiteralListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class LiteralResult:
    def __init__(self: 'LiteralResult'):
        self.value: Literal = None
        self.result: bool = False

    def SetValue(self: 'LiteralResult',new_value: 'Literal') -> 'None':
        self.value = new_value

    def GetValue(self: 'LiteralResult') -> 'Literal':
        return self.value

    def SetResult(self: 'LiteralResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'LiteralResult') -> 'bool':
        return self.result

class LiteralListResult:
    def __init__(self: 'LiteralListResult'):
        self.value: list[Literal] = []
        self.result: bool = False

    def SetValue(self: 'LiteralListResult',new_value: 'list[Literal]') -> 'None':
        self.value = new_value

    def GetValue(self: 'LiteralListResult') -> 'list[Literal]':
        return self.value

    def SetResult(self: 'LiteralListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'LiteralListResult') -> 'bool':
        return self.result

class Literal:
    def __init__(self: 'Literal'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'Literal',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Literal') -> 'str':
        return self.length_string.GetString()

class LiteralCharacterParser:
    def __init__(self: 'LiteralCharacterParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'LiteralCharacterParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'LiteralCharacterParser',index: 'LengthString',result: 'LiteralCharacterResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'LiteralCharacter' = LiteralCharacter()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and character_range_parser_instance.ParseSingle(index,0x00,0x21):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and string_parser_instance.ParseSingle(index,"\\\""):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and character_range_parser_instance.ParseSingle(index,0x23,0x5B):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and string_parser_instance.ParseSingle(index,"\\\\"):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and character_range_parser_instance.ParseSingle(index,0x5D,0xFF):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'LiteralCharacterParser',index: 'LengthString') -> 'bool':
        result: 'LiteralCharacterResult' = LiteralCharacterResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'LiteralCharacterParser',index: 'LengthString',result: 'LiteralCharacterResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'LiteralCharacterParser',index: 'LengthString') -> 'bool':
        result: 'LiteralCharacterResult' = LiteralCharacterResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'LiteralCharacterParser',index: 'LengthString',list_result: 'LiteralCharacterListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[LiteralCharacter]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'LiteralCharacterResult' = LiteralCharacterResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'LiteralCharacterParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'LiteralCharacterListResult' = LiteralCharacterListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class LiteralCharacterResult:
    def __init__(self: 'LiteralCharacterResult'):
        self.value: LiteralCharacter = None
        self.result: bool = False

    def SetValue(self: 'LiteralCharacterResult',new_value: 'LiteralCharacter') -> 'None':
        self.value = new_value

    def GetValue(self: 'LiteralCharacterResult') -> 'LiteralCharacter':
        return self.value

    def SetResult(self: 'LiteralCharacterResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'LiteralCharacterResult') -> 'bool':
        return self.result

class LiteralCharacterListResult:
    def __init__(self: 'LiteralCharacterListResult'):
        self.value: list[LiteralCharacter] = []
        self.result: bool = False

    def SetValue(self: 'LiteralCharacterListResult',new_value: 'list[LiteralCharacter]') -> 'None':
        self.value = new_value

    def GetValue(self: 'LiteralCharacterListResult') -> 'list[LiteralCharacter]':
        return self.value

    def SetResult(self: 'LiteralCharacterListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'LiteralCharacterListResult') -> 'bool':
        return self.result

class LiteralCharacter:
    def __init__(self: 'LiteralCharacter'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'LiteralCharacter',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'LiteralCharacter') -> 'str':
        return self.length_string.GetString()

class HexDigitParser:
    def __init__(self: 'HexDigitParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'HexDigitParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'HexDigitParser',index: 'LengthString',result: 'HexDigitResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'HexDigit' = HexDigit()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and character_range_parser_instance.ParseSingle(index,0x30,0x39):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and character_range_parser_instance.ParseSingle(index,0x41,0x46):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'HexDigitParser',index: 'LengthString') -> 'bool':
        result: 'HexDigitResult' = HexDigitResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'HexDigitParser',index: 'LengthString',result: 'HexDigitResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'HexDigitParser',index: 'LengthString') -> 'bool':
        result: 'HexDigitResult' = HexDigitResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'HexDigitParser',index: 'LengthString',list_result: 'HexDigitListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[HexDigit]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'HexDigitResult' = HexDigitResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'HexDigitParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'HexDigitListResult' = HexDigitListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class HexDigitResult:
    def __init__(self: 'HexDigitResult'):
        self.value: HexDigit = None
        self.result: bool = False

    def SetValue(self: 'HexDigitResult',new_value: 'HexDigit') -> 'None':
        self.value = new_value

    def GetValue(self: 'HexDigitResult') -> 'HexDigit':
        return self.value

    def SetResult(self: 'HexDigitResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'HexDigitResult') -> 'bool':
        return self.result

class HexDigitListResult:
    def __init__(self: 'HexDigitListResult'):
        self.value: list[HexDigit] = []
        self.result: bool = False

    def SetValue(self: 'HexDigitListResult',new_value: 'list[HexDigit]') -> 'None':
        self.value = new_value

    def GetValue(self: 'HexDigitListResult') -> 'list[HexDigit]':
        return self.value

    def SetResult(self: 'HexDigitListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'HexDigitListResult') -> 'bool':
        return self.result

class HexDigit:
    def __init__(self: 'HexDigit'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'HexDigit',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'HexDigit') -> 'str':
        return self.length_string.GetString()

class WhitespaceParser:
    def __init__(self: 'WhitespaceParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'WhitespaceParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'WhitespaceParser',index: 'LengthString',result: 'WhitespaceResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Whitespace' = Whitespace()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and character_range_parser_instance.ParseSingle(index,0x00,0x09):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and character_range_parser_instance.ParseSingle(index,0x0B,0x0C):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and character_range_parser_instance.ParseSingle(index,0x0E,0x20):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'WhitespaceParser',index: 'LengthString') -> 'bool':
        result: 'WhitespaceResult' = WhitespaceResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'WhitespaceParser',index: 'LengthString',result: 'WhitespaceResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'WhitespaceParser',index: 'LengthString') -> 'bool':
        result: 'WhitespaceResult' = WhitespaceResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'WhitespaceParser',index: 'LengthString',list_result: 'WhitespaceListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Whitespace]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'WhitespaceResult' = WhitespaceResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'WhitespaceParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'WhitespaceListResult' = WhitespaceListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class WhitespaceResult:
    def __init__(self: 'WhitespaceResult'):
        self.value: Whitespace = None
        self.result: bool = False

    def SetValue(self: 'WhitespaceResult',new_value: 'Whitespace') -> 'None':
        self.value = new_value

    def GetValue(self: 'WhitespaceResult') -> 'Whitespace':
        return self.value

    def SetResult(self: 'WhitespaceResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'WhitespaceResult') -> 'bool':
        return self.result

class WhitespaceListResult:
    def __init__(self: 'WhitespaceListResult'):
        self.value: list[Whitespace] = []
        self.result: bool = False

    def SetValue(self: 'WhitespaceListResult',new_value: 'list[Whitespace]') -> 'None':
        self.value = new_value

    def GetValue(self: 'WhitespaceListResult') -> 'list[Whitespace]':
        return self.value

    def SetResult(self: 'WhitespaceListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'WhitespaceListResult') -> 'bool':
        return self.result

class Whitespace:
    def __init__(self: 'Whitespace'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'Whitespace',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Whitespace') -> 'str':
        return self.length_string.GetString()

class EolParser:
    def __init__(self: 'EolParser'):
        self.parser_network: ParserNetwork = None

    def SetParserNetwork(self: 'EolParser',input: 'ParserNetwork') -> 'None':
        self.parser_network = input

    def ParseSingleSave(self: 'EolParser',index: 'LengthString',result: 'EolResult') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        consumed_string: 'LengthString' = LengthString()
        consumed_string.SetData(index.GetData())
        consumed_string.SetStart(index.GetStart())
        consumed_string.SetLength(0)
        instance: 'Eol' = Eol()
        grammar_parser_instance: 'GrammarParser' = self.parser_network.GetGrammarParser()
        rule_parser_instance: 'RuleParser' = self.parser_network.GetRuleParser()
        expression_parser_instance: 'ExpressionParser' = self.parser_network.GetExpressionParser()
        token_parser_instance: 'TokenParser' = self.parser_network.GetTokenParser()
        simple_token_parser_instance: 'SimpleTokenParser' = self.parser_network.GetSimpleTokenParser()
        modifier_parser_instance: 'ModifierParser' = self.parser_network.GetModifierParser()
        cardinality_parser_instance: 'CardinalityParser' = self.parser_network.GetCardinalityParser()
        name_parser_instance: 'NameParser' = self.parser_network.GetNameParser()
        name_character_parser_instance: 'NameCharacterParser' = self.parser_network.GetNameCharacterParser()
        number_parser_instance: 'NumberParser' = self.parser_network.GetNumberParser()
        digit_parser_instance: 'DigitParser' = self.parser_network.GetDigitParser()
        punctuation_parser_instance: 'PunctuationParser' = self.parser_network.GetPunctuationParser()
        comment_character_parser_instance: 'CommentCharacterParser' = self.parser_network.GetCommentCharacterParser()
        comment_parser_instance: 'CommentParser' = self.parser_network.GetCommentParser()
        literal_parser_instance: 'LiteralParser' = self.parser_network.GetLiteralParser()
        literal_character_parser_instance: 'LiteralCharacterParser' = self.parser_network.GetLiteralCharacterParser()
        hex_digit_parser_instance: 'HexDigitParser' = self.parser_network.GetHexDigitParser()
        whitespace_parser_instance: 'WhitespaceParser' = self.parser_network.GetWhitespaceParser()
        eol_parser_instance: 'EolParser' = self.parser_network.GetEolParser()
        string_parser_instance: 'StringParser' = self.parser_network.GetStringParser()
        character_parser_instance: 'CharacterParser' = self.parser_network.GetCharacterParser()
        character_range_parser_instance: 'CharacterRangeParser' = self.parser_network.GetCharacterRangeParser()
        if True and character_parser_instance.ParseSingle(index,0x0A) and character_parser_instance.ParseSingle(index,0x0D):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and character_parser_instance.ParseSingle(index,0x0D) and character_parser_instance.ParseSingle(index,0x0A):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and character_parser_instance.ParseSingle(index,0x0A):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True and character_parser_instance.ParseSingle(index,0x0D):
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        if True:
            consumed_string.SetLength(index.GetStart()-index_start)
            instance.SetLengthString(consumed_string)
            result.SetValue(instance)
            result.SetResult(True)
            return result.GetResult()
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
        result.SetResult(False)
        return result.GetResult()

    def ParseSingle(self: 'EolParser',index: 'LengthString') -> 'bool':
        result: 'EolResult' = EolResult()
        return self.ParseSingleSave(index,result)

    def ParseOptionalSave(self: 'EolParser',index: 'LengthString',result: 'EolResult') -> 'bool':
        self.ParseSingleSave(index,result)
        result.SetResult(True)
        return True

    def ParseOptional(self: 'EolParser',index: 'LengthString') -> 'bool':
        result: 'EolResult' = EolResult()
        return self.ParseOptionalSave(index,result)

    def ParseManySave(self: 'EolParser',index: 'LengthString',list_result: 'EolListResult',minimum: 'int',maximum: 'int') -> 'bool':
        index_start: 'int' = index.GetStart()
        index_length: 'int' = index.GetLength()
        results: 'list[Eol]' = []
        count: 'int' = 0
        max_check: 'int' = maximum
        check_next: 'bool' = True
        if maximum<0:
            max_check = count+1
        while check_next and count<max_check:
            result: 'EolResult' = EolResult()
            self.ParseSingleSave(index,result)
            check_next = result.GetResult()
            if result.GetResult():
                count = count+1
                Append(results,result.GetValue())
            if maximum<0:
                max_check = count+1
        if count>=minimum and count<=max_check:
            list_result.SetValue(results)
            list_result.SetResult(True)
        else:
            index.SetStart(index_start)
            index.SetLength(index_length)
            list_result.SetResult(False)
        return list_result.GetResult()

    def ParseMany(self: 'EolParser',index: 'LengthString',minimum: 'int',maximum: 'int') -> 'bool':
        result: 'EolListResult' = EolListResult()
        return self.ParseManySave(index,result,minimum,maximum)

class EolResult:
    def __init__(self: 'EolResult'):
        self.value: Eol = None
        self.result: bool = False

    def SetValue(self: 'EolResult',new_value: 'Eol') -> 'None':
        self.value = new_value

    def GetValue(self: 'EolResult') -> 'Eol':
        return self.value

    def SetResult(self: 'EolResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'EolResult') -> 'bool':
        return self.result

class EolListResult:
    def __init__(self: 'EolListResult'):
        self.value: list[Eol] = []
        self.result: bool = False

    def SetValue(self: 'EolListResult',new_value: 'list[Eol]') -> 'None':
        self.value = new_value

    def GetValue(self: 'EolListResult') -> 'list[Eol]':
        return self.value

    def SetResult(self: 'EolListResult',new_result: 'bool') -> 'None':
        self.result = new_result

    def GetResult(self: 'EolListResult') -> 'bool':
        return self.result

class Eol:
    def __init__(self: 'Eol'):
        self.length_string: LengthString = None

    def SetLengthString(self: 'Eol',new_value: 'LengthString') -> 'None':
        self.length_string = LengthString()
        self.length_string.SetData(new_value.GetData())
        self.length_string.SetStart(new_value.GetStart())
        self.length_string.SetLength(new_value.GetLength())

    def UnParse(self: 'Eol') -> 'str':
        return self.length_string.GetString()

