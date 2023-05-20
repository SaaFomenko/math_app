cmake_minimum_required(VERSION 3.18)

project(math_app)

# set the C++ standard
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(${PROJECT_NAME}.exe main.cpp)

target_link_libraries(${PROJECT_NAME}.exe 
	math_fn_lib
	str_split_lib)
