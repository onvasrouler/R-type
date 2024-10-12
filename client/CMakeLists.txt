cmake_minimum_required(VERSION 3.10)
project(UDPClient)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system filesystem)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(r-type_client src/main.cpp)

target_link_libraries(r-type_client Boost::system Boost::filesystem)

target_link_libraries(r-type_client Boost::boost)

file(GLOB_RECURSE CLIENT_CPP_FILES "src/*.cpp")

add_custom_target(
    clang-format-client
    COMMAND clang-format -i ${CLIENT_CPP_FILES}
    COMMENT "Running clang-format on client source files"
)

add_dependencies(r-type_client clang-format-client)
