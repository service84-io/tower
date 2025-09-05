#ifndef S84_TOWER_GENERATOR_CTCODEGENERATOR_CTCODE_H
#define S84_TOWER_GENERATOR_CTCODEGENERATOR_CTCODE_H

#include "S84.Tower.System.ctcode.hpp"
#include "S84.Tower.Generator.ctcode.hpp"
#include "S84.Tower.dbnf.ctcode.hpp"

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
    template<typename U>
    OmniPointer(U* value) { value_raw = value; }
    OmniPointer(std::shared_ptr<T> value) { value_raw = NULL; value_shared = value; }
    template<typename U>
    OmniPointer(std::shared_ptr<U> value) { value_raw = NULL; value_shared = value; }

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
inline void SetKV(std::unordered_map<std::string, T>& input, const std::string& key, T element)
{
    input.erase(key);
    input.insert(std::pair<std::string, T>(key, element));
}
template<typename T>
inline std::vector<std::string> Keys(const std::unordered_map<std::string, T>& input)
{
    std::vector<std::string> result;
    for(typename std::unordered_map<std::string, T>::const_iterator index = input.begin();index != input.end();index++) {
        result.push_back(index->first);
    }
    return result;
}
template<typename T>
inline bool HasKV(const std::unordered_map<std::string, T>& input, const std::string& key)
{
    typename std::unordered_map<std::string, T>::const_iterator beginning = input.find(key);
    return beginning != input.end();
}
template<typename T>
inline T GetKV(const std::unordered_map<std::string, T>& input, const std::string& key) { return input.at(key); }
inline int Length(const std::string& input) { return (int)input.length(); };
inline std::string At(const std::string& input, int index) { return input.substr(index, 1); };
inline int IntAt(const std::string& input, int index) { return (input.at(index) + 256) % 256; };
inline std::string Concat(const std::string& left, const std::string& right) { return left + right; };
#endif

namespace s84 {
namespace tower {
namespace generator {
namespace ctcodegenerator {
namespace ctcode {

class MemberType;
class CTCodeGenerator;

class MemberType {
public:
    MemberType();
    inline ~MemberType() {}

    void SetBaseType(std::string input);
    std::string GetBaseType();
    void SetIsList(bool input);
    bool GetIsList();

private:
    std::string base_type;
    bool is_list;
};

class CTCodeGenerator : public s84::tower::generator::ctcode::Generator {
public:
    CTCodeGenerator();
    inline ~CTCodeGenerator() {}

    int GenerateParser(OmniPointer<s84::tower::system::ctcode::System> system, OmniPointer<s84::tower::dbnf::ctcode::Grammar> grammar, std::string base_name);
    void WriteClasses(OmniPointer<s84::tower::dbnf::ctcode::Grammar> grammar, std::string base_name);
    void WriteClass(OmniPointer<s84::tower::dbnf::ctcode::Grammar> grammar, OmniPointer<s84::tower::dbnf::ctcode::Rule> rule);
    void WriteExpression(OmniPointer<s84::tower::dbnf::ctcode::Expression> expression);
    std::unordered_map<std::string, OmniPointer<MemberType>> GetMembers(OmniPointer<s84::tower::dbnf::ctcode::Rule> rule);
    std::string GenerateClassName(OmniPointer<s84::tower::dbnf::ctcode::Name> name_node);
    std::string GenerateMemberName(OmniPointer<s84::tower::dbnf::ctcode::Name> name_node);
    std::string GenerateMimicName(std::string member);
    std::string GenerateGetterName(std::string member);
    std::string GenerateSetterName(std::string member);
    std::string SnakeCaseToCamelCase(std::string snake_case);
    std::string CamelCaseToSnakeCase(std::string camel_case);
    bool IsUpper(std::string character);
    bool IsDigit(std::string character);
    std::string ToLower(std::string input);
    std::string CharacterToLower(std::string input);
    std::string ToUpper(std::string input);
    std::string CharacterToUpper(std::string input);

private:
    OmniPointer<s84::tower::system::ctcode::OutputStream> logger;
    OmniPointer<s84::tower::system::ctcode::OutputStream> ctcode_file;
};

};
};
};
};
};

#endif
