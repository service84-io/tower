#ifndef DSA_VENT_TOWER_DBNF_CTCODE_H
#define DSA_VENT_TOWER_DBNF_CTCODE_H


#include <cstring>
#include <list>
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>

#ifndef CTCODE_COMMON_FUNCTIONS_VERSION_1
#define CTCODE_COMMON_FUNCTIONS_VERSION_1
template<typename T>
class OmniPointer
{
public:
    OmniPointer() { value_raw = NULL; }
    OmniPointer(T* value) { value_raw = value; }
    OmniPointer(std::shared_ptr<T> value) { value_raw = NULL; value_shared = value; }

    operator bool()
    {
        if (value_raw) return true;
        return value_shared.get() != NULL;
    }
    T& operator*()
    {
        if (value_raw) return *value_raw;
        return *value_shared;
    }
    T* operator->()
    {
        if (value_raw) return value_raw;
        return value_shared.get();
    }
    T* raw()
    {
        if (value_raw) return value_raw;
        return value_shared.get();
    }

private:
    T* value_raw;
    std::shared_ptr<T> value_shared;
};

template<typename T>
inline std::vector<T*> UnwrapOmniList(std::vector<OmniPointer<T>> input) {
	std::vector<T*> result;
	for (typename std::vector<OmniPointer<T>>::iterator index = input.begin();index != input.end();index++) {
		result.push_back(index->raw());
	}
	return result;
};
template<typename T>
inline void ClearList(std::vector<T>& input) { input.clear(); };
template<typename T>
inline int Size(const std::vector<T>& input) { return input.size(); };
template<typename T>
inline T Element(const std::vector<T>& input, int element) { return input.at(element); };
template<typename T>
inline void Append(std::vector<T>& input, T element) { input.push_back(element); };
template<typename T>
inline void ClearMap(std::unordered_map<std::string, T>& input) { input.clear(); };
template<typename T>
inline void SetKV(std::unordered_map<std::string, T>& input, std::string key, T element)
{
    input.erase(key);
    input.insert(std::pair<std::string, T>(key, element));
}
template<typename T>
inline bool HasKV(const std::unordered_map<std::string, T>& input, std::string key)
{
    typename std::unordered_map<std::string, T>::iterator beginning = input.find(key);
    return beginning != input.end();
}
template<typename T>
inline T GetKV(const std::unordered_map<std::string, T>& input, std::string key) { return input.at(key); }
inline int Length(std::string input) { return (int)input.length(); };
inline std::string At(std::string input, int index) { return input.substr(index, 1); };
inline int IntAt(std::string input, int index) { return (input.at(index) + 256) % 256; };
inline std::string Concat(std::string left, std::string right) { return left + right; };
#endif

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
class StringParser;
class StringResult;
class StringListResult;
class String;
class CharacterParser;
class CharacterResult;
class CharacterListResult;
class Character;
class CharacterRangeParser;
class CharacterRangeResult;
class CharacterRangeListResult;
class CharacterRange;
class ParserNetwork;
class DBNFOmniType;
class DBNFOmniTypeResult;
class DBNFOmniTypeListResult;
class LengthString;
class GrammarParser;
class GrammarResult;
class GrammarListResult;
class Grammar;
class RuleParser;
class RuleResult;
class RuleListResult;
class Rule;
class ExpressionParser;
class ExpressionResult;
class ExpressionListResult;
class Expression;
class TokenParser;
class TokenResult;
class TokenListResult;
class Token;
class SimpleTokenParser;
class SimpleTokenResult;
class SimpleTokenListResult;
class SimpleToken;
class ModifierParser;
class ModifierResult;
class ModifierListResult;
class Modifier;
class CardinalityParser;
class CardinalityResult;
class CardinalityListResult;
class Cardinality;
class NameParser;
class NameResult;
class NameListResult;
class Name;
class NameCharacterParser;
class NameCharacterResult;
class NameCharacterListResult;
class NameCharacter;
class NumberParser;
class NumberResult;
class NumberListResult;
class Number;
class DigitParser;
class DigitResult;
class DigitListResult;
class Digit;
class PunctuationParser;
class PunctuationResult;
class PunctuationListResult;
class Punctuation;
class CommentCharacterParser;
class CommentCharacterResult;
class CommentCharacterListResult;
class CommentCharacter;
class CommentParser;
class CommentResult;
class CommentListResult;
class Comment;
class LiteralParser;
class LiteralResult;
class LiteralListResult;
class Literal;
class LiteralCharacterParser;
class LiteralCharacterResult;
class LiteralCharacterListResult;
class LiteralCharacter;
class HexDigitParser;
class HexDigitResult;
class HexDigitListResult;
class HexDigit;
class WhitespaceParser;
class WhitespaceResult;
class WhitespaceListResult;
class Whitespace;
class EolParser;
class EolResult;
class EolListResult;
class Eol;


