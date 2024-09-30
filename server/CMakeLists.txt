cmake_minimum_required(VERSION 3.10)
project(UDPServer)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)

add_executable(r-type_server
    src/main.cpp
    src/UDPServer.cpp
)

target_link_libraries(r-type_server Boost::boost)

file(GLOB_RECURSE SERVER_CPP_FILES "src/*.cpp")

add_custom_target(
    clang-format-server
    COMMAND clang-format -i ${SERVER_CPP_FILES}
    COMMENT "Running clang-format on server source files"
)

add_dependencies(r-type_server clang-format-server)
