cmake_minimum_required(VERSION 3.20)

project(RType VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajout des options de compilation en fonction du compilateur
if (MSVC)
    # Pour MSVC (Visual Studio), utiliser /W4 pour des avertissements plus stricts
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /MP /D_WIN32_WINNT=0x0601")
else()
    # Pour les compilateurs GCC et Clang, utiliser -Wall et -Wextra
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/elements)

# Utiliser vcpkg pour récupérer nlohmann-json
find_package(nlohmann_json REQUIRED)
find_package(raylib REQUIRED)

add_custom_command(
    OUTPUT ${CMAKE_SOURCE_DIR}/src/raygui/raygui.c
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/src/raygui/raygui.h ${CMAKE_SOURCE_DIR}/src/raygui/raygui.c
    DEPENDS ${CMAKE_SOURCE_DIR}/src/raygui/raygui.h
    COMMENT "Copying raygui.h to raygui.c"
)

# Add the renamed file to the library
add_library(raygui SHARED ${CMAKE_SOURCE_DIR}/src/raygui/raygui.c)

target_compile_definitions(raygui PRIVATE RAYGUI_IMPLEMENTATION BUILD_LIBTYPE_SHARED)

set_target_properties(raygui PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

target_include_directories(raygui PRIVATE src)

if(WIN32)
    # Windows specific
    target_link_libraries(raygui PRIVATE raylib opengl32 gdi32 winmm)
elseif(APPLE)
    # macOS specific
    find_package(raylib REQUIRED)
    target_link_libraries(raygui PRIVATE raylib "-framework OpenGL" pthread dl)
elseif(UNIX)
    # Linux specific
    find_package(raylib REQUIRED)
    target_link_libraries(raygui PRIVATE raylib GL m pthread dl rt X11)
endif()

install(TARGETS raygui RUNTIME DESTINATION bin LIBRARY DESTINATION lib)

# Install the executable
install(TARGETS ${TARGET_NAME} DESTINATION bin)

if(WIN32)
    set(LIBS opengl32 gdi32 winmm)  # Bibliothèques pour Windows
else()
    set(LIBS GL dl rt X11 pthread)  # Bibliothèques pour Unix
endif()

set(SRC_FILES
    src/fpsCounter/fpsCounter.cpp
    src/jsonParser/jsonParser.cpp
    src/elements/guiElements/guiElem/AGuiElem.cpp
    src/elements/guiElements/gui.cpp
    src/elements/guiElements/guiFunction.cpp
    src/menu/menuManager.cpp
    src/menu/GuiElementFactory.cpp
    src/network/networkElem.cpp
    src/game/game.cpp
    src/game/entities/Entities.cpp
    src/game/entities/EntitiesFactory.cpp
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

set(TARGET_NAME r-type_client)

link_directories(${CMAKE_SOURCE_DIR}/build/debug)

# Ajouter l'exécutable
add_executable(${TARGET_NAME} ${SRC_FILES} ${GUIELEM_FILES} ${MAIN_FILE})

# Lier les bibliothèques nécessaires (raylib, raygui, nlohmann-json, etc.)
target_link_libraries(${TARGET_NAME} raylib raygui nlohmann_json::nlohmann_json ${LIBS})

# Pour macOS, lier les frameworks supplémentaires
if(APPLE)
    target_link_libraries(${TARGET_NAME} "-framework OpenGL" "-framework Cocoa")
endif()

add_custom_command(
    TARGET raygui POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_SOURCE_DIR}/client/src/raygui/raygui.c
    COMMENT "Deleting raygui.c after build"
)
