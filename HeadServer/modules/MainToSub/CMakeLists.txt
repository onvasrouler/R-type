# Add the source files for the library
target_sources(rtype_head_server_lib PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/MainToSub.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MainToSub.hpp
)

# Optionally, specify the include directory for the library
target_include_directories(rtype_head_server_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
