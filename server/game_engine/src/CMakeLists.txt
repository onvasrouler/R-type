add_subdirectory(tools)
add_subdirectory(game)
add_subdirectory(entity)

target_include_directories(rtype_server_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
