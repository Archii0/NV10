cmake_minimum_required(VERSION 3.9.1)
project(NV10)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_executable(nv10 src/NV10.cpp)

target_link_libraries(nv10 ${SDL2_LIBRARIES})