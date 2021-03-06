cmake_minimum_required(VERSION 3.0)
project(type-name VERSION 1.0.0 LANGUAGES CXX)
set(platform ${CMAKE_SYSTEM_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -fPIC -fvisibility=hidden")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -pg -fprofile-arcs")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(type-name INTERFACE)

target_include_directories(type-name
    INTERFACE include
)

add_subdirectory(external/constexpr-string)
target_link_libraries(type-name
    INTERFACE constexpr-string
)

if (BUILD_TESTS)
    add_subdirectory(test)
endif()

