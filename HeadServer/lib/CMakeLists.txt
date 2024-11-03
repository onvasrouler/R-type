target_sources(rtype_head_server_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Buffer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Buffer.hpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/MultiThread.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/MultiThread.hpp
)

target_include_directories(rtype_head_server_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})