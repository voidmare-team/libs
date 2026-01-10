cmake_minimum_required(VERSION 3.28.3)
project(voidmare_libs)

file(GLOB SOURCES src/*.c)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_compile_options(${PROJECT_NAME} PRVATE --std=c11)
