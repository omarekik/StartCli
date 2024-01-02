cmake_minimum_required(VERSION 3.26)
project(Start)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GoogleTest)

enable_testing ()

add_subdirectory(config)
add_subdirectory(main)

install(TARGETS Start DESTINATION bin)
