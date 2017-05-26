cmake_minimum_required(VERSION 3.0)
project(uri)

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})


set(PARSER_OUTPUT ${PROJECT_DIR}/src/uri-parser.c)
set(PARSER_INPUT ${PROJECT_DIR}/src/uri.leg)



include_directories(include)
add_subdirectory(src)
add_subdirectory(example)