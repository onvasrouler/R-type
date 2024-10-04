cmake_minimum_required(VERSION 3.20)

project(Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROJECT_NAME server)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
include_directories(src/entity/ src/entity/bullet/ src/entity/character/ src/game/ src/tools/ src/tools/special/ src/tools/src/)

set(SOURCES
    src/main.cpp
    src/entity/ACharacter.cpp
    src/entity/AEntity.cpp
    src/entity/bullet/Bullet.cpp
    src/entity/character/Player.cpp
    src/entity/character/Enemy.cpp
    src/game/Game.cpp
    src/tools/ATools.cpp
    src/tools/special/Point.cpp
    src/tools/special/Rect.cpp
    src/tools/special/Id.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
