# CacheCraft

A Redis-inspired, in-memory key-value storage engine built with C++20.

CacheCraft is an educational systems-programming project focused on data
structures, memory management, persistence, networking, testing, and
performance measurement.

## Project Status

Under active development.

The initial C++20 build foundation is in place. Core storage functionality
and additional capabilities will be implemented incrementally.

## Planned Features

- Basic key-value operations: SET, GET, and DELETE
- LRU eviction with configurable capacity
- Time-to-live (TTL) expiration
- Append-only persistence and recovery
- TCP server and client
- Automated tests and performance benchmarks
- Continuous integration with GitHub Actions

## Requirements

- C++20-compatible compiler
- CMake 3.20 or newer
- Ninja

## Build

    cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
    cmake --build build

## Run

    ./build/cachecraft

## Project Goals

- Practice modern C++ and systems programming.
- Make data-structure and algorithm choices explicit.
- Validate behavior with automated tests.
- Measure performance rather than make unsupported claims.
- Document design decisions and limitations.

## License

No license has been selected yet.
