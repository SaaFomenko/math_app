cmake_minimum_required(VERSION 3.5)

project(math_fn)

# set the C++ standard
set(CMAKE_CXX_STANDARD 11)

file(GLOB
	lib_source "lib/*.cpp")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(${PROJECT_NAME}_lib STATIC 
	${lib_source})

add_executable(${PROJECT_NAME}.exe main.cpp 
	${lib_source})

target_link_libraries(${PROJECT_NAME}.exe ${PROJECT_NAME}_lib) 
