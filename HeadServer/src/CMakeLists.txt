target_sources(rtype_head_server_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/HeadServer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/HeadServer.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/HeadServerServerModule.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/HeadServerServerModule.hpp
)

target_include_directories(rtype_head_server_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
