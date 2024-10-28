cmake_minimum_required(VERSION 3.10)
project(UDPServer)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include/uuid)
find_library(UUID_LIB uuid)

add_library(rtype_head_server_lib STATIC)

target_include_directories(rtype_head_server_lib PUBLIC include)

if(UUID_LIB)
target_link_libraries(rtype_head_server_lib ${UUID_LIB})
endif()

add_executable(r-type_head_server
src/main.cpp
)
target_include_directories(r-type_head_server PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_SOURCE_DIR}/client
${CMAKE_SOURCE_DIR}/lib
${CMAKE_SOURCE_DIR}/modules
${CMAKE_SOURCE_DIR}/network
${CMAKE_SOURCE_DIR}/src
)

target_include_directories(rtype_head_server_lib PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_SOURCE_DIR}/client
${CMAKE_SOURCE_DIR}/lib
${CMAKE_SOURCE_DIR}/modules
${CMAKE_SOURCE_DIR}/network
${CMAKE_SOURCE_DIR}/src
)

add_subdirectory(client)
add_subdirectory(lib)
add_subdirectory(modules)
add_subdirectory(network)
add_subdirectory(src)

target_link_libraries(r-type_head_server rtype_head_server_lib)

if (MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /FS")
elseif (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wpedantic")
endif()

if (TESTS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -g")
    target_link_options(rtype_head_server_lib PUBLIC "--coverage")
endif ()

file(GLOB_RECURSE SERVER_CPP_FILES "src/*.cpp")

if(CLANG_FORMAT_EXECUTABLE)
    add_custom_target(
        clang-format-server
        COMMAND clang-format -i ${SERVER_CPP_FILES}
        COMMENT "Running clang-format on server source files"
    )
    add_dependencies(r-type_head_server clang-format-server)
else()
    message(WARNING "clang-format not found, skipping clang-format step.")
endif()
