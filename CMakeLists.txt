cmake_minimum_required(VERSION 3.25)

project(pong 
        VERSION 1.0.0
        LANGUAGES CXX       
        DESCRIPTION "a very simple pong game in sfml")

set(CMAKE_CXX_STANDARD         14)
set(CMAKE_C_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_FEATURES         OFF)

set(TARGET_NAME pong)

include(FetchContent)

set(SFML_LIB_NAME SFML)

FetchContent_Declare(
    ${SFML_LIB_NAME}
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 2.6.1
    GIT_SHALLOW FALSE 
)

FetchContent_MakeAvailable(${SFML_LIB_NAME})

# Define the executable target before linking libraries
add_executable(${TARGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Now link libraries to the target
target_link_libraries(${TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${TARGET_NAME} PUBLIC sfml-system) 
target_link_libraries(${TARGET_NAME} PUBLIC sfml-graphics)