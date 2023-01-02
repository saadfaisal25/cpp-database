cmake_minimum_required(VERSION 3.16.3)

add_executable(database-cli main.cpp)

target_link_libraries(database-cli PRIVATE database)

target_compile_features(database-cli PRIVATE cxx_std_17)