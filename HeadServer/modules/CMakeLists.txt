target_sources(rtype_head_server_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/AbstractModule.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/AbstractModule.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MultiThread.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MultiThread.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/UUID.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/UUID.hpp
)

target_include_directories(rtype_head_server_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(logModule)
add_subdirectory(MainToClients)
add_subdirectory(MainToSub)