class StringParser
{
public:
    inline StringParser() {};
    inline ~StringParser() {};

    bool ParseSingleSave(OmniPointer<LengthString> index, std::string value, OmniPointer<StringResult> result);
    bool ParseSingle(OmniPointer<LengthString> index, std::string value);
};

class StringResult
{
public:
    inline StringResult() {};
    inline ~StringResult() {};

    void SetValue(OmniPointer<String> new_value);
    OmniPointer<String> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<String> value;
    bool result;
};

class StringListResult
{
public:
    inline StringListResult() {};
    inline ~StringListResult() {};

    void SetValue(std::vector<OmniPointer<String>> new_value);
    std::vector<OmniPointer<String>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<String>> value;
    bool result;
};

class String
{
public:
    inline String() {};
    inline ~String() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class CharacterParser
{
public:
    inline CharacterParser() {};
    inline ~CharacterParser() {};

    bool ParseSingle(OmniPointer<LengthString> index, int value);
};

class CharacterResult
{
public:
    inline CharacterResult() {};
    inline ~CharacterResult() {};

    void SetValue(OmniPointer<Character> new_value);
    OmniPointer<Character> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Character> value;
    bool result;
};

class CharacterListResult
{
public:
    inline CharacterListResult() {};
    inline ~CharacterListResult() {};

    void SetValue(std::vector<OmniPointer<Character>> new_value);
    std::vector<OmniPointer<Character>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Character>> value;
    bool result;
};

class Character
{
public:
    inline Character() {};
    inline ~Character() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class CharacterRangeParser
{
public:
    inline CharacterRangeParser() {};
    inline ~CharacterRangeParser() {};

    bool ParseSingle(OmniPointer<LengthString> index, int low_value, int high_value);
};

class CharacterRangeResult
{
public:
    inline CharacterRangeResult() {};
    inline ~CharacterRangeResult() {};

    void SetValue(OmniPointer<CharacterRange> new_value);
    OmniPointer<CharacterRange> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<CharacterRange> value;
    bool result;
};

class CharacterRangeListResult
{
public:
    inline CharacterRangeListResult() {};
    inline ~CharacterRangeListResult() {};

    void SetValue(std::vector<OmniPointer<CharacterRange>> new_value);
    std::vector<OmniPointer<CharacterRange>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<CharacterRange>> value;
    bool result;
};

class CharacterRange
{
public:
    inline CharacterRange() {};
    inline ~CharacterRange() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class ParserNetwork
{
public:
    inline ParserNetwork() {};
    inline ~ParserNetwork() {};

    OmniPointer<GrammarParser> GetGrammarParser();
    OmniPointer<RuleParser> GetRuleParser();
    OmniPointer<ExpressionParser> GetExpressionParser();
    OmniPointer<TokenParser> GetTokenParser();
    OmniPointer<SimpleTokenParser> GetSimpleTokenParser();
    OmniPointer<ModifierParser> GetModifierParser();
    OmniPointer<CardinalityParser> GetCardinalityParser();
    OmniPointer<NameParser> GetNameParser();
    OmniPointer<NameCharacterParser> GetNameCharacterParser();
    OmniPointer<NumberParser> GetNumberParser();
    OmniPointer<DigitParser> GetDigitParser();
    OmniPointer<PunctuationParser> GetPunctuationParser();
    OmniPointer<CommentCharacterParser> GetCommentCharacterParser();
    OmniPointer<CommentParser> GetCommentParser();
    OmniPointer<LiteralParser> GetLiteralParser();
    OmniPointer<LiteralCharacterParser> GetLiteralCharacterParser();
    OmniPointer<HexDigitParser> GetHexDigitParser();
    OmniPointer<WhitespaceParser> GetWhitespaceParser();
    OmniPointer<EolParser> GetEolParser();
    OmniPointer<StringParser> GetStringParser();
    OmniPointer<CharacterParser> GetCharacterParser();
    OmniPointer<CharacterRangeParser> GetCharacterRangeParser();
    void Initialize();

private:
    OmniPointer<GrammarParser> grammar_parser_field;
    OmniPointer<RuleParser> rule_parser_field;
    OmniPointer<ExpressionParser> expression_parser_field;
    OmniPointer<TokenParser> token_parser_field;
    OmniPointer<SimpleTokenParser> simple_token_parser_field;
    OmniPointer<ModifierParser> modifier_parser_field;
    OmniPointer<CardinalityParser> cardinality_parser_field;
    OmniPointer<NameParser> name_parser_field;
    OmniPointer<NameCharacterParser> name_character_parser_field;
    OmniPointer<NumberParser> number_parser_field;
    OmniPointer<DigitParser> digit_parser_field;
    OmniPointer<PunctuationParser> punctuation_parser_field;
    OmniPointer<CommentCharacterParser> comment_character_parser_field;
    OmniPointer<CommentParser> comment_parser_field;
    OmniPointer<LiteralParser> literal_parser_field;
    OmniPointer<LiteralCharacterParser> literal_character_parser_field;
    OmniPointer<HexDigitParser> hex_digit_parser_field;
    OmniPointer<WhitespaceParser> whitespace_parser_field;
    OmniPointer<EolParser> eol_parser_field;
    OmniPointer<StringParser> string_parser_field;
    OmniPointer<CharacterParser> character_parser_field;
    OmniPointer<CharacterRangeParser> character_range_parser_field;
};

class DBNFOmniType
{
public:
    inline DBNFOmniType() {};
    inline ~DBNFOmniType() {};

