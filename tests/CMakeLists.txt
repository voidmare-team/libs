cmake_minimum_required(VERSION 3.28.3)
project(voidmare_libs_tests LANGUAGES C)

# FetchContent
include(FetchContent)
FetchContent_Declare(
    voidmare_test
    GIT_REPOSITORY https://github.com/voidmare-team/test.git
    GIT_TAG        v1.0.0
)
FetchContent_MakeAvailable(voidmare_test)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE voidmare_test voidmare_libs)
target_compile_options(${PROJECT_NAME} PRIVATE --std=c11)
