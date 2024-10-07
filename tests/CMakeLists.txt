cmake_minimum_required(VERSION 3.20)

if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE "MY_DISK_PATH" CACHE STRING "Vcpkg toolchain file")
endif()

enable_testing()

if (UNIX)
    if (MACOS)
        set(GTest_ROOT /opt/homebrew/opt/googletest)
    endif()
    find_package(GTest REQUIRED PATHS ${GTest_ROOT})
    include_directories(${GTest_ROOT}/include)
    link_directories(${GTest_ROOT}/lib)
else()
    find_package(GTest CONFIG REQUIRED)
endif()

add_executable(r-type_tests main.cpp)

add_subdirectory(server)

include(GoogleTest)
gtest_discover_tests(r-type_tests)

if (UNIX)
    target_link_libraries(r-type_tests PRIVATE rtype_server_lib GTest::gtest GTest::gtest_main)
endif()

if (WIN32)
    target_link_libraries(r-type_tests PRIVATE rtype_server_lib GTest::gtest GTest::gtest_main)
endif()

target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/client)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/core)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/lib)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/network)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/room)
target_include_directories(r-type_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/src)
