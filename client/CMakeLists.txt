cmake_minimum_required(VERSION 3.10)
project(UDPClient)

set(CMAKE_CXX_STANDARD 11)

if (MACOS)
    set(BOOST_ROOT "/usr/local/opt/boost")
endif()

find_package(Boost REQUIRED)

add_executable(r-type_client src/main.cpp)

target_link_libraries(r-type_client Boost::boost)

file(GLOB_RECURSE CLIENT_CPP_FILES "src/*.cpp")

add_custom_target(
    clang-format-client
    COMMAND clang-format -i ${CLIENT_CPP_FILES}
    COMMENT "Running clang-format on client source files"
)

add_dependencies(r-type_client clang-format-client)
