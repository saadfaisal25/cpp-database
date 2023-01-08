cmake_minimum_required(VERSION 3.16.3)

add_executable(mydatabase-cli main.cpp)

include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(mydatabase-cli PRIVATE mydatabase)

target_compile_features(mydatabase-cli PRIVATE cxx_std_17)