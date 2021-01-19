cmake_minimum_required (VERSION 3.2.0)
project (TippdesDungeonExample)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (DEBUG)
    set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
    set (CMAKE_BUILD_TYPE "Debug")
endif()

include (GNUInstallDirs)

include_directories (include/)

file (GLOB_RECURSE ALL_SOURCE_FILES
    src/*.cpp include/*.hpp
)

message("-- Looking for TippdesDungeon source files")

find_file (TIPP_DES_DUNGEON_TEST NAMES lib/TippdesDungeon/CMakeLists.txt HINTS ${CMAKE_CURRENT_SOURCE_DIR} CMAKE_FIND_ROOT_PATH_BOTH) # look for CMakeLists.txt

if(NOT TIPP_DES_DUNGEON_TEST)
    message("-- Looking for yaml-cpp source files - not found")
else()
    message("-- Looking for yaml-cpp source files - found")
endif()

find_file (TIPP_DES_DUNGEON NAMES lib/TippdesDungeon HINTS ${CMAKE_CURRENT_SOURCE_DIR} CMAKE_FIND_ROOT_PATH_BOTH)

find_package (Threads REQUIRED)
find_package (Curses REQUIRED)

add_subdirectory(${TIPP_DES_DUNGEON})

include_directories (${CURSES_INCLUDE_DIR})

add_executable (tipp_des_dungeon_console ${ALL_SOURCE_FILES})

add_dependencies (tipp_des_dungeon_console libtipp_des_dungeon)

target_link_libraries(tipp_des_dungeon_console curses libtipp_des_dungeon ${CURSES_LIBRARIES})
