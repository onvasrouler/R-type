add_library(rtype_server_lib STATIC)

target_include_directories(rtype_server_lib PUBLIC include)

add_executable(r-type_server src/main.cpp)
add_subdirectory(client)
add_subdirectory(core)
add_subdirectory(lib)
add_subdirectory(network)
add_subdirectory(room)
add_subdirectory(src)
if (MSVC)
    # Microsoft Visual C++ specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
elseif (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # GCC/Clang specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

if (TESTS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -g")
    target_link_options(rtype_server_lib PUBLIC "--coverage")
endif ()

target_link_libraries(r-type_server rtype_server_lib)
