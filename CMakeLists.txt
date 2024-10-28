cmake_minimum_required(VERSION 3.20)

project(R-type VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# set(CMAKE_BUILD_TYPE Debug)
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FS")
endif()

find_package(Boost REQUIRED COMPONENTS system filesystem)

option(SERVER "Build the server" ON)
option(CLIENT "Build the client" ON)
option(TESTS "Build the tests" ON)
option(DEBUG "Debug mode" ON)

if (SERVER)
    add_subdirectory(server)
    add_subdirectory(server_dev_tools/source_code)
endif()

if (CLIENT)
    add_subdirectory(client)
endif()

if (HEAD_SERVER)
    add_subdirectory(HeadServer)
endif()

if (TESTS AND UNIX)
    add_subdirectory(tests)
endif()
