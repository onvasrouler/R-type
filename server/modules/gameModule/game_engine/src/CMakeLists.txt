add_subdirectory(tools)
add_subdirectory(game)
add_subdirectory(entity)

target_include_directories(gameModule PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
