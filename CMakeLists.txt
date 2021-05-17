set(CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.8)
project("Algorithm")

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# Add source to this project's executable.
add_executable (Algorithm  "Main.cpp" "MainWindow.h" "MainWindow.cpp" "HashTable.hpp" "Hash.h" "HashMap.hpp" "formatter.hpp")

#fmt pkg
find_package(fmt CONFIG REQUIRED)
target_link_libraries(Algorithm PRIVATE fmt::fmt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
