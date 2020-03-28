cmake_minimum_required(VERSION 3.15)
project(Proyect1 C)

set(CMAKE_C_STANDARD 99)

ADD_LIBRARY(regex STATIC IMPORTED)
SET_TARGET_PROPERTIES(regex PROPERTIES IMPORTED_LOCATION C:/msys64/mingw64/lib/libsystre.dll.a)

add_executable(Proyect1 main.c)
target_link_libraries(Proyect1 regex)