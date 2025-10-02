cmake_minimum_required(VERSION 3.10)

# A Comment
project(
    CMakeDemo
    VERSION 1.0
)

add_library(math_add_lib STATIC src/math_add.cpp)
target_include_directories(math_add_lib PUBLIC include)

add_executable(main_exec src/main.cpp)
target_include_directories(main_exec PUBLIC include)
target_link_libraries(main_exec PUBLIC math_add_lib)