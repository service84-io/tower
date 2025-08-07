#ifndef DSA_VENT_TOWER_DBNF_H
#define DSA_VENT_TOWER_DBNF_H

#include <cstring>
#include <list>
#include <string>
#include <vector>

namespace dsa
{
namespace vent
{
namespace tower
{
namespace dbnf
{
class Node;
class String;
class Grammar;
class Rule;
class Expression;
class Token;
class SimpleToken;
class Modifier;
class Cardinality;
class Name;
class NameCharacter;
class Number;
class Digit;
class Punctuation;
class CommentCharacter;
class Comment;
class Literal;
class LiteralCharacter;
class HexDigit;
class Whitespace;
class Eol;

struct LengthString
{
    const char* data;
    size_t length;
};

class Node
{
public:
    Node();
    virtual ~Node();

    std::string UnParse();
    dsa::vent::tower::dbnf::LengthString UnParseLString();
    std::list<dsa::vent::tower::dbnf::Node*> GetChildren();

protected:
    void SetString(dsa::vent::tower::dbnf::LengthString data);
    void SetChildren(std::list<dsa::vent::tower::dbnf::Node*> children);

private:
    dsa::vent::tower::dbnf::LengthString data_;
    std::list<dsa::vent::tower::dbnf::Node*> children_;
};

template<class T>
class List : public dsa::vent::tower::dbnf::Node
{
public:
    List()
    {
    }
    virtual ~List()
    {
    }

    virtual std::list<T*> GetList()
    {
        return list_;
    }

    virtual std::vector<T*> GetVector()
    {
        return {list_.begin(), list_.end()};
    }

protected:
    std::list<T*> list_;
};

class String : public dsa::vent::tower::dbnf::Node
{
public:
    String(dsa::vent::tower::dbnf::LengthString data);
    ~String();
};

typedef List<Grammar> GrammarList;

class Grammar : public dsa::vent::tower::dbnf::Node
{
public:
    Grammar();
    ~Grammar();

    static dsa::vent::tower::dbnf::Grammar* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Grammar* Parse(dsa::vent::tower::dbnf::LengthString& index);

    List<dsa::vent::tower::dbnf::Rule>* GetRules();

private:
    List<dsa::vent::tower::dbnf::Rule>* rules_;
};

typedef List<Rule> RuleList;

class Rule : public dsa::vent::tower::dbnf::Node
{
public:
    Rule();
    ~Rule();

    static dsa::vent::tower::dbnf::Rule* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Rule* Parse(dsa::vent::tower::dbnf::LengthString& index);

    List<dsa::vent::tower::dbnf::Expression>* GetExpressions();
    dsa::vent::tower::dbnf::Name* GetName();

private:
    List<dsa::vent::tower::dbnf::Expression>* expressions_;
    dsa::vent::tower::dbnf::Name* name_;
};

typedef List<Expression> ExpressionList;

class Expression : public dsa::vent::tower::dbnf::Node
{
public:
    Expression();
    ~Expression();

    static dsa::vent::tower::dbnf::Expression* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Expression* Parse(dsa::vent::tower::dbnf::LengthString& index);

    dsa::vent::tower::dbnf::String* GetExpressionDiscriminator();
    List<dsa::vent::tower::dbnf::Token>* GetTokenSequence();

private:
    dsa::vent::tower::dbnf::String* expression_discriminator_;
    List<dsa::vent::tower::dbnf::Token>* token_sequence_;
};

typedef List<Token> TokenList;

class Token : public dsa::vent::tower::dbnf::Node
{
public:
    Token();
    ~Token();

    static dsa::vent::tower::dbnf::Token* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Token* Parse(dsa::vent::tower::dbnf::LengthString& index);

    dsa::vent::tower::dbnf::Modifier* GetModifier();
    dsa::vent::tower::dbnf::Name* GetName();
    dsa::vent::tower::dbnf::SimpleToken* GetValue();

private:
    dsa::vent::tower::dbnf::Modifier* modifier_;
    dsa::vent::tower::dbnf::Name* name_;
    dsa::vent::tower::dbnf::SimpleToken* value_;
};

typedef List<SimpleToken> SimpleTokenList;

class SimpleToken : public dsa::vent::tower::dbnf::Node
{
public:
    SimpleToken();
    ~SimpleToken();

    static dsa::vent::tower::dbnf::SimpleToken* Parse(const char*& index);
    static dsa::vent::tower::dbnf::SimpleToken* Parse(dsa::vent::tower::dbnf::LengthString& index);

