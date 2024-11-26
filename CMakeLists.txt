cmake_minimum_required(VERSION 3.30.1)

project(RogueSMS)
find_package(Curses REQUIRED)
file(GLOB SOURCES "src/*.cpp")
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
