cmake_minimum_required(VERSION 3.10)

project(CryptoTool)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

aux_source_directory(src SRC_LIST)

add_executable(CryptoTool ${SRC_LIST})