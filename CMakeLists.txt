cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME GMRES)
set(CMAKE_CXX_STANDARD 20)

project(${PROJECT_NAME})

add_subdirectory(math)
add_subdirectory(core)

add_executable(${PROJECT_NAME} core/src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Gmres_Core)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})