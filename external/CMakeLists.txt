# Append to any IDE folders already set be calling scripts.
set(PARENT_FOLDER ${CMAKE_FOLDER})

# Gemcutter #
set(CMAKE_FOLDER "${PARENT_FOLDER}/Engine")
add_subdirectory(gemcutter)