    void SetGrammar(OmniPointer<Grammar> input_value);
    OmniPointer<Grammar> GetGrammar();
    void SetRule(OmniPointer<Rule> input_value);
    OmniPointer<Rule> GetRule();
    void SetExpression(OmniPointer<Expression> input_value);
    OmniPointer<Expression> GetExpression();
    void SetToken(OmniPointer<Token> input_value);
    OmniPointer<Token> GetToken();
    void SetSimpleToken(OmniPointer<SimpleToken> input_value);
    OmniPointer<SimpleToken> GetSimpleToken();
    void SetModifier(OmniPointer<Modifier> input_value);
    OmniPointer<Modifier> GetModifier();
    void SetCardinality(OmniPointer<Cardinality> input_value);
    OmniPointer<Cardinality> GetCardinality();
    void SetName(OmniPointer<Name> input_value);
    OmniPointer<Name> GetName();
    void SetNameCharacter(OmniPointer<NameCharacter> input_value);
    OmniPointer<NameCharacter> GetNameCharacter();
    void SetNumber(OmniPointer<Number> input_value);
    OmniPointer<Number> GetNumber();
    void SetDigit(OmniPointer<Digit> input_value);
    OmniPointer<Digit> GetDigit();
    void SetPunctuation(OmniPointer<Punctuation> input_value);
    OmniPointer<Punctuation> GetPunctuation();
    void SetCommentCharacter(OmniPointer<CommentCharacter> input_value);
    OmniPointer<CommentCharacter> GetCommentCharacter();
    void SetComment(OmniPointer<Comment> input_value);
    OmniPointer<Comment> GetComment();
    void SetLiteral(OmniPointer<Literal> input_value);
    OmniPointer<Literal> GetLiteral();
    void SetLiteralCharacter(OmniPointer<LiteralCharacter> input_value);
    OmniPointer<LiteralCharacter> GetLiteralCharacter();
    void SetHexDigit(OmniPointer<HexDigit> input_value);
    OmniPointer<HexDigit> GetHexDigit();
    void SetWhitespace(OmniPointer<Whitespace> input_value);
    OmniPointer<Whitespace> GetWhitespace();
    void SetEol(OmniPointer<Eol> input_value);
    OmniPointer<Eol> GetEol();

private:
    OmniPointer<Grammar> grammar_field;
    OmniPointer<Rule> rule_field;
    OmniPointer<Expression> expression_field;
    OmniPointer<Token> token_field;
    OmniPointer<SimpleToken> simple_token_field;
    OmniPointer<Modifier> modifier_field;
    OmniPointer<Cardinality> cardinality_field;
    OmniPointer<Name> name_field;
    OmniPointer<NameCharacter> name_character_field;
    OmniPointer<Number> number_field;
    OmniPointer<Digit> digit_field;
    OmniPointer<Punctuation> punctuation_field;
    OmniPointer<CommentCharacter> comment_character_field;
    OmniPointer<Comment> comment_field;
    OmniPointer<Literal> literal_field;
    OmniPointer<LiteralCharacter> literal_character_field;
    OmniPointer<HexDigit> hex_digit_field;
    OmniPointer<Whitespace> whitespace_field;
    OmniPointer<Eol> eol_field;
};

class DBNFOmniTypeResult
{
public:
    inline DBNFOmniTypeResult() {};
    inline ~DBNFOmniTypeResult() {};

