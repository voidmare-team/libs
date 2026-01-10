cmake_minimum_required(VERSION 3.28.3)
project(voidmare_libs)

# Find source files
file(GLOB SOURCES src/*.c)

# Build
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_compile_options(${PROJECT_NAME} PRIVATE --std=c11)

# Add tests folder
add_subdirectory(tests)
