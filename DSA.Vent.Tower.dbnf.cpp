#include "DSA.Vent.Tower.dbnf.hpp"

namespace dsa
{
namespace vent
{
namespace tower
{
namespace dbnf
{

class LITERAL_ID0
{
public:
    static const char* GetLiteral()
    {
        return " ";
    }
};

class LITERAL_ID1
{
public:
    static const char* GetLiteral()
    {
        return "!";
    }
};

class LITERAL_ID2
{
public:
    static const char* GetLiteral()
    {
        return "#";
    }
};

class LITERAL_ID3
{
public:
    static const char* GetLiteral()
    {
        return "(";
    }
};

class LITERAL_ID4
{
public:
    static const char* GetLiteral()
    {
        return ")";
    }
};

class LITERAL_ID5
{
public:
    static const char* GetLiteral()
    {
        return "*";
    }
};

class LITERAL_ID6
{
public:
    static const char* GetLiteral()
    {
        return "+";
    }
};

class LITERAL_ID7
{
public:
    static const char* GetLiteral()
    {
        return ",";
    }
};

class LITERAL_0X_ID8
{
public:
    static const char* GetLiteral()
    {
        return "-0x";
    }
};

class LITERAL_ID9
{
public:
    static const char* GetLiteral()
    {
        return ".";
    }
};

class LITERAL_0X_ID10
{
public:
    static const char* GetLiteral()
    {
        return "0x";
    }
};

class LITERAL_ID11
{
public:
    static const char* GetLiteral()
    {
        return "::=";
    }
};

class LITERAL_ID12
{
public:
    static const char* GetLiteral()
    {
        return "<";
    }
};

class LITERAL_ID13
{
public:
    static const char* GetLiteral()
    {
        return ">";
    }
};

class LITERAL_ID14
{
public:
    static const char* GetLiteral()
    {
        return "?";
    }
};

class LITERAL_0X_ID15
{
public:
    static const char* GetLiteral()
    {
        return "[0x";
    }
};

class LITERAL_ID16
{
public:
    static const char* GetLiteral()
    {
        return "\"";
    }
};

class LITERAL_ID17
{
public:
    static const char* GetLiteral()
    {
        return "\\\"";
    }
};

class LITERAL_ID18
{
public:
    static const char* GetLiteral()
    {
        return "\\\\";
    }
};

class LITERAL_ID19
{
public:
    static const char* GetLiteral()
    {
        return "]";
    }
};

class LITERAL___ID20
{
public:
    static const char* GetLiteral()
    {
        return "_";
    }
};

class LITERAL_ATTRIBUTE_ID21
{
public:
    static const char* GetLiteral()
    {
        return "attribute";
    }
};

class LITERAL_ID22
{
public:
    static const char* GetLiteral()
    {
        return "{";
    }
};

class LITERAL_ID23
{
public:
    static const char* GetLiteral()
    {
        return "}";
    }
};

static bool Match(std::list<dsa::vent::tower::dbnf::Node*>& nodes, dsa::vent::tower::dbnf::Node* node)
{
    if(node)
    {
        nodes.push_back(node);
        return true;
    }
    else
    {
        return false;
    }
}

static bool Optional(std::list<dsa::vent::tower::dbnf::Node*>& nodes, dsa::vent::tower::dbnf::Node* node)
{
    Match(nodes, node);
    return true;
}

template<typename Reference, typename Parser>
static bool Match(std::list<dsa::vent::tower::dbnf::Node*>& nodes, Reference*& reference, Parser* node)
{
    reference = node;
    return Match(nodes, node);
}

template<typename Reference, typename Parser>
static bool Optional(std::list<dsa::vent::tower::dbnf::Node*>& nodes, Reference*& reference, Parser* node)
{
    Match<Reference, Parser>(nodes, reference, node);
    return true;
}

static bool Reset(dsa::vent::tower::dbnf::LengthString value, dsa::vent::tower::dbnf::LengthString& index)
{
    index = value;
    return false;
}

static bool ClearNodes(std::list<dsa::vent::tower::dbnf::Node*>& nodes)
{
    while(!nodes.empty())
    {
        dsa::vent::tower::dbnf::Node* node = nodes.front();
        nodes.pop_front();
        delete node;
    }

    return true;
}

template<typename Parser, int minimum, int maximum>
class RangeParser : public dsa::vent::tower::dbnf::List<Parser>
{
public:
    RangeParser()
    {
    }
    virtual ~RangeParser()
    {
    }