    void SetValue(OmniPointer<DBNFOmniType> new_value);
    OmniPointer<DBNFOmniType> GetValue();
    void SetResult(bool new_result);
    bool GetResult();
    void SetGrammar(OmniPointer<Grammar> input_value);
    void SetRule(OmniPointer<Rule> input_value);
    void SetExpression(OmniPointer<Expression> input_value);
    void SetToken(OmniPointer<Token> input_value);
    void SetSimpleToken(OmniPointer<SimpleToken> input_value);
    void SetModifier(OmniPointer<Modifier> input_value);
    void SetCardinality(OmniPointer<Cardinality> input_value);
    void SetName(OmniPointer<Name> input_value);
    void SetNameCharacter(OmniPointer<NameCharacter> input_value);
    void SetNumber(OmniPointer<Number> input_value);
    void SetDigit(OmniPointer<Digit> input_value);
    void SetPunctuation(OmniPointer<Punctuation> input_value);
    void SetCommentCharacter(OmniPointer<CommentCharacter> input_value);
    void SetComment(OmniPointer<Comment> input_value);
    void SetLiteral(OmniPointer<Literal> input_value);
    void SetLiteralCharacter(OmniPointer<LiteralCharacter> input_value);
    void SetHexDigit(OmniPointer<HexDigit> input_value);
    void SetWhitespace(OmniPointer<Whitespace> input_value);
    void SetEol(OmniPointer<Eol> input_value);

private:
    OmniPointer<DBNFOmniType> value;
    bool result;
};

class DBNFOmniTypeListResult
{
public:
    inline DBNFOmniTypeListResult() {};
    inline ~DBNFOmniTypeListResult() {};

    void SetValue(std::vector<OmniPointer<DBNFOmniType>> new_value);
    std::vector<OmniPointer<DBNFOmniType>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();
    void SetGrammar(std::vector<OmniPointer<Grammar>> input_value);
    void SetRule(std::vector<OmniPointer<Rule>> input_value);
    void SetExpression(std::vector<OmniPointer<Expression>> input_value);
    void SetToken(std::vector<OmniPointer<Token>> input_value);
    void SetSimpleToken(std::vector<OmniPointer<SimpleToken>> input_value);
    void SetModifier(std::vector<OmniPointer<Modifier>> input_value);
    void SetCardinality(std::vector<OmniPointer<Cardinality>> input_value);
    void SetName(std::vector<OmniPointer<Name>> input_value);
    void SetNameCharacter(std::vector<OmniPointer<NameCharacter>> input_value);
    void SetNumber(std::vector<OmniPointer<Number>> input_value);
    void SetDigit(std::vector<OmniPointer<Digit>> input_value);
    void SetPunctuation(std::vector<OmniPointer<Punctuation>> input_value);
    void SetCommentCharacter(std::vector<OmniPointer<CommentCharacter>> input_value);
    void SetComment(std::vector<OmniPointer<Comment>> input_value);
    void SetLiteral(std::vector<OmniPointer<Literal>> input_value);
    void SetLiteralCharacter(std::vector<OmniPointer<LiteralCharacter>> input_value);
    void SetHexDigit(std::vector<OmniPointer<HexDigit>> input_value);
    void SetWhitespace(std::vector<OmniPointer<Whitespace>> input_value);
    void SetEol(std::vector<OmniPointer<Eol>> input_value);

private:
    std::vector<OmniPointer<DBNFOmniType>> value;
    bool result;
};

class LengthString
{
public:
    inline LengthString() {};
    inline ~LengthString() {};

    void SetData(std::string new_data);
    std::string GetData();
    void SetStart(int new_start);
    int GetStart();
    void SetLength(int new_length);
    int GetLength();
    std::string GetString();

private:
    std::string data;
    int start;
    int length;
};

class GrammarParser
{
public:
    inline GrammarParser() {};
    inline ~GrammarParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<GrammarResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<GrammarResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<GrammarListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class GrammarResult
{
public:
    inline GrammarResult() {};
    inline ~GrammarResult() {};

    void SetValue(OmniPointer<Grammar> new_value);
    OmniPointer<Grammar> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Grammar> value;
    bool result;
};

class GrammarListResult
{
public:
    inline GrammarListResult() {};
    inline ~GrammarListResult() {};

