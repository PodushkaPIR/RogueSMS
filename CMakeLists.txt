cmake_minimum_required(VERSION 3.30.1)

project(RogueSMS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Curses REQUIRED)
file(GLOB SOURCES "src/*.cpp")
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SOURCES}
        include/PlayerController.h
        include/Controller.h
        src/PlayerController.cpp
        include/MenuController.h
        src/MenuController.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})

# Gcc or Clang
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

# Debug or Release
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
    message(STATUS "Building in Debug mode")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
    message(STATUS "Building in Release mode")
endif()
