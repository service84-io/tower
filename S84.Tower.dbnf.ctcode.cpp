#include "S84.Tower.dbnf.ctcode.hpp"


namespace s84
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
        OmniPointer<LargeString> index_data = index->GetData();
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
            if (index_data->GetAt(index->GetStart() + offset_index) != At(value, offset_index))
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
        return this->ParseSingleSave(index, value, result);
    }

    void StringResult::SetValue(OmniPointer<String> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<String> StringResult::GetValue()
    {
        return this->value;
    }

    void StringResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool StringResult::GetResult()
    {
        return this->result;
    }

    void StringListResult::SetValue(std::vector<OmniPointer<String>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<String>> StringListResult::GetValue()
    {
        return this->value;
    }

    void StringListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool StringListResult::GetResult()
    {
        return this->result;
    }

    void String::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string String::UnParse()
    {
        return this->length_string->GetString();
    }

    bool CharacterParser::ParseSingle(OmniPointer<LengthString> index, int value)
    {
        if (0 == index->GetLength())
        {
            return false;
        }

        OmniPointer<LargeString> index_data = index->GetData();
        int current_character = index_data->GetIntAt(index->GetStart());
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
        this->value = new_value;
    }

    OmniPointer<Character> CharacterResult::GetValue()
    {
        return this->value;
    }

    void CharacterResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool CharacterResult::GetResult()
    {
        return this->result;
    }

    void CharacterListResult::SetValue(std::vector<OmniPointer<Character>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Character>> CharacterListResult::GetValue()
    {
        return this->value;
    }

    void CharacterListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool CharacterListResult::GetResult()
    {
        return this->result;
    }

    void Character::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Character::UnParse()
    {
        return this->length_string->GetString();
    }

    bool CharacterRangeParser::ParseSingle(OmniPointer<LengthString> index, int low_value, int high_value)
    {
        if (0 == index->GetLength())
        {
            return false;
        }

        OmniPointer<LargeString> index_data = index->GetData();
        int current_character = index_data->GetIntAt(index->GetStart());
        if (low_value <= current_character && current_character <= high_value)
        {
            index->SetStart(index->GetStart() + 1);
            index->SetLength(index->GetLength() - 1);
            return true;
        }

        return false;
    }

    void CharacterRangeResult::SetValue(OmniPointer<CharacterRange> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<CharacterRange> CharacterRangeResult::GetValue()
    {
        return this->value;
    }

    void CharacterRangeResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool CharacterRangeResult::GetResult()
    {
        return this->result;
    }

    void CharacterRangeListResult::SetValue(std::vector<OmniPointer<CharacterRange>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<CharacterRange>> CharacterRangeListResult::GetValue()
    {
        return this->value;
    }

    void CharacterRangeListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool CharacterRangeListResult::GetResult()
    {
        return this->result;
    }

    void CharacterRange::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string CharacterRange::UnParse()
    {
        return this->length_string->GetString();
    }

    OmniPointer<GrammarParser> ParserNetwork::GetGrammarParser()
    {
        return this->grammar_parser_field;
    }

    OmniPointer<RuleParser> ParserNetwork::GetRuleParser()
    {
        return this->rule_parser_field;
    }

    OmniPointer<ExpressionParser> ParserNetwork::GetExpressionParser()
    {
        return this->expression_parser_field;
    }

    OmniPointer<TokenParser> ParserNetwork::GetTokenParser()
    {
        return this->token_parser_field;
    }

    OmniPointer<SimpleTokenParser> ParserNetwork::GetSimpleTokenParser()
    {
        return this->simple_token_parser_field;
    }

    OmniPointer<ModifierParser> ParserNetwork::GetModifierParser()
    {
        return this->modifier_parser_field;
    }

    OmniPointer<CardinalityParser> ParserNetwork::GetCardinalityParser()
    {
        return this->cardinality_parser_field;
    }

    OmniPointer<NameParser> ParserNetwork::GetNameParser()
    {
        return this->name_parser_field;
    }

    OmniPointer<NameCharacterParser> ParserNetwork::GetNameCharacterParser()
    {
        return this->name_character_parser_field;
    }

    OmniPointer<NumberParser> ParserNetwork::GetNumberParser()
    {
        return this->number_parser_field;
    }

    OmniPointer<DigitParser> ParserNetwork::GetDigitParser()
    {
        return this->digit_parser_field;
    }

    OmniPointer<PunctuationParser> ParserNetwork::GetPunctuationParser()
    {
        return this->punctuation_parser_field;
    }

    OmniPointer<CommentCharacterParser> ParserNetwork::GetCommentCharacterParser()
    {
        return this->comment_character_parser_field;
    }

    OmniPointer<CommentParser> ParserNetwork::GetCommentParser()
    {
        return this->comment_parser_field;
    }

    OmniPointer<LiteralParser> ParserNetwork::GetLiteralParser()
    {
        return this->literal_parser_field;
    }

    OmniPointer<LiteralCharacterParser> ParserNetwork::GetLiteralCharacterParser()
    {
        return this->literal_character_parser_field;
    }

    OmniPointer<HexDigitParser> ParserNetwork::GetHexDigitParser()
    {
        return this->hex_digit_parser_field;
    }

    OmniPointer<WhitespaceParser> ParserNetwork::GetWhitespaceParser()
    {
        return this->whitespace_parser_field;
    }

    OmniPointer<EolParser> ParserNetwork::GetEolParser()
    {
        return this->eol_parser_field;
    }

    OmniPointer<StringParser> ParserNetwork::GetStringParser()
    {
        return this->string_parser_field;
    }

    OmniPointer<CharacterParser> ParserNetwork::GetCharacterParser()
    {
        return this->character_parser_field;
    }

    OmniPointer<CharacterRangeParser> ParserNetwork::GetCharacterRangeParser()
    {
        return this->character_range_parser_field;
    }

    void ParserNetwork::Initialize()
    {
        this->grammar_parser_field = std::shared_ptr<GrammarParser>(new GrammarParser());
        this->grammar_parser_field->SetParserNetwork(this);
        this->rule_parser_field = std::shared_ptr<RuleParser>(new RuleParser());
        this->rule_parser_field->SetParserNetwork(this);
        this->expression_parser_field = std::shared_ptr<ExpressionParser>(new ExpressionParser());
        this->expression_parser_field->SetParserNetwork(this);
        this->token_parser_field = std::shared_ptr<TokenParser>(new TokenParser());
        this->token_parser_field->SetParserNetwork(this);
        this->simple_token_parser_field = std::shared_ptr<SimpleTokenParser>(new SimpleTokenParser());
        this->simple_token_parser_field->SetParserNetwork(this);
        this->modifier_parser_field = std::shared_ptr<ModifierParser>(new ModifierParser());
        this->modifier_parser_field->SetParserNetwork(this);
        this->cardinality_parser_field = std::shared_ptr<CardinalityParser>(new CardinalityParser());
        this->cardinality_parser_field->SetParserNetwork(this);
        this->name_parser_field = std::shared_ptr<NameParser>(new NameParser());
        this->name_parser_field->SetParserNetwork(this);
        this->name_character_parser_field = std::shared_ptr<NameCharacterParser>(new NameCharacterParser());
        this->name_character_parser_field->SetParserNetwork(this);
        this->number_parser_field = std::shared_ptr<NumberParser>(new NumberParser());
        this->number_parser_field->SetParserNetwork(this);
        this->digit_parser_field = std::shared_ptr<DigitParser>(new DigitParser());
        this->digit_parser_field->SetParserNetwork(this);
        this->punctuation_parser_field = std::shared_ptr<PunctuationParser>(new PunctuationParser());
        this->punctuation_parser_field->SetParserNetwork(this);
        this->comment_character_parser_field = std::shared_ptr<CommentCharacterParser>(new CommentCharacterParser());
        this->comment_character_parser_field->SetParserNetwork(this);
        this->comment_parser_field = std::shared_ptr<CommentParser>(new CommentParser());
        this->comment_parser_field->SetParserNetwork(this);
        this->literal_parser_field = std::shared_ptr<LiteralParser>(new LiteralParser());
        this->literal_parser_field->SetParserNetwork(this);
        this->literal_character_parser_field = std::shared_ptr<LiteralCharacterParser>(new LiteralCharacterParser());
        this->literal_character_parser_field->SetParserNetwork(this);
        this->hex_digit_parser_field = std::shared_ptr<HexDigitParser>(new HexDigitParser());
        this->hex_digit_parser_field->SetParserNetwork(this);
        this->whitespace_parser_field = std::shared_ptr<WhitespaceParser>(new WhitespaceParser());
        this->whitespace_parser_field->SetParserNetwork(this);
        this->eol_parser_field = std::shared_ptr<EolParser>(new EolParser());
        this->eol_parser_field->SetParserNetwork(this);
        this->string_parser_field = std::shared_ptr<StringParser>(new StringParser());
        this->character_parser_field = std::shared_ptr<CharacterParser>(new CharacterParser());
        this->character_range_parser_field = std::shared_ptr<CharacterRangeParser>(new CharacterRangeParser());
    }

    void DBNFOmniType::SetGrammar(OmniPointer<Grammar> input_value)
    {
        this->grammar_field = input_value;
    }

    OmniPointer<Grammar> DBNFOmniType::GetGrammar()
    {
        return this->grammar_field;
    }

    void DBNFOmniType::SetRule(OmniPointer<Rule> input_value)
    {
        this->rule_field = input_value;
    }

    OmniPointer<Rule> DBNFOmniType::GetRule()
    {
        return this->rule_field;
    }

    void DBNFOmniType::SetExpression(OmniPointer<Expression> input_value)
    {
        this->expression_field = input_value;
    }

    OmniPointer<Expression> DBNFOmniType::GetExpression()
    {
        return this->expression_field;
    }

    void DBNFOmniType::SetToken(OmniPointer<Token> input_value)
    {
        this->token_field = input_value;
    }

    OmniPointer<Token> DBNFOmniType::GetToken()
    {
        return this->token_field;
    }

    void DBNFOmniType::SetSimpleToken(OmniPointer<SimpleToken> input_value)
    {
        this->simple_token_field = input_value;
    }

    OmniPointer<SimpleToken> DBNFOmniType::GetSimpleToken()
    {
        return this->simple_token_field;
    }

    void DBNFOmniType::SetModifier(OmniPointer<Modifier> input_value)
    {
        this->modifier_field = input_value;
    }

    OmniPointer<Modifier> DBNFOmniType::GetModifier()
    {
        return this->modifier_field;
    }

    void DBNFOmniType::SetCardinality(OmniPointer<Cardinality> input_value)
    {
        this->cardinality_field = input_value;
    }

    OmniPointer<Cardinality> DBNFOmniType::GetCardinality()
    {
        return this->cardinality_field;
    }

    void DBNFOmniType::SetName(OmniPointer<Name> input_value)
    {
        this->name_field = input_value;
    }

    OmniPointer<Name> DBNFOmniType::GetName()
    {
        return this->name_field;
    }

    void DBNFOmniType::SetNameCharacter(OmniPointer<NameCharacter> input_value)
    {
        this->name_character_field = input_value;
    }

    OmniPointer<NameCharacter> DBNFOmniType::GetNameCharacter()
    {
        return this->name_character_field;
    }

    void DBNFOmniType::SetNumber(OmniPointer<Number> input_value)
    {
        this->number_field = input_value;
    }

    OmniPointer<Number> DBNFOmniType::GetNumber()
    {
        return this->number_field;
    }

    void DBNFOmniType::SetDigit(OmniPointer<Digit> input_value)
    {
        this->digit_field = input_value;
    }

    OmniPointer<Digit> DBNFOmniType::GetDigit()
    {
        return this->digit_field;
    }

    void DBNFOmniType::SetPunctuation(OmniPointer<Punctuation> input_value)
    {
        this->punctuation_field = input_value;
    }

    OmniPointer<Punctuation> DBNFOmniType::GetPunctuation()
    {
        return this->punctuation_field;
    }

    void DBNFOmniType::SetCommentCharacter(OmniPointer<CommentCharacter> input_value)
    {
        this->comment_character_field = input_value;
    }

    OmniPointer<CommentCharacter> DBNFOmniType::GetCommentCharacter()
    {
        return this->comment_character_field;
    }

    void DBNFOmniType::SetComment(OmniPointer<Comment> input_value)
    {
        this->comment_field = input_value;
    }

    OmniPointer<Comment> DBNFOmniType::GetComment()
    {
        return this->comment_field;
    }

    void DBNFOmniType::SetLiteral(OmniPointer<Literal> input_value)
    {
        this->literal_field = input_value;
    }

    OmniPointer<Literal> DBNFOmniType::GetLiteral()
    {
        return this->literal_field;
    }

    void DBNFOmniType::SetLiteralCharacter(OmniPointer<LiteralCharacter> input_value)
    {
        this->literal_character_field = input_value;
    }

    OmniPointer<LiteralCharacter> DBNFOmniType::GetLiteralCharacter()
    {
        return this->literal_character_field;
    }

    void DBNFOmniType::SetHexDigit(OmniPointer<HexDigit> input_value)
    {
        this->hex_digit_field = input_value;
    }

    OmniPointer<HexDigit> DBNFOmniType::GetHexDigit()
    {
        return this->hex_digit_field;
    }

    void DBNFOmniType::SetWhitespace(OmniPointer<Whitespace> input_value)
    {
        this->whitespace_field = input_value;
    }

    OmniPointer<Whitespace> DBNFOmniType::GetWhitespace()
    {
        return this->whitespace_field;
    }

    void DBNFOmniType::SetEol(OmniPointer<Eol> input_value)
    {
        this->eol_field = input_value;
    }

    OmniPointer<Eol> DBNFOmniType::GetEol()
    {
        return this->eol_field;
    }

    void DBNFOmniTypeResult::SetValue(OmniPointer<DBNFOmniType> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<DBNFOmniType> DBNFOmniTypeResult::GetValue()
    {
        return this->value;
    }

    void DBNFOmniTypeResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool DBNFOmniTypeResult::GetResult()
    {
        return this->result;
    }

    void DBNFOmniTypeResult::SetGrammar(OmniPointer<Grammar> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetGrammar(input_value);
    }

    void DBNFOmniTypeResult::SetRule(OmniPointer<Rule> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetRule(input_value);
    }

    void DBNFOmniTypeResult::SetExpression(OmniPointer<Expression> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetExpression(input_value);
    }

    void DBNFOmniTypeResult::SetToken(OmniPointer<Token> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetToken(input_value);
    }

    void DBNFOmniTypeResult::SetSimpleToken(OmniPointer<SimpleToken> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetSimpleToken(input_value);
    }

    void DBNFOmniTypeResult::SetModifier(OmniPointer<Modifier> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetModifier(input_value);
    }

    void DBNFOmniTypeResult::SetCardinality(OmniPointer<Cardinality> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetCardinality(input_value);
    }

    void DBNFOmniTypeResult::SetName(OmniPointer<Name> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetName(input_value);
    }

    void DBNFOmniTypeResult::SetNameCharacter(OmniPointer<NameCharacter> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetNameCharacter(input_value);
    }

    void DBNFOmniTypeResult::SetNumber(OmniPointer<Number> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetNumber(input_value);
    }

    void DBNFOmniTypeResult::SetDigit(OmniPointer<Digit> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetDigit(input_value);
    }

    void DBNFOmniTypeResult::SetPunctuation(OmniPointer<Punctuation> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetPunctuation(input_value);
    }

    void DBNFOmniTypeResult::SetCommentCharacter(OmniPointer<CommentCharacter> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetCommentCharacter(input_value);
    }

    void DBNFOmniTypeResult::SetComment(OmniPointer<Comment> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetComment(input_value);
    }

    void DBNFOmniTypeResult::SetLiteral(OmniPointer<Literal> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetLiteral(input_value);
    }

    void DBNFOmniTypeResult::SetLiteralCharacter(OmniPointer<LiteralCharacter> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetLiteralCharacter(input_value);
    }

    void DBNFOmniTypeResult::SetHexDigit(OmniPointer<HexDigit> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetHexDigit(input_value);
    }

    void DBNFOmniTypeResult::SetWhitespace(OmniPointer<Whitespace> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetWhitespace(input_value);
    }

    void DBNFOmniTypeResult::SetEol(OmniPointer<Eol> input_value)
    {
        this->value = std::shared_ptr<DBNFOmniType>(new DBNFOmniType());
        this->value->SetEol(input_value);
    }

    void DBNFOmniTypeListResult::SetValue(std::vector<OmniPointer<DBNFOmniType>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<DBNFOmniType>> DBNFOmniTypeListResult::GetValue()
    {
        return this->value;
    }

    void DBNFOmniTypeListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool DBNFOmniTypeListResult::GetResult()
    {
        return this->result;
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

    void LargeString::SetData(std::string new_data)
    {
        this->data = new_data;
    }

    std::string LargeString::GetData()
    {
        return this->data;
    }

    int LargeString::GetIntAt(int offset)
    {
        return IntAt(this->data, offset);
    }

    std::string LargeString::GetAt(int offset)
    {
        return At(this->data, offset);
    }

    void LengthString::SetData(OmniPointer<LargeString> new_data)
    {
        this->data = new_data;
    }

    OmniPointer<LargeString> LengthString::GetData()
    {
        return this->data;
    }

    void LengthString::SetStart(int new_start)
    {
        this->start = new_start;
    }

    int LengthString::GetStart()
    {
        return this->start;
    }

    void LengthString::SetLength(int new_length)
    {
        this->length = new_length;
    }

    int LengthString::GetLength()
    {
        return this->length;
    }

    std::string LengthString::GetString()
    {
        std::string deep_data = this->data->GetData();
        std::string result;
        int index = this->start;
        int end = this->start + this->length;
        while (index < end)
        {
            result = Concat(result, At(deep_data, index));
            index = index + 1;
        }

        return result;
    }

    void GrammarParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
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
        return this->ParseSingleSave(index, result);
    }

    bool GrammarParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<GrammarResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool GrammarParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<GrammarResult> result = std::shared_ptr<GrammarResult>(new GrammarResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void GrammarResult::SetValue(OmniPointer<Grammar> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Grammar> GrammarResult::GetValue()
    {
        return this->value;
    }

    void GrammarResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool GrammarResult::GetResult()
    {
        return this->result;
    }

    void GrammarListResult::SetValue(std::vector<OmniPointer<Grammar>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Grammar>> GrammarListResult::GetValue()
    {
        return this->value;
    }

    void GrammarListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool GrammarListResult::GetResult()
    {
        return this->result;
    }

    void Grammar::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Grammar::UnParse()
    {
        return this->length_string->GetString();
    }

    void Grammar::SetRules(std::vector<OmniPointer<Rule>> input_value)
    {
        this->rules_field = input_value;
    }

    std::vector<OmniPointer<Rule>> Grammar::GetRules()
    {
        return this->rules_field;
    }

    void RuleParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
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
        return this->ParseSingleSave(index, result);
    }

    bool RuleParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<RuleResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool RuleParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<RuleResult> result = std::shared_ptr<RuleResult>(new RuleResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void RuleResult::SetValue(OmniPointer<Rule> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Rule> RuleResult::GetValue()
    {
        return this->value;
    }

    void RuleResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool RuleResult::GetResult()
    {
        return this->result;
    }

    void RuleListResult::SetValue(std::vector<OmniPointer<Rule>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Rule>> RuleListResult::GetValue()
    {
        return this->value;
    }

    void RuleListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool RuleListResult::GetResult()
    {
        return this->result;
    }

    void Rule::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Rule::UnParse()
    {
        return this->length_string->GetString();
    }

    void Rule::SetExpressions(std::vector<OmniPointer<Expression>> input_value)
    {
        this->expressions_field = input_value;
    }

    std::vector<OmniPointer<Expression>> Rule::GetExpressions()
    {
        return this->expressions_field;
    }

    void Rule::SetName(OmniPointer<Name> input_value)
    {
        this->name_field = input_value;
    }

    OmniPointer<Name> Rule::GetName()
    {
        return this->name_field;
    }

    void ExpressionParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<StringResult> expression_discriminator_field = std::shared_ptr<StringResult>(new StringResult());
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingleSave(index, std::string("::="), expression_discriminator_field) && token_parser_instance->ParseManySave(index, token_sequence_field, 0, -1) && eol_parser_instance->ParseSingle(index))
        {
            instance->SetTokenSequence(token_sequence_field->GetValue());
            instance->SetExpressionDiscriminator(expression_discriminator_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
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
            expression_discriminator_field = std::shared_ptr<StringResult>(new StringResult());
        }

        if (true && comment_parser_instance->ParseSingle(index))
        {
            instance->SetTokenSequence(token_sequence_field->GetValue());
            instance->SetExpressionDiscriminator(expression_discriminator_field->GetValue());
            consumed_string->SetLength(index->GetStart() - index_start);
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
            expression_discriminator_field = std::shared_ptr<StringResult>(new StringResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool ExpressionParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<ExpressionResult> result = std::shared_ptr<ExpressionResult>(new ExpressionResult());
        return this->ParseSingleSave(index, result);
    }

    bool ExpressionParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<ExpressionResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool ExpressionParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<ExpressionResult> result = std::shared_ptr<ExpressionResult>(new ExpressionResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void ExpressionResult::SetValue(OmniPointer<Expression> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Expression> ExpressionResult::GetValue()
    {
        return this->value;
    }

    void ExpressionResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool ExpressionResult::GetResult()
    {
        return this->result;
    }

    void ExpressionListResult::SetValue(std::vector<OmniPointer<Expression>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Expression>> ExpressionListResult::GetValue()
    {
        return this->value;
    }

    void ExpressionListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool ExpressionListResult::GetResult()
    {
        return this->result;
    }

    void Expression::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Expression::UnParse()
    {
        return this->length_string->GetString();
    }

    void Expression::SetTokenSequence(std::vector<OmniPointer<Token>> input_value)
    {
        this->token_sequence_field = input_value;
    }

    std::vector<OmniPointer<Token>> Expression::GetTokenSequence()
    {
        return this->token_sequence_field;
    }

    void Expression::SetExpressionDiscriminator(OmniPointer<String> input_value)
    {
        this->expression_discriminator_field = input_value;
    }

    OmniPointer<String> Expression::GetExpressionDiscriminator()
    {
        return this->expression_discriminator_field;
    }

    void TokenParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<SimpleTokenResult> value_field = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
        OmniPointer<NameResult> name_field = std::shared_ptr<NameResult>(new NameResult());
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("attribute")) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("(")) && whitespace_parser_instance->ParseMany(index, 0, -1) && name_parser_instance->ParseSingleSave(index, name_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && simple_token_parser_instance->ParseSingleSave(index, value_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && modifier_parser_instance->ParseSingleSave(index, modifier_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string(")")) && whitespace_parser_instance->ParseMany(index, 0, -1))
        {
            instance->SetModifier(modifier_field->GetValue());
            instance->SetValue(value_field->GetValue());
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
            modifier_field = std::shared_ptr<ModifierResult>(new ModifierResult());
            value_field = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
            name_field = std::shared_ptr<NameResult>(new NameResult());
        }

        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("attribute")) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string("(")) && whitespace_parser_instance->ParseMany(index, 0, -1) && name_parser_instance->ParseSingleSave(index, name_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && simple_token_parser_instance->ParseSingleSave(index, value_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string(")")) && whitespace_parser_instance->ParseMany(index, 0, -1))
        {
            instance->SetModifier(modifier_field->GetValue());
            instance->SetValue(value_field->GetValue());
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
            modifier_field = std::shared_ptr<ModifierResult>(new ModifierResult());
            value_field = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
            name_field = std::shared_ptr<NameResult>(new NameResult());
        }

        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && simple_token_parser_instance->ParseSingleSave(index, value_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && modifier_parser_instance->ParseSingleSave(index, modifier_field) && whitespace_parser_instance->ParseMany(index, 0, -1))
        {
            instance->SetModifier(modifier_field->GetValue());
            instance->SetValue(value_field->GetValue());
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
            modifier_field = std::shared_ptr<ModifierResult>(new ModifierResult());
            value_field = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
            name_field = std::shared_ptr<NameResult>(new NameResult());
        }

        if (true && whitespace_parser_instance->ParseMany(index, 0, -1) && simple_token_parser_instance->ParseSingleSave(index, value_field) && whitespace_parser_instance->ParseMany(index, 0, -1))
        {
            instance->SetModifier(modifier_field->GetValue());
            instance->SetValue(value_field->GetValue());
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
            modifier_field = std::shared_ptr<ModifierResult>(new ModifierResult());
            value_field = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
            name_field = std::shared_ptr<NameResult>(new NameResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool TokenParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<TokenResult> result = std::shared_ptr<TokenResult>(new TokenResult());
        return this->ParseSingleSave(index, result);
    }

    bool TokenParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<TokenResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool TokenParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<TokenResult> result = std::shared_ptr<TokenResult>(new TokenResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void TokenResult::SetValue(OmniPointer<Token> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Token> TokenResult::GetValue()
    {
        return this->value;
    }

    void TokenResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool TokenResult::GetResult()
    {
        return this->result;
    }

    void TokenListResult::SetValue(std::vector<OmniPointer<Token>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Token>> TokenListResult::GetValue()
    {
        return this->value;
    }

    void TokenListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool TokenListResult::GetResult()
    {
        return this->result;
    }

    void Token::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Token::UnParse()
    {
        return this->length_string->GetString();
    }

    void Token::SetModifier(OmniPointer<Modifier> input_value)
    {
        this->modifier_field = input_value;
    }

    OmniPointer<Modifier> Token::GetModifier()
    {
        return this->modifier_field;
    }

    void Token::SetValue(OmniPointer<SimpleToken> input_value)
    {
        this->value_field = input_value;
    }

    OmniPointer<SimpleToken> Token::GetValue()
    {
        return this->value_field;
    }

    void Token::SetName(OmniPointer<Name> input_value)
    {
        this->name_field = input_value;
    }

    OmniPointer<Name> Token::GetName()
    {
        return this->name_field;
    }

    void SimpleTokenParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<HexDigitResult> high_low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        OmniPointer<HexDigitResult> high_high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        OmniPointer<HexDigitResult> low_low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        OmniPointer<HexDigitResult> low_high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        OmniPointer<HexDigitResult> low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        OmniPointer<LiteralResult> literal_field = std::shared_ptr<LiteralResult>(new LiteralResult());
        OmniPointer<HexDigitResult> high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        OmniPointer<NameResult> token_field = std::shared_ptr<NameResult>(new NameResult());
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
        if (true && string_parser_instance->ParseSingle(index, std::string("<")) && name_parser_instance->ParseSingleSave(index, token_field) && string_parser_instance->ParseSingle(index, std::string(">")))
        {
            instance->SetHighLow(high_low_field->GetValue());
            instance->SetHighHigh(high_high_field->GetValue());
            instance->SetLowLow(low_low_field->GetValue());
            instance->SetLowHigh(low_high_field->GetValue());
            instance->SetLow(low_field->GetValue());
            instance->SetLiteral(literal_field->GetValue());
            instance->SetHigh(high_field->GetValue());
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
            high_low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            high_high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            literal_field = std::shared_ptr<LiteralResult>(new LiteralResult());
            high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            token_field = std::shared_ptr<NameResult>(new NameResult());
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("0x")) && hex_digit_parser_instance->ParseSingleSave(index, high_field) && hex_digit_parser_instance->ParseSingleSave(index, low_field))
        {
            instance->SetHighLow(high_low_field->GetValue());
            instance->SetHighHigh(high_high_field->GetValue());
            instance->SetLowLow(low_low_field->GetValue());
            instance->SetLowHigh(low_high_field->GetValue());
            instance->SetLow(low_field->GetValue());
            instance->SetLiteral(literal_field->GetValue());
            instance->SetHigh(high_field->GetValue());
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
            high_low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            high_high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            literal_field = std::shared_ptr<LiteralResult>(new LiteralResult());
            high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            token_field = std::shared_ptr<NameResult>(new NameResult());
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("\"")) && literal_parser_instance->ParseSingleSave(index, literal_field) && string_parser_instance->ParseSingle(index, std::string("\"")))
        {
            instance->SetHighLow(high_low_field->GetValue());
            instance->SetHighHigh(high_high_field->GetValue());
            instance->SetLowLow(low_low_field->GetValue());
            instance->SetLowHigh(low_high_field->GetValue());
            instance->SetLow(low_field->GetValue());
            instance->SetLiteral(literal_field->GetValue());
            instance->SetHigh(high_field->GetValue());
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
            high_low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            high_high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            literal_field = std::shared_ptr<LiteralResult>(new LiteralResult());
            high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            token_field = std::shared_ptr<NameResult>(new NameResult());
        }

        if (true && string_parser_instance->ParseSingle(index, std::string("[0x")) && hex_digit_parser_instance->ParseSingleSave(index, low_high_field) && hex_digit_parser_instance->ParseSingleSave(index, low_low_field) && string_parser_instance->ParseSingle(index, std::string("-0x")) && hex_digit_parser_instance->ParseSingleSave(index, high_high_field) && hex_digit_parser_instance->ParseSingleSave(index, high_low_field) && string_parser_instance->ParseSingle(index, std::string("]")))
        {
            instance->SetHighLow(high_low_field->GetValue());
            instance->SetHighHigh(high_high_field->GetValue());
            instance->SetLowLow(low_low_field->GetValue());
            instance->SetLowHigh(low_high_field->GetValue());
            instance->SetLow(low_field->GetValue());
            instance->SetLiteral(literal_field->GetValue());
            instance->SetHigh(high_field->GetValue());
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
            high_low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            high_high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            low_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            literal_field = std::shared_ptr<LiteralResult>(new LiteralResult());
            high_field = std::shared_ptr<HexDigitResult>(new HexDigitResult());
            token_field = std::shared_ptr<NameResult>(new NameResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool SimpleTokenParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<SimpleTokenResult> result = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
        return this->ParseSingleSave(index, result);
    }

    bool SimpleTokenParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<SimpleTokenResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool SimpleTokenParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<SimpleTokenResult> result = std::shared_ptr<SimpleTokenResult>(new SimpleTokenResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void SimpleTokenResult::SetValue(OmniPointer<SimpleToken> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<SimpleToken> SimpleTokenResult::GetValue()
    {
        return this->value;
    }

    void SimpleTokenResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool SimpleTokenResult::GetResult()
    {
        return this->result;
    }

    void SimpleTokenListResult::SetValue(std::vector<OmniPointer<SimpleToken>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<SimpleToken>> SimpleTokenListResult::GetValue()
    {
        return this->value;
    }

    void SimpleTokenListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool SimpleTokenListResult::GetResult()
    {
        return this->result;
    }

    void SimpleToken::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string SimpleToken::UnParse()
    {
        return this->length_string->GetString();
    }

    void SimpleToken::SetHighLow(OmniPointer<HexDigit> input_value)
    {
        this->high_low_field = input_value;
    }

    OmniPointer<HexDigit> SimpleToken::GetHighLow()
    {
        return this->high_low_field;
    }

    void SimpleToken::SetHighHigh(OmniPointer<HexDigit> input_value)
    {
        this->high_high_field = input_value;
    }

    OmniPointer<HexDigit> SimpleToken::GetHighHigh()
    {
        return this->high_high_field;
    }

    void SimpleToken::SetLowLow(OmniPointer<HexDigit> input_value)
    {
        this->low_low_field = input_value;
    }

    OmniPointer<HexDigit> SimpleToken::GetLowLow()
    {
        return this->low_low_field;
    }

    void SimpleToken::SetLowHigh(OmniPointer<HexDigit> input_value)
    {
        this->low_high_field = input_value;
    }

    OmniPointer<HexDigit> SimpleToken::GetLowHigh()
    {
        return this->low_high_field;
    }

    void SimpleToken::SetLow(OmniPointer<HexDigit> input_value)
    {
        this->low_field = input_value;
    }

    OmniPointer<HexDigit> SimpleToken::GetLow()
    {
        return this->low_field;
    }

    void SimpleToken::SetLiteral(OmniPointer<Literal> input_value)
    {
        this->literal_field = input_value;
    }

    OmniPointer<Literal> SimpleToken::GetLiteral()
    {
        return this->literal_field;
    }

    void SimpleToken::SetHigh(OmniPointer<HexDigit> input_value)
    {
        this->high_field = input_value;
    }

    OmniPointer<HexDigit> SimpleToken::GetHigh()
    {
        return this->high_field;
    }

    void SimpleToken::SetToken(OmniPointer<Name> input_value)
    {
        this->token_field = input_value;
    }

    OmniPointer<Name> SimpleToken::GetToken()
    {
        return this->token_field;
    }

    void ModifierParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
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
        return this->ParseSingleSave(index, result);
    }

    bool ModifierParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<ModifierResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool ModifierParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<ModifierResult> result = std::shared_ptr<ModifierResult>(new ModifierResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void ModifierResult::SetValue(OmniPointer<Modifier> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Modifier> ModifierResult::GetValue()
    {
        return this->value;
    }

    void ModifierResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool ModifierResult::GetResult()
    {
        return this->result;
    }

    void ModifierListResult::SetValue(std::vector<OmniPointer<Modifier>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Modifier>> ModifierListResult::GetValue()
    {
        return this->value;
    }

    void ModifierListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool ModifierListResult::GetResult()
    {
        return this->result;
    }

    void Modifier::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Modifier::UnParse()
    {
        return this->length_string->GetString();
    }

    void Modifier::SetCardinality(OmniPointer<Cardinality> input_value)
    {
        this->cardinality_field = input_value;
    }

    OmniPointer<Cardinality> Modifier::GetCardinality()
    {
        return this->cardinality_field;
    }

    void CardinalityParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<NumberResult> maximum_field = std::shared_ptr<NumberResult>(new NumberResult());
        OmniPointer<NumberResult> count_field = std::shared_ptr<NumberResult>(new NumberResult());
        OmniPointer<NumberResult> minimum_field = std::shared_ptr<NumberResult>(new NumberResult());
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
        if (true && number_parser_instance->ParseSingleSave(index, minimum_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string(",")) && whitespace_parser_instance->ParseMany(index, 0, -1) && number_parser_instance->ParseSingleSave(index, maximum_field))
        {
            instance->SetMaximum(maximum_field->GetValue());
            instance->SetCount(count_field->GetValue());
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
            maximum_field = std::shared_ptr<NumberResult>(new NumberResult());
            count_field = std::shared_ptr<NumberResult>(new NumberResult());
            minimum_field = std::shared_ptr<NumberResult>(new NumberResult());
        }

        if (true && number_parser_instance->ParseSingleSave(index, minimum_field) && whitespace_parser_instance->ParseMany(index, 0, -1) && string_parser_instance->ParseSingle(index, std::string(",")))
        {
            instance->SetMaximum(maximum_field->GetValue());
            instance->SetCount(count_field->GetValue());
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
            maximum_field = std::shared_ptr<NumberResult>(new NumberResult());
            count_field = std::shared_ptr<NumberResult>(new NumberResult());
            minimum_field = std::shared_ptr<NumberResult>(new NumberResult());
        }

        if (true && number_parser_instance->ParseSingleSave(index, count_field))
        {
            instance->SetMaximum(maximum_field->GetValue());
            instance->SetCount(count_field->GetValue());
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
            maximum_field = std::shared_ptr<NumberResult>(new NumberResult());
            count_field = std::shared_ptr<NumberResult>(new NumberResult());
            minimum_field = std::shared_ptr<NumberResult>(new NumberResult());
        }

        result->SetResult(false);
        return result->GetResult();
    }

    bool CardinalityParser::ParseSingle(OmniPointer<LengthString> index)
    {
        OmniPointer<CardinalityResult> result = std::shared_ptr<CardinalityResult>(new CardinalityResult());
        return this->ParseSingleSave(index, result);
    }

    bool CardinalityParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<CardinalityResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool CardinalityParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<CardinalityResult> result = std::shared_ptr<CardinalityResult>(new CardinalityResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void CardinalityResult::SetValue(OmniPointer<Cardinality> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Cardinality> CardinalityResult::GetValue()
    {
        return this->value;
    }

    void CardinalityResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool CardinalityResult::GetResult()
    {
        return this->result;
    }

    void CardinalityListResult::SetValue(std::vector<OmniPointer<Cardinality>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Cardinality>> CardinalityListResult::GetValue()
    {
        return this->value;
    }

    void CardinalityListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool CardinalityListResult::GetResult()
    {
        return this->result;
    }

    void Cardinality::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Cardinality::UnParse()
    {
        return this->length_string->GetString();
    }

    void Cardinality::SetMaximum(OmniPointer<Number> input_value)
    {
        this->maximum_field = input_value;
    }

    OmniPointer<Number> Cardinality::GetMaximum()
    {
        return this->maximum_field;
    }

    void Cardinality::SetCount(OmniPointer<Number> input_value)
    {
        this->count_field = input_value;
    }

    OmniPointer<Number> Cardinality::GetCount()
    {
        return this->count_field;
    }

    void Cardinality::SetMinimum(OmniPointer<Number> input_value)
    {
        this->minimum_field = input_value;
    }

    OmniPointer<Number> Cardinality::GetMinimum()
    {
        return this->minimum_field;
    }

    void NameParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
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
        return this->ParseSingleSave(index, result);
    }

    bool NameParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<NameResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool NameParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<NameResult> result = std::shared_ptr<NameResult>(new NameResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void NameResult::SetValue(OmniPointer<Name> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Name> NameResult::GetValue()
    {
        return this->value;
    }

    void NameResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool NameResult::GetResult()
    {
        return this->result;
    }

    void NameListResult::SetValue(std::vector<OmniPointer<Name>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Name>> NameListResult::GetValue()
    {
        return this->value;
    }

    void NameListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool NameListResult::GetResult()
    {
        return this->result;
    }

    void Name::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Name::UnParse()
    {
        return this->length_string->GetString();
    }

    void NameCharacterParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
        if (true && character_range_parser_instance->ParseSingle(index, 0x30, 0x39))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_range_parser_instance->ParseSingle(index, 0x41, 0x5A))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
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

        if (true && character_range_parser_instance->ParseSingle(index, 0x61, 0x7A))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
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
        return this->ParseSingleSave(index, result);
    }

    bool NameCharacterParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<NameCharacterResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool NameCharacterParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<NameCharacterResult> result = std::shared_ptr<NameCharacterResult>(new NameCharacterResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void NameCharacterResult::SetValue(OmniPointer<NameCharacter> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<NameCharacter> NameCharacterResult::GetValue()
    {
        return this->value;
    }

    void NameCharacterResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool NameCharacterResult::GetResult()
    {
        return this->result;
    }

    void NameCharacterListResult::SetValue(std::vector<OmniPointer<NameCharacter>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<NameCharacter>> NameCharacterListResult::GetValue()
    {
        return this->value;
    }

    void NameCharacterListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool NameCharacterListResult::GetResult()
    {
        return this->result;
    }

    void NameCharacter::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string NameCharacter::UnParse()
    {
        return this->length_string->GetString();
    }

    void NumberParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
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
        return this->ParseSingleSave(index, result);
    }

    bool NumberParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<NumberResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool NumberParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<NumberResult> result = std::shared_ptr<NumberResult>(new NumberResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void NumberResult::SetValue(OmniPointer<Number> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Number> NumberResult::GetValue()
    {
        return this->value;
    }

    void NumberResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool NumberResult::GetResult()
    {
        return this->result;
    }

    void NumberListResult::SetValue(std::vector<OmniPointer<Number>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Number>> NumberListResult::GetValue()
    {
        return this->value;
    }

    void NumberListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool NumberListResult::GetResult()
    {
        return this->result;
    }

    void Number::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Number::UnParse()
    {
        return this->length_string->GetString();
    }

    void DigitParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
        if (true && character_range_parser_instance->ParseSingle(index, 0x30, 0x39))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
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
        return this->ParseSingleSave(index, result);
    }

    bool DigitParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<DigitResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool DigitParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<DigitResult> result = std::shared_ptr<DigitResult>(new DigitResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void DigitResult::SetValue(OmniPointer<Digit> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Digit> DigitResult::GetValue()
    {
        return this->value;
    }

    void DigitResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool DigitResult::GetResult()
    {
        return this->result;
    }

    void DigitListResult::SetValue(std::vector<OmniPointer<Digit>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Digit>> DigitListResult::GetValue()
    {
        return this->value;
    }

    void DigitListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool DigitListResult::GetResult()
    {
        return this->result;
    }

    void Digit::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Digit::UnParse()
    {
        return this->length_string->GetString();
    }

    void PunctuationParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
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
        return this->ParseSingleSave(index, result);
    }

    bool PunctuationParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<PunctuationResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool PunctuationParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<PunctuationResult> result = std::shared_ptr<PunctuationResult>(new PunctuationResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void PunctuationResult::SetValue(OmniPointer<Punctuation> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Punctuation> PunctuationResult::GetValue()
    {
        return this->value;
    }

    void PunctuationResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool PunctuationResult::GetResult()
    {
        return this->result;
    }

    void PunctuationListResult::SetValue(std::vector<OmniPointer<Punctuation>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Punctuation>> PunctuationListResult::GetValue()
    {
        return this->value;
    }

    void PunctuationListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool PunctuationListResult::GetResult()
    {
        return this->result;
    }

    void Punctuation::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Punctuation::UnParse()
    {
        return this->length_string->GetString();
    }

    void CommentCharacterParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
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
        return this->ParseSingleSave(index, result);
    }

    bool CommentCharacterParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<CommentCharacterResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool CommentCharacterParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<CommentCharacterResult> result = std::shared_ptr<CommentCharacterResult>(new CommentCharacterResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void CommentCharacterResult::SetValue(OmniPointer<CommentCharacter> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<CommentCharacter> CommentCharacterResult::GetValue()
    {
        return this->value;
    }

    void CommentCharacterResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool CommentCharacterResult::GetResult()
    {
        return this->result;
    }

    void CommentCharacterListResult::SetValue(std::vector<OmniPointer<CommentCharacter>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<CommentCharacter>> CommentCharacterListResult::GetValue()
    {
        return this->value;
    }

    void CommentCharacterListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool CommentCharacterListResult::GetResult()
    {
        return this->result;
    }

    void CommentCharacter::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string CommentCharacter::UnParse()
    {
        return this->length_string->GetString();
    }

    void CommentParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
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
        return this->ParseSingleSave(index, result);
    }

    bool CommentParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<CommentResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool CommentParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<CommentResult> result = std::shared_ptr<CommentResult>(new CommentResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void CommentResult::SetValue(OmniPointer<Comment> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Comment> CommentResult::GetValue()
    {
        return this->value;
    }

    void CommentResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool CommentResult::GetResult()
    {
        return this->result;
    }

    void CommentListResult::SetValue(std::vector<OmniPointer<Comment>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Comment>> CommentListResult::GetValue()
    {
        return this->value;
    }

    void CommentListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool CommentListResult::GetResult()
    {
        return this->result;
    }

    void Comment::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Comment::UnParse()
    {
        return this->length_string->GetString();
    }

    void LiteralParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
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
        return this->ParseSingleSave(index, result);
    }

    bool LiteralParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<LiteralResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool LiteralParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<LiteralResult> result = std::shared_ptr<LiteralResult>(new LiteralResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void LiteralResult::SetValue(OmniPointer<Literal> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Literal> LiteralResult::GetValue()
    {
        return this->value;
    }

    void LiteralResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool LiteralResult::GetResult()
    {
        return this->result;
    }

    void LiteralListResult::SetValue(std::vector<OmniPointer<Literal>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Literal>> LiteralListResult::GetValue()
    {
        return this->value;
    }

    void LiteralListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool LiteralListResult::GetResult()
    {
        return this->result;
    }

    void Literal::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Literal::UnParse()
    {
        return this->length_string->GetString();
    }

    void LiteralCharacterParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
        if (true && character_range_parser_instance->ParseSingle(index, 0x00, 0x21))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
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

        if (true && character_range_parser_instance->ParseSingle(index, 0x23, 0x5B))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
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

        if (true && character_range_parser_instance->ParseSingle(index, 0x5D, 0xFF))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
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
        return this->ParseSingleSave(index, result);
    }

    bool LiteralCharacterParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<LiteralCharacterResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool LiteralCharacterParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<LiteralCharacterResult> result = std::shared_ptr<LiteralCharacterResult>(new LiteralCharacterResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void LiteralCharacterResult::SetValue(OmniPointer<LiteralCharacter> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<LiteralCharacter> LiteralCharacterResult::GetValue()
    {
        return this->value;
    }

    void LiteralCharacterResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool LiteralCharacterResult::GetResult()
    {
        return this->result;
    }

    void LiteralCharacterListResult::SetValue(std::vector<OmniPointer<LiteralCharacter>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<LiteralCharacter>> LiteralCharacterListResult::GetValue()
    {
        return this->value;
    }

    void LiteralCharacterListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool LiteralCharacterListResult::GetResult()
    {
        return this->result;
    }

    void LiteralCharacter::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string LiteralCharacter::UnParse()
    {
        return this->length_string->GetString();
    }

    void HexDigitParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
        if (true && character_range_parser_instance->ParseSingle(index, 0x30, 0x39))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_range_parser_instance->ParseSingle(index, 0x41, 0x46))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
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
        return this->ParseSingleSave(index, result);
    }

    bool HexDigitParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<HexDigitResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool HexDigitParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<HexDigitResult> result = std::shared_ptr<HexDigitResult>(new HexDigitResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void HexDigitResult::SetValue(OmniPointer<HexDigit> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<HexDigit> HexDigitResult::GetValue()
    {
        return this->value;
    }

    void HexDigitResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool HexDigitResult::GetResult()
    {
        return this->result;
    }

    void HexDigitListResult::SetValue(std::vector<OmniPointer<HexDigit>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<HexDigit>> HexDigitListResult::GetValue()
    {
        return this->value;
    }

    void HexDigitListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool HexDigitListResult::GetResult()
    {
        return this->result;
    }

    void HexDigit::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string HexDigit::UnParse()
    {
        return this->length_string->GetString();
    }

    void WhitespaceParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
        if (true && character_range_parser_instance->ParseSingle(index, 0x00, 0x09))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_range_parser_instance->ParseSingle(index, 0x0B, 0x0C))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
            result->SetValue(instance);
            result->SetResult(true);
            return result->GetResult();
        }
        else
        {
            index->SetStart(index_start);
            index->SetLength(index_length);
        }

        if (true && character_range_parser_instance->ParseSingle(index, 0x0E, 0x20))
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
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
        return this->ParseSingleSave(index, result);
    }

    bool WhitespaceParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<WhitespaceResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool WhitespaceParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<WhitespaceResult> result = std::shared_ptr<WhitespaceResult>(new WhitespaceResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void WhitespaceResult::SetValue(OmniPointer<Whitespace> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Whitespace> WhitespaceResult::GetValue()
    {
        return this->value;
    }

    void WhitespaceResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool WhitespaceResult::GetResult()
    {
        return this->result;
    }

    void WhitespaceListResult::SetValue(std::vector<OmniPointer<Whitespace>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Whitespace>> WhitespaceListResult::GetValue()
    {
        return this->value;
    }

    void WhitespaceListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool WhitespaceListResult::GetResult()
    {
        return this->result;
    }

    void Whitespace::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Whitespace::UnParse()
    {
        return this->length_string->GetString();
    }

    void EolParser::SetParserNetwork(OmniPointer<ParserNetwork> input)
    {
        this->parser_network = input;
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
        OmniPointer<GrammarParser> grammar_parser_instance = this->parser_network->GetGrammarParser();
        OmniPointer<RuleParser> rule_parser_instance = this->parser_network->GetRuleParser();
        OmniPointer<ExpressionParser> expression_parser_instance = this->parser_network->GetExpressionParser();
        OmniPointer<TokenParser> token_parser_instance = this->parser_network->GetTokenParser();
        OmniPointer<SimpleTokenParser> simple_token_parser_instance = this->parser_network->GetSimpleTokenParser();
        OmniPointer<ModifierParser> modifier_parser_instance = this->parser_network->GetModifierParser();
        OmniPointer<CardinalityParser> cardinality_parser_instance = this->parser_network->GetCardinalityParser();
        OmniPointer<NameParser> name_parser_instance = this->parser_network->GetNameParser();
        OmniPointer<NameCharacterParser> name_character_parser_instance = this->parser_network->GetNameCharacterParser();
        OmniPointer<NumberParser> number_parser_instance = this->parser_network->GetNumberParser();
        OmniPointer<DigitParser> digit_parser_instance = this->parser_network->GetDigitParser();
        OmniPointer<PunctuationParser> punctuation_parser_instance = this->parser_network->GetPunctuationParser();
        OmniPointer<CommentCharacterParser> comment_character_parser_instance = this->parser_network->GetCommentCharacterParser();
        OmniPointer<CommentParser> comment_parser_instance = this->parser_network->GetCommentParser();
        OmniPointer<LiteralParser> literal_parser_instance = this->parser_network->GetLiteralParser();
        OmniPointer<LiteralCharacterParser> literal_character_parser_instance = this->parser_network->GetLiteralCharacterParser();
        OmniPointer<HexDigitParser> hex_digit_parser_instance = this->parser_network->GetHexDigitParser();
        OmniPointer<WhitespaceParser> whitespace_parser_instance = this->parser_network->GetWhitespaceParser();
        OmniPointer<EolParser> eol_parser_instance = this->parser_network->GetEolParser();
        OmniPointer<StringParser> string_parser_instance = this->parser_network->GetStringParser();
        OmniPointer<CharacterParser> character_parser_instance = this->parser_network->GetCharacterParser();
        OmniPointer<CharacterRangeParser> character_range_parser_instance = this->parser_network->GetCharacterRangeParser();
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

        if (true)
        {
            consumed_string->SetLength(index->GetStart() - index_start);
            instance->SetLengthString(consumed_string);
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
        return this->ParseSingleSave(index, result);
    }

    bool EolParser::ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<EolResult> result)
    {
        this->ParseSingleSave(index, result);
        result->SetResult(true);
        return true;
    }

    bool EolParser::ParseOptional(OmniPointer<LengthString> index)
    {
        OmniPointer<EolResult> result = std::shared_ptr<EolResult>(new EolResult());
        return this->ParseOptionalSave(index, result);
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
            this->ParseSingleSave(index, result);
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
        return this->ParseManySave(index, result, minimum, maximum);
    }

    void EolResult::SetValue(OmniPointer<Eol> new_value)
    {
        this->value = new_value;
    }

    OmniPointer<Eol> EolResult::GetValue()
    {
        return this->value;
    }

    void EolResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool EolResult::GetResult()
    {
        return this->result;
    }

    void EolListResult::SetValue(std::vector<OmniPointer<Eol>> new_value)
    {
        this->value = new_value;
    }

    std::vector<OmniPointer<Eol>> EolListResult::GetValue()
    {
        return this->value;
    }

    void EolListResult::SetResult(bool new_result)
    {
        this->result = new_result;
    }

    bool EolListResult::GetResult()
    {
        return this->result;
    }

    void Eol::SetLengthString(OmniPointer<LengthString> new_value)
    {
        this->length_string = std::shared_ptr<LengthString>(new LengthString());
        this->length_string->SetData(new_value->GetData());
        this->length_string->SetStart(new_value->GetStart());
        this->length_string->SetLength(new_value->GetLength());
    }

    std::string Eol::UnParse()
    {
        return this->length_string->GetString();
    }

};
};
};
};
