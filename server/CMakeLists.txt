cmake_minimum_required(VERSION 3.10)
project(UDPServer)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include/uuid)
find_library(UUID_LIB uuid)
find_package(nlohmann_json 3.11.3 REQUIRED)

add_library(rtype_server_lib STATIC)

target_include_directories(rtype_server_lib PUBLIC include)

if(UUID_LIB)
target_link_libraries(rtype_server_lib ${UUID_LIB})
endif()
target_link_libraries(rtype_server_lib nlohmann_json::nlohmann_json)

add_executable(r-type_server
src/main.cpp
)
target_include_directories(r-type_server PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_SOURCE_DIR}/client
${CMAKE_SOURCE_DIR}/config
${CMAKE_SOURCE_DIR}/lib
${CMAKE_SOURCE_DIR}/network
${CMAKE_SOURCE_DIR}/room
${CMAKE_SOURCE_DIR}/src
)

target_include_directories(rtype_server_lib PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_SOURCE_DIR}/client
${CMAKE_SOURCE_DIR}/config
${CMAKE_SOURCE_DIR}/lib
${CMAKE_SOURCE_DIR}/modules
${CMAKE_SOURCE_DIR}/network
${CMAKE_SOURCE_DIR}/room
${CMAKE_SOURCE_DIR}/src
)

add_subdirectory(client)
add_subdirectory(config)
add_subdirectory(lib)
add_subdirectory(modules)
add_subdirectory(network)
add_subdirectory(room)
add_subdirectory(src)

target_link_libraries(r-type_server rtype_server_lib)

if (MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /FS")
elseif (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wpedantic")
endif()

if (TESTS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -g")
    target_link_options(rtype_server_lib PUBLIC "--coverage")
endif ()

file(GLOB_RECURSE SERVER_CPP_FILES "src/*.cpp")

if(CLANG_FORMAT_EXECUTABLE)
    add_custom_target(
        clang-format-server
        COMMAND clang-format -i ${SERVER_CPP_FILES}
        COMMENT "Running clang-format on server source files"
    )
    add_dependencies(r-type_server clang-format-server)
else()
    message(WARNING "clang-format not found, skipping clang-format step.")
endif()
