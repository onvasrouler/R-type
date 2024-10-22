cmake_minimum_required(VERSION 3.20)

project(R-type VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_BUILD_TYPE Debug)
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FS")
endif()

option(SERVER "Build the server" ON)
option(CLIENT "Build the client" ON)
option(TESTS "Build the tests" ON)
option(DEBUG "Debug mode" ON)

if (SERVER)
    add_subdirectory(server)
endif()

if (CLIENT)
    add_subdirectory(client2)
endif()

if (TESTS AND UNIX)
    add_subdirectory(tests)
endif()
