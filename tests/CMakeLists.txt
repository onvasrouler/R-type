cmake_minimum_required(VERSION 3.20)

# Define configuration file for vcpkg
if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
endif()

# Enable testing
enable_testing()

# Find Google Test
find_package(GTest CONFIG REQUIRED)

# Create executable for tests
add_executable(r-type_tests main.cpp)

# Add subdirectories for the tests
add_subdirectory(server)

# Automatically discover and add tests
include(GoogleTest)
gtest_discover_tests(r-type_tests)

# Link libraries based on platform
if(UNIX)
    target_link_libraries(r-type_tests PRIVATE rtype_server_lib gtest)
endif()

if(WIN32)
    target_link_libraries(r-type_tests PRIVATE rtype_server_lib GTest::gtest GTest::gtest_main)
endif()

target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/client)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/core)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/lib)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/network)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/room)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/src)
