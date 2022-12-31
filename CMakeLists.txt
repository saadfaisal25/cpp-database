cmake_minimum_required(VERSION 3.0)

project(database)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(GNUInstallDirs)

add_subdirectory(database)
add_subdirectory(tests)
add_subdirectory(cli)