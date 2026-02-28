cmake_minimum_required(VERSION 3.16)
project(ST-1)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)

add_test(NAME ST1_unit COMMAND ${PROJECT_NAME}.test)