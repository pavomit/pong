cmake_minimum_required(VERSION 3.25)

project(pong 
        VERSION 1.0.0
        LANGUAGES CXX       
        DESCRIPTION "a very simple pong game in sfml")

set(CMAKE_CXX_STANDARD         14)
set(CMAKE_C_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_FEATURES         OFF)

set(TARGET_NAME pong)

add_executable(pong main.cpp)