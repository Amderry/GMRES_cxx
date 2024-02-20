cmake_minimum_required(VERSION 3.28)

set(MATH_PROJECT_NAME Math)
set(CMAKE_CXX_STANDARD 20)

set(MATH_PUBLIC_INCLUDES
		includes/Minimization.hpp
		includes/MMultiplication.hpp
		includes/Norm.hpp
		includes/ScalarMultiplication.hpp
		includes/Matrix.hpp
		includes/MSum.hpp
		includes/MSub.hpp
	)
	
set(MATH_PRIVATE_SOURCES
		src/Minimization.cpp
		src/MMultiplication.cpp
		src/Norm.cpp
		src/ScalarMultiplication.cpp
		src/Matrix.cpp
		src/MSum.cpp
		src/MSub.cpp
)


add_library(${MATH_PROJECT_NAME} STATIC
			${MATH_PUBLIC_INCLUDES}
			${MATH_PRIVATE_SOURCES})

target_include_directories(${MATH_PROJECT_NAME} PUBLIC includes)
target_include_directories(${MATH_PROJECT_NAME} PRIVATE src)