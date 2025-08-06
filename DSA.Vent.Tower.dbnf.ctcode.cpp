#include "DSA.Vent.Tower.dbnf.ctcode.hpp"


namespace dsa
{
namespace vent
{
namespace tower
{
namespace dbnf
{
namespace ctcode
{
    bool StringParser::ParseSingleSave(OmniPointer<LengthString> index, std::string value, OmniPointer<StringResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<String> instance = std::shared_ptr<String>(new String());
        int value_length = Length(value);
        if (value_length > index->GetLength())
        {
            result->SetResult(false);
            return false;
        }

        int offset_index = 0;
        while (offset_index < value_length)
        {
            if (At(index->GetData(), index->GetStart() + offset_index) != At(value, offset_index))
            {
                result->SetResult(false);
                return false;
            }

            offset_index = offset_index + 1;
        }

        index->SetStart(index->GetStart() + value_length);
        index->SetLength(index->GetLength() - value_length);
        consumed_string->SetLength(index->GetStart() - index_start);
        instance->SetLengthString(consumed_string);
        result->SetValue(instance);
        result->SetResult(true);
        return true;
    }

    bool StringParser::ParseSingle(OmniPointer<LengthString> index, std::string value)
    {
        OmniPointer<StringResult> result = std::shared_ptr<StringResult>(new StringResult());
        return ParseSingleSave(index, value, result);
    }

    void StringResult::SetValue(OmniPointer<String> new_value)
    {
        value = new_value;
    }

    OmniPointer<String> StringResult::GetValue()
    {
        return value;
    }

    void StringResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool StringResult::GetResult()
    {
        return result;
    }

