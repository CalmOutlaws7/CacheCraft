cmake_minimum_required(VERSION 3.20)

project(CacheCraft
    VERSION 0.1.0
    DESCRIPTION "A Redis-inspired in-memory key-value storage engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cachecraft
    src/main.cpp
)

target_compile_options(cachecraft PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wshadow
)