    dsa::vent::tower::dbnf::HexDigit* GetHigh();
    dsa::vent::tower::dbnf::HexDigit* GetHighHigh();
    dsa::vent::tower::dbnf::HexDigit* GetHighLow();
    dsa::vent::tower::dbnf::Literal* GetLiteral();
    dsa::vent::tower::dbnf::HexDigit* GetLow();
    dsa::vent::tower::dbnf::HexDigit* GetLowHigh();
    dsa::vent::tower::dbnf::HexDigit* GetLowLow();
    dsa::vent::tower::dbnf::Name* GetToken();

private:
    dsa::vent::tower::dbnf::HexDigit* high_;
    dsa::vent::tower::dbnf::HexDigit* high_high_;
    dsa::vent::tower::dbnf::HexDigit* high_low_;
    dsa::vent::tower::dbnf::Literal* literal_;
    dsa::vent::tower::dbnf::HexDigit* low_;
    dsa::vent::tower::dbnf::HexDigit* low_high_;
    dsa::vent::tower::dbnf::HexDigit* low_low_;
    dsa::vent::tower::dbnf::Name* token_;
};

typedef List<Modifier> ModifierList;

class Modifier : public dsa::vent::tower::dbnf::Node
{
public:
    Modifier();
    ~Modifier();

    static dsa::vent::tower::dbnf::Modifier* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Modifier* Parse(dsa::vent::tower::dbnf::LengthString& index);

    dsa::vent::tower::dbnf::Cardinality* GetCardinality();

private:
    dsa::vent::tower::dbnf::Cardinality* cardinality_;
};

typedef List<Cardinality> CardinalityList;

class Cardinality : public dsa::vent::tower::dbnf::Node
{
public:
    Cardinality();
    ~Cardinality();

    static dsa::vent::tower::dbnf::Cardinality* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Cardinality* Parse(dsa::vent::tower::dbnf::LengthString& index);

    dsa::vent::tower::dbnf::Number* GetCount();
    dsa::vent::tower::dbnf::Number* GetMaximum();
    dsa::vent::tower::dbnf::Number* GetMinimum();

private:
    dsa::vent::tower::dbnf::Number* count_;
    dsa::vent::tower::dbnf::Number* maximum_;
    dsa::vent::tower::dbnf::Number* minimum_;
};

typedef List<Name> NameList;

class Name : public dsa::vent::tower::dbnf::Node
{
public:
    Name();
    ~Name();

    static dsa::vent::tower::dbnf::Name* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Name* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<NameCharacter> NameCharacterList;

class NameCharacter : public dsa::vent::tower::dbnf::Node
{
public:
    NameCharacter();
    ~NameCharacter();

    static dsa::vent::tower::dbnf::NameCharacter* Parse(const char*& index);
    static dsa::vent::tower::dbnf::NameCharacter* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<Number> NumberList;

class Number : public dsa::vent::tower::dbnf::Node
{
public:
    Number();
    ~Number();

    static dsa::vent::tower::dbnf::Number* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Number* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<Digit> DigitList;

class Digit : public dsa::vent::tower::dbnf::Node
{
public:
    Digit();
    ~Digit();

    static dsa::vent::tower::dbnf::Digit* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Digit* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<Punctuation> PunctuationList;

class Punctuation : public dsa::vent::tower::dbnf::Node
{
public:
    Punctuation();
    ~Punctuation();

    static dsa::vent::tower::dbnf::Punctuation* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Punctuation* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<CommentCharacter> CommentCharacterList;

class CommentCharacter : public dsa::vent::tower::dbnf::Node
{
public:
    CommentCharacter();
    ~CommentCharacter();

    static dsa::vent::tower::dbnf::CommentCharacter* Parse(const char*& index);
    static dsa::vent::tower::dbnf::CommentCharacter* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<Comment> CommentList;

class Comment : public dsa::vent::tower::dbnf::Node
{
public:
    Comment();
    ~Comment();

    static dsa::vent::tower::dbnf::Comment* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Comment* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<Literal> LiteralList;

class Literal : public dsa::vent::tower::dbnf::Node
{
public:
    Literal();
    ~Literal();

    static dsa::vent::tower::dbnf::Literal* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Literal* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<LiteralCharacter> LiteralCharacterList;

class LiteralCharacter : public dsa::vent::tower::dbnf::Node
{
public:
    LiteralCharacter();
    ~LiteralCharacter();

    static dsa::vent::tower::dbnf::LiteralCharacter* Parse(const char*& index);
    static dsa::vent::tower::dbnf::LiteralCharacter* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<HexDigit> HexDigitList;

class HexDigit : public dsa::vent::tower::dbnf::Node
{
public:
    HexDigit();
    ~HexDigit();

    static dsa::vent::tower::dbnf::HexDigit* Parse(const char*& index);
    static dsa::vent::tower::dbnf::HexDigit* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<Whitespace> WhitespaceList;

class Whitespace : public dsa::vent::tower::dbnf::Node
{
public:
    Whitespace();
    ~Whitespace();

    static dsa::vent::tower::dbnf::Whitespace* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Whitespace* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

typedef List<Eol> EolList;

class Eol : public dsa::vent::tower::dbnf::Node
{
public:
    Eol();
    ~Eol();

    static dsa::vent::tower::dbnf::Eol* Parse(const char*& index);
    static dsa::vent::tower::dbnf::Eol* Parse(dsa::vent::tower::dbnf::LengthString& index);
};

};
};
};
};

#endif
