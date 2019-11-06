![GitHub](https://img.shields.io/github/license/proxict/type-name)

type-name
---------

This library creates a `constexpr` string from the given type. For example, `getTypeName<int>()` function returns an "int" string.
The library depends on [constexpr-string library](https://github.com/proxict/constexpr-string).

Integration with CMake
----------------------------
```bash
mkdir -p external
cd external
git clone --recursive https://github.com/proxict/type-name.git
```

```cmake
add_subdirectory(external/type-name)
target_link_libraries(your-target
    PRIVATE type-name
)
```

Tests can be enabled by setting `BUILD_TESTS` variable to `TRUE`:
```bash
mkdir -p build && cd build
cmake -DBUILD_TESTS=1 ..
```

How to use?
-----------
Just include the header and you're ready to go:
```c++
#include <iostream>
#include <type-name/type-name.hpp>

int main() {
    std::cout << getTypeName<int>() << std::endl; // prints "int"
    return 0;
}
```
