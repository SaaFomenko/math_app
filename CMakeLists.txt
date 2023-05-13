cmake_minimum_required(VERSION 3.5)

project(math_app)

# set the C++ standard
set(CMAKE_CXX_STANDARD 11)

file(GLOB
	app_exception_src "lib/app_exception/*.cpp"
	str_split_src "lib/str_split/*.cpp"
	math_fn_src "lib/math_fn/*.cpp")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#add_library(math_fn_lib STATIC ${math_fn_src})

add_executable(${PROJECT_NAME}.exe main.cpp 
	${math_fn_src}
	${str_split_src}
	${app_exception_src})

target_link_libraries(${PROJECT_NAME}.exe 
	math_fn_lib
	str_split_lib
	app_exception_lib) 
