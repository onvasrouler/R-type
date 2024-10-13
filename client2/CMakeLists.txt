cmake_minimum_required(VERSION 3.10)
project(SFML_Menu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(r-type_client main.cpp src/Menu.cpp src/Game.cpp src/GameObject.cpp)

target_link_libraries(r-type_client sfml-graphics sfml-window sfml-system)
target_link_libraries(r-type_client -pthread)

set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/client2/chipset")
set(DEBUG_OUTPUT_DIR "${CMAKE_BINARY_DIR}/client2/Debug")

add_custom_command(TARGET r-type_client POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${ASSETS_DIR}" "${DEBUG_OUTPUT_DIR}/chipset"
    COMMENT "Copying assets to Debug directory"
)
