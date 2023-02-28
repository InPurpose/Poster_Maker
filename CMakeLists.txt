cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sfml_project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp MouseEvents.cpp MouseEvents.h EventHandler.h States.cpp States.h
                 SnapshotInterface.h Snapshot.cpp Snapshot.h GUIComponents.cpp GUIComponents.h
                 TextInput.cpp TextInput.h History.cpp History.h Cursor.cpp Cursor.h Typing.cpp
                 Typing.h LinkedList.cpp LinkedList.h Node.h Node_Iterator.cpp Node_Iterator.h
                 MultiText.cpp MultiText.h Keyboard_Shortcuts.cpp Keyboard_Shortcuts.h
                 Myfont.cpp Myfont.h ChangeColor.cpp ChangeColor.h Label.cpp Label.h Box.cpp Box.h
                 Binary_Tree.cpp Binary_Tree.h TreeNode.h Item.cpp Item.h ItemList.cpp ItemList.h
                 InputBox.cpp InputBox.h DropdownMenu.cpp DropdownMenu.h Menu.cpp Menu.h
                 MenuBar.cpp MenuBar.h FileItem.cpp FileItem.h Image.cpp Image.h FileNode.cpp FileNode.h
                 FileTree.cpp FileTree.h Slider.cpp Slider.h ImageEditor.cpp ImageEditor.h
                 SliderHandler.cpp SliderHandler.h Window_Dialog.cpp Window_Dialog.h ColorSquare.cpp
                 ColorSquare.h ColorMenu.cpp ColorMenu.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()