    void SetValue(std::vector<OmniPointer<Grammar>> new_value);
    std::vector<OmniPointer<Grammar>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Grammar>> value;
    bool result;
};

class Grammar
{
public:
    inline Grammar() {};
    inline ~Grammar() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();
    void SetRules(std::vector<OmniPointer<Rule>> input_value);
    std::vector<OmniPointer<Rule>> GetRules();

private:
    OmniPointer<LengthString> length_string;
    std::vector<OmniPointer<Rule>> rules_field;
};

class RuleParser
{
public:
    inline RuleParser() {};
    inline ~RuleParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<RuleResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<RuleResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<RuleListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class RuleResult
{
public:
    inline RuleResult() {};
    inline ~RuleResult() {};

    void SetValue(OmniPointer<Rule> new_value);
    OmniPointer<Rule> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Rule> value;
    bool result;
};

class RuleListResult
{
public:
    inline RuleListResult() {};
    inline ~RuleListResult() {};

    void SetValue(std::vector<OmniPointer<Rule>> new_value);
    std::vector<OmniPointer<Rule>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Rule>> value;
    bool result;
};

class Rule
{
public:
    inline Rule() {};
    inline ~Rule() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();
    void SetExpressions(std::vector<OmniPointer<Expression>> input_value);
    std::vector<OmniPointer<Expression>> GetExpressions();
    void SetName(OmniPointer<Name> input_value);
    OmniPointer<Name> GetName();

private:
    OmniPointer<LengthString> length_string;
    std::vector<OmniPointer<Expression>> expressions_field;
    OmniPointer<Name> name_field;
};

class ExpressionParser
{
public:
    inline ExpressionParser() {};
    inline ~ExpressionParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<ExpressionResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<ExpressionResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<ExpressionListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class ExpressionResult
{
public:
    inline ExpressionResult() {};
    inline ~ExpressionResult() {};

    void SetValue(OmniPointer<Expression> new_value);
    OmniPointer<Expression> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Expression> value;
    bool result;
};

class ExpressionListResult
{
public:
    inline ExpressionListResult() {};
    inline ~ExpressionListResult() {};

    void SetValue(std::vector<OmniPointer<Expression>> new_value);
    std::vector<OmniPointer<Expression>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Expression>> value;
    bool result;
};

class Expression
{
public:
    inline Expression() {};
    inline ~Expression() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();
    void SetExpressionDiscriminator(OmniPointer<String> input_value);
    OmniPointer<String> GetExpressionDiscriminator();
    void SetTokenSequence(std::vector<OmniPointer<Token>> input_value);
    std::vector<OmniPointer<Token>> GetTokenSequence();

private:
    OmniPointer<LengthString> length_string;
    OmniPointer<String> expression_discriminator_field;
    std::vector<OmniPointer<Token>> token_sequence_field;
};

class TokenParser
{
public:
    inline TokenParser() {};
    inline ~TokenParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<TokenResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<TokenResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<TokenListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class TokenResult
{
public:
    inline TokenResult() {};
    inline ~TokenResult() {};

    void SetValue(OmniPointer<Token> new_value);
    OmniPointer<Token> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Token> value;
    bool result;
};

class TokenListResult
{
public:
    inline TokenListResult() {};
    inline ~TokenListResult() {};

    void SetValue(std::vector<OmniPointer<Token>> new_value);
    std::vector<OmniPointer<Token>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Token>> value;
    bool result;
};

class Token
{
public:
    inline Token() {};
    inline ~Token() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();
    void SetModifier(OmniPointer<Modifier> input_value);
    OmniPointer<Modifier> GetModifier();
    void SetName(OmniPointer<Name> input_value);
    OmniPointer<Name> GetName();
    void SetValue(OmniPointer<SimpleToken> input_value);
    OmniPointer<SimpleToken> GetValue();

private:
    OmniPointer<LengthString> length_string;
    OmniPointer<Modifier> modifier_field;
    OmniPointer<Name> name_field;
    OmniPointer<SimpleToken> value_field;
};

class SimpleTokenParser
{
public:
    inline SimpleTokenParser() {};
    inline ~SimpleTokenParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<SimpleTokenResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<SimpleTokenResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<SimpleTokenListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class SimpleTokenResult
{
public:
    inline SimpleTokenResult() {};
    inline ~SimpleTokenResult() {};

    void SetValue(OmniPointer<SimpleToken> new_value);
    OmniPointer<SimpleToken> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<SimpleToken> value;
    bool result;
};

class SimpleTokenListResult
{
public:
    inline SimpleTokenListResult() {};
    inline ~SimpleTokenListResult() {};

