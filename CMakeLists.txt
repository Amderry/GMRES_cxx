cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME linear_algebra)
set(CMAKE_CXX_STANDARD 20)

project(${PROJECT_NAME})

add_subdirectory(external/eigen)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ./external/eigen/)


set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})