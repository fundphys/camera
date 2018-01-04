cmake_minimum_required(VERSION 3.7.2)
project(camera)

set(CMAKE_CXX_STANDARD 14)

#find_package(PythonLibs 3.5 REQUIRED)
#include_directories(${PYTHON_INCLUDE_DIR})

#find_package(Boost 1.62.0 COMPONENTS python REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})

#find_package(Boost 1.62.0 REQUIRED)

#include_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})

add_library(camera SHARED test_camera.cpp)
target_link_libraries(camera  "-lpython3.5m")

add_executable(trash.exe main.cpp)
target_link_libraries(trash.exe camera)


add_library(pycamera SHARED py_wrap.cpp)
include_directories("/usr/include/python3.5m")
SET_TARGET_PROPERTIES(pycamera PROPERTIES PREFIX "")
target_link_libraries(pycamera camera "-lpython3.5m" "-lboost_python-py35")
