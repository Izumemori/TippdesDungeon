cmake_minimum_required (VERSION 3.2.0)
project (TippdesDungeon)

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

find_package (Threads REQUIRED)
find_package (Curses REQUIRED)

include_directories (${CURSES_INCLUDE_DIR})

add_executable (tipp_des_dungeon ${ALL_SOURCE_FILES})
target_link_libraries(tipp_des_dungeon ${CURSES_LIBRARIES})