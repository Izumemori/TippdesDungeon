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

add_library (tipp_des_dungeon SHARED ${ALL_SOURCE_FILES})
