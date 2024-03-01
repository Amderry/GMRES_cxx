cmake_minimum_required(VERSION 3.28)

set(CORE_PROJECT_NAME CR_core)
set(CMAKE_CXX_STANDARD 20)

set(GMRES_PUBLIC_INCLUDES
		includes/CR.hpp
	)
	
set(GMRES_PRIVATE_SOURCES
		src/CR.cpp
)

add_library(${CORE_PROJECT_NAME} STATIC 
	${GMRES_PUBLIC_INCLUDES}
	${GMRES_PRIVATE_SOURCES}
)

target_include_directories(${CORE_PROJECT_NAME} PUBLIC includes)
target_include_directories(${CORE_PROJECT_NAME} PUBLIC src)