    void SetValue(std::vector<OmniPointer<SimpleToken>> new_value);
    std::vector<OmniPointer<SimpleToken>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<SimpleToken>> value;
    bool result;
};

class SimpleToken
{
public:
    inline SimpleToken() {};
    inline ~SimpleToken() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();
    void SetHigh(OmniPointer<HexDigit> input_value);
    OmniPointer<HexDigit> GetHigh();
    void SetHighHigh(OmniPointer<HexDigit> input_value);
    OmniPointer<HexDigit> GetHighHigh();
    void SetHighLow(OmniPointer<HexDigit> input_value);
    OmniPointer<HexDigit> GetHighLow();
    void SetLiteral(OmniPointer<Literal> input_value);
    OmniPointer<Literal> GetLiteral();
    void SetLow(OmniPointer<HexDigit> input_value);
    OmniPointer<HexDigit> GetLow();
    void SetLowHigh(OmniPointer<HexDigit> input_value);
    OmniPointer<HexDigit> GetLowHigh();
    void SetLowLow(OmniPointer<HexDigit> input_value);
    OmniPointer<HexDigit> GetLowLow();
    void SetToken(OmniPointer<Name> input_value);
    OmniPointer<Name> GetToken();

private:
    OmniPointer<LengthString> length_string;
    OmniPointer<HexDigit> high_field;
    OmniPointer<HexDigit> high_high_field;
    OmniPointer<HexDigit> high_low_field;
    OmniPointer<Literal> literal_field;
    OmniPointer<HexDigit> low_field;
    OmniPointer<HexDigit> low_high_field;
    OmniPointer<HexDigit> low_low_field;
    OmniPointer<Name> token_field;
};

class ModifierParser
{
public:
    inline ModifierParser() {};
    inline ~ModifierParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<ModifierResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<ModifierResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<ModifierListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class ModifierResult
{
public:
    inline ModifierResult() {};
    inline ~ModifierResult() {};

    void SetValue(OmniPointer<Modifier> new_value);
    OmniPointer<Modifier> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Modifier> value;
    bool result;
};

class ModifierListResult
{
public:
    inline ModifierListResult() {};
    inline ~ModifierListResult() {};

    void SetValue(std::vector<OmniPointer<Modifier>> new_value);
    std::vector<OmniPointer<Modifier>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Modifier>> value;
    bool result;
};

class Modifier
{
public:
    inline Modifier() {};
    inline ~Modifier() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();
    void SetCardinality(OmniPointer<Cardinality> input_value);
    OmniPointer<Cardinality> GetCardinality();

private:
    OmniPointer<LengthString> length_string;
    OmniPointer<Cardinality> cardinality_field;
};

class CardinalityParser
{
public:
    inline CardinalityParser() {};
    inline ~CardinalityParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<CardinalityResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<CardinalityResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<CardinalityListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class CardinalityResult
{
public:
    inline CardinalityResult() {};
    inline ~CardinalityResult() {};

    void SetValue(OmniPointer<Cardinality> new_value);
    OmniPointer<Cardinality> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Cardinality> value;
    bool result;
};

class CardinalityListResult
{
public:
    inline CardinalityListResult() {};
    inline ~CardinalityListResult() {};

    void SetValue(std::vector<OmniPointer<Cardinality>> new_value);
    std::vector<OmniPointer<Cardinality>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Cardinality>> value;
    bool result;
};

class Cardinality
{
public:
    inline Cardinality() {};
    inline ~Cardinality() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();
    void SetCount(OmniPointer<Number> input_value);
    OmniPointer<Number> GetCount();
    void SetMaximum(OmniPointer<Number> input_value);
    OmniPointer<Number> GetMaximum();
    void SetMinimum(OmniPointer<Number> input_value);
    OmniPointer<Number> GetMinimum();

private:
    OmniPointer<LengthString> length_string;
    OmniPointer<Number> count_field;
    OmniPointer<Number> maximum_field;
    OmniPointer<Number> minimum_field;
};

class NameParser
{
public:
    inline NameParser() {};
    inline ~NameParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<NameResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<NameResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<NameListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class NameResult
{
public:
    inline NameResult() {};
    inline ~NameResult() {};

    void SetValue(OmniPointer<Name> new_value);
    OmniPointer<Name> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Name> value;
    bool result;
};

class NameListResult
{
public:
    inline NameListResult() {};
    inline ~NameListResult() {};