    void StringListResult::SetValue(std::vector<OmniPointer<String>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<String>> StringListResult::GetValue()
    {
        return value;
    }

    void StringListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool StringListResult::GetResult()
    {
        return result;
    }

    void String::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string String::UnParse()
    {
        return length_string->GetString();
    }

    bool CharacterParser::ParseSingle(OmniPointer<LengthString> index, int value)
    {
        if (0 == index->GetLength())
        {
            return false;
        }

        int current_character = IntAt(index->GetData(), index->GetStart());
        if (current_character == value)
        {
            index->SetStart(index->GetStart() + 1);
            index->SetLength(index->GetLength() - 1);
            return true;
        }

        return false;
    }

    void CharacterResult::SetValue(OmniPointer<Character> new_value)
    {
        value = new_value;
    }

    OmniPointer<Character> CharacterResult::GetValue()
    {
        return value;
    }

    void CharacterResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool CharacterResult::GetResult()
    {
        return result;
    }

    void CharacterListResult::SetValue(std::vector<OmniPointer<Character>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Character>> CharacterListResult::GetValue()
    {
        return value;
    }

    void CharacterListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool CharacterListResult::GetResult()
    {
        return result;
    }

    void Character::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Character::UnParse()
    {
        return length_string->GetString();
    }

    OmniPointer<GrammarParser> ParserNetwork::GetGrammarParser()
    {
        return grammar_parser_field;
    }

    OmniPointer<RuleParser> ParserNetwork::GetRuleParser()
    {
        return rule_parser_field;
    }

    OmniPointer<ExpressionParser> ParserNetwork::GetExpressionParser()
    {
        return expression_parser_field;
    }

    OmniPointer<TokenParser> ParserNetwork::GetTokenParser()
    {
        return token_parser_field;
    }

    OmniPointer<SimpleTokenParser> ParserNetwork::GetSimpleTokenParser()
    {
        return simple_token_parser_field;
    }

    OmniPointer<ModifierParser> ParserNetwork::GetModifierParser()
    {
        return modifier_parser_field;
    }

    OmniPointer<CardinalityParser> ParserNetwork::GetCardinalityParser()
    {
        return cardinality_parser_field;
    }

    OmniPointer<NameParser> ParserNetwork::GetNameParser()
    {
        return name_parser_field;
    }

    OmniPointer<NameCharacterParser> ParserNetwork::GetNameCharacterParser()
    {
        return name_character_parser_field;
    }

    OmniPointer<NumberParser> ParserNetwork::GetNumberParser()
    {
        return number_parser_field;
    }

    OmniPointer<DigitParser> ParserNetwork::GetDigitParser()
    {
        return digit_parser_field;
    }

    OmniPointer<PunctuationParser> ParserNetwork::GetPunctuationParser()
    {
        return punctuation_parser_field;
    }

    OmniPointer<CommentCharacterParser> ParserNetwork::GetCommentCharacterParser()
    {
        return comment_character_parser_field;
    }

    OmniPointer<CommentParser> ParserNetwork::GetCommentParser()
    {
        return comment_parser_field;
    }

    OmniPointer<LiteralParser> ParserNetwork::GetLiteralParser()
    {
        return literal_parser_field;
    }

    OmniPointer<LiteralCharacterParser> ParserNetwork::GetLiteralCharacterParser()
    {
        return literal_character_parser_field;
    }

    OmniPointer<HexDigitParser> ParserNetwork::GetHexDigitParser()
    {
        return hex_digit_parser_field;
    }

    OmniPointer<WhitespaceParser> ParserNetwork::GetWhitespaceParser()
    {
        return whitespace_parser_field;
    }

    OmniPointer<EolParser> ParserNetwork::GetEolParser()
    {
        return eol_parser_field;
    }

    OmniPointer<StringParser> ParserNetwork::GetStringParser()
    {
        return string_parser_field;
    }

    OmniPointer<CharacterParser> ParserNetwork::GetCharacterParser()
    {
        return character_parser_field;
    }

    void ParserNetwork::Initialize()
    {
        grammar_parser_field = std::shared_ptr<GrammarParser>(new GrammarParser());
        grammar_parser_field->SetParserNetwork(this);
        rule_parser_field = std::shared_ptr<RuleParser>(new RuleParser());
        rule_parser_field->SetParserNetwork(this);
        expression_parser_field = std::shared_ptr<ExpressionParser>(new ExpressionParser());
        expression_parser_field->SetParserNetwork(this);
        token_parser_field = std::shared_ptr<TokenParser>(new TokenParser());
        token_parser_field->SetParserNetwork(this);
        simple_token_parser_field = std::shared_ptr<SimpleTokenParser>(new SimpleTokenParser());
        simple_token_parser_field->SetParserNetwork(this);
        modifier_parser_field = std::shared_ptr<ModifierParser>(new ModifierParser());
        modifier_parser_field->SetParserNetwork(this);
        cardinality_parser_field = std::shared_ptr<CardinalityParser>(new CardinalityParser());
        cardinality_parser_field->SetParserNetwork(this);
        name_parser_field = std::shared_ptr<NameParser>(new NameParser());
        name_parser_field->SetParserNetwork(this);
        name_character_parser_field = std::shared_ptr<NameCharacterParser>(new NameCharacterParser());
        name_character_parser_field->SetParserNetwork(this);
        number_parser_field = std::shared_ptr<NumberParser>(new NumberParser());
        number_parser_field->SetParserNetwork(this);
        digit_parser_field = std::shared_ptr<DigitParser>(new DigitParser());
        digit_parser_field->SetParserNetwork(this);
        punctuation_parser_field = std::shared_ptr<PunctuationParser>(new PunctuationParser());
        punctuation_parser_field->SetParserNetwork(this);
        comment_character_parser_field = std::shared_ptr<CommentCharacterParser>(new CommentCharacterParser());
        comment_character_parser_field->SetParserNetwork(this);
        comment_parser_field = std::shared_ptr<CommentParser>(new CommentParser());
        comment_parser_field->SetParserNetwork(this);
        literal_parser_field = std::shared_ptr<LiteralParser>(new LiteralParser());
        literal_parser_field->SetParserNetwork(this);
        literal_character_parser_field = std::shared_ptr<LiteralCharacterParser>(new LiteralCharacterParser());
        literal_character_parser_field->SetParserNetwork(this);
        hex_digit_parser_field = std::shared_ptr<HexDigitParser>(new HexDigitParser());
        hex_digit_parser_field->SetParserNetwork(this);
        whitespace_parser_field = std::shared_ptr<WhitespaceParser>(new WhitespaceParser());
        whitespace_parser_field->SetParserNetwork(this);
        eol_parser_field = std::shared_ptr<EolParser>(new EolParser());
        eol_parser_field->SetParserNetwork(this);
        string_parser_field = std::shared_ptr<StringParser>(new StringParser());
        character_parser_field = std::shared_ptr<CharacterParser>(new CharacterParser());
    }

    void DBNFOmniType::SetGrammar(OmniPointer<Grammar> input_value)
    {
        grammar_field = input_value;
    }

    OmniPointer<Grammar> DBNFOmniType::GetGrammar()
    {
        return grammar_field;
    }

    void DBNFOmniType::SetRule(OmniPointer<Rule> input_value)
    {
        rule_field = input_value;
    }

    OmniPointer<Rule> DBNFOmniType::GetRule()
    {
        return rule_field;
    }

    void DBNFOmniType::SetExpression(OmniPointer<Expression> input_value)
    {
        expression_field = input_value;
    }

    OmniPointer<Expression> DBNFOmniType::GetExpression()
    {
        return expression_field;
    }

    void DBNFOmniType::SetToken(OmniPointer<Token> input_value)
    {
        token_field = input_value;
    }

    OmniPointer<Token> DBNFOmniType::GetToken()
    {
        return token_field;
    }

    void DBNFOmniType::SetSimpleToken(OmniPointer<SimpleToken> input_value)
    {
        simple_token_field = input_value;
    }

    OmniPointer<SimpleToken> DBNFOmniType::GetSimpleToken()
    {
        return simple_token_field;
    }

    void DBNFOmniType::SetModifier(OmniPointer<Modifier> input_value)
    {
        modifier_field = input_value;
    }

    OmniPointer<Modifier> DBNFOmniType::GetModifier()
    {
        return modifier_field;
    }

    void DBNFOmniType::SetCardinality(OmniPointer<Cardinality> input_value)
    {
        cardinality_field = input_value;
    }

    OmniPointer<Cardinality> DBNFOmniType::GetCardinality()
    {
        return cardinality_field;
    }

    void DBNFOmniType::SetName(OmniPointer<Name> input_value)
    {
        name_field = input_value;
    }

    OmniPointer<Name> DBNFOmniType::GetName()
    {
        return name_field;
    }

    void DBNFOmniType::SetNameCharacter(OmniPointer<NameCharacter> input_value)
    {
        name_character_field = input_value;
    }

    OmniPointer<NameCharacter> DBNFOmniType::GetNameCharacter()
    {
        return name_character_field;
    }

    void DBNFOmniType::SetNumber(OmniPointer<Number> input_value)
    {
        number_field = input_value;
    }

    OmniPointer<Number> DBNFOmniType::GetNumber()
    {
        return number_field;
    }

    void DBNFOmniType::SetDigit(OmniPointer<Digit> input_value)
    {
        digit_field = input_value;
    }

    OmniPointer<Digit> DBNFOmniType::GetDigit()
    {
        return digit_field;
    }

    void DBNFOmniType::SetPunctuation(OmniPointer<Punctuation> input_value)
    {
        punctuation_field = input_value;
    }

    OmniPointer<Punctuation> DBNFOmniType::GetPunctuation()
    {
        return punctuation_field;
    }

    void DBNFOmniType::SetCommentCharacter(OmniPointer<CommentCharacter> input_value)
    {
        comment_character_field = input_value;
    }

    OmniPointer<CommentCharacter> DBNFOmniType::GetCommentCharacter()
    {
        return comment_character_field;
    }

    void DBNFOmniType::SetComment(OmniPointer<Comment> input_value)
    {
        comment_field = input_value;
    }

    OmniPointer<Comment> DBNFOmniType::GetComment()
    {
        return comment_field;
    }

    void DBNFOmniType::SetLiteral(OmniPointer<Literal> input_value)
    {
        literal_field = input_value;
    }

    OmniPointer<Literal> DBNFOmniType::GetLiteral()
    {
        return literal_field;
    }

    void DBNFOmniType::SetLiteralCharacter(OmniPointer<LiteralCharacter> input_value)
    {
        literal_character_field = input_value;
    }

    OmniPointer<LiteralCharacter> DBNFOmniType::GetLiteralCharacter()
    {
        return literal_character_field;
    }

    void DBNFOmniType::SetHexDigit(OmniPointer<HexDigit> input_value)
    {
        hex_digit_field = input_value;
    }

    OmniPointer<HexDigit> DBNFOmniType::GetHexDigit()
    {
        return hex_digit_field;
    }

    void DBNFOmniType::SetWhitespace(OmniPointer<Whitespace> input_value)
    {
        whitespace_field = input_value;
    }

    OmniPointer<Whitespace> DBNFOmniType::GetWhitespace()
    {
        return whitespace_field;
    }

    void DBNFOmniType::SetEol(OmniPointer<Eol> input_value)
    {
        eol_field = input_value;
    }

    OmniPointer<Eol> DBNFOmniType::GetEol()
    {
        return eol_field;
    }

    void DBNFOmniTypeResult::SetValue(OmniPointer<DBNFOmniType> new_value)
    {
        value = new_value;
    }

    OmniPointer<DBNFOmniType> DBNFOmniTypeResult::GetValue()
    {
        return value;
    }

    void DBNFOmniTypeResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool DBNFOmniTypeResult::GetResult()
    {
        return result;
    }

    void DBNFOmniTypeResult::SetGrammar(OmniPointer<Grammar> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetGrammar(input_value);
    }

    void DBNFOmniTypeResult::SetRule(OmniPointer<Rule> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetRule(input_value);
    }

    void DBNFOmniTypeResult::SetExpression(OmniPointer<Expression> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetExpression(input_value);
    }

    void DBNFOmniTypeResult::SetToken(OmniPointer<Token> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetToken(input_value);
    }

    void DBNFOmniTypeResult::SetSimpleToken(OmniPointer<SimpleToken> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetSimpleToken(input_value);
    }

    void DBNFOmniTypeResult::SetModifier(OmniPointer<Modifier> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetModifier(input_value);
    }

    void DBNFOmniTypeResult::SetCardinality(OmniPointer<Cardinality> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetCardinality(input_value);
    }

    void DBNFOmniTypeResult::SetName(OmniPointer<Name> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetName(input_value);
    }

    void DBNFOmniTypeResult::SetNameCharacter(OmniPointer<NameCharacter> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetNameCharacter(input_value);
    }

    void DBNFOmniTypeResult::SetNumber(OmniPointer<Number> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetNumber(input_value);
    }

    void DBNFOmniTypeResult::SetDigit(OmniPointer<Digit> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetDigit(input_value);
    }

    void DBNFOmniTypeResult::SetPunctuation(OmniPointer<Punctuation> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetPunctuation(input_value);
    }

    void DBNFOmniTypeResult::SetCommentCharacter(OmniPointer<CommentCharacter> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetCommentCharacter(input_value);
    }

    void DBNFOmniTypeResult::SetComment(OmniPointer<Comment> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetComment(input_value);
    }

    void DBNFOmniTypeResult::SetLiteral(OmniPointer<Literal> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetLiteral(input_value);
    }

    void DBNFOmniTypeResult::SetLiteralCharacter(OmniPointer<LiteralCharacter> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetLiteralCharacter(input_value);
    }

    void DBNFOmniTypeResult::SetHexDigit(OmniPointer<HexDigit> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetHexDigit(input_value);
    }

    void DBNFOmniTypeResult::SetWhitespace(OmniPointer<Whitespace> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetWhitespace(input_value);
    }

    void DBNFOmniTypeResult::SetEol(OmniPointer<Eol> input_value)
    {
        value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        value->SetEol(input_value);
    }

    void DBNFOmniTypeListResult::SetValue(std::vector<OmniPointer<DBNFOmniType>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<DBNFOmniType>> DBNFOmniTypeListResult::GetValue()
    {
        return value;
    }

    void DBNFOmniTypeListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool DBNFOmniTypeListResult::GetResult()
    {
        return result;
    }

    void DBNFOmniTypeListResult::SetGrammar(std::vector<OmniPointer<Grammar>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetGrammar(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetRule(std::vector<OmniPointer<Rule>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetRule(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetExpression(std::vector<OmniPointer<Expression>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetExpression(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetToken(std::vector<OmniPointer<Token>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetToken(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetSimpleToken(std::vector<OmniPointer<SimpleToken>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetSimpleToken(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetModifier(std::vector<OmniPointer<Modifier>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetModifier(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetCardinality(std::vector<OmniPointer<Cardinality>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetCardinality(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetName(std::vector<OmniPointer<Name>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetName(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetNameCharacter(std::vector<OmniPointer<NameCharacter>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetNameCharacter(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetNumber(std::vector<OmniPointer<Number>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetNumber(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetDigit(std::vector<OmniPointer<Digit>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetDigit(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetPunctuation(std::vector<OmniPointer<Punctuation>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetPunctuation(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetCommentCharacter(std::vector<OmniPointer<CommentCharacter>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetCommentCharacter(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetComment(std::vector<OmniPointer<Comment>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetComment(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetLiteral(std::vector<OmniPointer<Literal>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetLiteral(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetLiteralCharacter(std::vector<OmniPointer<LiteralCharacter>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetLiteralCharacter(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetHexDigit(std::vector<OmniPointer<HexDigit>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetHexDigit(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetWhitespace(std::vector<OmniPointer<Whitespace>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetWhitespace(Element(input_value, index));
            index = index + 1;
        }
    }

    void DBNFOmniTypeListResult::SetEol(std::vector<OmniPointer<Eol>> input_value)
    {
        int index = 0;
        while (index < Size(input_value))
        {
            OmniPointer<DBNFOmniType> value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
            value->SetEol(Element(input_value, index));
            index = index + 1;
        }
    }

    void LengthString::SetData(std::string new_data)
    {
        data = new_data;
    }

    std::string LengthString::GetData()
    {
        return data;
    }

    void LengthString::SetStart(int new_start)
    {
        start = new_start;
    }

    int LengthString::GetStart()
    {
        return start;
    }

    void LengthString::SetLength(int new_length)
    {
        length = new_length;
    }

    int LengthString::GetLength()
    {
        return length;
    }

    std::string LengthString::GetString()
    {
        std::string result;
        int index = start;
        int end = start + length;
        while (index < end)
        {
            result = Concat(result, At(data, index));
            index = index + 1;
        }

        return result;
    }

    void GrammarParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool GrammarParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<GrammarResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Grammar> instance = std::shared_ptr<Grammar>(new Grammar());
        OmniPointer<RuleListResult> rules_field = std::shared_ptr<RuleListResult>(new RuleListResult());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && rule_parser_instance->ParseManySave(index, rules_field, 0, -1))
        {
            instance->SetRules(rules_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            rules_field = std::shared_ptr<RuleListResult>(new RuleListResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool GrammarParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<GrammarResult> result = std::shared_ptr<GrammarResult>(new GrammarResult());
        return ParseSingleSave(index, result);
    }

    bool GrammarParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<GrammarResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool GrammarParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<GrammarResult> result = std::shared_ptr<GrammarResult>(new GrammarResult());
        return ParseOptionalSave(index, result);
    }

    bool GrammarParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<GrammarListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Grammar>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<GrammarResult> result = std::shared_ptr<GrammarResult>(new GrammarResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool GrammarParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<GrammarListResult> result = std::shared_ptr<GrammarListResult>(new GrammarListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void GrammarResult::SetValue(OmniPointer<Grammar> new_value)
    {
        value = new_value;
    }

    OmniPointer<Grammar> GrammarResult::GetValue()
    {
        return value;
    }

    void GrammarResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool GrammarResult::GetResult()
    {
        return result;
    }

    void GrammarListResult::SetValue(std::vector<OmniPointer<Grammar>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Grammar>> GrammarListResult::GetValue()
    {
        return value;
    }

    void GrammarListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool GrammarListResult::GetResult()
    {
        return result;
    }

    void Grammar::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Grammar::UnParse()
    {
        return length_string->GetString();
    }

    void Grammar::SetRules(std::vector<OmniPointer<Rule>> input_value)
    {
        rules_field = input_value;
    }

    std::vector<OmniPointer<Rule>> Grammar::GetRules()
    {
        return rules_field;
    }

    void RuleParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool RuleParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<RuleResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Rule> instance = std::shared_ptr<Rule>(new Rule());
        OmniPointer<ExpressionListResult> expressions_field = std::shared_ptr<ExpressionListResult>(new ExpressionListResult());
        OmniPointer<NameResult> name_field = std::shared_ptr<NameResult>(new NameResult());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("<")) && name_parser_instance->ParseSingleSave(index, name_field) && string_parser_instance->ParseSingle(index, std::string(">")) && expression_parser_instance->ParseManySave(index, expressions_field, 0, -1))
        {
            instance->SetExpressions(expressions_field->GetValue());
            instance->SetName(name_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            expressions_field = std::shared_ptr<ExpressionListResult>(new ExpressionListResult());
            name_field = std::shared_ptr<NameResult>(new NameResult());
        }

        if (true && comment_parser_instance->ParseSingle(index))
        {
            instance->SetExpressions(expressions_field->GetValue());
            instance->SetName(name_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            expressions_field = std::shared_ptr<ExpressionListResult>(new ExpressionListResult());
            name_field = std::shared_ptr<NameResult>(new NameResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool RuleParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<RuleResult> result = std::shared_ptr<RuleResult>(new RuleResult());
        return ParseSingleSave(index, result);
    }

    bool RuleParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<RuleResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool RuleParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<RuleResult> result = std::shared_ptr<RuleResult>(new RuleResult());
        return ParseOptionalSave(index, result);
    }

    bool RuleParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<RuleListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Rule>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<RuleResult> result = std::shared_ptr<RuleResult>(new RuleResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool RuleParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<RuleListResult> result = std::shared_ptr<RuleListResult>(new RuleListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void RuleResult::SetValue(OmniPointer<Rule> new_value)
    {
        value = new_value;
    }

    OmniPointer<Rule> RuleResult::GetValue()
    {
        return value;
    }

    void RuleResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool RuleResult::GetResult()
    {
        return result;
    }

    void RuleListResult::SetValue(std::vector<OmniPointer<Rule>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Rule>> RuleListResult::GetValue()
    {
        return value;
    }

    void RuleListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool RuleListResult::GetResult()
    {
        return result;
    }

    void Rule::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Rule::UnParse()
    {
        return length_string->GetString();
    }

    void Rule::SetExpressions(std::vector<OmniPointer<Expression>> input_value)
    {
        expressions_field = input_value;
    }

    std::vector<OmniPointer<Expression>> Rule::GetExpressions()
    {
        return expressions_field;
    }

    void Rule::SetName(OmniPointer<Name> input_value)
    {
        name_field = input_value;
    }

    OmniPointer<Name> Rule::GetName()
    {
        return name_field;
    }

    void ExpressionParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool ExpressionParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<ExpressionResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Expression> instance = std::shared_ptr<Expression>(new Expression());
        OmniPointer<TokenListResult> token_sequence_field = std::shared_ptr<TokenListResult>(new TokenListResult());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("::=")) && token_parser_instance->ParseManySave(index, token_sequence_field, 0, -1) && eol_parser_instance->ParseSingle(index))
        {
            instance->SetTokenSequence(token_sequence_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            token_sequence_field = std::shared_ptr<TokenListResult>(new TokenListResult());
        }

        if (true && comment_parser_instance->ParseSingle(index))
        {
            instance->SetTokenSequence(token_sequence_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            token_sequence_field = std::shared_ptr<TokenListResult>(new TokenListResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool ExpressionParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<ExpressionResult> result = std::shared_ptr<ExpressionResult>(new ExpressionResult());
        return ParseSingleSave(index, result);
    }

    bool ExpressionParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<ExpressionResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool ExpressionParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<ExpressionResult> result = std::shared_ptr<ExpressionResult>(new ExpressionResult());
        return ParseOptionalSave(index, result);
    }

    bool ExpressionParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<ExpressionListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Expression>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<ExpressionResult> result = std::shared_ptr<ExpressionResult>(new ExpressionResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool ExpressionParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<ExpressionListResult> result = std::shared_ptr<ExpressionListResult>(new ExpressionListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void ExpressionResult::SetValue(OmniPointer<Expression> new_value)
    {
        value = new_value;
    }

    OmniPointer<Expression> ExpressionResult::GetValue()
    {
        return value;
    }

    void ExpressionResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool ExpressionResult::GetResult()
    {
        return result;
    }

    void ExpressionListResult::SetValue(std::vector<OmniPointer<Expression>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Expression>> ExpressionListResult::GetValue()
    {
        return value;
    }

    void ExpressionListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool ExpressionListResult::GetResult()
    {
        return result;
    }

    void Expression::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Expression::UnParse()
    {
        return length_string->GetString();
    }

    void Expression::SetTokenSequence(std::vector<OmniPointer<Token>> input_value)
    {
        token_sequence_field = input_value;
    }

    std::vector<OmniPointer<Token>> Expression::GetTokenSequence()
    {
        return token_sequence_field;
    }

    void TokenParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool TokenParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<TokenResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Token> instance = std::shared_ptr<Token>(new Token());
        OmniPointer<ModifierResult> modifier_field = std::shared_ptr<ModifierResult>(new ModifierResult());
        OmniPointer<NameResult> name_field = std::shared_ptr<NameResult>(new NameResult());
        OmniPointer<SimpleTokenResult> value_field = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("attribute")) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("(")) && whitespace_parser_instance->ParseMany(index, 0, -1) && name_parser_instance->ParseSingleSave(index, name_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && simple_token_parser_instance->ParseSingleSave(index, value_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && modifier_parser_instance->ParseSingleSave(index, modifier_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string(")")) && whitespace_parser_instance->ParseMany(index, 0, -1))
        {
            instance->SetModifier(modifier_field->GetValue());
            instance->SetName(name_field->GetValue());
            instance->SetValue(value_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            modifier_field = std::shared_ptr<ModifierResult>(new ModifierResult());
            name_field = std::shared_ptr<NameResult>(new NameResult());
            value_field = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
        }

        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("attribute")) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("(")) && whitespace_parser_instance->ParseMany(index, 0, -1) && name_parser_instance->ParseSingleSave(index, name_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && simple_token_parser_instance->ParseSingleSave(index, value_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string(")")) && whitespace_parser_instance->ParseMany(index, 0, -1))
        {
            instance->SetModifier(modifier_field->GetValue());
            instance->SetName(name_field->GetValue());
            instance->SetValue(value_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            modifier_field = std::shared_ptr<ModifierResult>(new ModifierResult());
            name_field = std::shared_ptr<NameResult>(new NameResult());
            value_field = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
        }

        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && simple_token_parser_instance->ParseSingleSave(index, value_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && modifier_parser_instance->ParseSingleSave(index, modifier_field) && whitespace_parser_instance->ParseMany(index, 0, -1))
        {
            instance->SetModifier(modifier_field->GetValue());
            instance->SetName(name_field->GetValue());
            instance->SetValue(value_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            modifier_field = std::shared_ptr<ModifierResult>(new ModifierResult());
            name_field = std::shared_ptr<NameResult>(new NameResult());
            value_field = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
        }

        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && simple_token_parser_instance->ParseSingleSave(index, value_field) && whitespace_parser_instance->ParseMany(index, 0, -1))
        {
            instance->SetModifier(modifier_field->GetValue());
            instance->SetName(name_field->GetValue());
            instance->SetValue(value_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            modifier_field = std::shared_ptr<ModifierResult>(new ModifierResult());
            name_field = std::shared_ptr<NameResult>(new NameResult());
            value_field = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool TokenParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<TokenResult> result = std::shared_ptr<TokenResult>(new TokenResult());
        return ParseSingleSave(index, result);
    }

    bool TokenParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<TokenResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool TokenParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<TokenResult> result = std::shared_ptr<TokenResult>(new TokenResult());
        return ParseOptionalSave(index, result);
    }

    bool TokenParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<TokenListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Token>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<TokenResult> result = std::shared_ptr<TokenResult>(new TokenResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool TokenParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<TokenListResult> result = std::shared_ptr<TokenListResult>(new TokenListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void TokenResult::SetValue(OmniPointer<Token> new_value)
    {
        value = new_value;
    }

    OmniPointer<Token> TokenResult::GetValue()
    {
        return value;
    }

    void TokenResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool TokenResult::GetResult()
    {
        return result;
    }

    void TokenListResult::SetValue(std::vector<OmniPointer<Token>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Token>> TokenListResult::GetValue()
    {
        return value;
    }

    void TokenListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool TokenListResult::GetResult()
    {
        return result;
    }

    void Token::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Token::UnParse()
    {
        return length_string->GetString();
    }

    void Token::SetModifier(OmniPointer<Modifier> input_value)
    {
        modifier_field = input_value;
    }

    OmniPointer<Modifier> Token::GetModifier()
    {
        return modifier_field;
    }

    void Token::SetName(OmniPointer<Name> input_value)
    {
        name_field = input_value;
    }

    OmniPointer<Name> Token::GetName()
    {
        return name_field;
    }

    void Token::SetValue(OmniPointer<SimpleToken> input_value)
    {
        value_field = input_value;
    }

    OmniPointer<SimpleToken> Token::GetValue()
    {
        return value_field;
    }

    void SimpleTokenParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool SimpleTokenParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<SimpleTokenResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<SimpleToken> instance = std::shared_ptr<SimpleToken>(new SimpleToken());
        OmniPointer<HexDigitResult> high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        OmniPointer<LiteralResult> literal_field = std::shared_ptr<LiteralResult>(new LiteralResult());
        OmniPointer<HexDigitResult> low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        OmniPointer<NameResult> token_field = std::shared_ptr<NameResult>(new NameResult());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && string_parser_instance->ParseSingle(index, std::string("<")) && name_parser_instance->ParseSingleSave(index, token_field) && string_parser_instance->ParseSingle(index, std::string(">")))
        {
            instance->SetHigh(high_field->GetValue());
            instance->SetLiteral(literal_field->GetValue());
            instance->SetLow(low_field->GetValue());
            instance->SetToken(token_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            literal_field = std::shared_ptr<LiteralResult>(new LiteralResult());
            low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            token_field = std::shared_ptr<NameResult>(new NameResult());
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("0x")) && hex_digit_parser_instance->ParseSingleSave(index, high_field) && hex_digit_parser_instance->ParseSingleSave(index, low_field))
        {
            instance->SetHigh(high_field->GetValue());
            instance->SetLiteral(literal_field->GetValue());
            instance->SetLow(low_field->GetValue());
            instance->SetToken(token_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            literal_field = std::shared_ptr<LiteralResult>(new LiteralResult());
            low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            token_field = std::shared_ptr<NameResult>(new NameResult());
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("\"")) && literal_parser_instance->ParseSingleSave(index, literal_field) && string_parser_instance->ParseSingle(index, std::string("\"")))
        {
            instance->SetHigh(high_field->GetValue());
            instance->SetLiteral(literal_field->GetValue());
            instance->SetLow(low_field->GetValue());
            instance->SetToken(token_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            literal_field = std::shared_ptr<LiteralResult>(new LiteralResult());
            low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            token_field = std::shared_ptr<NameResult>(new NameResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool SimpleTokenParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<SimpleTokenResult> result = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
        return ParseSingleSave(index, result);
    }

    bool SimpleTokenParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<SimpleTokenResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool SimpleTokenParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<SimpleTokenResult> result = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
        return ParseOptionalSave(index, result);
    }

    bool SimpleTokenParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<SimpleTokenListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<SimpleToken>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<SimpleTokenResult> result = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool SimpleTokenParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<SimpleTokenListResult> result = std::shared_ptr<SimpleTokenListResult>(new SimpleTokenListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void SimpleTokenResult::SetValue(OmniPointer<SimpleToken> new_value)
    {
        value = new_value;
    }

    OmniPointer<SimpleToken> SimpleTokenResult::GetValue()
    {
        return value;
    }

    void SimpleTokenResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool SimpleTokenResult::GetResult()
    {
        return result;
    }

    void SimpleTokenListResult::SetValue(std::vector<OmniPointer<SimpleToken>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<SimpleToken>> SimpleTokenListResult::GetValue()
    {
        return value;
    }

    void SimpleTokenListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool SimpleTokenListResult::GetResult()
    {
        return result;
    }

    void SimpleToken::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string SimpleToken::UnParse()
    {
        return length_string->GetString();
    }

    void SimpleToken::SetHigh(OmniPointer<HexDigit> input_value)
    {
        high_field = input_value;
    }

    OmniPointer<HexDigit> SimpleToken::GetHigh()
    {
        return high_field;
    }

    void SimpleToken::SetLiteral(OmniPointer<Literal> input_value)
    {
        literal_field = input_value;
    }

    OmniPointer<Literal> SimpleToken::GetLiteral()
    {
        return literal_field;
    }

    void SimpleToken::SetLow(OmniPointer<HexDigit> input_value)
    {
        low_field = input_value;
    }

    OmniPointer<HexDigit> SimpleToken::GetLow()
    {
        return low_field;
    }

    void SimpleToken::SetToken(OmniPointer<Name> input_value)
    {
        token_field = input_value;
    }

    OmniPointer<Name> SimpleToken::GetToken()
    {
        return token_field;
    }

    void ModifierParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool ModifierParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<ModifierResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Modifier> instance = std::shared_ptr<Modifier>(new Modifier());
        OmniPointer<CardinalityResult> cardinality_field = std::shared_ptr<CardinalityResult>(new CardinalityResult());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && string_parser_instance->ParseSingle(index, std::string("*")))
        {
            instance->SetCardinality(cardinality_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            cardinality_field = std::shared_ptr<CardinalityResult>(new CardinalityResult());
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("?")))
        {
            instance->SetCardinality(cardinality_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            cardinality_field = std::shared_ptr<CardinalityResult>(new CardinalityResult());
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("+")))
        {
            instance->SetCardinality(cardinality_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            cardinality_field = std::shared_ptr<CardinalityResult>(new CardinalityResult());
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("{")) && whitespace_parser_instance->ParseMany(index, 0, -1) && cardinality_parser_instance->ParseSingleSave(index, cardinality_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("}")))
        {
            instance->SetCardinality(cardinality_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            cardinality_field = std::shared_ptr<CardinalityResult>(new CardinalityResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool ModifierParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<ModifierResult> result = std::shared_ptr<ModifierResult>(new ModifierResult());
        return ParseSingleSave(index, result);
    }

    bool ModifierParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<ModifierResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool ModifierParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<ModifierResult> result = std::shared_ptr<ModifierResult>(new ModifierResult());
        return ParseOptionalSave(index, result);
    }

    bool ModifierParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<ModifierListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Modifier>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<ModifierResult> result = std::shared_ptr<ModifierResult>(new ModifierResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool ModifierParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<ModifierListResult> result = std::shared_ptr<ModifierListResult>(new ModifierListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void ModifierResult::SetValue(OmniPointer<Modifier> new_value)
    {
        value = new_value;
    }

    OmniPointer<Modifier> ModifierResult::GetValue()
    {
        return value;
    }

    void ModifierResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool ModifierResult::GetResult()
    {
        return result;
    }

    void ModifierListResult::SetValue(std::vector<OmniPointer<Modifier>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Modifier>> ModifierListResult::GetValue()
    {
        return value;
    }

    void ModifierListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool ModifierListResult::GetResult()
    {
        return result;
    }

    void Modifier::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Modifier::UnParse()
    {
        return length_string->GetString();
    }

    void Modifier::SetCardinality(OmniPointer<Cardinality> input_value)
    {
        cardinality_field = input_value;
    }

    OmniPointer<Cardinality> Modifier::GetCardinality()
    {
        return cardinality_field;
    }

    void CardinalityParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool CardinalityParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<CardinalityResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Cardinality> instance = std::shared_ptr<Cardinality>(new Cardinality());
        OmniPointer<NumberResult> count_field = std::shared_ptr<NumberResult>(new NumberResult());
        OmniPointer<NumberResult> maximum_field = std::shared_ptr<NumberResult>(new NumberResult());
        OmniPointer<NumberResult> minimum_field = std::shared_ptr<NumberResult>(new NumberResult());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && number_parser_instance->ParseSingleSave(index, minimum_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string(",")) && whitespace_parser_instance->ParseMany(index, 0, -1) && number_parser_instance->ParseSingleSave(index, maximum_field))
        {
            instance->SetCount(count_field->GetValue());
            instance->SetMaximum(maximum_field->GetValue());
            instance->SetMinimum(minimum_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            count_field = std::shared_ptr<NumberResult>(new NumberResult());
            maximum_field = std::shared_ptr<NumberResult>(new NumberResult());
            minimum_field = std::shared_ptr<NumberResult>(new NumberResult());
        }

        if (true && number_parser_instance->ParseSingleSave(index, minimum_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string(",")))
        {
            instance->SetCount(count_field->GetValue());
            instance->SetMaximum(maximum_field->GetValue());
            instance->SetMinimum(minimum_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            count_field = std::shared_ptr<NumberResult>(new NumberResult());
            maximum_field = std::shared_ptr<NumberResult>(new NumberResult());
            minimum_field = std::shared_ptr<NumberResult>(new NumberResult());
        }

        if (true && number_parser_instance->ParseSingleSave(index, count_field))
        {
            instance->SetCount(count_field->GetValue());
            instance->SetMaximum(maximum_field->GetValue());
            instance->SetMinimum(minimum_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            count_field = std::shared_ptr<NumberResult>(new NumberResult());
            maximum_field = std::shared_ptr<NumberResult>(new NumberResult());
            minimum_field = std::shared_ptr<NumberResult>(new NumberResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool CardinalityParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<CardinalityResult> result = std::shared_ptr<CardinalityResult>(new CardinalityResult());
        return ParseSingleSave(index, result);
    }

    bool CardinalityParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<CardinalityResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool CardinalityParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<CardinalityResult> result = std::shared_ptr<CardinalityResult>(new CardinalityResult());
        return ParseOptionalSave(index, result);
    }

    bool CardinalityParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<CardinalityListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Cardinality>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<CardinalityResult> result = std::shared_ptr<CardinalityResult>(new CardinalityResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool CardinalityParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<CardinalityListResult> result = std::shared_ptr<CardinalityListResult>(new CardinalityListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void CardinalityResult::SetValue(OmniPointer<Cardinality> new_value)
    {
        value = new_value;
    }

    OmniPointer<Cardinality> CardinalityResult::GetValue()
    {
        return value;
    }

    void CardinalityResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool CardinalityResult::GetResult()
    {
        return result;
    }

    void CardinalityListResult::SetValue(std::vector<OmniPointer<Cardinality>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Cardinality>> CardinalityListResult::GetValue()
    {
        return value;
    }

    void CardinalityListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool CardinalityListResult::GetResult()
    {
        return result;
    }

    void Cardinality::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Cardinality::UnParse()
    {
        return length_string->GetString();
    }

    void Cardinality::SetCount(OmniPointer<Number> input_value)
    {
        count_field = input_value;
    }

    OmniPointer<Number> Cardinality::GetCount()
    {
        return count_field;
    }

    void Cardinality::SetMaximum(OmniPointer<Number> input_value)
    {
        maximum_field = input_value;
    }

    OmniPointer<Number> Cardinality::GetMaximum()
    {
        return maximum_field;
    }

    void Cardinality::SetMinimum(OmniPointer<Number> input_value)
    {
        minimum_field = input_value;
    }

    OmniPointer<Number> Cardinality::GetMinimum()
    {
        return minimum_field;
    }

    void NameParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool NameParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<NameResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Name> instance = std::shared_ptr<Name>(new Name());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && name_character_parser_instance->ParseMany(index, 1, -1))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool NameParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<NameResult> result = std::shared_ptr<NameResult>(new NameResult());
        return ParseSingleSave(index, result);
    }

    bool NameParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<NameResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool NameParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<NameResult> result = std::shared_ptr<NameResult>(new NameResult());
        return ParseOptionalSave(index, result);
    }

    bool NameParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<NameListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Name>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<NameResult> result = std::shared_ptr<NameResult>(new NameResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool NameParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<NameListResult> result = std::shared_ptr<NameListResult>(new NameListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void NameResult::SetValue(OmniPointer<Name> new_value)
    {
        value = new_value;
    }

    OmniPointer<Name> NameResult::GetValue()
    {
        return value;
    }

    void NameResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool NameResult::GetResult()
    {
        return result;
    }

    void NameListResult::SetValue(std::vector<OmniPointer<Name>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Name>> NameListResult::GetValue()
    {
        return value;
    }

    void NameListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool NameListResult::GetResult()
    {
        return result;
    }

    void Name::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Name::UnParse()
    {
        return length_string->GetString();
    }

    void NameCharacterParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool NameCharacterParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<NameCharacterResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<NameCharacter> instance = std::shared_ptr<NameCharacter>(new NameCharacter());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && string_parser_instance->ParseSingle(index, std::string("0")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("1")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("2")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("3")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("4")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("5")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("6")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("7")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("8")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("9")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("A")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("B")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("C")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("D")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("E")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("F")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("G")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("H")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("I")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("J")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("K")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("L")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("M")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("N")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("O")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("P")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("Q")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("R")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("S")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("T")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("U")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("V")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("W")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("X")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("Y")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("Z")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("_")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("a")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("b")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("c")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("d")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("e")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("f")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("g")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("h")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("i")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("j")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("k")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("l")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("m")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("n")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("o")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("p")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("q")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("r")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("s")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("t")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("u")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("v")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("w")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("x")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("y")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("z")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool NameCharacterParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<NameCharacterResult> result = std::shared_ptr<NameCharacterResult>(new NameCharacterResult());
        return ParseSingleSave(index, result);
    }

    bool NameCharacterParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<NameCharacterResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool NameCharacterParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<NameCharacterResult> result = std::shared_ptr<NameCharacterResult>(new NameCharacterResult());
        return ParseOptionalSave(index, result);
    }

    bool NameCharacterParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<NameCharacterListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<NameCharacter>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<NameCharacterResult> result = std::shared_ptr<NameCharacterResult>(new NameCharacterResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool NameCharacterParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<NameCharacterListResult> result = std::shared_ptr<NameCharacterListResult>(new NameCharacterListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void NameCharacterResult::SetValue(OmniPointer<NameCharacter> new_value)
    {
        value = new_value;
    }

    OmniPointer<NameCharacter> NameCharacterResult::GetValue()
    {
        return value;
    }

    void NameCharacterResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool NameCharacterResult::GetResult()
    {
        return result;
    }

    void NameCharacterListResult::SetValue(std::vector<OmniPointer<NameCharacter>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<NameCharacter>> NameCharacterListResult::GetValue()
    {
        return value;
    }

    void NameCharacterListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool NameCharacterListResult::GetResult()
    {
        return result;
    }

    void NameCharacter::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string NameCharacter::UnParse()
    {
        return length_string->GetString();
    }

    void NumberParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool NumberParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<NumberResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Number> instance = std::shared_ptr<Number>(new Number());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && digit_parser_instance->ParseMany(index, 1, -1))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool NumberParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<NumberResult> result = std::shared_ptr<NumberResult>(new NumberResult());
        return ParseSingleSave(index, result);
    }

    bool NumberParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<NumberResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool NumberParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<NumberResult> result = std::shared_ptr<NumberResult>(new NumberResult());
        return ParseOptionalSave(index, result);
    }

    bool NumberParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<NumberListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Number>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<NumberResult> result = std::shared_ptr<NumberResult>(new NumberResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool NumberParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<NumberListResult> result = std::shared_ptr<NumberListResult>(new NumberListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void NumberResult::SetValue(OmniPointer<Number> new_value)
    {
        value = new_value;
    }

    OmniPointer<Number> NumberResult::GetValue()
    {
        return value;
    }

    void NumberResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool NumberResult::GetResult()
    {
        return result;
    }

    void NumberListResult::SetValue(std::vector<OmniPointer<Number>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Number>> NumberListResult::GetValue()
    {
        return value;
    }

    void NumberListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool NumberListResult::GetResult()
    {
        return result;
    }

    void Number::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Number::UnParse()
    {
        return length_string->GetString();
    }

    void DigitParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool DigitParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<DigitResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Digit> instance = std::shared_ptr<Digit>(new Digit());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && string_parser_instance->ParseSingle(index, std::string("0")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("1")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("2")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("3")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("4")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("5")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("6")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("7")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("8")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("9")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool DigitParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<DigitResult> result = std::shared_ptr<DigitResult>(new DigitResult());
        return ParseSingleSave(index, result);
    }

    bool DigitParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<DigitResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool DigitParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<DigitResult> result = std::shared_ptr<DigitResult>(new DigitResult());
        return ParseOptionalSave(index, result);
    }

    bool DigitParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<DigitListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Digit>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<DigitResult> result = std::shared_ptr<DigitResult>(new DigitResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool DigitParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<DigitListResult> result = std::shared_ptr<DigitListResult>(new DigitListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void DigitResult::SetValue(OmniPointer<Digit> new_value)
    {
        value = new_value;
    }

    OmniPointer<Digit> DigitResult::GetValue()
    {
        return value;
    }

    void DigitResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool DigitResult::GetResult()
    {
        return result;
    }

    void DigitListResult::SetValue(std::vector<OmniPointer<Digit>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Digit>> DigitListResult::GetValue()
    {
        return value;
    }

    void DigitListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool DigitListResult::GetResult()
    {
        return result;
    }

    void Digit::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Digit::UnParse()
    {
        return length_string->GetString();
    }

    void PunctuationParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool PunctuationParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<PunctuationResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Punctuation> instance = std::shared_ptr<Punctuation>(new Punctuation());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && string_parser_instance->ParseSingle(index, std::string(",")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string(".")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("?")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("!")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool PunctuationParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<PunctuationResult> result = std::shared_ptr<PunctuationResult>(new PunctuationResult());
        return ParseSingleSave(index, result);
    }

    bool PunctuationParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<PunctuationResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool PunctuationParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<PunctuationResult> result = std::shared_ptr<PunctuationResult>(new PunctuationResult());
        return ParseOptionalSave(index, result);
    }

    bool PunctuationParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<PunctuationListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Punctuation>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<PunctuationResult> result = std::shared_ptr<PunctuationResult>(new PunctuationResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool PunctuationParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<PunctuationListResult> result = std::shared_ptr<PunctuationListResult>(new PunctuationListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void PunctuationResult::SetValue(OmniPointer<Punctuation> new_value)
    {
        value = new_value;
    }

    OmniPointer<Punctuation> PunctuationResult::GetValue()
    {
        return value;
    }

    void PunctuationResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool PunctuationResult::GetResult()
    {
        return result;
    }

    void PunctuationListResult::SetValue(std::vector<OmniPointer<Punctuation>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Punctuation>> PunctuationListResult::GetValue()
    {
        return value;
    }

    void PunctuationListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool PunctuationListResult::GetResult()
    {
        return result;
    }

    void Punctuation::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Punctuation::UnParse()
    {
        return length_string->GetString();
    }

    void CommentCharacterParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool CommentCharacterParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<CommentCharacterResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<CommentCharacter> instance = std::shared_ptr<CommentCharacter>(new CommentCharacter());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && name_character_parser_instance->ParseSingle(index))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && punctuation_parser_instance->ParseSingle(index))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string(" ")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("#")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool CommentCharacterParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<CommentCharacterResult> result = std::shared_ptr<CommentCharacterResult>(new CommentCharacterResult());
        return ParseSingleSave(index, result);
    }

    bool CommentCharacterParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<CommentCharacterResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool CommentCharacterParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<CommentCharacterResult> result = std::shared_ptr<CommentCharacterResult>(new CommentCharacterResult());
        return ParseOptionalSave(index, result);
    }

    bool CommentCharacterParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<CommentCharacterListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<CommentCharacter>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<CommentCharacterResult> result = std::shared_ptr<CommentCharacterResult>(new CommentCharacterResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool CommentCharacterParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<CommentCharacterListResult> result = std::shared_ptr<CommentCharacterListResult>(new CommentCharacterListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void CommentCharacterResult::SetValue(OmniPointer<CommentCharacter> new_value)
    {
        value = new_value;
    }

    OmniPointer<CommentCharacter> CommentCharacterResult::GetValue()
    {
        return value;
    }

    void CommentCharacterResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool CommentCharacterResult::GetResult()
    {
        return result;
    }

    void CommentCharacterListResult::SetValue(std::vector<OmniPointer<CommentCharacter>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<CommentCharacter>> CommentCharacterListResult::GetValue()
    {
        return value;
    }

    void CommentCharacterListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool CommentCharacterListResult::GetResult()
    {
        return result;
    }

    void CommentCharacter::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string CommentCharacter::UnParse()
    {
        return length_string->GetString();
    }

    void CommentParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool CommentParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<CommentResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Comment> instance = std::shared_ptr<Comment>(new Comment());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("#")) && comment_character_parser_instance->ParseMany(index, 0, -1) && eol_parser_instance->ParseSingle(index))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool CommentParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<CommentResult> result = std::shared_ptr<CommentResult>(new CommentResult());
        return ParseSingleSave(index, result);
    }

    bool CommentParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<CommentResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool CommentParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<CommentResult> result = std::shared_ptr<CommentResult>(new CommentResult());
        return ParseOptionalSave(index, result);
    }

    bool CommentParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<CommentListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Comment>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<CommentResult> result = std::shared_ptr<CommentResult>(new CommentResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool CommentParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<CommentListResult> result = std::shared_ptr<CommentListResult>(new CommentListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void CommentResult::SetValue(OmniPointer<Comment> new_value)
    {
        value = new_value;
    }

    OmniPointer<Comment> CommentResult::GetValue()
    {
        return value;
    }

    void CommentResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool CommentResult::GetResult()
    {
        return result;
    }

    void CommentListResult::SetValue(std::vector<OmniPointer<Comment>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Comment>> CommentListResult::GetValue()
    {
        return value;
    }

    void CommentListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool CommentListResult::GetResult()
    {
        return result;
    }

    void Comment::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Comment::UnParse()
    {
        return length_string->GetString();
    }

    void LiteralParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool LiteralParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<LiteralResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Literal> instance = std::shared_ptr<Literal>(new Literal());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && literal_character_parser_instance->ParseMany(index, 0, -1))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool LiteralParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<LiteralResult> result = std::shared_ptr<LiteralResult>(new LiteralResult());
        return ParseSingleSave(index, result);
    }

    bool LiteralParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<LiteralResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool LiteralParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<LiteralResult> result = std::shared_ptr<LiteralResult>(new LiteralResult());
        return ParseOptionalSave(index, result);
    }

    bool LiteralParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<LiteralListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Literal>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<LiteralResult> result = std::shared_ptr<LiteralResult>(new LiteralResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool LiteralParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<LiteralListResult> result = std::shared_ptr<LiteralListResult>(new LiteralListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void LiteralResult::SetValue(OmniPointer<Literal> new_value)
    {
        value = new_value;
    }

    OmniPointer<Literal> LiteralResult::GetValue()
    {
        return value;
    }

    void LiteralResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool LiteralResult::GetResult()
    {
        return result;
    }

    void LiteralListResult::SetValue(std::vector<OmniPointer<Literal>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Literal>> LiteralListResult::GetValue()
    {
        return value;
    }

    void LiteralListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool LiteralListResult::GetResult()
    {
        return result;
    }

    void Literal::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Literal::UnParse()
    {
        return length_string->GetString();
    }

    void LiteralCharacterParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool LiteralCharacterParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<LiteralCharacterResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<LiteralCharacter> instance = std::shared_ptr<LiteralCharacter>(new LiteralCharacter());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && character_parser_instance->ParseSingle(index, 0x00))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x01))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x02))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x03))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x04))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x05))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x06))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x07))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x08))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x09))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0A))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0B))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0C))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0D))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0E))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0F))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x10))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x11))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x12))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x13))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x14))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x15))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x16))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x17))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x18))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x19))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1A))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1B))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1C))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1D))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1E))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1F))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string(" ")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("!")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("\\\"")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("#")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("$")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("%")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("&")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("'")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("(")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string(")")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("*")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("+")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string(",")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("-")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string(".")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("/")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("0")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("1")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("2")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("3")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("4")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("5")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("6")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("7")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("8")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("9")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string(":")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string(";")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("<")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("=")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string(">")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("?")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("@")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("A")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("B")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("C")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("D")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("E")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("F")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("G")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("H")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("I")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("J")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("K")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("L")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("M")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("N")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("O")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("P")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("Q")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("R")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("S")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("T")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("U")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("V")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("W")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("X")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("Y")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("Z")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("[")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("\\\\")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("]")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("^")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("_")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("`")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("a")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("b")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("c")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("d")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("e")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("f")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("g")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("h")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("i")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("j")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("k")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("l")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("m")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("n")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("o")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("p")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("q")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("r")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("s")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("t")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("u")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("v")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("w")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("x")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("y")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("z")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("{")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("|")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("}")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("~")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x80))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x81))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x82))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x83))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x84))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x85))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x86))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x87))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x88))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x89))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x8A))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x8B))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x8C))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x8D))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x8E))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x8F))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x90))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x91))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x92))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x93))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x94))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x95))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x96))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x97))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x98))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x99))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x9A))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x9B))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x9C))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x9D))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x9E))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x9F))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xA0))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xA1))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xA2))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xA3))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xA4))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xA5))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xA6))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xA7))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xA8))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xA9))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xAA))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xAB))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xAC))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xAD))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xAE))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xAF))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xB0))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xB1))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xB2))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xB3))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xB4))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xB5))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xB6))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xB7))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xB8))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xB9))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xBA))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xBB))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xBC))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xBD))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xBE))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xBF))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xC0))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xC1))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xC2))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xC3))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xC4))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xC5))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xC6))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xC7))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xC8))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xC9))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xCA))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xCB))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xCC))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xCD))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xCE))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xCF))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xD0))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xD1))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xD2))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xD3))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xD4))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xD5))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xD6))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xD7))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xD8))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xD9))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xDA))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xDB))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xDC))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xDD))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xDE))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xDF))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xE0))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xE1))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xE2))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xE3))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xE4))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xE5))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xE6))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xE7))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xE8))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xE9))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xEA))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xEB))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xEC))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xED))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xEE))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xEF))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xF0))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xF1))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xF2))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xF3))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xF4))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xF5))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xF6))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xF7))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xF8))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xF9))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xFA))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xFB))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xFC))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xFD))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xFE))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0xFF))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool LiteralCharacterParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<LiteralCharacterResult> result = std::shared_ptr<LiteralCharacterResult>(new LiteralCharacterResult());
        return ParseSingleSave(index, result);
    }

    bool LiteralCharacterParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<LiteralCharacterResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool LiteralCharacterParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<LiteralCharacterResult> result = std::shared_ptr<LiteralCharacterResult>(new LiteralCharacterResult());
        return ParseOptionalSave(index, result);
    }

    bool LiteralCharacterParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<LiteralCharacterListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<LiteralCharacter>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<LiteralCharacterResult> result = std::shared_ptr<LiteralCharacterResult>(new LiteralCharacterResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool LiteralCharacterParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<LiteralCharacterListResult> result = std::shared_ptr<LiteralCharacterListResult>(new LiteralCharacterListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void LiteralCharacterResult::SetValue(OmniPointer<LiteralCharacter> new_value)
    {
        value = new_value;
    }

    OmniPointer<LiteralCharacter> LiteralCharacterResult::GetValue()
    {
        return value;
    }

    void LiteralCharacterResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool LiteralCharacterResult::GetResult()
    {
        return result;
    }

    void LiteralCharacterListResult::SetValue(std::vector<OmniPointer<LiteralCharacter>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<LiteralCharacter>> LiteralCharacterListResult::GetValue()
    {
        return value;
    }

    void LiteralCharacterListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool LiteralCharacterListResult::GetResult()
    {
        return result;
    }

    void LiteralCharacter::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string LiteralCharacter::UnParse()
    {
        return length_string->GetString();
    }

    void HexDigitParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool HexDigitParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<HexDigitResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<HexDigit> instance = std::shared_ptr<HexDigit>(new HexDigit());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && string_parser_instance->ParseSingle(index, std::string("0")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("1")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("2")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("3")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("4")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("5")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("6")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("7")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("8")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("9")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("A")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("B")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("C")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("D")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("E")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("F")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool HexDigitParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<HexDigitResult> result = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        return ParseSingleSave(index, result);
    }

    bool HexDigitParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<HexDigitResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool HexDigitParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<HexDigitResult> result = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        return ParseOptionalSave(index, result);
    }

    bool HexDigitParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<HexDigitListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<HexDigit>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<HexDigitResult> result = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool HexDigitParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<HexDigitListResult> result = std::shared_ptr<HexDigitListResult>(new HexDigitListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void HexDigitResult::SetValue(OmniPointer<HexDigit> new_value)
    {
        value = new_value;
    }

    OmniPointer<HexDigit> HexDigitResult::GetValue()
    {
        return value;
    }

    void HexDigitResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool HexDigitResult::GetResult()
    {
        return result;
    }

    void HexDigitListResult::SetValue(std::vector<OmniPointer<HexDigit>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<HexDigit>> HexDigitListResult::GetValue()
    {
        return value;
    }

    void HexDigitListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool HexDigitListResult::GetResult()
    {
        return result;
    }

    void HexDigit::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string HexDigit::UnParse()
    {
        return length_string->GetString();
    }

    void WhitespaceParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool WhitespaceParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<WhitespaceResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Whitespace> instance = std::shared_ptr<Whitespace>(new Whitespace());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && character_parser_instance->ParseSingle(index, 0x00))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x01))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x02))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x03))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x04))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x05))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x06))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x07))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x08))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x09))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0B))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0C))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0E))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0F))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x10))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x11))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x12))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x13))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x14))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x15))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x16))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x17))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x18))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x19))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1A))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1B))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1C))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1D))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1E))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x1F))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && string_parser_instance->ParseSingle(index, std::string(" ")))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool WhitespaceParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<WhitespaceResult> result = std::shared_ptr<WhitespaceResult>(new WhitespaceResult());
        return ParseSingleSave(index, result);
    }

    bool WhitespaceParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<WhitespaceResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool WhitespaceParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<WhitespaceResult> result = std::shared_ptr<WhitespaceResult>(new WhitespaceResult());
        return ParseOptionalSave(index, result);
    }

    bool WhitespaceParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<WhitespaceListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Whitespace>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<WhitespaceResult> result = std::shared_ptr<WhitespaceResult>(new WhitespaceResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool WhitespaceParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<WhitespaceListResult> result = std::shared_ptr<WhitespaceListResult>(new WhitespaceListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void WhitespaceResult::SetValue(OmniPointer<Whitespace> new_value)
    {
        value = new_value;
    }

    OmniPointer<Whitespace> WhitespaceResult::GetValue()
    {
        return value;
    }

    void WhitespaceResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool WhitespaceResult::GetResult()
    {
        return result;
    }

    void WhitespaceListResult::SetValue(std::vector<OmniPointer<Whitespace>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Whitespace>> WhitespaceListResult::GetValue()
    {
        return value;
    }

    void WhitespaceListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool WhitespaceListResult::GetResult()
    {
        return result;
    }

    void Whitespace::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Whitespace::UnParse()
    {
        return length_string->GetString();
    }

    void EolParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        parser_network = input;
    }

    bool EolParser::ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<EolResult> result)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        OmniPointer<LengthString> consumed_string = std::shared_ptr<LengthString>(new LengthString());
        consumed_string->SetData(index->GetData());
        consumed_string->SetStart(index->GetStart());
        consumed_string->SetLength(0);
        OmniPointer<Eol> instance = std::shared_ptr<Eol>(new Eol());
        OmniPointer<GrammarParser> grammar_parser_instance = parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = parser_network->GetCharacterParser();
        if (true && character_parser_instance->ParseSingle(index, 0x0A) && character_parser_instance->ParseSingle(index, 0x0D))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0D) && character_parser_instance->ParseSingle(index, 0x0A))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0A))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_parser_instance->ParseSingle(index, 0x0D))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool EolParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<EolResult> result = std::shared_ptr<EolResult>(new EolResult());
        return ParseSingleSave(index, result);
    }

    bool EolParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<EolResult> result)
    {
        ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool EolParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<EolResult> result = std::shared_ptr<EolResult>(new EolResult());
        return ParseOptionalSave(index, result);
    }

    bool EolParser::ParseManySave(OmniPointer<LengthString> index, OmniPointer<EolListResult> list_result, int minimum, int maximum)
    {
        int index_start = index->GetStart();
        int index_length = index->GetLength();
        std::vector<OmniPointer<Eol>> results;
        int count = 0;
        int max_check = maximum;
        bool check_next = true;
        if (maximum < 0)
        {
            max_check = count + 1;
        }

        while (check_next && count < max_check)
        {
            OmniPointer<EolResult> result = std::shared_ptr<EolResult>(new EolResult());
            ParseSingleSave(index, result);
            check_next = result->GetResult();
            if (result->GetResult())
            {
                count = count + 1;
                Append(results, result->GetValue());
            }

            if (maximum < 0)
            {
                max_check = count + 1;
            }
        }

        if (count >= minimum && count <= max_check)
        {
            list_result->SetValue(results);
            list_result->SetResult(true);
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
            list_result->SetResult(false);
        }

        return list_result->GetResult();
    }

    bool EolParser::ParseMany(OmniPointer<LengthString> index, int minimum, int maximum)
    {
        OmniPointer<EolListResult> result = std::shared_ptr<EolListResult>(new EolListResult());
        return ParseManySave(index, result, minimum, maximum);
    }

    void EolResult::SetValue(OmniPointer<Eol> new_value)
    {
        value = new_value;
    }

    OmniPointer<Eol> EolResult::GetValue()
    {
        return value;
    }

    void EolResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool EolResult::GetResult()
    {
        return result;
    }

    void EolListResult::SetValue(std::vector<OmniPointer<Eol>> new_value)
    {
        value = new_value;
    }

    std::vector<OmniPointer<Eol>> EolListResult::GetValue()
    {
        return value;
    }

    void EolListResult::SetResult(bool new_result)
    {
        result = new_result;
    }

    bool EolListResult::GetResult()
    {
        return result;
    }

    void Eol::SetLengthString(OmniPointer<LengthString> new_value)
    {
        length_string = std::shared_ptr<LengthString>(new LengthString());
        length_string->SetData(new_value->GetData());
        length_string->SetStart(new_value->GetStart());
        length_string->SetLength(new_value->GetLength());
    }

    std::string Eol::UnParse()
    {
        return length_string->GetString();
    }

};
};
};
};
};
