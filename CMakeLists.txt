cmake_minimum_required(VERSION 3.16)

# Set supported platform and binary output directory.
set(CMAKE_GENERATOR_PLATFORM Win32)
set(CMAKE_VS_PLATFORM_NAME Win32)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Detect a reasonable project name from the current folder.
get_filename_component(folder_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" folder_name ${folder_name})
set(GAME_PROJECT_NAME ${folder_name} CACHE PATH "")
option(GAME_PROJECT_NAME "The name of the game.")

project(${GAME_PROJECT_NAME} CXX)

# Omit ZERO_CHECK target.
set(CMAKE_SUPPRESS_REGENERATION ON)

add_subdirectory(external)

gem_set_up_workspace("${CMAKE_CURRENT_LIST_DIR}/workspace/"
    PACK_TARGET ASSETS
)

add_subdirectory(source)
