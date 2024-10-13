cmake_minimum_required(VERSION 3.10)
project(UDPClient)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system filesystem)
include_directories(${Boost_INCLUDE_DIRS})

file(GLOB_RECURSE CLIENT_CPP_FILES "src/*.cpp")

add_executable(r-type_client ${CLIENT_CPP_FILES})

target_link_libraries(r-type_client Boost::system Boost::filesystem Boost::boost)

find_program(CLANG_FORMAT_EXECUTABLE clang-format)

if(CLANG_FORMAT_EXECUTABLE)
    add_custom_target(
        clang-format-client
        COMMAND ${CLANG_FORMAT_EXECUTABLE} -i ${CLIENT_CPP_FILES}
        COMMENT "Running clang-format on client source files"
    )

    add_dependencies(r-type_client clang-format-client)
else()
    message(WARNING "clang-format not found, skipping clang-format step.")
endif()
