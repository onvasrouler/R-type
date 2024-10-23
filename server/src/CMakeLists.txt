target_sources(rtype_server_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Server.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Server.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/serverModule.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/serverModule.hpp
)

target_include_directories(rtype_server_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
