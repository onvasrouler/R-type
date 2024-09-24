cmake_minimum_required(VERSION 3.10)
project(UDPServer)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)

add_executable(r-type_server src/main.cpp)

target_link_libraries(r-type_server Boost::boost)
