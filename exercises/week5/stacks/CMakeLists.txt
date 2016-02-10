#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.6)
#Name your project here
project(ICE)

#Sends the -std=c99 flag to the gcc compiler
add_definitions(-std=c99)
#This tells CMake to fib.c and name it fibonacci
file(GLOB SOURCES *.c)

add_executable(stack_array ${SOURCES})

