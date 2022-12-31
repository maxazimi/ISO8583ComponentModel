cmake_minimum_required(VERSION 3.19)
project(iso_component_model)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB SOURCES *.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
