target_sources(gameModule
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Point.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Point.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Rect.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Rect.hpp
)

target_include_directories(gameModule PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
