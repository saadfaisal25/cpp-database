cmake_minimum_required(VERSION 3.16.3)
find_package(Catch2 3 REQUIRED)

add_executable(db-tests 
  dbmanage-tests.cpp
  keyvalue-tests.cpp
)

include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(db-tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(db-tests PRIVATE mydatabase)

target_compile_features(db-tests PRIVATE cxx_std_17)