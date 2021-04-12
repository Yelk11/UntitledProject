cmake_minimum_required(VERSION 3.0.0)
project(UntitledProject VERSION 0.1.0)

include(CTest)
enable_testing()


add_library(
    map
    map.cpp
    map.hpp
)
add_library(
    player_controller
    player_controller.cpp
    player_controller.hpp
)
add_library(
    entity
    entity.cpp
    entity.hpp
)
add_library(
    monster
    monster.cpp
    monster.hpp
)



add_executable(UntitledProject main.cpp)

target_link_libraries(
    UntitledProject
    map
    player_controller
    ncurses
    entity
    monster
)
#target_link_libraries(UntitledProject /opt/homebrew/opt/ncurses/lib/libcurses.a)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
