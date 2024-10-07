cmake_minimum_required(VERSION 3.10)
project(UDPServer)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system filesystem)

if (MACOS)
    include_directories(/opt/homebrew/include)
    link_directories(/opt/homebrew/lib)
endif()

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_library(rtype_server_lib STATIC)

target_include_directories(rtype_server_lib PUBLIC include)

add_executable(r-type_server
    src/main.cpp
)

target_link_libraries(r-type_server Boost::boost rtype_server_lib)

add_subdirectory(client)
add_subdirectory(core)
add_subdirectory(lib)
add_subdirectory(network)
add_subdirectory(room)
add_subdirectory(src)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
elseif (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wpedantic")
endif()

if (TESTS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -g")
    target_link_options(rtype_server_lib PUBLIC "--coverage")
endif ()

file(GLOB_RECURSE SERVER_CPP_FILES "src/*.cpp")

add_custom_target(
    clang-format-server
    COMMAND clang-format -i ${SERVER_CPP_FILES}
    COMMENT "Running clang-format on server source files"
)

add_dependencies(r-type_server clang-format-server)