    static RangeParser<Parser, minimum, maximum>* Parse(dsa::vent::tower::dbnf::LengthString& index)
    {
        dsa::vent::tower::dbnf::LengthString start = index;
        dsa::vent::tower::dbnf::LengthString local_start = index;
        std::list<dsa::vent::tower::dbnf::Node*> children;
        RangeParser<Parser, minimum, maximum>* range_parser = NULL;
        std::list<Parser*> list;
        Parser* node = NULL;
        int count = 0;

        while(((count < maximum) && (node = Parser::Parse(index))) || dsa::vent::tower::dbnf::Reset(local_start, index))
        {
            local_start = index;
            ++count;
            children.push_back(node);
            list.push_back(node);
        }

        if((count > minimum) || (dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Reset(start, index)))
        {
            range_parser = new RangeParser<Parser, minimum, maximum>();
            range_parser->SetChildren(children);
            range_parser->list_ = list;
        }

        return range_parser;
    }
};

template<typename Parser, int minimum>
class MinimumParser : public dsa::vent::tower::dbnf::List<Parser>
{
public:
    MinimumParser()
    {
    }
    virtual ~MinimumParser()
    {
    }

    static MinimumParser<Parser, minimum>* Parse(dsa::vent::tower::dbnf::LengthString& index)
    {
        dsa::vent::tower::dbnf::LengthString start = index;
        dsa::vent::tower::dbnf::LengthString local_start = index;
        std::list<dsa::vent::tower::dbnf::Node*> children;
        MinimumParser<Parser, minimum>* minimum_parser = NULL;
        std::list<Parser*> list;
        Parser* node = NULL;
        int count = 0;

        while((node = Parser::Parse(index)) || dsa::vent::tower::dbnf::Reset(local_start, index))
        {
            local_start = index;
            ++count;
            children.push_back(node);
            list.push_back(node);
        }

        if((count >= minimum) || (dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Reset(start, index)))
        {
            minimum_parser = new MinimumParser<Parser, minimum>();
            minimum_parser->SetChildren(children);
            minimum_parser->list_ = list;
        }

        return minimum_parser;
    }
};

template<int character>
class CharacterParser
{
public:
    static dsa::vent::tower::dbnf::String* Parse(dsa::vent::tower::dbnf::LengthString& index)
    {
        int current_character = ((*(index.data)) + 256) % 256;
        dsa::vent::tower::dbnf::LengthString data = {index.data, 1};

        if((index.length > 0) && (current_character == character))
        {
            ++(index.data);
            --(index.length);
            dsa::vent::tower::dbnf::String* string_node = new dsa::vent::tower::dbnf::String(data);
            return string_node;
        }
        else
        {
            return NULL;
        }
    }
};

template<int low_character, int high_character>
class CharacterRangeParser
{
public:
    static dsa::vent::tower::dbnf::String* Parse(dsa::vent::tower::dbnf::LengthString& index)
    {
        int current_character = ((*(index.data)) + 256) % 256;
        dsa::vent::tower::dbnf::LengthString data = {index.data, 1};

        if((index.length > 0) && (low_character <= current_character) && (current_character <= high_character))
        {
            ++(index.data);
            --(index.length);
            dsa::vent::tower::dbnf::String* string_node = new dsa::vent::tower::dbnf::String(data);
            return string_node;
        }
        else
        {
            return NULL;
        }
    }
};

template<typename Literal>
class StringParser
{
public:
    static bool MatchCharacter(char value, dsa::vent::tower::dbnf::LengthString& index)
    {
        if((index.length > 0) && ((*(index.data)) == value))
        {
            ++(index.data);
            --(index.length);
            return true;
        }
        else
        {
            return false;
        }
    }

