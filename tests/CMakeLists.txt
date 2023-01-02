cmake_minimum_required(VERSION 3.16.3)
find_package(Catch2 3 REQUIRED)

add_executable(dbmanage-tests dbmanage-tests.cpp)

include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(dbmanage-tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(dbmanage-tests PRIVATE database)

target_compile_features(dbmanage-tests PRIVATE cxx_std_17)