# Combine the sources from the parent directory

find_package(Boost REQUIRED COMPONENTS system filesystem)

set(AdminPanelModuleSourceCode
    ${CMAKE_CURRENT_SOURCE_DIR}/adminClient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/adminClient.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/adminPanelModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/adminPanelModule.hpp
)

# Print the value of SOURCE_CODE
message(STATUS "SOURCE_CODE: ${SOURCE_CODE}")
message(STATUS "MODULE_INCLUDE: ${MODULE_INCLUDE}")

# Create the shared library
add_library(AdminPanelModule SHARED ${AdminPanelModuleSourceCode})
if(Boost_FOUND)
    message(STATUS "Boost found: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(AdminPanelModule PRIVATE Boost::system Boost::filesystem)
else()
    message(FATAL_ERROR "Boost not found")
endif()

# Link the precompiled static library to your shared library
target_link_libraries(AdminPanelModule PRIVATE ${SOURCE_CODE})

# Add the include directories for ModuleTemplate
target_include_directories(AdminPanelModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(AdminPanelModule PUBLIC ${MODULE_INCLUDE})
