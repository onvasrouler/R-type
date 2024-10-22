cmake_minimum_required(VERSION 3.20)

project(R-type VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

find_package(Boost REQUIRED COMPONENTS system filesystem)

option(SERVER "Build the server" ON)
option(CLIENT "Build the client" ON)
option(TESTS "Build the tests" ON)

if (SERVER)
    add_subdirectory(server)
endif()

if (CLIENT)
    add_subdirectory(client)
endif()

if (TESTS AND UNIX)
    add_subdirectory(tests)
endif()
