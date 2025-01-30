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
add_dependencies(${GAME_PROJECT_NAME} ASSETS)
sf_target_compile_warnings(${GAME_PROJECT_NAME})
sf_target_compile_warnings_as_errors(${GAME_PROJECT_NAME} OPTIONAL)

target_include_directories(${GAME_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(${GAME_PROJECT_NAME} PROPERTIES
	VS_DEBUGGER_WORKING_DIRECTORY
		"${CMAKE_SOURCE_DIR}"
)

target_link_libraries(${GAME_PROJECT_NAME} PUBLIC gemcutter)

target_precompile_headers(${GAME_PROJECT_NAME}
	PRIVATE
		<algorithm>
		<array>
		<cstddef>
		<cstdint>
		<cstring>
		<fstream>
		<functional>
		<map>
		<memory>
		<numeric>
		<optional>
		<queue>
		<span>
		<string_view>
		<string>
		<type_traits>
		<unordered_map>
		<vector>
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Application/FileSystem.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Application/Logging.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Application/Reflection.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Entity/Entity.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/GUI/Widget.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Math/Matrix.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Math/Quaternion.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Math/Transform.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Math/Vector.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Resource/Shareable.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Utilities/Meta.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Utilities/Random.h
		${CMAKE_SOURCE_DIR}/external/gemcutter/gemcutter/Utilities/ScopeGuard.h
)