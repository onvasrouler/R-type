cmake_minimum_required(VERSION 3.10)

project(RType VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

# Include project-specific directories
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/elements)

# Find Raylib automatically using vcpkg
find_package(raylib CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)


# Set platform-specific libraries
if(WIN32)
    set(LIBS opengl32 gdi32 winmm)  # Additional Windows libraries
else()
    set(LIBS GL dl rt X11 pthread)  # Additional Unix-based libraries
endif()

# Raygui setup
set(LIBGUIPATH ${CMAKE_SOURCE_DIR}/client/src/raygui)
set(RAYGUI_SOURCES ${LIBGUIPATH}/raygui.c)
set(RAYGUI_HEADERS ${LIBGUIPATH}/raygui.h)

add_library(raygui STATIC ${RAYGUI_SOURCES})
target_compile_definitions(raygui PRIVATE DRAYGUI_IMPLEMENTATION BUILD_LIBTYPE_SHARED)

# Link Raylib and Raygui
if(WIN32)
    target_link_libraries(raygui raylib ${LIBS})
elseif(UNIX AND NOT APPLE)
    target_link_libraries(raygui raylib ${LIBS})
elseif(APPLE)
    target_link_libraries(raygui raylib "-framework OpenGL" "-framework Cocoa" ${LIBS})
endif()

# Add executable target
set(SRC_FILES
    src/fpsCounter/fpsCounter.cpp
    src/jsonParser/jsonParser.cpp
    src/elements/guiElements/guiElem/AGuiElem.cpp
    src/elements/guiElements/gui.cpp
    src/elements/guiElements/guiFunction.cpp
    src/menu/menuManager.cpp
    src/raylibWindow/utils.cpp
    src/raylibWindow/raylibWindow.cpp
)

set(GUIELEM_FILES
    src/elements/guiElements/guiElem/src/GButton/GButton.cpp
    src/elements/guiElements/guiElem/src/GCheckBox/GCheckBox.cpp
    src/elements/guiElements/guiElem/src/GColorPicker/GColorPicker.cpp
    src/elements/guiElements/guiElem/src/GDropDown/GDropDown.cpp
    src/elements/guiElements/guiElem/src/GGroup/GGroup.cpp
    src/elements/guiElements/guiElem/src/GList/GList.cpp
    src/elements/guiElements/guiElem/src/GListEx/GListEx.cpp
    src/elements/guiElements/guiElem/src/GPannel/GPannel.cpp
    src/elements/guiElements/guiElem/src/GProgressBar/GProgressBar.cpp
    src/elements/guiElements/guiElem/src/GSlider/GSlider.cpp
    src/elements/guiElements/guiElem/src/GSpinner/GSpinner.cpp
    src/elements/guiElements/guiElem/src/GTextInput/GTextInput.cpp
    src/elements/guiElements/guiElem/src/GTextInputBox/GTextInputBox.cpp
    src/elements/guiElements/guiElem/src/GToggleGroup/GToggleGroup.cpp
    src/elements/guiElements/guiElem/src/GToggleSlider/GToggleSlider.cpp
    src/elements/guiElements/guiElem/src/GValueBox/GValueBox.cpp
    src/elements/guiElements/guiElem/src/GWindBox/GWindBox.cpp
    src/elements/guiElements/guiElem/src/Text/Text.cpp
)

set(MAIN_FILE main.cpp)
set(TARGET_NAME Rtype)

link_directories(${CMAKE_SOURCE_DIR}/build/debug)

add_executable(${TARGET_NAME} ${SRC_FILES} ${GUIELEM_FILES} ${MAIN_FILE})

# Link Raylib and Raygui
target_link_libraries(${TARGET_NAME} raylib nlohmann_json::nlohmann_json ${LIBS})

if(APPLE)
    target_link_libraries(${TARGET_NAME} "-framework OpenGL" "-framework Cocoa")
    target_link_libraries(raygui "-framework OpenGL" "-framework Cocoa")
endif()
