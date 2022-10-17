cmake_minimum_required(VERSION 3.17)
project(MonteCarloPi)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(MonteCarloPi main.cpp Simulation.cpp Simulation.h GenerateCN.cpp GenerateCN.h MathFunction.cpp MathFunction.h)

include_directories(C:/Python/Python39/include)
include_directories(C:/Python/Python39/Lib)
link_directories(C:/Python/Python39/libs)

find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(MonteCarloPi ${PYTHON_LIBRARIES})