cmake_minimum_required(VERSION 3.10)
project(SFML_Menu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(SFML_Menu main.cpp src/Menu.cpp src/Game.cpp src/GameObject.cpp)

target_link_libraries(SFML_Menu sfml-graphics sfml-window sfml-system)
target_link_libraries(SFML_Menu -pthread)
