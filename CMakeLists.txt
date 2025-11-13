cmake_minimum_required(VERSION 3.23)
project(CSnake)
find_package(raylib)
set(CMAKE_BUILD_TYPE Debug)

add_executable(CSnake)

target_sources(CSnake
    PRIVATE
        src/main.c
        src/gameFunctions.c
        src/player.c
    
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/gameFunctions.h
            include/player.h
)

target_link_libraries(CSnake
    PRIVATE
        raylib
)
