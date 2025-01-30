cmake_minimum_required(VERSION 3.20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Detect a reasonable project name from the current folder.
get_filename_component(folder_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" folder_name ${folder_name})
set(GAME_PROJECT_NAME ${folder_name} CACHE PATH "")
option(GAME_PROJECT_NAME "The name of the game.")

project(${GAME_PROJECT_NAME} CXX)

add_subdirectory(external)

gem_set_up_workspace("${CMAKE_CURRENT_LIST_DIR}/workspace/"
    PACK_TARGET ASSETS
)

add_subdirectory(source)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${GAME_PROJECT_NAME})
