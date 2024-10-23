cmake_minimum_required(VERSION 3.20)

enable_testing()

find_package(GTest 1.15.2 CONFIG REQUIRED)

add_executable(r-type_tests main.cpp)

add_subdirectory(server)

include(GoogleTest)
gtest_discover_tests(r-type_tests)

target_link_libraries(r-type_tests PRIVATE rtype_server_lib GTest::gtest GTest::gtest_main)

target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/client)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/core)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/lib)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/network)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/room)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/src)
