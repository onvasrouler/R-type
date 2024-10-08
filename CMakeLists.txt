cmake_minimum_required(VERSION 3.20)

project(MyCppProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (WIN32)
    cmake_policy(SET CMP0167 NEW)
endif ()

#set your vcpkg path here
set(CMAKE_TOOLCHAIN_FILE "C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake")

option(SERVER "Build the server" ON)
option(CLIENT "Build the client" ON)
option(TESTS "Build the tests" ON)

if (SERVER)
    add_subdirectory(server)
endif ()

if (CLIENT)
    add_subdirectory(client)
endif ()

if (TESTS)
    add_subdirectory(tests)
endif ()
