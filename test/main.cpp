#include <type-name/type-name.hpp>

#include <iostream>
#include <string>

namespace ns {
enum class EnumClass { DUMMY };
}

class A {};

int main() {
    static_assert(getTypeName<int>() == String("int"), "int failed");
    static_assert(getTypeName<ns::EnumClass>() == String("ns::EnumClass"), "ns::EnumClass failed");
    static_assert(getTypeName<std::string>() == String("std::__cxx11::basic_string<char>"), "std::string failed");
    static_assert(getTypeName<std::ostream>() == String("std::basic_ostream<char>"), "std::ostream failed");
    static_assert(getTypeName<A>() == String("A"), "A failed");

    std::cout << getTypeName<int>().cStr() << std::endl;
    std::cout << getTypeName<ns::EnumClass>().cStr() << std::endl;
    std::cout << getTypeName<std::string>().cStr() << std::endl;
    std::cout << getTypeName<std::ostream>().cStr() << std::endl;
    std::cout << getTypeName<A>().cStr() << std::endl;
    std::cout << "\nPassed" << std::endl;
}
