cmake_minimum_required(VERSION 3.19)
project(TicTacToe)
set(CMAKE_CXX_STANDARD 23)

if (WIN32)
    set(SDL2_DIR dependencies/SDL2-2.0.20)
    set(GLEW_DIR dependencies/glew-2.1.0)
endif()
set(glm_DIR dependencies/glm-0.9.9.8/glm/cmake/glm)

set(SOURCE_FILES src/Renderer.cpp src/shader.cpp src/Field.cpp src/lines.cpp src/triangles.cpp src/draw_object_factory.cpp src/gameLogic.cpp )

add_executable(TicTacToe src/main.cpp ${SOURCE_FILES})

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)

find_library(SDL2_LIB SDL2.lib ${SDL2_DIR}/lib/x64/)
find_library(GLEW_LIB glew32.lib ${GLEW_DIR}lib/Release/x64/)

target_link_libraries(TicTacToe ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})

include_directories(TicTacToe PUBLIC 
    ${SDL2_INCLUDE_DIRS} 
    ${GLEW_INCLUDE_DIRS} 
    ${GLM_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    include)

if (WIN32)
    configure_file("${SDL2_LIBRARIES_DIR}/SDL2.dll" "${CMAKE_BINARY_DIR}/" COPYONLY)
    configure_file("${GLEW_LIBRARIES_DIR}/glew32.dll" "${CMAKE_BINARY_DIR}/" COPYONLY)
endif()