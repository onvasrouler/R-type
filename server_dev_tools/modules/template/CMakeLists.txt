# Combine the sources from the parent directory
set(ModuleTemplateSourceCode
    ${CMAKE_CURRENT_SOURCE_DIR}/ModuleTemplate.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ModuleTemplate.hpp
)

# Print the value of SOURCE_CODE
message(STATUS "SOURCE_CODE: ${SOURCE_CODE}")
message(STATUS "MODULE_INCLUDE: ${MODULE_INCLUDE}")

# Create the shared library
add_library(ModuleTemplate SHARED ${ModuleTemplateSourceCode})

# Link the precompiled static library to your shared library
target_link_libraries(ModuleTemplate PRIVATE ${SOURCE_CODE})

# Add the include directories for ModuleTemplate
target_include_directories(ModuleTemplate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ModuleTemplate PUBLIC ${MODULE_INCLUDE})
