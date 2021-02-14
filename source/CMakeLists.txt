list(APPEND gemcutter_game_files
	"Game.cpp"
	"Game.h"
	"main.cpp"
)

# Match the folder structure inside the IDE.
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${gemcutter_game_files})

# Set the game window name to match the game's name.
configure_file("${CMAKE_CURRENT_LIST_DIR}/main.cpp" "${CMAKE_CURRENT_LIST_DIR}/main.cpp")

add_executable(${GAME_PROJECT_NAME} WIN32 ${gemcutter_game_files})
sf_target_compile_warnings(${GAME_PROJECT_NAME})
sf_target_compile_warnings_as_errors(${GAME_PROJECT_NAME} OPTIONAL)

target_include_directories(${GAME_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(${GAME_PROJECT_NAME} PROPERTIES
	VS_DEBUGGER_WORKING_DIRECTORY
		"${CMAKE_SOURCE_DIR}"
)

target_link_libraries(${GAME_PROJECT_NAME} PUBLIC gemcutter)
