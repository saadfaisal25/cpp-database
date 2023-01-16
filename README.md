# cpp-database

A simple database library for C++ with a CLI interface. Currently supports storage using a key-value store.

## Usage

Requires Catch2 and cxxopts. Built with CMake.

```bash
cmake -B build
cmake --build build --config Debug --target all -j
cd build
```

## CLI

To list all available commands, run:
```bash
cd cli
./mydatabase-cli --help
```