    void SetValue(std::vector<OmniPointer<Name>> new_value);
    std::vector<OmniPointer<Name>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Name>> value;
    bool result;
};

class Name
{
public:
    inline Name() {};
    inline ~Name() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class NameCharacterParser
{
public:
    inline NameCharacterParser() {};
    inline ~NameCharacterParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<NameCharacterResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<NameCharacterResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<NameCharacterListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class NameCharacterResult
{
public:
    inline NameCharacterResult() {};
    inline ~NameCharacterResult() {};

    void SetValue(OmniPointer<NameCharacter> new_value);
    OmniPointer<NameCharacter> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<NameCharacter> value;
    bool result;
};

class NameCharacterListResult
{
public:
    inline NameCharacterListResult() {};
    inline ~NameCharacterListResult() {};

    void SetValue(std::vector<OmniPointer<NameCharacter>> new_value);
    std::vector<OmniPointer<NameCharacter>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<NameCharacter>> value;
    bool result;
};

class NameCharacter
{
public:
    inline NameCharacter() {};
    inline ~NameCharacter() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class NumberParser
{
public:
    inline NumberParser() {};
    inline ~NumberParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<NumberResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<NumberResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<NumberListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class NumberResult
{
public:
    inline NumberResult() {};
    inline ~NumberResult() {};

    void SetValue(OmniPointer<Number> new_value);
    OmniPointer<Number> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Number> value;
    bool result;
};

class NumberListResult
{
public:
    inline NumberListResult() {};
    inline ~NumberListResult() {};

    void SetValue(std::vector<OmniPointer<Number>> new_value);
    std::vector<OmniPointer<Number>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Number>> value;
    bool result;
};

class Number
{
public:
    inline Number() {};
    inline ~Number() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class DigitParser
{
public:
    inline DigitParser() {};
    inline ~DigitParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<DigitResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<DigitResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<DigitListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class DigitResult
{
public:
    inline DigitResult() {};
    inline ~DigitResult() {};

    void SetValue(OmniPointer<Digit> new_value);
    OmniPointer<Digit> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Digit> value;
    bool result;
};

class DigitListResult
{
public:
    inline DigitListResult() {};
    inline ~DigitListResult() {};

    void SetValue(std::vector<OmniPointer<Digit>> new_value);
    std::vector<OmniPointer<Digit>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Digit>> value;
    bool result;
};

class Digit
{
public:
    inline Digit() {};
    inline ~Digit() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class PunctuationParser
{
public:
    inline PunctuationParser() {};
    inline ~PunctuationParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<PunctuationResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<PunctuationResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<PunctuationListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class PunctuationResult
{
public:
    inline PunctuationResult() {};
    inline ~PunctuationResult() {};

    void SetValue(OmniPointer<Punctuation> new_value);
    OmniPointer<Punctuation> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Punctuation> value;
    bool result;
};

class PunctuationListResult
{
public:
    inline PunctuationListResult() {};
    inline ~PunctuationListResult() {};

    void SetValue(std::vector<OmniPointer<Punctuation>> new_value);
    std::vector<OmniPointer<Punctuation>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Punctuation>> value;
    bool result;
};

class Punctuation
{
public:
    inline Punctuation() {};
    inline ~Punctuation() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class CommentCharacterParser
{
public:
    inline CommentCharacterParser() {};
    inline ~CommentCharacterParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<CommentCharacterResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<CommentCharacterResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<CommentCharacterListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class CommentCharacterResult
{
public:
    inline CommentCharacterResult() {};
    inline ~CommentCharacterResult() {};

    void SetValue(OmniPointer<CommentCharacter> new_value);
    OmniPointer<CommentCharacter> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<CommentCharacter> value;
    bool result;
};

class CommentCharacterListResult
{
public:
    inline CommentCharacterListResult() {};
    inline ~CommentCharacterListResult() {};

    void SetValue(std::vector<OmniPointer<CommentCharacter>> new_value);
    std::vector<OmniPointer<CommentCharacter>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<CommentCharacter>> value;
    bool result;
};

class CommentCharacter
{
public:
    inline CommentCharacter() {};
    inline ~CommentCharacter() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class CommentParser
{
public:
    inline CommentParser() {};
    inline ~CommentParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<CommentResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<CommentResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<CommentListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class CommentResult
{
public:
    inline CommentResult() {};
    inline ~CommentResult() {};

    void SetValue(OmniPointer<Comment> new_value);
    OmniPointer<Comment> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Comment> value;
    bool result;
};

class CommentListResult
{
public:
    inline CommentListResult() {};
    inline ~CommentListResult() {};

    void SetValue(std::vector<OmniPointer<Comment>> new_value);
    std::vector<OmniPointer<Comment>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Comment>> value;
    bool result;
};

class Comment
{
public:
    inline Comment() {};
    inline ~Comment() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class LiteralParser
{
public:
    inline LiteralParser() {};
    inline ~LiteralParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<LiteralResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<LiteralResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<LiteralListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class LiteralResult
{
public:
    inline LiteralResult() {};
    inline ~LiteralResult() {};

    void SetValue(OmniPointer<Literal> new_value);
    OmniPointer<Literal> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Literal> value;
    bool result;
};

class LiteralListResult
{
public:
    inline LiteralListResult() {};
    inline ~LiteralListResult() {};

    void SetValue(std::vector<OmniPointer<Literal>> new_value);
    std::vector<OmniPointer<Literal>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Literal>> value;
    bool result;
};

class Literal
{
public:
    inline Literal() {};
    inline ~Literal() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class LiteralCharacterParser
{
public:
    inline LiteralCharacterParser() {};
    inline ~LiteralCharacterParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<LiteralCharacterResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<LiteralCharacterResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<LiteralCharacterListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class LiteralCharacterResult
{
public:
    inline LiteralCharacterResult() {};
    inline ~LiteralCharacterResult() {};

    void SetValue(OmniPointer<LiteralCharacter> new_value);
    OmniPointer<LiteralCharacter> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<LiteralCharacter> value;
    bool result;
};

class LiteralCharacterListResult
{
public:
    inline LiteralCharacterListResult() {};
    inline ~LiteralCharacterListResult() {};

    void SetValue(std::vector<OmniPointer<LiteralCharacter>> new_value);
    std::vector<OmniPointer<LiteralCharacter>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<LiteralCharacter>> value;
    bool result;
};

class LiteralCharacter
{
public:
    inline LiteralCharacter() {};
    inline ~LiteralCharacter() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class HexDigitParser
{
public:
    inline HexDigitParser() {};
    inline ~HexDigitParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<HexDigitResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<HexDigitResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<HexDigitListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class HexDigitResult
{
public:
    inline HexDigitResult() {};
    inline ~HexDigitResult() {};

    void SetValue(OmniPointer<HexDigit> new_value);
    OmniPointer<HexDigit> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<HexDigit> value;
    bool result;
};

class HexDigitListResult
{
public:
    inline HexDigitListResult() {};
    inline ~HexDigitListResult() {};

    void SetValue(std::vector<OmniPointer<HexDigit>> new_value);
    std::vector<OmniPointer<HexDigit>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<HexDigit>> value;
    bool result;
};

class HexDigit
{
public:
    inline HexDigit() {};
    inline ~HexDigit() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class WhitespaceParser
{
public:
    inline WhitespaceParser() {};
    inline ~WhitespaceParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<WhitespaceResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<WhitespaceResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<WhitespaceListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class WhitespaceResult
{
public:
    inline WhitespaceResult() {};
    inline ~WhitespaceResult() {};

    void SetValue(OmniPointer<Whitespace> new_value);
    OmniPointer<Whitespace> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Whitespace> value;
    bool result;
};

class WhitespaceListResult
{
public:
    inline WhitespaceListResult() {};
    inline ~WhitespaceListResult() {};

    void SetValue(std::vector<OmniPointer<Whitespace>> new_value);
    std::vector<OmniPointer<Whitespace>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Whitespace>> value;
    bool result;
};

class Whitespace
{
public:
    inline Whitespace() {};
    inline ~Whitespace() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};

class EolParser
{
public:
    inline EolParser() {};
    inline ~EolParser() {};

    void SetParserNetwork(OmniPointer<ParserNetwork> input);
    bool ParseSingleSave(OmniPointer<LengthString> index, OmniPointer<EolResult> result);
    bool ParseSingle(OmniPointer<LengthString> index);
    bool ParseOptionalSave(OmniPointer<LengthString> index, OmniPointer<EolResult> result);
    bool ParseOptional(OmniPointer<LengthString> index);
    bool ParseManySave(OmniPointer<LengthString> index, OmniPointer<EolListResult> list_result, int minimum, int maximum);
    bool ParseMany(OmniPointer<LengthString> index, int minimum, int maximum);

private:
    OmniPointer<ParserNetwork> parser_network;
};

class EolResult
{
public:
    inline EolResult() {};
    inline ~EolResult() {};

    void SetValue(OmniPointer<Eol> new_value);
    OmniPointer<Eol> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    OmniPointer<Eol> value;
    bool result;
};

class EolListResult
{
public:
    inline EolListResult() {};
    inline ~EolListResult() {};

    void SetValue(std::vector<OmniPointer<Eol>> new_value);
    std::vector<OmniPointer<Eol>> GetValue();
    void SetResult(bool new_result);
    bool GetResult();

private:
    std::vector<OmniPointer<Eol>> value;
    bool result;
};

class Eol
{
public:
    inline Eol() {};
    inline ~Eol() {};

    void SetLengthString(OmniPointer<LengthString> new_value);
    std::string UnParse();

private:
    OmniPointer<LengthString> length_string;
};
};
};
};
};
};

#endif
