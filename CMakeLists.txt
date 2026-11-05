cmake_minimum_required(VERSION 3.20)

project(CacheCraft
    VERSION 0.1.0
    DESCRIPTION "A Redis-inspired in-memory key-value storage engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(cachecraft_core
    src/cache.cpp
)

target_include_directories(cachecraft_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(cachecraft_core PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wshadow
)

add_executable(cachecraft
    src/main.cpp
)

target_link_libraries(cachecraft
    PRIVATE
        cachecraft_core
)

target_compile_options(cachecraft PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wshadow
)

include(CTest)

if(BUILD_TESTING)
    add_executable(cachecraft_tests
        tests/test_cache.cpp
    )

    target_link_libraries(cachecraft_tests
        PRIVATE
            cachecraft_core
    )

    target_compile_options(cachecraft_tests PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wshadow
    )

    add_test(
        NAME cachecraft_tests
        COMMAND cachecraft_tests
    )
endif()
