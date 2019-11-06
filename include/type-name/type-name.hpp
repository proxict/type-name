#ifndef PROXICT_TYPE_NAME_HPP_
#define PROXICT_TYPE_NAME_HPP_
#include <constexpr-string/constexpr-string.hpp>
#include <cstring>

#if defined(__clang__)
    #define TYPE_NAME_START (String(__PRETTY_FUNCTION__).find('[') + 5)
    #define TYPE_NAME_END String(__PRETTY_FUNCTION__).find(']')
#elif  defined(__GNUC__)
    #define TYPE_NAME_START (String(__PRETTY_FUNCTION__).find('[') + 10)
    #define TYPE_NAME_END String(__PRETTY_FUNCTION__).find(']')
#else
#error This compiler is not yet supported
#endif

template <typename T>
constexpr int getTypeNameLength() {
    return TYPE_NAME_END - TYPE_NAME_START;
}

template <typename T>
constexpr ConstexprString<getTypeNameLength<T>()> getTypeName() {
    return String(__PRETTY_FUNCTION__).template substr<TYPE_NAME_START, TYPE_NAME_START + getTypeNameLength<T>()>();
}

#endif // PROXICT_TYPE_NAME_HPP_
