add_subdirectory(src)

target_include_directories(gameModule PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(rtype_server_tests_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})