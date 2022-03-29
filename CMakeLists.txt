cmake_minimum_required(VERSION 3.19)
project(TicTacToe)
set(CMAKE_CXX_STANDARD 23)

set(SDL2_DIR dependencies/SDL2-2.0.20)

set(SOURCE_FILES Renderer.cpp)

add_executable(TicTacToe main.cpp ${SOURCE_FILES})

find_package(SDL2 REQUIRED)

find_library(SDL2_LIB SDL2.lib ${SDL2_DIR}/lib/x64/)

target_link_libraries(TicTacToe ${SDL2_LIBRARIES})

include_directories(TicTacToe PUBLIC ${SDL2_INCLUDE_DIRS})

if (WIN32)
    configure_file("${SDL2_LIBRARIES_DIR}/SDL2.dll" "${CMAKE_BINARY_DIR}/" COPYONLY)
endif()