    static dsa::vent::tower::dbnf::String* Parse(dsa::vent::tower::dbnf::LengthString& index)
    {
        dsa::vent::tower::dbnf::LengthString start = index;
        const char* literal_index = Literal::GetLiteral();
        dsa::vent::tower::dbnf::LengthString data = {index.data, strlen(literal_index)};
        
        while((*literal_index) && (start.length > 0) && MatchCharacter(*literal_index, start))
        {
            ++literal_index;
        }
        
        if((*literal_index) == 0)
        {
            index = start;
            dsa::vent::tower::dbnf::String* string_node = new dsa::vent::tower::dbnf::String(data);
            return string_node;
        }
        else
        {
            return NULL;
        }
    }

};

Node::Node()
{
    data_.data = NULL;
    data_.length = 0;
}

Node::~Node()
{
    dsa::vent::tower::dbnf::ClearNodes(children_);
}

std::string Node::UnParse()
{
    std::string data(data_.data, data_.length);
    return data;
}

dsa::vent::tower::dbnf::LengthString Node::UnParseLString()
{
    return data_;
}

std::list<dsa::vent::tower::dbnf::Node*> Node::GetChildren()
{
    return children_;
}

void Node::SetString(dsa::vent::tower::dbnf::LengthString data)
{
    data_ = data;
}

void Node::SetChildren(std::list<dsa::vent::tower::dbnf::Node*> children)
{
    dsa::vent::tower::dbnf::ClearNodes(children_);
    children_ = children;
}

String::String(dsa::vent::tower::dbnf::LengthString data)
{
    SetString(data);
}

String::~String()
{
}

Grammar::Grammar() : Node()
    ,rules_(NULL)
{
}

List<dsa::vent::tower::dbnf::Rule>* Grammar::GetRules()
{
    return rules_;
}

Grammar::~Grammar()
{
}

dsa::vent::tower::dbnf::Grammar* Grammar::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Grammar* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Grammar* Grammar::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;
    List<dsa::vent::tower::dbnf::Rule>* rules = NULL;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, rules, MinimumParser<dsa::vent::tower::dbnf::Rule, 0>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Grammar* instance = new dsa::vent::tower::dbnf::Grammar();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->rules_ = rules;
        return instance;
    } else {
        rules = NULL;
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Rule::Rule() : Node()
    ,expressions_(NULL)
    ,name_(NULL)
{
}

List<dsa::vent::tower::dbnf::Expression>* Rule::GetExpressions()
{
    return expressions_;
}

dsa::vent::tower::dbnf::Name* Rule::GetName()
{
    return name_;
}

Rule::~Rule()
{
}

dsa::vent::tower::dbnf::Rule* Rule::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Rule* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Rule* Rule::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;
    List<dsa::vent::tower::dbnf::Expression>* expressions = NULL;
    dsa::vent::tower::dbnf::Name* name = NULL;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID12>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, name, dsa::vent::tower::dbnf::Name::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID13>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, expressions, MinimumParser<dsa::vent::tower::dbnf::Expression, 0>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Rule* instance = new dsa::vent::tower::dbnf::Rule();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->name_ = name;
        instance->expressions_ = expressions;
        return instance;
    } else {
        name = NULL;
        expressions = NULL;
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, dsa::vent::tower::dbnf::Comment::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Rule* instance = new dsa::vent::tower::dbnf::Rule();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Expression::Expression() : Node()
    ,expression_discriminator_(NULL)
    ,token_sequence_(NULL)
{
}

dsa::vent::tower::dbnf::String* Expression::GetExpressionDiscriminator()
{
    return expression_discriminator_;
}

List<dsa::vent::tower::dbnf::Token>* Expression::GetTokenSequence()
{
    return token_sequence_;
}

Expression::~Expression()
{
}

dsa::vent::tower::dbnf::Expression* Expression::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Expression* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Expression* Expression::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;
    dsa::vent::tower::dbnf::String* expression_discriminator = NULL;
    List<dsa::vent::tower::dbnf::Token>* token_sequence = NULL;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, expression_discriminator, StringParser<LITERAL_ID11>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, token_sequence, MinimumParser<dsa::vent::tower::dbnf::Token, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, dsa::vent::tower::dbnf::Eol::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Expression* instance = new dsa::vent::tower::dbnf::Expression();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->expression_discriminator_ = expression_discriminator;
        instance->token_sequence_ = token_sequence;
        return instance;
    } else {
        expression_discriminator = NULL;
        token_sequence = NULL;
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, dsa::vent::tower::dbnf::Comment::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Expression* instance = new dsa::vent::tower::dbnf::Expression();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Token::Token() : Node()
    ,modifier_(NULL)
    ,name_(NULL)
    ,value_(NULL)
{
}

dsa::vent::tower::dbnf::Modifier* Token::GetModifier()
{
    return modifier_;
}

dsa::vent::tower::dbnf::Name* Token::GetName()
{
    return name_;
}

dsa::vent::tower::dbnf::SimpleToken* Token::GetValue()
{
    return value_;
}

Token::~Token()
{
}

dsa::vent::tower::dbnf::Token* Token::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Token* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Token* Token::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;
    dsa::vent::tower::dbnf::Modifier* modifier = NULL;
    dsa::vent::tower::dbnf::Name* name = NULL;
    dsa::vent::tower::dbnf::SimpleToken* value = NULL;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ATTRIBUTE_ID21>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID3>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, name, dsa::vent::tower::dbnf::Name::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, value, dsa::vent::tower::dbnf::SimpleToken::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, modifier, dsa::vent::tower::dbnf::Modifier::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID4>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Token* instance = new dsa::vent::tower::dbnf::Token();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->name_ = name;
        instance->value_ = value;
        instance->modifier_ = modifier;
        return instance;
    } else {
        name = NULL;
        value = NULL;
        modifier = NULL;
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ATTRIBUTE_ID21>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID3>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, name, dsa::vent::tower::dbnf::Name::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, value, dsa::vent::tower::dbnf::SimpleToken::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID4>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Token* instance = new dsa::vent::tower::dbnf::Token();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->name_ = name;
        instance->value_ = value;
        return instance;
    } else {
        name = NULL;
        value = NULL;
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, value, dsa::vent::tower::dbnf::SimpleToken::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, modifier, dsa::vent::tower::dbnf::Modifier::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Token* instance = new dsa::vent::tower::dbnf::Token();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->value_ = value;
        instance->modifier_ = modifier;
        return instance;
    } else {
        value = NULL;
        modifier = NULL;
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, value, dsa::vent::tower::dbnf::SimpleToken::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Token* instance = new dsa::vent::tower::dbnf::Token();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->value_ = value;
        return instance;
    } else {
        value = NULL;
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

SimpleToken::SimpleToken() : Node()
    ,high_(NULL)
    ,high_high_(NULL)
    ,high_low_(NULL)
    ,literal_(NULL)
    ,low_(NULL)
    ,low_high_(NULL)
    ,low_low_(NULL)
    ,token_(NULL)
{
}

dsa::vent::tower::dbnf::HexDigit* SimpleToken::GetHigh()
{
    return high_;
}

dsa::vent::tower::dbnf::HexDigit* SimpleToken::GetHighHigh()
{
    return high_high_;
}

dsa::vent::tower::dbnf::HexDigit* SimpleToken::GetHighLow()
{
    return high_low_;
}

dsa::vent::tower::dbnf::Literal* SimpleToken::GetLiteral()
{
    return literal_;
}

dsa::vent::tower::dbnf::HexDigit* SimpleToken::GetLow()
{
    return low_;
}

dsa::vent::tower::dbnf::HexDigit* SimpleToken::GetLowHigh()
{
    return low_high_;
}

dsa::vent::tower::dbnf::HexDigit* SimpleToken::GetLowLow()
{
    return low_low_;
}

dsa::vent::tower::dbnf::Name* SimpleToken::GetToken()
{
    return token_;
}

SimpleToken::~SimpleToken()
{
}

dsa::vent::tower::dbnf::SimpleToken* SimpleToken::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::SimpleToken* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::SimpleToken* SimpleToken::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;
    dsa::vent::tower::dbnf::HexDigit* high = NULL;
    dsa::vent::tower::dbnf::HexDigit* high_high = NULL;
    dsa::vent::tower::dbnf::HexDigit* high_low = NULL;
    dsa::vent::tower::dbnf::Literal* literal = NULL;
    dsa::vent::tower::dbnf::HexDigit* low = NULL;
    dsa::vent::tower::dbnf::HexDigit* low_high = NULL;
    dsa::vent::tower::dbnf::HexDigit* low_low = NULL;
    dsa::vent::tower::dbnf::Name* token = NULL;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID12>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, token, dsa::vent::tower::dbnf::Name::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID13>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::SimpleToken* instance = new dsa::vent::tower::dbnf::SimpleToken();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->token_ = token;
        return instance;
    } else {
        token = NULL;
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_0X_ID10>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, high, dsa::vent::tower::dbnf::HexDigit::Parse(index)) && dsa::vent::tower::dbnf::Match(children, low, dsa::vent::tower::dbnf::HexDigit::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::SimpleToken* instance = new dsa::vent::tower::dbnf::SimpleToken();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->high_ = high;
        instance->low_ = low;
        return instance;
    } else {
        high = NULL;
        low = NULL;
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID16>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, literal, dsa::vent::tower::dbnf::Literal::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID16>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::SimpleToken* instance = new dsa::vent::tower::dbnf::SimpleToken();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->literal_ = literal;
        return instance;
    } else {
        literal = NULL;
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_0X_ID15>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, low_high, dsa::vent::tower::dbnf::HexDigit::Parse(index)) && dsa::vent::tower::dbnf::Match(children, low_low, dsa::vent::tower::dbnf::HexDigit::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_0X_ID8>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, high_high, dsa::vent::tower::dbnf::HexDigit::Parse(index)) && dsa::vent::tower::dbnf::Match(children, high_low, dsa::vent::tower::dbnf::HexDigit::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID19>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::SimpleToken* instance = new dsa::vent::tower::dbnf::SimpleToken();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->low_high_ = low_high;
        instance->low_low_ = low_low;
        instance->high_high_ = high_high;
        instance->high_low_ = high_low;
        return instance;
    } else {
        low_high = NULL;
        low_low = NULL;
        high_high = NULL;
        high_low = NULL;
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Modifier::Modifier() : Node()
    ,cardinality_(NULL)
{
}

dsa::vent::tower::dbnf::Cardinality* Modifier::GetCardinality()
{
    return cardinality_;
}

Modifier::~Modifier()
{
}

dsa::vent::tower::dbnf::Modifier* Modifier::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Modifier* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Modifier* Modifier::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;
    dsa::vent::tower::dbnf::Cardinality* cardinality = NULL;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID5>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Modifier* instance = new dsa::vent::tower::dbnf::Modifier();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID14>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Modifier* instance = new dsa::vent::tower::dbnf::Modifier();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID6>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Modifier* instance = new dsa::vent::tower::dbnf::Modifier();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID22>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, cardinality, dsa::vent::tower::dbnf::Cardinality::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID23>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Modifier* instance = new dsa::vent::tower::dbnf::Modifier();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->cardinality_ = cardinality;
        return instance;
    } else {
        cardinality = NULL;
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Cardinality::Cardinality() : Node()
    ,count_(NULL)
    ,maximum_(NULL)
    ,minimum_(NULL)
{
}

dsa::vent::tower::dbnf::Number* Cardinality::GetCount()
{
    return count_;
}

dsa::vent::tower::dbnf::Number* Cardinality::GetMaximum()
{
    return maximum_;
}

dsa::vent::tower::dbnf::Number* Cardinality::GetMinimum()
{
    return minimum_;
}

Cardinality::~Cardinality()
{
}

dsa::vent::tower::dbnf::Cardinality* Cardinality::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Cardinality* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Cardinality* Cardinality::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;
    dsa::vent::tower::dbnf::Number* count = NULL;
    dsa::vent::tower::dbnf::Number* maximum = NULL;
    dsa::vent::tower::dbnf::Number* minimum = NULL;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, minimum, dsa::vent::tower::dbnf::Number::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID7>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, maximum, dsa::vent::tower::dbnf::Number::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Cardinality* instance = new dsa::vent::tower::dbnf::Cardinality();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->minimum_ = minimum;
        instance->maximum_ = maximum;
        return instance;
    } else {
        minimum = NULL;
        maximum = NULL;
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, minimum, dsa::vent::tower::dbnf::Number::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID7>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Cardinality* instance = new dsa::vent::tower::dbnf::Cardinality();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->minimum_ = minimum;
        return instance;
    } else {
        minimum = NULL;
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, count, dsa::vent::tower::dbnf::Number::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Cardinality* instance = new dsa::vent::tower::dbnf::Cardinality();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        instance->count_ = count;
        return instance;
    } else {
        count = NULL;
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Name::Name() : Node()
{
}

Name::~Name()
{
}

dsa::vent::tower::dbnf::Name* Name::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Name* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Name* Name::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::NameCharacter, 1>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Name* instance = new dsa::vent::tower::dbnf::Name();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

NameCharacter::NameCharacter() : Node()
{
}

NameCharacter::~NameCharacter()
{
}

dsa::vent::tower::dbnf::NameCharacter* NameCharacter::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::NameCharacter* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::NameCharacter* NameCharacter::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x30, 0x39>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::NameCharacter* instance = new dsa::vent::tower::dbnf::NameCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x41, 0x5A>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::NameCharacter* instance = new dsa::vent::tower::dbnf::NameCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL___ID20>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::NameCharacter* instance = new dsa::vent::tower::dbnf::NameCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x61, 0x7A>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::NameCharacter* instance = new dsa::vent::tower::dbnf::NameCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Number::Number() : Node()
{
}

Number::~Number()
{
}

dsa::vent::tower::dbnf::Number* Number::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Number* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Number* Number::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Digit, 1>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Number* instance = new dsa::vent::tower::dbnf::Number();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Digit::Digit() : Node()
{
}

Digit::~Digit()
{
}

dsa::vent::tower::dbnf::Digit* Digit::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Digit* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Digit* Digit::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x30, 0x39>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Digit* instance = new dsa::vent::tower::dbnf::Digit();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Punctuation::Punctuation() : Node()
{
}

Punctuation::~Punctuation()
{
}

dsa::vent::tower::dbnf::Punctuation* Punctuation::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Punctuation* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Punctuation* Punctuation::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID7>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Punctuation* instance = new dsa::vent::tower::dbnf::Punctuation();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID9>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Punctuation* instance = new dsa::vent::tower::dbnf::Punctuation();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID14>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Punctuation* instance = new dsa::vent::tower::dbnf::Punctuation();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID1>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Punctuation* instance = new dsa::vent::tower::dbnf::Punctuation();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

CommentCharacter::CommentCharacter() : Node()
{
}

CommentCharacter::~CommentCharacter()
{
}

dsa::vent::tower::dbnf::CommentCharacter* CommentCharacter::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::CommentCharacter* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::CommentCharacter* CommentCharacter::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, dsa::vent::tower::dbnf::NameCharacter::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::CommentCharacter* instance = new dsa::vent::tower::dbnf::CommentCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, dsa::vent::tower::dbnf::Punctuation::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::CommentCharacter* instance = new dsa::vent::tower::dbnf::CommentCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID0>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::CommentCharacter* instance = new dsa::vent::tower::dbnf::CommentCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID2>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::CommentCharacter* instance = new dsa::vent::tower::dbnf::CommentCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Comment::Comment() : Node()
{
}

Comment::~Comment()
{
}

dsa::vent::tower::dbnf::Comment* Comment::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Comment* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Comment* Comment::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::Whitespace, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID2>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::CommentCharacter, 0>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, dsa::vent::tower::dbnf::Eol::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Comment* instance = new dsa::vent::tower::dbnf::Comment();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Literal::Literal() : Node()
{
}

Literal::~Literal()
{
}

dsa::vent::tower::dbnf::Literal* Literal::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Literal* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Literal* Literal::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, MinimumParser<dsa::vent::tower::dbnf::LiteralCharacter, 0>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Literal* instance = new dsa::vent::tower::dbnf::Literal();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

LiteralCharacter::LiteralCharacter() : Node()
{
}

LiteralCharacter::~LiteralCharacter()
{
}

dsa::vent::tower::dbnf::LiteralCharacter* LiteralCharacter::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::LiteralCharacter* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::LiteralCharacter* LiteralCharacter::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x00, 0x21>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::LiteralCharacter* instance = new dsa::vent::tower::dbnf::LiteralCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID17>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::LiteralCharacter* instance = new dsa::vent::tower::dbnf::LiteralCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x23, 0x5B>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::LiteralCharacter* instance = new dsa::vent::tower::dbnf::LiteralCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, StringParser<LITERAL_ID18>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::LiteralCharacter* instance = new dsa::vent::tower::dbnf::LiteralCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x5D, 0xFF>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::LiteralCharacter* instance = new dsa::vent::tower::dbnf::LiteralCharacter();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

HexDigit::HexDigit() : Node()
{
}

HexDigit::~HexDigit()
{
}

dsa::vent::tower::dbnf::HexDigit* HexDigit::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::HexDigit* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::HexDigit* HexDigit::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x30, 0x39>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::HexDigit* instance = new dsa::vent::tower::dbnf::HexDigit();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x41, 0x46>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::HexDigit* instance = new dsa::vent::tower::dbnf::HexDigit();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Whitespace::Whitespace() : Node()
{
}

Whitespace::~Whitespace()
{
}

dsa::vent::tower::dbnf::Whitespace* Whitespace::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Whitespace* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Whitespace* Whitespace::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x00, 0x09>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Whitespace* instance = new dsa::vent::tower::dbnf::Whitespace();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x0B, 0x0C>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Whitespace* instance = new dsa::vent::tower::dbnf::Whitespace();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterRangeParser<0x0E, 0x20>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Whitespace* instance = new dsa::vent::tower::dbnf::Whitespace();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

Eol::Eol() : Node()
{
}

Eol::~Eol()
{
}

dsa::vent::tower::dbnf::Eol* Eol::Parse(const char*& index)
{
    dsa::vent::tower::dbnf::LengthString length_string_index;
    length_string_index.data = index;
    length_string_index.length = strlen(index);
    dsa::vent::tower::dbnf::Eol* instance = Parse(length_string_index);
    index = length_string_index.data;
    return instance;
}

dsa::vent::tower::dbnf::Eol* Eol::Parse(dsa::vent::tower::dbnf::LengthString& index)
{
    dsa::vent::tower::dbnf::LengthString start = index;
    std::list<dsa::vent::tower::dbnf::Node*> children;

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterParser<0x0A>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, CharacterParser<0x0D>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Eol* instance = new dsa::vent::tower::dbnf::Eol();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterParser<0x0D>::Parse(index)) && dsa::vent::tower::dbnf::Match(children, CharacterParser<0x0A>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Eol* instance = new dsa::vent::tower::dbnf::Eol();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterParser<0x0A>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Eol* instance = new dsa::vent::tower::dbnf::Eol();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children) && dsa::vent::tower::dbnf::Match(children, CharacterParser<0x0D>::Parse(index))) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Eol* instance = new dsa::vent::tower::dbnf::Eol();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    if ((dsa::vent::tower::dbnf::ClearNodes(children)) || dsa::vent::tower::dbnf::Reset(start, index))
    {
        dsa::vent::tower::dbnf::Eol* instance = new dsa::vent::tower::dbnf::Eol();
        dsa::vent::tower::dbnf::LengthString data;
        data.length = start.length - index.length;
        data.data = start.data;
        instance->SetString(data);
        instance->SetChildren(children);
        return instance;
    } else {
    }

    dsa::vent::tower::dbnf::ClearNodes(children);
    return NULL;
}

};
};
};
};
