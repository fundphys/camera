cmake_minimum_required(VERSION 3.9)
project(camera)

set(CMAKE_CXX_STANDARD 17)

add_executable(camera main.cpp)

target_link_libraries(camera profiler)
